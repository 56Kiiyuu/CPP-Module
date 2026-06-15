/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:33:05 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/12 14:44:53 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _is_signed(false), _sign_grade(150), _exec_grade(150), _target("Default_Target")
{}

AForm::AForm(const std::string name, int sign_grade, int exec_grade, const std::string target)
	: _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade), _target(target)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name), _is_signed(src._is_signed), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade), _target(src._target)
{}

AForm	&AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		this->_is_signed = rhs._is_signed;
	return *this;
}

AForm::~AForm()
{}

std::string	AForm::getName() const
{
	return this->_name;
}

bool	AForm::getIsSigned() const
{
	return this->_is_signed;
}

int	AForm::getSignGrade() const
{
	return this->_sign_grade;
}

int	AForm::getExecGrade() const
{
	return this->_exec_grade;
}

std::string AForm::getTarget() const {
	return this->_target;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw AForm::GradeTooLowException();
	this->_is_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_is_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_exec_grade)
		throw AForm::GradeTooLowException();
	this->executeAction();
}

std::ostream &operator<<(std::ostream &o, const AForm &rhs) {
	o << "AForm '" << rhs.getName() << "' [Signed: " << (rhs.getIsSigned() ? "Yes" : "No")
	<< " | Grade required to sign: " << rhs.getSignGrade()
	<< " | Grade required to execute: " << rhs.getExecGrade() << "]";
	return o;
}
