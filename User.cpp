#include "User.h"

// Constructor
User::User(const std::string &id, const std::string &name) : userID(id), name(name) {}

// Getters
std::string User::getUserID() const {
    return userID;
}

std::string User::getName() const {
    return name;
}
