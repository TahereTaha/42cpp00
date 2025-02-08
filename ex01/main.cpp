/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:12:25 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/08 14:13:47 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string	to_string(size_t num)
{
	std::stringstream out;
	out << num;
	return (out.str());
}

Contact	make_new_contact(void)
{
	static size_t	i;
	Contact contact;
	std::string	str1;

	contact.initialized = 1;
	str1 = "first_name ";
	str1 += to_string(i);
	contact.set_first_name(str1);
	str1 = "last_name ";
	str1 += to_string(i);
	contact.set_last_name(str1);
	str1 = "nicname ";
	str1 += to_string(i);
	contact.set_nicname(str1);
	str1 = "phone_number ";
	str1 += to_string(i);
	contact.set_phone_number(str1);
	str1 = "darkest_secret ";
	str1 += to_string(i);
	contact.set_darkest_secret(str1);
	i++;
	return (contact);
}

void	print_contact(Contact contact)
{
	if (!contact.initialized)
	{
		std::cout << "nothing" << std::endl;
		return ;
	}
	std::cout << "first_name: " << contact.get_first_name() << std::endl;
	std::cout << "last_name: " << contact.get_last_name() << std::endl;
	std::cout << "nicname: " << contact.get_nicname() << std::endl;
	std::cout << "phone_number: " << contact.get_phone_number() << std::endl;
	std::cout << "darkest_secret: " << contact.get_darkest_secret() << std::endl;
}

std::string	expand_tabs(std::string str)
{
	std::string	return_string = "";

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '\t')
			return_string += "    ";
		else
			return_string += str[i];
	}
	return (return_string);
}

void	print_string_in_box(std::string str1)
{
	std::string	str;
	str = expand_tabs(str1);
	if (str.length() <= 10)
	{
		size_t	i;

		i = 10 - str.length();
		while (i)
		{
			std::cout << " ";
			i--;
		}
	}
	std::string sub;
	if (str.length() <= 10)
		sub = str.substr(0, 10);
	else
		sub = str.substr(0, 9) + ".";
	std::cout << sub;
}

void	print_contact_short(Contact contact, size_t	i)
{
	std::cout << "|";
	print_string_in_box(to_string(i));
	std::cout << "|";
	print_string_in_box(contact.get_first_name());
	std::cout << "|";
	print_string_in_box(contact.get_last_name());
	std::cout << "|";
	print_string_in_box(contact.get_nicname());
	std::cout << "|";
	std::cout << std::endl;
}

void	print_table_colums(void)
{
	std::cout << "|";
	print_string_in_box("index");
	std::cout << "|";
	print_string_in_box("first name");
	std::cout << "|";
	print_string_in_box("last name");
	std::cout << "|";
	print_string_in_box("nickname");
	std::cout << "|";
	std::cout << std::endl;
}

void	print_phone_book(PhoneBook phone_book)
{
	size_t	i;

	std::cout << "\nthis is the phonebook\n" << std::endl;
	print_table_colums();
	i = 0;
	while (i < CONTACT_ARRAY_SIZE && phone_book.get_contact(i).initialized)
	{
		print_contact_short(phone_book.get_contact(i), i);
		i++;
	}
}

int		is_num(std::string num)
{
	size_t	i;

	if (num.length() == 0)
		return (0);
	i = 0;
	while (i < num.length())
	{
		if (std::isdigit(num[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_correct_index(size_t	i, PhoneBook phone_book)
{
	if (i > CONTACT_ARRAY_SIZE - 1)
		return (0);
	if (phone_book.get_contact(i).initialized)
		return (1);
	return (0);
}

void	search_contact(PhoneBook phone_book)
{
	std::string input;
	size_t		i;

	if (phone_book.get_contact(0).initialized == 0)
	{
		std::cout << "this phone book is empty" << std::endl;
		return ;
	}
	print_phone_book(phone_book);
	std::cout << "plese select a index to view the contact" << std::endl;
search_start:
	if (!std::getline(std::cin, input))
		std::exit(42);
	if (is_num(input) == 0)
	{
		std::cout << "only digits" << std::endl;
		goto search_start;
	}
	if (input.length() == 1)
		i = input[0] - 48;
	else
		i = 10;
	if (!check_correct_index(i, phone_book))
	{
		std::cout << "index out of range" << std::endl;
		goto search_start;
	}
	print_contact(phone_book.get_contact(i));
}

std::string	get_input(std::string prompt)
{
	std::string	input;
begin_get_input:
	std::cout << prompt << std::endl;

	if (!std::getline(std::cin, input))
	{
		std::cout << "error" << std::endl;
		exit(42);
	}
	if (input.length() == 0)
	{
		std::cout << "empty entry try again" << std::endl;
		goto begin_get_input;
	}
	return (input);
}

Contact	make_contact(void)
{
	std::string input;
	Contact		contact;

	contact.initialized = 1;
	get_input("First Name :");
	contact.set_first_name(input);
	get_input("Last Name :");
	contact.set_last_name(input);
	get_input("Nickname :");
	contact.set_nicname(input);
	
	std::cout << "Number :";
	do
	{
		std::cout << "only digits allowed" << std::endl;
		if (!std::getline(std::cin, input))
			std::exit(42);
	}
	while (!is_num(input));
	contact.set_phone_number(input);
	get_input("Darkest Secret :");
	contact.set_darkest_secret(input);

	return (contact);
}

void	print_instructions(void)
{
	std::cout << "Now the phone book is empty.\n";
	std::cout << "Please do one of the folowing commands.\n";
	std::cout << "\tADD.\n";
	std::cout << "\tSEARCH.\n";
	std::cout << "\tEXIT.\n";
	std::cout << std::endl;
}

void	print_cmd_prompt(void)
{
	std::cout << "cmd>" << std::flush;
}

int	main(void)
{
	PhoneBook	phone_book;
	std::string	input;

	print_instructions();
	print_cmd_prompt();
	while (std::getline(std::cin, input))
	{
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			phone_book.add_contact(make_contact());
		else if (input == "SEARCH")
			search_contact(phone_book);
		else
			std::cout << "wrong option. try again" << std::endl;
		print_cmd_prompt();
	}
	return (42);
}
