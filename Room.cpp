#include "Room.h"
#include<string>

using std::cout;
using std::cin;
using std::string;

namespace example
{
    Room::Room()
    {
        availability=true;
    }

    void Room::set_room_details()
    {
       cout<<"\nEnter the rent of this room: ";
       cin>>rent_per_day;
       cout<<"\nSet the room number of this room: ";
       cin>>roomNumber;
    }

    int Room::get_rent()
    {
        return rent_per_day;
    }

    int Room::get_roomNumber()
    {
        return roomNumber;
    }

    Customer* Room::get_customer_details()
    {
        return &currentCustomer;
    }

    void Room::bookRoom()
    {
      Customer* c = new Customer;
      currentCustomer = *c;
      currentCustomer.fill_customer_details();
      availability=false;
    }

    void Room::emptyRoom()
    {
        availability=true;
        delete &currentCustomer;
    }

    bool Room::check_availability()
    {
        return availability;
    }

    void Room::displayRoom()
    {
    cout<<"\n------------------- ROOM DETAILS--------------- ";
    cout<<"\n Room Number: \t"<<roomNumber;
    cout<<"\n Rent: "<<rent_per_day;
    availability==false?cout<<"\n Room is booked .":cout<<"\n Room is available";
    }


}


