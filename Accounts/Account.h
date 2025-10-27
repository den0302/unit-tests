/**
 * @file Account.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header defining Account interfaces.
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <sstream>
using namespace std;

enum /**
 * @class Role
 * @brief Represents the Role entity used in the Zoo Management System.
 * @details This class is part of the Zoo Management System database layer.
 */
/**
 * @example
 * Role obj; // Example of using Role methods.
 */

class Role {

    ADMIN = 0,
    MANAGER = 1,
    EMPLOYEE = 2
};

/**
 * @class Account
 * @brief Represents the Account entity used in the Zoo Management System.
 * @details This class is part of the Zoo Management System database layer.
 */
/**
 * @example
 * Account obj; // Example of using Account methods.
 */

class Account {

private:
    string username;
    size_t passwordHash;
    Role role;

public:
/**
 * @brief Method Account.
 * @return Result value.
 */
    Account() = default;
/**
 * @brief Method Account.
 * @param u Parameter.
 * @param hash Parameter.
 * @param r Parameter.
 * @return Result value.
 */
    Account(string u, size_t hash, Role r);

/**
 * @brief Method getUsername.
 * @return Result value.
 */
    const string& getUsername() const;
/**
 * @brief Method getPasswordHash.
 * @return Result value.
 */
    size_t getPasswordHash() const;
/**
 * @brief Method getRole.
 * @return Result value.
 */
    Role getRole() const;

/**
 * @brief Method roleToString.
 * @param r Parameter.
 * @return Result value.
 */
    static string roleToString(Role r);
/**
 * @brief Method intToRole.
 * @param v Parameter.
 * @return Result value.
 */
    static Role intToRole(int v);
/**
 * @brief Method roleToInt.
 * @param r Parameter.
 * @return Result value.
 */
    static int roleToInt(Role r);

/**
 * @brief Method serialize.
 * @return Result value.
 */
    string serialize() const;
/**
 * @brief Method deserialize.
 * @param line Parameter.
 * @return Result value.
 */
    static Account deserialize(const string& line);
};


#endif //ACCOUNT_H
