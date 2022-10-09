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
		"10. Search by Book id\n"
		"11. Search by Book name\n"
		"12. Search by Book author\n"
		"0. Exit " << std::endl;
	int cmd;
	std::cout << "~$ ";
	std::cin >> cmd;
	return cmd;
};

void create_new_book(List<Book> *list)
{
	int year, count;
	std::string author, pub, name;
	std::cout << "Enter name of book: ";
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	std::cout << "Enter author of book: ";
	std::getline(std::cin, author);
	std::cout << "Enter year of publication: ";
	std::cin >> year;
	std::cout << "Enter publisher: ";
	std::cin >> pub;
	std::cout << "Enter count of pages: ";
	std::cin >> count;
	
	Book* a = new Book(name, author, year, pub, count);
	(*list).append(a);
}

void add_book_to_catalog(List<Book> *list, List<LibraryBook> *list1)
{

	list->print_names();
	std::cout << "Enter name of the book which you want to add to catalog: ";
	std::string name;
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	Node<Book>* temp = list->first;
	while (temp->next && temp->data->name != name)
	{
		temp = temp->next;
	}
	Book *a = temp->data;
	//temp = list.first;
	//while (temp->first)
	int total_count;
	std::cout << "Enter count of Books: ";
	std::cin >> total_count;
	LibraryBook* b = new LibraryBook(*a, total_count, total_count);
	list1->append(b);
}

void add_reader_to_library_book(List<LibraryBook> *list1)
{
	list1->print_names();
	std::cout << "Enter name of the book which you want to add readers: ";
	std::string name;
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	Node<LibraryBook> *temp = list1->first;

	while (temp->next && temp->data->name != name)
	{
		temp = temp->next;
	}
	temp->data->add_reader();
}

void rm_reader(List<LibraryBook>* list1)
{
	list1->print_names();
	std::cout << "Enter name of the book which you want to remove readers: ";
	std::string name;
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	Node<LibraryBook>* temp = list1->first;

	while (temp->next && temp->data->name != name)
	{
		temp = temp->next;
	}
	temp->data->remove_reader();
}

int LibraryBook::count = 0;


int main()
{
	List<Book> list;
	List<LibraryBook> list1;
	std::string name;
	std::string author;

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
			rm_reader(&list1);
			break;
		case 10:
			int id;
			std::cout << "Enter book id: ";
			std::cin >> id;
			list1.search(id);
			break;
		case 11:
			
			std::cout << "Enter the name of book: ";
			std::cin >> name;
			list1.search_by_name(name);
			break;
		case 12:
			
			std::cout << "Enter author of books: ";
			std::cin >> author;
			list1.search_by_author(author);
			break;
		};
		if (exit == true) break;
	};
}


