#include "Person.h"



template<typename T, typename U>
Person<T, U>::Person(T h, U w)
{
	height = h, weight = w;
}

template<typename T, typename U>
void Person<T, U>::GetData()
{
	cout << "Height : " << height
		<< " Weight : " << weight
		<< endl;
}
