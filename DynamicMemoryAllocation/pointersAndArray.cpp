#include<iostream>
using namespace std;

int* memoryAllocate(int n){
    int* ptr;
    ptr = new int[n];
        return ptr;
}
void inputArray(int* ptr , int n){
    for(int i = 0; i < n; i++){
       cin>>ptr[i];
    }
}
void displayArray(int* ptr , int n){
    for(int i = 0; i < n; i++){
        cout<<ptr[i]<<" ";
    }
}
int sumOfArray(int* ptr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
       sum+=ptr[i];
    }
    return sum;
}

void freePTR(int* ptr){
    delete[] ptr;
}

int main() {
   int n;
   cout<<"enter number of elements\n";
   cin>>n;
   int* ptr = memoryAllocate(n);
    cout<<"enter array elements:\n";
   inputArray(ptr,n);
   cout<<"\n";
   displayArray(ptr,n);
   cout<<"\n";
   cout<<"sum of array is "<<sumOfArray(ptr,n);
   freePTR(ptr);
}