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
	int id;
	char password[20];
public:
	Salesman();
	Salesman(int, char arr[]);
	void view_booking();
	void view_available_animals();
	void view_details();
	void view_an_animal();
	

};

