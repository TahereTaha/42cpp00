/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:03:22 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/04 06:47:40 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_hpp
# define Contact_hpp

#include <string>

class Contact 
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nicname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		int			initialized;
		Contact();
		~Contact(void);
		
		void set_first_name(std::string first_name);
		void set_last_name(std::string last_name);
		void set_nicname(std::string nicname);
		void set_phone_number(std::string phone_number);
		void set_darkest_secret(std::string darkest_secret);
		
		std::string get_first_name(void);
		std::string get_last_name(void);
		std::string get_nicname(void);
		std::string get_phone_number(void);
		std::string get_darkest_secret(void);
};

#endif
