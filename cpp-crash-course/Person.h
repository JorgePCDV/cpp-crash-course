#pragma once
#include <iostream>
using namespace std;



template <typename T, typename U>
class Person
{
public:
	T height;
	U weight;
	Person(T h, U w);
	void GetData();
};


