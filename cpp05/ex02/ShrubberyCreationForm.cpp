/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:38:16 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/15 14:14:35 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("Shrubbery Creation", 145, 137, target)
{}

void	ShrubberyCreationForm::executeAction() const {
	std::ofstream file((this->getTarget() + "_shrubbery").c_str());
	if (file.is_open()) {
		file << "    c     \n"
			<< "   abc    \n"
			<< "  abcde   \n"
			<< " abcdefg  \n"
			<< "   |||    \n";
		file.close();
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}
