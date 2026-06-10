/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:31:11 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/10 14:04:36 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include <string>

#include "Animal.hpp"

class Cat : public Animal
{
	protected:
		std::string	type;
	public:
		Cat();
		Cat(const Cat &src);
		Cat	&operator=(const Cat &rhs);
		virtual	~Cat();
		virtual void	makeSound(void) const;
};

#endif
