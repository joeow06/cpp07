/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:56:31 by jow               #+#    #+#             */
/*   Updated: 2026/04/15 20:56:32 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <cstdlib>
# include <exception>

template <typename T>
class Array {
	private:
		T *_array;
		unsigned int _numOfElements;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T &operator[](unsigned int i);
		const T &operator[](unsigned int i) const;
		unsigned int size() const;

		class OutOfBoundsException : public std::exception {
			public:
				const char* what() const throw();
		};
} ;

# include "Array.tpp"

#endif
