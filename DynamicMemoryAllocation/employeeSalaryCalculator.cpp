#include<iostream>
#include<string>
using namespace std;

struct Employees{
 
    string name;
    int hoursWorked;
    int hourlyRate;

};

void setInfo(Employees* e,int n){
    for(int i=0;i<n;i++){
        cout<<"EMPLOYEE "<<i+1<<endl;
        cout<<"Enter Name of Employee"<<endl;
        getline(cin, e[i].name);
        cout<<"Enter hours worked"<<endl;
        cin>>e[i].hoursWorked;
        cin.ignore();
        cout<<"Enter hourly Rate"<<endl;
        cin>>e[i].hourlyRate;
        cin.ignore();
      
    }
}
void showInfo(Employees* e,int n){
    for(int i=0;i<n;i++){
        cout<<"\n";
        cout<<"EMPLOYEE "<<i+1<<endl;
        cout<<"Name of Employee: "<<e[i].name<<endl;
        cout<<"Salary of employee: "<<(e[i].hourlyRate * e[i].hoursWorked)<<endl;
        cout<<"\n";
      
    }
}
int main(){
    int numberOfEmployees;
    cout<<"ENTER NUMBER OF EMPLOYEES\t";
    cin>>numberOfEmployees;
    cin.ignore();
    Employees* E;
    E = new Employees[numberOfEmployees];
    setInfo(E,numberOfEmployees);
    showInfo(E,numberOfEmployees);
    delete[] E;
}