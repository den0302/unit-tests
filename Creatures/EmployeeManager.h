/**
 * @file EmployeeManager.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header for EmployeeManager declarations.
 */

#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H
#include "Employee.h"
#include "../DatabaseManager/EmployeeRepository.h"
#include <unordered_map>
#include <memory>

/**
 * @class EmployeeManager
 * @brief Represents the EmployeeManager entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * EmployeeManager* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class EmployeeManager {

private:
    ZooGraph& zooGraph;
    EmployeeRepository& employeeRepo;
    unordered_map<string, shared_ptr<Employee>> employees;
public:
/**
 * @brief Method EmployeeManager.
 * @param graph Parameter.
 * @param employeeRepo Parameter.
 */
    EmployeeManager(ZooGraph& graph, EmployeeRepository& employeeRepo);

/**
 * @brief Method loadEmployeesFromRepo.
 * @param employeeRepo Parameter.
 */
    void loadEmployeesFromRepo(EmployeeRepository& employeeRepo);

/**
 * @brief Method getEmployee.
 * @param id Parameter.
 * @return Result value.
 */
    shared_ptr<Employee> getEmployee(const string& id) const;
/**
 * @brief Method getAllEmployees.
 * @return Result value.
 */
    const unordered_map<string, shared_ptr<Employee>>& getAllEmployees() const;
/**
 * @brief Method getUnassignedEmployees.
 * @return Result value.
 */
    vector<shared_ptr<Employee>> getUnassignedEmployees() const;

/**
 * @brief Method addEmployee.
 * @param employee Parameter.
 * @return Result value.
 */
    bool addEmployee(const shared_ptr<Employee>& employee);
    bool assignEmployeeToAviary(const string& employeeId, const string& aviaryId);//updateAviaryEmployee in Aviary?ad
/**
 * @brief Method removeEmployee.
 * @param id Parameter.
 * @return Result value.
 */
    bool removeEmployee(const string& id);
    bool reassignEmployee(const string& empId, const string& fromAviaryId, const string& toAviaryId); //updateAviaryEmployee in Aviary
    bool removeEmployeeFromAviary(const string& employeeId, const string& aviaryId);//updateAviaryEmployee in Aviary

/**
 * @brief Method listAllEmployees.
 */
    void listAllEmployees() const;
};
#endif //EMPLOYEEMANAGER_H
