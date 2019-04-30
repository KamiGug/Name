#pragma once
#include <memory>



class Data {
	static int allocated;
public:
	signed char data;
	Data();
	Data(int);
	~Data();
	static int getAllocated();
};

class Global {
public:
	static Data* old_ptr;
	static std::unique_ptr<Data[]> unq_ptr;
	static void clear();
};
Data* getData(int);
bool checkSomething(Data*);

int zadanie1a();
int zadanie1b();
int zadanie2a();
int zadanie2b();
int zadanie3();