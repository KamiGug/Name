#pragma once
#include <typeinfo>
#include <iostream>

struct Pojazd { };
struct Samochod : Pojazd { };
struct Budynek {
	virtual ~Budynek() { }
};
struct Dom : Budynek { };
void AaAaAaAaAaAaAaAaAaAaAaAaAa();
