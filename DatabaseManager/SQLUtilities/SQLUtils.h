/**
* @file SQLUtils.h
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Header defining SQLUtils interfaces.
 */

#ifndef SQLUTILS_H
#define SQLUTILS_H

#include <string>

using namespace std;

string escapeSQL(const std::string& value);

#endif