#include<iostream>
#include<algorithm>
using namespace std;

class Product{
  public:
  int id;
  string name;
  int quantity;

  Product(int id,string name,int quantity) : id(id), name(name), quantity(quantity) {}

  void showProduct(){
    cout<<"Product Id: "<<id<<endl;
    cout<<"Product name: "<<name<<endl;
    cout<<"Product qantity: "<<quantity<<endl;
  }
};

class Inventory{
 public:
 Product* product[10];
 int count;
 
 Inventory() { count = 0; }
 void addProduct(Product* p){
   if(count < 10 ){
    product[count++] = p;
    cout<<p->name<< " Added successfully"<<endl;
   }else{
    cout<<"Inventory is full"<<endl;
   }
 }

 void searchProduct(){
    int pId;
    cout<<"Enter Product Id"<<endl;
    cin>>pId;
    bool found = false;
    for(int i=0 ; i<count; i++){
        if(product[i]->id == pId){
            cout<<"Product Found Successfully"<<endl;
            product[i]->showProduct();
            found = true;
            break;
        }
    }
    if(found == false){
        cout<<"Product Not Found"<<endl;
    }
 }

 void sortProduct(){
    sort(product, product + count, [](Product* a, Product* b) {
        return a->name < b->name;
    });

    cout<<"Sorted Product"<<endl;
    cout<<"\n";
    for(int i=0;i<count; i++){
        product[i]->showProduct();
    }
    cout<<endl;
 }
};

int main(){
    Product tv(232,"TV",40);
    Product AC(234,"AC",25);
    Product washingMachine(235,"Washing Machine",15);

    Inventory GadaElectronics;
    GadaElectronics.addProduct(&tv);
    GadaElectronics.addProduct(&AC);
    GadaElectronics.addProduct(&washingMachine);

    GadaElectronics.searchProduct();
    cout<<"\n";
    GadaElectronics.sortProduct();
}