/**
* @file AviaryRepository.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header defining AviaryRepository interfaces.
 */

#ifndef AVIARYREPOSITORY_H
#define AVIARYREPOSITORY_H

#include "DatabaseManager.h"
#include <unordered_map>
#include <memory>
#include <iostream>
class Aviary;

using namespace std;

/**
 * @class AviaryRepository
 * @brief Represents the AviaryRepository entity used in the Zoo Management System.
 * @details This class is part of the Zoo Management System database layer.
 */
/**
 * @example
 * AviaryRepository obj; // Example of using AviaryRepository methods.
 */

class AviaryRepository {

private:
    DatabaseManager& db;

public:
    explicit AviaryRepository(DatabaseManager& database) : db(database) {}

    /**
     * @brief Method initTable.
     */
    void initTable();

    /**
     * @brief Method addAviary.
     * @param a Parameter.
     */
    void addAviary(const Aviary& a);
    /**
     * @brief Method removeAviary.
     * @param id Parameter.
     */
    void removeAviary(const string& id);

    /**
     * @brief Method updateAviaryEmployee.
     * @param aviaryId Parameter.
     * @param employeeId Parameter.
     */
    void updateAviaryEmployee(const string& aviaryId, const string& employeeId);

    /**
     * @brief Method getAllAviaries.
     * @return Result value.
     */
    unordered_map<string, shared_ptr<Aviary>> getAllAviaries();

    /**
     * @brief Method clearAll.
     */
    void clearAll();
};

#endif // AVIARYREPOSITORY_H
