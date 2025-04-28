#include "sqlite_database.h"

namespace Stockroom::Database {

    bool Sqlite_database::connect(const std::string& name)
    {
        return true;
    }

    void Sqlite_database::disconnect() {}

} // namespace Stockroom::Database
