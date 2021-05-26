#include<iostream>

using namespace std;



class Prime_Port()
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

    return 0;
}
