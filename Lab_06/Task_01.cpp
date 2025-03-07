#include<iostream>
using namespace std;

class Employee{
public:
string name;
float salary;

Employee(string name, float salary) : name(name), salary(salary) {}

void displayDetails(){
    cout<<"Employee Name: "<<name<<endl;
    cout<<"Employee Salary: "<<salary<<endl;
}
  
};

class Manager : public Employee{
    public:
    float bonus;

    Manager(string name,float salary,float bonus) : Employee(name,salary), bonus(bonus) {}
  
    void displayDetails(){
        Employee ::displayDetails();
        cout<<"Bonus: "<<bonus<<endl;
    }
};

int main(){
    Manager kabeer("Kabeer",25000.00,3000);
    kabeer.displayDetails();
}
