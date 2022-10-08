#pragma once
#include "Book.h"
#include "LibraryBook.h"
#include <string>


template<typename T>
class Node
{
public:
	Node* next;
	T *data;
	Node(T *data);
	Node(T data = T(), Node* next = nullptr);
	//Node(T data, Node* next = nullptr);

};

template<typename T>
class List
{
	
public:
	
	List();
	~List();
	Node<T>* first;
	void append(T *data);
	void delete_node();
	void print();
	void print_names();


};


template<typename T>
void List<T>::append(T* data)
{
	Node<T>* newnode = new Node<T>(data);
	if (this->first == nullptr) {
		this->first = newnode;
		return;
	}

	Node<T>* temp = this->first;
	while (temp->next != nullptr)
		temp = temp->next;
	newnode->next = nullptr;
	temp->next = newnode;
}

template<typename T>
void List<T>::delete_node()
{
	print_names();
	std::string name;
	std::cout << "Enter the title of book which you want to delete: " << std::endl;
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	Node<T>* temp = this->first;
	while (temp->next && temp->data->name != name)
	{

		temp = temp->next;
	}
	this->first = temp->next;
	delete temp;
}

template<typename T>
void List<T>::print()
{
	//if (this->next == nullptr)
	//	a.print_fullinfo();
	//else
	Node<T>* print = this->first;
	if (print == nullptr)
		std::cout << "List is Empty" << std::endl;
	while (print)
	{
		print->data->print_fullinfo();
		print = print->next;
	}
}

template<typename T>
void List<T>::print_names()
{
	Node<T>* print = this->first;
	if (print == nullptr)
		std::cout << "List is Empty" << std::endl;
	while (print)
	{
		print->data->print_name();
		print = print->next;
	}
}

template<typename T>
List<T>::List()
{
	this->first = nullptr;
}

template<typename T>
List<T>::~List()
{

}


template<typename T>
inline Node<T>::Node(T* data)
{
	this->data = data;
	this->next = nullptr;
}

template<typename T>
inline Node<T>::Node(T data, Node* next)
{
	this->data = data;
	this->next = next;
}
