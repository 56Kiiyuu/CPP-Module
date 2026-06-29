/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:40:13 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/29 13:39:13 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = n << _bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_rawBits = rhs.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->toFloat() != rhs.toFloat());
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	if (rhs.getRawBits() == 0)
	{
		std::cerr << "Error: Division by zero!" << std::endl;
		return (Fixed(0));
	}
	return (this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++()
{
	this->_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed duplicated(*this);
	operator++();
	return duplicated;
}

Fixed &Fixed::operator--()
{
	this->_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed duplicated(*this);
	operator--();
	return duplicated;
}

Fixed	&Fixed::min(Fixed &Fixed1, Fixed &Fixed2)
{
	return (Fixed1 < Fixed2 ? Fixed1 : Fixed2);
}

const Fixed	&Fixed::min(const Fixed &Fixed1, const Fixed &Fixed2)
{
	return (Fixed1 < Fixed2 ? Fixed1 : Fixed2);
}

Fixed	&Fixed::max(Fixed &Fixed1, Fixed &Fixed2)
{
	return (Fixed1 > Fixed2 ? Fixed1 : Fixed2);
}
const Fixed	&Fixed::max(const Fixed &Fixed1, const Fixed &Fixed2)
{
	return (Fixed1 > Fixed2 ? Fixed1 : Fixed2);
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return o;
}
