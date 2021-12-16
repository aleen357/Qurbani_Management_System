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
