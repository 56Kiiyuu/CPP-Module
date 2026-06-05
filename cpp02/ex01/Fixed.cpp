/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:40:13 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/05 12:08:36 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	this->_rawBits = n << _bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	this->_rawBits = roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed &src) : _rawBits(src._rawBits)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
	{
		this->_rawBits = rhs.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

int	Fixed::toInt(void) const
{
	return this->_rawBits >> _bits;
}

float Fixed::toFloat(void) const
{
	return (float)this->_rawBits / (1 << _bits);
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return o;
}
