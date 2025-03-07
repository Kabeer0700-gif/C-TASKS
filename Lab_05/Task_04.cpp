#include<iostream>
using namespace std;

class AlarmSystem{
  private:
  string securityLevel;

  public:
  AlarmSystem(){}
  AlarmSystem(string securityLevel) : securityLevel(securityLevel) {}
  
  void viewAlarm(){
    cout<<"Alarm Security Level: "<<securityLevel<<endl;
  }

  string getSecurityLevel() { return securityLevel; }
  
  ~AlarmSystem(){
    cout<<"Alarm System Removed From Smart Home"<<endl;
  }
};

class SmartHome{
 private:
 AlarmSystem alarm;
 int numOfRooms;
 string location;
 public:
 SmartHome(int numOfRooms, string location, string security) : numOfRooms(numOfRooms), location(location), alarm(security) {}

 void SmartHomeDetails(){
    cout<<"Smart Home Details: "<<endl;
    cout<<"Number Of Rooms: "<<numOfRooms<<endl;
    cout<<"Location: "<<location<<endl;
    alarm.viewAlarm();
 }

 ~SmartHome(){
    cout<<"Smart Home Deleted Successfully"<<endl;
 }

};

int main(){
    SmartHome smrt(3,"Gulberg City","High");
    smrt.SmartHomeDetails();
}