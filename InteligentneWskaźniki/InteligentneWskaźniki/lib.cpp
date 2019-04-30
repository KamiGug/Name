#include "header.h"
#include <cstdlib>

int Data::allocated = 0;

Data::Data() {
	allocated++;
}
Data::Data(int _data) : data(_data){
	allocated++;
}
Data::~Data() {
	allocated--;
}

int Data::getAllocated() {
	return allocated;
}


Data* Global::old_ptr = nullptr;
std::unique_ptr<Data[]> Global::unq_ptr;
void Global::clear() {
	delete[] old_ptr;
	old_ptr = nullptr;
	unq_ptr.reset();
}

Data* getData(int size) {
	Data* ret = new Data[size];
	for (int i = 0; i < size; i++) {
		ret[i].data = rand() % 8;
	}
	return ret;
}

bool checkSomething(Data* data) {
	return data[1].data % 2;
}