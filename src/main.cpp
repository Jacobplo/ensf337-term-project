// TODO Add headers to all files.

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "airline.h"
#include "flight.h"
#include <cassert>

using namespace std;

int get_choice(int min, int max);
int get_num_lines(const string& file);

int main(void) {
  // Title.
  cout << "FMAS Version: 1.0" << endl
       << "Term Project - Flight Management Application System" << endl
       << "Produced by group#: 12" << endl
       << "Names: Jacob Plourde, Julia Izuogo, Unas Khalid" << endl << endl
       << "<<< Press Return to Continue >>>" << endl;
  cin.get();

  // Load data from files.
  ifstream input;

  // Flight data.
  Airline west_jet("WestJet");
  input.open("flights.txt");
  assert(!input.fail());
  {
    // Goes through the file line by line, adding each flight to a vector of flights.
    string id, src, dest;
    int num_rows, num_seats_per_row;
    for(int line = 0; line < get_num_lines("flights.txt"); line++) {
      input >> id >> src >> dest >> num_rows >> num_seats_per_row;
      west_jet.addFlight(id, num_rows, num_seats_per_row, src, dest);
    }
  } 
  input.close();

  // Passenger data;
  input.open("passengers.txt");
  assert(!input.fail());
  {
    string flight_id, fname, lname, phone;
    int row_num, seat_char, id;
    for(int line = 0; line < get_num_lines("passengers.txt"); line++) {
      row_num = 0;

      input >> flight_id >> fname >> lname >> phone;

      // Get row number without character because there is no whitespace between the number and character.
      input.get();
      do {
        char c = input.get();
        row_num = 10 * row_num + (c - '0');
      } while(input.peek() >= '0' && input.peek() <= '9');
     
      seat_char = input.get();
      input >> id;

      for(size_t i = 0; i < west_jet.get_flights()->size(); i++) {
        if(west_jet.get_flights()->at(i).get_id() == flight_id) {
          west_jet.get_flights()->at(i).addPassenger(id, fname, lname, phone, row_num, seat_char);
        }
      }
    }
  }
  input.close();



  int selected_flight = 0;

  // Main loop.
  while(1) {
    cout << endl;
    // Main menu.
    cout << "Please select one of the following options:" << endl
         << "\t1. Select a flight" << endl
         << "\t2. Display flight seat map" << endl
         << "\t3. Display passenger's information" << endl
         << "\t4. Add a new passenger" << endl
         << "\t5. Remove an existing passenger" << endl
         << "\t6. Save data" << endl
         << "\t7. Quit" << endl;
    cout << "Enter your choice (1, 2, 3, 4, 5, 6, or 7): ";
    int choice = get_choice(1, 7);
    cout << endl;

    switch(choice) {
      // Case for selecting a flight.
      case 1:
        // List flights.
        cout << "Here is the list of available flights. Please select one:" << endl;
        size_t i;
        for(i = 0; i < west_jet.get_flights()->size(); i++) {
          Flight *flight = &west_jet.get_flights()->at(i);
          cout << "\t" << i + 1 << ". " << flight->get_id() << setw(10) 
                                        << flight->get_route()->get_source() << setw(10) 
                                        << flight->get_route()->get_destination() << setw(10)
                                        << flight->get_number_of_rows() << setw(6)
                                        << flight->get_number_of_seats_per_row() << endl;
        }
        cout << "Enter your choice: ";
        selected_flight = get_choice(1, i);
        break;
     
      // Case for displaying the selecting flight's seat map.
      case 2:
        if(!selected_flight) {
          cout << "Must select flight first" << endl;
          break;
        }

        west_jet.get_flights()->at(selected_flight - 1).print_seat_map();
        break;

      // Case for displaying a passenger's information.
      case 3:
        break;

      // Case for adding a new passenger.
      case 4:
        break;

      // Case for removing an existing passenger.
      case 5:
        break;

      // Case for saving data to files.
      case 6:
        break;

      case 7:
        // Case for quitting.
        exit(1);
        break;
    }
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

int get_num_lines(const string& file) {
  int count = 0;
  ifstream input(file);
  assert(!input.fail());
  char chr;
  while((chr = input.get()) != EOF) {
    if(chr == '\n') count++;
  }

  return count;
}
