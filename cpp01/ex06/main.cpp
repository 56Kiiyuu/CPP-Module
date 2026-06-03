/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:20:08 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/03 19:01:22 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	get_level_index(std::string level)
{
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return i;
	}
	return -1;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return 1;
	}
	Harl harl;
	std::string input_level = av[1];

	switch (get_level_index(input_level))
	{
	case 0:
		harl.complain("DEBUG");
		//fallthrough
	case 1:
		harl.complain("INFO");
		//fallthrough
	case 2:
		harl.complain("WARNING");
		//fallthrough
	case 3:
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
	return 0;
}
