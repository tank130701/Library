#pragma once
#include "Book.h"
#include "LibraryBook.h"

class Node
{
public:
	Book* a;
	Node* next;
	Node(Book* a);
};

class List
{
	Node* first;
public:
	void append(Book* a);
	void print();
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
	Node1* first;
public:
	void append(LibraryBook* a);
	void print();
	List1();
};