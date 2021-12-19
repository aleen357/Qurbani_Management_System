
#include "Booking_main.h"

#include <iostream>
#include<fstream>

using namespace std;
int Booking_main::total_bookings=0;
 int Booking_main::curr_hours = 5;
 int Booking_main::curr_mins = 30;

 void Booking_main::TimeSet()
 {
	 if (curr_mins + 30 >= 60)
	 {
		 curr_hours = curr_hours++;
		 curr_mins = curr_mins + 30 - 60;
	 }
	 else if (curr_mins + 30 < 60)
	 {
		 curr_mins = curr_mins + 30;
	 }
 }

 void Booking_main::TimeReset()
 {
	 curr_hours = 5;
	 curr_mins = 30;
 }

 void Booking_main::Set_customer(Customer &obj)
 {
	 char N[30], id[20], c[15];
	 int x = 0;
	
	 cout << "Enter name: ";
	 cin.ignore();
	 cin.getline(N, 30);
	 obj.SetName(N);

	 cout << "Enter CNIC(without hyphen): ";
	 cin.ignore();
	 
	 while (x != 2)
	 {
		 cin.getline(id, 20);
		 for (int i = 0; i < strlen(id) && x != 1; i++)
		 {
			 x = 2;
			 if (id[i] < 48 || id[i] > 57)
			 {
				 cout << "wrong input. enter phone no again\n";
				 x = 1;
				 break;
			 }

		 }
		 if (x != 2)
		 {
			x = 0;
		 }
			
	 }
	 obj.SetCNIC(id);

	 cout << "Enter Contact No.(without hyphen): ";
	 cin.ignore();
	 x = 0;
	 while (x!=2)
	 {
		 cin.getline(c, 15);
		 for (int i = 0; i < strlen(c) && x!=1; i++)
		 {
			 x = 2;
			 if (c[i] < 48 || c[i] > 57 )
			 {
				 cout << "wrong input. enter phone no again\n";
				 x = 1;
				 break;
			 }
					 
		 }
		 if(x!=2)
			x = 0;
	 }
		 obj.SetContact(c);
 }

 void Booking_main::SetBookings(Booking &obj)
 {
	 total_bookings++;
	 
	 TimeSet();
	 obj.Shour = curr_hours;
	 obj.Smins = curr_mins;
	 obj.Ehour = curr_hours + 3;
	 obj.Emins = curr_mins;

	 Set_customer(obj.buyer);

	 if (total_bookings < Bookings_per_day[0])
	 {
		 obj.Day_to_get_meat = 1;
	 }
	 else if (total_bookings < Bookings_per_day[0] + Bookings_per_day[1])
	 {
		 if (total_bookings == Bookings_per_day[0] + 1)
			 TimeReset();
		 obj.Day_to_get_meat = 2;

	 }
	 else if (total_bookings < Bookings_per_day[0] + Bookings_per_day[1] + Bookings_per_day[2])
	 {
		 if (total_bookings == Bookings_per_day[1] + 1)
			 TimeReset();
		 obj.Day_to_get_meat = 3;
	 }
 }

 bool Booking_main::Check_valid_order(int tok, int share, Animal_details &obj)		//check if token and parts are valid and sets the parts of that animal
 {
	 int PartRem = 0;
	 for (auto i = obj.my_cow.begin(); i != obj.my_cow.end(); ++i)
	 {
		 if (i->token == tok && i->status == false)
		 {
			 cout << "The animal is a Cow\n";
			 cout << "price: " << i->price << endl;
			 cout << "token: " << i->token << endl << endl;

			 PartRem = i->Get_parts_remaining();
			 if (share <= PartRem)
			 {
				 i->Set_parts(share, 1);
				 obj.write_details();
				 return true;
			 }
			 else
			 {
				 cout << "Not enough parts remain of this cow\n";

				 return false;
			 }
		 } 
	 }
	 for (auto i = obj.my_goat.begin(); i != obj.my_goat.end(); ++i)
	 {
		 if (i->token == tok && i->status == false)
		 {
			 cout << "The animal is a Goat\n";
			 cout << "price: " << i->price << endl;
			 cout << "token: " << i->token << endl << endl;
			 i->status = true;
			 i->Set_part_of_goat(1);
			 obj.write_details();
			 return true;
		 }
	 }
	 
	 return false;
 }

 


