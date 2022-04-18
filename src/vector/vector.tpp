#ifndef VECTOR_TPP
#define VECTOR_TPP

#include <iostream>
#include <string>
#include "./vector.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T>
ft::vector<T>::vector()
{
}

template <typename T>
ft::vector<T>::vector(const ft::vector<T> &src)
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename T>
ft::vector<T>::~vector()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <typename T>
ft::vector<T> &ft::vector<T>::operator=(ft::vector<T> const &rhs)
{
	(void)rhs;
	// if ( this != &rhs )
	//{
	// this->_value = rhs.getValue();
	//}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/





/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */

#endif