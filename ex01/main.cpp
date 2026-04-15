/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:09:50 by jow               #+#    #+#             */
/*   Updated: 2026/04/15 17:09:51 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void printChar(const char &c)
{
	std::cout << c << std::endl;
}

void stringToUpper(std::string &s)
{
    for (size_t i = 0; i < s.size(); i++)
        s[i] = std::toupper(s[i]);
}

void charToUpper(char &a)
{
	a = std::toupper(a);
}

void plusOne(int &a)
{
	a *= 10;
}

int main(void)
{
	// integer test
	int array1[5] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
		std::cout << array1[i] << " ";
	std::cout << std::endl;
	iter(array1, 5, &plusOne);
	for (int i = 0; i < 5; i++)
		std::cout << array1[i] << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	// character test
	char array2[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	for (int i = 0; i < 6; i++)
		std::cout << array2[i] << " ";
	std::cout << std::endl;
	iter(array2, 6, &charToUpper);
	for (int i = 0; i < 6; i++)
		std::cout << array2[i] << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	// string test
	std::string array3[4] = {"my", "name", "is", "joe"};
	for (int i = 0; i < 4; i++)
		std::cout << array3[i] << " ";
	std::cout << std::endl;
	iter(array3, 4, &stringToUpper);
	for (int i = 0; i < 4; i++)
		std::cout << array3[i] << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	// const reference test
	iter(array2, 6, &printChar);
}
