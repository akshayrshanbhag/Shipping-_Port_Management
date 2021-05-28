
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
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

class Ports:public Current_port_info
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
        Current_port_info(wind,open,close,port_id)
    }

};

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
    virtual void display=0;
}
class Cargo
{
    public:
     string name,type;
     float weight,length,breadth,height,price;
     int cargo_id;
     Cargo(string name,string type,float weight,float lenght,float breadth,float height,float price,int cargo_id)
}
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
        cout << "\tDay : "  << day << "\tMonth : " << month << "\tYear : " << year << "\tArrival : " << ad << endl;
        for(int i=0;i<total_items<i++)
        {
            cout << items[i] << "\n";
        }
    }
    void get_current_port_info()
    {

    }

}
