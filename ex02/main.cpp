/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:56:33 by jow               #+#    #+#             */
/*   Updated: 2026/04/15 20:56:34 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

int main()
{
	std::cout << "--- Default constructor ---" << std::endl;
	{
		Array<int> a;
		std::cout << "a.size() = " << a.size() << std::endl;
	}

	std::cout << "\nConstructor with n + write/read" << std::endl;
	{
		Array<int> a(5);
		std::cout << "a.size() = " << a.size() << std::endl;

		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = static_cast<int>(i) * 10;

		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
	}

	std::cout << "\nOut of bounds (non-const)" << std::endl;
	{
		Array<int> a(3);
		try
		{
			std::cout << a[3] << std::endl; // invalid: last valid is 2
		}
		catch (const std::exception &e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\nOut of bounds (const)" << std::endl;
	{
		Array<int> a(2);
		a[0] = 42;
		a[1] = 84;

		const Array<int> ca(a);
		try
		{
			std::cout << ca[2] << std::endl; // invalid
		}
		catch (const std::exception &e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\nCopy constructor (deep copy)" << std::endl;
	{
		Array<int> a(3);
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = static_cast<int>(i + 1);
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		std::cout << std::endl;

		Array<int> b(a);     // copy
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << "b[" << i << "] = " << b[i] << std::endl;
		std::cout << std::endl;

		b[0] = 999;          // modify copy
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << "b[" << i << "] = " << b[i] << std::endl;
		std::cout << std::endl;

		std::cout << "a[0] = " << a[0] << " (should be 1)" << std::endl;
		std::cout << "b[0] = " << b[0] << " (should be 999)" << std::endl;
	}
	std::cout << "\nCopy assignment (deep copy + self-assignment)" << std::endl;
	{
		Array<int> a(4);	// array a
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = static_cast<int>(i) + 10;
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		std::cout << std::endl;

		Array<int> b(1);	// array b
		b[0] = -1;	//modify
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << "b[" << i << "] = " << b[i] << std::endl;
		std::cout << std::endl;

		b = a;      // assignment
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << "b[" << i << "] = " << b[i] << std::endl;
		std::cout << std::endl;

		b[1] = 777; // modify assigned copy
		std::cout << "a[1] = " << a[1] << " (should be 11)" << std::endl;
		std::cout << "b[1] = " << b[1] << " (should be 777)" << std::endl;
	}
	std::cout << "\nArray Char Test" << std::endl;
	{
		Array<char> charArray(3);
		char alphabet = 'a';
		for (unsigned int i = 0; i < charArray.size(); i++)
		{
			charArray[i] = alphabet;
			alphabet++;
		}
		for (unsigned int i = 0; i < charArray.size(); i++)
			std::cout << "charArray[" << i << "] = " << charArray[i] << std::endl;
	}
	return 0;
}
