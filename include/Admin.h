#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <iostream>

using namespace std;

// Class representing system administrator
// Demonstrates: Encapsulation
class Admin {
private:
    string adminID;
    string username;
    string password;
    string fullName;
    string email;

public:
    // Constructors
    Admin();
    Admin(string adminID, string username, string password, string fullName, string email);
    
    // Destructor
    ~Admin();
    
    // Admin methods
    bool login(const string& inputUsername, const string& inputPassword);
    void displayAdminInfo() const;
    void changePassword(const string& oldPassword, const string& newPassword);
    
    // Getters
    string getAdminID() const;
    string getUsername() const;
    string getFullName() const;
    string getEmail() const;
    
    // Setters
    void setAdminID(const string& adminID);
    void setUsername(const string& username);
    void setPassword(const string& password);
    void setFullName(const string& fullName);
    void setEmail(const string& email);
};

#endif