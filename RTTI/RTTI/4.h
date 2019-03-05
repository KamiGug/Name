#pragma once
#include <iostream>
#include <typeinfo>

class szklanka  
{
	int wsp_wytrzymalosci = 3;
	char rodzaj_szkla[14];
public:
	szklanka();
	virtual void f();
};
class kubek : public szklanka  
{
public:
	int pojemnosc = 250;
	char producent[5];
	kubek();
	void f();
};

void AaAaAaAaAaAaAaAaAaAaAa();