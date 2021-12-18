#pragma once
#include "Animal_details.h"
#include "Booking_main.h"
#include "Salesman.h"
#include<list> 
class Admin_UI:public Salesman
{
	list<Salesman> My_Salesmen;
	int number_salesman;

public:
	Admin_UI();
	Admin_UI(char arr[20]);
	//void add_booking();
	void add_animal();
	//void view_booking();
	//void set_password();
	//void get_password();
	void add_salesman();
	void view_details();
	void write_salesman();//updates salesman file
};
