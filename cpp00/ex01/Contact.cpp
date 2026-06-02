/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:36:13 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/02 14:05:38 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFname(std::string f_name)
{
	this->f_name = f_name;
}

void	Contact::setLname(std::string l_name)
{
	this->l_name = l_name;
}

void	Contact::setNname(std::string n_name)
{
	this->n_name = n_name;
}

void	Contact::setPhone(std::string phone)
{
	this->phone = phone;
}

void	Contact::setSecret(std::string secret)
{
	this->secret = secret;
}

std::string	Contact::getFname()
{
	return (this->f_name);
}

std::string	Contact::getLname()
{
	return (this->l_name);
}

std::string	Contact::getNname()
{
	return (this->n_name);
}

std::string	Contact::getPhone()
{
	return (this->phone);
}

std::string	Contact::getSecret()
{
	return (this->secret);
}
