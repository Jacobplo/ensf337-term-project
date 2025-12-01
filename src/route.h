/*
 *  File Name: route.h
 *  Assignment: Term Project
 *  Lecture Section: L01
 *  Completed by: Jacob Plourde
 *  Development Date: November 29, 2025
 */
//
//  route.h
//  Project 1
//
//  Created by Julia Izuogu on 2025-11-30.
//


#ifndef ROUTE_H
#define ROUTE_H

#include <string>

using std::string;

class Route {
private:
  string source;
  string destination;
public:
  Route() {};
  Route(const string& src, const string& dest);
  string get_source()const { return source; }
  string get_destination()const { return destination; }
};

#endif
