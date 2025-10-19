/*
 * Gym Management System
 * A comprehensive Object-Oriented C++ console application
 * 
 * Features:
 * - Member Management (Add, Remove, Update, Attendance)
 * - Trainer Management (Add, Remove, Assign)
 * - Plan Management (Create plans, View plans)
 * - Equipment Management (Add, Remove, Maintenance tracking)
 * - Billing System (Generate bills, Process payments)
 * - Reporting System (Financial and operational reports)
 * - Admin Authentication
 * 
 * OOP Concepts Demonstrated:
 * - Encapsulation: Private data members with public getters/setters
 * - Abstraction: Abstract base class (Person) with pure virtual functions
 * - Inheritance: Member and Trainer inherit from Person
 * - Polymorphism: Virtual functions overridden in derived classes
 * - Composition: Gym owns Members, Trainers, Equipment, etc.
 * - Aggregation: Trainer works with Members, Member has a Plan
 */

#include "Gym.h"
#include <iostream>

using namespace std;

void displayWelcomeBanner() {
    cout << "\n";
    cout << "╔═══════════════════════════════════════════════════════╗\n";
    cout << "║                                                       ║\n";
    cout << "║          WELCOME TO GYM MANAGEMENT SYSTEM             ║\n";
    cout << "║                                                       ║\n";
    cout << "║         Your Complete Fitness Management Solution    ║\n";
    cout << "║                                                       ║\n";
    cout << "╚═══════════════════════════════════════════════════════╝\n";
    cout << "\n";
}

int main() {
    displayWelcomeBanner();
    
    // Create gym instance
    Gym* fitnessCenterGym = new Gym("FitLife Fitness Center", "123 Fitness Street, Health City");
    
    // Initialize with sample data for demonstration
    cout << "Initializing system with sample data...\n";
    fitnessCenterGym->initializeSampleData();
    
    // Admin login
    cout << "\n=== ADMIN LOGIN REQUIRED ===\n";
    cout << "(Default credentials - Username: admin, Password: admin123)\n";
    
    int loginAttempts = 0;
    const int maxAttempts = 3;
    bool loginSuccess = false;
    
    while (loginAttempts < maxAttempts && !loginSuccess) {
        loginSuccess = fitnessCenterGym->adminLogin();
        
        if (!loginSuccess) {
            loginAttempts++;
            if (loginAttempts < maxAttempts) {
                cout << "\nAttempts remaining: " << (maxAttempts - loginAttempts) << endl;
            } else {
                cout << "\nMaximum login attempts exceeded. System locked.\n";
                delete fitnessCenterGym;
                return 1;
            }
        }
    }
    
    // Display gym information after successful login
    fitnessCenterGym->displayGymInfo();
    
    // Show main menu
    fitnessCenterGym->showMainMenu();
    
    // Clean up
    cout << "\n=== System Shutdown ===\n";
    cout << "Cleaning up resources...\n";
    delete fitnessCenterGym;
    
    cout << "Thank you for using Gym Management System!\n";
    cout << "Goodbye!\n\n";
    
    return 0;
}