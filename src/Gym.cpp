#include "Gym.h"
#include <iomanip>
#include <limits>

// Constructor
Gym::Gym(string gymName, string location) 
    : gymName(gymName), location(location), memberCounter(1000), 
      trainerCounter(2000), planCounter(3000), equipmentCounter(4000), billCounter(5000) {
    // Initialize admin with default credentials
    admin = new Admin("A001", "admin", "admin123", "System Administrator", "admin@gym.com");
}

// Destructor - Clean up all dynamically allocated memory
Gym::~Gym() {
    // Delete all members
    for (size_t i = 0; i < members.size(); i++) {
        delete members[i];
    }
    
    // Delete all trainers
    for (size_t i = 0; i < trainers.size(); i++) {
        delete trainers[i];
    }
    
    // Delete all plans
    for (size_t i = 0; i < plans.size(); i++) {
        delete plans[i];
    }
    
    // Delete all equipment
    for (size_t i = 0; i < equipment.size(); i++) {
        delete equipment[i];
    }
    
    // Delete all bills
    for (size_t i = 0; i < bills.size(); i++) {
        delete bills[i];
    }
    
    // Delete admin
    delete admin;
}

// Initialize system with sample data
void Gym::initializeSampleData() {
    // Add sample plans
    Plan* basicPlan = new Plan("P3000", "Basic Plan", 1, 30.0, "Access to gym equipment");
    Plan* standardPlan = new Plan("P3001", "Standard Plan", 3, 80.0, "Gym + Group Classes");
    Plan* premiumPlan = new Plan("P3002", "Premium Plan", 6, 150.0, "All access + Personal Trainer");
    
    plans.push_back(basicPlan);
    plans.push_back(standardPlan);
    plans.push_back(premiumPlan);
    planCounter = 3003;
    
    // Add sample members
    Member* m1 = new Member("John Doe", 25, "Male", "1234567890", "john@email.com", 
                           "123 Main St", "M1000", basicPlan, "2025-01-15");
    m1->setMembershipExpiry("2025-02-15");
    m1->setPaymentStatus("Paid");
    
    Member* m2 = new Member("Sarah Smith", 28, "Female", "0987654321", "sarah@email.com", 
                           "456 Oak Ave", "M1001", premiumPlan, "2025-01-10");
    m2->setMembershipExpiry("2025-07-10");
    m2->setPaymentStatus("Paid");
    
    members.push_back(m1);
    members.push_back(m2);
    memberCounter = 1002;
    
    // Add sample trainers
    Trainer* t1 = new Trainer("Mike Johnson", 30, "Male", "5551234567", "mike@gym.com", 
                             "789 Pine Rd", "T2000", "Strength Training", 3000.0);
    
    Trainer* t2 = new Trainer("Emily Davis", 27, "Female", "5559876543", "emily@gym.com", 
                             "321 Elm St", "T2001", "Yoga & Cardio", 2800.0);
    
    trainers.push_back(t1);
    trainers.push_back(t2);
    trainerCounter = 2002;
    
    // Add sample equipment
    Equipment* eq1 = new Equipment("E4000", "Treadmill", 5, "Good", "2024-01-01", 2000.0);
    Equipment* eq2 = new Equipment("E4001", "Dumbbells Set", 10, "Good", "2024-02-15", 500.0);
    Equipment* eq3 = new Equipment("E4002", "Exercise Bike", 3, "Needs Maintenance", "2023-12-10", 1500.0);
    
    equipment.push_back(eq1);
    equipment.push_back(eq2);
    equipment.push_back(eq3);
    equipmentCounter = 4003;
    
    cout << "\nSample data initialized successfully!" << endl;
}

// ==================== MEMBER MANAGEMENT ====================

