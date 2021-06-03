#include<iostream>
#include<map>
#include<iterator>


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
    virtual void display();
};

class Cargo
{
    public:
     string name,type;
     float weight,length,breadth,height,price;
     int cargo_id;
     Cargo(string name,string type,float weight,float lenght,float breadth,float height,float price,int cargo_id)
     {}
};


class Current_port_info
{
    public:
      float wind_speed;
      bool open;
      bool closed;
      int port_id;
      Current_port_info(float wind_speed,bool open,bool close,int port_id)
      {
          this->wind_speed=wind_speed;
          this->open=open;
          this->closed=close;
          this->port_id=port_id;
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
      void get_port_info()
      {

      }
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
    }

};




class Arrival_departure_ships:public Ships
{
    public :
     int day,month ,year;
     bool departure,arrival;
     Cargo* items;
     int total_items;
     Arrival_departure_ships(int day,int month,int year,bool ad,Cargo items[],int totalitems)
     {
         this->day=day;
         this->month=month;
         this->year=year;
         this->arrival=ad;
         this->items=items;
         this->total_items=totalitems;
     }
    void display()
    {
        cout << "\tDay : "  << day << "\tMonth : " << month << "\tYear : " << year<<endl;
        for(int i=0;i<total_items;i++)
        {
            cout <<items[i] << "\n";
        }

    }
    void get_current_port_info()
    {
        Current_port_info T();

        T.display_port_info();
    }
};


class Prime_Port: public Ports
{
Ground_transport G;
Delivery D;
public:
Prime_Port(string name, int arrival_c, int departure_c, string location, float wind, bool o, bool c, int id)
: Ports(name(name), arrival_capacity(arrival_c), departure_capacity(departure_c), location(location), wind(wind),open(o), closed(c),port_id(id))
{
D.fill_customs_chart();
}

void operate(Arrival_Departure_Ships lists[],int counter)
{
   int i;
   for(i=0;i<counter;i++)
   {
        if(lists[i].arrival == true && lists[i].departure == false)
        {
            call_ground_transport();
            call_delivery(lists[i].Cargo,lists[i].total_capacity);
        }
        else if(lists[i].arrival == false && lists[i].departure == true)
            send_departure_ship_info(lists[i].arriving_port_id);
   }
}

void call_ground_transport()
{
    G.unload_Cargo(lists[i].total_capacity);

}

void call_delivery(Cargo[],int n)
{
    D.deliver(Cargo,n);
}

void send_departure_ship_info(int id)
{
    cout<<"Sent the departure ships information to port "<<id<<endl;
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
        cout<<"Unloaded the Cargo Successfully!"<endl;

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
map<string, float> : Customs_chart;
bool success;

Customs()
{
  success = false;
}
int levy_customs(cargo[],int n)
{
    int i;
    map<string,float> : itr;
    for(i=0;i<n;i++)
    {
        for(itr=Customs_Chart.begin();itr<Customs_Chart.end(),itr++)
        {
            if(itr->first==cargo[i].type)
                {
                    cargo[i].price += itr->second;
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

void fill_customs_chart()
{

}

int deliver(Cargo[], int n)
{
   bool temp;
   int i;
   temp = customs.levy_customs(Cargo[],n);
   if(temp==true)
        {
            cout<<"Name\t\tPrice\t\tType"<<endl;
            for(i=0;i<n;i++)
            {
                cout<<Cargo[i].name<<"\t\t"<<Cargo[i].price<<"\t\t"<<Cargo[i].type<<endl;
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



int main()
{
    Ship *S[10];
    /// LIst of Ships:
    S[0]();
    S[1]();
    S[2]();
    S[3]();
    S[4]();
    S[5]();
    S[6]();
    S[7]();
    S[8]();
    S[9]();



    ///Loading Cargo
    cout<<"Cargo is getting loaded to arrival departure ships...."<<endl;

    Cargo* C1[3];
    C1[0]();
    C1[1]();
    C1[2]();

    int n1 = 3;


    Cargo* C2[4];
    C2[0]();
    C2[1]();
    C2[2]();
    C2[3]();

    int n2 = 4;

    Cargo* C3[5];

    C3[0]();
    C3[1]();
    C3[2]();
    C3[3]();
    C3[4]();

    int n3 = 5;

    cout<<"Cargo Loaded Successfully..."<<endl;

    Arrival_departure_ships *ADS[5];
    ///Arrival Departure Ships
    ADS[0]();
    ADS[1]();
    ADS[2]();
    ADS[3]();
    ADS[4]();
    cout<<"Arrival & Departure Ships Scheduled..."<<endl;

    int i;

    for(i=0;i<5;i++)
    {
        ADS[i].display();

    }

    ///Loading the list of ports

    Ports* P[8];

    P[0]();
    P[1]();
    P[2]();
    P[3]();
    P[4]();
    P[5]();
    P[6]();
    P[7]();
    cout<<"Ports Information Loaded..."<<endl;

    P[0].open = true; ///Prime Port
    Prime_Port* PM();
    cout<<"Our Prime Port Opened"<<endl;
    cout<<"\nNAME\t\tLocation\t\tPort ID\n";
    cout<<PM.name<<"\t\t"<<PM.location<<"\t"<<PM.port_id;


    cout<<"Ships are Sailing and are requesting their destination port information..."<<endl;
    for(i=0;i<5;i++)
    {
        ADS[i].get_current_port_info();
    }

    PM.operate();
    cout<<"\t\t\tTHANK YOU"<<endl;
    return 0;
}
