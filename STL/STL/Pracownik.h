#pragma once
#include <iostream>
#include <string>


class Pracownik
{
public:
	Pracownik();
	Pracownik(std::string name, int ID);
	~Pracownik();

	friend std::ostream& operator<<(std::ostream& os, const Pracownik& ten);

	bool operator<(Pracownik p)
	{
		if (ID < p.ID)
			return true;
		else return false;
	}

private:
	std::string name;
	int ID;
};

