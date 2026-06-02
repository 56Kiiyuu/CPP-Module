/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:18:37 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/02 14:05:15 by kevlim           ###   ########.fr       */
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

bool	is_printable(const std::string &s);
bool	get_secure_input(std::string &output, const std::string &prompt);

#include "Contact.hpp"
#include "PhoneBook.hpp"

#endif
