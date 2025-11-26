#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include "seat.h"

using std::string;

class Passenger {
private:
  int id;
  string first_name;
  string last_name;
  string phone_number;
  Seat *seat;
public:
  Passenger(string& fname, string& lname, string& phone, Seat *seat);
  string& get_first_name() const { return first_name; };
  string& get_last_name() const { return last_name; };
  string& get_phone_number() const { return phone_number; };
};

#endif
