/*
 *  File Name: airline.h
 *  Assignment: Term Project
 *  Lecture Section: L01
 *  Completed by: Jacob Plourde
 *  Development Date: November 29, 2025
 */
#ifndef AIRLINE_H
#define AIRLINE_H

#include "flight.h"

class Airline {
private:
  string name;
  vector<Flight> flights;
public:
  Airline(const string& name): name(name) { };
  void addFlight(string& id, int num_rows, int num_seats_per_row, string& src, string& dest);
  vector<Flight> *get_flights() { return &flights; };
};

#endif
