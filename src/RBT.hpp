#ifndef RBT_HPP
#define RBT_HPP

#include <cstddef>
#include <iostream>
#include <memory>
#include "Iterator.hpp"
#include "Utils.hpp"

#include <__tree>

namespace ft
{
	template <class Tp, class NodePtr, class DiffType>
	class tree_iterator
	{
	};
	template <class Tp, class NodePtr, class DiffType>
	class tree_const_iterator
	{
	};

	template <class Tp, class Compare, class Allocator>
	class tree;
} // namespace ft

#endif