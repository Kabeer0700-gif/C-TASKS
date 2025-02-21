#include"iostream"
#include"string"
using namespace std;

class Car{
    public:
    string brand;
    string model;
    double price;
    bool status;

    Car(){
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        status = true;
    }

     void rentalRequest(){
         if(status){
            cout<<"\nCar is available for rent and rented successfully"<<endl;
            status = false;
         }
         else{
            cout<<"\nNot available"<<endl;
         }
     }
     void displayCar(){
        cout<<"\n----------------------"<<endl;
        cout<<"Name: "<<brand<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Rental Price: "<<price<<endl;
        cout<<"Status: "<<status<<endl;
     }
};

int main(){
    Car C1;
    cout<<"Car 1 details\n";
    C1.displayCar();
    Car c2;
    c2.brand="Toyota";
    c2.model="Corolla";
    c2.price=23000.0;
    c2.status = true;
    cout<<"Car 2 details\n";
    c2.displayCar();
    c2.rentalRequest();
    c2.displayCar();
}
