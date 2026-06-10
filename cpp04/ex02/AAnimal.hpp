/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:58:57 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/10 14:59:51 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>
#include <string>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		AAnimal(const AAnimal &src);
		AAnimal	&operator=(const AAnimal &rhs);
		virtual	~AAnimal();
		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
