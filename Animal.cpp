#include "Animal.h"

Animal::Animal()
{

}
Animal::Animal(int id, int price)
{
	this->token = id;
	this->price = price;
	this->status = false;//false shows animal is not completely booked
}

int Animal::Get_token()
{
	return this->token;
}

int Animal::Get_price()
{
	return this->price;
}