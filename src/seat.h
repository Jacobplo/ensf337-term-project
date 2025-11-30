/*
 *  File Name: seat.h
 *  Assignment: Term Project
 *  Lecture Section: L01
 *  Completed by: Jacob Plourde
 *  Development Date: November 29, 2025
 */
#ifndef SEAT_H
#define SEAT_H

#include <cstdbool>

class Seat {
private:
  int row_number;
  char seat_character;
  bool occupied;
public:
  Seat() {};
  Seat(int row_num, char seat_char);
  int get_row_number() const { return row_number; };
  void set_row_number(int num) { row_number = num; };
  char get_seat_character() const { return seat_character; };
  void set_seat_character(char chr) { seat_character = chr; };
  bool get_occupied()const { return occupied; };
  void set_occupied(bool state) { occupied = state; };
};

#endif
