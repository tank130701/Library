#pragma once
#include <iostream>
#include <ctime>
class Reader
{
public:
	std::string first_name;
	std::string last_name;
	std::time_t end_time;
	//Reader* next;
	Reader(std::string first_name, std::string last_name);
	Reader();
	void print_name();
	void print_fullinfo();
	
};


