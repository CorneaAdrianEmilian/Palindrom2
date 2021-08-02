// Palindrom2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "Rearanjeaza.h"
#include "CouldBePalindrom.h"
#include "MightBePalindrom.h"
int main()
{
	std::string test;
	std::cout << "Introduceti un sir de caractere\n";
	std::cin >> test;
	/*if (MightBePalindrom(test)) {
		std::cout << "Sirul poate fi un palindrom\n";
	}
	else
		std::cout << "Sirul nu poate fi un palindrom\n";*/
	rearanjeaza(test);
	std::cout << test << std::endl;
}
	


