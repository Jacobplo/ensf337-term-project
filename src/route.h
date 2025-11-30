#ifndef ROUTE_H
#define ROUTE_H

#include <string>

using std::string;

class Route {
private:
  string source;
  string destination;
public:
  Route();
  Route(string& src, string& dest): source(src), destination(dest) {};
  string get_source()const { return source; };
  string get_destination()const { return destination; };
};

#endif
