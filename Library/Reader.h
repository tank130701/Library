#pragma once
#include <iostream>
#include <ctime>
class Reader
{
	std::string first_name;
	std::string last_name;
	std::time_t end_time;
	Reader* next;
public:
	Reader(std::string first_name, std::string last_name);
	Reader();
	void print_readerinfo();
};

class Reader_Node
{
public:
	Reader *r;
	Reader_Node* next;
	Reader_Node(Reader* r);
};


class Readers_list
{
	Reader_Node *first;
public:
	void print();
	void append(Reader* a);
	Readers_list();
};

