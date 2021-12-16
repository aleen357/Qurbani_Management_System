#include "Animal_details.h"
#include <iostream>
#include <fstream>
using namespace std;
int Animal_details::curr_token = 0;
Animal_details::Animal_details()
{
	//
	
}
void Animal_details::fill_details()
{
	//

}

void Animal_details::write_details()
{
	ofstream out;
	out.open("Cow.txt");
	if (out.is_open())
	{
		cout << "cow file opened to write" << endl;
		Cow dummy()
		file_obj.write((char*)& class_obj, sizeof(class_obj));

	}
	else
		cout << "error in cow file" << endl;
}

bool Animal_details::add_animal()
{
	cout << "Select type of animal" << endl;
	cout << "1.cow" << endl;
	cout << "2.goat" << endl;
	int x = 0;
	cin >> x;
	if (x == 1)
	{
		add_cow();
		
	}
	else
	{
		add_goat();
	}
	return false;
}

int Animal_details::validate_price()
{
	int x;
	bool check=false;
	//int this function we take inpu of price and validate the price
	cout << "ENTER PRICE OF YOUR ANIMAL: PKR ";
	while (check == false)
	{
		cin >> x;
		if (x < 0)
		{
			cout << "incorrect price" << endl;
			cout << "enter again" << endl;
		}
		else
			check = true;
	}
	return x;
}

bool Animal_details::add_cow()
{
	cout<<"NEW COW"<<endl;
	int price=validate_price();
	curr_token++;
	Cow new_cow(curr_token, price);
	this->my_cow.push_back(new_cow);
	return true;
}

bool Animal_details::add_goat()
{
	cout << "NEW GOAT" << endl;
	int price = validate_price();
	curr_token++;
	Goat new_goat(curr_token, price);
	this->my_goat.push_back(new_goat);
	return true;
}











