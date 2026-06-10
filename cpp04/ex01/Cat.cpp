/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:31:36 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/10 14:13:34 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor called\n";
	this->_brain = new Brain();
	*this->_brain = *src._brain;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat assignment operator called\n";
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

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!\n";
}
