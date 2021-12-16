#pragma once
#ifndef SDA_PROJECT_ANIMAL_H
#define SDA_PROJECT_ANIMAL_H

class Animal
{
protected:
	int token;
	int price;
	bool status;
public:
	Animal(int, int);
	Animal();
	friend class Animal_details;
	
};

#endif //SDA_PROJECT_ANIMAL_H
