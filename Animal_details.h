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
	void fill_details();//the file handling function which will read from cow.txt and goat.txt and fill the arrays
	void write_details();
	bool add_animal();
	bool add_cow();
	bool add_goat();
	int validate_price();

};