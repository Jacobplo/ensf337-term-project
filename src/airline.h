#ifndef AIRLINE_H
#define AIRLINE_H

#include "flight.h"

class Airline {
private:
  string name;
  vector<Flight> flights;
public:
  Airline(const string& name): name(name) {};
  void addFlight(string& id, int num_rows, int num_seats_per_row, string& src, string& dest);
  vector<Flight> *get_flights() { return &flights; };
};

#endif
