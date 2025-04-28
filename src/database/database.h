#ifndef STOCKROOM_DATABASE_H
#define STOCKROOM_DATABASE_H

#include <string>

namespace Stockroom::Database {

    /**
     * Database interface.
     */
    class Database {
    public:
        /**
         * Destroys an instance of the class.
         */
        virtual ~Database() = default;

        /**
         * Connects to the database.
         *
         * @param name The filename or host of the database.
         *
         * @returns <tt>true</tt> if the connection was succesfully; otherwise,
         * <tt>false</tt>.
         */
        virtual bool connect(const std::string& name) = 0;

        /**
         * Disconnects from the database.
         */
        virtual void disconnect() = 0;
    };

} // namespace Stockroom::Database

#endif
