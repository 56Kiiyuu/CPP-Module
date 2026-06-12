/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:33:05 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/12 14:44:53 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{}

Form::Form(const std::string name, int sign_grade, int exec_grade)
	: _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _is_signed(src._is_signed), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{}

Form	&Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		this->_is_signed = rhs._is_signed;
	return *this;
}

Form::~Form()
{}

std::string	Form::getName() const
{
	return this->_name;
}

bool	Form::getIsSigned() const
{
	return this->_is_signed;
}

int	Form::getSignGrade() const
{
	return this->_sign_grade;
}

int	Form::getExecGrade() const
{
	return this->_exec_grade;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	this->_is_signed = true;
}

std::ostream &operator<<(std::ostream &o, const Form &rhs) {
	o << "Form '" << rhs.getName() << "' [Signed: " << (rhs.getIsSigned() ? "Yes" : "No")
	<< " | Grade required to sign: " << rhs.getSignGrade()
	<< " | Grade required to execute: " << rhs.getExecGrade() << "]";
	return o;
}
