#pragma once
#ifndef SDA_PROJECT_ANIMAL_H
#define SDA_PROJECT_ANIMAL_H

class Animal
{
protected:
	int token;
	int price;
	bool status;		//booked or not
public:
	Animal(int, int);
	Animal();
	friend class Animal_details;
	friend class Booking_main;
	int Get_token();
	int Get_price();
};

#endif //SDA_PROJECT_ANIMAL_H
