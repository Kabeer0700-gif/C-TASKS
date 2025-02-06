#include<iostream>
using namespace std;

int** memoryAllocation(int r, int c){
    int** ptr;
    ptr = new int*[r];
    for(int i=0;i<r;i++){
        ptr[i] = new int[c];
    }
        return ptr;
}

void freeMemory(int** p,int n){
    for(int i=0;i<n;i++){
        delete[] p[i];
    }
    delete[] p;
    cout<<"memory free successfully::";
}
void inputMatrix(int** p, int r, int c){
    for(int i=0;i<r;i++){
        cout<<"Row "<<i+1<<endl;
        for(int j=0;j<c;j++){
            cout<<"column "<<j+1<<endl;
            cin>>*(*(p + i) + j);
        }
    }
}

void multiplyMatrices(int** p, int** b, int n, int m, int r, int c){
       int res[n][c]={0};
    if(m==r){
        int cr = m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j] = 0;
                for(int k=0 ;k<cr; k++){
                    res[i][j]+=p[i][k]*b[k][j];
                }
            }
        }
    }
    else{
        cout<<"columns of 1st matrix do not matches with the row of second matrix..\nMultiplication failed!"<<endl;
        freeMemory(p,n);
        freeMemory(b,r);
        return ;
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < c; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
  int n,m,p,q;
  cout<<"enter number of rows for matrix 1\t";
  cin>>n;
  cout<<"enter number of columns for matrix 1\t";
  cin>>m;
  cout<<"enter number of rows for matrix 2\t";
  cin>>p;
  cout<<"enter number of columns for matrix 2\t";
  cin>>q;

  int** ptr = memoryAllocation(n , m);
  int** btr = memoryAllocation(p , q);

  cout<<"enter values for matrix 1\n";
  inputMatrix(ptr,n,m);
  cout<<"enter values for matrix 2\n";
  inputMatrix(btr,p,q);
  cout<<"\n";
  multiplyMatrices(ptr,btr,n,m,p,q);

  freeMemory(ptr,n);
  freeMemory(btr,p);
  
}