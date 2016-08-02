#include "../src/prompts.h"
#include "../src/Database.h"
#include "../libs/sqlite3pp/src/sqlite3pp.h"
#include <istream>
#include <ostream>
#include <gtest/gtest.h>

class DatabaseTest : public ::testing::Test {};


TEST_F (DatabaseTest, createDatabase) {
    sqlite3pp::database db("test.db");
    db.execute("INSERT INTO contacts (name, phone) VALUES ('Mike', '555-1234')");

    sqlite3pp::command cmd(
        db, "INSERT INTO contacts (name, phone) VALUES (?, ?)");
    cmd.binder() << "Mike" << "555-1234";
    cmd.execute();
}