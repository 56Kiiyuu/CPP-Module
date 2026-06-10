/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:00:15 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/10 15:01:10 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal constructor called\n";
}

AAnimal::AAnimal(const AAnimal &src)
{
	*this = src;
	std::cout << "AAnimal copy constructor called\n";
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called\n";
}

std::string	AAnimal::getType(void) const
{
	return this->type;
}
