#include "LibraryBook.h"



void LibraryBook::print_fullinfo()
{
	std::cout << "Author: " << author << std::endl;
	std::cout << "Year of publication: " << year << std::endl;
	std::cout << "Publisher: " << pub << std::endl;
	std::cout << "Page count : " << pages_count << std::endl;
	std::cout << "Book id : " << book_id << std::endl;
	std::cout << "Total books count : " << total_count << std::endl;
	std::cout << "Avilable books count : " << avilable_book_count << std::endl;
	std::cout << "===============================================" << std::endl;
}

LibraryBook::LibraryBook()
{
	book_id = 0;
	total_count = 0;
	avilable_book_count = 0;
}

LibraryBook::LibraryBook(std::string author, int year, std::string pub, int page_count, int total_count, int avilable_book_count):Book(author, year, pub, page_count)
{
	this->total_count = total_count;
	this->avilable_book_count = avilable_book_count;
	book_id = rand();
	count++;
}