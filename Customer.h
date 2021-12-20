
#ifndef SDA_PROJECT_CUSTOMER_H
#define SDA_PROJECT_CUSTOMER_H

#include <string>
#include <iostream>
#include <string.h>
using namespace std;

class Customer {
    char name[30];
    char cnic[20];
    char contact[15];
public:
    friend class Booking;
	Customer();
	void SetName(char(&N)[30]);
	void SetCNIC(char(&id)[20]);
	void SetContact(char(&c)[15]);
	Customer( char (&N)[30],  char (&id)[20], char (&c)[15]);
	char* getName();
	char* getCNIC();
	char* getContact();
};


#endif //SDA_PROJECT_CUSTOMER_H
