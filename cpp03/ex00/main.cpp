/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:12:15 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/09 13:58:15 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	std::cout << "CREATE\n";
	ClapTrap clappy("Clappy");
	ClapTrap bandit("Handsome Jack");

	std::cout << "\nACTIONS\n";
	clappy.attack("Handsome Jack");
	bandit.takeDamage(0); // Clappy damage(0)

	clappy.beRepaired(5); // 15 HP and 8 Energy

	std::cout << "\nEnergy drain\n";
	// Consume all energy for clappy (8)
	for (int i = 0; i < 8; i++) {
		clappy.attack("a poor target");
	}
	// 9th action : no energy
	clappy.attack("one last target");

	std::cout << "\nDEATHS TEST\n";
	bandit.takeDamage(5);
	bandit.takeDamage(10); // Overkill (Jack death)
	bandit.beRepaired(5);  // Impossible, already dead

	std::cout << "\nDESTRUCTORS\n";
	return 0;
}
