#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
	struct input_iterator_tag
	{
	};
	struct output_iterator_tag
	{
	};
	struct forward_iterator_tag : public input_iterator_tag
	{
	};
	struct bidirectional_iterator_tag : public forward_iterator_tag
	{
	};
	struct random_access_iterator_tag : public bidirectional_iterator_tag
	{
	};

	template <class Iterator>
	class iterator_traits
	{
	public:
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
	};

	template <class T>
	class iterator_traits<T *>
	{
	public:
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef random_access_iterator_tag iterator_category;
		typedef T *pointer;
		typedef T &reference;
	};

	template <class T>
	class iterator_traits<const T *>
	{
	public:
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef random_access_iterator_tag iterator_category;
		typedef const T *pointer;
		typedef const T &reference;
	};

	template <class Category,			  // iterator::iterator_category
			  class T,					  // iterator::value_type
			  class Distance = ptrdiff_t, // iterator::difference_type
			  class Pointer = T *,		  // iterator::pointer
			  class Reference = T &		  // iterator::reference
			  >
	class iterator
	{
	public:
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	template <typename T>
	class random_access_iterator : public ft::iterator<random_access_iterator, T>
	{
	private:
		T *_p;

	public:
		random_access_iterator();
		random_access_iterator(T *p);
		random_access_iterator(const random_access_iterator &src);
		~random_access_iterator();
		random_access_iterator &operator=(const random_access_iterator &rhs);

		random_access_iterator &operator++();
		random_access_iterator operator++(int);
		random_access_iterator &operator--();
		random_access_iterator operator--(int);
		random_access_iterator operator+(const difference_type n) const
		{
			return (_ptr + n);
		};
		random_access_iterator operator-(const difference_type n) const
		{
			return (_ptr - n);
		};
		random_access_iterator &operator+=(const difference_type n) const
		{
			_ptr += n;
			return (*this);
		};
		random_access_iterator &operator-=(const difference_type n) const
		{
			_ptr -= n;
			return (*this);
		};

		bool operator==(const random_access_iterator &rhs) const;
		bool operator!=(const random_access_iterator &rhs) const;
		bool operator<(const random_access_iterator &rhs) const;
		bool operator>(const random_access_iterator &rhs) const;
		bool operator>=(const random_access_iterator &rhs) const;
		bool operator<=(const random_access_iterator &rhs) const;

		T &operator*() const;
		T *operator->() const T operator[](const difference_type n) const
		{
			return _ptr[n];
		}
	};

} // namespace ft

#include "Iterator.tpp"

#endif
