#include<iostream>
#include<string>


using namespace std;

struct Books{
  string author;
  string title;
  int year;
};

void setInfo(Books* b,int n){
    
    for(int i=0;i<n;i++){
        cout<<"Book "<<i+1<<endl;
        cout<<"Enter Name of author"<<endl;
        getline(cin,b[i].author);
        cout<<"Enter book Title"<<endl;
        getline(cin,b[i].title);
        cout<<"Enter pulished year"<<endl;
        cin>>b[i].year;
        cin.ignore();
      
    }
}

void displayInfo(Books* b,int n){
    for(int i=0;i<n;i++){
        cout<<"\n";
        cout<<"BOOK "<<i+1<<endl;
        cout<<"Name of author: "<<b[i].author;
        cout<<"\n";
        cout<<"book Title: "<<b[i].title;
        cout<<"\n";
        cout<<"pulished year: "<<b[i].year;
        cout<<"\n";
    }
}

int main(){
    Books* b1;
    int n;
    cout<<"Enter number of books\t";
    cin>>n;
    cin.ignore();
    b1 = new Books[n];

    setInfo(b1,n);
    displayInfo(b1,n);

    delete[] b1;
}