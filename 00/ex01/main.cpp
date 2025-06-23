#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string	get_info()
{
	std::string	line;
	
	while (line.empty())
	{
		std::getline(std::cin, line);
		if (!line.empty())
			return (line);
		else
			std::cout << "You can't let a blank :";
	}
	return line;
}

Contact	make_contact()
{
	Contact contact;
	std::string pipi;
	std::cout << "First Name:";
	contact.set_first_name(get_info());
	std::cout << "Last Name:";
	contact.set_last_name(get_info());
	std::cout << "Nickname:";
	contact.set_nickname(get_info());
	std::cout << "Phone Number:";
	contact.set_phone_number(get_info());
	std::cout << "Darkest Secrect:";
	contact.set_darkest_secret(get_info());
	std::cout << "\n";
	return (contact);
}

void	choose_function(PhoneBook& book)
{
	std::string funct;
	std::getline(std::cin, funct);
	if (funct == "ADD")
	{
		std::cout << "\n";
		book.add_contact(make_contact());
	}	
	else if (funct == "SEARCH")
	{
		std::cout << "\n";
		book.check_list();
		book.choose_contact();
	}
	else if (funct == "EXIT")
		exit(0);
}

int main()
{
	PhoneBook book;
	while (1)
	{	
		std::cout << "You have 3 choices : \n" 
			<< "'ADD' to register a new contact.\n"
			<< "'SEARCH' to display the contact asked.\n" 
			<< "'EXIT' to leave the PhoneBook." << std::endl;
		choose_function(book);
	}
	
}
