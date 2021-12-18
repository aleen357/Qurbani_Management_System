
#include "Customer.h"
#include <string.h>
#include <iostream>
using namespace std;

Customer::Customer()
{

}

Customer::Customer(char(&N)[30], char(&id)[20], char(&c)[15])
{
	strcpy_s(name,30, N);
	strcpy_s(cnic, 20, id);
	strcpy_s(contact, 15, c);
}


void Customer::SetName(char(&N)[30])
{
	strcpy_s(name, 30, N);
}

void Customer::SetCNIC(char(&id)[20])
{
	strcpy_s(cnic, 20, id);
}

void Customer::SetContact(char(&c)[15])
{
	strcpy_s(name, 15, c);
}

