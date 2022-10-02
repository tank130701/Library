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
	this->a = a;
	this->next = nullptr;
}

void Reader::print_readerinfo()
{
	std::cout << "Reader first name: " << first_name <<std::endl;
	std::cout << "Reader last name: " << last_name << std::endl;
	std::cout << "Date of issue: " << std::ctime(&end_time) << std::endl;
}

void Readers_list::print()
{

}

void Readers_list::append(Reader *a)
{
	Reader* newnode = new Reader(a);
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
