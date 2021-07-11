#ifndef __ROOM
#define __ROOM
#include<iostream>
#include "Customer.h"

using namespace std;

namespace example
{
    class Room
    {
        protected:
        int roomNumber;
        Customer currentCustomer;
        int rent_per_day;
        bool availability;
        

        public:
        Room();
        virtual void set_room_details();
        int get_roomNumber();
        int get_rent();
        bool check_availability();
        Customer* get_customer_details();
        void bookRoom(); 
        void emptyRoom();
        virtual void displayRoom();   
        
    };
}

#endif