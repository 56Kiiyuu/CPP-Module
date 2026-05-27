/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:36:13 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/27 15:26:22 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFname(str f_name)
{
	this->f_name = f_name;
}

void	Contact::setLname(str l_name)
{
	this->l_name = l_name;
}

void	Contact::setNname(str n_name)
{
	this->n_name = n_name;
}

void	Contact::setPhone(str phone)
{
	this->phone = phone;
}

void	Contact::setSecret(str secret)
{
	this->secret = secret;
}

str	Contact::getFname()
{
	return (this->f_name);
}

str	Contact::getLname()
{
	return (this->l_name);
}

str	Contact::getNname()
{
	return (this->n_name);
}

str	Contact::getPhone()
{
	return (this->phone);
}

str	Contact::getSecret()
{
	return (this->secret);
}
