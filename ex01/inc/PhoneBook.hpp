/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:46:53 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/04 07:11:26 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_hpp
# define PhoneBook_hpp

# include "Contact.hpp"
# include "phone_book.h"

class PhoneBook	{
	private:
		Contact	contacts[CONTACT_ARRAY_SIZE];
		size_t	last_updated_contact;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		Contact		get_contact(size_t index);
		void		add_contact(Contact contact);
};



#endif
