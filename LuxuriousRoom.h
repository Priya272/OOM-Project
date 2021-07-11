#ifndef __LUXURIOUSROOM
#define __LUXURIOUSROOM

#include"Room.h"
#include<string>
using std::string;


namespace example
{
    class LuxuriousRoom : public Room
    {
     protected:
     char tv;
     char ac;
     char size;

     public:
     void set_room_details();
     void displayRoom();
     char ac_status();
     char tv_status();
     char room_size();
    };
}

#endif