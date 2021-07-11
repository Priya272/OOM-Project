#include<iostream>
#include<string> 
#include "Hotel.h"
#include<fstream>


using std::string;
using std::cout;
using std::cin;
using std::endl;

namespace example
{

    Hotel::Hotel(string name, string password)
    {
        this->hotel_name = name;
        this->hotel_password= password;
    }

    void Hotel::checkIn()
    {
       if(count_of_Nrooms==0 && count_of_Lrooms==0)
       {
         cout<<"---------------------------------"<<endl;
         cout<<"\n Add room first.";
         return;
       }
       else
       {
         int found=0;
         cout<<"\n------------------CHECK IN-------------------";
         cout<<"\n Enter type of the room : ";
         cout<<"\n Normal Room(N)/Luxurious Room(L) : ";
         char type;
         cin>>type;
         if(type=='N' && count_of_Nrooms!=0)
         {
           for(int i=0;i<count_of_Nrooms;i++)
           {
             if(Nrooms[i].check_availability())
             {
             Nrooms[i].bookRoom();
             Nrooms[i].displayRoom();
             cout<<"\n------------------You have checked in successfully.-------------------";
             found=1;
             storeRecord(&Nrooms[i]);
             break;
             }
           }
         }
         else if(type=='L' && count_of_Lrooms!=0)
         {
            char ans1,ans2,ans3;
            cout<<"\n AC/non-AC[A/N]: ";
            cin>>ans1;
            cout<<"\n TV/no TV[Y/N]: ";
            cin>>ans2;
            cout<<"\n Size(Medium/Large[M/L]: ";
            cin>>ans3;
            for(int i=0;i<count_of_Lrooms;i++)
            {
              if(Lrooms[i].check_availability() && Lrooms[i].ac_status()==ans1 && Lrooms[i].tv_status()==ans2 && Lrooms[i].room_size()==ans3)
              {
                 Lrooms[i].bookRoom();
                 Lrooms[i].displayRoom();
                 cout<<"\n-------------------------------";
                 cout<<"\n------------------You have checked in successfully.-------------------";
                 found=1;
                 storeRecord(&Lrooms[i]);
                 break;
              }
            }
          }
    
         if(found==0)
         {
           cout<<"\n Sorry, no room available as per your choice."; 
         }
       }
    }

    void Hotel::checkOut()
    {
      if(count_of_Lrooms==0 && count_of_Nrooms==0)
      {
        cout<<"\n Add room first.";
        return;
      }    
      else
      {
        int rno;
        cout<<"Enter the room number: ";
        cin>>rno;
        cout<<"\n";
        int found=0;
        for(int i=0;i<count_of_Nrooms;i++)
        {
          if(Nrooms[i].get_roomNumber()==rno)
          {
            system("clear");
            cout<<"\n--------------CHECK OUT---------------";
            cout<<"\n Your bill is Rs: "<<Nrooms[i].get_rent()*(*(Nrooms[i].get_customer_details())).get_days();
            cout<<"\n Pay the bill(just type the bill) : ";
            (Nrooms[i].get_customer_details())->pay_bill();
            if(((Nrooms[i].get_customer_details())->bill_paid()) < (Nrooms[i].get_rent()*(*(Nrooms[i].get_customer_details())).get_days()))
            {
              found=1;
              cout<<"\nThe amount you paid is less than the required amount in bill...Please pay required amount";
              break;
            }
            if(((Nrooms[i].get_customer_details())->bill_paid()) > (Nrooms[i].get_rent()*(*(Nrooms[i].get_customer_details())).get_days()))
            {
              found=1;
              cout<<"\nThe amount you paid is greater than the required amount in bill...Please pay required amount";
              break;
            }
            else{
            Nrooms[i].emptyRoom();
            cout<<"\n----------Checked out successfully.---------";
            found=1;
            break;
            }
          }
        }
        for(int i=0;i<count_of_Lrooms;i++)
        {
          if(Lrooms[i].get_roomNumber()==rno)
          {
            system("clear");
            cout<<"\n--------------CHECK OUT---------------";
            cout<<"\n Your bill is : "<<Lrooms[i].get_rent()*(*(Lrooms[i].get_customer_details())).get_days();
            cout<<"\n Pay the bill(just type the bill) : ";
            (Lrooms[i].get_customer_details())->pay_bill();
            if(((Lrooms[i].get_customer_details())->bill_paid()) < (Lrooms[i].get_rent()*(*(Lrooms[i].get_customer_details())).get_days()))
            {
              found=1;
              cout<<"\nThe amount you paid is less than the required amount in bill...Please pay required amount";
              break;
            }
            if(((Lrooms[i].get_customer_details())->bill_paid()) > (Lrooms[i].get_rent()*(*(Lrooms[i].get_customer_details())).get_days()))
            {
              found=1;
              cout<<"\nThe amount you paid is greater than the required amount in bill...Please pay required amount";
              break;
            }
            else{
            Lrooms[i].emptyRoom();
            cout<<"\n----------Checked out successfully.---------";
            found=1;
            break;
            }
          }
        }
        if(found==0)
        {
            cout<<"\n No such room exist"; 
        }
       }
}

