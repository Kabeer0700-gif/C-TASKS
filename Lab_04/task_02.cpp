

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
    Car(string b,string m,double p,bool s){
        brand = b;
        model = m;
        price = p;
        status = s;
    }

     void rentalRequest(){
         if(status){
            cout<<"\n";
            cout<<brand + model <<" is available for rent and rented successfully"<<endl;
            status = false;
         }
         else{
            cout<<"\nNot available"<<endl;
         }
     }

     void applayDiscount(int days){
        if(!status){
            if(days > 5 ){
                if(days > 10){
                    price = price - price*0.10;
                    cout<<"--> 10percent discount applied successfully.Now current price is: "<<price<<endl;
                    
                } 
                else{
                    price = price - price*0.05;
                    cout<<"--> 5percent discount applied successfully.Now current price is: "<<price<<endl;
                   
                }
            }
            else{
                cout<<"--> First rent a car for more than 5 or 10 days"<<endl;
                
            }
           
        }else{
            cout<<"--> car is not available for rent"<<endl;
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
    Car c1("Toyota","Corolla",12000,true);
    Car c2("Honda","Rebirth",16000,true);
    c1.displayCar();
    c2.displayCar();
    c1.rentalRequest();
    c1.applayDiscount(11);
    c1.rentalRequest();

}
