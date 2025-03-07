#include<iostream>
using namespace std;

class Account{
  public:
  int accountNumber;
  float balance;

  Account(int accountNumber, float balance) : accountNumber(accountNumber), balance(balance) {}

  void displayDetails(){
    cout<<"Account Number: "<<accountNumber<<endl;
    cout<<"Balance: "<<balance<<endl;
  }
};

class SavingsAccount : protected Account{
    public:
    float interestRate;

    SavingsAccount(int accountNumber, float balance, float interestRate) : Account(accountNumber,balance), interestRate(interestRate) {}

    
  void displayDetails(){
    cout<<"Saving Account: "<<endl;
    Account:: displayDetails();
    cout<<"interest rate: "<<interestRate<<endl;
  }
};

class CheckingAccount : protected Account{
 public:
 float overDraftLimit;

 CheckingAccount(int accountNumber, float balance,float overDraftLimit) : Account(accountNumber,balance), overDraftLimit(overDraftLimit) {}

 void displayDetails(){
    cout<<"Checking Account: "<<endl;
    Account:: displayDetails();
    cout<<"Over Draft Limit: "<<overDraftLimit<<endl;
  }
};

int main(){
    SavingsAccount S1(343,23000,0.4);
    CheckingAccount  C1(333,10000,3.3);

    S1.displayDetails();
    cout<<"\n";
    C1.displayDetails();
}