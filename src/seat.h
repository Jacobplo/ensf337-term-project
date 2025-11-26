#ifndef SEAT_H
#define SEAT_H

#include <cstdbool>

class Seat {
private:
  int row_number;
  char seat_character;
  bool occupied;
public:
  Seat(int row_num, char seat_char);
  int get_row_number() const { return row_number; };
  char get_seat_character() const { return seat_character; };
};

#endif
