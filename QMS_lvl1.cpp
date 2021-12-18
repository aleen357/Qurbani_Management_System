// QMS_lvl1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Admin_UI.h"
#include <fstream>

#include<stdlib.h>

void AdminMenu()
{
	cout << "Welcome Admin" << endl;
	cout << "1. Add animal" << endl;
	cout << "2. Add bookin/make schedule" << endl;
	cout << "3. View all animals" << endl;
	cout << "4. View Available animal" << endl;
	cout << "5. View a Specific Animal's Details" << endl;
	cout << "6. View booking/ Schedule" << endl;
	cout << "7. View reservation of a customer--(requires booking id)" << endl;
	cout << "8. Quit" << endl;
}

void Admin_function(char buff[20])
{
	/*Add animal
	Add salesman
	Make a schedule


	(Salesman's use cases)
	View the list of animals
	View the list of available animals
	View an animal's detail
	View schedule
	View all the reservations of a customer(show the total amount)*/
	Admin_UI Admin;
	AdminMenu();
	int x, id=0;
	cin >> x;
	while (x != 8)
	{
		switch (x)
		{
		case 1:
			Admin.add_animal();
			break;
		
		case 2:
			Admin.add_booking();
			break;
		case 3:
			Admin.view_details();
			break;
		
		case 4:
			Admin.view_available_animals();
			break;
		case 5:
			cout << "Enter the token Id of that animal\n";
			cin >> id;
			Admin.view_an_animal(id);
			break;
		case 6:
			Admin.view_booking();
			break;
		case 7:
			cout << "Enter the booking Id of that customer\n";
			cin >> id;
			Admin.view_reservations_of_customer(id);
			break;

		case 8:
			cout << "Quitting";
			break;

		default:
			break;
		}
		system("pause");
		system("CLS");
		AdminMenu();
		cin >> x;
	}
}

void Slaughter_House_Main()
{
	cout << "Signed in as Admin " << endl;
	
	char buff[20];
	char buff_text[20];
	
		cout << "Enter Password" << endl;
		cin >> buff;
		ifstream fin;
		fin.open("AdminPass.txt");
		if (fin.is_open())
		{
			fin.getline(buff_text, 20);
			int length = strlen(buff_text);
			buff_text[length] = '\0';
			cout << buff_text << endl;
			cout << buff << endl;
			if (strcmp(buff, buff_text) == 0)
			{
				Admin_function(buff_text);
			}
			else
				cout << "Wrong Password\n";
		}
		else
			cout << "admin pass not opened" << endl;
	return;
}


int main()
{
	cout << "						Welcome to the Qurbani Masjid\n";
	Slaughter_House_Main();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
