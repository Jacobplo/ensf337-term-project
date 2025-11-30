#include "flight.h"

Flight::Flight(int id, int num_rows, int num_seats_per_row, Route& route): id(id), number_of_rows(num_rows), number_of_seats_per_row(num_seats_per_row), {
  this->route = new Route(route.get_source(), route.get_destination());
  populate_seats_vector();
}

void Flight::populate_seats_vector() {
  seats.resize(number_of_rows);
  for(int i = 0; i < number_of_seats_per_row; i++) {
    seats.at(i).resize(number_of_seats_per_row);
  }

  for(int i = 0; i < number_of_rows; i++) {
    for(int j = 0; j < number_of_seats_per_row; j++) {
      seats.at(i).at(j).set_row_number(i);
      seats.at(i).at(j).set_seat_character('A' + j);
    }
  }
}

void Flight::addPassenger(int id, string& fname, string& lname, string& phone, int row_num, char seat_char) {
  passengers.push_back(Passenger(id, fname, lname, phone, &seats.at(row_num).at(seat_char - 'A'))); 
  seats.at(row_num).at(seat_char - 'A').set_occupied(true);
}

void Flight::removePassenger(int id) {
  for(int i = 0; i < passengers.size(); i++) {
    Passenger *cur = &passengers.at(i);
    if(cur->get_id() == id) {
      cur->get_seat()->set_occupied(false);
    }
  }
}
