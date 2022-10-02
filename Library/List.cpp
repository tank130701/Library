#include "List.h"
#include "Book.h"
#include "LibraryBook.h"

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

void List::print()
{
	//if (this->next == nullptr)
	//	a.print_fullinfo();
	//else
	Node* print = this->first;
	while (print)
	{
		print->a->print_fullinfo();
		print = print->next;
	}
}

List::List()
{
	this->first = nullptr;
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

void List1::print()
{
	Node1* print = this->first;
	while (print)
	{
		print->a->print_fullinfo();
		print = print->next;
	}
}

List1::List1()
{
}
