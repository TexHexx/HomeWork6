// HomeWork6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "lc_ReverseLinkedList.h"

std::ostream& endll(std::ostream& os) {
	os << '\n' << '\n';
	os.flush();
	return os;
}


int getNumber() {
	int num;
	while (true)
	{
		std::cout << "Enter number: ";
		std::cin >> num;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "String is not a number number, lets try again" << std::endl;
			continue;
		}
		break;
	}
	return num;
};

void FirstTask() {
	std::cout << getNumber();
};

void SecondTask() {
	std::cout << "Hello" << endll;
	std::cout << "Bye" << endll;
}

int main()
{
	FirstTask();
	SecondTask();
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
