#include "passenger.h"

Passenger::Passenger(int id, string& fname, string& lname, string& phone, Seat *seat): id(id), first_name(fname), last_name(lname), phone_number(phone), seat(seat) {}

