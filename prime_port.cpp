#include<iostream>
#include<windows.h>
#include<conio.h>
#include<iterator>
#include<map>


using namespace std;


class Ships
{
    public:
    string name,country;
    float weight;
    int ship_no;
    Ships(string name,float weight,string country,int ship_no)
    {
        this->name=name;
        this->weight=weight;
        this->country=country;
        this->ship_no=ship_no;
    }
    virtual void display()
    {
        cout<<name<<"\t\t"<<country<<"\t\t"<<weight<<"\t\t"<<ship_no<<"\t\t"<<endl;
    }

};

class Cargo
{
    public:
     string name,type;
     float weight,length,breadth,height,price;
     int cargo_id;
     Cargo()
     {}
     Cargo(string name,string type,float weight,float length,float breadth,float height,float price,int cargo_id):
         name(name),type(type),weight(weight),length(length),breadth(breadth),height(height),price(price),cargo_id(cargo_id)
     {}
};


class Ports
{
    public:
    string name,location;
    int arrival_capacity,departure_capacity,*arrival_ship_list,port_id;
    float wind_speed;
    bool open,close;
    Ports(string name,int arrival_capacity,int departure_capacity,string location,float wind,bool open,bool close,int port_id)
    {
        this->name=name;
        this->location=location;
        this->arrival_capacity=arrival_capacity;
        this->departure_capacity=departure_capacity;
        this->wind_speed = wind;
        this->open = open;
        this->close = close;
        this->port_id = port_id;
    }

};


class Current_port_info
{
    public:
      float wind_speed;
      bool open;
      bool closed;
      int port_id;
      Current_port_info()
      {
         wind_speed = 0;
         open = -1;
         closed = -1;
         port_id = -1;
      }
      void display_port_info()
      {
          cout <<"wind speed : " << wind_speed;
          if(open)
           cout << "\t Opened";
          else
           cout << "\t Closed";
           cout << "\t Port Id : " << port_id << endl;
      }
      void get_port_info(Ports **P,int p)
      {
          port_id =  p;

        for(int i=0;i<10;i++)
        {
            if(P[i]->port_id==port_id)
            {
                wind_speed = P[i]->wind_speed;
                open = P[i]->open;
                closed = P[i]->close;


            }

        }

      }
};



class Arrival_departure_ships : public Ships
{
    public :
     int day,month ,year;
     bool departure,arrival;
     Cargo** items;
     int total_items;
     int port_id;
     Arrival_departure_ships(Ships** S,int day,int month,int year,bool arrival,bool departure,Cargo **it,int totalitems,int i,int port_id)
     : Ships(S[i]->name,S[i]->weight,S[i]->country,S[i]->ship_no)
     {
         this->day=day;
         this->month=month;
         this->year=year;
         this->arrival=arrival;
         this->departure = departure;
         this->total_items=totalitems;
         this->port_id = port_id;
         this->items = it;

     }
    void display()
    {
        cout<<day<<"\t\t"<<month<<"\t\t"<<year<<"\t\t"<<ship_no<<endl;
    }
    void get_current_port_info(Ports **P)
    {
        Current_port_info T;
        T.get_port_info(P,port_id);
        T.display_port_info();
    }
};

class Ground_transport
{
public:
bool overloaded;
int capacity;
Ground_transport()
{
    overloaded = false;
    capacity = 100;
}

int unload_Cargo(int n)
{
    if(n<=capacity)
    {
        cout<<"Unloaded the Cargo Successfully!"<<endl;

    }
    else
    {
            capacity_insufficient();
    }
    return !overloaded;
}
void capacity_insufficient()
{
    overloaded = true;
    cout<<"The Ground transport is overloaded"<<endl;
}

};


class Customs
{
public:
map<string, float> Customs_Chart;
bool success;

Customs()
{
  success = false;
}
int levy_customs(Cargo** cargo,int n)
{
    int i;
    map<string,float> ::iterator itr;
    for(i=0;i<n;i++)
    {
        for(itr=Customs_Chart.begin();itr!=Customs_Chart.end();itr++)
        {
            if(itr->first==cargo[i]->type)
                {
                    cargo[i]->price += itr->second;
                }
        }

    }

if(i==n)
    {
        success = true;
        cout<<"Customs added to the price of the cargo"<<endl;
    }

return success;
}
};



