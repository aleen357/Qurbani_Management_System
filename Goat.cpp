
#include "Goat.h"

Goat::Goat()
{

}
Goat::Goat(int id, int price) :Animal(id, price)
{
	part_of_goat = 0;//will initialize all parts with zero--we will mark parts taken with 1
}

Goat::~Goat()
{

}

int Goat::Get_part_of_goat()
{
	return part_of_goat;
}
void Goat::Set_part_of_goat(int x)
{
	part_of_goat = x;
}