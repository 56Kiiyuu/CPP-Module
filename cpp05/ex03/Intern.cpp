/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:30:05 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/23 17:23:02 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return *this;
}

Intern::~Intern()
{}

AForm* Intern::_createShrubbery(const std::string target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::_createRobotomy(const std::string target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::_createPresidential(const std::string target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string formName, const std::string target) const
{
	std::string	formNames[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*formCreators[3])(const std::string) const =
	{
		&Intern::_createShrubbery,
		&Intern::_createRobotomy,
		&Intern::_createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	std::cout << "Error: Intern cannot create '" << formName << "' because it doesn't exist." << std::endl;
	return NULL;
}
