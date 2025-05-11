#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream read("vehicle.txt");
    if(!read.is_open()){
        cerr<<"File failed to open"<<endl;
        exit(1);
    }

    string line;

    while(getline(read,line)){
        cout<<line<<endl;
    }

    read.close();

}
