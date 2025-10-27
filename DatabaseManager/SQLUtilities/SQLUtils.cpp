/**
* @file SQLUtils.cpp
 * @author Denys Freyuk
 * @date 27.10.2025
 * @version 1.0
 * @brief Implementation of SQLUtils logic for the Zoo Management System.
 */

#include "SQLUtils.h"

string escapeSQL(const string& value) {
    string escaped;
    escaped.reserve(value.size());
    for (char c : value) {
        if (c == '\'') escaped += "''";
        else escaped += c;
    }
    return escaped;
}
