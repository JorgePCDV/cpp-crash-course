#pragma once
#include "ShapeAbstract.h"
class CircleAbstract : public ShapeAbstract
{
protected:
	double width;
public:
	CircleAbstract(double w);
	double Area() override;
};

