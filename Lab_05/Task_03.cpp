#include<iostream>
using namespace std;

class Employee{
 private:
  string name;
  string designation;

  public:
  Employee(string name, string designation) : name(name) , designation(designation) {}

  void displayEmployees() {
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Designation "<<designation<<endl;
        cout<<"\n";
  }

  string getName(){ return name; }
  string getdesignation() { return designation; }

};

class Project{
 private:
  string title;
  string deadline;
  Employee *e[10];
  int count;
  public:
  Project(string title,string deadline) : title(title), deadline(deadline),count(0) {}

  void addEmployee(Employee* E){
    if(count < 10){
        e[count++] = E; 
        cout<<E->getName()<<" added successfully"<<endl;
    }
}

 void viewProjectDetails(){
      cout<<"Project Title: "<<title<<endl;
      cout<<"Deadline: "<<deadline<<endl;
      cout<<"Employees: "<<endl;
      for(int i=0; i<count; i++){
        e[i]->displayEmployees();
      }
 }


};

int main(){
    Employee kabeer("Kabeer","Manager");
    Employee Shamveel("Shamveel","Assisstant");
    Employee Usman("usman","Intern");

    Project Ai("AI","Wednesday");
    Ai.addEmployee(&kabeer);
    Ai.addEmployee(&Shamveel);
    Ai.addEmployee(&Usman);

    Ai.viewProjectDetails();
}