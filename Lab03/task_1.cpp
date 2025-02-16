#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Wallet
{
private:
    double totalBalance;

public:
    string ownerName;
    vector<double> transactionHistory;
    Wallet(string ownerName)
    {
        this->ownerName = ownerName;
        this->totalBalance = 0;
    }

    void addMoney(double M)
    {
        if (M > 0)
        {
            totalBalance += M;
            cout << M << " rupees added to your wallet " << endl;
            cout<<"\n";
            transactionHistory.push_back(M);
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }

    void spendMoney(double M)
    {
        if ( M>0 && M <  totalBalance)
        {
            totalBalance -= M;
            cout << M << " ruppes spend successfull.Now your current balance is " << totalBalance << endl;
            cout<<"\n";
            transactionHistory.push_back(M);
        }
        else
        {
            cout << "invalid input or NOT sufficient Money" << endl;
        }
    }

    void displayTransaction()
    {
        cout << "\n"
             << ownerName << " Transaction history " << endl;
        for (double val : transactionHistory)
        {
            cout << val << endl;
        }
    }
};

int main()
{
    cout << "Enter your name:\t";
    string name;
    cin >> name;
    cout << "Welcome " << name << " your wallet has been created successfully" << endl;
    Wallet w(name);

    int flag = 1;
    int choice;
    while (flag)
    {    
        cout << " 1) ADD MONEY\n 2) SPEND MONEY\n 3)VIEW TRANSACTION HISTORY\n 4)EXIT PROGRAM\n Enter your choice(1-4)" << endl;
        cin>>choice;

        switch(choice){
            case 1:{
                double amount;
                cout<<"ENTER AMOUNT YOU WANT TO ADD\t";
                cin>>amount;
                w.addMoney(amount);
                break;
            }

            case 2:{
                double amount;
                cout<<"ENTER AMOUNT YOU WANT TO SPEND\t";
                cin>>amount;
                w.spendMoney(amount);
                break;
            }
            
            case 3:{
                w.displayTransaction();
                break;
            }

            case 4:{
                flag = 0;
                break;
            }
        }
    }
}