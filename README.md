# 🏋️ Gym Management System

A comprehensive **Object-Oriented C++ Console Application** for managing gym operations efficiently. This system demonstrates core OOP principles and provides a complete solution for fitness center management.

## ✨ Features

### 👥 Member Management
- Add, remove, and update member records
- Track member attendance with detailed logs
- Search members by ID
- Manage membership plans and payment status

### 💪 Trainer Management
- Register trainers with specialties (Cardio, Strength Training, Yoga, etc.)
- Assign trainers to members
- Track trainer information and assigned members

### 📋 Plan Management
- Create custom membership plans (Basic, Standard, Premium)
- Define plan duration and pricing
- View all available plans

### 🏃 Equipment Management
- Track gym equipment inventory
- Monitor maintenance status (Good, Needs Maintenance, Under Repair)
- Update equipment quantities and conditions

### 💰 Billing System
- Generate bills for members automatically
- Process payments (Cash, Card, Online)
- Track payment status (Paid, Pending, Overdue)

### 📊 Reports & Analytics
- Financial reports (revenue, paid/pending bills)
- Member statistics and payment status
- Equipment condition overview
- Comprehensive operational reports

## 🎯 OOP Concepts Demonstrated

- **Encapsulation**: Private data members with public getters/setters
- **Abstraction**: Abstract base class (Person) with pure virtual functions
- **Inheritance**: Member and Trainer inherit from Person
- **Polymorphism**: Virtual functions overridden in derived classes
- **Composition**: Gym owns Members, Trainers, Equipment, Plans, and Billing records
- **Aggregation**: Trainer works with Members, Member has a Plan

## 🚀 Getting Started

### Prerequisites
- C++ compiler with C++11 support (g++, clang++, MSVC)

### Compilation
```bash
g++ -std=c++11 main.cpp src/*.cpp -I include -o gym_system
```

### Running the Application
```bash
./gym_system          # Linux/Mac
gym_system.exe        # Windows
```

### Default Login Credentials
- **Username**: `admin`
- **Password**: `admin123`

## 📁 Project Structure
```
Gym_Management_System/
├── include/          # Header files (.h)
├── src/              # Implementation files (.cpp)
├── main.cpp          # Entry point
└── README.md
```

## 🛠️ Technologies Used
- C++11
- Standard Template Library (STL)
- Object-Oriented Programming principles

## 📝 Sample Data
The system initializes with sample data including:
- 2 Members (John Doe, Sarah Smith)
- 2 Trainers (Mike Johnson, Emily Davis)
- 3 Plans (Basic, Standard, Premium)
- 3 Equipment items (Treadmill, Dumbbells, Exercise Bike)

## 👨‍💻 Author
Your fitness management solution built with modern C++ practices!

---
⭐ Star this repository if you find it helpful!
