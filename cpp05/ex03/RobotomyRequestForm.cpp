/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:58:01 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/17 14:06:29 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45, "default_target")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("Robotomy Request", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void	RobotomyRequestForm::executeAction() const {
	std::cout << "* BZZZZZZZZZZZZ... DRILL NOISES *" << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "The robotomy on " << this->getTarget() << " failed." << std::endl;
	}
}

