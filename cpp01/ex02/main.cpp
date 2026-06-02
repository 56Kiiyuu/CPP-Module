/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:42:59 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/02 13:48:38 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout	<< &str << "\n";
	std::cout	<< stringPTR << "\n";
	std::cout	<< &stringREF << "\n";

	std::cout	<< str << "\n";
	std::cout	<< *stringPTR << "\n";
	std::cout	<< stringREF << "\n";

}
