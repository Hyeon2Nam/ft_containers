#ifndef ITERATOR_TPP
#define ITERATOR_TPP

#include "iterator.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T>
ft::random_access_iterator<T>::random_access_iterator()
{
	ft::random_access_iterator<T>::_p = 0;
}

template <typename T>
ft::random_access_iterator<T>::random_access_iterator(T *p)
{
	ft::random_access_iterator<T>::_p(p);
}

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
		if (*ft::random_access_iterator<T>::_p)
			delete ft::random_access_iterator<T>::_p;
		this->ft::random_access_iterator<T>::_p = rhs.ft::random_access_iterator<T>::_p;
	}
	return *this;
}

template <typename T>
ft::random_access_iterator<T> &ft::random_access_iterator<T>::operator++()
{
	++ft::random_access_iterator<T>::_p;
	return *this;
}

template <typename T>
ft::random_access_iterator<T> ft::random_access_iterator<T>::operator++(int)
{
	ft::random_access_iterator<T> tmp(*this);
	++ft::random_access_iterator<T>::_p;
	return tmp;
}

template <typename T>
ft::random_access_iterator<T> &ft::random_access_iterator<T>::operator--()
{
	--ft::random_access_iterator<T>::_p;
	return *this;
}

template <typename T>
ft::random_access_iterator<T> ft::random_access_iterator<T>::operator--(int)
{
	ft::random_access_iterator<T> tmp(*this);
	--ft::random_access_iterator<T>::_p;
	return tmp;
}

template <typename T>
ft::random_access_iterator<T> ft::random_access_iterator<T>::operator+(
	const typename ft::random_access_iterator<T>::difference_type n) const
{
	return (ft::random_access_iterator<T>::_ptr + n);
};

template <typename T>
ft::random_access_iterator<T> ft::random_access_iterator<T>::operator-(
	const typename ft::random_access_iterator<T>::difference_type n) const
{
	return (ft::random_access_iterator<T>::_ptr - n);
};

template <typename T>
ft::random_access_iterator<T> &ft::random_access_iterator<T>::operator+=(
	const typename ft::random_access_iterator<T>::difference_type n)
{
	ft::random_access_iterator<T>::_ptr += n;
	return (*this);
};

template <typename T>
ft::random_access_iterator<T> &ft::random_access_iterator<T>::operator-=(
	const typename ft::random_access_iterator<T>::difference_type n)
{
	ft::random_access_iterator<T>::_ptr -= n;
	return (*this);
};

template <typename T>
bool ft::random_access_iterator<T>::operator==(const random_access_iterator &rhs) const
{
	return ft::random_access_iterator<T>::_p == rhs.ft::random_access_iterator<T>::_p;
}

template <typename T>
bool ft::random_access_iterator<T>::operator!=(const random_access_iterator &rhs) const
{
	return ft::random_access_iterator<T>::_p != rhs.ft::random_access_iterator<T>::_p;
}

template <typename T>
bool ft::random_access_iterator<T>::operator<(const random_access_iterator &rhs) const
{
	return ft::random_access_iterator<T>::_p < rhs.ft::random_access_iterator<T>::_p;
}

template <typename T>
bool ft::random_access_iterator<T>::operator>(const random_access_iterator &rhs) const
{
	return ft::random_access_iterator<T>::_p > rhs.ft::random_access_iterator<T>::_p;
}

template <typename T>
bool ft::random_access_iterator<T>::operator>=(const random_access_iterator &rhs) const
{
	return ft::random_access_iterator<T>::_p >= rhs.ft::random_access_iterator<T>::_p;
}

template <typename T>
bool ft::random_access_iterator<T>::operator<=(const random_access_iterator &rhs) const
{
	return ft::random_access_iterator<T>::_p <= rhs.ft::random_access_iterator<T>::_p;
}

template <typename T>
typename ft::random_access_iterator<T>::reference ft::random_access_iterator<T>::operator*() const
{
	return *ft::random_access_iterator<T>::_p;
}

template <typename T>
typename ft::random_access_iterator<T>::pointer ft::random_access_iterator<T>::operator->() const
{
	return ft::random_access_iterator<T>::_p;
}

template <typename T>
typename ft::random_access_iterator<T>::reference ft::random_access_iterator<T>::operator[](
	typename ft::random_access_iterator<T>::difference_type n) const
{
	return ft::random_access_iterator<T>::_p[n];
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

#endif

/* ************************************************************************** */