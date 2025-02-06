#include"iostream"
using namespace std;

int*** allocateMemory(int x,int y,int z){
       int*** ptr = new int**[x];

       for(int i=0;i<x;i++){
        ptr[i] = new int*[y];
        for(int j=0;j<y;j++){
            ptr[i][j] = new int[y];
        }
       }

       return ptr;
}

void inputArr(int*** ptr, int x, int y, int z){
    for(int i=0;i<x;i++){
        cout<<"layer "<<i+1<<endl;
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                cin>>ptr[i][j][k];
            }
        }
    }
}

void displayArr(int*** ptr, int x, int y, int z){
    for(int i=0;i<x;i++){
        cout<<"layer "<<i+1<<endl;
        for(int j=0;j<y;j++){
            cout<<"[ ";
            for(int k=0;k<z;k++){
                cout<<ptr[i][j][k]<<" ";
            }
            cout<<"]\n";
        }
        cout<<"\n";
    }
}

void deleteMemory(int*** ptr,int x,int y){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            delete[] ptr[i][j];
        }
        delete[] ptr[i];
    }
     delete[] ptr;
}

int main(){
    int x,y,z;
    cout<<"Enter dimension of 3d matrix\n";
    cin>>x;
    cin>>y;
    cin>>z;

    int*** ptr = allocateMemory(x,y,z);
    inputArr(ptr,x,y,z);
    cout<<"\n";
    displayArr(ptr,x,y,z);
    deleteMemory(ptr,x,y);
}