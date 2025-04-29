#include <catch2/catch_test_macros.hpp>
#include <database/sqlite_database.h>

using Stockroom::Database::Sqlite_database;

TEST_CASE("Database is bootstraped", "[Database]")
{
    Sqlite_database database;

    REQUIRE(database.connect("/tmp/test.db") == true);
}
