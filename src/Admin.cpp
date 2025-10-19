#include "Admin.h"

// Default constructor
Admin::Admin() : adminID(""), username(""), password(""), fullName(""), email("") {}

// Parameterized constructor
Admin::Admin(string adminID, string username, string password, string fullName, string email)
    : adminID(adminID), username(username), password(password), fullName(fullName), email(email) {}

// Destructor
Admin::~Admin() {}

// Login method
bool Admin::login(const string& inputUsername, const string& inputPassword) {
    if (username == inputUsername && password == inputPassword) {
        cout << "\nLogin successful! Welcome, " << fullName << "!" << endl;
        return true;
    } else {
        cout << "\nInvalid username or password!" << endl;
        return false;
    }
}

// Display admin information
void Admin::displayAdminInfo() const {
    cout << "\n========== Admin Information ==========\n";
    cout << "Admin ID: " << adminID << endl;
    cout << "Username: " << username << endl;
    cout << "Full Name: " << fullName << endl;
    cout << "Email: " << email << endl;
    cout << "=======================================\n";
}

// Change password
void Admin::changePassword(const string& oldPassword, const string& newPassword) {
    if (password == oldPassword) {
        password = newPassword;
        cout << "Password changed successfully!" << endl;
    } else {
        cout << "Old password is incorrect!" << endl;
    }
}

// Getters
string Admin::getAdminID() const { return adminID; }
string Admin::getUsername() const { return username; }
string Admin::getFullName() const { return fullName; }
string Admin::getEmail() const { return email; }

// Setters
void Admin::setAdminID(const string& adminID) { this->adminID = adminID; }
void Admin::setUsername(const string& username) { this->username = username; }
void Admin::setPassword(const string& password) { this->password = password; }
void Admin::setFullName(const string& fullName) { this->fullName = fullName; }
void Admin::setEmail(const string& email) { this->email = email; }