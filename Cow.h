
#ifndef SDA_PROJECT_COW_H
#define SDA_PROJECT_COW_H

#include "Animal.h"

class Cow : public Animal {
    bool *parts;
    int parts_remaining;
public:
	Cow();
	Cow(int, int);
	~Cow();
};


#endif //SDA_PROJECT_COW_H
