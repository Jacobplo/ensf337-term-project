/*
 *  File Name: route.h
 *  Assignment: ENSF 337 Term Project
 *  Lab and Lecture Section: 1
 *  Completed by: Unas Khalid
 *  Development Date: November 28, 2025
 */

#ifndef HEADER_FOR_ROUTE
#define HEADER_FOR_ROUTE
#include <string>

using std::string;

class Route {

private:
    
    string origin;
    string destination_city;
    
public:

    Route() {
        origin = "";
        destination_city = "";
    }

    Route(const string &from, const string &to);

    string get_source() const;
    
    string get_destination() const;

};

#endif
