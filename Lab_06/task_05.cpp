#include<iostream>
using namespace std;


class Device{
  public:
  int deviceID;
  bool status;
  Device() {}
  Device(int deviceID, bool status) : deviceID(deviceID), status(status) {}

  void displayDetails(){
    cout<<"Device Details:-"<<endl;
    cout<<"Device Id: "<<deviceID<<endl;
    cout<<"Available: ";
    cout << (status ? "Yes" : "No") << endl;

  }
};

class SmartPhone : protected Device{
 public:
 float screenSize;
 SmartPhone(){}
 SmartPhone(int deviceID, bool status, float screenSize) : Device(deviceID,status), screenSize(screenSize) {}
  
 void displayDetails(){
    Device:: displayDetails();
    cout<<"Screen Size: "<<screenSize<<endl;
}

};

class SmartWatch : protected SmartPhone{
    public:
    bool heartRateMonitor;

    SmartWatch(int deviceID, bool status, float screenSize, bool heartRateMonitor) : SmartPhone(deviceID,status,screenSize), heartRateMonitor(heartRateMonitor) {}
  
    void displayDetails(){
        SmartPhone:: displayDetails();
        cout<<"Heart Rate Monitor: ";
        cout << (heartRateMonitor ? "Yes" : "No") << endl;

    }
};

class SmartWearable : protected SmartWatch{
    public:
    int stepCounter;

    SmartWearable(int deviceID, bool status, float screenSize, bool heartRateMonitor, int stepCounter) : SmartWatch(deviceID,status,screenSize,heartRateMonitor), stepCounter(stepCounter) {}

    void displayDetails(){
        SmartWatch:: displayDetails();
        cout<<"Step Counter: "<<stepCounter<<endl;
    }
};

int main(){
    SmartWearable bracelet(700,true,2.5,true,200);
    bracelet.displayDetails();
}