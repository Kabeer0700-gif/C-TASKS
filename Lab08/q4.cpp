#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    double price;

public:
    Car(string m, double p) {
        model = m;
        price = p;
    }

    void displayDetails() {
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
    }

    friend class InventoryManager;
    friend void comparePrice(Car c1, Car c2);
};

class InventoryManager {
public:
    void updatePrice(Car &c, double newPrice) {
        c.price = newPrice;
    }

    void displayCarDetails(Car c) {
        c.displayDetails();
    }
};

void comparePrice(Car c1, Car c2) {
    if (c1.price > c2.price)
        cout << c1.model << " is more expensive." << endl;
    else if (c2.price > c1.price)
        cout << c2.model << " is more expensive." << endl;
    else
        cout << "Both cars have the same price." << endl;
}

int main() {
    Car c1("Toyota", 30000);
    Car c2("Honda", 28000);

    InventoryManager manager;
    manager.displayCarDetails(c1);
    manager.displayCarDetails(c2);

    comparePrice(c1, c2);

    cout << "\nUpdating Honda price...\n";
    manager.updatePrice(c2, 32000);
    manager.displayCarDetails(c2);

    comparePrice(c1, c2);

    return 0;
}
