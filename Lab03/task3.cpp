#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Library{
    public:
      string bookList[100];
      string borrowedBooks[100];
      string availableBooks[100];
      int List;
      int Borrowed;
      int available;
      Library(){
        List = 0;
        Borrowed = 0;
        available = 0;
      }

    void addBooks(string Book){
         
        bookList[List++] = Book;
        availableBooks[available++] = Book;
       
        
    }

    void lendBooks(string borrow){
        int index = -1;
        int length;
        for(int i=0;i<available;i++){
            if(availableBooks[i] == borrow){
              index = i;
            }

        }
        if(index != -1){
          length = availableBooks[index].length();
          availableBooks[index].erase(0,length);
}           
        else{
          cout<<"Book Not Found"<<endl;
        }
        }

       void returnBook(string Return){
              availableBooks[available++] = Return;
              cout<<endl;
              cout<<Return <<" has been returned successfully"<<endl;
              cout<<endl;
       }

       void displayBook(){
        cout<<"=================Book List================"<<endl;
        for(int j=0;j<List;j++){
            cout<<j+1<<") "<<bookList[j]<<endl;
        }   
        cout<<"\n";
          cout<<"==============Available Books==========="<<endl;
         for(int j=0;j<available;j++){
          if(availableBooks[j]==""){
            availableBooks[j] = "Unavailable";
          }
          cout<<j+1<<") "<<availableBooks[j]<<endl;
}
       }

      
};

int main(){
  Library lib;
  lib.addBooks("THINK AND GROW RICH");
  lib.addBooks("RICH DAD POOR DAD");
  lib.addBooks("C++");
  lib.lendBooks("THINK AND GROW RICH");
  lib.displayBook();
  lib.returnBook("THINK AND GROW RICH");
  lib.displayBook();
}