    void Hotel::searchRoom(int ro)
    {
        if(count_of_Nrooms==0 && count_of_Lrooms==0)
        {
          cout<<"\n Add room first.";
          return;
        }
        else
        {
          int found=0;
          for(int i=0;i<count_of_Nrooms;i++)
          {
            if(Nrooms[i].get_roomNumber()==ro)
            {
              cout<<"\nIt is a Normal Room"<<endl;
              Nrooms[i].displayRoom();
              found=1;
              break;
            }
          }
  
          for(int i=0;i<count_of_Lrooms;i++)
          {
             if(Lrooms[i].get_roomNumber()==ro)
             {
               cout<<"\nIt is a Luxurious Room"<<endl;
               Lrooms[i].displayRoom();
               found=1;
               break;
             }
          }
          
          if(found==0)
          {
             cout<<"\n No such room exist";
          }
        }   
    }
    
    void Hotel::addRoom(Room r)
    {   
    Nrooms[count_of_Nrooms] = r;     
    count_of_Nrooms++;
    cout<<"\n Room added successfully";
    }

    void Hotel::addRoom(LuxuriousRoom r)
    {   
    Lrooms[count_of_Lrooms] = r;     
    count_of_Lrooms++;
    cout<<"\n Room added successfully";
    }

    void Hotel::check_available_rooms()
     {
       int found=0;
       for(int i=0;i<count_of_Nrooms;i++)
       {
         if(Nrooms[i].check_availability())
         {
           found=1;
           Nrooms[i].displayRoom();
         }
       }

       for(int i=0;i<count_of_Lrooms;i++)
       {
         if(Lrooms[i].check_availability())
         {
           found=1;
           Lrooms[i].displayRoom();
         }
       }
       if(found==0) cout<<"\n No room available";
       else cout<<"\n-------Thank You-------";
     }

     void Hotel::storeRecord(Room* r)
    {
      fstream fio;
      fio.open("records.txt",ios::in|ios::out|ios::app);
      fio<<"------------------------------------------------------------\n";
      fio<<"Customer name: "<<(r->get_customer_details())->get_name()<<"\n";
      fio<<"Phone Number: "<<(r->get_customer_details())->get_phone()<<"\n";
      fio<<"Room Number: "<<(r->get_roomNumber())<<"\n";
      fio<<"Check in date: "<<(r->get_customer_details())->get_check_in_date()<<"\n";
      fio<<"Check out date: "<<(r->get_customer_details())->get_check_out_date()<<"\n";
      fio<<"Number of days:  "<<(r->get_customer_details())->get_days()<<"\n";
      fio<<"------------------------------------------------------------\n";
      fio.close();
    }

    void Hotel::viewRecord()
    {
      fstream fio;
      fio.open("records.txt");
      fio.seekg(0, ios::beg);
      string line;
      while (fio)
      {
  
        // Read a Line from File
        getline(fio, line);
  
        // Print line in Console
        cout << line << endl;
      }
  
    // Close the file
    fio.close();
    }

    void Hotel::getGuestSummary()
     {
       if(count_of_Nrooms==0 && count_of_Lrooms==0)
       {
         cout<<"\n Enter Nrooms first.";
         return;
       }
       else
       {
         int found=0;
        
         if(count_of_Nrooms)
         {
           for(int i=0;i<count_of_Nrooms;i++)
           {
             if(Nrooms[i].check_availability()==false)
             {
                found=1;
                (Nrooms[i].get_customer_details())->displayCustomerDetails();
                cout<<"\n Room number : "<<Nrooms[i].get_roomNumber();
                cout<<"---------------------------------"<<endl;
                
             }
           }
           cout<<endl;
         }

         if(count_of_Lrooms) 
         {
           for(int i=0;i<count_of_Lrooms;i++)
           {
             if(Lrooms[i].check_availability()==false)
             {
                found=1;
                (Lrooms[i].get_customer_details())->displayCustomerDetails();
                cout<<"\n Room number : "<<Lrooms[i].get_roomNumber();
                cout<<"---------------------------------"<<endl;
            }
           }
         }
         
         if(found==0) 
         {
            cout<<"\n No customer in the hotel.";
            cout<<"---------------------------------"<<endl;
         }
       }

    
    }
     
     void Hotel::searchCustomer()
     {
       cout<<"\n Enter name of customer: ";
       string name; cin>>name;
       int found =0;
       for(int i=0;i<count_of_Nrooms;i++)
       {
         if(Nrooms[i].get_customer_details()->get_name()==name && (Nrooms[i].check_availability() == false))
         {
           Nrooms[i].get_customer_details()->displayCustomerDetails();
           found=1;
           cout<<"---------------------------------"<<endl;
         }
       }

       for(int i=0;i<count_of_Lrooms;i++)
       {
         if(Lrooms[i].get_customer_details()->get_name()==name && (Lrooms[i].check_availability() == false))
         {
           Lrooms[i].get_customer_details()->displayCustomerDetails();
           found=1;
           cout<<"---------------------------------"<<endl;
         }
       }

       if(found==0) cout<<"\n No such customer found.";

       cout<<"\n Thank you!!";
     }
     
     string Hotel::get_hotel_password()
     {
       return hotel_password;
     }


}
