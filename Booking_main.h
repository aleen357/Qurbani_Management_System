
#ifndef SDA_PROJECT_BOOKING_MAIN_H
#define SDA_PROJECT_BOOKING_MAIN_H

#include"Booking.h"
#include "Animal_details.h"
#include <list>
#include <iostream>
#include <ctime>
using namespace std;

class Booking_main {
    list<Booking> list_of_Booking;
    static int total_bookings;
	int Bookings_per_day[3];
	static int curr_hours;
	static int curr_mins;

public:
	Booking_main();
	void add_booking(Animal_details &obj);
	void view_booking(int);
	void fill_bookings(); 
	void write_bookings();
	void view_booking_of_a_customer(char (&a)[20]);
	void TimeSet();
	void TimeReset();
	void Set_customer(Customer &obj);
	
	void SetBookings(Booking &obj);
	bool Check_valid_order(int tok, int share, Animal_details &obj);
	//
	void Execute_Bookings(int ID);
	void Execute_All_Bookings();
	void Customer_has_come(int B_id);
};


#endif //SDA_PROJECT_BOOKING_MAIN_H
