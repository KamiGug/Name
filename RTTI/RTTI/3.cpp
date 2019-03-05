#include "pch.h"

#include "3.h"


void AaAaAaAaAaAaAaAaAaAaAaAa()
{
	struktura_2 obiekt;
	struktura_1 *wsk = &obiekt;
	void *wsk2 = dynamic_cast<void*>(wsk);
	std::cout << wsk << std::endl;
	std::cout << wsk2 << std::endl;
	std::cout << &obiekt << std::endl;
}