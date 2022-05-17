#ifndef MAP_HPP
#define MAP_HPP

#include <cstddef>
#include <iostream>
#include <memory>
#include <exception>
#include "Iterator.hpp"
#include "Reverse_iterator.hpp"
#include "Utils.hpp"
#include "BST.hpp"

namespace ft
{
	template <class _Key, class _CP, class _Compare>
	class map_value_compare
	{
	private:
		_Compare comp;

	public:
		map_value_compare() : comp(){};
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
			  class Alloc = std::allocator<ft::pair< Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<key_type, mapped_type> value_type;
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
			bool operator()(const value_type &x, const value_type &y) const { return comp(x.first, y.first); };
		};

	private:
		typedef map_value_compare<key_type, value_type, key_compare> vc;
		typedef ft::tree<value_type, vc, allocator_type> _base;

		_base _tree;
		key_compare comp;

	public:
		typedef typename _base::iterator iterator;
		typedef typename _base::const_iterator const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) : _tree(comp, alloc){};

		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) : _tree(comp, alloc)
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
		const_iterator begin() const { return _tree.begin(); };

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
			pair<iterator, bool> p = insert(ft::make_pair(k, mapped_type()));
			return p.first->second;
		};

		pair<iterator, bool> insert(const value_type &val) { return _tree.insert_unique(val); };
		// hint
		iterator insert(iterator position, const value_type &val) { return _tree.insert_unique(position, val); };
		// range
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (; first != last; ++first)
				_tree.insert_unique(*first);
		};

		void erase(iterator position) { _tree.erase(position); };
		size_type erase(const key_type &k) { return _tree.erase_unique(k); };
		void erase(const_iterator first, const_iterator last) { return _tree.erase(first, last); };

		void swap(map &x) { _tree.swap(x._tree); };

		void clear() { _tree.clear(); };

		key_compare key_comp() const { return _tree.key_comp(); };

		value_compare value_comp() const { return value_comp(_tree.key_comp()); };

		iterator find(const key_type &k) { return _tree.find(k); };
		const_iterator find(const key_type &k) const { return _tree.find(k); };

		size_type count(const key_type &k) const { return _tree.count_unique(k); };

		iterator lower_bound(const key_type &k)
		{ 
			iterator b = begin();

			while (b != end())
			{
				if (!comp(b->first, k))
					break;
				b++;
			}

			return b;
		};
		const_iterator lower_bound(const key_type &k) const {
			const_iterator b = begin();

			while (b != end())
			{
				if (!comp(k, k))
					break;
				++b;
			}

			return b;			
		};

		iterator upper_bound(const key_type &k)
		{
			iterator b = begin();

			while (b != end())
			{
				if (comp(k, b->first))
					break;
				b++;
			}

			return b;
		};
		const_iterator upper_bound(const key_type &k) const
		{
			const_iterator b = begin();

			while (b != end())
			{
				if (comp(k, b->first))
					break;
				b++;
			}

			return b;
		};

		pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			return ft::make_pair(lower_bound(k), upper_bound(k));			
		}
		pair<iterator, iterator> equal_range(const key_type &k)
		{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}
		allocator_type get_allocator() const { return _tree.get_allocator(); };
	};
};

#endif