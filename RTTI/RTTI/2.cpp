#include "pch.h"
#include "2.h"

void AaAaAaAaAaAaAaAaAaAaAaAaAa()
{
	Pojazd    poj;
	Samochod  sam1, sam2;
	Samochod* p_sam1 = &sam1;
	Pojazd*   p_sam2 = &sam2;
	Pojazd&   r_sam1 = sam1;
	std::cout << "    poj: " << typeid(poj).name() << std::endl
		<< "   sam1: " << typeid(sam1).name() << std::endl
		<< "   sam2: " << typeid(sam2).name() << std::endl
		<< " p_sam1: " << typeid(p_sam1).name() << std::endl
		<< " p_sam2: " << typeid(p_sam2).name() << std::endl
		<< "*p_sam1: " << typeid(*p_sam1).name() << std::endl
		<< "*p_sam2: " << typeid(*p_sam2).name() << std::endl
		<< " r_sam1: " << typeid(r_sam1).name() << std::endl;

	std::cout << "Typy *p_sam1 i *p_sam2 sa "
		<< (typeid(*p_sam1) == typeid(*p_sam2) ?
			"takie same\n" : "rozne\n") << std::endl;
	Budynek  bud;
	Dom   dom1, dom2;
	Dom*  p_dom1 = &dom1;
	Budynek* p_dom2 = &dom2;
	Budynek& r_dom1 = dom1;
	std::cout << "    bud: " << typeid(bud).name() << std::endl
		<< "   dom1: " << typeid(dom1).name() << std::endl
		<< "   dom2: " << typeid(dom2).name() << std::endl
		<< " p_dom1: " << typeid(p_dom1).name() << std::endl
		<< " p_dom2: " << typeid(p_dom2).name() << std::endl
		<< "*p_dom1: " << typeid(*p_dom1).name() << std::endl
		<< "*p_dom2: " << typeid(*p_dom2).name() << std::endl
		<< " r_dom1: " << typeid(r_dom1).name() << std::endl;
	std::cout << "Typy *p_dom1 i *p_dom2 sa " << (typeid(*p_dom1) == typeid(*p_dom2) ? "takie same\n" : "rozne\n");
}