#include<iostream>

// QUESTION 2:
using namespace std;

int main(){
    int AQI[4][7];
    for(int i=0;i<4;i++){
        cout<<"Enter Air Quality of week for City "<<i+1<<":"<<endl;
        for(int j=0;j<7;j++){
            cout<<"Day "<<j+1<<":"<<endl;
            cin>>AQI[i][j];
        }
    }
    float avg[7]={0},sum[7]={0};
    for(int i=0;i<4;i++){
        for(int j=0;j<7;j++){
            sum[i]+=AQI[i][j];
        }
    }
        
    
        cout<<"\n\n";
        for(int j=0;j<4;j++){
            avg[j]=sum[j]/7.0;
        }
        cout<<"=========Average of cities=========\n\n";
        
        for(int j=0;j<4;j++){
                cout<<"CITY --> "<<j+1<<") "<<avg[j]<<"  ";
        }
        int mx=-1;
        int city=0;
      for(int i=0;i<4;i++){
          if(mx<avg[i]){
            mx=avg[i];
            city=i;
          }
      }
    cout<<"\n\n";
    cout<<"The worst air quality is in city:"<<city+1<<endl;
    cout<<"\nDAYS WHERE LIMIT EXCEED 150"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<7;j++){
            if(AQI[i][j]>150){
             cout<<"CITY => "<<i+1<<") "<<"DAY -> "<<j+1<<endl;

            }
           
        }
        cout<<"\n";
    }
     int n;
     cout<<"\nGRAPH REPRESENTATION FOR INCREMENT OF 50"<<endl;
     cout<<"\n";
     for(int i=0;i<4;i++){
        cout<<"CITY "<<i+1<<":-";
        for(int j=0;j<7;j++){
            n=AQI[i][j]/50;
            if(n>0){
               cout<<"\nDAY "<<j+1<<": ";
               for(int k=1;k<=n;k++){
                cout<<"* ";
               }
               
            }
        }
            cout<<"\n\n";
     }
    
}