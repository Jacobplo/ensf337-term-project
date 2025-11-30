#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>
#include "seat.h"
#include "passenger.h"
#include "route.h"

using std::vector;

class Flight {
private:
  string id;
  vector<vector<Seat>> seats;
  vector<Passenger> passengers;
  int number_of_rows;
  int number_of_seats_per_row;
  Route route;
  void populate_seats_vector();
public:
  Flight() {};
  Flight(string& id, int num_rows, int num_seats_per_row, string& source, string& dest);
  void addPassenger(int id, string& fname, string &lname, string& phone, int row_num, char seat_char);
  void removePassenger(int id);
  void print_seat_map();
  int get_number_of_rows()const { return number_of_rows; };
  int get_number_of_seats_per_row()const { return number_of_seats_per_row; };
  string get_id()const { return id; };
  const vector<Passenger> *get_passengers()const { return &passengers; };
  const Route *get_route()const { return &route; };
};

#endif
