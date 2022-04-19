#ifndef REVERSE_ITERATOR_TPP
#define REVERSE_ITERATOR_TPP

#include <iostream>
#include "Reverse_iterator.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator() : base_iterator() {}

template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(typename ft::reverse_iterator<Iterator>::iterator_type it) : base_iterator(it) {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <class Iterator>
typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator*() const
{
	iterator_type tmp(base_iterator);
	--tmp;
	return *tmp;
}

template <class Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator+(
	typename ft::reverse_iterator<Iterator>::difference_type n) const
{
	return reverse_iterator(base_iterator - n);
}

template <class Iterator>
ft::reverse_iterator<Iterator> &ft::reverse_iterator<Iterator>::operator++()
{
	--base_iterator;
	return *this;
}

template <class Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator++(int)
{
	ft::reverse_iterator<Iterator> temp = *this;
	--(*this);
	return temp;
}

template <class Iterator>
ft::reverse_iterator<Iterator> &ft::reverse_iterator<Iterator>::operator+=(
	typename ft::reverse_iterator<Iterator>::difference_type n)
{
	base_iterator -= n;
	return *this;
}

template <class Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator-(
	typename ft::reverse_iterator<Iterator>::difference_type n) const
{
	return ft::reverse_iterator(base_iterator + n);
}

template <class Iterator>
ft::reverse_iterator<Iterator> &ft::reverse_iterator<Iterator>::operator--()
{
	++base_iterator;
	return *this;
}

template <class Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator--(int)
{
	ft::reverse_iterator<Iterator> temp = *this;
	++(*this);
	return temp;
}

template <class Iterator>
ft::reverse_iterator<Iterator> &ft::reverse_iterator<Iterator>::operator-=(
	typename ft::reverse_iterator<Iterator>::difference_type n)
{
	base_iterator += n;
	return *this;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::pointer ft::reverse_iterator<Iterator>::operator->() const
{
	return &(ft::reverse_iterator<Iterator>::operator*());
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator[](
	typename ft::reverse_iterator<Iterator>::difference_type n) const
{
	return base_iterator[-n - 1];
}

template <class Iterator>
bool ft::operator==(const ft::reverse_iterator<Iterator> &lhs,
					const ft::reverse_iterator<Iterator> &rhs)
{
	return (lhs.base() == rhs.base());
}

template <class Iterator>
bool ft::operator!=(const ft::reverse_iterator<Iterator> &lhs,
					const ft::reverse_iterator<Iterator> &rhs)
{
	return (lhs.base() != rhs.base());
}

template <class Iterator>
bool ft::operator<(const ft::reverse_iterator<Iterator> &lhs,
				   const ft::reverse_iterator<Iterator> &rhs)
{
	return (lhs.base() < rhs.base());
}

template <class Iterator>
bool ft::operator<=(const ft::reverse_iterator<Iterator> &lhs,
					const ft::reverse_iterator<Iterator> &rhs)
{
	return (lhs.base() <= rhs.base());
}

template <class Iterator>
bool ft::operator>(const ft::reverse_iterator<Iterator> &lhs,
				   const ft::reverse_iterator<Iterator> &rhs)
{
	return (lhs.base() > rhs.base());
}

template <class Iterator>
bool ft::operator>=(const ft::reverse_iterator<Iterator> &lhs,
					const ft::reverse_iterator<Iterator> &rhs)
{
	return (lhs.base() >= rhs.base());
}

template <class Iterator>
ft::reverse_iterator<Iterator> ft::operator+(
	typename reverse_iterator<Iterator>::difference_type n,
	const reverse_iterator<Iterator> &rev_it)
{
	return rev_it + n;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::difference_type operator-(
	const ft::reverse_iterator<Iterator> &lhs,
	const ft::reverse_iterator<Iterator> &rhs)
{
	return lhs.base() - rhs.base();
}

/*
** --------------------------------- METHODS ----------------------------------
*/

template <class Iterator>
typename ft::reverse_iterator<Iterator>::iterator_type ft::reverse_iterator<Iterator>::base() const
{
	return base_iterator;
}

#endif
/* ************************************************************************** */