
#ifndef SDA_PROJECT_BOOKING_H
#define SDA_PROJECT_BOOKING_H


#include "Animal.h"
#include "Customer.h"
#include <list>
#include <iostream>
using namespace std;

struct booked_animal//we can make a list of this strut so we can keep track of all 
	                // animals and their parts a customer is buying in one booking
{
	int token;
	int parts;
};

class Booking {
    static int booking_id_count;
    int booking_id;
    list<booked_animal> detail_of_animal;
    Customer buyer;
    int Day_to_get_meat;
    string Start_time;  // when his slaughter time starts
    string End_time;
public:
    friend class Customer;
	Booking();
};




#endif //SDA_PROJECT_BOOKING_H
