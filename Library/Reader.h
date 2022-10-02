#pragma once
#include <iostream>

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
	Reader r;
	Reader* next;
	Reader_Node(Reader* r);
};


class Readers_list
{
	Reader *first;
public:
	void print();
	void append();
};

