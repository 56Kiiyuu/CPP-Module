/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:27:37 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/22 13:44:00 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &num1, T &num2)
{
	T tmp = num1;
	num1 = num2;
	num2 = tmp;
};

template <typename T>
T min(T &num1, T &num2)
{
	return (num1 < num2 ? num1 : num2);
};

template <typename T>
T max(T &num1, T &num2)
{
	return (num1 > num2 ? num1 : num2);
};

#endif