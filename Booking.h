
#ifndef SDA_PROJECT_BOOKING_H
#define SDA_PROJECT_BOOKING_H


#include "Animal.h"
#include "Animal_details.h"
#include "Customer.h"
#include <list>
#include <iostream>
using namespace std;


class Booking {
protected:

	struct booked_animal//we can make a list of this strut so we can keep track of all 
					// animals and their parts a customer is buying in one booking
	{
		int token;
		int parts;
	};

    int booking_id;
    list<booked_animal> detail_of_animal;
    Customer buyer;
    int Day_to_get_meat;

    int Shour;  // when his slaughter time starts
	int Ehour;
	int Smins;  // when his slaughter time starts
	int Emins;
	int status;
	int total_price;

public:

	

	friend class Booking_main;
    friend class Customer;
	Booking();
	Booking(int);
	int calc_total_price(Animal_details &obj);
	void SetPrice(int);
	void Set_booking_id(int x);
	int Get_booking_id();
	void insert_an_animal(int, int);
	void print_booking();//prints booking details of one booking
};




#endif //SDA_PROJECT_BOOKING_H
