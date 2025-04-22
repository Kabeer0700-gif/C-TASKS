#include <iostream>
using namespace std;

class MenuItem {
    protected:
        string dishName;
        double price;
    public:
        MenuItem(string dn, double p) : dishName(dn), price(p) {}
        virtual void showDetails() = 0;
        virtual void prepare() = 0;
    };
    
    class Appetizer : public MenuItem {
    public:
        Appetizer(string dn, double p) : MenuItem(dn, p) {}
        void showDetails() override {
            cout << "Appetizer: " << dishName << ", Price: " << price << endl;
        }
        void prepare() override {
            cout << "Preparing Appetizer: " << dishName << endl;
        }
    };
    
    class MainCourse : public MenuItem {
    public:
        MainCourse(string dn, double p) : MenuItem(dn, p) {}
        void showDetails() override {
            cout << "Main Course: " << dishName << ", Price: " << price << endl;
        }
        void prepare() override {
            cout << "Preparing Main Course: " << dishName << endl;
        }
    };
 int main(){
    MenuItem* m1 = new Appetizer("Spring Rolls", 4.5);
    MenuItem* m2 = new MainCourse("Grilled Chicken", 12.0);

    m1->showDetails();
    m1->prepare();

    m2->showDetails();
    m2->prepare();

    delete m1,m2;

 }