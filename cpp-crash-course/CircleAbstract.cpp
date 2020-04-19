#include "CircleAbstract.h"
#include <cmath>

CircleAbstract::CircleAbstract(double w)
{
	width = w;
}

double CircleAbstract::Area()
{
	return 3.14159 * pow((width / 2), 2);
}
