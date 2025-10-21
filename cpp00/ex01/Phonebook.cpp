/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabi <fabi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:26:04 by fabi              #+#    #+#             */
/*   Updated: 2025/10/15 21:37:14 by fabi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

Phonebook::Phonebook(void) : _index(0)
{
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void	Phonebook::add(void)
{
	Contact		contact;
	std::string	input;

	input = getInput("First name: ");
	contact.setFirstName(input);
	input = getInput("Last name: ");
	contact.setLastName(input);
	input = getInput("Nickname: ");
	contact.setNickname(input);
	input = getInput("Phone number: ");
	contact.setPhoneNumber(input);
	input = getInput("Darkest secret: ");
	contact.setDarkestSecret(input);
	this->_contacts[this->_index % 8] = contact;
	this->_index++;
	std::cout << "Contact added successfully!" << std::endl;
}

void	Phonebook::print(Contact contact)
{
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

void	Phonebook::search(void)
{
	std::string	input;
	int			index;
	int			max;

	if (this->_index == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	max = this->_index > 8 ? 8 : this->_index;
	for (int i = 0; i < max; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(this->_contacts[i].getFirstName(), 10) << "|";
		std::cout << std::setw(10) << truncate(this->_contacts[i].getLastName(), 10) << "|";
		std::cout << std::setw(10) << truncate(this->_contacts[i].getNickname(), 10) << std::endl;
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		exit(0);
	}
	index = std::atoi(input.c_str());
	if (index < 0 || index >= max)
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	this->print(this->_contacts[index]);
}

Contact	Phonebook::get_contact(int index)
{
	return (this->_contacts[index]);
}
