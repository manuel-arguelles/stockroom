#ifndef SQLITE_DATABASE_H
#define SQLITE_DATABASE_H

#include "database.h"
#include <sqlite3.h>

namespace Stockroom::Database {
    class Sqlite_database : public Database {
    public:
        /**
         * Connect to database.
         *
         * @param name The file namde of the database to connect to.
         */
        bool connect(const std::string& name) override;

        /**
         * Disconnects from the database.
         */
        void disconnect() override;
    private:
        /**
         * Migrates the database to the current scheme.
         */
        void migrate();

        sqlite3* context;
    };

} // namespace Stockroom::Database
#endif
