#ifndef RBT_HPP
#define RBT_HPP

#include <cstddef>
#include <iostream>
#include <memory>
#include "Iterator.hpp"
#include "Utils.hpp"

namespace ft
{
	template <typename Pair>
	struct Node
	{
		Pair value;
		Node *left;
		Node *right;
		Node *parent;

		Node() : value(NULL), left(NULL), right(NULL), parent(NULL){};
		Node(const Pair &src) : value(src), left(NULL), right(NULL), parent(NULL){};
		Node(const Node &src) { *this = src; };
		~Node(){};

		Node &operator=(const Node &rhs)
		{
			if (this != &rhs)
			{
				this->value = rhs.value;
				this->left = rhs.left;
				this->right = rhs.right;
				this->parent = rhs.parent;
			}
			return *this;
		};
	};

	template <typename T, typename Node, typename Pointer, typename Refernce>
	class Tree_iterator
	{
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef Pointer pointer;
		typedef Refernce reference;
		typedef bidirectional_iterator_tag iterator_category;

		typedef Node node_type;
		typedef Node *node_pointer;

	private:
		node_pointer node;

	public:
		Tree_iterator() : node(){};
		Tree_iterator(const node_pointer n) : node(n){};
		Tree_iterator(const Tree_iterator &src) { *this = src; };
		~Tree_iterator(){};

		operator Tree_iterator<const T, Node, Pointer, Refernce>() const
		{
			return (Tree_iterator<const T, Node, Pointer, Refernce>(this->node));
		};

		Tree_iterator &operator=(const Tree_iterator &rhs)
		{
			if (this != &rhs)
				this->node = rhs.node;
			return *this;
		};

		reference operator*() const { return node->value; };
		pointer operator->() const { return &node->value; };

		Tree_iterator &operator++()
		{
			node_pointer tmp = node;
			if (node->right)
			{
				tmp = tmp->right;
				while (tmp->left)
					tmp = tmp->left;
				this->node = tmp;

				return *this;
			}

			node_pointer parent = tmp->parent;

			if (parent && tmp == parent->right)
				tmp = parent;
			parent = parent->parent;
			this->node = parent;
			return *this;
		};

		Tree_iterator operator++(int)
		{
			node_pointer tmp(node);
			operator++();
			return tmp;
		};

		Tree_iterator &operator--()
		{
			node_pointer tmp = node;

			if (node->left)
			{
				tmp = tmp->left;
				while (tmp->right)
					tmp = tmp->right;
				return tmp;
			}

			node_pointer parent = tmp->parent;

			if (parent && tmp == parent->left)
				tmp = parent;
			parent = parent->parent;
			return parent;
		};

		Tree_iterator operator--(int)
		{
			node_pointer tmp(node);
			operator--();
			return tmp;
		};

		bool operator==(const Tree_iterator &x)
		{
			return x.node == this->node;
		};
		bool operator!=(const Tree_iterator &x)
		{
			return !(x.node == this->node);
		};
	};

	template <class Tp, class Allocator = std::allocator<Tp> >
	class tree
	{
	public:
		typedef Tp value_type;
		typedef typename Tp::first_type key_type;
		// typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef Node<Tp> node_type;
		typedef Node<Tp> *node_pointer;

		typedef typename allocator_type::size_type size_type;

		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef Tree_iterator<value_type, node_type, pointer, reference> iterator;
		typedef Tree_iterator<const value_type, node_type, pointer, reference> const_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;

		typedef typename Allocator::template rebind<node_type>::other alloc_node;

	private:
		size_type _size;
		alloc_node _alloc;
		// key_compare cmp;

		node_pointer root;
		node_pointer begin_node;
		node_pointer end_node;

	public:
		explicit tree(const allocator_type &alloc = allocator_type()) : _alloc(alloc)
		{
			_size = 0;

			root = _alloc.allocate(1);
			_alloc.construct(root, value_type());

			begin_node = _alloc.allocate(1);
			_alloc.construct(begin_node, value_type());

			begin_node->parent = root;
			root->left = begin_node;

			end_node = _alloc.allocate(1);
			_alloc.construct(end_node, value_type());

			end_node->parent = root;
			root->right = end_node;
		}

		tree(const tree &t) { return *this = t; };

		~tree() { delete_node(root); };

		tree &operator=(const tree &t)
		{
			if (this != &t)
			{
				this->_size = t._size;
				this->_alloc = t._alloc;
				// this->cmp = t.cmp;
				insert(t.begin(), t.end());
			}

			return *this;
		};

		iterator begin()
		{
			if (!_size)
				return iterator(end_node);
			return iterator(begin_node->parent);
		};

		const_iterator begin() const
		{
			if (!_size)
				return const_iterator(end_node);
			return const_iterator(begin_node->parent);
		};

		iterator end() { return iterator(end_node); };
		const_iterator end() const { return const_iterator(end_node); };

		size_type size() const { return _size; };

		size_type max_size() const { return _alloc.max_size(); };

