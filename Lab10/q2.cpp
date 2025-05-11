#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main() {
    ifstream read("vehicle.txt");
    if (!read.is_open()) {
        cerr << "File failed to open" << endl;
        exit(1);
    }

    string line;
    while (getline(read, line)) {
        istringstream iss(line);
        string type, id, name, year, extra, cert;

       
        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, year, ',');
        getline(iss, extra, ',');
        getline(iss, cert, ',');

        cout << "TYPE: " << type
             << ", ID: " << id
             << ", NAME: " << name
             << ", YEAR: " << year
             << ", EXTRA: " << extra
             << ", CERT: " << cert << endl;
    }

    read.close();
    return 0;
}
