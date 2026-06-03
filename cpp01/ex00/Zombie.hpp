/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:55:42 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/03 15:58:29 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	_name;
	public:
		void	announce(void);
		Zombie(const std::string &in_name);
		~Zombie();

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
#endif
