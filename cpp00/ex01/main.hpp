/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:18:37 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/28 15:45:22 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <unistd.h>
#include <cctype>

typedef std::string str;

bool	is_printable(const str &s);
bool	get_secure_input(str &output, const str &prompt);

#include "Contact.hpp"
#include "PhoneBook.hpp"

#endif
