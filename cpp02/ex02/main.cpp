/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:38:12 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/29 13:36:24 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

//int main( void )
//{
//	Fixed a;
//	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//	std::cout << a << std::endl;
//	std::cout << ++a << std::endl;
//	std::cout << a << std::endl;
//	std::cout << a++ << std::endl;
//	std::cout << a << std::endl;
//	std::cout << b << std::endl;
//	std::cout << Fixed::max( a, b ) << std::endl;
//	return 0;
//}


int	main(void)
{
	Fixed	a(Fixed(3));
	Fixed	const b(Fixed(5) * Fixed(2));
	Fixed	c(Fixed(0));

	std::cout << a << std::endl;
	//std::cout << ++a << std::endl;
	//std::cout << a << std::endl;
	//std::cout << a++ << std::endl;
	//std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a++ << std::endl;
	//std::cout << b/2 << std::endl;
	std::cout << b/c << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	return 0;
}

