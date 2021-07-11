#include"Hotel.h"
#include<string>
#include<stdlib.h>

using std::cin;
using std::cout;
using std::string;
using namespace example;

void manage()
{
    Hotel hotel("Taj Hotel","1234");
    int opt1;
    do
    {
    system("clear");
    cout<<"\n-------"<<hotel.hotel_name<<"-------";
    cout<<"\n1.) Staff";
    cout<<"\n2.) Customer";
    cout<<"\n3.) Exit";
    cout<<"\n Enter option: ";
    cin>>opt1;
    switch(opt1)
    {
        case 1:
        {
          cout<<"\n Enter password: ";
          string pass; cin>>pass;
          if(pass==hotel.get_hotel_password())
          {
            int opt2;
            do
            {
              cout<<"---------------------------------"<<endl;
              cout<<"\n1.) Add Room";
              cout<<"\n2.) Search Customer";
              cout<<"\n3.) Search Room";
              cout<<"\n4.) Get present guest summary";
              cout<<"\n5.) Get all records";
              cout<<"\n6.) Exit";
              cout<<"\n Enter option: ";
              cin>>opt2;

              switch(opt2)
              {
                case 1:
                {
                cout<<"---------------------------------"<<endl;
                cout<<"\n Normal Room/Luxurious Room[N/L]: ";
                char ans; cin>>ans;
                if(ans=='N')
                {
                  Room room;
                  room.set_room_details();
                  hotel.addRoom(room);
                }
                else if(ans=='L')
                {
                  LuxuriousRoom room;
                  room.set_room_details();
                  hotel.addRoom(room);
                }
                else
                {
                  cout<<"\n You entered a wrong option.";
                }
                cout<<"\n---------------------------------"<<endl;
                break;
                }

                case 2:
                cout<<"---------------------------------"<<endl;
                hotel.searchCustomer();
                cout<<"\n---------------------------------"<<endl;
                break;

                case 3:
                {
                cout<<"---------------------------------"<<endl;
                int room_no;
                cout<<"\n Enter Room Number: ";
                cin>>room_no;
                hotel.searchRoom(room_no);
                cout<<"\n---------------------------------"<<endl;
                break;
                }

                case 4:
                cout<<"---------------------------------"<<endl;
                hotel.getGuestSummary();
                cout<<"\n---------------------------------"<<endl;
                break;

                case 5:
                cout<<"---------------------------------"<<endl;
                hotel.viewRecord();
                cout<<"\n Thank You \n";
                cout<<"\n---------------------------------"<<endl;
                break;

                case 6:
                break;

                default:
                cout<<"\n Wrong option";
                cout<<"\n---------------------------------"<<endl;
              }
        
            }while(opt2!=6);
          }
          else
          {
            cout<<"\n Wrong Password ";
            cout<<"\n---------------------------------"<<endl;
          }
          break;
        }

        case 2:
        {
        int opt3;
        do
        {
         cout<<"---------------------------------"<<endl;
         cout<<"\n1.) Check In ";
         cout<<"\n2.) Check out ";
         cout<<"\n3.) Check available rooms";
         cout<<"\n4.) Exit ";
         cout<<"\n Enter option: ";
         cin>>opt3;
        
         switch(opt3)
         {
            case 1:
            cout<<"---------------------------------"<<endl;
            hotel.checkIn();
            break;

            case 2:
            cout<<"---------------------------------"<<endl;
            hotel.checkOut();
            break;
            
            case 3:
            cout<<"---------------------------------"<<endl;
            hotel.check_available_rooms();
            break;
            
            case 4:
            break; 

            default:
            cout<<"\n Wrong Option.";
            
         }  
        }while(opt3!=4);
        }

        case 3:
        break;

        default:
        cout<<"\n Wrong option";
    }

} while (opt1!=3);

    
}

int main()
{
  manage();
  cout<<".......Thank You For using our software.......";
  cout<<endl;
  return 0;
}
// g++ Customer.cpp Room.cpp LuxuriousRoom.cpp Hotel.cpp HotelManagementExample.cpp 
