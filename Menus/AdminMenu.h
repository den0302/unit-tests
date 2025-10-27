/**
* @file AdminMenu.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header for AdminMenu declarations.
 */

#ifndef ADMINMENU_H
#define ADMINMENU_H
#include "../Accounts/AuthManager.h"
#include "../Graphs/ZooGraph.h"

namespace AdminMenu {
    void show(const std::string& username, AuthManager& auth, ZooGraph& zoo);
}

#endif //ADMINMENU_H
