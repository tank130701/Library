#include "List.h"
#include "Book.h"
#include "LibraryBook.h"
#include <string>

void List::append(Book* a)
{
	Node* newnode = new Node(a);
	if (this->first == nullptr) {
		this->first = newnode;
		return;
	}

	Node* temp = this->first;
	while (temp->next != nullptr)
		temp = temp->next;
	newnode->next = nullptr;
	temp->next = newnode;
}

void List::delete_node()
{
	print_names();
	std::string name;
	std::cout << "Enter the title of book which you want to delete: " << std::endl;
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	Node *temp = this->first;
	while (temp->next && temp->a->name != name)
	{
		
		temp = temp->next;
	}
	this->first = temp->next;
	delete temp;
}

void List::print()
{
	//if (this->next == nullptr)
	//	a.print_fullinfo();
	//else
	Node* print = this->first;
	if (print == nullptr)
		std::cout << "List is Empty" << std::endl;
	while (print)
	{
		print->a->print_fullinfo();
		print = print->next;
	}
}

void List::print_names()
{
	Node* print = this->first;
	if (print == nullptr)
		std::cout << "List is Empty" << std::endl;
	while (print)
	{
		print->a->print_name();
		print = print->next;
	}
}

List::List()
{
	this->first = nullptr;
}

Node::Node()
{
	this->a = new Book;
	this->next = nullptr;
}

Node::Node(Book* a)
{
	this->a = a;
	this->next = nullptr;
}

Node1::Node1(LibraryBook *a)
{
	this->a = a;
	this->next = nullptr;
}

void List1::append(LibraryBook *a)
{
	Node1* newnode = new Node1(a);
	if (this->first == nullptr) {
		this->first = newnode;
		return;
	}

	Node1* temp = this->first;
	while (temp->next != nullptr)
		temp = temp->next;
	newnode->next = nullptr;
	temp->next = newnode;
}

void List1::delete_node()
{
	print_names();
	std::string name;
	std::cout << "Enter the title of book which you want to delete: " << std::endl;
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	Node1* temp = this->first;
	while (temp->a->name != name)
	{
		temp = temp->next;
	}
	this->first = temp->next;
	delete temp;

}

void List1::print()
{
	Node1* print = this->first;
	if (print == nullptr)
		std::cout << "List is Empty" << std::endl;
	while (print)
	{
		print->a->print_fullinfo();
		print = print->next;
	}
}

void List1::print_names()
{
	Node1* print = this->first;
	if (print == nullptr)
		std::cout << "List is Empty" << std::endl;
	while (print)
	{
		print->a->print_name();
		print = print->next;
	}
}

List1::List1()
{
	this->first = nullptr;
}
