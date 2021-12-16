
#include "Booking.h"
int Booking::booking_id_count = 0;

Booking::Booking()
{
	booking_id = booking_id_count + 1;
	booking_id_count++;
	Day_to_get_meat = 0;

}