#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include "iterator.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef typename Iterator iterator_type;										 // Iterator's type
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category; // Preserves Iterator's category
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;				 // Preserves Iterator's value type
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;	 // Preserves Iterator's difference type
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;					 // Preserves Iterator's pointer type
		typedef typename ft::iterator_traits<Iterator>::reference reference;				 // 	Preserves Iterator's reference type
	private:
		iterator_type base_iterator; // Base iterator

	public:
		reverse_iterator();
		explicit reverse_iterator(iterator_type it);
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it)
		{
			base_iterator = rev_it.base_iterator;
		};

		iterator_type base() const;

		reference operator*() const;
		reverse_iterator operator+(difference_type n) const;
		reverse_iterator &operator++();
		reverse_iterator operator++(int);
		reverse_iterator &operator+=(difference_type n);
		reverse_iterator operator-(difference_type n) const;
		reverse_iterator &operator--();
		reverse_iterator operator--(int);
		reverse_iterator &operator-=(difference_type n);
		pointer operator->() const;
		reference operator[](difference_type n) const;
	};

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs);

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs);

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs);

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs);

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs);

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs);

	template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator> &rev_it);

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator> &lhs,
		const reverse_iterator<Iterator> &rhs);
};

#include "Reverse_iterator.tpp"

#endif /* ************************************************ REVERSE_ITERATOR_H */