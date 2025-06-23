#ifndef _PHONEBOOK_
	#define _PHONEBOOK_

	#include <iostream>
	#include <string>
	#include <cstdlib>
	#include <iomanip>
	#include <sstream>
	#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _list[8];
		int _i;
		int _nb_contact;
	public:
		PhoneBook();
		~PhoneBook();
		void add_contact(Contact contact);
		void check_list();
		void print_element(std::string element);
		void choose_contact();
		void display_contact(int index);
		int get_nb_contact();
};

#endif