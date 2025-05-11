#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

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
        }else if (type == "HybridTruck") {
    
    size_t sepPos = extra.find('|');
    if (sepPos != string::npos) {
        string cargoPart = extra.substr(0, sepPos);
        string batteryPart = extra.substr(sepPos + 1);

 
        size_t cargoPos = cargoPart.find(':');
        size_t batteryPos = batteryPart.find(':');

        if (cargoPos != string::npos && batteryPos != string::npos) {
            try {
                int cargoCapacity = stoi(cargoPart.substr(cargoPos + 1));
                int batteryCapacity = stoi(batteryPart.substr(batteryPos + 1));

                cout << "VEHICLE ID: " << id
                     << " CARGO CAPACITY: " << cargoCapacity
                     << " BATTERY CAPACITY: " << batteryCapacity << endl;
            } catch (invalid_argument& e) {
                cerr << "Invalid number in HybridTruck line: " << line << endl;
            } catch (out_of_range& e) {
                cerr << "Number out of range in HybridTruck line: " << line << endl;
            }
        } else {
            cerr << "Missing ':' in extra field: " << extra << endl;
        }
    } else {
        cerr << "Missing '|' in extra field: " << extra << endl;
    }
}

        }

    }


