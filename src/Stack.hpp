#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
	public:
		typedef Container container_type;
		typedef typename container_type::value_type value_type;
		typedef typename container_type::size_type size_type;

	protected:
		container_type c;

	public:
		explicit stack(const container_type &ctnr = container_type()) : c(ctnr){};

		bool empty() const
		{
			if (!size())
				return true;
			return false;
		};

		size_type size() const
		{
			return c.size();
		};

		value_type &top()
		{
			return c.back();
		};

		const value_type &top() const
		{
			return c.back();
		};

		void push(const value_type &val)
		{
			c.push_back(val);
		};

		void pop()
		{
			c.pop_back();
		};

		template <typename T1, typename _C1>
		friend bool operator==(const stack<T1, _C1> &lhs, const stack<T1, _C1> &rhs);
		template <typename T1, typename _C1>
		friend bool operator<(const stack<T1, _C1> &lhs, const stack<T1, _C1> &rhs);
	};

	template <typename _Tp, typename _C1>
	bool operator==(const stack<_Tp, _C1> &lhs, const stack<_Tp, _C1> &rhs)
	{
		return lhs.c == rhs.c;
	};

	template <typename _Tp, typename _C1>
	bool operator!=(const stack<_Tp, _C1> &lhs, const stack<_Tp, _C1> &rhs)
	{
		return !(lhs == rhs);
	};

	template <class T1, class _C1>
	bool operator<(const stack<T1, _C1> &lhs, const stack<T1, _C1> &rhs)
	{
		return lhs.c < rhs.c;
	};

	template <class T1, class _C1>
	bool operator<=(const stack<T1, _C1> &lhs, const stack<T1, _C1> &rhs)
	{
		return !(rhs < lhs);
	};

	template <class T1, class _C1>
	bool operator>(const stack<T1, _C1> &lhs, const stack<T1, _C1> &rhs)
	{
		return rhs < lhs;
	};

	template <class T1, class _C1>
	bool operator>=(const stack<T1, _C1> &lhs, const stack<T1, _C1> &rhs)
	{
		return !(lhs < rhs);
	};
};

#endif