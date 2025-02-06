#include<iostream>
#include<string>

using namespace std;

struct productInventory
{
    int productId;
    string name;
    int quantity;
    float price;
};

void setInfo(productInventory* p,int n){
    for(int i=0;i<n;i++){
        cout<<"Product "<<i+1<<endl;
        cout<<"Enter Product Name\t";
        getline(cin, p[i].name);
        cout<<"Enter product Id\t";
        cin>>p[i].productId;
        cin.ignore();
        cout<<"Enter quantity\t";
        cin>>p[i].quantity;
        cin.ignore();
        cout<<"Enter price\t";
        cin>>p[i].price;
        cin.ignore();
    }

}

void calculateInventory(productInventory* p,int n){
    float price[n]={0};
    for(int i=0;i<n;i++){
       price[i]=(p[i].quantity)*(p[i].price);
    }
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=price[i];
    }
    cout<<"TOTAL PRICE IS: "<<sum<<endl;
    for(int i=0;i<n;i++){
        cout<<"Product: "<<i+1<<endl;
        cout<<price[i]<<endl;
    }

}

int main(){
    int n;
    cout<<"Enter Number of Products\t";
    cin>>n;
    cin.ignore();
    productInventory *p = new productInventory[n];

    setInfo(p,n);
    cout<<"\n";
    calculateInventory(p,n);
}