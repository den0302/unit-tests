/**
* @file AuthManager.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header defining AuthManager interfaces.
 */

#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "Account.h"
#include <optional>
#include <string>
#include <vector>
class AccountRepository;

/**
 * @class AuthManager
 * @brief Represents the AuthManager entity used in the Zoo Management System.
 * @details This class is part of the Zoo Management System database layer.
 */
/**
 * @example
 * AuthManager obj; // Example of using AuthManager methods.
 */

class AuthManager {

private:
    AccountRepository& repo;

public:
    /**
     * @brief Method AuthManager.
     * @param repository Parameter.
     * @return Result value.
     */
    explicit AuthManager(AccountRepository& repository);

    /**
     * @brief Method authenticateInteractive.
     * @return Result value.
     */
    std::optional<std::pair<std::string, Role>> authenticateInteractive();

    /**
     * @brief Method addAccount.
     * @param username Parameter.
     * @param password Parameter.
     * @param role Parameter.
     * @return Result value.
     */
    bool addAccount(const std::string& username, const std::string& password, Role role);
    /**
     * @brief Method removeAccount.
     * @param username Parameter.
     * @return Result value.
     */
    bool removeAccount(const std::string& username);
    /**
     * @brief Method editAccount.
     * @param username Parameter.
     * @return Result value.
     */
    bool editAccount(const std::string& username);

    /**
     * @brief Method accountExists.
     * @param username Parameter.
     * @return Result value.
     */
    bool accountExists(const std::string& username) const;

    /**
     * @brief Method listUsernames.
     * @return Result value.
     */
    std::vector<std::string> listUsernames() const;
};

#endif // AUTHMANAGER_H
