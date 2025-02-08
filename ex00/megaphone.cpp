/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:58:50 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/08 12:42:39 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print_arg_uppercase(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		std::cout << (char)std::toupper(arg[i]);
		i++;
	}
	std::cout << " " ;
}


int	main(int argc, char **argv)
{
	size_t	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	i = 1;
	while (argv[i])
	{
		print_arg_uppercase(argv[i]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}
