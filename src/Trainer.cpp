#include "Trainer.h"

// Default constructor
Trainer::Trainer() : Person(), trainerID(""), specialty(""), salary(0.0) {}

// Parameterized constructor
Trainer::Trainer(string name, int age, string gender, string contactNumber, string email, 
                 string address, string trainerID, string specialty, double salary)
    : Person(name, age, gender, contactNumber, email, address), 
      trainerID(trainerID), specialty(specialty), salary(salary) {}

// Destructor
Trainer::~Trainer() {}

// Override displayInfo (Polymorphism)
void Trainer::displayInfo() const {
    cout << "\n========== Trainer Information ==========\n";
    cout << "Trainer ID: " << trainerID << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Contact: " << contactNumber << endl;
    cout << "Email: " << email << endl;
    cout << "Address: " << address << endl;
    cout << "Specialty: " << specialty << endl;
    cout << "Salary: $" << salary << endl;
    cout << "Assigned Members: " << assignedMemberIDs.size() << endl;
    cout << "=========================================\n";
}

// Assign a member to this trainer
void Trainer::assignMember(const string& memberID) {
    assignedMemberIDs.push_back(memberID);
    cout << "Member " << memberID << " assigned to trainer " << name << endl;
}

// Remove a member from this trainer
void Trainer::removeMember(const string& memberID) {
    for (size_t i = 0; i < assignedMemberIDs.size(); i++) {
        if (assignedMemberIDs[i] == memberID) {
            assignedMemberIDs.erase(assignedMemberIDs.begin() + i);
            cout << "Member " << memberID << " removed from trainer " << name << endl;
            return;
        }
    }
    cout << "Member " << memberID << " not found in trainer's assigned list." << endl;
}

// View all assigned members
void Trainer::viewAssignedMembers() const {
    cout << "\n========== Assigned Members for Trainer " << name << " ==========\n";
    if (assignedMemberIDs.empty()) {
        cout << "No members assigned yet." << endl;
    } else {
        for (size_t i = 0; i < assignedMemberIDs.size(); i++) {
            cout << (i + 1) << ". Member ID: " << assignedMemberIDs[i] << endl;
        }
    }
    cout << "========================================\n";
}

// Getters
string Trainer::getTrainerID() const { return trainerID; }
string Trainer::getSpecialty() const { return specialty; }
double Trainer::getSalary() const { return salary; }
vector<string> Trainer::getAssignedMemberIDs() const { return assignedMemberIDs; }

// Setters
void Trainer::setTrainerID(const string& trainerID) { this->trainerID = trainerID; }
void Trainer::setSpecialty(const string& specialty) { this->specialty = specialty; }
void Trainer::setSalary(double salary) { this->salary = salary; }