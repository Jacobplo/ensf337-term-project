#include "flight.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

Flight::Flight(string& id, int num_rows, int num_seats_per_row, string& source, string& dest): id(id), number_of_rows(num_rows), number_of_seats_per_row(num_seats_per_row) {
  route = Route(source, dest);
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

void Flight::print_seat_map() {
  cout << "Aircraft Seat Map for Flight " << id << endl;
  // Seat char row.
  cout << "     ";
  for(int i = 0; i < seats.at(0).size(); i++) {
    cout << i + 'A' << setw(4);
  }
  cout << "\n  +";
  for(int i = 0; i < seats.at(0).size(); i++) {
    cout << "---+";
  }
  cout << endl;

  // Fill table.
  for(int row = 0; row < seats.size() * 2; row++) {
    if(row % 2 == 0) {
      cout << row / 2 << " |";
    }
    else {
      cout << "  +";
    }

    for(int col = 0; col < seats.at(row / 2).size(); col++) {
      if(row % 2 == 0) {
        cout << ' ' << (seats.at(row / 2).at(col).get_occupied() ? 'X' : ' ') << " |";  
      }
      else {
        cout << "---+"; 
      }
    }
    cout << endl;
  }
}
