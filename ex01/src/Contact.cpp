/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:37:56 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/04 06:51:08 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"

Contact::Contact(void)
{
	initialized = 0;
}

Contact::~Contact(void)
{
}

void	Contact::set_first_name(std::string _first_name)
{
	first_name = _first_name;
}

void	Contact::set_last_name(std::string _last_name)
{
	last_name = _last_name;
}

void	Contact::set_nicname(std::string _nicname)
{
	nicname = _nicname;
}

void	Contact::set_phone_number(std::string _phone_number)
{
	phone_number = _phone_number;
}

void	Contact::set_darkest_secret(std::string _darkest_secret)
{
	darkest_secret = _darkest_secret;
}


std::string	Contact::get_first_name(void)
{
	return (first_name);
}

std::string	Contact::get_last_name(void)
{
	return (last_name);
}

std::string	Contact::get_nicname(void)
{
	return (nicname);
}

std::string	Contact::get_phone_number(void)
{
	return (phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (darkest_secret);
}
