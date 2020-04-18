#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>

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

	printf("Loss of precision sum = %.7f\n", (f1 + f2));
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

int main()
{
	numberGuess();
	//stringStream();
	//vectors();
	//arrays();
	//cout.setf(ios::boolalpha);
	//cout << ternaryOperatorEx(4) << endl;
	//printNumericLimits();
	//inputExample();
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
