
#ifndef SDA_PROJECT_COW_H
#define SDA_PROJECT_COW_H

#include "Animal.h"

class Cow : public Animal {
    int parts[7];		//0=not booked, 1= booked, 2= slaughtered, 3= delivered, 4= distributed
    int parts_remaining;
public:
	Cow();
	Cow(int, int);
	~Cow();
	int Get_parts_remaining();
	void Set_parts(int, int);
};


#endif //SDA_PROJECT_COW_H
