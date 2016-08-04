#include "../src/prompts.h"
#include "../src/Database.h"
#include "../libs/sqlite3pp/src/sqlite3pp.h"
#include <istream>
#include <ostream>
#include <gtest/gtest.h>

class DatabaseTest : public ::testing::Test
{
};


TEST_F (DatabaseTest, createRawDatabase)
{
    // Connect to database
    sqlite3pp::database db("test.db");

    // Create data
    db.execute("CREATE TABLE contacts (\n"
        "id INTEGER PRIMARY KEY ASC,\n"
        "name TEXT NOT NULL,\n"
        "phone text NOT NULL UNIQUE)");
    db.execute(
        "INSERT INTO contacts (name, phone) VALUES ('Mike', '555-1234')");

    // Check data has been created
    sqlite3pp::query qry(db, "SELECT id, name, phone FROM contacts");

    // Column count
    ASSERT_EQ(3, qry.column_count());

    // Check column names
    ASSERT_EQ("id", std::string(qry.column_name(0)));
    ASSERT_EQ("name", std::string(qry.column_name(1)));
    ASSERT_EQ("phone", std::string(qry.column_name(2)));

    // Check data
    for (auto v : qry)
    {
        std::string name, phone, id;
        v.getter() >> id >> name >> phone;
        std::cout << "\t" << name << "\t" << phone << std::endl;

        ASSERT_EQ("1", id);
        ASSERT_EQ("Mike", name);
        ASSERT_EQ("555-1234", phone);
    }

    // Cleanup
    db.disconnect();
    std::remove("test.db");
}