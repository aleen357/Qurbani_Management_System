#include "Admin_UI.h"
#include<iostream>
#include<fstream>
using namespace std;
Admin_UI::Admin_UI()
{
	//
}
Admin_UI::Admin_UI(char buff[20])
{
	this->id = 0;//Id of admin will always be 0 of admin by default
	strcpy(password, buff);

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
	cin.getline(buff, 20);
	Salesman new_salesman(number_salesman, buff);
	My_Salesmen.push_back(new_salesman);
	//write new salesman to file

}
void Admin_UI::write_salesman()//this function updates the salesman file with the new sales man
{

}





