#ifndef PLAN_H
#define PLAN_H

#include <string>
#include <iostream>

using namespace std;

// Class representing a membership plan
// Demonstrates: Encapsulation
class Plan {
private:
    string planID;
    string planName;
    int durationMonths;
    double price;
    string description;

public:
    // Constructors
    Plan();
    Plan(string planID, string planName, int durationMonths, double price, string description);
    
    // Destructor
    ~Plan();
    
    // Display plan details
    void showPlanDetails() const;
    
    // Getters
    string getPlanID() const;
    string getPlanName() const;
    int getDurationMonths() const;
    double getPrice() const;
    string getDescription() const;
    
    // Setters
    void setPlanID(const string& planID);
    void setPlanName(const string& planName);
    void setDurationMonths(int durationMonths);
    void setPrice(double price);
    void setDescription(const string& description);
};

#endif