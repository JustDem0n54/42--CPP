#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_i = 0;
	_nb_contact = 0;
}

PhoneBook::~PhoneBook()
{
}

int	PhoneBook::get_nb_contact()
{
	return this->_nb_contact;
}

void PhoneBook::add_contact(Contact contact)
{
	this->_list[this->_i] = contact;
	this->_i = (this->_i + 1) % 8;
	if (this->_nb_contact < 8)
		this->_nb_contact++;
}

void PhoneBook::print_element(std::string element)
{
	if (element.length() > 10)
		std::cout << std::setw(10) << element.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << element;
}

void PhoneBook::check_list()
{
	int i = 0;

	while(i < 8 && !this->_list[i].get_first_name().empty())
	{
		std::cout << std::setw(10) << i + 1;
		std::cout << "|";
		this->print_element(this->_list[i].get_first_name());
		std::cout << "|";
		this->print_element(this->_list[i].get_last_name());
		std::cout << "|";
		this->print_element(this->_list[i].get_nickname());
		std::cout << std::endl;
		i++;
	}
	std::cout << "\n";
}

void PhoneBook::display_contact(int index)
{
	std::cout << this->_list[index-1].get_first_name() << std::endl;
	std::cout << this->_list[index-1].get_last_name() << std::endl;
	std::cout << this->_list[index-1].get_nickname() << std::endl;
	std::cout << this->_list[index-1].get_phone_number() << std::endl;
	std::cout << this->_list[index-1].get_darkest_secret() << std::endl;
}

void PhoneBook::choose_contact()
{
	std::string input;
	int index;

	if (this->_list[0].get_first_name().empty())
	{
		std::cout << "You don't have any contacts. " << "Start to ADD some.\n" << std::endl;
		return ;
	}
	std::cout << "Choose a contact index:";
	while (1)
	{
		int nb_contact = this->get_nb_contact();
		std::getline(std::cin, input);
		std::stringstream convertion(input);
		if (!(convertion >> index))
			std::cout << "Have to be a number:";
		else if (index <= nb_contact && index > 0)
		{
			this->display_contact(index);
			std::cout << "\n";
			return ;
		}
		else
		{
			if (nb_contact == 1)
				std::cout << "Index should be 1:";
			else
				std::cout << "Need a number between 1 and " << nb_contact << ":";
		}
	}
}
