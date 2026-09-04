/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:58:37 by kevlim            #+#    #+#             */
/*   Updated: 2026/09/04 13:12:16 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _db(src._db)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_db = rhs._db;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

std::string	BitcoinExchange::trim(const std::string &str) const
{
	size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, (last - first + 1));
}

bool	BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	//verification 30/31 and february
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return false;
	}
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &valStr, float &value) const
{
	if (valStr.empty())
	{
		std::cout << "Error: bad input => " << valStr << std::endl;
		return false;
	}

	char *endptr;
	double val = std::strtod(valStr.c_str(), &endptr);

	// if invalid input after number
	if (*endptr != '\0')
	{
		std::cout << "Error: bad input => " << valStr << std::endl;
		return false;
	}
	if (val < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (val > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	value = static_cast<float>(val);
	return true;
}

bool	BitcoinExchange::loadDataBase(const std::string &dbPath)
{
	std::ifstream file(dbPath.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return false;
	}
	std::string line;
	std::getline(file, line); //skip first line
	while (std::getline(file, line))
	{
		size_t commaPos = line.find(',');
		if (commaPos != std::string::npos)
		{
			std::string date = trim(line.substr(0, commaPos));
			std::string rateStr = trim(line.substr(commaPos + 1));
			float rate = static_cast<float>(std::atof(rateStr.c_str()));
			this->_db[date] = rate;
		}
	}
	file.close();
	return true;
}

void BitcoinExchange::processInputFile(const std::string &inputPath) const
{
	std::ifstream file(inputPath.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip first line

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipePos));
		std::string valStr = trim(line.substr(pipePos + 1));

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		float	val;
		if (!isValidValue(valStr, val))
			continue;

		std::map<std::string, float>::const_iterator it = this->_db.find(date);

		if (it != this->_db.end())
		{
			std::cout << date << " => " << val << " = " << val * it->second << std::endl;
		}
		else
		{
			// search nearest date (<)
			it = this->_db.lower_bound(date);
			if (it == this->_db.begin())
			{
				std::cout << "Error: date earlier than database records." << std::endl;
			}
			else
			{
				--it;
				std::cout << date << " => " << val << " = " << val * it->second << std::endl;
			}
		}
	}
	file.close();
}
