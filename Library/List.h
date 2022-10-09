#pragma once
#include "Book.h"
#include "LibraryBook.h"
#include "Reader.h"
#include <string>
#include <iostream>

template<typename T>
class Node
{
public:
	Node* next;
	T *data;
	Node(T *data);
};

template<typename T>
class List
{
	
public:
	
	List();
	~List();
	Node<T>* first;
	void search(int id);
	void search_by_name(std::string name);
	void search_by_author(std::string author);
	void check_readers();
	void append(T *data);
	void delete_node();
	void delete_reader();
	void print();
	void print_names();
};


template<typename T>
inline void List<T>::search(int id)
{
	bool flag = false;
	Node<T>* temp = this->first;
	if (temp->next == nullptr && temp->data->book_id == id)
		temp->data->print_fullinfo();
	else if (temp->next == nullptr && temp->data->book_id != id)
		std::cout << "Book with this id does not exist." << std::endl;
	else
	{ 
	while (temp->next)
	{
		if (temp->data->book_id == id)
		{
			flag = true; break;
		}
		temp = temp->next;
	}
	if (flag == true)
		temp->data->print_fullinfo();
	else
		std::cout << "Book with this id does not exist." << std::endl;
	}
}

template<typename T>
inline void List<T>::search_by_name(std::string name)
{
	bool flag = false;
	Node<T>* temp = this->first;
	if (temp->next == nullptr && temp->data->name == name)
		temp->data->print_fullinfo();
	else if (temp->next == nullptr && temp->data->name != name)
		std::cout << "Book with this name does not exist." << std::endl;
	else
	{
		while (temp->next)
		{
			if (temp->data->name == name)
			{
				flag = true; break;
			}
			temp = temp->next;
		}
		if (flag == true)
			temp->data->print_fullinfo();
		else
			std::cout << "Book with this name does not exist." << std::endl;
	}
}

template<typename T>
inline void List<T>::search_by_author(std::string author)
{
	bool flag = false;
	Node<T>* temp = this->first;
	List<T>* search = new List<T>;
	if (temp->next == nullptr && temp->data->author == author)
		temp->data->print_fullinfo();
	else if (temp->next == nullptr && temp->data->author != author)
		std::cout << "Books from this author does not exist." << std::endl;
	else
	{
		while (temp->next)
		{
			if (temp->data->author == author)
			{
				search->append(temp->data);
				flag = true;
			}
			temp = temp->next;
		}
		if (flag == true)
			search->print();
		else
			std::cout << "Books from this author does not exist." << std::endl;
	}
}

template<typename T>
inline void List<T>::check_readers()
{

}

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
	std::cout << "Enter the title of book which you want to delete: ";
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
void List<T>::delete_reader()
{
	print_names();
	std::string name;
	std::cout << "Enter the Last name of reader which you want to delete: ";
	std::getline(std::cin, name);
	Node<T>* temp = this->first;
	while (temp->next && temp->data->last_name != name)
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
		std::cout << "List is empty" << std::endl;
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
		std::cout << "List is empty" << std::endl;
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

