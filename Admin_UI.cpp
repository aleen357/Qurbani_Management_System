#include "Admin_UI.h"
#include<iostream>
#include<fstream>
using namespace std;
int Admin_UI::number_salesman = 0;

Admin_UI::Admin_UI()
{
	//
}
Admin_UI::Admin_UI(char buff[20])
{
	number_salesman = 0;
	this->id = 0;//Id of admin will always be 0 of admin by default
	strcpy_s(password, 20, buff);
	this->fill_salesman_list();


}
void Admin_UI::fill_salesman_list()
{
	//STEP 1: Fill salesman list with salesman.bin
	ifstream fin;
	fin.open("Salesman.bin", ios::binary);
	if (fin.is_open())
	{
		//for cows
		Salesman* dummy;
		dummy = new Salesman;
		while (fin.read((char*) & *dummy, sizeof(Salesman)))//until we read full salesman file--we read obj and place in list
		{
			this->my_salesmen.push_back(*dummy);
			
			number_salesman = dummy->get_id();
			cout << number_salesman << endl;
			delete dummy;
			dummy = new Salesman;
		}
		fin.close();
	}
	else
		cout << "error in salesman file" << endl;
}

void Admin_UI::add_animal()
{
	My_Animals.add_animal();
}

void Admin_UI::view_details()
{
	My_Animals.view_details();
}

void Admin_UI::add_salesman()
{
	//assign new id to salesman \
	//assign password
	number_salesman++;
	cout << "Creating a new salesman" << endl;
	cout << "ID of new salesman is: " << number_salesman << endl;
	char buff[20];
	cout << "Enter Password of new salesman" << endl;
	cin >> buff;
	Salesman new_salesman(number_salesman, buff);
	my_salesmen.push_back(new_salesman);
	//write new salesman to file
	this->write_salesman();

}
void Admin_UI::write_salesman()//this function updates the salesman file with the new sales man
{
	//For Salesman
	char buff[20];
	ofstream out;
	out.open("Salesman.bin", ios::binary);
	if (out.is_open())
	{
		cout << "This is the new list of Salesman in the system:" << endl;
		Salesman dummy;

		for (auto i = my_salesmen.begin(); i != my_salesmen.end(); ++i)
		{
			strcpy_s(buff, 20, i->get_pass());
			/*out.write((char*) & *i, sizeof(Salesman));
			strcpy_s(buff, 20, i->get_pass());
			cout << i->get_id() << " " << buff<< endl;*/
			out << i->get_id() << " " << buff << endl;
		}
		out.close();
	}
	else
		cout << "error in salesmen file" << endl;
}





