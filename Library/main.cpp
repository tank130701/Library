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
		"6. Print Books list\n"
		"7. Print Library Books list\n"
		"8. Add reader to Library book\n"
		"9. Remove reader from library book\n"
		"0. Exit " << std::endl;
	int cmd;
	std::cout << "~$ ";
	std::cin >> cmd;
	return cmd;
};

void create_new_book(List *list)
{
	int year, count;
	std::string author, pub, name;
	std::cout << "Enter name of book: " << std::endl;
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	std::cout << "Enter author of book: " << std::endl;
	std::getline(std::cin, author);
	std::cout << "Enter year of publication: " << std::endl;
	std::cin >> year;
	std::cout << "Enter publisher: " << std::endl;
	std::cin >> pub;
	std::cout << "Enter count of pages" << std::endl;
	std::cin >> count;
	
	Book* a = new Book(name, author, year, pub, count);
	(*list).append(a);
}

void add_book_to_catalog(List *list, List1 *list1)
{

	list->print_names();
	std::cout << "Enter name of the book which you want to add to catalog" << std::endl;
	std::string name;
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	Node* temp = list->first;
	while (temp->next && temp->a->name != name)
	{
		temp = temp->next;
	}
	Book *a = temp->a;
	//temp = list.first;
	//while (temp->first)
	int total_count;
	std::cout << "Enter count of Books" << std::endl;
	std::cin >> total_count;
	LibraryBook* b = new LibraryBook(*a, total_count, total_count);
	list1->append(b);
}

void add_reader_to_library_book(List1 *list1)
{
	list1->print_names();
	std::cout << "Enter name of the book which you want to add readers" << std::endl;
	std::string name;
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	Node1 *temp = list1->first;

	while (temp->next && temp->a->name != name)
	{
		temp = temp->next;
	}
	temp->a->add_reader();
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
		case 2:
			list.delete_node();
			break;
		case 3:
			add_book_to_catalog(&list, &list1);
			break;
		case 4:
			list1.delete_node();
			break;
		case 5:
			//list.print();
			break;
		case 6:
			list.print();
			break;
		case 7:
			list1.print();
			break;
		case 8:
			add_reader_to_library_book(&list1);
			break;
		case 9:
			break;
		};
		if (exit == true) break;
	};
}


