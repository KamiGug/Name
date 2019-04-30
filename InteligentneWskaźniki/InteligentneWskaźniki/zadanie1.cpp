#include "header.h"

bool checkSomething2(std::unique_ptr<Data[]> &data);

//zadanie 1 a)
//zmodyfikuj funkcjê tak by usun¹æ wycieki pamiêci bez u¿ycia inteligentnych wskaŸników
int zadanie1a() 
{
	int n = 4;
	Data* data = getData(n);
	switch (data[0].data) 
	{
	case 0:
		delete[] data;
		return 0;
	case 1:
		if (data[1].data == 0)
		{
			delete[] data;
			return -1;
		}
		else 
		if (data[1].data < 128)
		{
			delete[] data;
			return 1;
		}
		else 
		{
			if (data[11].data < 128)
			{
				delete[] data;
				return 11;
			}	
			else
			{
				delete[] data;
				return 21;
			}
				
		}
	case 2:
		if (checkSomething(data))
		{
			delete[] data;
			return 2;
		}
		else
		{
			delete[] data;
			return -2;
		}
			
	case 3:
		Global::old_ptr = data;
		return 3;
	case 4:
		Global::unq_ptr = std::unique_ptr<Data[]>(data);
		return 4;
	default:
		delete[] data;
		return 127;
	}
	delete[] data;
	return -128;
}

//zadanie 1 b)
//zmodyfikuj funkcjê tak by usun¹æ wycieki pamiêci z u¿yciem inteligentnych wskaŸników (nie operatorów u¿ywaj new i delete)
int zadanie1b() 
{
	int n = 4;
	std::unique_ptr<Data[]> data(getData(n));
	switch (data[0].data) 
	{
	case 0:
		return 0;
	case 1:
		if (data[1].data == 0)
			return -1;
		else if (data[1].data < 128)
			return 1;
		else {
			if (data[11].data < 128)
				return 11;
			else
				return 21;
		}
	case 2:
		if (checkSomething2(data))
			return 2;
		else
			return -2;
	case 3:
		Global::old_ptr = data.release();
		return 3;
	case 4:
		Global::unq_ptr = move(data);
		return 4;
	default:
		return 127;
	}
	return -128;
}

//zadanie 1 c)
//zmodyfikuj funkcjê tak, by przyjmowa³a inteligentny wskaŸnik unique_ptr i mog³a zostaæ zastosowana w instrukcji warunkowej w zadaniu 1b w case 2 w postaci checkSomething2(data)
bool checkSomething2(std::unique_ptr<Data[]> &data) {
	return data[1].data % 2;
}