#pragma once
#include "Animal_details.h"
#include "Booking_main.h"
class Admin_UI
{
	//Booking_main My_bookings;
	Animal_details My_Animals;
public:
	Admin_UI();
	void add_booking();
	void add_animal();
	void view_booking();
};
