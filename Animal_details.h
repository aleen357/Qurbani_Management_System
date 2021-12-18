#pragma once
#include "Goat.h"
#include "Cow.h"
#include <list>

using namespace std;
class Animal_details
{
protected:
	list<Cow> my_cow;
	list<Goat> my_goat;
	static int curr_token;
	
public:
	Animal_details();
	void fill_details();	//the file handling function which will read from cow.txt and goat.txt and fill the arrays
	void write_details();	//writes the animal to the file
	void available_animal_details();	//displays the available animals
	bool add_animal();		//adds a new animal
	bool add_cow();			//adds a new cow
	bool add_goat();		//adds a new goat
	int validate_price();	//makes sure the price is not negative
	void view_details();	//displays all the animals
	void view_animal(int);	//displays a specific  animal
	friend class Booking_main;
};