class Delivery
{
public:
bool delivery_status;

Customs customs;
void fill_customs_chart()
{
customs.Customs_Chart.insert(pair<string, float>("Food",1.5));
customs.Customs_Chart.insert(pair<string, float>("Apparels",10.5));
customs.Customs_Chart.insert(pair<string, float>("Metals",5.5));
customs.Customs_Chart.insert(pair<string, float>("Coal",20.5));
customs.Customs_Chart.insert(pair<string, float>("Fertilizer",3.5));
customs.Customs_Chart.insert(pair<string, float>("Computers",6.5));
customs.Customs_Chart.insert(pair<string, float>("Machinery",8.5));
customs.Customs_Chart.insert(pair<string, float>("Papers",0.5));
customs.Customs_Chart.insert(pair<string, float>("Bags",1.5));
customs.Customs_Chart.insert(pair<string, float>("Pens",0.5));
customs.Customs_Chart.insert(pair<string, float>("Tablets",2.5));

}

int deliver(Cargo **cargo, int n)
{
   bool temp;
   int i;
   temp = customs.levy_customs(cargo,n);
   if(temp==true)
        {
            cout<<"Name\t\tPrice\t\tType"<<endl;
            for(i=0;i<n;i++)
            {
                cout<<cargo[i]->name<<"\t\t"<<cargo[i]->price<<"\t\t"<<cargo[i]->type<<endl;
            }
            cout<<"All Cargo Delivered"<<endl;
            delivery_status = true;
        }
    else{
        delivery_status =  false;
    }

   return delivery_status;
}


};


class Prime_Port: public Ports
{
Ground_transport G;
Delivery D;
public:
Prime_Port(string name, int arrival_c, int departure_c, string location, float wind, bool o, bool c, int id)
: Ports(name, arrival_c, departure_c, location, wind,o,c,id)
{
D.fill_customs_chart();
}

void operate(Arrival_departure_ships **lists,int counter)
{
   int i;
   for(i=0;i<counter;i++)
   {
        if(lists[i]->arrival == true && lists[i]->departure == false)
        {
            call_ground_transport(lists[i]);
            call_delivery(lists[i]->items,lists[i]->total_items);
        }
        else if(lists[i]->arrival == false && lists[i]->departure == true)
            send_departure_ship_info(lists[i]->port_id);
   }
}

void call_ground_transport(Arrival_departure_ships* lists)
{
    G.unload_Cargo(lists->total_items);

}

void call_delivery(Cargo* cargo[],int n)
{
    D.deliver(cargo,n);
}

void send_departure_ship_info(int id)
{
    cout<<"Sent the departure ships information to port "<<id<<endl;
}
};

