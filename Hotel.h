#ifndef __HOTEL
#define __HOTEL

#include<string>
#include<fstream>
#include "LuxuriousRoom.h"
using std::string;

namespace example
{
    class Hotel
    {
            private:
            string hotel_password;

            public:
            Room Nrooms[100];
            LuxuriousRoom Lrooms[100];
            string hotel_name;
            int count_of_Nrooms=0;
            int count_of_Lrooms=0; 
            
            public:
            Hotel(string, string);
            void checkIn();
            void checkOut();
            void searchRoom(int roomNumber); 
            void addRoom(Room);
            void addRoom(LuxuriousRoom);
            void check_available_rooms();
            void storeRecord(Room*);
            void viewRecord();                   //Record of all the customers who have ever checkedIn in hotel till date.
            string get_hotel_password();
            void searchCustomer();
            void getGuestSummary();             //Record of all customers who are presently checkedIn in hotel.


    };
}

#endif

