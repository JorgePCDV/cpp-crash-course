#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>
#include "Shape.h"
#include "Circle.h"
#include "ShapeAbstract.h"
#include "CircleAbstract.h"

using namespace std;

int globalVariable = 2;
const double PI = 3.14;

void printNumericLimits() {
	cout << "Min unsigned short int " << numeric_limits<unsigned short int>::min() << endl;
	cout << "Max unsigned short int " << numeric_limits<unsigned short int>::max() << endl;
	cout << "Min short int " << numeric_limits<short int>::min() << endl;
	cout << "Max short int " << numeric_limits<short int>::max() << endl;
	cout << "Min int " << numeric_limits<int>::min() << endl;
	cout << "Max int " << numeric_limits<int>::max() << endl;
	cout << "Min long" << numeric_limits<long>::min() << endl;
	cout << "Max long " << numeric_limits<long>::max() << endl;

	float f1 = 1.1111111;
	float f2 = 1.1111111;

	//printf("Loss of precision sum = %.7f\n", (f1 + f2));
}

void inputExample() {
	string input;
	cout << "Enter a number: " << endl;
	cin >> input;
	printf("Number: %d\n", stoi(input));
}

bool ternaryOperatorEx(int age) {
	bool canIVote = (age >= 18) ? true : false;
	return canIVote;
}

void arrays() {
	int arrNums1[10] = {1};
	int arrNums2[] = { 1, 2, 3 };

	cout << "arrNums2 first value: " << arrNums2[0] << endl;
	arrNums2[0] = 7;
	cout << "arrNums2 first value is now: " << arrNums2[0] << endl;
}

void vectors() {
	vector<int> nums(2);
	nums[0] = 1;
	nums[1] = 2;
	nums.push_back(3);
	cout << "Nums vector size: " << nums.size() << endl;
}

void stringStream() {
	vector<string> words;
	stringstream ss("Some Random Words");
	string word;
	
	while (getline(ss, word, ' ')) {
		words.push_back(word);
	}

	for (auto word : words) cout << word << endl;
	
}

void numberGuess() {
	srand(time(NULL));
	int secretNum = rand() % 11;
	int guess;

	do {
		cout << "Guess the number: " << endl;
		cin >> guess;
		if (guess > secretNum) cout << "Too big" << endl;
		if (guess < secretNum) cout << "Too small" << endl;
	} while (secretNum != guess);
	printf("Guessed correct secret number %d", secretNum);

	string again;
	cout << endl << "Again? Y/N" << endl;
	cin >> again;

	if (again == "Y" || again == "y") numberGuess();
}

void strings() {
	string string1 = "String example";
	cout << "First: " << string1[0] << endl;
	cout << "Last: " << string1.back() << endl;
	cout << "Length: " << string1.length() << endl;
	
	string string2 = string1;
	string string3(string2, 4);
}

void pointers() {
	int n = 5;
	int* pn = &n;
	cout << "n address: " << pn << endl;
	cout << "n value: " << *pn << endl;
}

void pointerToArray() {
	int intArray[] = {1, 2, 3, 4};
	int* pIntArray = intArray;
	cout << "1st array address: " << pIntArray << endl;
	cout << "1st array value: " << *pIntArray << endl;
	pIntArray++;
	cout << "2nd array address: " << pIntArray << endl;
	cout << "2nd array value: " << *pIntArray << endl;
}

void doubleArray(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = arr[i] * 2;
	}
}

void exceptionHandling() {
	double num1 = 10, num2 = 0;
	try {
		if(num2 == 0) {
			throw "division by zero error";
		} else {
			printf("%.1f / %.1f = %.1f", num1, num2, (num1 / num2));
		}
	} catch (const char* exp) {
		cout << "Error: " << exp << endl;
	}
}

double addNumbers(double num1, double num2);
void assignAge(int age);
void assignAgePointer(int* agePointer);
void showAreaAbstract(ShapeAbstract& shape);

void showArea(Shape& shape) {
	cout << "Area of " << typeid(shape).name() << " is " << shape.area() << endl;
}

void showAreaAbstract(ShapeAbstract& shape) {
	cout << "Area of " << typeid(shape).name() << " is " << shape.Area() << endl;
}

struct ShapeStruct {
	double length, width;
	
	ShapeStruct(double l = 1, double w = 1) {
		length = l;
		width = w;
	}
	
	double Area() {
		return length * width;
	}
	
private:
	int id;
};

struct CircleStruct : ShapeStruct {
	CircleStruct(double width) {
		this->width = width;
	}

	double Area() {
		return 3.14159 * pow((width / 2), 2);
	}
};

int main() {
	ShapeStruct shapeStruct(10, 10);
	cout << "Square Area: " << shapeStruct.Area() << endl;
	CircleStruct circleStruct(6.5);
	cout << "Circle Area: " << circleStruct.Area() << endl;


	
	/*CircleAbstract circleAbstract(10);
	showAreaAbstract(circleAbstract);*/
	
	/*Shape square(10, 5);
	Circle circle(10);
	showArea(square);
	showArea(circle);*/
	
	/*int someArray[] = {1, 2, 3, 4};
	doubleArray(someArray, size(someArray));
	for (auto n : someArray) {
		printf("%d", n);
	}*/
	//pointerToArray();
	//pointers();
	//printf("%.1f + %.1f = %.1f", 5.0, 4.0, addNumbers(5, 4));
	//numberGuess();
	//stringStream();
	//vectors();
	//arrays();
	//cout.setf(ios::boolalpha);
	//cout << ternaryOperatorEx(4) << endl;
	//printNumericLimits();
	//inputExample();
}

void assignAgePointer(int* agePointer) {
	*agePointer = 24;
}

void assignAge(int age) {
	age = 24;
}

double addNumbers(double num1=0, double num2=0) {
	return num1 + num2;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
