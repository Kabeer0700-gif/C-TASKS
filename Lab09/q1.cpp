#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    int id;
public:
    Patient(string n, int i) : name(n), id(i) {}
    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;
};

class InPatient : public Patient {
public:
    InPatient(string n, int i) : Patient(n, i) {}
    void displayTreatment() override {
        cout << "InPatient Treatment for " << name << endl;
    }
    double calculateCost() override {
        return 2000.0;
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, int i) : Patient(n, i) {}
    void displayTreatment() override {
        cout << "OutPatient Treatment for " << name << endl;
    }
    double calculateCost() override {
        return 500.0;
    }
};

int main() {
    Patient* p1 = new InPatient("John", 101);
    Patient* p2 = new OutPatient("Jane", 102);

    p1->displayTreatment();
    cout << "Cost: $" << p1->calculateCost() << endl;

    p2->displayTreatment();
    cout << "Cost: $" << p2->calculateCost() << endl;

    delete p1;
    delete p2;

}