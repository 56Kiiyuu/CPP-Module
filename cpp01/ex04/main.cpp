/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:26:03 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/23 16:40:19 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>

std::string	replace_custom(std::string content, const std::string &s1, const std::string &s2)
{
	if (s1.empty())
		return content;
	size_t	index = 0;
	while ((index = content.find(s1, index)) != std::string::npos)
	{
		content.erase(index, s1.length());
		content.insert(index, s2);
		index += s2.length();
	}
	return content;
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error: ./sed <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Cannot open file: " << filename << std::endl;
		return 1;
	}

	std::string	content;
	std::string	line;
	while (std::getline(ifs, line))
	{
		content += line;
		if (!ifs.eof())
			content += "\n";
	}
	ifs.close();

	std::string	new_content = replace_custom(content, s1, s2);

	std::ofstream ofs((filename + ".replace").c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Cannot create output file" << std::endl;
		return 1;
	}
	ofs << new_content;
	ofs.close();
	return 0;
}
