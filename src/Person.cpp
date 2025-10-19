#include "Person.h"

// Default constructor
Person::Person() : name(""), age(0), gender(""), contactNumber(""), email(""), address("") {}

// Parameterized constructor
Person::Person(string name, int age, string gender, string contactNumber, string email, string address)
    : name(name), age(age), gender(gender), contactNumber(contactNumber), email(email), address(address) {}

// Virtual destructor
Person::~Person() {}

// Getters
string Person::getName() const { return name; }
int Person::getAge() const { return age; }
string Person::getGender() const { return gender; }
string Person::getContactNumber() const { return contactNumber; }
string Person::getEmail() const { return email; }
string Person::getAddress() const { return address; }

// Setters
void Person::setName(const string& name) { this->name = name; }
void Person::setAge(int age) { this->age = age; }
void Person::setGender(const string& gender) { this->gender = gender; }
void Person::setContactNumber(const string& contactNumber) { this->contactNumber = contactNumber; }
void Person::setEmail(const string& email) { this->email = email; }
void Person::setAddress(const string& address) { this->address = address; }