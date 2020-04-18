#include "Shape.h"

int Shape::numOfShapes = 0;

Shape::Shape(double length) {
	this->height = length;
	this->width = length;
}

Shape::Shape(double height, double width) {
	this->height = height;
	this->width = width;
}

Shape::~Shape() = default;

void Shape::setHeight(double height) {
	this->height = height;
}

double Shape::getHeight() {
	return height;
}

void Shape::setWidth(double width) {
	this->width = width;
}

double Shape::getWidth() {
	return width;
}

int Shape::getNumOfShapes() {
	return numOfShapes;
}

double Shape::area(){
	return height * width;
}
