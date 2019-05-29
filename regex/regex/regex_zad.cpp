#include <iostream>
#include <regex>
#include <string>

void CzyKod(std::string ToCheck, std::regex kod, std::string CoTo)
{
	std::cout << ToCheck << " ";
	if (!std::regex_match(ToCheck, kod))
	{
		std::cout << "nie ";
	}
	std::cout << "jest jak " << CoTo << std::endl;
}

void dopasowania(std::string str, std::regex reg)
{
	std::smatch tak;
	int ile = 0;
	bool CzyByly, CzyNieBylo;
	while (std::regex_search(str, tak, reg))
	{
		CzyByly = tak.ready();
		CzyNieBylo = tak.empty();
		ile++;
		//ile = tak.size();
		
		std::cout << "Dopasowanie : " << tak.str() << std::endl;
		str = tak.suffix().str();
	}
	std::cout << "Czy byly dopasowania: " << CzyByly << std::endl;
	std::cout << "Czy nie bylo zadnych dopasowan: " << CzyNieBylo << std::endl;
	std::cout << "Liczba dopasowan: " << ile << std::endl;
	
}

int main() 
{
	//zad 1
	std::string kod1 = "12-345";
	std::string kod2 = "123-45";
	std::string kod3 = "1c-3d5";
	std::string kod4 = "12345";

	std::regex TakiKod("[0-9]{2}-[0-9]{3}");

	CzyKod(kod1, TakiKod, "kod pocztowy");
	CzyKod(kod2, TakiKod, "kod pocztowy");
	CzyKod(kod3, TakiKod, "kod pocztowy");
	CzyKod(kod4, TakiKod, "kod pocztowy");



	//zad 2
	std::string test = "the ape was on the apex";
	std::regex LessThanDeadTheyNeverWere("was");
	std::smatch Tak;
	std::regex_search(test, Tak, LessThanDeadTheyNeverWere);
	std::cout << std::endl << "Zad2: \n" << Tak.prefix() << "<<prefix   suffix>>" << Tak.suffix() << std::endl;

	//Zad 3
	std::cout << "Zad 3: \n";
	std::regex reg("(ape[^ ]?)");
	dopasowania(test, reg);

	//Zad 4
	std::string email = "nowak@email.pl , sss@we , email.pl , www.site.pL , tak@nie.com ";
	std::regex ToEmail("[\\w]+@[\\w]+\.[a-z]{2,3}");
	std::cout << "Zad 4: \n";
	dopasowania(email, ToEmail);

	//Zad 5 
	std::string tekst = "Ala ma kota";
	std::cout << "Zad 5: \n";
	std::regex Ala("Ala");
	std::cout << tekst << std::endl;
	std::cout << std::regex_replace(tekst, Ala, "Eugeniusz");
	std::cout << std::endl;

	//Zad 6
	
	std::cout << "Zad6: \n";
	std::regex moze("sss@we");
	dopasowania(std::regex_replace(email, moze, "hghj@hsa.com"), ToEmail);


	system("Pause");
	return 0;
}
