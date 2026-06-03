/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:09:42 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/03 16:16:41 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook() : _max_contacts(8), _current_numb(0), _nb_contacts(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add_contact()
{
	std::string	f_name = "";
	std::string	l_name = "";
	std::string	n_name = "";
	std::string	phone = "";
	std::string	secret = "";

	system("clear");
	if (this->_current_numb == 8)
		this->_current_numb = 0;
	system("clear");
	if (!get_secure_input(f_name, "Type firstname : ") ||
		!get_secure_input(l_name, "Type lastname : ") ||
		!get_secure_input(n_name, "Type nickname : ") ||
		!get_secure_input(phone, "Type phone : ") ||
		!get_secure_input(secret, "Type secret : "))
	{
		return ;
	}

	system("clear");
	this->_array[this->_current_numb].setFname(f_name);
	this->_array[this->_current_numb].setLname(l_name);
	this->_array[this->_current_numb].setNname(n_name);
	this->_array[this->_current_numb].setPhone(phone);
	this->_array[this->_current_numb].setSecret(secret);
	this->_current_numb++;
	if (_nb_contacts < 8)
		_nb_contacts++;
}

void	PhoneBook::search_contact()
{
	int	i = 0;
	std::string	f_name = "";
	std::string	l_name = "";
	std::string	n_name = "";
	std::string	phone = "";
	std::string	secret = "";
	std::string	ret;
	int	index;

	system("clear");
	if (this->_nb_contacts == 0)
	{
		std::cout << "No contact available !" << std::endl;
		sleep(1);
		return;
	}
	std::cout << std::setw(5) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	while (i < _nb_contacts)
	{
		std::cout << std::setw(5) << i << "|";
		f_name = this->_array[i].getFname();
		l_name = this->_array[i].getLname();
		n_name = this->_array[i].getNname();
		phone = this->_array[i].getPhone();
		secret = this->_array[i].getSecret();
		if (f_name.length() > 9)
			f_name = f_name.substr(0, 9) + ".";
		if (l_name.length() > 9)
			l_name = l_name.substr(0, 9) + ".";
		if (n_name.length() > 9)
			n_name = n_name.substr(0, 9) + ".";
		std::cout << std::setw(10) << f_name << "|";
		std::cout << std::setw(10) << l_name << "|";
		std::cout << std::setw(10) << n_name << std::endl;
		i++;
	}

	if (!get_secure_input(ret, "\nType index : "))
		return ;
	index = atoi(ret.c_str());
	if ((index == 0 && ret[0] != '0')
		|| (index > 7 || index < 0))
	{
		std::cout << "Pls enter valid index !" << std::endl;
		sleep(1);
		return ;
	}
	if (index >= this->_nb_contacts)
	{
		std::cout << "No contact found !" << std::endl;
		sleep(1);
		return ;
	}
	std::cout << "Firstname : " << this->_array[index].getFname() << std::endl;
	std::cout << "Lastname : " << this->_array[index].getLname() << std::endl;
	std::cout << "Nickname : " << this->_array[index].getNname() << std::endl;
	std::cout << "Phone : " << this->_array[index].getPhone() << std::endl;
	std::cout << "Secret : " << this->_array[index].getSecret() << std::endl;
	std::cout << std::endl << "Press ENTER to continue" << std::endl;

	std::string	stash;
	if (!std::getline(std::cin, stash))
	{
		std::cout << std::endl << "Bye ! (EOF)" << std::endl;
		return ;
	}
}
