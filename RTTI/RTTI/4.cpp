#include "pch.h"

#include "4.h"

void szklanka::f() 
{ 
	std::cout << " Jestem szklanka" << wsp_wytrzymalosci << std::endl; 
}

szklanka::szklanka() 
{
	strcpy_s(rodzaj_szkla, 14, "bardzo_twarde");
}

kubek::kubek()
{
	strcpy_s(producent, 5, "IKEA");
}

void kubek::f()
{ 
	std::cout << "Jestem kubek " << producent << std::endl; 
}

void AaAaAaAaAaAaAaAaAaAaAa()
{
	kubek k;
	szklanka sz;
	sz = k;
	std::cout << &sz << std::endl;
	std::cout << &k << std::endl;

	szklanka *przedmiot_2 = new kubek();
	kubek *przedmiot_1 = dynamic_cast<kubek*>(przedmiot_2);
	std::cout << przedmiot_1->pojemnosc << " " << przedmiot_1->producent << std::endl; 
	przedmiot_1->f();
	przedmiot_2->f(); 

	kubek k_1, *k_2;
	szklanka * sz_1;
	sz_1 = &k_1;
	k_2 = dynamic_cast <kubek*>(sz_1);
	if (k_2)
		std::cout << "rzutowanie udane" << std::endl;
	else
		std::cout << "rzutowanie nie udane" << std::endl;
	delete przedmiot_1;
}