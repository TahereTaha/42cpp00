/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:04:42 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/04 07:14:45 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "phone_book.h"

PhoneBook::PhoneBook(void)
{
	last_updated_contact = CONTACT_ARRAY_SIZE - 1;
}

PhoneBook::~PhoneBook(void)
{
}

Contact	PhoneBook::get_contact(size_t index)
{
	return (contacts[index]);
}

void	PhoneBook::add_contact(Contact contact)
{
	if (last_updated_contact == CONTACT_ARRAY_SIZE - 1)
		last_updated_contact = 0;
	else
		last_updated_contact++;
	contacts[last_updated_contact] = contact;
}
