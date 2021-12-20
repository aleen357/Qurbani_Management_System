
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
	 obj.booking_id = total_bookings;
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
	fill_bookings();
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
			z = 1;
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
		write_bookings();
	}
	cout << "Your Total is: " << total;
	

}

void Booking_main::view_booking(int x)//view booking with an id
{
	Execute_Bookings(x);
	for (auto i = list_of_Booking.begin(); i != list_of_Booking.end(); ++i)
	{
		if (i->booking_id == x)
		{
			//found a match
			i->print_booking();
			break;
		}
		
	}
}

void Booking_main::fill_bookings()
{
	//this function will be called for exportinig file info of bookings to program
	Booking* dummy;
	int x;
	char buff_name[30];
	char buff_cnic[20];
	char buff_phone[15];
	int token = 0;
	int price = 0;
	char nl = ' ';//nl=newline or eof
	int start = 1;
	int total_book = 0;
	ifstream fin;
	fin.open("Booking.txt");
	if (fin.is_open())
	{
		//bookingid day_to_get_meat shour ehour smin emin name/ cnic/ contact/ token price token price/" "\n
		fin >> x;
		total_book = x;
		while (start!=total_book+1)
		{
			
			nl = ' ';
			dummy = new Booking;
			fin >> x;
			dummy[0].booking_id = x;

			fin >> x;
			dummy[0].status = x;

			fin >> x;
			dummy[0].Day_to_get_meat = x;

			fin >> x;
			dummy[0].Shour = x;

			fin >> x;
			dummy[0].Ehour = x;

			fin >> x;
			dummy[0].Smins = x;

			fin >> x;
			dummy[0].Emins = x;

			fin >> x;
			dummy[0].total_price = x;

			fin.getline(buff_name, 30, '/');

			dummy[0].buyer.SetName(buff_name);

			fin.getline(buff_cnic, 20, '/');
			dummy[0].buyer.SetCNIC(buff_cnic);

			fin.getline(buff_phone, 15, '/');
			dummy[0].buyer.SetContact(buff_phone);
			while (nl != '/')
			{
				fin >> x;
				token = x;

				fin >> x;
				price = x;

				dummy->insert_an_animal(token, price);

				fin >> nl;
			}

			/*while (nl != '/')
			{
				x = (int)nl;
				token = x-48;

				fin >> x;
				price = x;

				dummy->insert_an_animal(token, price);

				fin >> nl;
			}*/

			total_bookings = dummy->booking_id;
			curr_hours = dummy->Shour;
			curr_mins = dummy->Smins;
			//fin >> nl;//fins for endl
			//fin >> nl;//fins for eof case
			list_of_Booking.push_back(dummy[0]);
			nl = ' ';
			delete dummy;
			start++;
		
		}
	}
	else
		cout << "Booking.txt is empty" << endl;


}

void Booking_main::write_bookings()
{
	int count = 0;
	int size=0;
	int x;
	ofstream out;
	out.open("Booking.txt");
	if (out.is_open())
	{
		out << total_bookings << endl;
		//bookingid status day_to_get_meat shour ehour smin emin total_price name/ cnic contact token price token price/
		for (auto i = list_of_Booking.begin(); i != list_of_Booking.end(); ++i)
		{
			size = i->detail_of_animal.size();

			out << i->booking_id << " " <<i->status<<" "<< i->Day_to_get_meat << " " << i->Shour << " " << i->Ehour << " " << i->Smins << " " << i->Emins<<" "<<i->total_price<<" "<< i->buyer.getName() << "/ " << i->buyer.getCNIC() << "/ " << i->buyer.getContact() << "/";
			for (auto j = i->detail_of_animal.begin(); j != i->detail_of_animal.end(); ++j)
			{
				if (count<size-1)
					out << " " << j->token << " " << j->parts << " + ";
				else
					out << " " << j->token << " " << j->parts;
				count++;
			}
			if(i!=list_of_Booking.end())
			out << "/\n";
			else
			out<<"/";
		}

		cout << "booking recoreded" << endl;
	}
	else
		cout << "error in booking" << endl;

}