void Gym::addMember() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string name, gender, contact, email, address;
    int age;
    
    cout << "\n========== Add New Member ==========\n";
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Gender: ";
    getline(cin, gender);
    cout << "Enter Contact Number: ";
    getline(cin, contact);
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter Address: ";
    getline(cin, address);
    
    // Show available plans
    cout << "\nAvailable Plans:\n";
    for (size_t i = 0; i < plans.size(); i++) {
        cout << (i + 1) << ". " << plans[i]->getPlanName() 
             << " - $" << plans[i]->getPrice() 
             << " (" << plans[i]->getDurationMonths() << " months)" << endl;
    }
    
    cout << "Select Plan (1-" << plans.size() << "): ";
    int planChoice;
    cin >> planChoice;
    
    if (planChoice < 1 || planChoice > (int)plans.size()) {
        cout << "Invalid plan selection!" << endl;
        return;
    }
    
    Plan* selectedPlan = plans[planChoice - 1];
    string memberID = generateMemberID();
    
    Member* newMember = new Member(name, age, gender, contact, email, address, 
                                   memberID, selectedPlan, "2025-10-19");
    newMember->setMembershipExpiry("2025-11-19");  // Placeholder
    newMember->setPaymentStatus("Pending");
    
    members.push_back(newMember);
    cout << "\nMember added successfully! Member ID: " << memberID << endl;
}

