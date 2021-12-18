#pragma once
//Salesman can
//View the list of animals
//View the list of available animals
//View an animal's detail
//View schedule
//View all the reservations of a customer(show the total amount)
#include"Animal_details.h"
struct salesmaninfo
{
	int ids;
	char passes[20];
public:
	salesmaninfo()
	{

	}
	salesmaninfo(int, char[])
	{

	}
	int get_id() {
		return this->ids;
	}
	char* get_pass() {
		return passes;
	}
};
class Salesman//
{
protected:
	//Booking_main My_bookings;
	Animal_details My_Animals;
	int id;
	char password[20];
	
public:
	Salesman();
	//Salesman(int);
	Salesman(int, char arr[]);
	void view_booking();
	void view_available_animals();
	void view_details();
	void view_an_animal();
	void view_reservations_of_customer(int);
	int get_id();
	char* get_pass();
	//Animal_details My_Animals;
	//friend class Animal_details;
};

//password mechanism shit?
//make an admin pass file
//read its id
//save its id as such
//read its password
//save its password


