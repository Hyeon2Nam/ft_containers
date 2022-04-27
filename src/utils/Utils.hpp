#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include "../iterator/Iterator.hpp"

namespace ft
{
	template <class T1, class T2>
	bool equal(T1 first1, T1 last1, T2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	};

	template <class T1, class T2, class BinaryPredicate>
	bool equal(T1 first1, T1 last1, T2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	};

	template <class T1, class T2>
	bool lexicographical_compare(T1 first1, T1 last1, T2 first2, T2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	};

	template <class T1, class T2, class Compare>
	bool lexicographical_compare(T1 first1, T1 last1, T2 first2, T2 last2, Compare comp)
	{
		for (; first2 != last2; ++first1, (void)++first2)
		{
			if (first1 == last1 || comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
		}
		return false;
	};

	template <class T>
	typename ft::iterator_traits<T>::difference_type
	distance(T first, T last)
	{
		typename ft::iterator_traits<T>::difference_type i = 0;
		for (; first != last; i++)
			first++;
		return i;
	};

	template <bool Cond, class T = void>
	struct enable_if
	{
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template <class T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		operator T() { return v; }
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template <class T>
	struct is_integral : public false_type
	{
	};

	template <>
	struct is_integral<bool> : public true_type
	{
	};

	template <>
	struct is_integral<char> : public true_type
	{
	};

	template <>
	struct is_integral<char16_t> : public true_type
	{
	};

	template <>
	struct is_integral<char32_t> : public true_type
	{
	};

	template <>
	struct is_integral<wchar_t> : public true_type
	{
	};

	template <>
	struct is_integral<signed char> : public true_type
	{
	};

	template <>
	struct is_integral<short int> : public true_type
	{
	};

	template <>
	struct is_integral<int> : public true_type
	{
	};

	template <>
	struct is_integral<long int> : public true_type
	{
	};

	template <>
	struct is_integral<long long int> : public true_type
	{
	};

	template <>
	struct is_integral<unsigned char> : public true_type
	{
	};

	template <>
	struct is_integral<unsigned short int> : public true_type
	{
	};

	template <>
	struct is_integral<unsigned int> : public true_type
	{
	};

	template <>
	struct is_integral<unsigned long int> : public true_type
	{
	};

	template <>
	struct is_integral<unsigned long long int> : public true_type
	{
	};

	template <class InputIter>
	typename ft::iterator_traits<InputIter>::difference_type diff(InputIter first, InputIter last)
	{
		typename ft::iterator_traits<InputIter>::difference_type i = 0;

		for (; first != last; ++first)
			++i;
		return (i);
	}
};

#endif /* *********************************************************** UTILS_H */