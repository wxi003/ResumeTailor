#include "Admin.h"
#include <iostream>

// Constructor
Admin::Admin(const std::string &id, const std::string &name, const std::string &adminID)
    : User(id, name), adminID(adminID) {}

// Manage content functionality (placeholder)
void Admin::manageContent() {
    std::cout << "Admin managing content..." << std::endl;
}
