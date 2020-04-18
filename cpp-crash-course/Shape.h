#pragma once
class Shape
{
protected:
	double height;
	double width;
public:
	static int numOfShapes;
	
	Shape(double length);
	Shape(double height, double width);
	Shape();
	
	virtual ~Shape();
	
	void setHeight(double height);
	double getHeight();

	void setWidth(double width);
	double getWidth();

	static int getNumOfShapes();

	virtual double area();
};