void Gym::showMemberMenu() {
    int choice;
    
    while (true) {
        cout << "\n--- Member Management ---\n";
        cout << "1. Add Member\n";
        cout << "2. Remove Member\n";
        cout << "3. View All Members\n";
        cout << "4. Search Member\n";
        cout << "5. Update Member\n";
        cout << "6. Mark Attendance\n";
        cout << "7. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addMember();
                break;
            case 2:
                removeMember();
                break;
            case 3:
                viewAllMembers();
                break;
            case 4:
                searchMember();
                break;
            case 5:
                updateMember();
                break;
            case 6:
                markMemberAttendance();
                break;
            case 7:
                return;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}

void Gym::showTrainerMenu() {
    int choice;
    
    while (true) {
        cout << "\n--- Trainer Management ---\n";
        cout << "1. Add Trainer\n";
        cout << "2. Remove Trainer\n";
        cout << "3. View All Trainers\n";
        cout << "4. Assign Trainer to Member\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addTrainer();
                break;
            case 2:
                removeTrainer();
                break;
            case 3:
                viewAllTrainers();
                break;
            case 4:
                assignTrainerToMember();
                break;
            case 5:
                return;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}

void Gym::showEquipmentMenu() {
    int choice;
    
    while (true) {
        cout << "\n--- Equipment Management ---\n";
        cout << "1. Add Equipment\n";
        cout << "2. Remove Equipment\n";
        cout << "3. View All Equipment\n";
        cout << "4. Update Equipment Status\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addEquipment();
                break;
            case 2:
                removeEquipment();
                break;
            case 3:
                viewAllEquipment();
                break;
            case 4:
                updateEquipmentStatus();
                break;
            case 5:
                return;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}

void Gym::removeMember() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "\n========== Remove Member ==========\n";
    cout << "Enter Member ID: ";
    string memberID;
    getline(cin, memberID);
    
    for (size_t i = 0; i < members.size(); i++) {
        if (members[i]->getMembershipID() == memberID) {
            delete members[i];
            members.erase(members.begin() + i);
            cout << "Member removed successfully!" << endl;
            return;
        }
    }
    
    cout << "Member not found!" << endl;
}

void Gym::viewAllMembers() const {
    cout << "\n========== All Members ==========\n";
    if (members.empty()) {
        cout << "No members found." << endl;
        return;
    }
    
    for (size_t i = 0; i < members.size(); i++) {
        members[i]->displayInfo();
    }
}

void Gym::searchMember() const {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "\n========== Search Member ==========\n";
    cout << "Enter Member ID: ";
    string memberID;
    getline(cin, memberID);
    
    Member* member = findMemberByID(memberID);
    if (member != nullptr) {
        member->displayInfo();
    } else {
        cout << "Member not found!" << endl;
    }
}

void Gym::updateMember() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "\n========== Update Member ==========\n";
    cout << "Enter Member ID: ";
    string memberID;
    getline(cin, memberID);
    
    Member* member = findMemberByID(memberID);
    if (member == nullptr) {
        cout << "Member not found!" << endl;
        return;
    }
    
    cout << "\nWhat would you like to update?\n";
    cout << "1. Contact Number\n";
    cout << "2. Email\n";
    cout << "3. Address\n";
    cout << "4. Payment Status\n";
    cout << "Enter choice: ";
    
    int choice;
    cin >> choice;
    cin.ignore();
    
    string newValue;
    switch (choice) {
        case 1:
            cout << "Enter new contact number: ";
            getline(cin, newValue);
            member->setContactNumber(newValue);
            cout << "Contact number updated!" << endl;
            break;
        case 2:
            cout << "Enter new email: ";
            getline(cin, newValue);
            member->setEmail(newValue);
            cout << "Email updated!" << endl;
            break;
        case 3:
            cout << "Enter new address: ";
            getline(cin, newValue);
            member->setAddress(newValue);
            cout << "Address updated!" << endl;
            break;
        case 4:
            cout << "Enter payment status (Paid/Pending): ";
            getline(cin, newValue);
            member->setPaymentStatus(newValue);
            cout << "Payment status updated!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}

void Gym::markMemberAttendance() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "\n========== Mark Attendance ==========\n";
    cout << "Enter Member ID: ";
    string memberID;
    getline(cin, memberID);
    
    Member* member = findMemberByID(memberID);
    if (member != nullptr) {
        member->markAttendance("2025-10-19");
        member->viewAttendanceHistory();
    } else {
        cout << "Member not found!" << endl;
    }
}

// ==================== TRAINER MANAGEMENT ====================

void Gym::addTrainer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string name, gender, contact, email, address, specialty;
    int age;
    double salary;
    
    cout << "\n========== Add New Trainer ==========\n";
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Gender: ";
    getline(cin, gender);
    cout << "Enter Contact Number: ";
    getline(cin, contact);
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Specialty: ";
    getline(cin, specialty);
    cout << "Enter Salary: ";
    cin >> salary;
    
    string trainerID = generateTrainerID();
    
    Trainer* newTrainer = new Trainer(name, age, gender, contact, email, address, 
                                     trainerID, specialty, salary);
    
    trainers.push_back(newTrainer);
    cout << "\nTrainer added successfully! Trainer ID: " << trainerID << endl;
}

void Gym::removeTrainer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "\n========== Remove Trainer ==========\n";
    cout << "Enter Trainer ID: ";
    string trainerID;
    getline(cin, trainerID);
    
    for (size_t i = 0; i < trainers.size(); i++) {
        if (trainers[i]->getTrainerID() == trainerID) {
            delete trainers[i];
            trainers.erase(trainers.begin() + i);
            cout << "Trainer removed successfully!" << endl;
            return;
        }
    }
    
    cout << "Trainer not found!" << endl;
}

void Gym::viewAllTrainers() const {
    cout << "\n========== All Trainers ==========\n";
    if (trainers.empty()) {
        cout << "No trainers found." << endl;
        return;
    }
    
    for (size_t i = 0; i < trainers.size(); i++) {
        trainers[i]->displayInfo();
    }
}

void Gym::assignTrainerToMember() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "\n========== Assign Trainer to Member ==========\n";
    cout << "Enter Trainer ID: ";
    string trainerID;
    getline(cin, trainerID);
    
    cout << "Enter Member ID: ";
    string memberID;
    getline(cin, memberID);
    
    Trainer* trainer = findTrainerByID(trainerID);
    Member* member = findMemberByID(memberID);
    
    if (trainer != nullptr && member != nullptr) {
        trainer->assignMember(memberID);
    } else {
        cout << "Trainer or Member not found!" << endl;
    }
}

