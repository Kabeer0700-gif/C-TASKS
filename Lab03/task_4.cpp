#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Car{
    public:
    string brand;
    int model;
    float fuelCapacity;
    float currentFuelLevel;

    Car(string brand, int model, float fuelCapacity){
        this->brand = brand;
        this->model = model;
        this->fuelCapacity = fuelCapacity;
        currentFuelLevel = 0;
    }

    void refuelTank(float fuel){
        if(fuel > 0 && fuel < fuelCapacity){
            currentFuelLevel = fuel;

    } 
      else if(fuel == fuelCapacity){
        cout<<"Tank is full (ameer party)"<<endl;
      }
    else{
        cout<<"Invalid quantity"<<endl;
        return;
    }

    }

    void checkFuel(){
        cout<<"Your current fuel is: "<<currentFuelLevel<<" Lit"<<endl;
        
    }

    void reducingFuelLevel(float reduce){
        if(reduce > 0 && reduce < fuelCapacity)
        {
            currentFuelLevel-=reduce;
        }

        cout<< reduce << " litre fuel has been reduced from "<<currentFuelLevel<<endl;
        checkFuel();

    }

    void displayDetails(){
        cout<<"\n==============Car Details=============\n";
        cout<<"Car Model: "<<model<<endl;
        cout<<"Car Brand: "<<brand<<endl;
        cout<<"Car Fuel Capacity: "<<fuelCapacity<<endl;
        cout<<"Car Current Fuel Capacity: "<<currentFuelLevel<<endl;
    }
};

int main(){
    Car toyota("Corolla",2022,40.5);
    toyota.refuelTank(20.5);
    toyota.checkFuel();
    toyota.reducingFuelLevel(5.8);
    toyota.displayDetails();
}