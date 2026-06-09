/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:12:15 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/09 14:28:55 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	std::cout << "TESTING CLAPTRAP\n";
	{
		ClapTrap clap("BasicClap");
		clap.attack("a target");
	}

	std::cout << "\nTESTING SCAVTRAP (CHAINING)\n";
	{
		ScavTrap scav("Scavvy");

		scav.attack("a dangerous enemy");
		scav.takeDamage(30);
		scav.beRepaired(15);
		scav.guardGate();
	}
	return 0;
}
