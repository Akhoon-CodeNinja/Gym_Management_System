#ifndef GYM_H
#define GYM_H

#include "Member.h"
#include "Trainer.h"
#include "Plan.h"
#include "Equipment.h"
#include "Billing.h"
#include "Admin.h"
#include <vector>

// Main Gym Management System class
// Demonstrates: Composition, Aggregation, Encapsulation
// This class manages all entities in the system
class Gym {
private:
    string gymName;
    string location;
    vector<Member*> members;       // Composition: Gym owns Members
    vector<Trainer*> trainers;     // Composition: Gym owns Trainers
    vector<Plan*> plans;           // Composition: Gym owns Plans
    vector<Equipment*> equipment;  // Composition: Gym owns Equipment
    vector<Billing*> bills;        // Composition: Gym owns Billing records
    Admin* admin;                  // Composition: Gym has an Admin
    
    int memberCounter;
    int trainerCounter;
    int planCounter;
    int equipmentCounter;
    int billCounter;

public:
    // Constructor
    Gym(string gymName, string location);
    
    // Destructor - Clean up all dynamically allocated memory
    ~Gym();
    
    // Initialize system with sample data
    void initializeSampleData();
    
    // Member management
    void addMember();
    void removeMember();
    void viewAllMembers() const;
    void searchMember() const;
    void updateMember();
    void markMemberAttendance();
    
    // Trainer management
    void addTrainer();
    void removeTrainer();
    void viewAllTrainers() const;
    void assignTrainerToMember();
    
    // Plan management
    void addPlan();
    void viewAllPlans() const;
    
    // Equipment management
    void addEquipment();
    void removeEquipment();
    void viewAllEquipment() const;
    void updateEquipmentStatus();
    
    // Billing management
    void generateBillForMember();
    void viewAllBills() const;
    void processBillPayment();
    
    // Reports
    void generateReports() const;
    
    // Admin functions
    bool adminLogin();
    void displayGymInfo() const;
    
    // Main menu system
    void showMainMenu();
    void showMemberMenu();
    void showTrainerMenu();
    void showEquipmentMenu();
    void showBillingMenu();
    void showReportsMenu();
    
    // Helper methods
    Member* findMemberByID(const string& memberID) const;
    Trainer* findTrainerByID(const string& trainerID) const;
    Plan* findPlanByID(const string& planID) const;
    Equipment* findEquipmentByID(const string& equipmentID) const;
    Billing* findBillByID(const string& billID) const;
    
    string generateMemberID();
    string generateTrainerID();
    string generatePlanID();
    string generateEquipmentID();
    string generateBillID();
};

#endif