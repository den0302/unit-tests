/**
* @file Menu.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header for Menu declarations.
 */

#ifndef MENU_H
#define MENU_H
#include "../Accounts/Account.h"
#include "../Accounts/AuthManager.h"
#include "../Graphs/ZooGraph.h"
#include <string>

/**
 * @class Menu
 * @brief Represents the Menu entity in the zoo management system.
 * @details This class is part of the Zoo Management project.
 */
/**
 * @example
 * Menu* obj = nullptr; // Create or obtain an instance
 * // Use the public interface as needed.
 */

class Menu {

public:
    /**
     * @brief Method showFor.
     * @param username Parameter.
     * @param role Parameter.
     * @param auth Parameter.
     * @param zoo Parameter.
     * @return Result value.
     */
    static void showFor(const std::string& username, Role role, AuthManager& auth, ZooGraph& zoo);
};

#endif //MENU_H
