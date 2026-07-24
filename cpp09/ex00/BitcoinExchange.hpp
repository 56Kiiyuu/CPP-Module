/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:58:24 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/24 13:58:25 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_db;
		bool	isValidDate(const std::string &date) const;
		bool	isValidValue(const std::string &valStr, float &value) const;
		std::string trim(const std::string &str) const;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();

		bool	loadDataBase(const std::string &src);
		void	processInputFile(const std::string &inputPath) const;
};

#endif
