#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <time.h>
#include <iterator>
#include <string>
#include <numeric>
#include <fstream>

using namespace std;
bool ujemna(int i)
{
	return (i % 2 == 0);
}
class Klasa
{
	int ID;
	double parametr;
	string nazwa;
public:
	Klasa(int i, double d, string s)
	{
		ID = i;
		parametr = d;
		nazwa = s;
	}
	friend void wyswietl(vector<Klasa> wektor);
	friend bool sortuj_po_int(Klasa a, Klasa b);
	friend bool sortuj_po_double(Klasa a, Klasa b);
	friend bool sortuj_po_string(Klasa a, Klasa b);
};
void wyswietl(vector<Klasa> wektor)
{
	for (vector<Klasa>::iterator it = wektor.begin(); it != wektor.end(); it++)
	{
		cout << (*it).ID << " " << (*it).parametr << " " << (*it).nazwa << "\n";
	}
	cout << endl;
}
bool sortuj_po_int(Klasa a, Klasa b)
{
	return a.ID < b.ID;
}
bool sortuj_po_double(Klasa a, Klasa b)
{
	return a.parametr < b.parametr;
}
bool sortuj_po_string(Klasa a, Klasa b)
{
	return a.nazwa < b.nazwa;
}
int main()
{
	//////////////////////////////////////////////////
	vector<int> w1;
	for (int i = 0; i < 10; i++)
	{
		w1.push_back(i);
	}
	vector<int>::iterator i1 = find(w1.begin(), w1.end(), 5);
	cout << *i1 << endl;
	vector<int>::reverse_iterator i2(i1);
	cout << *i2 << endl;
	vector<int>::iterator i3(i2.base());
	cout << *i3 << endl;
	w1.clear();
	///////////////////////////////////////////////////
	deque<int> d1;
	front_insert_iterator<deque<int>> frontit(d1);
	back_insert_iterator<deque<int>> backit(d1);
	*frontit = 1;
	*frontit = 2;
	*frontit = 3;
	for (deque<int>::iterator i = d1.begin(); i != d1.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	*backit = 6;
	*backit = 7;
	*backit = 8;
	for (deque<int>::iterator i = d1.begin(); i != d1.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	insert_iterator<deque<int>> iter(d1, d1.begin() + 3);
	*iter = 32;
	for (deque<int>::iterator i = d1.begin(); i != d1.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	copy(d1.begin(), d1.end(), frontit);
	for (deque<int>::iterator i = d1.begin(); i != d1.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	d1.clear();
	////////////////////////////////////////////////////////
	srand(time(NULL));
	vector<int>w3;
	for (int i = 0; i < 10; i++)
	{
		w3.push_back(rand() % 101);
	}
	cout << count_if(w3.begin(), w3.end(), ujemna) << endl;
	/////////////////////////////////////////////////////////
	cout << accumulate(w3.begin(), w3.end(), 0) << endl;
	/////////////////////////////////////////////////////////
	for (vector<int>::iterator i = w3.begin(); i != w3.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	reverse(w3.begin(), w3.end());
	for (vector<int>::iterator i = w3.begin(); i != w3.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	/////////////////////////////////////////////////////////
	sort(w3.begin(),w3.end(), [](int l, int r) {return l % 5 < r % 5; });
	cout << "mod\n";
	int licznik = 0;
	for (vector<int>::iterator i = w3.begin(); i != w3.end(); i++)
	{
		if ((*i) % 5 != licznik)
		{
			cout << *i << " ";
		}
		else
		{
			cout << "|";
			cout << *i << " ";
			licznik++;
		}
	}
	cout << endl;
	w3.clear();
	/////////////////////////////////////////////////////////
	vector<Klasa> wektor;
	vector<Klasa> wektor2;
	vector<Klasa> wekto3;
	Klasa k1(1, 3.14, "pi");
	Klasa k2(3, 9.81, "G");
	Klasa k3(2, 2.71, "liczba e");
	Klasa k4(10, 6.63, "stala Plancka");
	wektor.push_back(k1);
	wektor.push_back(k2);
	wektor.push_back(k3);
	wektor.push_back(k4);
	sort(wektor.begin(), wektor.end(), sortuj_po_int);
	wyswietl(wektor);
	sort(wektor.begin(), wektor.end(), sortuj_po_double);
	wyswietl(wektor);
	sort(wektor.begin(), wektor.end(), sortuj_po_string);
	wyswietl(wektor);
	wektor.clear();
	//////////////////////////////////////////////////////////
	fstream plik;
	plik.open("piosenka.txt", ios::in);
	string slowo;
	vector<string> slowa;

	while (!plik.eof())
	{
		plik >> slowo;
		if (find(slowa.begin(), slowa.end(), slowo) == slowa.end())
		{
			slowa.push_back(slowo);
		}
	}
	sort(slowa.begin(), slowa.end());

	for (vector<string>::iterator k = slowa.begin(); k != slowa.end(); k++)
	{
		cout << *k << " ";
	}
	cout << endl;
	make_heap(slowa.begin(), slowa.end());
	int o = 1, o1 = 1;

	cout << endl;
	for (vector<string>::iterator k = slowa.begin(); k != slowa.end(); k++)
	{
		cout << *k << " ";
		if (o == o1)
		{
			o = 1;
			o1 = o1 * 2;
			cout << endl;
		}
		else
			o++;
	}
	cout << endl;

	if (is_heap(slowa.begin(), slowa.end()))
		cout << "To kopiec\n";
	pop_heap(slowa.begin(), slowa.end());
	if (is_heap(slowa.begin(), slowa.end()))
		cout << "To kopiec\n";


	slowa.clear();
	plik.close();
	system("pause");
}
