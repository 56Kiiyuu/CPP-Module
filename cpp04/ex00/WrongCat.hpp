/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:37:35 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/10 14:04:51 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongCat();
		WrongCat(const WrongCat &src);
		WrongCat	&operator=(const WrongCat &rhs);
		~WrongCat();
		void	makeSound(void) const;
};

#endif
