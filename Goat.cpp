
#include "Goat.h"

Goat::Goat()
{

}
Goat::Goat(int id, int price) :Animal(id, price)
{
	part_of_goat = false;//will initialize all parts with zero--we will mark parts taken with 1
}

Goat::~Goat()
{

}