#ifndef MAP_HPP
#define MAP_HPP

#include <cstddef>
#include <iostream>
#include <memory>
#include <exception>
#include "Iterator.hpp"
#include "Reverse_iterator.hpp"
#include "Utils.hpp"
#include "RBT.hpp"

namespace ft
{
	template <class _Key, class _CP, class _Compare>
	class map_value_compare
	{
	private:
		_Compare comp public : map_value_compare() : comp(){};
		map_value_compare(_Compare c) : comp(c){};
		const _Compare &key_comp() const { return comp; };

		bool operator()(const _CP &x, const _CP &y) const
		{
			return comp(x.first, y.first);
		}

		bool operator()(const _CP &x, const _Key &y) const
		{
			return comp(x.first, y);
		}

		bool operator()(const _Key &x, const _CP &y) const
		{
			return comp(x, y.first);
		}

		void swap(map_value_compare &y)
		{
			std::swap(comp, y.comp);
		}
	};

	template <class _Key, class _CP, class _Compare>
	void swap(map_value_compare<_Key, _CP, _Compare> &x,
			  map_value_compare<_Key, _CP, _Compare> &y)
	{
		x.swap(y);
	}

	template <class Key,
			  class T,
			  class Compare = ft::less<Key>,
			  class Alloc = std::allocator<ft::pair<const Key, T>>>
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::size_type size_type;
		typedef typename allocator_type::difference_type difference_type;

		class value_compare
			: public binary_function<value_type, value_type, bool>
		{
			friend class map;

		protected:
			key_compare comp;

			value_compare(key_compare c) : comp(c){};

		public:
			bool operator()(const value_type &x, const value_type &y) const {return comp(x.first, y.first)};
		};

	private:
		typedef map_value_compare<key_type, value_type, key_compare> vc;
		typedef ft::tree<value_type, vc, allocator_type> _base;

		_base _tree;

	public:
		typedef _base::iterator iterator;
		typedef _base::const_iterator const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) : _tree(comp, alloc){};
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type()) : _tree(comp, alloc)
		{
			insert(first, last);
		};
		map(const map &x) : _tree(x._tree){};
		~map(){};

		map &operator=(const map &x)
		{
			_tree = x._tree;
			return *this;
		};

		iterator begin() { return _tree.begin(); };
		const_iterator begin() const {return _tree.begin()};

		iterator end() { return _tree.end(); };
		const_iterator end() const { return _tree.end(); };

		reverse_iterator rbegin() { return reverse_iterator(end()); };
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); };

		reverse_iterator rend() { return reverse_iterator(begin()); };
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };

		bool empty() const { return _tree.size() == 0; };

		size_type size() const { return _tree.size(); };

		size_type max_size() const { return _tree.max_size(); };

		mapped_type &operator[](const key_type &k)
		{
			pair<iterator, bool> p;
			iterator i = find(k);
			if (i == end())
				p = insert(ft::make_pair(k, mapped_type()));
			return p.second;
		};

		pair<iterator, bool> insert(const value_type &val) { return _tree.insert_unique(val); };

		iterator insert(iterator position, const value_type &val) { return _tree.insert_unique(position, val); };

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (const_iterator e = end(); first != last; ++first)
				insert(e, *first);
		};

		void erase(iterator position) { _tree.erase(position); };
		size_type erase(const key_type &k) { return _tree.erase_unique(k); };
		void erase(iterator first, iterator last);

		void swap(map &x) { _tree.swap(x._tree); };

		void clear() { _tree.clear(); };

		key_compare key_comp() const { return _tree.key_comp(); };

		value_compare value_comp() const { return _tree.value_comp(); };

		iterator find(const key_type &k) { return _tree.find(k); };
		const_iterator find(const key_type &k) const { return _tree.find(k); };

		size_type count(const key_type &k) const { return _tree.count_unique(k); };

		iterator lower_bound(const key_type &k) { return _tree.lower_bound(k); };
		const_iterator lower_bound(const key_type &k) const { return _tree.lower_bound(k); };

		iterator upper_bound(const key_type &k) { return _tree.upper_bound(k); };
		const_iterator upper_bound(const key_type &k) const { return _tree.upper_bound(k); };

		pair<const_iterator, const_iterator> equal_range(const key_type &k) const { return _tree.equal_range_unique(k); };
		pair<iterator, iterator> equal_range(const key_type &k) { return _tree.equal_range_unique(k); };

		allocator_type get_allocator() const { return _tree.get_allocator(); };
	};
};

#endif