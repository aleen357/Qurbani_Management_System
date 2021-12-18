#include "Admin_UI.h"
#include<iostream>
#include<fstream>
using namespace std;

Admin_UI::Admin_UI()
{
	//
}
Admin_UI::Admin_UI(char buff[20])
{
	this->id = 0;//Id of admin will always be 0 of admin by default


void Admin_UI::add_animal()
{
	My_Animals.add_animal();
	
}

void Admin_UI::view_details()
{
	My_Animals.view_details();
	
}
void Admin_UI::add_booking()
{

}
void Admin_UI::view_booking()
{

}
void Admin_UI::view_available_animals()
{
	My_Animals.available_animal_details();
}

void Admin_UI::view_an_animal(int id)
{
	My_Animals.view_animal( id);
}
void Admin_UI::view_reservations_of_customer(int)
{

}





