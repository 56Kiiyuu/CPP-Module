/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:38:16 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/17 14:08:58 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137, "default_target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("Shrubbery Creation", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::executeAction() const {
	std::ofstream file((this->getTarget() + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open or create the shrubbery file." << std::endl;
		return;
	}
	file << "    c     \n"
		<< "   abc    \n"
		<< "  abcde   \n"
		<< " abcdefg  \n"
		<< "   |||    \n";
	file.close();
}
