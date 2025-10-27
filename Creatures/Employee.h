/**
 * @file Employee.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header for Employee declarations.
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <vector>
#include <string>

using namespace std;

class ZooGraph;

/**
 * @class Employee
 * @brief Represents the Employee entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Employee* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Employee {

private:
    string id;
    string name;
    int age;
    int salary;
    int experience;
    vector<string> aviaryIds;

public:
/**
 * @brief Method Employee.
 * @param id Parameter.
 * @param name Parameter.
 * @param age Parameter.
 * @param salary Parameter.
 * @param experience Parameter.
 * @param aviaryIds Parameter.
 */
    Employee(const string& id, const string& name, int age, int salary, int experience, const string& aviaryIds);
/**
 * @brief Method Employee.
 * @param name Parameter.
 * @param age Parameter.
 * @param salary Parameter.
 * @param experience Parameter.
 */
    Employee(const string& name, int age, int salary, int experience);

/**
 * @brief Method getId.
 * @return Result value.
 */
    [[nodiscard]] string getId() const;
/**
 * @brief Method getAge.
 * @return Result value.
 */
    [[nodiscard]] int getAge() const;
/**
 * @brief Method getSalary.
 * @return Result value.
 */
    [[nodiscard]] int getSalary() const;
/**
 * @brief Method getExperience.
 * @return Result value.
 */
    [[nodiscard]] int getExperience() const;
/**
 * @brief Method getName.
 * @return Result value.
 */
    [[nodiscard]] string getName() const;

/**
 * @brief Method getAssignedAviaries.
 * @return Result value.
 */
    [[nodiscard]] string getAssignedAviaries() const;
/**
 * @brief Method setAssignedAviaries.
 * @param assignedAviaries Parameter.
 */
    void setAssignedAviaries(const string& assignedAviaries);
/**
 * @brief Method setAssignedAviaries.
 * @param assignedAviaries Parameter.
 */
    void setAssignedAviaries(vector<string> assignedAviaries);
/**
 * @brief Method assignedAviaries.
 * @param assignedAviaries Parameter.
 * @return Result value.
 */
    vector<string> assignedAviaries(const string& assignedAviaries);


/**
 * @brief Method getFullInfoAboutEmployee.
 * @return Result value.
 */
    [[nodiscard]] string getFullInfoAboutEmployee() const;
/**
 * @brief Method listAviaries.
 * @return Result value.
 */
    [[nodiscard]] string listAviaries() const ;
/**
 * @brief Method replaceAviary.
 * @param fromAviary Parameter.
 * @param toAviary Parameter.
 */
    void replaceAviary(const string& fromAviary, const string& toAviary);
/**
 * @brief Method removeAviary.
 * @param aviaryId Parameter.
 */
    void removeAviary(const string& aviaryId);
/**
 * @brief Method isAssigned.
 * @return Result value.
 */
    [[nodiscard]] bool isAssigned() const;

/**
 * @brief Method getAviaryIds.
 * @return Result value.
 */
    [[nodiscard]] const vector<string>& getAviaryIds() const;
/**
 * @brief Method assignAviary.
 * @param aviary Parameter.
 */
    void assignAviary(const string& aviary);
};

#endif //EMPLOYEE_H
