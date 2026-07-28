/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:07:50 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/28 15:14:55 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"


// Modify all elem (non const)
template <typename T>
void increment(T &x) {
	x += 1;
}

// Read (const)
template <typename T>
void printElement(const T &x) {
	std::cout << x << " ";
}

// Non Template
void printUpperChar(char &c) {
	if (c >= 'a' && c <= 'z')
		c = c - 32;
}

int main()
{
	std::cout << "TEST : Array of INTs (Modification)" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	std::size_t intLen = 5;

	std::cout << "Before increment: ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << std::endl;

	// instanciated function template
	::iter(intArray, intLen, increment<int>);

	std::cout << "After increment:  ";
	::iter(intArray, intLen, printElement<int>);
	std::cout << "\n" << std::endl;

	std::cout << "TEST : Array of STRINGS (Read-Only)" << std::endl;
	std::string strArray[] = {"Hello", "42", "Kevin", "CPP07"};
	std::size_t strLen = 4;

	std::cout << "Print strings: ";
	::iter(strArray, strLen, printElement<std::string>);
	std::cout << "\n" << std::endl;

	std::cout << "TEST : CONST Array (Read-Only)" << std::endl;
	const int constIntArray[] = {10, 20, 30};
	std::size_t constLen = 3;

	std::cout << "Print const int array: ";
	// should compile even if const array
	::iter(constIntArray, constLen, printElement<int>);
	std::cout << "\n" << std::endl;

	std::cout << "TEST : Array of CHARs" << std::endl;
	char charArray[] = {'a', 'b', 'c', 'd'};
	std::size_t charLen = 4;

	::iter(charArray, charLen, printUpperChar);
	std::cout << "To uppercase: ";
	::iter(charArray, charLen, printElement<char>);
	std::cout << std::endl;

	return 0;
}
/*
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  const int len = 5;

  iter( tab, len, print<const int> );
  iter( tab2, len, print<Awesome> );

  return 0;
}
*/
