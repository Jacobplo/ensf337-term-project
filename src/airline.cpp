#include "airline.h"

void Airline::addFlight(string& id, int num_rows, int num_seats_per_row, string& src, string& dest) {
  flights.push_back(Flight(id, num_rows, num_seats_per_row, src, dest));
}
