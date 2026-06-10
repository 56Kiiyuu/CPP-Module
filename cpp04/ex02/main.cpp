/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:40:57 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/10 15:05:05 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "CLASSIC USAGE\n";
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;

	//const AAnimal* test = new AAnimal(); error compil
	return 0;
}
