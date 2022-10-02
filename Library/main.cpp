#include <iostream>
#include <string>
#include "Book.h"
#include "LibraryBook.h"
#include "List.h"

int menu() {
	std::cout << "\n1. Create Book\n"
		"2. Delete Book\n"
		"3. Append book to catalog\n"
		"4. Remove book from catalog\n"
		"5. Print info about book by id\n"
		"0. Exit " << std::endl;
	int cmd;
	std::cout << "~$ ";
	std::cin >> cmd;
	return cmd;
};

void create_new_book(List *list)
{
	int year, count;
	std::string author, pub;
	std::cout << "Enter author of book: " << std::endl;
	std::getline(std::cin, author);
	std::getline(std::cin, author);
	std::cout << "Enter year of publication: " << std::endl;
	std::cin >> year;
	std::cout << "Enter publisher: " << std::endl;
	std::cin >> pub;
	std::cout << "Enter count of pages" << std::endl;
	std::cin >> count;
	
	Book* a = new Book(author, year, pub, count);
	//LibraryBook* b = new LibraryBook(author, year, pub, count, total_count, total_count);
	(*list).append(a);
}

void add_book_to_catalog(List *list, List1 *list1)
{
	int total_count;
	std::cout << "Enter count of Books" << std::endl;
	std::cin >> total_count;
}

int LibraryBook::count = 0;


int main()
{
	List list;
	List1 list1;
	while (true)
	{
		int cmd = menu();
		bool exit = false;
		switch (cmd) {
		case 0:
			exit = true;
			break;
		case 1:
			create_new_book(&list);
			break;
		case 5:
			list.print();
			break;
		};
		if (exit == true) break;
	};
}


