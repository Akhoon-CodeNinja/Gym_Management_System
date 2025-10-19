#ifndef BILLING_H
#define BILLING_H

#include <string>
#include <iostream>

using namespace std;

// Class representing billing/invoice
// Demonstrates: Encapsulation
class Billing {
private:
    string billID;
    string memberID;
    double amount;
    string date;
    string paymentMethod;  // "Cash", "Card", "Online"
    string status;  // "Paid", "Pending", "Overdue"

public:
    // Constructors
    Billing();
    Billing(string billID, string memberID, double amount, string date, 
            string paymentMethod, string status);
    
    // Destructor
    ~Billing();
    
    // Billing methods
    void generateBill();
    void displayBill() const;
    void markAsPaid();
    
    // Getters
    string getBillID() const;
    string getMemberID() const;
    double getAmount() const;
    string getDate() const;
    string getPaymentMethod() const;
    string getStatus() const;
    
    // Setters
    void setBillID(const string& billID);
    void setMemberID(const string& memberID);
    void setAmount(double amount);
    void setDate(const string& date);
    void setPaymentMethod(const string& paymentMethod);
    void setStatus(const string& status);
};

#endif