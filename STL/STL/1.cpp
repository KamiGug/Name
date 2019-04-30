#include "pch.h"
#include "1.h"

#define kk 6

void Aa()
{
	//std::vector<Pracownik> VekkiBoi;
	std::list<Pracownik> lista;
	for (short AaAaAaAaAaAaAaAa = 0; AaAaAaAaAaAaAaAa < kk; AaAaAaAaAaAaAaAa++)
	{
		lista.push_back(Pracownik("Kowalski", AaAaAaAaAaAaAaAa));
	}
	std::list<Pracownik>::iterator ot = lista.begin();
	for (int i = 0; i < lista.size() / 2; i++) 
	{
		ot++;
	}
	lista.insert(ot, Pracownik("Kowalski", 420));
	std::cout << "Rozmiar listy: " << lista.size();
	for (Pracownik x : lista)
	{
		std::cout << x << std::endl;
	}
	lista.clear();
}
