
#include "Booking.h"

Booking::Booking()
{
	//
	status = 0;
}

Booking::Booking(int x)
{
	booking_id = x;
	status = 0;
}
int Booking::calc_total_price(Animal_details &obj)
{
	int Sum = 0, tok = 0, share_of_this_animal = 0, prices_individual = 0;
	for (auto i = this->detail_of_animal.begin(); i != this->detail_of_animal.end(); ++i)
	{
		tok= i->token;
		share_of_this_animal = i->parts;
		for (auto j = obj.my_cow.begin(); j != obj.my_cow.end(); ++j)
		{
			if (tok == j->Get_token())
			{
				prices_individual = j->Get_price();
				prices_individual = prices_individual / 7;
				prices_individual = prices_individual * share_of_this_animal;
				Sum = Sum + prices_individual;
				prices_individual = 0;
			}

		}

	}
	for (auto i = this->detail_of_animal.begin(); i != this->detail_of_animal.end(); ++i)
	{
		tok = i->token;
		for (auto j = obj.my_goat.begin(); j != obj.my_goat.end(); ++j)
		{
			if (tok == j->Get_token())
			{
				Sum = Sum + j->Get_price();
			}

		}

	}
	return Sum;
}

void Booking::insert_an_animal(int id, int number_of_shares)
{
	booked_animal obj;
	obj.parts = number_of_shares;
	obj.token = id;
	detail_of_animal.push_back(obj);
}


void Booking::SetPrice(int a)
{
	total_price = a;
}
void Booking::Set_booking_id(int x)
{
	booking_id = x;
}
int Booking::Get_booking_id()
{
	return booking_id ;
}

void Booking::print_booking()
{
	int count = 1;
	cout << "----------------------------------" << endl;
	cout << "                                  " <<endl;
	cout << "Booking ID: " << this->booking_id << " " << endl;
	cout << "Customer Name: " << this->buyer.name << endl;
	cout << "Customer CNIC: " << this->buyer.cnic << endl;
	cout << "Customer Constact: " << this->buyer.contact << endl;
	cout << "Day " << this->Day_to_get_meat << " at time " << Shour << " : " << Smins << endl;
	cout << "Animal ";
	for (auto i = this->detail_of_animal.begin(); i != this->detail_of_animal.end(); ++i)
	{
		cout<< count << " :" << endl;
		cout << "Token: " << i->token << endl;
		cout << "Parts: " << i->parts << endl;
		count++;
	}
	cout << "          TOTAL PRICE= " << this->total_price << endl;
	cout << "current status of booking ";
	int s = this->status;
	if (s == 0)
		cout << "In Process" << endl;
	if (s == 1)
		cout << "slaughtered" << endl;
	if (s == 2)
		cout << "collected" << endl;
	if (s == 3)
		cout << "distributed to poor" << endl;
	cout << "----------------------------------" << endl;
}