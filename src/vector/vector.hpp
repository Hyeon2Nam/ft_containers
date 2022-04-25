#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <memory>
#include <exception>
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
		random_access_iterator operator+(const difference_type n) const { return (_p + n); };
		random_access_iterator operator-(const difference_type n) const { return (_p - n); };
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

		bool operator==(const random_access_iterator &rhs) const { return _p == rhs._p; };
		bool operator!=(const random_access_iterator &rhs) const { return _p != rhs._p; };
		bool operator<(const random_access_iterator &rhs) const { return _p < rhs._p; };
		bool operator>(const random_access_iterator &rhs) const { return _p > rhs._p; };
		bool operator>=(const random_access_iterator &rhs) const { return _p >= rhs._p; };
		bool operator<=(const random_access_iterator &rhs) const { return _p <= rhs._p; };

		reference operator*() const { return *_p; };
		pointer operator->() const { return _p; };
		reference operator[](difference_type n) const { return _p[n]; };
	};

	template <typename T>
	typename random_access_iterator<T>::difference_type operator==(
		const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return &(*lhs) == &(*rhs);
	}

	template <typename T>
	typename random_access_iterator<T>::difference_type operator!=(
		const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return &(*lhs) != &(*rhs);
	}

	template <typename T>
	typename random_access_iterator<T>::difference_type operator<(
		const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs) { return &(*lhs) < &(*rhs); }

	template <typename T>
	typename random_access_iterator<T>::difference_type operator>(
		const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs) { return &(*lhs) > &(*rhs); }

	template <typename T>
	typename random_access_iterator<T>::difference_type operator<=(
		const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs) { return &(*lhs) <= &(*rhs); }

	template <typename T>
	typename random_access_iterator<T>::difference_type operator>=(
		const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs) { return &(*lhs) >= &(*rhs); }

	template <typename T>
	typename random_access_iterator<T>::difference_type operator+(
		const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs) { return &(*lhs) + &(*rhs); }

	template <typename T>
	typename random_access_iterator<T>::difference_type operator-(
		const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs) { return &(*lhs) - &(*rhs); }

	template <class T>
	typename random_access_iterator<T>::difference_type operator+(
		typename random_access_iterator<T>::difference_type n,
		const random_access_iterator<T> &it)
	{
		return it + n;
	};

	template <class T>
	typename random_access_iterator<T>::difference_type operator-(
		typename random_access_iterator<T>::difference_type n,
		const random_access_iterator<T> &it)
	{
		return it - n;
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
			if (first > last)
				throw std::length_error("vector");

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

		size_type size() const { return _size; };

		size_type max_size() const { return _alloc.max_size(); };

		void resize(size_type n, value_type val = value_type())
		{
			if (n < _size || n > max_size())
			{
				for (size_type i = n; i < _size; i++)
					_alloc.destroy(_arr + n);
				_size = n;
			}
			if (n > _size)
			{
				if (n > _cap)
					reserve(n);
				for (size_type i = _size; i < n; i++)
					_alloc.construct(_arr + i, val);
				_size = n;
			}
		}

		size_type capacity() const { return _cap; };

		bool empty() const
		{
			if (_size == 0)
				return true;
			return false;
		};

		void reserve(size_type n)
		{
			if (n <= _cap)
				return;

			pointer tmp = _alloc.allocate(_cap);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(tmp + i, *(_arr + i));

			if (_size != 0)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_arr + i);
				_alloc.deallocate(_arr, _cap);
			}

			_cap = n;
			_arr = _alloc.allocate(_cap);
			_arr = tmp;
		}

		// /*
		// ** -------------------------------- Element access --------------------------------
		// */

		reference operator[](size_type n) { return *(_arr + n); };
		const_reference operator[](size_type n) const { return *(_arr + n); };

		reference at(size_type n)
		{
			if (n >= _size || n < 0)
				throw std::out_of_range("vector");
			return *(_arr + n);
		};
		const_reference at(size_type n) const
		{
			if (n >= _size || n < 0)
				throw std::out_of_range("vector");
			return *(_arr + n);
		};

		reference front() { return *_arr; };
		const_reference front() const { return *_arr; };

		reference back() { return *(_arr + (_size - 1)); };
		const_reference back() const { return *(_arr + (_size - 1)); };

		// /*
		// ** -------------------------------- Modifiers --------------------------------
		// */

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			if (first > last)
				throw std::length_error("vector");

			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_arr + i);

			_size = last - first;
			_cap = _size;
			_arr = _alloc.allocate(_cap);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_arr + i, *first++);
		};
		void assign(size_type n, const value_type &val)
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_arr + i);
			if (n > _cap)
				_alloc.deallocate(_arr, _cap);

			_size = n;
			_cap = n;
			_arr = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_arr + i, val);
		};

		void push_back(const value_type &val)
		{
			if (_size + 1 > max_size())
				return;
			if (_size + 1 >= _cap)
				reserve(_cap * 2);
			_alloc.construct(_arr + _size, val);
			++_size;
		};

		void pop_back()
		{
			if (!_size)
				return;
			--_size;
			_alloc.destroy(_arr + _size);
		};

		iterator insert(iterator position, const value_type &val)
		{
			difference_type diff = position - _arr;
			pointer tmp;
			difference_type i = 0;

			if (_size + 1 >= _cap)
				_cap *= 2;

			tmp = _alloc.allocate(_cap);
			for (; i < diff; i++)
				_alloc.construct(tmp + i, *(_arr + i));
			_alloc.construct(tmp + i, val);
			i++;
			_size++;
			for (; i < static_cast<difference_type>(_size); i++)
				_alloc.construct(tmp + i, *(_arr + (i - 1)));

			for (size_type i = 0; i < _size - 1; i++)
				_alloc.destroy(_arr + i);
			_alloc.deallocate(_arr, _cap);

			_arr = tmp;

			return _arr + diff;
		};
		void insert(iterator position, size_type n, const value_type &val)
		{
			difference_type diff = position - _arr;
			pointer tmp;
			difference_type i = 0;

			while (_size + n >= _cap)
				_cap *= 2;

			tmp = _alloc.allocate(_cap);
			for (; i < diff; i++)
				_alloc.construct(tmp + i, *(_arr + i));
			for (; i < diff + static_cast<difference_type>(n); i++)
				_alloc.construct(tmp + i, val);
			i++;
			for (; i < static_cast<difference_type>(_size + n); i++)
				_alloc.construct(tmp + i, *(_arr + (i - static_cast<difference_type>(n))));

			for (size_type i = 0; i < _size - 1; i++)
				_alloc.destroy(_arr + i);
			_alloc.deallocate(_arr, _cap);
			_size += n;
			_arr = tmp;
		};

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			if (first > last)
				return;

			difference_type pos = position - _arr;
			difference_type diff = last - first;
			difference_type i = 0;
			pointer tmp;

			while (_size + static_cast<size_type>(diff) >= _cap)
				_cap *= 2;

			tmp = _alloc.allocate(_cap);
			for (; i < pos; i++)
				_alloc.construct(tmp + i, *(_arr + i));
			for (; first != last; i++)
				_alloc.construct(tmp + i, (*first)++);
			for (; i < static_cast<difference_type>(_size) + diff; i++)
				_alloc.construct(tmp + i, *(_arr + (i - diff)));

			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_arr + i);
			_alloc.deallocate(_arr, _cap);

			_size += diff;
			_arr = tmp;
		};

		iterator erase(iterator position)
		{
			if (_size - 1 < 0)
				return;

			bool is_end = false;

			if (position == end())
				is_end = true;

			pointer tmp = _alloc.allocate(_cap);
			difference_type diff = position - _arr;
			size_type i = 0;

			for (; i < diff; i++)
				_alloc.construct(tmp + i, *(_arr + i));
			i++;
			for (; i < _size; i++)
				_alloc.construct(tmp + (i - 1), *(_arr + i));

			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_arr + i);
			_alloc.deallocate(_arr, _cap);

			_size--;
			_arr = tmp;

			if (is_end)
				return (end());

			return (_arr + diff);
		};

		iterator erase(iterator first, iterator last)
		{

			bool is_end = false;
			if (last == end())
				is_end = true;
			pointer tmp = _alloc.allocate(_cap);
			difference_type diff = first - _arr;
			difference_type diff2 = last - first;
			size_type i = 0;

			for (; i < diff; i++)
				_alloc.construct(tmp + i, *(_arr + i));
			i += diff2;
			for (; i < _size; i++)
				_alloc.construct(tmp + (i - diff2), *(_arr + i));

			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_arr + i);
			_alloc.deallocate(_arr, _cap);

			_size -= diff2;
			_arr = tmp;

			if (is_end)
				return end();

			return (_arr + diff);
		};

		void swap(vector &x)
		{
			pointer ta = x._arr;
			size_type ts = x._size;
			size_type tc = x._cap;
			allocator_type tal = x._alloc;

			x._arr = this->_arr;
			x._size = this->_size;
			x._cap = this->_cap;
			x._alloc = this->_alloc;

			this->_arr = ta;
			this->_size = ts;
			this->_cap = tc;
			this->_alloc = tal;
		};

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_arr + i);
			_size = 0;
		};

		// /*
		// ** -------------------------------- Allocator --------------------------------
		// */

		allocator_type get_allocator() const
		{
			return _alloc;
		};
	};

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		return equal(lhs.begin(), lhs.end(), rhs.begin());
	};
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	};
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(rhs < lhs);
	};
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return lhs < rhs;
	};
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	};

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	};
};

#endif /* ********************************************************** vector_H */