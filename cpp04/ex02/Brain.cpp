/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:59:54 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/10 14:01:06 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain copy constructor called\n";
	*this = src;
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain assignment operator called\n";
	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}
