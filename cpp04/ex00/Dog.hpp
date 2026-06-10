/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:25:45 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/10 14:04:39 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include <string>

#include "Animal.hpp"

class Dog : public Animal
{
	protected:
		std::string	type;
	public:
		Dog();
		Dog(const Dog &src);
		Dog	&operator=(const Dog &rhs);
		virtual	~Dog();
		virtual void	makeSound(void) const;
};

#endif
