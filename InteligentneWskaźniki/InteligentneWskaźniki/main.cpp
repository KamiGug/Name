#include "header.h"
#include <iostream>
#include <ctime>
#include <memory>
#include <conio.h>

int main() {
	srand(time(NULL));
	{ //zadanie 1
		std::cout << "Zadanie 1:\n";
		for (int i = 0; i < 64; i++) {
			zadanie1a();
			Global::clear();
		}
		std::cout << "Po zadaniu 1a: " << Data::getAllocated() << std::endl;
		for (int i = 0; i < 64; i++) {
			zadanie1b();
			Global::clear();
		}
		std::cout << "Po zadaniu 1b: " << Data::getAllocated() << std::endl;
	}
	{ //zadanie 2
		std::cout << "\nZadanie 2:\n";
		zadanie2a();
		std::cout << "Po zadaniu 2a: " << Data::getAllocated() << std::endl;
		zadanie2b();
		std::cout << "Po zadaniu 2b: " << Data::getAllocated() << std::endl;
	}
	{ //zadanie 3
		std::cout << "\nZadanie 3:\n";
		zadanie3();
		std::cout << "Po zadaniu 3: " << Data::getAllocated() << std::endl;
	}
	_getch();
	return 0;
}