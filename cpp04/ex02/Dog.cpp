/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:27:15 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/10 15:03:04 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog &src) : AAnimal(src)
{
	std::cout << "Dog copy constructor called\n";
	this->_brain = new Brain();
	*this->_brain = *src._brain;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog assignment operator called\n";
	if (this != &rhs)
	{
		this->type = rhs.type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
		*this->_brain = *rhs._brain;
	}
	return *this;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof !\n";
}
