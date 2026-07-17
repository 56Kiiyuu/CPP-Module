/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:00:18 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/17 14:02:46 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon", 25, 5, "default_target")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("Presidential Pardon", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void	PresidentialPardonForm::executeAction() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
