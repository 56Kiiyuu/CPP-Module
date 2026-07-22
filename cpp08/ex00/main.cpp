/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:27:20 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/22 15:31:06 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int	main() 
{
	std::cout << "TEST : std::vector" << std::endl;
	std::vector<int> vec;
	for (int i = 1; i <= 5; ++i) 
	{
		vec.push_back(i * 10); // [10, 20, 30, 40, 50]
	}

	try 
	{
		std::vector<int>::iterator it = ::easyfind(vec, 30);
		std::cout << "Found value: " << *it << std::endl;

		std::cout << "Searching for 99..." << std::endl;
		::easyfind(vec, 99);
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\nTEST : std::list" << std::endl;
	std::list<int> lst;
	lst.push_back(42);
	lst.push_back(100);
	lst.push_back(-5);

	try 
	{
		std::list<int>::iterator it = ::easyfind(lst, -5);
		std::cout << "Found value in list: " << *it << std::endl;
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\nTEST : std::deque" << std::endl;
	std::deque<int> deq;
	deq.push_back(7);
	deq.push_back(14);

	try 
	{
		std::deque<int>::iterator it = ::easyfind(deq, 5);
		std::cout << "Found value in deque: " << *it << std::endl;
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}