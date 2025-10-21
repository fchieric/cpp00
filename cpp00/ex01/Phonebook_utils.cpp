/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabi <fabi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:26:04 by fabi              #+#    #+#             */
/*   Updated: 2024/11/18 17:26:48 by fabi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook_utils.hpp"
#include <cstdlib>

std::string	truncate(std::string str, size_t width)
{
	if (str.length() > width)
		return (str.substr(0, width - 1) + ".");
	return (str);
}

std::string	getInput(std::string prompt)
{
	std::string	input;

	input = "";
	while (input.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit(0);
		}
		if (input.empty())
			std::cout << "Field cannot be empty!" << std::endl;
	}
	return (input);
}
