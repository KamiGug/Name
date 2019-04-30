#include "pch.h"
#include "2.h"

double PoleKola(double r)
{

	std::cout << "obliczamy pole kola o promieniu " << r << std::endl;
	if (r >= 0)
	{
		return 3.14*r*r;
	}
	else
	{
		std::cout << "Rzucenie wyjatku" << std::endl;
		BladUjemnegoPromienia e;
		throw e;
	}
}

void AaAa(void)
{
	std::cout << "2. \n";
	try
	{
		std::cout << "R = 21.37\n";
		double wartosc = PoleKola(21.37);
		std::cout << "Pole kola = " << wartosc << std::endl;

		std::cout << "R = -9,11\n";
		wartosc = PoleKola(-9.11);
		std::cout << "Pole kola = " << wartosc << std::endl;
	}
	catch (BladUjemnegoPromienia e)
	{
		e.wiadomosc = "zadany promien jest ujemny!";
		std::cout << e.wiadomosc << std::endl;
	}
}
