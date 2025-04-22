#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual double readData() = 0;
    virtual void displayReport() = 0;
};

class Thermometer : public WeatherSensor {
public:
    double readData() override {
        return 22.5;
    }
    void displayReport() override {
        cout << "Thermometer Reading: " << readData() << " °C" << endl;
    }
};

class Barometer : public WeatherSensor {
public:
    double readData() override {
        return 1012.8;
    }
    void displayReport() override {
        cout << "Barometer Reading: " << readData() << " hPa" << endl;
    }
};

int main() {
   

    WeatherSensor* s1 = new Thermometer();
    WeatherSensor* s2 = new Barometer();

    s1->displayReport();
    s2->displayReport();

    
    delete s1;
    delete s2;

    return 0;
}
