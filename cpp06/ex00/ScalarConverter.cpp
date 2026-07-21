/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:32:20 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/21 13:52:14 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs; return *this;
}

ScalarConverter::~ScalarConverter()
{}

void	ScalarConverter::convert(const std::string &literal)
{
	std::string	charResult = "";
	std::string	intResult = "";
	float		f = 0.0f;
	double		d = 0.0;

	// handle 1 literal char (ex 'a' or just b)
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		char	c = literal[0];
		d = static_cast<double>(c);
	}
	else
	{
		//convert str to double for handle all cases
		char	*endptr;
		d = std::strtod(literal.c_str(), &endptr);

		//if conversion failed
		if (*endptr != '\0' && std::string(endptr) != "f")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}

	// CHAR
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
	{
		charResult = "impossible";
	}
	else if (!std::isprint(static_cast<int>(d)))
	{
		charResult = "Non displayable";
	}
	else
	{
		charResult = "'";
		charResult += static_cast<char>(d);
		charResult += "'";
	}

	// INT
	if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
	{
		intResult = "impossible";
	}

	// cast float
	f = static_cast<float>(d);

	//print result
	std::cout << "char: " << charResult << std::endl;
	if (intResult == "impossible")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	// decimal format (.0f)
	if (d == static_cast<int>(d))
	{
		std::cout << std::fixed << std::setprecision(1);
	}
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
