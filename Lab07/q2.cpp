#include"iostream"
using namespace std;

class Product{
 public:
 int productID;
 string productName;
 float price;
 int stockQuantity;

 Product(){
    productID = 0;
    productName = " ";
    price = 0.0;
    stockQuantity = 0;
 }
 Product(int id, string name, float p, int q) : productID(id), productName(name), price(p), stockQuantity(q){}
 void applyDiscout(){
    price = price - price*0.10;
    cout<<"Discout has been applied"<<endl;
 }

 void virtual calculateTotalPrice(int q){
    if(q >= 1){
        float total = price * q;
        cout<<"Total Price: "<<total<<endl;
    }else{
        cout<<"Invalid quantity"<<endl;
    }
}

 void virtual displayProduct()
 {
    cout<<"Product Name: "<<productName<<endl;
    cout<<"Product ID: "<<productID<<endl;
    cout<<"Product Pice: "<<price<<endl;
    cout<<"Product Quantiy: "<<stockQuantity<<endl;

 }
};

class Electronics : protected Product{
 public:
 float warrantyPeriod;
 string brand;

 Electronics(int id, string name, float p, int q,float w,string b) : Product(id,name,p,q), warrantyPeriod(w),brand(b){}

 void displayProduct(){
    Product::displayProduct();
    cout<<"Warranty period: "<<warrantyPeriod<<endl;
    cout<<"Brand: "<<brand<<endl;
 }
};

class Clothing : protected Product{
 public:
 int size;
 string color;
 string material;

 Clothing(int id, string name, float p, int q, int s, string c, string m) : Product(id,name,p,q), size(s), color(c), material(m){}

 void applyDiscount(){
    cout<<"Seasional discount has been applied";
    float total = price - price*0.20;
    
            cout<<"Total Price: "<<total<<endl;
        
    }
 
};

class FoodItem : protected Product{
 public:
 string expirationDate;
 double calories;

 void calculateTotalPrice(int q){
    if(q >= 1 && q<5){
        price = price*q;
    }else if(q>=5){
        price = price* q;
        price = price - price*(0.25);
    }
    else{
        cout<<"invalid quantity"<<endl;
    }
 }
};

class Book : public Product{
 public:
  string author;
  string genre;

  Book(){}
   Book (int id, string name, float p, int q,string a, string g) :  Product(id,name,p,q), author(a), genre(g) {}
  void displayProduct(){
    Product:: displayProduct();
    cout<<"Author: "<<author<<endl;
    cout<<"Genre "<<genre<<endl;
  }

  Book operator+(Book &b){
    Book temp;
    temp.price = price + b.price;

    return temp;
  }

  friend ostream& operator<<(ostream &out, Book &b){
    out<<"Product Name: "<<b.productName<<endl;
    out<<"Author: "<<b.author<<endl;
    out<<"Genre: "<<b.genre<<endl;
    out<<"Price: "<<b.price<<endl;
    return out;
}
};

int main(){
    Book b1(21,"BOOK 1",250.0,4,"Kabeer","Code 1");
    Book b2(22,"BOOK 2",350.0,4,"Shamveel","Code 2");

    b1.applyDiscout();
    b2.applyDiscout();

    Book b3 = b1+b2;
    cout<<b3;

}