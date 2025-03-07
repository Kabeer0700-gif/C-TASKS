#include<iostream>
using namespace std;

class Vehicle{
 public:
 string brand;
 int speed;

 Vehicle(string brand, int speed) : brand(brand), speed(speed) {}
  
 void displayDetails(){
    cout<<"Brand: "<<brand<<endl;
    cout<<"Speed: "<<speed<<endl;
 }

};

class Car : protected Vehicle{
 public:
 int seats;

 Car(string brand, int speed, int seats) : Vehicle(brand,speed), seats(seats) {}

 void displayDetails(){
    Vehicle ::displayDetails(); 
    cout<<"Seats capacity: "<<seats<<endl;
 }
};

class ElectricCar : protected Car{
 public:
 int batteryLife;

 ElectricCar(string brand, int speed, int seats, int batteryLife) : Car(brand,speed,seats), batteryLife(batteryLife) {}
 void displayDetails(){
    Car ::displayDetails(); 
    cout<<"battery Life: "<<batteryLife<<endl;
 }

};


int main(){
    ElectricCar Audi("Audi",300,5,88);
    Audi.displayDetails();
}