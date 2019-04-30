#pragma once

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <time.h>
#include <iterator>
#include <string>
#include <numeric>
#include <fstream>

class Klasa
{
	int ID;
	double parametr;
	std::string nazwa;
public:
	Klasa();
	Klasa(int klucz, double d, std::string nazwa);
	~Klasa();
	friend void wyswietl(std::vector<Klasa> wektor);
	friend bool sortuj_po_string(Klasa a, Klasa b);
};

Klasa::Klasa()
{
}

Klasa::Klasa(int klucz, double parametr, std::string nazwa)
{
	this->ID = klucz;
	this->parametr = parametr;
	this->nazwa = nazwa;
}

Klasa::~Klasa()
{
}

void wyswietl(std::vector<Klasa> wektor)
{
	for (std::vector<Klasa>::iterator it = wektor.begin(); it != wektor.end(); it++)
	{
		std::cout << (*it).ID << " " << (*it).parametr << " " << (*it).nazwa << "\n";
	}
	std::cout << std::endl;
}
bool sortuj_po_string(Klasa a, Klasa b)
{
	return a.nazwa < b.nazwa;
}



bool parzysta(int i)
{
	return (i % 2 == 0);
}

int main()
{
	std::vector<int> WektorInt1;
	for (int i = 0; i < 10; i++)
	{
		WektorInt1.push_back(i);
	}
	std::vector<int>::iterator i1 = find(WektorInt1.begin(), WektorInt1.end(), 5);
	std::cout << *i1 << std::endl;
	std::vector<int>::reverse_iterator i2(i1);
	std::cout << *i2 << std::endl;
	std::vector<int>::iterator i3(i2.base());
	std::cout << *i3 << std::endl;
	WektorInt1.clear();



	std::deque<int> deque1;
	std::front_insert_iterator<std::deque<int>> frontit(deque1);
	std::back_insert_iterator<std::deque<int>> backit(deque1);
	*frontit = 1;
	*frontit = 2;
	*frontit = 3;
	for (std::deque<int>::iterator i = deque1.begin(); i != deque1.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	*backit = 6;
	*backit = 7;
	*backit = 8;
	for (std::deque<int>::iterator i = deque1.begin(); i != deque1.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::insert_iterator<std::deque<int>> iter(deque1, deque1.begin() + 3);
	*iter = 32;
	for (std::deque<int>::iterator i = deque1.begin(); i != deque1.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	copy(deque1.begin(), deque1.end(), frontit);
	for (std::deque<int>::iterator i = deque1.begin(); i != deque1.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	deque1.clear();
 
	srand(time(NULL));
	std::vector<int>WektorInt3;
	for (int i = 0; i < 10; i++)
	{
		WektorInt3.push_back(rand() % 101);
	}
	std::cout << count_if(WektorInt3.begin(), WektorInt3.end(), parzysta) << std::endl;
 
	std::cout << accumulate(WektorInt3.begin(), WektorInt3.end(), 0) << std::endl;
 
	for (std::vector<int>::iterator i = WektorInt3.begin(); i != WektorInt3.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	reverse(WektorInt3.begin(), WektorInt3.end());
	for (std::vector<int>::iterator i = WektorInt3.begin(); i != WektorInt3.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl; 

	sort(WektorInt3.begin(), WektorInt3.end(), [](int l, int r) {return l % 5 < r % 5; });
	std::cout << "mod\n";
	int licznik = 0;
	for (std::vector<int>::iterator i = WektorInt3.begin(); i != WektorInt3.end(); i++)
	{
		if ((*i) % 5 != licznik)
		{
			std::cout << *i << " ";
		}
		else
		{
			std::cout << *i << " ";
			licznik++;
		}
	}
	std::cout << std::endl;
	WektorInt3.clear();


	std::vector<Klasa> wektor;
	std::vector<Klasa> wektor2;
	std::vector<Klasa> wekto3;
	Klasa k1(1, 3.14, "pi");
	Klasa k2(3, 9.81, "G");
	Klasa k3(2, 2.71, "liczba e");
	Klasa k4(10, 6.63, "stala Plancka");
	wektor.push_back(k1);
	wektor.push_back(k2);
	wektor.push_back(k3);
	wektor.push_back(k4);
	sort(wektor.begin(), wektor.end(), sortuj_po_string);
	wyswietl(wektor);
	wektor.clear();



	std::fstream plik;
	plik.open("piosenka.txt", std::ios::in);
	if (plik.is_open())
	{
		std::string slowo;
		std::vector<std::string> piosenka;

		while (!plik.eof())
		{
			plik >> slowo;
			if (find(piosenka.begin(), piosenka.end(), slowo) == piosenka.end())
			{
				piosenka.push_back(slowo);
			}
		}
		sort(piosenka.begin(), piosenka.end());

		for (std::vector<std::string>::iterator k = piosenka.begin(); k != piosenka.end(); k++)
		{
			std::cout << *k << " ";
		}
		std::cout << std::endl;
		make_heap(piosenka.begin(), piosenka.end());
		int o = 1, o1 = 1;

		std::cout << std::endl;
		for (std::vector<std::string>::iterator k = piosenka.begin(); k != piosenka.end(); k++)
		{
			std::cout << *k << " ";
			if (o == o1)
			{
				o = 1;
				o1 = o1 * 2;
				std::cout << std::endl;
			}
			else
				o++;
		}
		std::cout << std::endl;

		if (is_heap(piosenka.begin(), piosenka.end()))
		{
			std::cout << "\nTo kopiec\n\n";
		}
			
		pop_heap(piosenka.begin(), piosenka.end());
		if (is_heap(piosenka.begin(), piosenka.end()))
		{
			std::cout << "\nTo kopiec\n\n";
		}
		piosenka.clear();
		plik.close();
	}
	else
	{
		std::cout << "nie ma pliku tu";
	}
}
