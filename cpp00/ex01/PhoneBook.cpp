/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:09:42 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/28 15:42:14 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook() : max_contacts(8), current_numb(0), nb_contacts(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add_contact()
{
	str	f_name = "";
	str	l_name = "";
	str	n_name = "";
	str	phone = "";
	str	secret = "";

	system("clear");
	if (this->current_numb == 8)
		this->current_numb = 0;
	system("clear");
	get_secure_input(f_name, "Type firstname : ");
	get_secure_input(l_name, "Type lastname : ");
	get_secure_input(n_name, "Type nickname : ");
	get_secure_input(phone, "Type phone : ");
	get_secure_input(secret, "Type secret : ");

	system("clear");
	this->array[this->current_numb].setFname(f_name);
	this->array[this->current_numb].setLname(l_name);
	this->array[this->current_numb].setNname(n_name);
	this->array[this->current_numb].setPhone(phone);
	this->array[this->current_numb].setSecret(secret);
	this->current_numb++;
	if (nb_contacts < 8)
		nb_contacts++;
}

void	PhoneBook::search_contact()
{
	int	i = 0;
	str	f_name = "";
	str	l_name = "";
	str	n_name = "";
	str	phone = "";
	str	secret = "";
	str	ret;
	int	index;

	system("clear");
	if (this->nb_contacts == 0)
	{
		std::cout << "No contact available !" << std::endl;
		sleep(1);
		return;
	}
	std::cout << std::setw(5) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	while (i < nb_contacts)
	{
		std::cout << std::setw(5) << i << "|";
		f_name = this->array[i].getFname();
		l_name = this->array[i].getLname();
		n_name = this->array[i].getNname();
		phone = this->array[i].getPhone();
		secret = this->array[i].getSecret();
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

	get_secure_input(ret, "\nType index : ");
	index = atoi(ret.c_str());
	if ((index == 0 && ret[0] != '0')
		|| (index > 7 || index < 0))
	{
		std::cout << "Pls enter valid index !" << std::endl;
		sleep(1);
		return ;
	}
	if (index >= this->nb_contacts)
	{
		std::cout << "No contact found !" << std::endl;
		sleep(1);
		return ;
	}
	std::cout << "Firstname : " << this->array[index].getFname() << std::endl;
	std::cout << "Lastname : " << this->array[index].getLname() << std::endl;
	std::cout << "Nickname : " << this->array[index].getNname() << std::endl;
	std::cout << "Phone : " << this->array[index].getPhone() << std::endl;
	std::cout << "Secret : " << this->array[index].getSecret() << std::endl;
	std::cout << std::endl << "Press ENTER to continue" << std::endl;

	str	stash;
	std::getline(std::cin, stash);
}
