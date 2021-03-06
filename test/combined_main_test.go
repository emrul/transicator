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
package test

import (
	"database/sql"
	"fmt"
	"os"
	"regexp"
	"testing"

	"github.com/apigee-labs/transicator/pgclient"
	. "github.com/onsi/ginkgo"
	"github.com/onsi/ginkgo/reporters"
	. "github.com/onsi/gomega"
)

var portSpec = regexp.MustCompile("^[\\.0-9]+:([0-9]+)->.*$")

func TestCombined(t *testing.T) {
	RegisterFailHandler(Fail)
	junitReporter := reporters.NewJUnitReporter("../test-reports/combined.xml")
	RunSpecsWithDefaultAndCustomReporters(t, "Combined suite", []Reporter{junitReporter})
}

var changeBase string
var snapshotBase string
var dbURL string
var db *sql.DB

var _ = BeforeSuite(func() {
	changeHost := os.Getenv("CHANGE_HOST")
	Expect(changeHost).ShouldNot(BeEmpty())
	snapshotHost := os.Getenv("SNAPSHOT_HOST")
	Expect(snapshotHost).ShouldNot(BeEmpty())
	changePortSpec := os.Getenv("CHANGE_PORT")
	Expect(changePortSpec).ShouldNot(BeEmpty())
	snapPortSpec := os.Getenv("SNAPSHOT_PORT")
	Expect(snapPortSpec).ShouldNot(BeEmpty())
	dbURL = os.Getenv("TEST_PG_URL")
	Expect(dbURL).ShouldNot(BeEmpty())

	changeBase = fmt.Sprintf("https://%s:%s", changeHost, changePortSpec)
	fmt.Printf("Change server at %s\n", changeBase)
	snapshotBase = fmt.Sprintf("https://%s:%s", snapshotHost, snapPortSpec)
	fmt.Printf("Snapshot server at %s\n", snapshotBase)

	var err error
	pgclient.RegisterDriver()
	db, err = sql.Open("transicator", dbURL)
	Expect(err).Should(Succeed())

	_, err = db.Exec(tableSQL)
	Expect(err).Should(Succeed())
})

var _ = AfterSuite(func() {
	if db != nil {
		db.Exec("drop table combined_test")
		db.Close()
	}
})

var tableSQL = `
  create table combined_test(
    id integer primary key,
    value varchar,
    _change_selector varchar);
  alter table combined_test replica identity full;
`
