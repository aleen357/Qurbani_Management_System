#pragma once
#include "Animal_details.h"
#include "Booking_main.h"
#include "Salesman.h"
#include<list> 
class Admin_UI
{
	//Booking_main My_bookings;
	Animal_details My_Animals;
	list<Salesman> My_Salesmen;
	int number_salesman;

public:
	Admin_UI();
	//void add_booking();
	void add_animal();
	//void view_booking();
	//void set_password();
	//void get_password();
	void add_salesman();
	void view_details();
};
