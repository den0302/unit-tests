/**
* @file EmployeeRepository.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header defining EmployeeRepository interfaces.
 */

#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H
#include "DatabaseManager.h"
#include <unordered_map>
#include <memory>

using namespace std;

class EmployeeManager;
class Employee;

/**
 * @class EmployeeRepository
 * @brief Represents the EmployeeRepository entity used in the Zoo Management System.
 * @details This class is part of the Zoo Management System database layer.
 */
/**
 * @example
 * EmployeeRepository obj; // Example of using EmployeeRepository methods.
 */

class EmployeeRepository {

private:
    DatabaseManager& db;

public:
    EmployeeRepository(DatabaseManager& database) : db(database) {}

    /**
     * @brief Method initTable.
     */
    void initTable() ;

    /**
     * @brief Method addEmployee.
     * @param e Parameter.
     */
    void addEmployee(const Employee& e);
    /**
     * @brief Method removeEmployee.
     * @param id Parameter.
     */
    void removeEmployee(const string& id);
    /**
     * @brief Method moveEmployee.
     * @param employeeId Parameter.
     * @param oldAviary Parameter.
     * @param newAviary Parameter.
     */
    void moveEmployee(const string& employeeId, const string& oldAviary, const string& newAviary);
    /**
     * @brief Method assignEmployeeToAviary.
     * @param employeeId Parameter.
     * @param aviaryId Parameter.
     * @return Result value.
     */
    bool assignEmployeeToAviary(const string& employeeId, const string& aviaryId);
    /**
     * @brief Method removeEmployeeFromAviary.
     * @param employeeId Parameter.
     * @param aviaryId Parameter.
     * @return Result value.
     */
    bool removeEmployeeFromAviary(const string& employeeId, const string& aviaryId);

    /**
     * @brief Method getAllEmployes.
     * @return Result value.
     */
    unordered_map<string, shared_ptr<Employee>> getAllEmployes();

    /**
     * @brief Method clearAll.
     */
    void clearAll();
};

#endif //EMPLOYEEREPOSITORY_H
