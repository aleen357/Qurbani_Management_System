
#ifndef SDA_PROJECT_BOOKING_H
#define SDA_PROJECT_BOOKING_H


#include "Animal.h"
#include "Customer.h"
#include <list>
#include <iostream>
using namespace std;

class Booking {
    static int booking_id_count;
    int booking_id;
    list<Animal> detail_of_animal;
    Customer buyer;
    int Day_to_get_meat;
    string Start_time;  // when his slaughter time starts
    string End_time;
public:
    friend class Customer;
	Booking();
};




#endif //SDA_PROJECT_BOOKING_H
