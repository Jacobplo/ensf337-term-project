#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>
#include "seat.h"
#include "passenger.h"
#include "route.h"

using std::vector;

class Flight {
private:
  vector<vector<Seat>> seats;
  vector<Passenger> passengers;
  int number_of_rows;
  int number_of_seats_per_row;
  Route route;
  void populate_seats();
  void addPassenger(string& fname, string &lname, string& phone, int row_num, char seat_char);
};

#endif
