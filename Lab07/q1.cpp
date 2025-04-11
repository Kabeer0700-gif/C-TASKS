#include<iostream>
using namespace std;

class Device{
 public:
 int deviceID;
 string deviceName;
 bool status;
 string location;

 Device(int id, string name, bool s, string l) : deviceID(id),deviceName(name),status(s),location(l){}

 virtual void turnOn(){
    if(status){
        cout<<"Device is  turned On"<<endl;
    }else{
        status = true;
        cout<<"Device is  turned On"<<endl;
    }
 }

 void virtual turnOff(){
    if(!status){
        cout<<"Device is  turned Off"<<endl;
    }else{
        status = false;
        cout<<"Device is  turned Off"<<endl;
    }
 }

 void virtual getStatus(){
    cout<< "Device is " << (status ? "ON" : "OFF") <<endl;
 }

 void virtual displayInfo(){
     cout<<"Device Name: "<<deviceName<<endl;
     cout<<"Device Id: "<<deviceID<<endl;
     cout<<"Device Status: "<< (status ? "ON" : "OFF")<<endl;
     cout<<"Device Location: "<<location<<endl;
}

};

class Light : protected Device{
    public:
    int brightnessLevel;
    string colorMode;

    Light(int id, string name, bool s, string l, int bl, string cm) : Device(id,name,s,l), brightnessLevel(bl), colorMode(cm){}

    void displayInfo(){
        Device:: displayInfo();
        cout<<"Brightness Level: "<<brightnessLevel<<endl;
        cout<<"Color Mode: "<<colorMode<<endl;
    }
};

class Thermostat : protected Device{
    public:
    float temperature;
    string mode;
    float targetTemperature;

    Thermostat(int id, string name, bool s, string l, float temp, string m, float tt) : Device(id,name,s,l), temperature(temp), mode(m), targetTemperature(tt) {}
    
    void getStatus(){
        Device::getStatus();
        cout<<"Current Temperature: "<<temperature<<endl;
    }
};

class SecurityCamera : protected Device{
    public:
    int resolution;
    bool recordingStatus;
    bool nightVision;

    SecurityCamera(int id, string name, bool s, string l,int res, bool rs, bool nv) : Device(id,name,s,l), resolution(res), recordingStatus(rs), nightVision(nv){}

    void turnOn(){
        Device::turnOn();
        recordingStatus = true;
        cout<<"Recording started"<<endl;
    }
   
};

class SmartPlug : protected Device{
    public:
    bool powerConsumption;
    float timerSetting;

    SmartPlug(int id, string name, bool s, string l,bool pc, float ts) : Device(id, name, s, l), powerConsumption(pc), timerSetting(ts) {}
    
    void turnOff(){
        Device:: turnOff();
        powerConsumption = false;
        cout<<"Power Consumption off: "<<endl;
    }

    void displayInfo(){
        Device:: displayInfo();
        cout<<"Power Consumption: "<<(powerConsumption?  "On" : "Off")<<endl;
        cout<<"Timer setting: "<<timerSetting<<"sec"<<endl;
    }
};

int main(){
    SmartPlug s1(12,"plug",true,"2m away",true,2.4);
    s1.displayInfo();

    s1.turnOff();

}
