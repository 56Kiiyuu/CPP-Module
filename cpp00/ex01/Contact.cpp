/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:36:13 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/03 16:06:30 by kevlim           ###   ########.fr       */
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
	this->_f_name = f_name;
}

void	Contact::setLname(std::string l_name)
{
	this->_l_name = l_name;
}

void	Contact::setNname(std::string n_name)
{
	this->_n_name = n_name;
}

void	Contact::setPhone(std::string phone)
{
	this->_phone = phone;
}

void	Contact::setSecret(std::string secret)
{
	this->_secret = secret;
}

std::string	Contact::getFname()
{
	return (this->_f_name);
}

std::string	Contact::getLname()
{
	return (this->_l_name);
}

std::string	Contact::getNname()
{
	return (this->_n_name);
}

std::string	Contact::getPhone()
{
	return (this->_phone);
}

std::string	Contact::getSecret()
{
	return (this->_secret);
}
