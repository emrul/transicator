/*
Copyright 2016 The Transicator Authors

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
package pgclient

import (
	"bytes"
	"database/sql"
	"fmt"
	"math/rand"
	"reflect"
	"testing/quick"
	"time"

	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

var driverTypeDB *sql.DB

var _ = Describe("Data type tests", func() {
	BeforeEach(func() {
		if dbURL != "" {
			var err error
			driverTypeDB, err = sql.Open("transicator", dbURL)
			Expect(err).Should(Succeed())
		}
	})

	AfterEach(func() {
		if driverTypeDB != nil {
			driverTypeDB.Exec("truncate table client_test")
			driverTypeDB.Close()
		}
	})

	It("String type", func() {
		ix := 0
		err := quick.Check(func(val string) bool {
			ix++
			return testStringType(ix, val)
		}, nil)
		Expect(err).Should(Succeed())
	})

	It("Integer type", func() {
		ix := 0
		err := quick.Check(func(val int) bool {
			ix++
			return testIntType(ix, val)
		}, nil)
		Expect(err).Should(Succeed())
	})

	It("Small Integer type", func() {
		ix := 0
		err := quick.Check(func(val int16) bool {
			ix++
			return testSmallintType(ix, val)
		}, nil)
		Expect(err).Should(Succeed())
	})

	It("OID type", func() {
		ix := 0
		err := quick.Check(func(val int) bool {
			ix++
			return testOIDType(ix)
		}, nil)
		Expect(err).Should(Succeed())
	})

	It("Float type", func() {
		ix := 0
		err := quick.Check(func(val float32) bool {
			ix++
			return testFloatType(ix, val)
		}, nil)
		Expect(err).Should(Succeed())
	})

	It("Bool type", func() {
		ix := 0
		err := quick.Check(func(val bool) bool {
			ix++
			return testBoolType(ix, val)
		}, nil)
		Expect(err).Should(Succeed())
	})

	It("Bytes type", func() {
		ix := 0
		err := quick.Check(func(val []byte) bool {
			ix++
			return testBytesType(ix, val)
		}, nil)
		Expect(err).Should(Succeed())
		// Don't miss nil
		ix++
		testBytesType(ix, nil)
	})

	It("Timestamp", func() {
		// Clamp down inputs to prevent generating dates that PG can't begin to imagine
		timeCfg := &quick.Config{
			Values: func(vals []reflect.Value, r *rand.Rand) {
				vals[0] = reflect.ValueOf(rand.Int63n(1 << 33))
				//vals[1] = reflect.ValueOf(rand.Int63n(1000000000))
				vals[1] = reflect.ValueOf(int64(0))
			},
		}
		ix := 0
		err := quick.Check(func(secs, ns int64) bool {
			ix++
			return testTimeType(ix, secs, ns, "ts")
		}, timeCfg)
		Expect(err).Should(Succeed())
	})

	It("Timestamp with time zone", func() {
		// Clamp down inputs to prevent generating dates that PG can't begin to imagine
		timeCfg := &quick.Config{
			Values: func(vals []reflect.Value, r *rand.Rand) {
				vals[0] = reflect.ValueOf(rand.Int63n(1 << 33))
				//vals[1] = reflect.ValueOf(rand.Int63n(1000000000))
				vals[1] = reflect.ValueOf(int64(0))
			},
		}
		ix := 0
		err := quick.Check(func(secs, ns int64) bool {
			ix++
			return testTimeType(ix, secs, ns, "timestamp")
		}, timeCfg)
		Expect(err).Should(Succeed())
	})

	It("Timestamps as string", func() {
		testTime, err := time.Parse(pgTimeFormat, "2007-03-28 14:30:00-05")
		Expect(err).Should(Succeed())
		_, err =
			driverTypeDB.Exec("insert into client_test (id, timestamp, ts) values(1, $1, $2)",
				"2007-03-28 14:30:00-05", "2007-03-28 14:30:00")
		Expect(err).Should(Succeed())

		row := driverTypeDB.QueryRow("select timestamp, ts from client_test where id = 1")
		var tsz string
		var ts string
		err = row.Scan(&tsz, &ts)
		Expect(err).Should(Succeed())
		tsst, err := time.Parse(time.RFC3339, tsz)
		Expect(err).Should(Succeed())
		Expect(tsst.UnixNano()).Should(Equal(testTime.UnixNano()))
		fmt.Fprintf(GinkgoWriter, "tsz = %s ts = %s\n", tsz, ts)

		row = driverTypeDB.QueryRow("select timestamp from client_test where id = 1")
		var ttz time.Time
		err = row.Scan(&ttz)
		Expect(err).Should(Succeed())
		Expect(ttz.UnixNano()).Should(Equal(testTime.UnixNano()))
	})

	It("Timestamps as Time", func() {
		testTime, err := time.Parse(pgTimeFormat, "2007-03-28 14:30:00-05")
		Expect(err).Should(Succeed())
		_, err =
			driverTypeDB.Exec("insert into client_test (id, timestamp) values(1, $1)", testTime)
		Expect(err).Should(Succeed())

		row := driverTypeDB.QueryRow("select timestamp from client_test where id = 1")
		var tss string
		err = row.Scan(&tss)
		Expect(err).Should(Succeed())
		tsst, err := time.Parse(time.RFC3339, tss)
		Expect(err).Should(Succeed())
		Expect(tsst.UnixNano()).Should(Equal(testTime.UnixNano()))

		row = driverTypeDB.QueryRow("select timestamp from client_test where id = 1")
		var ts time.Time
		err = row.Scan(&ts)
		Expect(err).Should(Succeed())
		Expect(ts.UnixNano()).Should(Equal(testTime.UnixNano()))
	})

	It("String null", func() {
		_, err := driverTypeDB.Exec("insert into client_test (id) values (1)")
		Expect(err).Should(Succeed())

		row := driverTypeDB.QueryRow("select string from client_test where id = 1")
		var ir interface{}
		err = row.Scan(&ir)
		Expect(err).Should(Succeed())
		Expect(ir).Should(BeNil())

		// Seems to be a special property of database/sql that a null string
		// can be scanned into an empty string
		row = driverTypeDB.QueryRow("select string from client_test where id = 1")
		var s string
		err = row.Scan(&s)
		Expect(err).Should(Succeed())
		Expect(s).Should(BeEmpty())
	})

	It("Big Integer null", func() {
		_, err := driverTypeDB.Exec("insert into client_test (id) values (1)")
		Expect(err).Should(Succeed())

		row := driverTypeDB.QueryRow("select int from client_test where id = 1")
		var ir interface{}
		err = row.Scan(&ir)
		Expect(err).Should(Succeed())
		Expect(ir).Should(BeNil())
	})

	It("Double null", func() {
		_, err := driverTypeDB.Exec("insert into client_test (id) values (1)")
		Expect(err).Should(Succeed())

		row := driverTypeDB.QueryRow("select double from client_test where id = 1")
		var ir interface{}
		err = row.Scan(&ir)
		Expect(err).Should(Succeed())
		Expect(ir).Should(BeNil())
	})

	It("Boolean null", func() {
		_, err := driverTypeDB.Exec("insert into client_test (id) values (1)")
		Expect(err).Should(Succeed())

		row := driverTypeDB.QueryRow("select yesno from client_test where id = 1")
		var ir interface{}
		err = row.Scan(&ir)
		Expect(err).Should(Succeed())
		Expect(ir).Should(BeNil())
	})

	It("Integer null", func() {
		_, err := driverTypeDB.Exec("insert into client_test (id) values (1)")
		Expect(err).Should(Succeed())

		row := driverTypeDB.QueryRow("select iint from client_test where id = 1")
		var ir interface{}
		err = row.Scan(&ir)
		Expect(err).Should(Succeed())
		Expect(ir).Should(BeNil())
	})

	It("Small Integer null", func() {
		_, err := driverTypeDB.Exec("insert into client_test (id) values (1)")
		Expect(err).Should(Succeed())

		row := driverTypeDB.QueryRow("select sint from client_test where id = 1")
		var ir interface{}
		err = row.Scan(&ir)
		Expect(err).Should(Succeed())
		Expect(ir).Should(BeNil())
	})

	It("Time null", func() {
		_, err := driverTypeDB.Exec("insert into client_test (id) values (1)")
		Expect(err).Should(Succeed())

		row := driverTypeDB.QueryRow("select timestamp from client_test where id = 1")
		var ir interface{}
		err = row.Scan(&ir)
		Expect(err).Should(Succeed())
		Expect(ir).Should(BeNil())
	})

	It("Bytes null", func() {
		_, err := driverTypeDB.Exec("insert into client_test (id) values (1)")
		Expect(err).Should(Succeed())

		row := driverTypeDB.QueryRow("select blob from client_test where id = 1")
		var ir interface{}
		err = row.Scan(&ir)
		Expect(err).Should(Succeed())
		Expect(ir).Should(BeNil())
	})
})

func testStringType(ix int, val string) bool {
	_, err := driverTypeDB.Exec("insert into client_test (id, string) values ($1, $2)",
		ix, val)
	Expect(err).Should(Succeed())

	row := driverTypeDB.QueryRow("select string from client_test where id = $1",
		ix)
	var ret string
	err = row.Scan(&ret)
	Expect(err).Should(Succeed())
	Expect(ret).Should(Equal(val))
	return true
}

func testIntType(ix int, val int) bool {
	_, err := driverTypeDB.Exec("insert into client_test (id, int) values ($1, $2)",
		ix, val)
	Expect(err).Should(Succeed())

	row := driverTypeDB.QueryRow("select int from client_test where id = $1",
		ix)
	var ret int
	err = row.Scan(&ret)
	Expect(err).Should(Succeed())
	Expect(ret).Should(Equal(val))
	return true
}

func testSmallintType(ix int, val int16) bool {
	_, err := driverTypeDB.Exec("insert into client_test (id, sint) values ($1, $2)",
		ix, val)
	Expect(err).Should(Succeed())

	row := driverTypeDB.QueryRow("select sint from client_test where id = $1",
		ix)
	var ret int16
	err = row.Scan(&ret)
	Expect(err).Should(Succeed())
	Expect(ret).Should(Equal(val))
	return true
}

func testOIDType(ix int) bool {
	_, err := driverTypeDB.Exec("insert into client_test (id) values ($1)",
		ix)
	Expect(err).Should(Succeed())

	row := driverTypeDB.QueryRow("select oid from client_test where id = $1",
		ix)
	var ret int32
	err = row.Scan(&ret)
	Expect(err).Should(Succeed())
	// Just make sure that we don't get errors when parsing OIDs
	Expect(ret).Should(BeNumerically(">=", 0))
	return true
}

func testFloatType(ix int, val float32) bool {
	_, err := driverTypeDB.Exec("insert into client_test (id, double) values ($1, $2)",
		ix, val)
	Expect(err).Should(Succeed())

	row := driverTypeDB.QueryRow("select double from client_test where id = $1",
		ix)
	var ret float32
	err = row.Scan(&ret)
	Expect(err).Should(Succeed())
	Expect(ret).Should(Equal(val))
	return true
}

func testBoolType(ix int, val bool) bool {
	_, err := driverTypeDB.Exec("insert into client_test (id, yesno) values ($1, $2)",
		ix, val)
	Expect(err).Should(Succeed())

	row := driverTypeDB.QueryRow("select yesno from client_test where id = $1",
		ix)
	var ret bool
	err = row.Scan(&ret)
	Expect(err).Should(Succeed())
	Expect(ret).Should(Equal(val))
	return true
}

func testBytesType(ix int, val []byte) bool {
	fmt.Fprintf(GinkgoWriter, "Testing bytes of length %d\n", len(val))
	_, err := driverTypeDB.Exec("insert into client_test (id, blob) values ($1, $2)",
		ix, val)
	Expect(err).Should(Succeed())

	row := driverTypeDB.QueryRow("select blob from client_test where id = $1",
		ix)
	var ret []byte
	err = row.Scan(&ret)
	Expect(err).Should(Succeed())
	Expect(bytes.Equal(ret, val)).Should(BeTrue())
	return true
}

func testTimeType(ix int, secs, ns int64, cn string) bool {
	now := time.Unix(secs, ns)
	_, err := driverTypeDB.Exec(
		fmt.Sprintf("insert into client_test (id, %s) values ($1, $2)", cn),
		ix, now)
	Expect(err).Should(Succeed())

	row := driverTypeDB.QueryRow(
		fmt.Sprintf("select %s from client_test where id = $1", cn),
		ix)
	var ret time.Time
	err = row.Scan(&ret)
	Expect(err).Should(Succeed())
	fmt.Fprintf(GinkgoWriter, "Time %s == %s\n", now, ret)
	Expect(ret.Unix()).Should(Equal(now.Unix()))
	return true
}
