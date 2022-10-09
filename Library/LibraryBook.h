#pragma once
#include "Book.h"
#include "List.h"
#include "Reader.h"

class LibraryBook :
    public Book
{
public:
	int avilable_book_count;
	int total_count;
	static int count;
	List<Reader> *list;
	int book_id;
	void add_reader();
	void remove_reader();
	void print_fullinfo();
	LibraryBook();
	LibraryBook(const Book &a, int total_count, int avilable_book_count);
	LibraryBook(std::string name, std::string author, int year, std::string pub, int page_count, int total_count, int avilable_book_count);
};

