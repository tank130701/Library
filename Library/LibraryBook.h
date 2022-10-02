#pragma once
#include "Book.h"
#include "Reader.h"

class LibraryBook :
    public Book
{
	int book_id;
	int avilable_book_count;
	int total_count;
	static int count;
	Readers_list *list;
public:
	void add_reader();
	void print_fullinfo();
	LibraryBook();
	LibraryBook(std::string author, int year, std::string pub, int page_count, int total_count, int avilable_book_count);
};

