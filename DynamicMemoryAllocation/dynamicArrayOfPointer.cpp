#include<iostream>
using namespace std;

int* allocateMemory(int r){
    int* ptr = new int[r];
    return ptr;
}

void inputArr(int* p , int r){
    for(int i=0;i<r;i++){
        cout<<"enter element: "<<i+1<<endl;
        cin>>p[i];
    }
}

void displayArr(int* p , int r){
    for(int i=0;i<r;i++){
        cout<<p[i]<<" ";
    }
}

void freeMemory(int* p){
    delete[] p;
}

int main(){
    int n;
    cout<<"enter number of elements\t";
    cin>>n;

    int* ptr = allocateMemory(n);
    inputArr(ptr,n);
    displayArr(ptr,n);
    freeMemory(ptr);
}