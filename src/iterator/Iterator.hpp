#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <string>

/*
** ------------------------------- Iterator operations --------------------------------
*/

template <class InputIterator, class Distance>
void advance(InputIterator &it, Distance n);

template <class InputIterator>
typename iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last);

/*
** ------------------------------- Iterator generators --------------------------------
*/

template <class Container>
back_insert_iterator<Container> back_inserter(Container &x);

template <class Container>
front_insert_iterator<Container> front_inserter(Container &x);

template <class Container, class Iterator>
insert_iterator<Container> inserter(Container &x, Iterator it);

namespace ft
{

	/*
	** ------------------------------- Iterator --------------------------------
	*/

	template <class Category, class T, class Distance = ptrdiff_t,
			  class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	template <class Category,			  // iterator::iterator_category
			  class T,					  // iterator::value_type
			  class Distance = ptrdiff_t, // iterator::difference_type
			  class Pointer = T *,		  // iterator::pointer
			  class Reference = T &		  // iterator::reference
			  >
	class iterator
	{
	private:
	public:
		iterator();
		iterator(iterator const &src);
		~iterator();

		iterator &operator=(iterator const &rhs);
	};

	/*
	** ------------------------------- iterator_traits --------------------------------
	*/

	template <class Iterator>
	class iterator_traits;
	template <class T>
	class iterator_traits<T *>;
	template <class T>
	class iterator_traits<const T *>;

	/*
	** ------------------------------- Predefined iterators --------------------------------
	*/

	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef iterator_traits<Iterator>::iterator_category iterator_category;
		typedef iterator_traits<Iterator>::value_type value_type;
		typedef iterator_traits<Iterator>::difference_type difference_type;
		typedef iterator_traits<Iterator>::pointer pointer;
		typedef iterator_traits<Iterator>::reference reference;

	private:
	public:
		reverse_iterator();
		explicit reverse_iterator(iterator_type it);
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it);

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

	template <class Container>
	class back_insert_iterator
	{
	};

	template <class Container>
	class front_insert_iterator;
	template <class Container>
	class insert_iterator;
	template <class T, class charT = char, class traits = char_traits<charT>,
			  class Distance = ptrdiff_t>
	class istream_iterator;
	template <class T, class charT = char, class traits = char_traits<charT> >
	class ostream_iterator;
	template <class charT, class traits = char_traits<charT> >
	class istreambuf_iterator;
	template <class charT, class traits = char_traits<charT> >
	class ostreambuf_iterator;

	/*
	** ------------------------------- Category tags --------------------------------
	*/

	struct input_iterator_tag
	{
	};
	struct output_iterator_tag
	{
	};
	struct forward_iterator_tag
	{
	};
	struct bidirectional_iterator_tag
	{
	};
	struct random_access_iterator_tag
	{
	};
} // namespace ft

#include "Iterator.tpp"

#endif /* ******************************************************** ITERATOR_H */