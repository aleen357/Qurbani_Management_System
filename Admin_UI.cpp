#include "Admin_UI.h"
#include<iostream>
#include<fstream>
using namespace std;
Admin_UI::Admin_UI()
{

	
	//make an obj of animal details to export all info of available animals
	//A_details.add_animal();
	//make an obj of booking_main to export all info of available bookings
	//Booking_main Our_bookings;

}
void Admin_UI::add_animal()
{
	My_Animals.add_animal();
}

void Admin_UI::view_details()
{
	My_Animals.view_details();
}

/*void Admin_UI::add_salesman()
{
	//assign new id to salesman \
	//assign password
	//employees->salesman
}*/