// ==================== PLAN MANAGEMENT ====================

void Gym::addPlan() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string planName, description;
    int duration;
    double price;
    
    cout << "\n========== Add New Plan ==========\n";
    cout << "Enter Plan Name: ";
    getline(cin, planName);
    cout << "Enter Duration (months): ";
    cin >> duration;
    cout << "Enter Price: ";
    cin >> price;
    cin.ignore();
    cout << "Enter Description: ";
    getline(cin, description);
    
    string planID = generatePlanID();
    
    Plan* newPlan = new Plan(planID, planName, duration, price, description);
    plans.push_back(newPlan);
    
    cout << "\nPlan added successfully! Plan ID: " << planID << endl;
}

void Gym::viewAllPlans() const {
    cout << "\n========== All Plans ==========\n";
    if (plans.empty()) {
        cout << "No plans found." << endl;
        return;
    }
    
    for (size_t i = 0; i < plans.size(); i++) {
        plans[i]->showPlanDetails();
    }
}

// ==================== EQUIPMENT MANAGEMENT ====================

void Gym::addEquipment() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string name, status, purchaseDate;
    int quantity;
    double cost;
    
    cout << "\n========== Add New Equipment ==========\n";
    cout << "Enter Equipment Name: ";
    getline(cin, name);
    cout << "Enter Quantity: ";
    cin >> quantity;
    cin.ignore();
    cout << "Enter Maintenance Status (Good/Needs Maintenance/Under Repair): ";
    getline(cin, status);
    cout << "Enter Purchase Date (YYYY-MM-DD): ";
    getline(cin, purchaseDate);
    cout << "Enter Cost: ";
    cin >> cost;
    
    string equipmentID = generateEquipmentID();
    
    Equipment* newEquipment = new Equipment(equipmentID, name, quantity, status, purchaseDate, cost);
    equipment.push_back(newEquipment);
    
    cout << "\nEquipment added successfully! Equipment ID: " << equipmentID << endl;
}

void Gym::removeEquipment() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "\n========== Remove Equipment ==========\n";
    cout << "Enter Equipment ID: ";
    string equipmentID;
    getline(cin, equipmentID);
    
    for (size_t i = 0; i < equipment.size(); i++) {
        if (equipment[i]->getEquipmentID() == equipmentID) {
            delete equipment[i];
            equipment.erase(equipment.begin() + i);
            cout << "Equipment removed successfully!" << endl;
            return;
        }
    }
    
    cout << "Equipment not found!" << endl;
}

void Gym::viewAllEquipment() const {
    cout << "\n========== All Equipment ==========\n";
    if (equipment.empty()) {
        cout << "No equipment found." << endl;
        return;
    }
    
    for (size_t i = 0; i < equipment.size(); i++) {
        equipment[i]->displayEquipment();
    }
}

void Gym::updateEquipmentStatus() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "\n========== Update Equipment Status ==========\n";
    cout << "Enter Equipment ID: ";
    string equipmentID;
    getline(cin, equipmentID);
    
    Equipment* eq = findEquipmentByID(equipmentID);
    if (eq != nullptr) {
        cout << "Enter new status (Good/Needs Maintenance/Under Repair): ";
        string newStatus;
        getline(cin, newStatus);
        eq->updateMaintenanceStatus(newStatus);
    } else {
        cout << "Equipment not found!" << endl;
    }
}

// ==================== BILLING MANAGEMENT ====================

void Gym::generateBillForMember() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "\n========== Generate Bill ==========\n";
    cout << "Enter Member ID: ";
    string memberID;
    getline(cin, memberID);
    
    Member* member = findMemberByID(memberID);
    if (member == nullptr) {
        cout << "Member not found!" << endl;
        return;
    }
    
    Plan* plan = member->getMemberPlan();
    if (plan == nullptr) {
        cout << "Member has no plan assigned!" << endl;
        return;
    }
    
    string billID = generateBillID();
    double amount = plan->getPrice();
    
    cout << "Enter payment method (Cash/Card/Online): ";
    string paymentMethod;
    getline(cin, paymentMethod);
    
    Billing* newBill = new Billing(billID, memberID, amount, "2025-10-19", paymentMethod, "Pending");
    bills.push_back(newBill);
    
    newBill->generateBill();
    newBill->displayBill();
}

