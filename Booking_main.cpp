
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

	 cout << "Enter name";
	 cin.getline(N, 30);
	 obj.SetName(N);

	 cout << "Enter CNIC";
	 cin.getline(id, 20);
	 obj.SetCNIC(id);

	 cout << "Enter Contact No.";
	 cin.getline(c, 15);
	 obj.SetContact(c);
 }

Booking_main::Booking_main()
{
	int x;
	ifstream fin;
	fin.open("BookingPerDay.txt");
	if (!fin) 
	{
		cout << "Enter the amount of booking we are going to execute on 1st day(must be less than 24)";
		cin >> Bookings_per_day[0];
		cout << "Enter the amount of booking we are going to execute on 2nd day(must be less than 24)";
		cin >> Bookings_per_day[1]; 
		cout << "Enter the amount of booking we are going to execute on 3rd day(must be less than 24)";
		cin >> Bookings_per_day[2];

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
		cout << "No. of bookings on 1st Day" << Bookings_per_day[0]<<endl;
		fin >> Bookings_per_day[1];
		cout << "No. of bookings on 2nd Day" << Bookings_per_day[1] << endl;
		fin >> Bookings_per_day[2];
		cout << "No. of bookings on 3rd Day" << Bookings_per_day[2] << endl;
		fin.close();
	}
}

void Booking_main::add_booking(Animal_details &obj)
{
	int x, y=0, z=0;
	cout << "Enter the token number of animal";
	cin >> x;
	for (auto i = obj.my_cow.begin(); i != obj.my_cow.end(); ++i)
	{
		if (i->token == x && i->status==false)
		{
			cout << "The animal is a Cow\n";
			cout << "price: " << i->price << endl;
			cout << "token: " << i->token << endl << endl;

			y = i->Get_parts_remaining();
			
			cout << "Enter the no. of parts of animal";
			cin >> z;
			if (z <= y)
			{
				i->Set_parts(z, 1);
				total_bookings++;
				Booking My_book;
				TimeSet();
				My_book.Shour = curr_hours;
				My_book.Smins = curr_mins;
				My_book.Ehour = curr_hours + 3;
				My_book.Emins = curr_mins;
				
				Set_customer(My_book.buyer);

				if(total_bookings< Bookings_per_day[0])
				{
					My_book.Day_to_get_meat=1;
				}
				else if (total_bookings < Bookings_per_day[0] + Bookings_per_day[1] )
				{
					if (total_bookings == Bookings_per_day[0] + 1)
						TimeReset();
					My_book.Day_to_get_meat = 2;

				}
				else if (total_bookings < Bookings_per_day[0] + Bookings_per_day[1] + Bookings_per_day[2])
				{
					if (total_bookings == Bookings_per_day[1] + 1)
						TimeReset();
					My_book.Day_to_get_meat = 3;
				}	
			}
			else
			{
				cout << "Not enough parts remain of this cow\n";
				return;
			}
		}
	}
	for (auto i = obj.my_goat.begin(); i != obj.my_goat.end(); ++i)
	{
		if (i->token == x && i->status == false)
		{
			cout << "The animal is a Goat\n";
			cout << "price: " << i->price << endl;
			cout << "token: " << i->token << endl << endl;
			i->status = true;
			i->Set_part_of_goat(1);

		}
	}
}

void Booking_main::view_booking()
{

}

void Booking_main::fill_bookings()
{

}

void Booking_main::write_bookings()
{

}

void Booking_main::view_booking_of_a_customer(int a)
{

}