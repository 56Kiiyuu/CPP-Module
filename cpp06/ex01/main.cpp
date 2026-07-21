/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:48:54 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/21 14:57:34 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data data;
	data.name = "Kevin";
	data.value = 42;

	Data* originalPtr = &data;

	//serialization (ptr to int)
	uintptr_t raw = Serializer::serialize(originalPtr);
	//raw += 4; for test doesnt match
	//deserialization (int to ptr)
	Data* deserializedPtr = Serializer::deserialize(raw);

	std::cout << "Original Pointer:     " << originalPtr << std::endl;
	std::cout << "Serialized (raw int): " << raw << std::endl;
	std::cout << "Deserialized Pointer: " << deserializedPtr << std::endl;

	// test compare value of deserialize with orgn ptr
	if (deserializedPtr == originalPtr)
	{
		std::cout << "\nSUCCESS: Pointers match" << std::endl;
		std::cout << "Data name:  " << deserializedPtr->name << std::endl;
		std::cout << "Data value: " << deserializedPtr->value << std::endl;
	}
	else {
		std::cout << "\nERROR: Pointers do not match" << std::endl;
	}
}
