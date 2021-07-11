#include "LuxuriousRoom.h"
#include<string>

using std::cout;
using std::cin;
using std::string;

namespace example
{
    void LuxuriousRoom::set_room_details()
    {
        Room::set_room_details();
        cout<<"\n ac/non-ac[A/N]: ";
        cin>>ac;
        cout<<"\n TV[Y/N]: ";
        cin>>tv;
        cout<<"\n Size[M/L]: ";
        cin>>size;
    }

    void LuxuriousRoom::displayRoom()
    {
        Room::displayRoom();
        cout<<"\n AC/Non-ac: "<<ac;
        cout<<"\n TV/No-Tv: "<<tv;
        cout<<"\n Medium/Large: "<<size;
    }
    
    char LuxuriousRoom::ac_status()
    {
        return ac;
    }

    char LuxuriousRoom::tv_status()
    {
        return tv;
    }

    char LuxuriousRoom::room_size()
    {
        return size;
    }
}


