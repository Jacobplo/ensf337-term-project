/*
 *  File Name: flight.h
 *  Assignment: Term Project
 *  Lecture Section: L01
 *  Completed by: Jacob Plourde
 *  Development Date: November 29, 2025
 */
#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>
#include <string>
#include "seat.h"
#include "passenger.h"
#include "route.h"

using std::vector;
using std::string;

class Flight {
private:
    string id;
    vector<vector<Seat>> seats;
    vector<Passenger> passengers;
    int number_of_rows;
    int number_of_seats_per_row;
    Route route;

    void populate_seats_vector();

public:
    Flight() : number_of_rows(0), number_of_seats_per_row(0) {}
    Flight(const string& id, int num_rows, int num_seats_per_row, const string& source, const string& dest);

    void addPassenger(int id, string& fname, string &lname, string& phone, int row_num, char seat_char);
    void removePassenger(int id);
    void print_seat_map();

    int get_number_of_rows() const { return number_of_rows; }
    int get_number_of_seats_per_row() const { return number_of_seats_per_row; }
    string get_id() const { return id; }
    const Route& get_route() const { return route; }

    // Correct accessors for passengers & seats
    vector<vector<Seat>>& get_seats() { return seats; }
    const vector<vector<Seat>>& get_seats() const { return seats; }

    vector<Passenger>& get_passengers() { return passengers; }
    const vector<Passenger>& get_passengers() const { return passengers; }
};

#endif

