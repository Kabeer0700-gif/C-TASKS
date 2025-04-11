#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;
public:
    virtual void displayInfo() = 0;
    virtual void updateInfo() = 0;
};

class Patient : public Person {
    string patientID, medicalHistory, doctorAssigned;
public:
    Patient(string n, int a, string c, string pID, string mH, string dA) {
        name = n; age = a; contactNumber = c; patientID = pID; medicalHistory = mH; doctorAssigned = dA;
    }
    void displayInfo() override {
        cout << "Patient ID: " << patientID << "\nName: " << name << "\nDoctor Assigned: " << doctorAssigned << endl;
    }
    void updateInfo() override {
        cout << "Updating Patient Info..." << endl;
    }
};

class Doctor : public Person {
    string specialization;
    double consultationFee;
    string patientList;
public:
    Doctor(string n, int a, string c, string s, double f, string pL) {
        name = n; age = a; contactNumber = c; specialization = s; consultationFee = f; patientList = pL;
    }
    void displayInfo() override {
        cout << "Doctor Name: " << name << "\nSpecialization: " << specialization << endl;
    }
    void updateInfo() override {
        cout << "Updating Doctor Info..." << endl;
    }
};

class Nurse : public Person {
    string assignedWard;
    string shiftTimings;
public:
    Nurse(string n, int a, string c, string ward, string shift) {
        name = n; age = a; contactNumber = c; assignedWard = ward; shiftTimings = shift;
    }
    void displayInfo() override {
        cout << "Nurse Name: " << name << "\nWard: " << assignedWard << endl;
    }
    void updateInfo() override {
        cout << "Updating Nurse Info..." << endl;
    }
};

class Administrator : public Person {
    string department;
    double salary;
public:
    Administrator(string n, int a, string c, string d, double s) {
        name = n; age = a; contactNumber = c; department = d; salary = s;
    }
    void displayInfo() override {
        cout << "Administrator Name: " << name << "\nDepartment: " << department << endl;
    }
    void updateInfo() override {
        cout << "Updating Staff Info..." << endl;
    }
};

int main() {
    Patient p1("Ali", 30, "0321-1234567", "P101", "Diabetes", "Dr. Ahmad");
    p1.displayInfo();

    Doctor d1("Dr. Ahmad", 50, "0300-7654321", "Cardiology", 3000, "P101, P102");
    d1.displayInfo();

    Nurse n1("Sara", 28, "0312-1112222", "Ward-5", "Night");
    n1.displayInfo();

    Administrator a1("Asad", 40, "0345-3334444", "Admin", 60000);
    a1.displayInfo();

    return 0;
}
