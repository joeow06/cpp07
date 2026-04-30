/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:06:27 by jow               #+#    #+#             */
/*   Updated: 2026/04/15 21:06:28 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _array(NULL), _numOfElements(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _numOfElements(n) {}

template <typename T>
Array<T>::Array(const Array &other) : _array(new T[other._numOfElements]), _numOfElements(other._numOfElements)
{
	for (unsigned int i = 0; i < this->_numOfElements; i++)
		this->_array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] this->_array;
		this->_numOfElements = other._numOfElements;
		_array = new T[_numOfElements];
		for (unsigned int i = 0; i < _numOfElements; i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return ("Index is out of bounds");
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _numOfElements)
		throw OutOfBoundsException();
	return (this->_array[i]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const
{
	if (i >= _numOfElements)
		throw OutOfBoundsException();
	return (this->_array[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_numOfElements);
}

#endif
