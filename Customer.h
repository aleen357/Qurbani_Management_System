
#ifndef SDA_PROJECT_CUSTOMER_H
#define SDA_PROJECT_CUSTOMER_H

#include <string>
#include <iostream>
#include <string.h>
using namespace std;

class Customer {
    string name;
    string cnic;
    string contact;
public:
    friend class Booking;
	Customer();
	Customer(const string &N, const string &id, const string &c);
};


#endif //SDA_PROJECT_CUSTOMER_H
