#include<iostream>
#include<sstream>
#include<fstream>
#include<stdexcept>
#include<string>

using namespace std;

int main(){
    ifstream file("vehicle.txt");
    if(!file.is_open()){
        cerr<<"Failed to open"<<endl;
        exit(1);
    }

    string line;

    while(getline(file,line)){
        istringstream iss(line);
        string type,id,name,year,extra,cert;

        getline(iss,type,',');
        getline(iss,id,',');
        getline(iss,name,',');
        getline(iss,year,',');
        getline(iss,extra,',');
        getline(iss,cert,',');

        if(type == "AutonomusCar"){
            size_t pos = extra.find(":");
            if(pos != string :: npos){
                float SV;
                string sv = extra.substr(pos + 1);
                SV = stof(sv);
                cout<<"VEHICLE ID: "<<id<<" SOFTWARE VERSION: "<<SV<<endl;  
            }else{
                cout<<"Data not found"<<endl;
            }
        }else if (type == "ElectricVehicle"){
            size_t pos = extra.find(":");
            if(pos != string :: npos){
                int bc;
                string BC = extra.substr(pos + 1);
                
                bc = stoi(BC);
                cout<<"VEHICLE ID: "<<id<<" BATTERY CATACITY: "<<bc<<endl;
            }
        }

    }
}