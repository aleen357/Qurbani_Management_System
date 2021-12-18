#include "Salesman.h"

Salesman::Salesman()
{
	id = 0;
	//you are signed in as id=x
	//
}
Salesman::Salesman(int x ,char arr[])
{
	this->id = x;
	strcpy_s(this->password,20, arr);
}
void Salesman::view_booking()
{

}
void Salesman::view_available_animals()
{

}
void Salesman::view_details()
{
	My_Animals.view_details();
	
}
void Salesman::view_an_animal()
{

}
void Salesman::view_reservations_of_customer(int)
{

}
int Salesman::get_id()
{
	return this->id;
}
char* Salesman::get_pass()
{
	return password;
}