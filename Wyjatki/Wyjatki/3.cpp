#include "pch.h"
#include "3.h"

void AwariaSamochodu::info()
{
	std::cout << "Awaria Samochodu" << std::endl;
}

AwariaSamochodu::~AwariaSamochodu()
{
}

void AwariaSilnika::info()
{
	std::cout << "Awaria Silnika" << std::endl;
}

AwariaSilnika::~AwariaSilnika()
{
}

AwariaSwiecy::~AwariaSwiecy()
{
}

void AwariaSwiecy::info()
{
	std::cout << "Awaria Swiecy" << std::endl;
}

void AaAaAa(void)
{
	std::cout << "3.\n";
	AwariaSamochodu* tab[9];

	for (int i = 0; i < 9;)
	{
		tab[i] = new AwariaSamochodu();
		i++;
		tab[i] = new AwariaSilnika();
		i++;
		tab[i] = new AwariaSwiecy();
		i++;
	}

	for (int i = 0; i < 9; i++)
	{
		try
		{
			if (typeid(*tab[i]).name() == typeid(AwariaSamochodu).name())
			{
				throw AwariaSamochodu();
			}

			if (typeid(*tab[i]).name() == typeid(AwariaSilnika).name())
			{
				throw AwariaSilnika();
			}

			if (typeid(*tab[i]).name() == typeid(AwariaSwiecy).name())
			{
				throw AwariaSwiecy();
			}
		}
		catch (AwariaSilnika e) //wazna kolejnosc blokow catch
		{
			e.info();
		}
		catch (AwariaSwiecy e)
		{
			e.info();
		}
		catch (AwariaSamochodu e)
		{
			e.info();
		}
		catch (...)
		{
			std::cout << "Blok catch, ktory lapie wszystkie wyjatki" << std::endl;
		}
	}

	std::cout << "--------------------------------------------------" << std::endl;

	for (int i = 0; i < 9; i++)
	{
		try
		{
			try
			{
				try
				{
					if (typeid(*tab[i]).name() == typeid(AwariaSamochodu).name())
					{
						throw AwariaSamochodu();
					}
				}
				catch (AwariaSamochodu  e)
				{
					e.info();
				}

				if (typeid(*tab[i]).name() == typeid(AwariaSilnika).name())
				{
					throw AwariaSilnika();
				}
			}
			catch (AwariaSilnika  e)
			{
				e.info();
			}

			if (typeid(*tab[i]).name() == typeid(AwariaSwiecy).name())
			{
				throw AwariaSwiecy();
			}
		}
		catch (AwariaSwiecy  e)
		{
			e.info();
		}
	}

	for (int i = 0; i < 9; i++)
	{
		delete tab[i];
	}
}
