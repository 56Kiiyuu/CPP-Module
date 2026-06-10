/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:40:57 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/10 13:48:34 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "IDEAL POLYMORPHISM\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); // Print ("Meow!") virtual
	j->makeSound(); // Print ("Woof Woof!") virtual
	meta->makeSound();

	delete meta;
	delete j; // Called own destructor before ~Animal()
	delete i; // Called own destructor before ~Animal()

	std::cout << "\nWRONG POLYMORPHISM\n";
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;

	wrongCat->makeSound(); // Print WrongAnimal sound not WrongCat because not virtual;
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongCat; // Don't call WrongCat destructor (maybe leak)

	return 0;
}
