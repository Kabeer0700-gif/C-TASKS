#include<iostream>
using namespace std;

class Doctor{
    private:
    string name;
    string specialization;
    int experience;

    public:
    Doctor(string name, string specialization,int experience): name(name), specialization(specialization), experience(experience) {}

    string getName() { return name;}
    string getSpecialization() {return specialization;}
    int getExperience() {return experience; }
    
    void viewDoctor(){
        cout<<"Doctor details: "<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Specialization: "<<specialization<<endl;
        cout<<"Experience: "<<experience<<endl;

    }
};

class Hospital{
 private:
  Doctor* doctor[10];
   int count;
   string name;
  public:
  Hospital(string name) : count(0), name(name) {}
  void addDoctor(Doctor* d){
    if(count < 10)
    {
        doctor[count++] = d;
        cout<<"Doctor added successfully"<<endl;
    }else{
        cout<<"Doctor list is full"<<endl;
    }
  }

  void displayDoc(){
    for(int i=0; i<count; i++){
        cout<<"\n";
        doctor[i]->viewDoctor();
    }
  }

  ~Hospital(){
   for(int i=0; i<count; i++) delete[] doctor[i];
  }
};

int main(){
    Hospital h1("CITY");

    h1.addDoctor(new Doctor("Kabeer","Heart Specialist",5));
    h1.addDoctor(new Doctor("Shamveel","Child Specialist",7));
    h1.addDoctor(new Doctor("Usman","Kidney Specialist",3));
    h1.displayDoc();


}
