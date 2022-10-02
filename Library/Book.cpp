#include "Book.h"
#include <string>



void Book::print_fullinfo()
{
	std::cout << "Author: " << author << std::endl;
	std::cout << "Year of publication: " << year << std::endl;
	std::cout << "Publisher: " << pub << std::endl;
	std::cout << "Page count : " << pages_count << std::endl;
	std::cout << "===============================================" << std::endl;
}
Book::Book()
{
	year = 0;
	pages_count = 0;
}

Book::Book(std::string author, int year, std::string pub, int pages_count)
{
	this->author = author;
	this->year = year;
	this->pub = pub;
	this->pages_count = pages_count;
}