void Gym::viewAllBills() const {
    cout << "\n========== All Bills ==========\n";
    if (bills.empty()) {
        cout << "No bills found." << endl;
        return;
    }
    
    for (size_t i = 0; i < bills.size(); i++) {
        bills[i]->displayBill();
    }
}

void Gym::processBillPayment() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "\n========== Process Bill Payment ==========\n";
    cout << "Enter Bill ID: ";
    string billID;
    getline(cin, billID);
    
    Billing* bill = findBillByID(billID);
    if (bill != nullptr) {
        bill->markAsPaid();
        
        // Update member payment status
        Member* member = findMemberByID(bill->getMemberID());
        if (member != nullptr) {
            member->makePayment();
        }
    } else {
        cout << "Bill not found!" << endl;
    }
}

// ==================== REPORTS ====================

void Gym::generateReports() const {
    cout << "\n========== Gym Management System Reports ==========\n";
    cout << "Gym Name: " << gymName << endl;
    cout << "Location: " << location << endl;
    cout << "\n--- Summary ---\n";
    cout << "Total Members: " << members.size() << endl;
    cout << "Total Trainers: " << trainers.size() << endl;
    cout << "Total Plans: " << plans.size() << endl;
    cout << "Total Equipment: " << equipment.size() << endl;
    cout << "Total Bills: " << bills.size() << endl;
    
    // Revenue calculation
    double totalRevenue = 0.0;
    int paidBills = 0;
    for (size_t i = 0; i < bills.size(); i++) {
        if (bills[i]->getStatus() == "Paid") {
            totalRevenue += bills[i]->getAmount();
            paidBills++;
        }
    }
    
    cout << "\n--- Financial Report ---\n";
    cout << "Total Revenue: $" << totalRevenue << endl;
    cout << "Paid Bills: " << paidBills << endl;
    cout << "Pending Bills: " << (bills.size() - paidBills) << endl;
    
    // Payment status of members
    int paidMembers = 0;
    for (size_t i = 0; i < members.size(); i++) {
        if (members[i]->getPaymentStatus() == "Paid") {
            paidMembers++;
        }
    }
    
    cout << "\n--- Member Status ---\n";
    cout << "Paid Members: " << paidMembers << endl;
    cout << "Pending Members: " << (members.size() - paidMembers) << endl;
    
    // Equipment status
    int goodEquipment = 0;
    int needsMaintenance = 0;
    for (size_t i = 0; i < equipment.size(); i++) {
        if (equipment[i]->getMaintenanceStatus() == "Good") {
            goodEquipment++;
        } else {
            needsMaintenance++;
        }
    }
    
    cout << "\n--- Equipment Status ---\n";
    cout << "Good Condition: " << goodEquipment << endl;
    cout << "Needs Maintenance: " << needsMaintenance << endl;
    cout << "===================================================\n";
}

// ==================== ADMIN FUNCTIONS ====================

bool Gym::adminLogin() {
    cout << "\n========== Admin Login ==========\n";
    cout << "Username: ";
    string username;
    cin >> username;
    cout << "Password: ";
    string password;
    cin >> password;
    
    return admin->login(username, password);
}

void Gym::displayGymInfo() const {
    cout << "\n========== Gym Information ==========\n";
    cout << "Gym Name: " << gymName << endl;
    cout << "Location: " << location << endl;
    cout << "Total Members: " << members.size() << endl;
    cout << "Total Trainers: " << trainers.size() << endl;
    cout << "Total Plans: " << plans.size() << endl;
    cout << "Total Equipment: " << equipment.size() << endl;
    cout << "====================================\n";
}

