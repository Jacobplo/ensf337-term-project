/*
 *  File Name: airline.cpp
 *  Assignment: Term Project
 *  Lecture Section: L01
 *  Completed by: Jacob Plourde
 *  Development Date: November 29, 2025
 */
#include "airline.h"

void Airline::addFlight(const string& id, int num_rows, int num_seats_per_row, const string& src, const string& dest) {
  flights.push_back(Flight(id, num_rows, num_seats_per_row, src, dest));
}

