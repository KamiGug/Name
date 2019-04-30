#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

template <class A, int wielkosc>
class tablica
{
	A* tab;
	int rozmiar;
	int ilosc_ele;
public:
	int get_ilosc() 
	{ 
		return ilosc_ele; 
	}
	tablica() : ilosc_ele(0), rozmiar(wielkosc)
	{
		tab = new A[rozmiar];
	}
	tablica(A obiekt) : ilosc_ele(rozmiar), rozmiar(wielkosc + 4)
	{
		tab = new A[ilosc_ele];
		for (int i = 0; i < ilosc_ele; i++)
			tab[i] = obiekt;
	}
	tablica(const tablica & obiekt) :rozmiar(obiekt.rozmiar), ilosc_ele(obiekt.ilosc_ele)
	{
		tab = new A[rozmiar];
		for (int i = 0; i < ilosc_ele; i++)
			tab[i] = obiekt.tab[i];
	}
	void dodaj(A obiekt);
	void wypisz()
	{
		for (int i = 0; i < ilosc_ele; i++)
			cout << "[" << i + 1 << "]: " << tab[i] << endl;
	}
	A operator[](int indeks)
	{
		if (indeks > ilosc_ele)
			throw "Wyjscie za tablice";
		else
			return tab[indeks];
	}
	~tablica()
	{
		delete[] tab;
	}
};
template <class A, int wielkosc> void tablica<A, wielkosc>::dodaj(A obiekt)
{
	if (ilosc_ele + 1 > rozmiar)
	{
		rozmiar += 4;
		A* nowa_tab = new A[rozmiar];
		for (int i = 0; i < ilosc_ele; i++)
			nowa_tab[i] = tab[i];
		nowa_tab[ilosc_ele] = obiekt;
		delete[] tab;
		tab = nowa_tab;
	}
	else
		tab[ilosc_ele] = obiekt;
	ilosc_ele++;
}


template <class A>
A policz(A ob_1, A ob_2)
{
	if (ob_1 > ob_2)
		return  ob_1 * ob_1 + ob_2 * ob_2;
	else
		return (ob_1 + ob_2)*(ob_1 + ob_2);
}

int policz(tablica<int, 2> tab_1, tablica<int, 2> tab_2)
{
	int suma_1 = 0, suma_2 = 0;
	for (int i = 0; i < tab_1.get_ilosc(); i++)
		suma_1 += tab_1[i];
	for (int i = 0; i < tab_2.get_ilosc(); i++)
		suma_2 += tab_2[i];
	if (suma_1 > suma_2)
		return  suma_1 * suma_1 + suma_2 * suma_2;
	else
		return (suma_1 + suma_2)*(suma_1 + suma_2);
}

string policz(char znak_1, char znak_2)
{
	if (znak_1 > znak_2)
		throw "Zla kolejnosc znakow";
	else
	{
		string napis;
		for (int i = 0; i < 3; i++)
		{
			napis += znak_1;
			napis += znak_2;
		}
		return napis;
	}
}
int main()
{
	cout << "Tab 1:\n";
	tablica<string, 2> tab;
	tab.dodaj("Does");
	tab.dodaj("it");
	tab.dodaj("work?");
	tab.dodaj("I");
	tab.dodaj("wanna");
	tab.dodaj("know.");
	tab.wypisz();
	cout << "\nTab 2:\n";
	tablica<int, 2> tab_1;
	tab_1.dodaj(2);
	tab_1.dodaj(1);
	tab_1.dodaj(3);
	tab_1.dodaj(7);
	tab_1.wypisz();
	tablica<int, 2> tab_2;
	tab_2.dodaj(4);
	tab_2.dodaj(2);
	tab_2.dodaj(0);
	cout << "\nTab 2 after additional additions:\n";
	tab_2.wypisz();
	int ai = 4, bi = 5;
	double ad = 12.8, bd = 1.5;
	char a = 'a', b = 'd';
	cout << "int: " <<policz(ai, bi) << "\nDouble: " << policz(ad, bd) << "\nTab: " << policz(tab_1, tab_2) << "\nchar: " << policz(a, b) << endl;
	return 0;
}