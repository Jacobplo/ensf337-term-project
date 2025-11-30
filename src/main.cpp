// TODO Add headers to all files.

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "flight.h"

using namespace std;

int get_choice(int min, int max);

int main(void) {
  // Title.
  cout << "FMAS Version: 1.0" << endl
       << "Term Project - Flight Management Application System" << endl
       << "Produced by group#: 12" << endl
       << "Names: Jacob Plourde, Julio Izuogo, Unas Khalid" << endl << endl
       << "<<< Press Return to Continue >>>" << endl;
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



  // Main loop.
  while(1) {
    // Main menu.
    cout << "Please select one of the following options:" << endl
         << "\t1. Select a flight" << endl
         << "\t2. Display flight seat map" << endl
         << "\t3. Display passengers information" << endl
         << "\t4. Add a new passenger" << endl
         << "\t5. Remove an existing passenger" << endl
         << "\t6. Save data" << endl
         << "\t7. Quit" << endl;
    int choice = get_choice(1, 7);
  }  
  




  return 0;
}



int get_choice(int min, int max) {
  while(1) {
    string input;
    getline(cin, input);

    char *endptr;
    int choice = strtol(input.c_str(), &endptr, 10);
    if(*endptr) {
      cout << "Invalid input: Must enter a valid integer. Try again: ";
      continue;
    }

    if(choice < min || choice > max) {
      cout << "Invalid input: Must be between " << min << " and " << max << ". Try again: ";
      continue;
    }

    return choice;
  }
}