// ==================== HELPER METHODS ====================

Member* Gym::findMemberByID(const string& memberID) const {
    for (size_t i = 0; i < members.size(); i++) {
        if (members[i]->getMembershipID() == memberID) {
            return members[i];
        }
    }
    return nullptr;
}

Trainer* Gym::findTrainerByID(const string& trainerID) const {
    for (size_t i = 0; i < trainers.size(); i++) {
        if (trainers[i]->getTrainerID() == trainerID) {
            return trainers[i];
        }
    }
    return nullptr;
}

Plan* Gym::findPlanByID(const string& planID) const {
    for (size_t i = 0; i < plans.size(); i++) {
        if (plans[i]->getPlanID() == planID) {
            return plans[i];
        }
    }
    return nullptr;
}

Equipment* Gym::findEquipmentByID(const string& equipmentID) const {
    for (size_t i = 0; i < equipment.size(); i++) {
        if (equipment[i]->getEquipmentID() == equipmentID) {
            return equipment[i];
        }
    }
    return nullptr;
}

Billing* Gym::findBillByID(const string& billID) const {
    for (size_t i = 0; i < bills.size(); i++) {
        if (bills[i]->getBillID() == billID) {
            return bills[i];
        }
    }
    return nullptr;
}

string Gym::generateMemberID() {
    return "M" + to_string(memberCounter++);
}

string Gym::generateTrainerID() {
    return "T" + to_string(trainerCounter++);
}

string Gym::generatePlanID() {
    return "P" + to_string(planCounter++);
}

string Gym::generateEquipmentID() {
    return "E" + to_string(equipmentCounter++);
}

string Gym::generateBillID() {
    return "B" + to_string(billCounter++);
}

// ==================== MENU SYSTEMS ====================

void Gym::showMainMenu() {
    int choice;
    
    while (true) {
        cout << "\n╔════════════════════════════════════════╗\n";
        cout << "║   GYM MANAGEMENT SYSTEM - MAIN MENU    ║\n";
        cout << "╚════════════════════════════════════════╝\n";
        cout << "1. Member Management\n";
        cout << "2. Trainer Management\n";
        cout << "3. Plan Management\n";
        cout << "4. Equipment Management\n";
        cout << "5. Billing Management\n";
        cout << "6. Reports\n";
        cout << "7. Gym Information\n";
        cout << "8. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                showMemberMenu();
                break;
            case 2:
                showTrainerMenu();
                break;
            case 3:
                cout << "\n--- Plan Management ---\n";
                cout << "1. Add Plan\n";
                cout << "2. View All Plans\n";
                cout << "3. Back\n";
                cout << "Enter choice: ";
                int planChoice;
                cin >> planChoice;
                if (planChoice == 1) addPlan();
                else if (planChoice == 2) viewAllPlans();
                break;
            case 4:
                updateEquipmentStatus();
                break;
            case 5:
                return;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}

void Gym::showBillingMenu() {
    int choice;
    
    while (true) {
        cout << "\n--- Billing Management ---\n";
        cout << "1. Generate Bill for Member\n";
        cout << "2. View All Bills\n";
        cout << "3. Process Bill Payment\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                generateBillForMember();
                break;
            case 2:
                viewAllBills();
                break;
            case 3:
                processBillPayment();
                break;
            case 4:
                return;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}

void Gym::showReportsMenu() {
    int choice;
    
    while (true) {
        cout << "\n--- Reports Menu ---\n";
        cout << "1. Generate Complete Report\n";
        cout << "2. View All Members\n";
        cout << "3. View All Trainers\n";
        cout << "4. View All Equipment\n";
        cout << "5. View All Bills\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                generateReports();
                break;
            case 2:
                viewAllMembers();
                break;
            case 3:
                viewAllTrainers();
                break;
            case 4:
                viewAllEquipment();
                break;
            case 5:
                viewAllBills();
                break;
            case 6:
                return;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}
