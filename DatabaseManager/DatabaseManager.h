/**
* @file DatabaseManager.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header defining DatabaseManager interfaces.
 */

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <sqlite3.h>
#include <string>
#include <iostream>
using namespace std;

/**
 * @class DatabaseManager
 * @brief Represents the DatabaseManager entity used in the Zoo Management System.
 * @details This class is part of the Zoo Management System database layer.
 */
/**
 * @example
 * DatabaseManager obj; // Example of using DatabaseManager methods.
 */

class DatabaseManager {

private:
    sqlite3* db;
    string dbName;

public:
    /**
     * @brief Method DatabaseManager.
     * @param name Parameter.
     * @return Result value.
     */
    DatabaseManager(const string& name= "zoo.db");

    /**
     * @brief Method open.
     * @return Result value.
     */
    bool open();

    /**
     * @brief Method close.
     */
    void close();

    /**
     * @brief Method execute.
     * @param sql Parameter.
     * @return Result value.
     */
    bool execute(const string& sql);
    /**
     * @brief Method prepare.
     * @param sql Parameter.
     * @param stmt Parameter.
     * @return Result value.
     */
    bool prepare(const string& sql, sqlite3_stmt** stmt);

    /**
     * @brief Method getDB.
     * @return Result value.
     */
    sqlite3* getDB() const;


    /**
     * @brief Method ~DatabaseManager.
     */
    ~DatabaseManager();
};


#endif //DATABASEMANAGER_H
