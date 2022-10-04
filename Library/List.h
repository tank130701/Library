#pragma once
#include "Book.h"
#include "LibraryBook.h"

class Node
{
public:
	Book* a;
	Node* next;
	Node();
	Node(Book* a);
};

class List
{	
public:
	Node* first;
	void append(Book* a);
	void delete_node();
	void print();
	void print_names();
	List();
};

class Node1
{
public:
	LibraryBook* a;
	Node1* next;
	Node1(LibraryBook* a);
};

class List1
{
public:
	Node1* first;
	void append(LibraryBook* a);
	void delete_node();
	void print();
	void print_names();
	List1();
};
