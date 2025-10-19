#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include "Plan.h"
#include <vector>

// Class representing a gym member
// Demonstrates: Inheritance, Composition, Encapsulation
class Member : public Person {
private:
    string membershipID;
    Plan* memberPlan;  // Composition: Member has a Plan
    string paymentStatus;  // "Paid" or "Pending"
    vector<string> attendanceLog;  // Stores attendance dates
    string registrationDate;
    string membershipExpiry;

public:
    // Constructors
    Member();
    Member(string name, int age, string gender, string contactNumber, string email, 
           string address, string membershipID, Plan* plan, string registrationDate);
    
    // Destructor
    ~Member();
    
    // Override displayInfo from Person (Polymorphism)
    void displayInfo() const override;
    
    // Member-specific methods
    void registerMember();
    void renewMembership(Plan* newPlan);
    void markAttendance(const string& date);
    void viewAttendanceHistory() const;
    void makePayment();
    
    // Getters
    string getMembershipID() const;
    Plan* getMemberPlan() const;
    string getPaymentStatus() const;
    string getRegistrationDate() const;
    string getMembershipExpiry() const;
    
    // Setters
    void setMembershipID(const string& membershipID);
    void setMemberPlan(Plan* plan);
    void setPaymentStatus(const string& paymentStatus);
    void setRegistrationDate(const string& registrationDate);
    void setMembershipExpiry(const string& membershipExpiry);
};

#endif