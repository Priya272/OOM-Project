#ifndef __CUSTOMER
#define __CUSTOMER

#include<string>
using std::string;

namespace example
{
    
class Customer
{
    private:
    string name;
    string phone;
    string check_in_date;
    string check_out_date;
    int days;                   //no. of days of residing in the hotel
    int hotel_id;               //id provided by the hotel to customer 
    int id_proof;               //customer's valid id proof
    static int hotel_id_counter;
    int bill;

    public:
    Customer();
    void fill_customer_details();
    string get_name();
    string get_phone();
    string get_check_in_date();
    string get_check_out_date();
    int get_hotel_id();
    int get_days();
    void pay_bill();
    int bill_paid();        //returns the bill paid by the customer
    void displayCustomerDetails();
};

}

#endif