Booking_main::Booking_main()
{
	int x=0;
	ifstream fin;
	fin.open("BookingPerDay.txt");
	if (!fin) 
	{
		cout << "Enter the amount of booking we are going to execute on 1st day(must be less than 24)\n";
		cin >> Bookings_per_day[0];
		while (Bookings_per_day[0]<0 || Bookings_per_day[0]>24)
		{
			cout << "Enter the right amount of bookings per day\n";
			cin >> Bookings_per_day[0];
		}

		cout << "Enter the amount of booking we are going to execute on 2nd day(must be less than 24)";
		cin >> Bookings_per_day[1]; 
		while (Bookings_per_day[1] < 0 || Bookings_per_day[1]>24)
		{
			cout << "Enter the right amount of bookings per day\n";
			cin >> Bookings_per_day[1];
		}

		cout << "Enter the amount of booking we are going to execute on 3rd day(must be less than 24)";
		cin >> Bookings_per_day[2];
		while (Bookings_per_day[2] < 0 || Bookings_per_day[2]>24)
		{
			cout << "Enter the right amount of bookings per day\n";
			cin >> Bookings_per_day[2];
		}

		//writing this all on file
		ofstream fout;
		fout.open("BookingPerDay.txt");
		if (fout.is_open())
		{
			fout << Bookings_per_day[0] << endl;
			fout << Bookings_per_day[1] << endl;
			fout << Bookings_per_day[2] << endl;
		}
	}
	else
	{
		fin >> Bookings_per_day[0];
		cout << "No. of bookings on 1st Day: " << Bookings_per_day[0]<<endl;
		fin >> Bookings_per_day[1];
		cout << "No. of bookings on 2nd Day: " << Bookings_per_day[1] << endl;
		fin >> Bookings_per_day[2];
		cout << "No. of bookings on 3rd Day: " << Bookings_per_day[2] << endl;
		fin.close();
	}
}

void Booking_main::add_booking(Animal_details &obj)
{
	int option=0, total = 0, turn = 0;
	bool Gotta_get_price = false;
	Booking My_book;
	while (option != -1)
	{
		int x, y = 0, z = 0;
		cout << "Enter the token number of animal";
		cin >> x;
		cout << "Is it a goat or cow? \nPress 1 for cow and 2 for goat";
		cin >> y;
		
		if (y == 1 )
		{
			cout << "Enter the no. of parts of animal";
			cin >> z;
			if (Check_valid_order(x, z, obj) == true)
			{
				if (turn == 0)
				{
					SetBookings(My_book);
					turn++;
				}
				My_book.insert_an_animal(x, z);
				Gotta_get_price = true;
			}
			else
				cout << "Couldn't book this cow\n";
		}
		else if (y == 2)
		{
			if (Check_valid_order(x, 1, obj) == true)
			{
				if (turn == 0)
				{
					SetBookings(My_book);
					turn++;
				}
				My_book.insert_an_animal(x, z);
				Gotta_get_price = true;
			}
			else
				cout << "Couldn't book this goat\n";
		}
		else
		{
			cout << "Wrong input wapis ja\n";
		}
		cout << "Do you want to add another animal?\nPress 1 for yes and -1 for no";
		cin >> option;
	}
	if (Gotta_get_price)
	{
		total = My_book.calc_total_price(obj);
		My_book.SetPrice(total);
		list_of_Booking.push_back(My_book);
	}
	cout << "Your Total is: " << total;
	

}

void Booking_main::view_booking(int x)
{

}

void Booking_main::fill_bookings()
{

}

void Booking_main::write_bookings()
{
	ofstream out;
	out.open("Booking.bin", ios::binary);
	if (out.is_open())
	{
	
	}

}

void Booking_main::view_booking_of_a_customer(char (&a)[20])
{
	
}