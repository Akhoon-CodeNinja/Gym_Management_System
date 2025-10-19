#include "Member.h"

// Default constructor
Member::Member() : Person(), membershipID(""), memberPlan(nullptr), paymentStatus("Pending"), 
                   registrationDate(""), membershipExpiry("") {}

// Parameterized constructor
Member::Member(string name, int age, string gender, string contactNumber, string email, 
               string address, string membershipID, Plan* plan, string registrationDate)
    : Person(name, age, gender, contactNumber, email, address), 
      membershipID(membershipID), memberPlan(plan), paymentStatus("Pending"),
      registrationDate(registrationDate), membershipExpiry("") {}

// Destructor
Member::~Member() {
    // Note: We don't delete memberPlan here as it's managed by Gym class
}

// Override displayInfo (Polymorphism)
void Member::displayInfo() const {
    cout << "\n========== Member Information ==========\n";
    cout << "Membership ID: " << membershipID << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Contact: " << contactNumber << endl;
    cout << "Email: " << email << endl;
    cout << "Address: " << address << endl;
    
    if (memberPlan != nullptr) {
        cout << "Plan: " << memberPlan->getPlanName() << endl;
        cout << "Plan Duration: " << memberPlan->getDurationMonths() << " months" << endl;
        cout << "Plan Price: $" << memberPlan->getPrice() << endl;
    } else {
        cout << "Plan: No plan assigned" << endl;
    }
    
    cout << "Payment Status: " << paymentStatus << endl;
    cout << "Registration Date: " << registrationDate << endl;
    cout << "Membership Expiry: " << membershipExpiry << endl;
    cout << "Total Attendance: " << attendanceLog.size() << " days" << endl;
    cout << "========================================\n";
}

// Register member
void Member::registerMember() {
    cout << "Member " << name << " registered successfully with ID: " << membershipID << endl;
}

// Renew membership
void Member::renewMembership(Plan* newPlan) {
    memberPlan = newPlan;
    paymentStatus = "Pending";
    cout << "Membership renewed for " << name << " with " << newPlan->getPlanName() << endl;
}

// Mark attendance
void Member::markAttendance(const string& date) {
    attendanceLog.push_back(date);
    cout << "Attendance marked for " << name << " on " << date << endl;
}

// View attendance history
void Member::viewAttendanceHistory() const {
    cout << "\n========== Attendance History for " << name << " ==========\n";
    if (attendanceLog.empty()) {
        cout << "No attendance records found." << endl;
    } else {
        for (size_t i = 0; i < attendanceLog.size(); i++) {
            cout << (i + 1) << ". " << attendanceLog[i] << endl;
        }
    }
    cout << "========================================\n";
}

// Make payment
void Member::makePayment() {
    paymentStatus = "Paid";
    cout << "Payment processed successfully for " << name << endl;
}

// Getters
string Member::getMembershipID() const { return membershipID; }
Plan* Member::getMemberPlan() const { return memberPlan; }
string Member::getPaymentStatus() const { return paymentStatus; }
string Member::getRegistrationDate() const { return registrationDate; }
string Member::getMembershipExpiry() const { return membershipExpiry; }

// Setters
void Member::setMembershipID(const string& membershipID) { this->membershipID = membershipID; }
void Member::setMemberPlan(Plan* plan) { this->memberPlan = plan; }
void Member::setPaymentStatus(const string& paymentStatus) { this->paymentStatus = paymentStatus; }
void Member::setRegistrationDate(const string& registrationDate) { this->registrationDate = registrationDate; }
void Member::setMembershipExpiry(const string& membershipExpiry) { this->membershipExpiry = membershipExpiry; }