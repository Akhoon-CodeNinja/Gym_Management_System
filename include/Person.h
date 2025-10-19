#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

// Base class representing a person in the gym system
// Demonstrates: Encapsulation and Abstraction
class Person {
protected:
    string name;
    int age;
    string gender;
    string contactNumber;
    string email;
    string address;

public:
    // Constructors
    Person();
    Person(string name, int age, string gender, string contactNumber, string email, string address);
    
    // Virtual destructor for proper cleanup in derived classes
    virtual ~Person();
    
    // Pure virtual function - makes this an abstract class
    virtual void displayInfo() const = 0;
    
    // Getters
    string getName() const;
    int getAge() const;
    string getGender() const;
    string getContactNumber() const;
    string getEmail() const;
    string getAddress() const;
    
    // Setters
    void setName(const string& name);
    void setAge(int age);
    void setGender(const string& gender);
    void setContactNumber(const string& contactNumber);
    void setEmail(const string& email);
    void setAddress(const string& address);
};

#endif