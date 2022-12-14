#include "LibraryBook.h"



void LibraryBook::add_reader()
{
	std::string firstname, lastname;
	std::cout << "Enter Reader's first name: ";
	std::cin >> firstname;
	std::cout << "Enter Reader's last name: ";
	std::cin >> lastname;
	Reader *newreader;
	newreader = new Reader(firstname, lastname);
	this->list->append(newreader);
	avilable_book_count--;
}

void LibraryBook::remove_reader()
{
	this->list->delete_reader();
	avilable_book_count++;
}



void LibraryBook::print_fullinfo()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Author: " << author << std::endl;
	std::cout << "Year of publication: " << year << std::endl;
	std::cout << "Publisher: " << pub << std::endl;
	std::cout << "Page count : " << pages_count << std::endl;
	std::cout << "Book id : " << book_id << std::endl;
	std::cout << "Total books count : " << total_count << std::endl;
	std::cout << "Avilable books count : " << avilable_book_count << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "Readers list: " << std::endl;
	this->list->print();
	std::cout << "===============================================" << std::endl;
}

LibraryBook::LibraryBook()
{
	list = new List<Reader>;
	book_id = 0;
	total_count = 0;
	avilable_book_count = 0;
}

LibraryBook::LibraryBook(const Book& a, int total_count, int avilable_book_count)
{
	name = a.name;
	author = a.author;
	year = a.year;
	pub = a.pub;
	pages_count = a.pages_count;
	book_id = rand();
	count++;
	list = new List<Reader>;
	this->total_count = total_count;
	this->avilable_book_count = avilable_book_count;
}

LibraryBook::LibraryBook(std::string name, std::string author, int year, std::string pub, int page_count, int total_count, int avilable_book_count):Book(name, author, year, pub, page_count)
{
	list = nullptr;
	this->total_count = total_count;
	this->avilable_book_count = avilable_book_count;
	book_id = rand();
	count++;
}