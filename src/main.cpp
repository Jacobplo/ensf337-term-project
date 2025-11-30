// TODO Add headers to all files.

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "flight.h"

using namespace std;

int main(void) {
  // Title.
  cout << "FMAS Version: 1.0" << endl
       << "Term Project - Flight Management Application System" << endl
       << "Produced by group#: 12" << endl
       << "Names: Jacob Plourde, Julio Izuogo, Unas Khalid" << endl << endl
       << "<<< Press Return to Continue >>>";
  cin.get();


  // Load data from files.
  ifstream input;

  // Flight data.
  vector<Flight> flights;
  input.open("flights.txt");
  {
    string id, src, dest;
    int num_rows, num_seats_per_row;
    while(input.peek() != EOF) {
      input >> id >> src >> dest >> num_rows >> num_seats_per_row;
      flights.push_back(Flight(id, num_rows, num_seats_per_row, src, dest));
    }
  } 
  input.close();

  // Passenger data;
  input.open("passengers.txt");
  {
    string flight_id, fname, lname, phone;
    int row_num = 0, seat_char, id;
    while(input.peek() != EOF) {
      input >> flight_id >> fname >> lname >> phone;

      // Get row number without character.
      input.get();
      do {
        char c = input.get();
        row_num = 10 * row_num + (c - '0');
      } while(input.peek() >= '0' && input.peek() <= '9');
      
      input >> seat_char >> id;

      for(int i = 0; i < flights.size(); i++) {
        if(flights.at(i).get_id() == flight_id) {
          flights.at(i).addPassenger(id, fname, lname, phone, row_num, seat_char);
        }
      }
    }
  }
  input.close();
  
  




  return 0;
}
