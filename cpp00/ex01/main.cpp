/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:14:31 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/27 15:54:08 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main()
{
	PhoneBook	PhoneBook;
	str	line = "";
	str	add = "ADD";
	str	search = "SEARCH";
	str	exit = "EXIT";

	system("clear");
	std::cout << "Welcome to PhoneBook" << std::endl;
	while (1)
	{
		std::cout << "ADD | SEARCH | EXIT : ";
		std::getline(std::cin, line);
		if (!line.compare(add))
			PhoneBook.add_contact();
		else if (!line.compare(search))
			PhoneBook.search_contact();
		else if (!line.compare(exit))
		{
			std::cout << "Bye !" << std::endl;
			break;
		}
		system("clear");
	}
	return (0);
}
