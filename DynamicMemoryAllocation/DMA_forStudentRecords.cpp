#include<iostream>
#include<string>
using namespace std;

struct Student{
 
 string name;
 int rollNo;
 int marks[3];

};

void setInfo(Student* s, int n){
    for(int i=0;i<n;i++){
    int mark=0;
        cout<<"Enter Name of Student\t";
        getline(cin, s[i].name);
        cout<<"Enter Roll Number\t";
        cin>>s[i].rollNo;
        cin.ignore();
            cout<<"ENTER MARKS OF 3 SUBJECTS"<<endl;
        while(mark<3){
            cin>>s[i].marks[mark];
            mark++;
        cin.ignore();
        }
    }
}

void displayInfo(Student* s,int n){
    for(int i=0;i<n;i++){
        cout<<"Student: "<<i+1<<endl;
        cout<<"Name: "<<s[i].name<<endl;
        cout<<"Roll NO: "<<s[i].rollNo<<endl;
        int x=0;
        while(x<3){
            cout<<"Marks of subject" <<x+1<<" "<<s[i].marks[x];
            x++;
        }
    }
}

void calculateAverage(Student* s,int n){
      float avg[n];
      for(int i=0;i<n;i++){
        avg[i]=0;
        int x=0;
        while(x<3){
         avg[i]+=s[i].marks[x]; 
         x++;  
        }
        avg[i]=avg[i]/3;
      }
    cout<<"\n\n";
      cout<<"AVERGES OF STUDENT\n";
    for(int i=0;i<n;i++){
        cout<<"Student: "<<i+1<<endl;
        cout<<avg[i]<<endl;
    }
    cout<<endl;
}



int main(){
    Student* s1;
    int n;
    cout<<"ENTER NUMBER OF STUDENTS\t";
    cin>>n;
    cin.ignore();
    s1 = new Student[n];

    setInfo(s1,n);
    displayInfo(s1,n);
    calculateAverage(s1,n);
}
    