		node_pointer searchNode(const value_type &val)
		{
			node_pointer tmp = root;

			while (tmp != end_node)
			{
				if (tmp->value.first == val.first)
					return tmp;
				else if (val.first < tmp->value.first)
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			return (NULL);
		}

		void reconnectNode(node_pointer par, node_pointer child, bool isleft)
		{
			if (child)
				child->parent = par;

			if (isleft)
				par->left = child;
			else
				par->right = child;
		}

		pair<iterator, bool> insert_unique(const value_type &val)
		{
			if (!_size)
			{
				root->value = val;
				_size++;
				return ft::make_pair(iterator(root), true);
			}

			node_pointer newNode = searchNode(val);
			node_pointer tmp = root;
			bool isleft = false;

			if (newNode)
				return ft::make_pair(iterator(newNode), false);

			newNode = _alloc.allocate(1);
			_alloc.construct(newNode, val);
			
			while (tmp != end_node)
			{
				if (newNode->value.first < tmp->value.first)
				{
					isleft = true;
					tmp = tmp->left;
				}
				else
					tmp = tmp->right;
			}
			reconnectNode(tmp->parent, newNode, isleft);
			reconnectNode(newNode, tmp, false);
			_size++;

			return ft::make_pair(iterator(newNode), true);
		};

		iterator insert_unique(iterator position, const value_type &val)
		{
			static_cast<void>(position);
			return insert_unique(val).first;
		};

		void erase(iterator position)
		{
			static_cast<void>(position);
			erase(position.first);
		};

		node_pointer findMaxNode(node_pointer root)
		{
			node_pointer tmp = root;

			if (!tmp)
				return NULL;

			while (tmp->right)
				tmp = tmp->right;
			return tmp;
		}

		size_type erase(const key_type &k)
		{
			bool isleft = false;
			node_pointer cur = searchNode(k);
			node_pointer tmp = NULL;
			node_pointer tp = NULL;

			if (!cur)
				return 0;

			tmp = cur;
			tp = cur->parent;
			if (tp->left == cur)
				isleft = true;
			if (cur->left == NULL && cur->right == NULL)
			{
				reconnectNode(tp, NULL, isleft);
				delete cur;
				cur = NULL;
			}
			else if (cur->left == NULL)
			{
				cur = cur->right;
				reconnectNode(tp, cur, isleft);
				delete tmp;
				tmp = NULL;
			}
			else if (cur->right == NULL)
			{
				cur = cur->left;
				reconnectNode(tp, cur, isleft);
				delete tmp;
				tmp = NULL;
			}
			else
			{
				node_pointer max = findMaxNode(cur->left);
				max->parent->right = NULL;
				max->left = cur->left;
				max->right = cur->right;
				reconnectNode(tp, max, isleft);
				delete cur;
				cur = NULL;
			}
			return 1;
		};

		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				iterator tmp(first);
				first++;
				erase(tmp.first);
			}
		};

		void swap(tree &x)
		{
			node_pointer tt = x.root;
			node_pointer tb = x.begin_node;
			node_pointer te = x.end_node;
			size_type ts = x._size;
			alloc_node ta = x._alloc;

			x.root = this->root;
			x.begin_node = this->begin_node;
			x.end_node = this->end_node;
			x._size = this->_size;
			x._alloc = this->_alloc;

			this->root = tt;
			this->begin_node = tb;
			this->end_node = te;
			this->_size = ts;
			this->_alloc = ta;
		}

		void delete_node(node_pointer node)
		{
			if (node->left)
				delete_node(node->left);
			if (node->right)
				delete_node(node->right);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}

		void clear() { delete_node(root); };

		// key_compare key_comp() const
		// {
		// 	return cmp;
		// };

		iterator find(const key_type &k)
		{
			for (iterator i = begin(); i != end(); i++)
				if (i->first == k)
					return i;

			return end();
		};
		const_iterator find(const key_type &k) const
		{
			for (const_iterator i = begin(); i != end(); i++)
				if (i->first == k)
					return i;

			return end();
		};

		size_type count_unique(const key_type &k) const
		{
			if (find(k))
				return 1;

			return 0;
		};

		// iterator lower_bound(const key_type &k)
		// {
		// 	iterator b = begin();

		// 	while (b != end())
		// 	{
		// 		if (!cmp(b->first, k))
		// 			break;
		// 		b++;
		// 	}

		// 	return b;
		// };

		// const_iterator lower_bound(const key_type &k) const
		// {
		// 	const_iterator b = begin();

		// 	while (b != end())
		// 	{
		// 		if (!cmp(k, k))
		// 			break;
		// 		++b;
		// 	}

		// 	return b;
		// };

		// iterator upper_bound(const key_type &k)
		// {
		// 	iterator b = begin();

		// 	while (b != end())
		// 	{
		// 		if (cmp(k, b->first))
		// 			break;
		// 		b++;
		// 	}

		// 	return b;
		// };
		// const_iterator upper_bound(const key_type &k) const
		// {
		// 	const_iterator b = begin();

		// 	while (b != end())
		// 	{
		// 		if (cmp(k, b->first))
		// 			break;
		// 		b++;
		// 	}

		// 	return b;
		// };

		// pair<const_iterator, const_iterator> equal_range_unique(const key_type &k) const
		// {
		// 	return ft::make_pair(lower_bound(k), upper_bound(k));
		// };

		// pair<iterator, iterator> equal_range_unique(const key_type &k)
		// {
		// 	return ft::make_pair(lower_bound(k), upper_bound(k));
		// };

		allocator_type get_allocator() const { return _alloc; };
	};
} // namespace ft

#endif