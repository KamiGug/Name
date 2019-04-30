#include "pch.h"
#include "Pracownik.h"


Pracownik::Pracownik()
{
	std::cout << "Podaj imie: ";
	std::cin >> this->name;
	std::cout << "Podaj ID: ";
	std::cin >> this->ID;
}

Pracownik::Pracownik(std::string name, int ID)
{
	this->name = name;
	this->ID = ID;
}


Pracownik::~Pracownik()
{
}

std::ostream & operator<<(std::ostream& os, const Pracownik &ten)
{
	os << "Imie: " << ten.name << " ID: " << ten.ID << std::endl;
	return os;
	// TODO: insert return statement here
}
