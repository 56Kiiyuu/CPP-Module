/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:14:31 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/28 15:45:07 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool	is_printable(const str &s)
{
	if (s.empty())
		return false;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!isprint(s[i]))
			return false;
	}
	return true;
}

bool get_secure_input(str &output, const str &prompt)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, output))
		{
			std::cout << std::endl << "Bye ! (EOF)" << std::endl;
			exit(0);
		}
		if (is_printable(output))
			return true;
		std::cout << "Invalid input !" << std::endl;
	}
}

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
		get_secure_input(line, "ADD | SEARCH | EXIT : ");
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
