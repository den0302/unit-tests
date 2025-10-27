/**
* @file AccountRepository.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header defining AccountRepository interfaces.
 */

#ifndef ACCOUNTREPOSITORY_H
#define ACCOUNTREPOSITORY_H

#include "DatabaseManager.h"
#include <string>
#include <vector>
#include <optional>
#include "../Accounts/AuthManager.h"

using namespace std;

/**
 * @class AccountRepository
 * @brief Represents the AccountRepository entity used in the Zoo Management System.
 * @details This class is part of the Zoo Management System database layer.
 */
/**
 * @example
 * AccountRepository obj; // Example of using AccountRepository methods.
 */

class AccountRepository {

private:
    DatabaseManager& db;

public:
    /**
     * @brief Method AccountRepository.
     * @param database Parameter.
     * @return Result value.
     */
    explicit AccountRepository(DatabaseManager& database);

    /**
     * @brief Method initTable.
     */
    void initTable();

    /**
     * @brief Method addAccount.
     * @param username Parameter.
     * @param passwordHash Parameter.
     * @param role Parameter.
     * @return Result value.
     */
    bool addAccount(const string& username, size_t passwordHash, Role role);
    /**
     * @brief Method removeAccount.
     * @param username Parameter.
     * @return Result value.
     */
    bool removeAccount(const string& username);
    bool updateAccount(const string& username, const string& newUsername,
                       optional<size_t> newPasswordHash, optional<Role> newRole);

    /**
     * @brief Method getAccount.
     * @param username Parameter.
     * @return Result value.
     */
    optional<Account> getAccount(const string& username);
    /**
     * @brief Method getAllAccounts.
     * @return Result value.
     */
    vector<Account> getAllAccounts();
    /**
     * @brief Method accountExists.
     * @param username Parameter.
     * @return Result value.
     */
    bool accountExists(const string& username);
};

#endif // ACCOUNTREPOSITORY_H
