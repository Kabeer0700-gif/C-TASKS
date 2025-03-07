#include<iostream>
using namespace std;

class Person{
 public:
 string name;
 int age;

 Person(string name, int age) : name(name), age(age) {}

 void display(){
    cout<<"Details:-"<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
 }
};

class Teacher : protected Person{
 public:
 string subject;

 Teacher(string name, int age, string subject) : Person(name,age), subject(subject) {}
 
 void display(){
    Person:: display();
    cout<<"Subject Expertise: "<<subject<<endl;
 }
 
};

class Researcher : protected Teacher{
 public:
 string researchArea;

 Researcher(string name, int age, string subject, string researchArea) : Teacher(name,age,subject), researchArea(researchArea) {}

 void display(){
    Teacher:: display();
    cout<<"Research Area: "<<researchArea<<endl;
 }
};

class Professor : protected Researcher{
 public:
 int publications;

 Professor(string name, int age, string subject, string researchArea, int publications) : Researcher(name,age,subject,researchArea), publications(publications) {}

 void display(){
    Researcher:: display();
    cout<<"Publications: "<<publications<<endl;
 }
};

int main(){
    Professor Talha("Talha Shahid", 28, "Object-Oriented Programming", "Cs",10);
    Talha.display();
}