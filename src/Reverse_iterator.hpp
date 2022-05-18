#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include "Iterator.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;

	private:
		iterator_type base_iterator;

	public:
		operator reverse_iterator<const Iterator>() const
		{
			return (reverse_iterator<const Iterator>(base_iterator));
		};

		reverse_iterator() : base_iterator(){};
		explicit reverse_iterator(iterator_type it) : base_iterator(it){};
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : base_iterator(rev_it.base()) {};

		iterator_type base() const
		{
			return base_iterator;
		};

		reference operator*() const
		{
			iterator_type tmp(base_iterator);
			--tmp;
			return *tmp;
		};
		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(base_iterator - n);
		};
		reverse_iterator &operator++()
		{
			--base_iterator;
			return *this;
		};
		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		};
		reverse_iterator &operator+=(difference_type n)
		{
			base_iterator -= n;
			return *this;
		};
		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(base_iterator + n);
		};
		reverse_iterator &operator--()
		{
			++base_iterator;
			return *this;
		};
		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		};
		reverse_iterator &operator-=(difference_type n)
		{
			base_iterator += n;
			return *this;
		};
		pointer operator->() const
		{
			return &(operator*());
		};
		reference operator[](difference_type n) const
		{
			return base_iterator[-n - 1];
		};
	};

	template <typename A, typename B>
	bool operator==(const reverse_iterator<A> &lhs,
					const reverse_iterator<B> &rhs)
	{
		return (lhs.base() == rhs.base());
	};

	template <typename A, typename B>
	bool operator!=(const reverse_iterator<A> &lhs,
					const reverse_iterator<B> &rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template <typename A, typename B>
	bool operator<(const reverse_iterator<A> &lhs,
				   const reverse_iterator<B> &rhs)
	{
		return rhs.base() < lhs.base();
	};

	template <typename A, typename B>
	bool operator<=(const reverse_iterator<A> &lhs,
					const reverse_iterator<B> &rhs)
	{
		return !(rhs < lhs);
	};

	template <typename A, typename B>
	bool operator>(const reverse_iterator<A> &lhs,
				   const reverse_iterator<B> &rhs)
	{
		return rhs < lhs;
	};

	template <typename A, typename B>
	bool operator>=(const reverse_iterator<A> &lhs,
					const reverse_iterator<B> &rhs)
	{
		return !(lhs < rhs);
	};

	template <typename T>
	reverse_iterator<T> operator+(
		typename reverse_iterator<T>::difference_type n,
		const reverse_iterator<T> &rev_it)
	{
		return rev_it + n;
	};

	template <typename T>
	reverse_iterator<T> operator-(
		typename reverse_iterator<T>::difference_type n,
		const reverse_iterator<T> &rev_it)
	{
		return rev_it - n;
	};

	template <typename A, typename B>
	typename reverse_iterator<A>::difference_type operator+(
		const reverse_iterator<A> &lhs,
		const reverse_iterator<B> &rhs)
	{
		return lhs.base() + rhs.base();
	};

	template <typename A, typename B>
	typename reverse_iterator<A>::difference_type operator-(
		const reverse_iterator<A> &lhs,
		const reverse_iterator<B> &rhs)
	{
		return rhs.base() - lhs.base();
	};
};

#endif /* ************************************************ REVERSE_ITERATOR_H */