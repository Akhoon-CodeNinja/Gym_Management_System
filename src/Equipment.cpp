#include "Equipment.h"

// Default constructor
Equipment::Equipment() : equipmentID(""), name(""), quantity(0), maintenanceStatus("Good"), 
                         purchaseDate(""), cost(0.0) {}

// Parameterized constructor
Equipment::Equipment(string equipmentID, string name, int quantity, string maintenanceStatus, 
                     string purchaseDate, double cost)
    : equipmentID(equipmentID), name(name), quantity(quantity), maintenanceStatus(maintenanceStatus),
      purchaseDate(purchaseDate), cost(cost) {}

// Destructor
Equipment::~Equipment() {}

// Display equipment details
void Equipment::displayEquipment() const {
    cout << "\n========== Equipment Details ==========\n";
    cout << "Equipment ID: " << equipmentID << endl;
    cout << "Name: " << name << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Maintenance Status: " << maintenanceStatus << endl;
    cout << "Purchase Date: " << purchaseDate << endl;
    cout << "Cost: $" << cost << endl;
    cout << "=======================================\n";
}

// Update maintenance status
void Equipment::updateMaintenanceStatus(const string& status) {
    maintenanceStatus = status;
    cout << "Maintenance status for " << name << " updated to: " << status << endl;
}

// Update quantity
void Equipment::updateQuantity(int newQuantity) {
    quantity = newQuantity;
    cout << "Quantity for " << name << " updated to: " << newQuantity << endl;
}

// Getters
string Equipment::getEquipmentID() const { return equipmentID; }
string Equipment::getName() const { return name; }
int Equipment::getQuantity() const { return quantity; }
string Equipment::getMaintenanceStatus() const { return maintenanceStatus; }
string Equipment::getPurchaseDate() const { return purchaseDate; }
double Equipment::getCost() const { return cost; }

// Setters
void Equipment::setEquipmentID(const string& equipmentID) { this->equipmentID = equipmentID; }
void Equipment::setName(const string& name) { this->name = name; }
void Equipment::setQuantity(int quantity) { this->quantity = quantity; }
void Equipment::setMaintenanceStatus(const string& maintenanceStatus) { this->maintenanceStatus = maintenanceStatus; }
void Equipment::setPurchaseDate(const string& purchaseDate) { this->purchaseDate = purchaseDate; }
void Equipment::setCost(double cost) { this->cost = cost; }