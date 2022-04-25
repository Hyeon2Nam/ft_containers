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
		typedef Iterator iterator_type;														 // Iterator's type
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category; // Preserves Iterator's category
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;				 // Preserves Iterator's value type
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;	 // Preserves Iterator's difference type
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;					 // Preserves Iterator's pointer type
		typedef typename ft::iterator_traits<Iterator>::reference reference;				 // 	Preserves Iterator's reference type
	private:
		iterator_type base_iterator; // Base iterator

	public:
		reverse_iterator() : base_iterator(){};
		explicit reverse_iterator(iterator_type it) : base_iterator(it){};
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) { base_iterator = rev_it.base_iterator; };

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
			return (base_iterator + n);
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

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() == rhs.base());
	};

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator> &rev_it)
	{
		return rev_it + n;
	};

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator> &lhs,
		const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() - rhs.base();
	};
};

#endif /* ************************************************ REVERSE_ITERATOR_H */