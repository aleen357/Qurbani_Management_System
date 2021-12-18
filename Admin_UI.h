#pragma once
#include "Animal_details.h"
#include "Booking_main.h"
#include <list>
class Admin_UI 
{
	Animal_details My_Animals;

public:
	Admin_UI();
	//Admin_UI(char arr[20]);
	void add_booking();
	void add_animal();
	//void add_salesman();
	void view_details();
	//void view_booking();
	//void set_password();
	//void get_password();
	void view_booking();
	void view_available_animals();
	void view_an_animal(int);
	void view_reservations_of_customer(int);


};