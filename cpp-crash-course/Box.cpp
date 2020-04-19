#include "Box.h"
#include <sstream>


Box::Box()
{
	length = 1, width = 1, breadth = 1;
}

Box::Box(double l, double w, double b)
{
	length = l;
	width = w;
	breadth = b;
}

Box& Box::operator++()
{
	length++;
	width++;
	breadth++;
	return *this;
}

Box::operator const char* ()
{
	std::ostringstream boxStream;
	boxStream << "Box : " <<
		length << ", " <<
		width << ", " <<
		breadth;
	boxString = boxStream.str();
	return boxString.c_str();
}

Box Box::operator+(const Box& box2)
{
	Box boxSum;
	boxSum.length = length + box2.length;
	boxSum.width = width + box2.width;
	boxSum.breadth = breadth + box2.breadth;
	return boxSum;
}

bool Box::operator==(const Box& box2)
{
	return ((length == box2.length) &&
			(width == box2.width) &&
			(breadth == box2.breadth));
}
