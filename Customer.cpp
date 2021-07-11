#include"Customer.h"
#include<iostream>

using std::cin;
using std::cout;

namespace example 
{
 int Customer::hotel_id_counter=100;

 Customer::Customer()
 {
     hotel_id=hotel_id_counter++;
 }

 void Customer::fill_customer_details()
 {
     cout<<"\n Enter your name : ";
     cin>>name;
     cout<<"\n Enter you phone number : ";
     cin>>phone;
     cout<<"\n Enter check in date (dd/mm/yyyy): ";
     cin>>check_in_date;
     cout<<"\n Enter check out date (dd/mm/yyyy): ";
     cin>>check_out_date;
     cout<<"\n Enter no. of days : ";
     cin>>days;
     cout<<"\n Enter id proof : ";
     cin>>id_proof;
 }

 int Customer::get_days()
 {
     return days;
 }


 
 string Customer::get_name()
 {
     return name;
 }

 string Customer::get_phone()
 {
     return phone;
 }

 string Customer::get_check_in_date()
 {
   return check_in_date;
 }

string Customer::get_check_out_date()
 {
   return check_out_date;
 }

 int Customer::get_hotel_id()
 {
   return hotel_id;
 }

 void Customer::displayCustomerDetails()
 {
    cout<<"\n-------------CUSTOMER DETAILS--------------";
    cout<<"\n Hotel ID: "<<hotel_id;
    cout<<"\n Customer Name: "<<name;
    cout<<"\n Phone Number: "<<phone;
    cout<<"\n Check in date: "<<check_in_date;
    cout<<"\n Check out date: "<<check_out_date;
    cout<<"\n Number of days: "<<days;
 }

 void Customer::pay_bill()
 {
   cin>>bill;
 }

 int Customer::bill_paid()
 {
   return bill;
 }

}