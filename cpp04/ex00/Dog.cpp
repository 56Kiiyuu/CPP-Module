/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:27:15 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/10 13:29:56 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog &src) : Animal(src)
{
	*this = src;
	std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof !\n";
}
