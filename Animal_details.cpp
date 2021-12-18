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
	fill_details();
	
}
void Animal_details::fill_details()
{
	//STEP 1: Fill Cow list with cow.bin
	int  token1 = 0, token2 = 0;

	ifstream fin;
	fin.open("Cow.bin", ios::binary);
	if (fin.is_open())
	{
		//for cows
		Cow *dummy;
		dummy = new Cow;
		while (fin.read((char*)& *dummy, sizeof(Cow)))//until we read full cow file--we read obj and place in list
		{
			this->my_cow.push_back(*dummy);
			token1 = dummy->token;
			delete dummy;
			dummy = new Cow;
		}
		fin.close();
	}
	else
		cout << "error in cow file" << endl;


	ifstream fins;
	fins.open("Goat.bin", ios::binary);
	if (fins.is_open())
	{
		//for goats
		Goat *dummy2;
		dummy2 = new Goat;
		while (fins.read((char*)& *dummy2, sizeof(Goat)))
		{
			this->my_goat.push_back(*dummy2);
			token2 = dummy2->token;
			delete dummy2;
			dummy2 = new Goat;
		}

		fins.close();
	}
	else
		cout << "error in goat file" << endl;

	if (token1 > token2)
		curr_token = token1;
	else
		curr_token = token2;

}

void Animal_details::view_details()
{
	//STEP 1: Fill Cow list with cow.bin
	
		cout << "We have these Cows here in our farm:" << endl;
		
		for (auto i = my_cow.begin(); i != my_cow.end(); ++i)
		{
			cout << "price: " << i->price << endl;
			cout << "token: " << i->token << endl << endl;
		}

		cout << "\nWe have the Goats here in our farm:" << endl;

		for (auto i = my_goat.begin(); i != my_goat.end(); ++i)
		{
			cout << "price: " << i->price << endl;
			cout << "token: " << i->token << endl << endl;
		}
}


void Animal_details::write_details()
{
	//For Cows
	ofstream out;
	out.open("Cow.bin", ios::binary);
	if (out.is_open())
	{
		cout << "This is the new list of cows in the farm:" << endl;
		Cow dummy;

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
		//cout << "cow file opened to read" << endl;
		Cow dummy;
		for (auto i = my_cow.begin(); i != my_cow.end(); ++i)
		{
			in.read((char*)& dummy, sizeof(Cow));
			cout << "price: " << dummy.price << endl;
			cout << "token: " << dummy.token << endl<< endl;
			//file_obj.write((char*)& class_obj, sizeof(class_obj));
		}
		in.close();
	}
	else
		cout << "error in cow file" << endl;

	//---------------------------------------------------------------- 
	//For Goats

	ofstream outs;
	outs.open("Goat.bin", ios::binary);
	if (outs.is_open())
	{
		cout << "This is the new list of goats in the farm:" << endl;
		Goat dummy();

		for (auto i = my_goat.begin(); i != my_goat.end(); ++i)
			outs.write((char*)& *i, sizeof(Goat));

		//file_obj.write((char*)& class_obj, sizeof(class_obj));
		outs.close();
	}
	else
		cout << "error in goat file" << endl;
	
	//Reading
	
	ifstream ins;
	ins.open("Goat.bin", ios::binary);
	if (ins.is_open())
	{
		//cout << "goat file opened to read" << endl;
		Goat dummy;
		for (auto i = my_goat.begin(); i != my_goat.end(); ++i)
		{
			ins.read((char*)& dummy, sizeof(Goat));
			cout << "price: " << dummy.price << endl;
			cout << "token: " << dummy.token << endl<< endl;
			//file_obj.write((char*)& class_obj, sizeof(class_obj));
		}
		ins.close();
	}
	else
		cout << "error in goat file" << endl;

}

bool Animal_details::add_animal()
{
	cout << "\nSelect type of animal" << endl;
	cout << "1.cow" << endl;
	cout << "2.goat" << endl;
	int x = 0;
	cin >> x;
	if (x == 1)
	{
		add_cow();
		
	}
	else if (x==2)
	{
		add_goat();
	}
	else
	{
		cout << "\nwrong input. Come again\n";
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
	this->write_details();
	return true;
}











