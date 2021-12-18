#pragma once
//Salesman can
//View the list of animals
//View the list of available animals
//View an animal's detail
//View schedule
//View all the reservations of a customer(show the total amount)
#include"Animal_details.h"

class Salesman//
{
	//Booking_main My_bookings;
	Animal_details My_Animals;
public:
	friend class Admin_UI;
	Salesman();
	void view_booking();
	void view_available_animals();
	void view_animals();

};

