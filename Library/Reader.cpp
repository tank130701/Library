#define _CRT_SECURE_NO_WARNINGS
#include "Reader.h"
#include <chrono>
#include <string>

Reader::Reader(std::string first_name, std::string last_name)
{
	this->first_name = first_name;
	this->last_name = last_name;
	//this->next = nullptr;
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	this->end_time = end_time;
}

Reader::Reader()
{
	end_time = 0;
	//this->next = nullptr;
}

void Reader::print_name()
{
	std::cout << "Reader last name: " << last_name << std::endl;
}

void Reader::print_fullinfo()
{
	std::cout << "Reader first name: " << first_name << std::endl;
	std::cout << "Reader last name: " << last_name << std::endl;
	std::cout << "Date of issue: " << std::ctime(&end_time) << std::endl;
}

