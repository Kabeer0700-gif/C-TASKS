#include<iostream>
#include<sstream>
#include<fstream>
#include<stdexcept>

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
try {
    int YEAR = stoi(year);
    cout << "YEAR: " << YEAR << endl;
} catch (invalid_argument& e) {
    cerr << "Invalid year format in line: " << line << endl;
} catch (out_of_range& e) {
    cerr << "Year out of range in line: " << line << endl;
}

    }
}