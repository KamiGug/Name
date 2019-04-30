#include "pch.h"
#include "3.h"

#define Nice 5

void AaAaAa()
{
	std::list<Pracownik> lista_pracownik;
	for (int i = 0; i < Nice; i++)
	{
		lista_pracownik.push_back(Pracownik("Kowalski", i));
	}
	lista_pracownik.sort();
	for (Pracownik x : lista_pracownik)
	{
		std::cout << x << std::endl;
	}
		

	std::vector<Pracownik> wektor_pracownik;
	for (int i = 0; i < Nice; i++)
	{
		wektor_pracownik.push_back(Pracownik("Nowak", 2 * Nice - i));
	}
	for (int i = 0; i < Nice - 1; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (wektor_pracownik[j] < wektor_pracownik[i])
			{
				std::swap(wektor_pracownik[j], wektor_pracownik[i]);
			}
				
		}
	}
	for (int i = 0; i < Nice; i++)
	{
		std::cout << wektor_pracownik[i] << std::endl;
	}
	
}
