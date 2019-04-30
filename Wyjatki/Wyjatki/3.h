#pragma once
#include<iostream>
#include<conio.h>

class AwariaSamochodu
{
public:

	virtual void info();
	virtual ~AwariaSamochodu();
};

class AwariaSilnika :public AwariaSamochodu
{
public:

	void info();
	virtual ~AwariaSilnika();
};



class AwariaSwiecy :public AwariaSilnika
{
public:

	virtual ~AwariaSwiecy();
	void info();
};

void AaAaAa(void);