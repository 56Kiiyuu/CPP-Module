/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:27:36 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/22 14:32:37 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

// Default Constructor (empty array)
template <typename T>
Array<T>::Array() : _elements(NULL), _size(0)
{}

// Constructor with int N (Config size)
template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) 
{}

// Copy constructor
template <typename T>
Array<T>::Array(const Array &src) : _elements(NULL), _size(0) 
{
	*this = src;
}

// Destructor
template <typename T>
Array<T>::~Array() 
{
	if (this->_elements)
		delete[] this->_elements;
}

// Assignement operator
template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs) 
{
	if (this != &rhs) 
	{
		if (this->_elements)
			delete[] this->_elements;
		
		this->_size = rhs._size;
		if (this->_size > 0) {
			this->_elements = new T[this->_size]();
			for (unsigned int i = 0; i < this->_size; i++) 
			{
				this->_elements[i] = rhs._elements[i];
			}
		} 
		else
		{
			this->_elements = NULL;
		}
	}
	return *this;
}

// Operator [] for READ/WRITE
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw Array<T>::OutOfBoundsException();
	return this->_elements[index];
}

// Operator [] for const obj (READ ONLY)
template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= this->_size)
		throw Array<T>::OutOfBoundsException();
	return this->_elements[index];
}

// size of array
template <typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}

#endif