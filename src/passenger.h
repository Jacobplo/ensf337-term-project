/*
 *  File Name: passenger.h
 *  Assignment: Term Project
 *  Lecture Section: L01
 *  Completed by: Jacob Plourde
 *  Development Date: November 27, 2025
 */
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
  Passenger(int id, string& fname, string& lname, string& phone, Seat *seat);
  int get_id() const { return id; };
  string get_first_name() const { return first_name; };
  void set_first_name(string& fname) { first_name = fname; };
  string get_last_name() const { return last_name; };
  void set_last_name(string& lname) { last_name = lname; };
  string get_phone_number() const { return phone_number; };
  void set_phone_number(string& phone) { phone_number = phone; };
  Seat *get_seat()const { return seat; };
};

#endif
