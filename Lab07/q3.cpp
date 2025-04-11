#include"iostream"

using namespace std;

class Ticket{
    public:
    int ticketId;
    string passangerName;
    float price;
    string date;
    string destination;

     Ticket(int id,string name, float p, string d, string des) : ticketId(id), passangerName(name), date(d), destination(des) {}
    
     void reserve(){
        cout<<"Ticket hAS BEEN reserved "<<endl;
     }

     void cancel(){
        cout<<"Ticket has been cancelled "<<endl;
        ticketId = 0;
        passangerName = "";
     }

     void displayInfo(){
        cout<<"Ticket Id: "<<ticketId<<endl;
        cout<<"Name "<<passangerName<<endl;
        cout<<"Ticket date: "<<date<<endl;
        cout<<"Ticket price: "<<price<<endl;
        cout<<"destination: "<<destination<<endl;

     }

};

class FlightTicket : public Ticket{
 public:
 string airlineName;
 int number;
 string seatClass;
 
 void displayInfo(){
    Ticket:: displayInfo();
    cout<<"Airline Name "<<airlineName<<endl;
    cout<<"Airline Number "<<number<<endl;
 }

 FlightTicket(int id,string name, float p, string d, string des, string airName,int n,string C) : Ticket(id,name,p,d,des),airlineName(airName), number(n), seatClass(C){}


};

class TrainTicket : public Ticket{
    public:
    int trainNumber;
    string coachType;
    string departureTime;
    int count = 0;
    void reserve(){
         
        count++;
        trainNumber = count;
        coachType = "Gareebo Wali";
        departureTime = "9:30 pm";
    }
   
    TrainTicket(int id,string name, float p, string d, string des,int num, string t, string dep) : Ticket(id,name,p,d,des), trainNumber(num), coachType(t), departureTime(dep){}

}; 

 class BusTicket : public Ticket{
  public:
   string company;
   int seatNumber;

   BusTicket(int id,string name, float p, string d, string des, string c, int s) : Ticket(id,name,p,d,des), company(c), seatNumber(s){}

   void cancel()  {
    cout << "Bus Ticket Cancelled with Last-Minute Refund Allowed!" << endl;
}

void displayTicketInfo()  {
    Ticket::displayInfo();
    cout << "Bus Company: " << company << endl;
    cout << "Seat Number: " << seatNumber << endl;
}
};


class ConcertTicket : public Ticket {
string artistName;
string venue;
string seatType;

public:
ConcertTicket(int id, string name, float price, string date, string destination,
              string artist, string venue, string seat)
    : Ticket(id, name, price, date, destination) {
    this->artistName = artist;
    this->venue = venue;
    this->seatType = seat;
}

void displayTicketInfo() {
    Ticket::displayInfo();
    cout << "Artist Name: " << artistName << endl;
    cout << "Venue: " << venue << endl;
    cout << "Seat Type: " << seatType << endl;
}
};


int main() {

BusTicket bt(103, "Ahmed", 800, "12-04-2025", "Islamabad", "Daewoo", 12);
bt.reserve();
bt.cancel();
bt.displayTicketInfo();
cout << "-----------------------------------" << endl;


ConcertTicket ct(104, "Hina", 2500, "20-04-2025", "Lahore", "Atif Aslam", "Expo Center", "VIP");
ct.reserve();
ct.displayTicketInfo();

return 0;
}