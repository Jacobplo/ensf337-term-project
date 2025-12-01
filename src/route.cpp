/*
 *  File Name: route.cpp
 *  Assignment: ENSF 337 Term Project
 *  Lab and Lecture Section: 1
 *  Completed by: Unas Khalid, Jacob Plourde
 *  Development Date: November 28, 2025
 */

#include "route.h"

Route::Route(const string &from, const string &to) {
    origin = from;
    destination_city = to;
}

string Route::get_source() const {
    return origin;
}

string Route::get_destination() const {
    return destination_city;
}
