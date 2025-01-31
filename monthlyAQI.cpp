#include<iostream>
#include"climits"
using namespace std;

// QUESTION 3:

int main(){
    int AQI[4][28];
     cout<<"ENTER DATA OF CITIES:"<<endl;
    for(int i=0;i<4;i++){
        cout<<"CITY: "<<i+1<<endl;
        for(int j=0;j<28;j++){
               cout<<"DAY "<<j+1<<":";
               cin>>AQI[i][j];
        }
    }

    float sum[4]={0};
    for(int i=0;i<4;i++){
        for(int j=0;j<28;j++){
            sum[i]=sum[i]+AQI[i][j];
        }
        sum[i]=sum[i]/28.0;
    }
    
     cout<<"\nAVEREGIES OF CITIES ARE AS FOLLOWS:"<<endl;
    for(int i=0;i<4;i++){
        cout<<"CITY "<<i+1<<":) "<<sum[i]<<endl;
    }

    float sum1=0;
    float avg[4][4]={0};
     cout<<"\n";
    for(int i=0;i<4;i++){
        sum1=0;
        int k=0;
        for(int j=0;j<28;j++){
            sum1=sum1+AQI[i][j];
            if(j==6 || j==13 || j==20 || j==27){
                avg[i][k]=sum1/7;
                sum1=0;
                k++;
            }
        }
    }
     

        int bestcity=1;
        float maxImprovement=avg[0][0]-avg[0][3];
        for(int i=1;i<4;i++){
         float improvement=avg[i][0]-avg[i][3];
         if(improvement > maxImprovement){
            maxImprovement = improvement;
            bestcity=i+1;
         }     
        }
       
       cout<<"City with most improved air quality is "<<bestcity<<":"<<endl;
       cout<<"\n";
       cout<<"====================MONTHLY REPORT====================\n\n";
       cout<<"CITIES WEEKLY AVERAGES: "<<endl;
       for(int i=0;i<4;i++){
        cout<<"CITY "<<i+1<<":"<<endl;
        for(int j=0;j<4;j++){
           cout<<"WEEK "<<j+1<<": "<<avg[i][j]<<endl;
        }
        cout<<"\n";
    }
    cout<<"CRITICAL POLLUTION DAYS: "<<endl;
       for(int i=0;i<4;i++){
        cout<<"CITY "<<i+1<<":"<<endl;
        cout<<"| ";
        for(int j=0;j<28;j++){
          if(AQI[i][j]>150){
            cout<<"DAY -> "<<j+1<<" |";
          }
        }
        cout<<endl;
    }    
    cout<<"\n"; 
    cout<<"HIGHEST AND LOWEST AQI VALUES RECORDED CITY WISE\n";
        cout<<"----------------------------------------------\n";
    for(int i=0;i<4;i++){
        int min = INT_MAX; 
        int max = INT_MIN;
        for(int j=0;j<28;j++){
               if(min > AQI[i][j]){
                min=AQI[i][j];
               }
               if(max<AQI[i][j]){
                max=AQI[i][j];
               }
        }
        cout<<"| CITY ==> "<<i+1<<":) "<<"HIGHEST--> "<<max<<" "<<"LOWEST--> "<<min<<" |"<<endl;
    }
        cout<<"--------------------------------------------";
}