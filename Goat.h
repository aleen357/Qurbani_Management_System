
#ifndef SDA_PROJECT_GOAT_H
#define SDA_PROJECT_GOAT_H

#include "Animal.h"
class Goat : public Animal {
    int part_of_goat;		//0=not booked, 1= booked, 2= slaughtered, 3= delivered, 4= distributed
public:
	Goat();
	Goat(int, int);
	int Get_part_of_goat();
	void Set_part_of_goat(int);
	~Goat();
};



#endif //SDA_PROJECT_GOAT_H
