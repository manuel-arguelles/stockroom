#include "sqlite_database.h"
#include <iostream>

namespace Stockroom::Database {

    int callback(void* user_data, int columns, char** values, char** names)
    {
        std::cout << "Got columns: " << columns << std::endl;
        for(size_t i = 0; i < columns; ++i) {
            std::cout << "name: " << names[i] << " value " << values[i]
                      << std::endl;
        }
        return 0;
    }
    bool Sqlite_database::connect(const std::string& name)
    {
        const int status = sqlite3_open(name.c_str(), &context);

        if(status == SQLITE_OK) migrate();

        return status == SQLITE_OK;
    }

    void Sqlite_database::disconnect()
    {
        sqlite3_close(context);
    }

    void Sqlite_database::migrate()
    {
        const int result = sqlite3_exec(context, "PRAGMA user_version",
                                        &callback, nullptr, nullptr);
    }

} // namespace Stockroom::Database
