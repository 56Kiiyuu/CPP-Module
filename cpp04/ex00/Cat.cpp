/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:31:36 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/10 13:32:19 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat &src) : Animal(src)
{
	*this = src;
	std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!\n";
}
