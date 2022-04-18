#ifndef ITERATOR_TPP
#define ITERATOR_TPP

#include "Iterator.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T>
ft::random_access_iterator<T>::random_access_iterator() : _p(0){};

template <typename T>
ft::random_access_iterator<T>::random_access_iterator(T *p) : _p(p){};

template <typename T>
ft::random_access_iterator<T>::random_access_iterator(const random_access_iterator &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename T>
ft::random_access_iterator<T>::~random_access_iterator() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <typename T>
ft::random_access_iterator<T> &ft::random_access_iterator<T>::operator=(const ft::random_access_iterator<T> &rhs)
{
	if (this != &rhs)
	{
		if (*_p)
			delete _p;
		this->_p = rhs._p;
	}
	return *this;
}

template <typename T>
ft::random_access_iterator<T> &ft::random_access_iterator<T>::operator++()
{
	++_p;
	return *this;
}

template <typename T>
ft::random_access_iterator<T> ft::random_access_iterator<T>::operator++(int)
{
	ft::random_access_iterator<T> tmp(*this);
	++_p;
	return tmp;
}

template <typename T>
ft::random_access_iterator<T> &ft::random_access_iterator<T>::operator--()
{
	--_p;
	return *this;
}

template <typename T>
ft::random_access_iterator<T> ft::random_access_iterator<T>::operator--(int)
{
	ft::random_access_iterator<T> tmp(*this);
	--_p;
	return tmp;
}

template <typename T>
bool ft::random_access_iterator<T>::operator==(const random_access_iterator &rhs) const
{
	return _p == rhs._p;
}

template <typename T>
bool ft::random_access_iterator<T>::operator!=(const random_access_iterator &rhs) const
{
	return _p != rhs._p;
}


template <typename T>
bool ft::random_access_iterator<T>::operator<(const random_access_iterator &rhs) const
{
	return _p < rhs._p;
}


template <typename T>
bool ft::random_access_iterator<T>::operator>(const random_access_iterator &rhs) const
{
	return _p > rhs._p;
}


template <typename T>
bool ft::random_access_iterator<T>::operator>=(const random_access_iterator &rhs) const
{
	return _p >= rhs._p;
}


template <typename T>
bool ft::random_access_iterator<T>::operator<=(const random_access_iterator &rhs) const
{
	return _p <= rhs._p;
}

template <typename T>
T &ft::random_access_iterator<T>::operator*() const
{
	return *_p;
}

template <typename T>
T *ft::random_access_iterator<T>::operator->() const
{
	return _p;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

#endif

/* ************************************************************************** */