/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:42:59 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/23 16:35:19 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout	<< &str << std::endl;
	std::cout	<< stringPTR << std::endl;
	std::cout	<< &stringREF << std::endl;

	std::cout	<< str << std::endl;
	std::cout	<< *stringPTR << std::endl;
	std::cout	<< stringREF << std::endl;

}
