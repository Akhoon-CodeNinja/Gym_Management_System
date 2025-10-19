#include "Billing.h"

// Default constructor
Billing::Billing() : billID(""), memberID(""), amount(0.0), date(""), 
                     paymentMethod(""), status("Pending") {}

// Parameterized constructor
Billing::Billing(string billID, string memberID, double amount, string date, 
                 string paymentMethod, string status)
    : billID(billID), memberID(memberID), amount(amount), date(date),
      paymentMethod(paymentMethod), status(status) {}

// Destructor
Billing::~Billing() {}

// Generate bill
void Billing::generateBill() {
    cout << "Bill generated successfully!" << endl;
    cout << "Bill ID: " << billID << " for Member ID: " << memberID << endl;
}

// Display bill details
void Billing::displayBill() const {
    cout << "\n========== Bill Details ==========\n";
    cout << "Bill ID: " << billID << endl;
    cout << "Member ID: " << memberID << endl;
    cout << "Amount: $" << amount << endl;
    cout << "Date: " << date << endl;
    cout << "Payment Method: " << paymentMethod << endl;
    cout << "Status: " << status << endl;
    cout << "==================================\n";
}

// Mark bill as paid
void Billing::markAsPaid() {
    status = "Paid";
    cout << "Bill " << billID << " marked as Paid." << endl;
}

// Getters
string Billing::getBillID() const { return billID; }
string Billing::getMemberID() const { return memberID; }
double Billing::getAmount() const { return amount; }
string Billing::getDate() const { return date; }
string Billing::getPaymentMethod() const { return paymentMethod; }
string Billing::getStatus() const { return status; }

// Setters
void Billing::setBillID(const string& billID) { this->billID = billID; }
void Billing::setMemberID(const string& memberID) { this->memberID = memberID; }
void Billing::setAmount(double amount) { this->amount = amount; }
void Billing::setDate(const string& date) { this->date = date; }
void Billing::setPaymentMethod(const string& paymentMethod) { this->paymentMethod = paymentMethod; }
void Billing::setStatus(const string& status) { this->status = status; }