
#include "Cow.h"

Cow::Cow()
{
	//
}

Cow::Cow(int id, int price):Animal(id,  price)
{
	parts = new bool [7]();//will initialize all parts with zero--we will mark parts taken with 1
	parts_remaining = 7;
}

Cow::~Cow()
{
	//
}