int main()
{
    Ships *S[10];
    /// List of Ships:
    S[0]= new Ships("A",4.5,"India",0);
    S[1]= new Ships("B",4.3,"Thailand",1);
    S[2]= new Ships("C",5.6,"India",2);
    S[3]= new Ships("D",6.7,"Canada",3);
    S[4]= new Ships("E",4.7,"Canada",4);
    S[5]= new Ships("F",3.4,"USA",5);
    S[6]= new Ships("G",1.7,"Portugal",6);
    S[7]= new Ships("H",3.7,"USA",7);
    S[8]= new Ships("I",4.2,"India",8);
    S[9]= new Ships("J",3.6,"UK",9);



    ///Loading Cargo
    cout<<"Cargo loading in progress..."<<endl;
/// name(name),type(type),weight(weight),length(length),breadth(breadth),height(height),price(price),cargo_id(cargo_id)
    Cargo* C1[3];
    C1[0]= new Cargo("ABC","Food",3.2,1.2,1.3,1.5,15.6,0);
    C1[1]= new Cargo("DEF","Apparels",4.2,2.2,2.3,2.5,24.6,1);
    C1[2]= new Cargo("GHI","Metals",3.2,1.2,1.3,1.5,105.6,2);

    int n1 = 3;


    Cargo* C2[4];
    C2[0]= new Cargo("JKL","Coal",7.2,8.2,9.3,1.3,5.6,3);
    C2[1]= new Cargo("UTR","Fertilizers",3.2,1.2,1.3,1.5,15.6,4);
    C2[2]= new Cargo("KOMP","Computers",3.2,4.2,2.3,1.5,15.6,5);
    C2[3]= new Cargo("MP","Machinery",3.2,4.2,2.3,1.5,72.6,6);

    int n2 = 4;

    Cargo* C3[5];

    C3[0]= new Cargo("PAP","Papers",3.2,4.2,2.3,1.5,3.6,7);
    C3[1]= new Cargo("KP","Computers",3.2,4.2,2.3,1.5,15.6,8);
    C3[2]= new Cargo("UIN","Bags",3.2,4.2,2.3,1.5,15.6,9);
    C3[3]= new Cargo("REYN","Pens",3.2,4.2,2.3,1.5,15.6,10);
    C3[4]= new Cargo("MECR","Tablets",3.2,4.2,2.3,1.5,15.6,11);

    int n3 = 5;

    cout<<"\nCargo Loaded Successfully..."<<endl;

    cout<<"\nPress Any Key to Schedule the ships...";
    getch();

    Arrival_departure_ships *ADS[5];
    ///Arrival Departure Ships
    ADS[0]= new Arrival_departure_ships(S,19,6,2021,1,0,C1,n1,8,2);
    ADS[1]= new Arrival_departure_ships(S,19,6,2021,1,0,C2,n2,3,2);
    ADS[2]= new Arrival_departure_ships(S,19,6,2021,0,1,C3,n3,0,7);
    ADS[3]= new Arrival_departure_ships(S,19,6,2021,1,0,C2,n2,9,2);
    ADS[4]= new Arrival_departure_ships(S,19,6,2021,0,1,C1,n1,4,7);
    cout<<"\nArrival & Departure Ships Scheduled..."<<endl;

    int i;
    cout<<"\nPress Any Key to Display the Scheduled Ships...";
    getch();
    cout<<endl;
    cout <<"\nDay\t\tMonth\t\tYear\t\tShip_no"<<endl;
    for(i=0;i<5;i++)
    {
        ADS[i]->display();

    }

    cout<<"\nPress Any Key to Load the Ports...";
    getch();
    cout<<"\nLoading the list of ports...\n";

    Ports* P[8];
    /// Ports(string name,int arrival_capacity,int departure_capacity,string location,float wind,bool open,bool close,int port_id)
    P[0]= new Ports("A",100,100,"India",5.3,1,0,0);
    P[1]= new Ports("B",100,100,"India",5.3,1,0,1);
    P[2]= new Ports("C",100,100,"India",5.3,1,0,2);
    P[3]= new Ports("D",100,100,"India",5.3,1,0,3);
    P[4]= new Ports("E",100,100,"India",5.3,1,0,4);
    P[5]= new Ports("F",100,100,"India",5.3,1,0,5);
    P[6]= new Ports("G",100,100,"India",5.3,1,0,6);
    P[7]= new Ports("H",100,100,"India",5.3,1,0,7);
    cout<<"Ports Information Loaded..."<<endl;

    cout<<"\nPress Any Key To load our Prime Port...";
    getch();
    cout<<"\nLoading Prime Port...\n";
    Prime_Port* PM = new Prime_Port("C",100,100,"India",5.3,1,0,2);
    cout<<"Our Prime Port Opened"<<endl;
    cout<<"Press Any Key to Display the Prime Port...";
    getch();
    cout<<"\n\nNAME\t\tLocation\t\tPort ID\n";
    cout<<PM->name<<"\t\t"<<PM->location<<"\t\t"<<PM->port_id<<endl;

    cout<<"Press Any Key to START SAILING THE SHIPS!...";
    getch();

    cout<<"\nJOURNEY BEGINS!!Ships are Sailing\n\n";

    cout<<"Ships are near to their destination and are requesting their destination port information";
    cout<<"\nPress Any key to deliver the live port information to the ships...";
    getch();
    cout<<"\nGiving their arrival port's live information\n\n";
    for(i=0;i<5;i++)
    {
        ADS[i]->get_current_port_info(P);
    }
    cout<<"DOCKING..."<<endl;

    cout<<"\nShips have reached the Prime Port!!"<<endl;
    cout<<"\nPress any key to start port operations....";
    getch();

    PM->operate(ADS,5);
    cout<<"\t\t\tTHANK YOU"<<endl;
    return 0;
}
