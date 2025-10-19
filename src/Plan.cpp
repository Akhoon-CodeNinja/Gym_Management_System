#include "Plan.h"

// Default constructor
Plan::Plan() : planID(""), planName(""), durationMonths(0), price(0.0), description("") {}

// Parameterized constructor
Plan::Plan(string planID, string planName, int durationMonths, double price, string description)
    : planID(planID), planName(planName), durationMonths(durationMonths), price(price), description(description) {}

// Destructor
Plan::~Plan() {}

// Display plan details
void Plan::showPlanDetails() const {
    cout << "\n========== Plan Details ==========\n";
    cout << "Plan ID: " << planID << endl;
    cout << "Plan Name: " << planName << endl;
    cout << "Duration: " << durationMonths << " months" << endl;
    cout << "Price: $" << price << endl;
    cout << "Description: " << description << endl;
    cout << "==================================\n";
}

// Getters
string Plan::getPlanID() const { return planID; }
string Plan::getPlanName() const { return planName; }
int Plan::getDurationMonths() const { return durationMonths; }
double Plan::getPrice() const { return price; }
string Plan::getDescription() const { return description; }

// Setters
void Plan::setPlanID(const string& planID) { this->planID = planID; }
void Plan::setPlanName(const string& planName) { this->planName = planName; }
void Plan::setDurationMonths(int durationMonths) { this->durationMonths = durationMonths; }
void Plan::setPrice(double price) { this->price = price; }
void Plan::setDescription(const string& description) { this->description = description; }