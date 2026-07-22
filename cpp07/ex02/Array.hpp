/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:20:51 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/22 14:27:05 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>

template <typename T>
class Array
{
	private:
		T*				_elements;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();
		Array &operator=(const Array &rhs);
		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
		unsigned int size() const;
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw() 
				{
					return "Index is out of bounds!";
				}
		};
};

# include "Array.tpp"
#endif
