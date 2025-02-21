#include<iostream>
#include<string>
using namespace std;

class Car{
    public:
    string *brand;
    string *model;
    double *price;
    bool *status;
    Car(){
       brand = new string;
       model = new string;
       price = new double;
       status = new bool;
    }
    Car(string b,string m,double p,bool s){
        brand = new string(b);
        model = new string(m);
        price = new double(p);
        status = new bool(s);
    }

     void rentalRequest(){
         if(*status){
            cout<<"\n";
            cout<<*brand <<" "<< *model<<" is available for rent and rented successfully"<<endl;
            *status = false;
         }
         else{
            cout<<"\nNot available"<<endl;
         }
     }

    
     void displayCar(int num){
        
        cout<<"----------------------"<<endl;
        cout<<"Car: "<<num<<" Details"<<endl;
        cout<<"Name: "<<*brand<<endl;
        cout<<"Model: "<<*model<<endl;
        cout<<"Rental Price: "<<*price<<endl;
        cout<<"Status: "<<*status<<endl;
     }

     Car(Car &c){
        brand = new string(*c.brand);
        model = new string(*c.model);
        price = new double(*c.price);
        status = new bool(*c.status);
     }

     ~Car(){
        delete brand;
        delete model;
        delete price;
        delete status;
        cout<<"\n";
        cout<<"--> Object deleted successfully <--"<<endl;
     }
};

int main(){
    Car c1("Toyota","Corolla",12000,true);
    Car c2(c1);
    c1.displayCar(1);
    c2.displayCar(2);
    cout<<"\n";
    *c1.model = "VITZ";
    *c1.price = 10000;
    c1.displayCar(1);
    c2.displayCar(2);
}