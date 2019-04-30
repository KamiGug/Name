#include "pch.h"
#include "1.h"

void Aa(void)
{
	std::cout << "1. \n";
	//a

	int rozmiar = 10000000000;


	try
	{
		int* tablica = new int[rozmiar]; //bad array length

	}
	catch (std::bad_alloc e)
	{
		std::cout << "a) przechwycona nieudana rezerwacja: " << e.what() << std::endl;
	}


	//b

	std::vector<int> myvector(10);

	try
	{

		myvector.at(20) = 100;      // dodanie wartosci 100 na 20 pozycje w wektorze(wyjscie poza zakres)
	}
	catch (const std::out_of_range e)
	{
		std::cout << "b) Wyjscie poza zakres: " << e.what() << std::endl;
	}

	//c
	try
	{
		Pojazd p;
		Samochod& s = dynamic_cast<Samochod&>(p);
	}
	catch (std::bad_cast e)
	{
		std::cout << "c) Blad rzutowania: " << e.what() << std::endl;
	}
}
