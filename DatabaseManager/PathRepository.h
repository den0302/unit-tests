/**
* @file PathRepository.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header defining PathRepository interfaces.
 */

#ifndef PATHREPOSITORY_H
#define PATHREPOSITORY_H

#include "DatabaseManager.h"
#include <unordered_map>
#include <vector>
#include <memory>
#include <iostream>
#include <string>

using namespace std;

class Path;

/**
 * @class PathRepository
 * @brief Represents the PathRepository entity used in the Zoo Management System.
 * @details This class is part of the Zoo Management System database layer.
 */
/**
 * @example
 * PathRepository obj; // Example of using PathRepository methods.
 */

class PathRepository {

private:
    DatabaseManager& db;

public:
    explicit PathRepository(DatabaseManager& database) : db(database) {}

    /**
     * @brief Method initTable.
     */
    void initTable();

    /**
     * @brief Method addPath.
     * @param fromId Parameter.
     * @param toId Parameter.
     * @param length Parameter.
     */
    void addPath(const string& fromId, const string& toId, double length);

    /**
     * @brief Method removePath.
     * @param fromId Parameter.
     * @param toId Parameter.
     */
    void removePath(const string& fromId, const string& toId);

    /**
     * @brief Method getAllPaths.
     * @return Result value.
     */
    vector<shared_ptr<Path>> getAllPaths();

    /**
     * @brief Method clearAll.
     */
    void clearAll();
};

#endif // PATHREPOSITORY_H
