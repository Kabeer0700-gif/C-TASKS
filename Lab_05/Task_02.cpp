#include<iostream>
#include<string>
using namespace std;

class Student{
  private:
  string name;
  int studentId;
  int* examScores;
  int scoreCount;
  int count;
  public:
  Student(string name, int studentId) : name(name), studentId(studentId), count(0), scoreCount(5){
       examScores = new int[scoreCount];
  }

  int getStudentId() {return studentId;}
  string getName() {return name;}

  void addExamScores(int es){
        if(count < scoreCount){
            examScores[count++] = es;
            cout<<"Score added successfully"<<endl;
        }else{
            cout<<"Score is full"<<endl;
        }
  }
  void studentDetails(){
    cout<<"Name: "<<name<<endl;
    cout<<"student id: "<<studentId<<endl;
    cout<<"Exam score: "<<endl;
    for(int i=0;i<count;i++){
        cout<<examScores[i]<<endl;
    }
  }

  ~Student(){
    delete[] examScores;
  }

  Student(const Student &st){
      examScores = new int[scoreCount];
      name = st.name;
      studentId = st.studentId;
      count = 0;

  }
};

int main(){
    Student kabeer("KABEER",700);
    kabeer.addExamScores(20);
    kabeer.addExamScores(25);
    kabeer.addExamScores(30);

    Student shamveel = kabeer;

    kabeer.studentDetails();
    cout<<"\n";
    shamveel.studentDetails();
    shamveel.addExamScores(15);
    shamveel.addExamScores(10);
    shamveel.addExamScores(30);
    cout<<"\nCopied Student"<<endl;
    shamveel.studentDetails();
}