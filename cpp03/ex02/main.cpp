/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:12:15 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/09 14:49:37 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << "TESTING FRAGTRAP (CHAINING)\n";
	{
		FragTrap frag("Fraggy");
		frag.attack("a scary monster");

		frag.takeDamage(50);
		frag.beRepaired(20);
		frag.highFivesGuys();
	}

	std::cout << "\nTESTS\n";
	{
		ScavTrap scav("Scavvy");
		FragTrap frag("Fraggy");

		scav.attack("Fraggy");
		frag.takeDamage(20);

		frag.attack("Scavvy");
		scav.takeDamage(30);
	}
	return 0;
}
