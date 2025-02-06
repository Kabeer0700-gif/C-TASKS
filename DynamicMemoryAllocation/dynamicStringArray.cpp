#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string* ptr;
    int n;
    cout<<"enter number of string\t";
    cin>>n;
    cin.ignore();
    ptr = new string[n];

    for(int i=0;i<n;i++){
        cout<<"Enter name "<<i+1<<endl;
        getline(cin, ptr[i]);
    }
    
     for(int i=0;i<n;i++){
        sort(ptr[i].begin(), ptr[i].end());
        
       }

       for(int i=0;i<n;i++){
        cout<<ptr[i]<<" ";
       }


}