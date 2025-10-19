#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <iostream>

using namespace std;

// Class representing gym equipment
// Demonstrates: Encapsulation
class Equipment {
private:
    string equipmentID;
    string name;
    int quantity;
    string maintenanceStatus;  // "Good", "Needs Maintenance", "Under Repair"
    string purchaseDate;
    double cost;

public:
    // Constructors
    Equipment();
    Equipment(string equipmentID, string name, int quantity, string maintenanceStatus, 
              string purchaseDate, double cost);
    
    // Destructor
    ~Equipment();
    
    // Equipment methods
    void displayEquipment() const;
    void updateMaintenanceStatus(const string& status);
    void updateQuantity(int newQuantity);
    
    // Getters
    string getEquipmentID() const;
    string getName() const;
    int getQuantity() const;
    string getMaintenanceStatus() const;
    string getPurchaseDate() const;
    double getCost() const;
    
    // Setters
    void setEquipmentID(const string& equipmentID);
    void setName(const string& name);
    void setQuantity(int quantity);
    void setMaintenanceStatus(const string& maintenanceStatus);
    void setPurchaseDate(const string& purchaseDate);
    void setCost(double cost);
};

#endif