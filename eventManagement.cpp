#include<iostream>
#include<cstring>

// QUESTION 1:

using namespace std;
void reverseName(char naam[][30],int n){
     for(int i=0;i<n;i++){
        int len,j;
     
        len=strlen(naam[i]);
        for(int j=len-1;j>=0;j--){
            cout<<naam[i][j];
        }
        cout<<"\n";
     }
}

void barchart(char naam[][30],int n){
    for(int i=1;i<=n;i++){
        cout<<"* ";
    }
}
int main(){
char names1[5][30];
char names2[5][30];
int ch;

    int n1=0;
    int n2=0;

int flag=1;
while(flag){
    cout<<"\nEvent Management System"<<endl;
    cout<<"1) ENTER ENTRIES\n2)CHECKING ATTENDENCE\n3)CALCULATE TOTAL DONATION\n4)NAME IN REVERSE\n5)EVENT POPULARITY IN CHARt\n6)EXIT\n";
    cin>>ch;
    switch(ch){
    case 1:
    
        cout<<"enter the name of event(i.e, 1 or 2)"<<endl;
        int event;
        cin>>event;
        if(event==1){
            if(n1==0) {
                cout<<"enter number of entries (maximum:5)"<<endl;
                cin>>n1;
                cout<<"event # 1"<<endl;
                for (int i=0;i<n1;i++){
                    cin>>names1[i];
                }
                cout<<"data entered successfully"<<endl;
            }
            else {
                cout<<"entries for this event are already donee!!"<<endl;
            }
        
        }
        else{
         if(n2==0) {
            cout<<"enter number of entries (maximum:5)"<<endl;
            cin>>n2;
            cout<<"event # 2"<<endl;
            for (int i=0;i<n2;i++){
                cin>>names2[i];
            }
            cout<<"data entered successfully"<<endl;
            }
            else {
                cout<<"entries for this event are already done!!"<<endl;
            }
        }
    
    
    
 break;
case 2:{
    if(n1==0 && n2==0){
        cout<<"first enter entries in both events"<<endl;
        break;
    }
  char check[30];
  cout<<"enter name:"<<endl;
  cin>>check;
  int found=0;
    for(int i=0;i<n1;i++){
        if(strcmp(check,names1[i])==0){
            cout<<"person found in event 1\n";
            found=1;
        }
    }
    for(int i=0;i<n2;i++){
       if(strcmp(check,names2[i])==0){
            cout<<"person found in event 2\n";
            found=1;
        }
    }   
         if(!found){
            cout<<"person not found in any of the event\n";
         }
       
    break;
}

    case 3:{
    int event1[5],event2[5];
    int sum1,sum2,tsum;
    sum1=0,sum2=0;
     cout<<"enter amount of persons from event 1:\n";
    for(int i=0;i<n1;i++){
        cin>>event1[i];
    }
    cout<<"enter amount of persons from event 2: "<<endl;
     for(int j=0;j<n2;j++){
        cin>>event2[j];
    }
   
    for(int k=0;k<n1;k++){
        sum1=sum1+event1[k];
    }
    for(int l=0;l<n2;l++){
        sum2=sum2+event2[l];
    }
   
    tsum=sum1+sum2;
    cout<<"total donation is: "<<"$"<<tsum<<endl;
   
    break;
    }
    case 4:{
        cout<<"Reverse Names For Event# 1"<<endl;
        reverseName(names1,n1);
        cout<<"\n";
        cout<<"Reverse Names For Event# 2"<<endl;
        reverseName(names2,n2);
        cout<<"\n";
        break;
    }

    case 5:{
        cout<<"          1 2 3 4 5\n";
        cout<<"event# 1: ";
        barchart(names1,n1);
        cout<<"\n";
        cout<<"event# 2: ";
        barchart(names2,n2);
        cout<<"\n";
        break;
    }

    case 6:
     flag=0;
     break;

     default:
     cout<<"invalid input"<<endl;
     break;
}

}
}