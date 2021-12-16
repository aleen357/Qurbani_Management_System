
#include "Customer.h"
#include <string.h>
#include <iostream>
using namespace std;

Customer::Customer()
{

}

Customer::Customer(const string &buff, const string &id, const string &c)
{
	name = buff;
	cnic = id;
	contact = c;
}
