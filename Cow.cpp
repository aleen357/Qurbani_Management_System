
#include "Cow.h"

Cow::Cow()
{
	//
}

Cow::Cow(int id, int price):Animal(id,  price)
{
	for (int i = 0; i < 7; i++) {
		parts[i] = 0;
	}
	
	parts_remaining = 7;
}

Cow::~Cow()
{
	//
}

int Cow::Get_parts_remaining()
{
	return parts_remaining;
}

void Cow::Set_parts(int x, int stat)			//x=no of parts to be booked
{
	int start = 7 - parts_remaining;
	for (int i = start; i <= x; i++)
	{
		parts[i] = stat;
	}
	parts_remaining = parts_remaining - x;
}