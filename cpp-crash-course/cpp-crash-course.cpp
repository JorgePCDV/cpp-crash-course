#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <functional>
#include <memory>
#include <memory>
#include <stdio.h>
#include <thread>
#include <chrono>
#include <mutex>

#include "Shape.h"
#include "Circle.h"
#include "ShapeAbstract.h"
#include "CircleAbstract.h"
#include "Box.h"
#include "Person.h"
#include "Person.cpp"

#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>


using namespace std;

#define PI 3.14159
#define AREA_CIRCLE(radius) (PI * pow(radius, 2))


int globalVariable = 2;

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

void lambdaExpressions() {
	vector<int> nums = {90, 20, 74, 21, 134 };
	vector<int> numsFiltered(nums.size());
	int sum = 0;
	
	//std::sort(nums.begin(), nums.end(), [](int x, int y) {return x < y; });
	//std::copy_if(nums.begin(), nums.end(), numsFiltered.begin(), [](int x) { return (x % 2) == 0; });;;;
	for_each(nums.begin(), nums.end(), [&](int x) { sum += x; });

	cout << "Sum: " << sum << endl;
	/*for (auto n : numsFiltered) {
		cout << n << endl;
	}*/
}

void fileIO() {
	std::ofstream writeToFile;
	ifstream readFromFile;
	string txtToWrite = "";
	string txtFromFile = "";

	writeToFile.open("test.txt", ios_base::out | ios_base::trunc);
	if (writeToFile.is_open()) {
		writeToFile << "Beginning of File\n";
		cout << "Enter data to write: ";
		getline(cin, txtToWrite);
		writeToFile << txtToWrite;
		writeToFile.close();
	}

	readFromFile.open("test.txt", ios_base::in);
	if (readFromFile.is_open()) {
		while (readFromFile.good()) {
			getline(readFromFile, txtFromFile);
			cout << txtFromFile << endl;
		}
		readFromFile.close();
	}
}

double functionsAsObjects(double num) {
	return num * 2;
}

double functionsAsArguments(function<double(double)> func, double num) {
	return func(num);
}

double multByThree(double num) {
	return num * 3;
}

template <typename T>
void Times2(T val) {
	cout << val << " * 2 = " << val * 2 << endl;
}

void containers() {
	deque<int> nums = {1, 2, 3, 4};
	nums.push_front(0);
	nums.push_back(5);
	for (int n : nums) {
		cout << n << endl;
	}
}

void iterators() {
	vector<int> nums = {1, 2, 3, 4, 5};
	vector<int>::iterator itr;
	for (itr = nums.begin(); itr < nums.end(); itr++) {
		cout << *itr << endl;
	}

	vector<int>::iterator itr2 = nums.begin();
	advance(itr2, 2);
	cout << *itr2 << endl;
}

void memoryAllocation() {
	int amountToStore;
	cout << "How many numbers to store: " << endl;
	cin >> amountToStore;

	int* pNums;
	pNums = (int*) malloc(amountToStore * sizeof(int));
	if (pNums != NULL) {
		int i = 0;
		while (i < amountToStore) {
			cout << "Enter a number : ";
			cin >> pNums[i];
			i++;
		}
	}
	cout << "You entered these numbers" << endl;
	for (int i = 0; i < amountToStore; i++) {
		cout << pNums[i] << endl;
	}
	delete pNums;
}

void smartPointers() {
	int amountToStore;
	cout << "How many numbers to store: " << endl;
	cin >> amountToStore;
	unique_ptr<int[]> pNums(new int[amountToStore]);
	if (pNums != NULL) {
		int i = 0;
		while (i < amountToStore) {
			cout << "Enter a number : ";
			cin >> pNums[i];
			i++;
		}
	}
	cout << "You entered these numbers" << endl;
	for (int i = 0; i < amountToStore; i++) {
		cout << pNums[i] << endl;
	}
}

int getRandom(int max) {
	srand(time(NULL));
	return rand() % max;
}

void execute_thread(int id) {
	auto nowTime = chrono::system_clock::now();
	time_t sleepTime = chrono::system_clock::to_time_t(nowTime);
	cout << "Thread id : " << id << endl;
	this_thread::sleep_for(chrono::seconds(getRandom(3)));
	nowTime = chrono::system_clock::now();
	sleepTime = chrono::system_clock::to_time_t(nowTime);
	cout << "Thread id : " << id
		<< endl;
}

void deques() {
	deque<int> deq1;
	deq1.push_back(5);
	deq1.push_front(1);
	deq1.assign({11, 12});
	cout << deq1[0] << endl;
	cout << deq1.at(1) << endl;
	deq1.pop_front();
	deq1.back();
}

void sets() {
	set<int> set1{5, 4, 3, 2, 1, 1};
	auto val = set1.find(3);
	cout << "Found " << *val << endl;
	for (int i : set1) cout << i << endl;
}

void maps() {
	map<int, string> map1;
	map1.insert(pair<int, string> (1, "Alice"));
	map1.insert(pair<int, string> (2, "Bob"));
	map1.insert(pair<int, string> (3, "Charlie"));
	map1.insert(pair<int, string> (4, "David"));

	auto match = map1.find(1);
	cout << match->second << endl;

	map<int, string>::iterator iterator1;
	for (iterator1 = map1.begin(); iterator1 != map1.end();++iterator1) {
		cout << "Key: " << iterator1->first << " Value: " << iterator1->second << endl;
	}
}

int main() {
	maps();
	//sets();
	//deques();
	/*thread thread1(execute_thread, 1);
	thread1.join();
	
	thread thread2(execute_thread, 2);
	thread2.join();*/

	//memoryAllocation();
	//iterators();
	//containers();
	
	/*Person<double, int> somePerson(5.83, 216);
	somePerson.GetData();*/

	/*Times2(5);
	Times2(5.3);*/
	
	//cout << "Circle Area " << AREA_CIRCLE(5) << endl;
	
	/*auto times2 = functionsAsObjects;
	cout << "5 * 2 = " << times2(5) << endl;
	
	cout << "6 * 2 = " << functionsAsArguments(functionsAsObjects, 6) << endl;

	vector<function<double(double)>> funcs(2);
	funcs[0] = functionsAsObjects;
	funcs[1] = multByThree;

	cout << "3 * 10 = " << funcs[1](10) << endl;*/

	//fileIO();
	//lambdaExpressions();
	
	/*Box box(10, 10, 10);
	cout << box << endl;
	++box;
	cout << box << endl;
	Box box2(5, 5, 5);
	cout << "Box 1 + Box 2 = " << box+box2 << endl;
	cout << box << endl;
	cout << "Box 1 == Box 2? " << (box == box2) << endl;*/

	
	/*ShapeStruct shapeStruct(10, 10);
	cout << "Square Area: " << shapeStruct.Area() << endl;
	CircleStruct circleStruct(6.5);
	cout << "Circle Area: " << circleStruct.Area() << endl;*/


	
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
