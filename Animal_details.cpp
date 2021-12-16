#include "Animal_details.h"
#include <iostream>
#include <fstream>
using namespace std;
int Animal_details::curr_token = 0;
Animal_details::Animal_details()
{
	//Animal details is a member variable of admin_ui So when it is made it should 
	//read Cow and Goat bin files
	//write objects to member of animal_details

	//STEP 1: Fill Cow list with cow.bin
	ifstream fin;
	fin.open("Cow.bin", ios::binary);
	if (fin.is_open())
	{
		cout << "cow file opened to read--reading to fill list cows in animal details" << endl;
		Cow *dummy;
		while(!fin.eof())
		{
			dummy = new Cow;
			fin.read((char*)& *dummy, sizeof(Cow));
			this->my_cow.push_back(*dummy);
			cout << "price: " << dummy->price << endl;
			cout << "token" << dummy->token << endl;
			//file_obj.write((char*)& class_obj, sizeof(class_obj));
			delete dummy;
		}

	}
	else
		cout << "error in cow file" << endl;
	
}
void Animal_details::fill_details()
{
	//

}

void Animal_details::write_details()
{
	ofstream out;
	out.open("Cow.bin", ios::binary);
	if (out.is_open())
	{
		cout << "cow file opened to write" << endl;
		Cow dummy();

		for (auto i = my_cow.begin(); i != my_cow.end(); ++i)
			out.write((char*)& *i, sizeof(Cow));

		//file_obj.write((char*)& class_obj, sizeof(class_obj));
		out.close();
	}
	else
		cout << "error in cow file" << endl;

	//read eg--this is only a testing code for read after writting the file with the new animal
	ifstream in;
	in.open("Cow.bin", ios::binary);
	if (in.is_open())
	{
		cout << "cow file opened to read" << endl;
		Cow dummy;
		for (auto i = my_cow.begin(); i != my_cow.end(); ++i)
		{
			in.read((char*)& dummy, sizeof(Cow));
			cout << "price: " << dummy.price << endl;
			cout << "token" << dummy.token << endl;
			//file_obj.write((char*)& class_obj, sizeof(class_obj));
		}
		
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
	this->write_details();
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











