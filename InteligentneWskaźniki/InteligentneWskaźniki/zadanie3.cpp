#include "header.h"
#include <stdexcept>
#include <iostream>

#define DEBUG //odkomentuj by wypisywaæ na ekran wyniki wywo³añ poszczególnych metod

//zmodyfikuj klasê tak, by korzysta³a tylko z inteligentnych wskaŸników (nie u¿ywaj operatorów new i delete)
class DoublyLinkedList {
	struct Node {
		Data data;
		std::shared_ptr<Node> next;
		std::weak_ptr<Node> prev;
	};
	std::shared_ptr<Node> head;
	std::shared_ptr<Node> tail;
	size_t lsize;
public:
	DoublyLinkedList() : head(nullptr), tail(nullptr), lsize(0) {}
	~DoublyLinkedList() 
	{
		clear();
	}
	Data& at(size_t pos) {
		if (!(pos < lsize))
			throw std::out_of_range("DoublyLinkedList::at out of range");
		std::shared_ptr<Node> current = head;
		while (pos-- != 0) {
			current = current->next;
		}
		return current->data;
	}
	void push_front(const Data& data) {
		std::shared_ptr<Node> add = std::make_shared<Node>();
		add->data = data;
		add->next = head;
		if (head != nullptr)
			head->prev = add;
		head = add;
		if (tail == nullptr)
			tail = add;
		lsize++;
	}
	void push_back(const Data& data) {
		std::shared_ptr<Node> add = std::make_shared<Node>();
		add->data = data;
		add->prev = tail;
		if (tail != nullptr)
			tail->next = add;
		tail = add;
		if (head == nullptr)
			head = add;
		lsize++;
	}
	void insert(size_t pos, const Data& data) {
		if (!(pos < lsize))
			throw std::out_of_range("DoublyLinkedList::insert out of range");
		if (pos == 0)
			push_front(data);
		else {
			std::shared_ptr<Node> current = head;
			while (pos-- != 1) {
				current = current->next;
			}
			std::shared_ptr<Node> add = std::make_shared<Node>();
			add->data = data;
			add->next = current->next;
			add->prev = current;
			current->next->prev = add;
			current->next = add;
			lsize++;
		}
	}
	void pop_front() {
		if (head == nullptr)
			throw std::logic_error("DoublyLinkedList::pop_front list is empty");
		std::shared_ptr<Node> del = head;
		head = del->next;
		lsize--;
	}
	void pop_back() {
		if (tail == nullptr)
			throw std::logic_error("DoublyLinkedList::pop_back list is empty");
		std::shared_ptr<Node> del = tail;
		tail = del->prev.lock();
		lsize--;
	}
	void erase(size_t pos) {
		if (head == nullptr)
			throw std::logic_error("DoublyLinkedList::erase list is empty");
		if (pos == 0)
			pop_front();
		else if (pos == lsize - 1)
			pop_back();
		else {
			std::shared_ptr<Node> current = head;
			while (pos-- != 1) {
				current = current->next;
			}
			std::shared_ptr<Node> del = current->next;
			del->next->prev = current;
			current->next = del->next;
			lsize--;
		}
	}
	void clear() {
		while (lsize > 0) {
			pop_front();
		}
	}
	size_t size() {
		return lsize;
	}
};

//nie modyfikuj tej funkcji
int zadanie3() {
	DoublyLinkedList list;
	///test push_front()
	for (int i = 0; i < 8; i++)
		list.push_front(Data(rand() % 256));
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//test pop_front()
	for (int i = 0; i < 2; i++)
		list.pop_front();
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//test insert()
	for (int i = 0; i < 3; i++)
		list.insert(i * 2, rand() % 256);
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//test erase()
	for (int i = 0; i < 3; i++)
		list.erase(i * 3);
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	///test push_back()
	for (int i = 0; i < 3; i++)
		list.push_back(Data(rand() % 256));
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//test pop_back()
	for (int i = 0; i < 2; i++)
		list.pop_back();
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//clear()
	list.clear();
	return 0;
}