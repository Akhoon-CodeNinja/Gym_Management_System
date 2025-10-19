#ifndef TRAINER_H
#define TRAINER_H

#include "Person.h"
#include <vector>

// Forward declaration to avoid circular dependency
class Member;

// Class representing a gym trainer
// Demonstrates: Inheritance, Aggregation, Encapsulation
class Trainer : public Person {
private:
    string trainerID;
    string specialty;  // e.g., "Cardio", "Strength Training", "Yoga"
    double salary;
    vector<string> assignedMemberIDs;  // Aggregation: Trainer works with Members

public:
    // Constructors
    Trainer();
    Trainer(string name, int age, string gender, string contactNumber, string email, 
            string address, string trainerID, string specialty, double salary);
    
    // Destructor
    ~Trainer();
    
    // Override displayInfo from Person (Polymorphism)
    void displayInfo() const override;
    
    // Trainer-specific methods
    void assignMember(const string& memberID);
    void removeMember(const string& memberID);
    void viewAssignedMembers() const;
    
    // Getters
    string getTrainerID() const;
    string getSpecialty() const;
    double getSalary() const;
    vector<string> getAssignedMemberIDs() const;
    
    // Setters
    void setTrainerID(const string& trainerID);
    void setSpecialty(const string& specialty);
    void setSalary(double salary);
};

#endif