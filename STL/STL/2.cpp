#include "pch.h"
#include "2.h"

void AaAa()
{
	srand(time(NULL));
	std::set<int> drzewo1;
	for (int i = 0; i < 20; i++)
	{
		drzewo1.insert((rand() % 10 + 1));
	}
		
	std::cout << "Rozmiar pierwszego drzewa: " << drzewo1.size() << std::endl;

	for (int x : drzewo1)
	{
		std::cout << x << std::endl;
	}
		

	std::multiset<int> drzewo2;
	for (int i = 0; i < 20; i++)
	{
		drzewo2.insert((rand() % 10 + 1));
	}
		
	std::cout << "Rozmiar drugiego drzewa: " << drzewo2.size() << std::endl;
	
	for (int x : drzewo2)
	{
		std::cout << x << std::endl;
	}
}
