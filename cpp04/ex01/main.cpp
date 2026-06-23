/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:40:57 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/23 17:15:52 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const int	size = 4;
	Animal* animals[size];

	std::cout << "FILL TAB\n";
	for (int i = 0; i < size; i++) {
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\nPOLYMORPHISM TEST\n";
	for (int i = 0; i < size; i++) {
		animals[i]->makeSound();
	}

	std::cout << "\nDEEP COPY\n";
	{
		Dog basic;
		{
			Dog tmp = basic; // Call copy constructor
		} // tmp delete here, but basic not
		std::cout << "Basic and his brain alive" << std::endl;
	}

	std::cout << "\nFREE TAB\n";
	for (int i = 0; i < size; i++) {
		delete animals[i]; // delete Animal*
	}

	return 0;
}
