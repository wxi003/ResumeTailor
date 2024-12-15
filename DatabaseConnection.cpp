#include "DatabaseConnection.h"
#include <iostream>
#include <stdexcept>
#include <mutex>

// TODO: use MySQL for testing
// Initialize static variables
std::shared_ptr<DatabaseConnection> DatabaseConnection::instance = nullptr;
std::mutex DatabaseConnection::mutex;

// Constructor
DatabaseConnection::DatabaseConnection() {
    conn = mysql_init(nullptr);
    if (!conn) {
        throw std::runtime_error("MySQL initialization failed");
    }
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 3306, nullptr, 0)) {
        throw std::runtime_error(mysql_error(conn));
    }
}

// Get instance (Singleton)
std::shared_ptr<DatabaseConnection> DatabaseConnection::getInstance() {
    std::lock_guard<std::mutex> lock(mutex);
    if (!instance) {
        instance = std::shared_ptr<DatabaseConnection>(new DatabaseConnection());
    }
    return instance;
}

// Get connection
MYSQL *DatabaseConnection::getConnection() {
    return conn;
}

// Destructor
DatabaseConnection::~DatabaseConnection() {
    if (conn) mysql_close(conn);
}
