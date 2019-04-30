#include "header.h"
#include <stdexcept>
#include <iostream>



//#define DEBUG //odkomentuj by wypisywać na ekran wyniki wywo³añ poszczególnych metod

//zmodyfikuj klasê tak, by usun¹æ wycieki pamiêci (metody pop_front(), erase() i clear())
class LinkedList_a {
	struct Node {
		Data data;
		Node* next;
	};
	Node* head;
	size_t lsize;
public:
	LinkedList_a() : head(nullptr), lsize(0) {}
	~LinkedList_a() {
		clear();
	}
	Data& at(size_t pos) {
		if (!(pos < lsize))
			throw std::out_of_range("LinkedList::at out of range");
		Node* current = head;
		while (pos-- != 0) {
			current = current->next;
		}
		return current->data;
	}
	void push_front(const Data& data) {
		Node* add = new Node;
		add->data = data;
		add->next = head;
		head = add;
		lsize++;
	}
	void insert(size_t pos, const Data& data) {
		if (!(pos < lsize))
			throw std::out_of_range("LinkedList::insert out of range");
		if (pos == 0)
			push_front(data);
		else {
			Node* current = head;
			while (pos-- != 1) {
				current = current->next;
			}
			Node* add = new Node;
			add->data = data;
			add->next = current->next;
			current->next = add;
			lsize++;
		}
	}
	void pop_front() {
		
		if (head == nullptr)
			throw std::logic_error("LinkedList::pop_front list is empty");
		Node* tmp = head;
		head = head->next;
		delete tmp;
		lsize--;
	}
	void erase(size_t pos) {

		if (head == nullptr)
			throw std::logic_error("LinkedList::erase list is empty");
		if (pos == 0)
			pop_front();
		else {
			Node* current = head;
			while (pos-- != 1) {
				current = current->next;
			}
			Node* tmp = current->next;
			current->next = current->next->next;
			delete tmp;
			lsize--;
		}
	}
	void clear() 
	{
		Node* current = head;
		while (current != NULL)
		{
			head = current;
			current = current->next;
			delete head;
		}
		head = nullptr;
	}
	size_t size() {
		return lsize;
	}
};

//zmodyfikuj klasê tak, by korzysta³a tylko z inteligentnych wskaŸników (nie u¿ywaj operatorów new i delete)
class LinkedList_b {
	struct Node {
		Data data;
		std::shared_ptr<Node> next;
	};
	std::shared_ptr<Node> head;
	size_t lsize;
public:
	LinkedList_b() : head(nullptr), lsize(0) {}
	~LinkedList_b() {
		clear();
	}
	Data& at(size_t pos) {
		if (!(pos < lsize))
			throw std::out_of_range("LinkedList::at out of range");
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
		head = add;
		lsize++;
	}
	void insert(size_t pos, const Data& data) {
		if (!(pos < lsize))
			throw std::out_of_range("LinkedList::insert out of range");
		if (pos == 0)
			push_front(data);
		else {
			std::shared_ptr<Node> current = head;
			while (pos-- != 1) {
				current = current->next;
			}
			std::shared_ptr<Node> add = std::make_shared <Node>();
			add->data = data;
			add->next = current->next;
			current->next = add;
			lsize++;
		}
	}
	void pop_front() {
		if (head == nullptr)
			throw std::logic_error("LinkedList::pop_front list is empty");
		head = head->next;
		lsize--;
	}
	void erase(size_t pos) {
		if (head == nullptr)
			throw std::logic_error("LinkedList::erase list is empty");
		if (pos == 0)
			pop_front();
		else {
			std::shared_ptr<Node> current = head;
			while (pos-- != 1) {
				current = current->next;
			}
			current->next = current->next->next;
			lsize--;
		}
	}
	void clear() {
		head = nullptr;
	}
	size_t size() {
		return lsize;
	}
};

//nie modyfikuj tej funkcji
int zadanie2a() {
	LinkedList_a list;
#ifdef DEBUG
	std::cout << "  a)\n";
#endif
	///push_front()
	for (unsigned int i = 0; i < 8; i++)
		list.push_front(Data(rand() % 256));
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//pop_front()
	for (unsigned int i = 0; i < 2; i++)
	list.pop_front();
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//insert()
	for (unsigned int i = 0; i < 3; i++)
		list.insert(i * 2, rand() % 256);
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//erase()
	for (unsigned int i = 0; i < 3; i++)
		list.erase(i * 3);
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//clear()
	list.clear();
	return 0;
}

//nie modyfikuj tej funkcji
int zadanie2b() {
	LinkedList_b list;
#ifdef DEBUG
	std::cout << "  b)\n";
#endif
	///push_front()
	for (unsigned int i = 0; i < 8; i++)
		list.push_front(Data(rand() % 256));
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//pop_front()
	for (unsigned int i = 0; i < 2; i++)
		list.pop_front();
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//insert()
	for (unsigned int i = 0; i < 3; i++)
		list.insert(i * 2, rand() % 256);
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//erase()
	for (unsigned int i = 0; i < 3; i++)
		list.erase(i * 3);
#ifdef DEBUG
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << (short)list.at(i).data << '\t';
	std::cout << std::endl;
#endif
	//clear()
	list.clear();
	return 0;
}