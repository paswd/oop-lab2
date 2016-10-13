#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cstdlib>

class Position {
public:
	double x;
	double y;

	void Input(std::istream &is);
	void Print();
};

double Absolute(double num);


#endif /* GEOMETRY_H */
