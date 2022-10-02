#define _CRT_SECURE_NO_WARNINGS
#include "Reader.h"
#include <chrono>

Reader::Reader(std::string first_name, std::string last_name)
{
	this->first_name = first_name;
	this->last_name = last_name;
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
}

Reader::Reader()
{
}

void Reader::print_readerinfo()
{
	std::cout << "Reader first name: " << first_name <<std::endl;
	std::cout << "Reader last name: " << last_name << std::endl;
	std::cout << "Date of issue: " << std::ctime(&end_time) << std::endl;
}

void Readers_list::print()
{
	Reader_Node* print = this->first;
	while (print)
	{
		print->r->print_readerinfo();
		print = print->next;
	}

}

void Readers_list::append(Reader *a)
{
	Reader_Node* newnode = new Reader_Node(a);
	if (this->first == nullptr) {
		this->first = newnode;
		return;
	}

	Reader_Node* temp = this->first;
	while (temp->next != nullptr)
		temp = temp->next;
	newnode->next = nullptr;
	temp->next = newnode;
}

Reader_Node::Reader_Node(Reader *r)
{
	this->r = r;
	this->next = nullptr;
}
