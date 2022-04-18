#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>

// #include <iostream>
// #include <string>
// #include "../iterator/Iterator.hpp"

// class iterator;
// class const_iterator;
// class random_access_iterator;
// class reverse_iterator;
// class iterator_traits;

// namespace ft
// {
// 	template <class T, class Alloc = std::allocator<T> >
// 	class vector
// 	{
// 	public:
// 		typedef T value_type;
// 		typedef Alloc allocator_type;
// 		typedef allocator_type::reference reference;
// 		typedef allocator_type::const_reference const_reference;
// 		typedef allocator_type::pointer pointer;
// 		typedef allocator_type::const_pointer const_pointer;
// 		typedef random_access_iterator<value_type> iterator;
// 		typedef random_access_iterator<const value_type> const_iterator;
// 		typedef reverse_iterator<iterator> reverse_iterator;
// 		typedef reverse_iterator<const iterator> const_reverse_iterator;
// 		typedef typename iterator_traits<iterator>::difference_type difference_type;
// 		typedef typename allocator_type::size_type size_type;

// 	private:
// 		value_type *arr;

// 	public:
// 		/*
// 		** ------------------------------- CONSTRUCTOR --------------------------------
// 		*/

// 		vector(const allocator_type &alloc = allocator_type());
// 		vector(size_type n, const value_type &val = value_type(),
// 			   const allocator_type &alloc = allocator_type());
// 		template <class InputIterator>
// 		vector(InputIterator first, InputIterator last,
// 			   const allocator_type &alloc = allocator_type());
// 		vector(const vector &x);

// 		/*
// 		** -------------------------------- DESTRUCTOR --------------------------------
// 		*/

// 		~vector();

// 		/*
// 		** --------------------------------- operator= ---------------------------------
// 		*/

// 		vector &operator=(const vector &x);

// 		/*
// 		** -------------------------------- Iterators --------------------------------
// 		*/

// 		iterator begin();
// 		const_iterator begin() const;

// 		iterator end();
// 		const_iterator end() const;

// 		reverse_iterator rbegin();
// 		const_reverse_iterator rbegin() const;

// 		reverse_iterator rend();
// 		const_reverse_iterator rend() const;

// 		/*
// 		** -------------------------------- Capacity --------------------------------
// 		*/

// 		size_type size() const;

// 		size_type max_size() const;

// 		void resize(size_type n, value_type val = value_type());

// 		size_type capacity() const;

// 		bool empty() const;

// 		void reserve(size_type n);

// 		/*
// 		** -------------------------------- Element access --------------------------------
// 		*/

// 		reference operator[](size_type n);
// 		const_reference operator[](size_type n) const;

// 		reference at(size_type n);
// 		const_reference at(size_type n) const;

// 		reference front();
// 		const_reference front() const;

// 		reference back();
// 		const_reference back() const;

// 		/*
// 		** -------------------------------- Modifiers --------------------------------
// 		*/

// 		template <class InputIterator>
// 		void assign(InputIterator first, InputIterator last);
// 		void assign(size_type n, const value_type &val);

// 		void push_back(const value_type &val);
// 		void pop_back();

// 		iterator insert(iterator position, const value_type &val);
// 		void insert(iterator position, size_type n, const value_type &val);
// 		template <class InputIterator>
// 		void insert(iterator position, InputIterator first, InputIterator last);

// 		iterator erase(iterator position);
// 		iterator erase(iterator first, iterator last);

// 		void swap(vector &x);

// 		void clear();

// 		/*
// 		** -------------------------------- Allocator --------------------------------
// 		*/

// 		allocator_type get_allocator() const;
// 	};

// 	template <class T, class Alloc>
// 	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
// 	template <class T, class Alloc>
// 	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
// 	template <class T, class Alloc>
// 	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
// 	template <class T, class Alloc>
// 	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
// 	template <class T, class Alloc>
// 	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
// 	template <class T, class Alloc>
// 	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

// 	template <class T, class Alloc>
// 	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y);
// };

// #include "vector.tpp"

#endif /* ********************************************************** vector_H */