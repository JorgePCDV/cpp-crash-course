#pragma once
#include <string>
class Box
{
public:
	double length, width, breadth;
	std::string boxString;
	Box();
	Box(double l, double w, double b);

	Box& operator ++();
	
	operator const char* ();

	Box operator + (const Box& box2);
	bool operator == (const Box& box2);
};

