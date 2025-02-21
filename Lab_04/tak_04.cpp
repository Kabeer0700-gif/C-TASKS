#include<iostream>
using namespace std;

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
      
     void applayDiscount(int days){
        if(!*status){
            if(days > 5 ){
                if(days > 10){
                    *price = *price - *price*0.10;
                    cout<<"--> 10percent discount applied successfully."<<endl;
                    cout<<"Price per day: "<<*price<<endl;
                    
                } 
                else{
                    *price = *price - *price*0.05;
                    cout<<"--> 5percent discount applied successfully."<<endl;

                    cout<<"Price per day: "<<*price<<endl;
                }
            }
            else{
                cout<<"--> First rent a car for more than 5 or 10 days"<<endl;
                
            }
           
        }else{
            cout<<"--> car is not available for rent"<<endl;
        }
    }

    void totalRevenue(int days){
        if(!*status){
           *price = *price * days;
           cout<<"total revenue generated is: "<<*price<<endl;
        }else{
          cout<<"\nFirst rent a car"<<endl;
        }
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
    Car c1("Toyota","Corolla",4500,true);
    c1.rentalRequest();
    c1.applayDiscount(6);
    c1.totalRevenue(6);
    
}

