void Booking_main::view_booking_of_a_customer(char (&a)[20])
{
	
}



void Booking_main::Execute_Bookings(int ID)
{
	time_t rawtime;
	struct tm* timeinfo;

	/* get current timeinfo and modify it to the user's choice */
	time(&rawtime);
	timeinfo = gmtime(&rawtime);

	/*time_t ttime = time(0);
	struct tm* local_time = localtime(&ttime);*/
	int year =1900+timeinfo->tm_year;
	int month = 1+timeinfo->tm_mon;
	int day = timeinfo->tm_mday;
	bool flag = false;
	bool day1 = false;
	bool day2 = false;
	bool day3 = false;
	bool time_has_come = false;
	bool time_has_end = false;
	int hour = 5+timeinfo->tm_hour;
	int mins = timeinfo->tm_min;

	for (auto i = list_of_Booking.begin(); i != list_of_Booking.end(); ++i)
	{
		if (i->booking_id == ID)
		{
			//found a match
			//check if day 1 matches 
			//i->print_booking();
			if (i->status == 2)
			{
				cout << "you have already collected" << endl;
				return;
			}
			if (i->status == 3)
			{
				cout << "your meat has been distributed....." << endl;
				return;
			}
			ifstream fout;
			fout.open("Eid.txt");
			int x = 0;
			int count = 1, date2, year2, month2;
			if (fout.is_open())
			{
				while (count <= 3)
				{

					fout >> date2;


					fout >> month2;


					fout >> year2;

					if (date2 == day && month2 == month && year2 == year && count == 1)
					{
						day1 = true;
						break;
					}

					if (date2 == day && month2 == month && year2 == year && count == 2)
					{
						day2 = true;
						break;
					}

					if (date2 == day && month2 == month && year2 == year && count == 3)
					{
						day3 = true;
						break;
					}
					count++;
				}

				if (i->Shour < hour && hour < i->Ehour)
				{
					time_has_come = true;
				}
				else if (i->Shour == hour && i->Smins <= mins)
				{
					time_has_come = true;
				}
				else if (i->Ehour == hour && i->Emins > mins)
				{
					time_has_come = true;
				}
				// ending conndition
				if (i->Ehour == hour && i->Emins < mins)
				{
					time_has_end = true;
				}
				else if (hour > i->Ehour)
				{
					time_has_end = true;
				}

				if (day1 == true && time_has_come == true)
				{
					//we change status to slaughtered
					i->status = 1;

				}
				if (day2 == true && time_has_come == true)
				{
					//we change status to slaughtered
					i->status = 1;

				}
				if (day3 == true && time_has_come == true)
				{
					//we change status to slaughtered
					i->status = 1;

				}

				if (day1 == true && time_has_end == true && i->status != 2)
				{
					//we change status to slaughtered
					i->status = 3;

				}
				if (day2 == true && time_has_end == true && i->status != 2)
				{
					//we change status to slaughtered
					i->status = 3;

				}
				if (day3 == true && time_has_end == true && i->status != 2)
				{
					//we change status to slaughtered
					i->status = 3;

				}
			}
			else
				cout << "error in eid file" << endl;
			this->write_bookings();
			break;
		}

	}



}

void Booking_main::Execute_All_Bookings()
{
	for (auto i = list_of_Booking.begin(); i != list_of_Booking.end(); ++i)
	{
		Execute_Bookings(i->booking_id);
	}
}

void Booking_main::Customer_has_come(int B_id)
{
	for (auto i = list_of_Booking.begin(); i != list_of_Booking.end(); ++i)
	{
		Execute_Bookings(B_id);
		if (i->booking_id == B_id)
		{
			if (i->status == 1)
			{
				cout << "Thankyou Heres your meat" << endl;
				i->status = 2;
			}
			if (i->status == 3)
			{
				cout << "Your meat has been distributed" << endl;
			}
		}
	}
}