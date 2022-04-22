#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <memory>
#include "../iterator/Iterator.hpp"
#include "../iterator/Reverse_iterator.hpp"
#include "../utils/Utils.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator
	{
	public:
		typedef typename ft::iterator_traits<T *>::value_type value_type;
		typedef typename ft::iterator_traits<T *>::difference_type difference_type;
		typedef typename ft::iterator_traits<T *>::pointer pointer;
		typedef typename ft::iterator_traits<T *>::reference reference;
		typedef typename ft::iterator_traits<T *>::iterator_category iterator_category;

	private:
		pointer _p;

	public:
		random_access_iterator() : _p(0){};
		random_access_iterator(pointer p) : _p(p){};
		random_access_iterator(const random_access_iterator &src) { *this = src; };
		~random_access_iterator(){};

		random_access_iterator &operator=(const random_access_iterator &rhs)
		{
			this->_p = rhs._p;
			return *this;
		};

		random_access_iterator &operator++()
		{
			++_p;
			return *this;
		};
		random_access_iterator operator++(int)
		{
			random_access_iterator tmp(*this);
			++_p;
			return tmp;
		};
		random_access_iterator &operator--()
		{
			--_p;
			return *this;
		};
		random_access_iterator operator--(int)
		{
			random_access_iterator<T> tmp(*this);
			--_p;
			return tmp;
		};
		random_access_iterator operator+(const difference_type n) const
		{
			return (_p + n);
		};
		random_access_iterator operator-(const difference_type n) const
		{
			return (_p - n);
		};
		random_access_iterator &operator+=(const difference_type n)
		{
			_p += n;
			return (*this);
		};
		random_access_iterator &operator-=(const difference_type n)
		{
			_p -= n;
			return (*this);
		};

		bool operator==(const random_access_iterator &rhs) const
		{
			return _p == rhs._p;
		};
		bool operator!=(const random_access_iterator &rhs) const
		{
			return _p != rhs._p;
		};
		bool operator<(const random_access_iterator &rhs) const
		{
			return _p < rhs._p;
		};
		bool operator>(const random_access_iterator &rhs) const
		{
			return _p > rhs._p;
		};
		bool operator>=(const random_access_iterator &rhs) const
		{
			return _p >= rhs._p;
		};
		bool operator<=(const random_access_iterator &rhs) const
		{
			return _p <= rhs._p;
		};

		reference operator*() const
		{
			return *_p;
		};
		pointer operator->() const
		{
			return _p;
		};
		reference operator[](difference_type n) const
		{
			return _p[n];
		};
	};

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef random_access_iterator<value_type> iterator;
		typedef random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const iterator> const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;

	private:
		allocator_type _alloc;
		pointer _arr;
		size_type _size;
		size_type _cap;

	public:
		/*
		** ------------------------------- CONSTRUCTOR --------------------------------
		*/
		explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _arr(0), _size(0), _cap(0){};
		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
		{
			_alloc = alloc;
			_arr = _alloc.allocate(n);
			_size = n;
			_cap = n;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_arr + i, val);
		};

		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type(),
			   typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			_alloc = alloc;
			_size = last - first;
			_cap = _size;
			_arr = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_arr + i, *first++);
		};
		vector(const vector &x) : _arr(0), _size(0), _cap(0) { *this = x; };

		/*
		** -------------------------------- DESTRUCTOR --------------------------------
		*/

		~vector()
		{
			if (_size != 0)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_arr + i);
				_alloc.deallocate(_arr, _cap);
			}
		};

		/*
		** --------------------------------- operator= ---------------------------------
		*/

		vector &operator=(const vector &x)
		{
			if (this != &x)
			{
				if (this->_size != 0)
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_arr + i);
					_alloc.deallocate(_arr, _cap);
				}
				this->_alloc = x.get_allocator();
				this->_size = x.size();
				this->_cap = x.capacity();
				this->_arr = this->_alloc.allocate(this->_cap);
				for (size_type i = 0; i < this->_size; i++)
					_alloc.construct(_arr + i, *(x._arr + i));
			}
			return *this;
		};

		/*
		** -------------------------------- Iterators --------------------------------
		*/

		iterator begin() { return iterator(_arr); };
		const_iterator begin() const { return const_iterator(_arr); };

		iterator end() { return iterator(_arr + _size); };
		const_iterator end() const { return const_iterator(_arr + _size); };

		reverse_iterator rbegin() { return reverse_iterator(end()); };
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); };

		reverse_iterator rend() { return reverse_iterator(begin()); };
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };

		// /*
		// ** -------------------------------- Capacity --------------------------------
		// */

		size_type size() const
		{
			return _size;
		};

		size_type max_size() const
		{
			return _alloc.max_size();
		};

		// void resize(size_type n, value_type val = value_type());

		size_type capacity() const
		{
			return _cap;
		};

		// bool empty() const;

		// void reserve(size_type n);

		// /*
		// ** -------------------------------- Element access --------------------------------
		// */

		// reference operator[](size_type n);
		// const_reference operator[](size_type n) const;

		// reference at(size_type n);
		// const_reference at(size_type n) const;

		// reference front();
		// const_reference front() const;

		// reference back();
		// const_reference back() const;

		// /*
		// ** -------------------------------- Modifiers --------------------------------
		// */

		// template <class InputIterator>
		// void assign(InputIterator first, InputIterator last);
		// void assign(size_type n, const value_type &val);

		// void push_back(const value_type &val);
		// void pop_back();

		// iterator insert(iterator position, const value_type &val);
		// void insert(iterator position, size_type n, const value_type &val);
		// template <class InputIterator>
		// void insert(iterator position, InputIterator first, InputIterator last);

		// iterator erase(iterator position);
		// iterator erase(iterator first, iterator last);

		// void swap(vector &x);

		// void clear();

		// /*
		// ** -------------------------------- Allocator --------------------------------
		// */

		allocator_type get_allocator() const
		{
			return _alloc;
		};
	};

	// template <class T, class Alloc>
	// bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
	// template <class T, class Alloc>
	// bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
	// template <class T, class Alloc>
	// bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
	// template <class T, class Alloc>
	// bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
	// template <class T, class Alloc>
	// bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
	// template <class T, class Alloc>
	// bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

	// template <class T, class Alloc>
	// void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	// {
	// 	x.swap(y);
	// };
};

#endif /* ********************************************************** vector_H */