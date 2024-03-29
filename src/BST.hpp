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
		bool tmp;
		Pair value;
		Node *left;
		Node *right;
		Node *parent;

		Node() : tmp(false), value(NULL), left(NULL), right(NULL), parent(NULL){};
		Node(const Pair &src) : tmp(false), value(src), left(NULL), right(NULL), parent(NULL){};
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
				this->tmp = rhs.tmp;
			}
			return *this;
		};
	};

	template <typename T, typename Node>
	class Tree_iterator
	{
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
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

		operator Tree_iterator<const T, Node>() const
		{
			return (Tree_iterator<const T, Node>(this->node));
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

			while (parent && tmp == parent->right)
			{
				tmp = parent;
				parent = tmp->parent;
			}
			this->node = parent;
			return *this;
		};

		Tree_iterator operator++(int)
		{
			Tree_iterator tmp(node);
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
				this->node = tmp;
				return *this;
			}

			node_pointer parent = tmp->parent;

			while (parent && tmp == parent->left)
			{
				tmp = parent;
				parent = tmp->parent;
			}
			this->node = parent;
			return *this;
		};

		Tree_iterator operator--(int)
		{
			Tree_iterator tmp(node);
			operator--();
			return tmp;
		};

		bool operator==(const Tree_iterator &x)
		{
			return this->node == x.node;
		};
		bool operator!=(const Tree_iterator &x)
		{
			return !(x.node == this->node);
		};
	};

	template <class Tp, class Compare, class Allocator = std::allocator<Tp> >
	class tree
	{
	public:
		typedef Tp value_type;
		typedef Compare key_compare;
		typedef typename Tp::first_type key_type;
		typedef Allocator allocator_type;
		typedef Node<Tp> node_type;
		typedef Node<Tp> *node_pointer;

		typedef typename allocator_type::size_type size_type;

		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef Tree_iterator<value_type, node_type> iterator;
		typedef Tree_iterator<const value_type, node_type> const_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;

		typedef typename Allocator::template rebind<node_type>::other alloc_node;
		typedef std::allocator_traits<alloc_node> node_traits;

	private:
		size_type _size;
		alloc_node _alloc;
		key_compare _comp;

		node_pointer root;
		node_pointer begin_node;
		node_pointer end_node;

	public:
		explicit tree(const allocator_type &alloc = allocator_type(), const key_compare &com = key_compare()) : _alloc(alloc), _comp(com)
		{
			init_tree();
		}

		tree(const tree &t)
		{
			init_tree();
			*this = t;
		};

		void init_tree()
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

		~tree()
		{
			clear();
		};

		tree &operator=(const tree &t)
		{
			if (this != &t)
			{
				if (_size != 0)
				{
					clear();
					init_tree();
				}
				this->_comp = t._comp;
				this->_alloc = t._alloc;
				insert_unique(t.begin(), t.end());
				this->_size = t._size;
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

		size_type max_size() const
		{
			return (std::min<size_type>(
                node_traits::max_size(alloc_node()),
                std::numeric_limits<difference_type>::max()));
		};

		node_pointer searchNode(const value_type &val)
		{
			node_pointer tmp = root;

			while (tmp != NULL && (tmp != end_node && tmp != begin_node))
			{
				if (tmp->value.first == val.first)
					return tmp;
				else if (_comp(val.first, tmp->value.first))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			return (NULL);
		}

		node_pointer searchNode(const key_type &val)
		{
			node_pointer tmp = root;

			while (tmp && (tmp != end_node && tmp != begin_node))
			{
				if (tmp->value.first == val)
					return tmp;
				else if (_comp(val, tmp->value.first))
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

		void change_root(node_pointer &newNode)
		{
			if (root->left != newNode)
				reconnectNode(newNode, root->left, true);
			if (root->right != newNode)
				reconnectNode(newNode, root->right, false);

			node_pointer tmp = root;
			root = newNode;
			
			_alloc.destroy(tmp);
			_alloc.deallocate(tmp, 1);
		}

		pair<iterator, bool> insert_unique(const value_type &val)
		{
			(void)val;
			if (!_size)
			{
				node_pointer newNode = _alloc.allocate(1);;
				_alloc.construct(newNode, val);
				change_root(newNode);
				++_size;

				return ft::make_pair(iterator(root), true);
			}

			node_pointer newNode = searchNode(val);
			node_pointer tmp = root;
			bool isleft = false;

			if (newNode)
				return ft::make_pair(iterator(newNode), false);

			newNode = _alloc.allocate(1);
			_alloc.construct(newNode, val);

			node_pointer tp;

			while (tmp && (tmp != end_node && tmp != begin_node))
			{
				tp = tmp;
				if (_comp(newNode->value.first, tmp->value.first))
				{
					isleft = true;
					tmp = tmp->left;
				}
				else
				{
					isleft = false;
					tmp = tmp->right;
				}
			}
			reconnectNode(tp, newNode, isleft);
			reconnectNode(newNode, tmp, isleft);
			++_size;

			return ft::make_pair(iterator(newNode), true);
		};

		iterator insert_unique(iterator position, const value_type &val)
		{
			static_cast<void>(position);
			return insert_unique(val).first;
		};

		template <class InputIterator>
		void insert_unique(InputIterator first, InputIterator last)
		{
			for (; first != last; ++first)
				insert_unique(*first);
		};

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

		void erase(iterator position)
		{
			static_cast<void>(position);
			erase(position->first);
		};

		node_pointer findMaxNode(node_pointer node)
		{
			node_pointer tmp = node;

			if (!tmp)
				return NULL;

			while (tmp->right)
				tmp = tmp->right;
			return tmp;
		}

		node_pointer findMinNode(node_pointer node)
		{
			node_pointer tmp = node;

			if (!tmp)
				return NULL;

			while (tmp->left)
				tmp = tmp->left;
			return tmp;
		}

		void erase_unique(node_pointer &parent, node_pointer child, bool isleft, node_pointer del)
		{
			reconnectNode(parent, child, isleft);
			if (del != NULL)
			{
				_alloc.destroy(del);
				_alloc.deallocate(del, 1);
			}
		}

		void erase_root()
		{
			if (root->left != begin_node)
			{
				node_pointer max = findMaxNode(root->left);
				if (max->left && max->parent != root)
					reconnectNode(max->parent, max->left, false);
				if (max->parent->right == max)
					max->parent->right = NULL;
				max->parent = NULL;
				change_root(max);
			}
			else if (root->right != end_node)
			{
				node_pointer min = findMinNode(root->right);
				if (min->right && min->parent != root)
					reconnectNode(min->parent, min->right, true);
				if (min->parent->left == min)
					min->parent->left = NULL;
				min->parent = NULL;
				change_root(min);
			}
			else
			{
				_size = 0;
				_alloc.destroy(root);
				_alloc.construct(root, value_type());
				return ;
			}
			--_size;
		}

		size_type erase(const key_type &k)
		{
			bool isleft = false;
			node_pointer cur = searchNode(k);
			node_pointer tmp = NULL;
			node_pointer tp = NULL;

			if (cur == NULL)
				return 0;

			if (cur == root)
			{
				erase_root();
				return 1;
			}

			tmp = cur;
			tp = cur->parent;
			if (tp->left == cur)
				isleft = true;

			if (cur->left == NULL && cur->right == NULL)
				erase_unique(tp, NULL, isleft, cur);
			else if (cur->left == NULL)
			{
				cur = cur->right;
				erase_unique(tp, cur, isleft, tmp);
			}
			else if (cur->right == NULL)
			{
				cur = cur->left;
				erase_unique(tp, cur, isleft, tmp);
			}
			else
			{
				node_pointer max = findMaxNode(cur->left);

				if (max->parent->right == max)
					max->parent->right = NULL;
				if (max->left && max->parent != cur)
					reconnectNode(max->parent, max->left, false);
				
				node_pointer left = cur->left;
				node_pointer right = cur->right;

				if (left == max)
					left = max->left;
				
				reconnectNode(max, left, true);
				reconnectNode(max, right, false);
				erase_unique(tp, max, isleft, cur);
			}
			--_size;

			return 1;
		};

		void erase(iterator first, iterator last)
		{
			if (first == begin() && last == end())
				clear();
			while (first != last)
			{
				iterator tmp(first);
				first++;
				erase(tmp->first);
			}
		};

		void swap(tree &x)
		{
			node_pointer tt = x.root;
			node_pointer tb = x.begin_node;
			node_pointer te = x.end_node;
			size_type ts = x._size;
			alloc_node ta = x._alloc;
			key_compare tc = x._comp;

			x.root = this->root;
			x.begin_node = this->begin_node;
			x.end_node = this->end_node;
			x._size = this->_size;
			x._alloc = this->_alloc;
			x._comp = this->_comp;

			this->root = tt;
			this->begin_node = tb;
			this->end_node = te;
			this->_size = ts;
			this->_alloc = ta;
			this->_comp = tc;
		}

		void delete_node(node_pointer node)
		{
			if (!node)
				return ;
			delete_node(node->left);
			delete_node(node->right);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}

		void clear()
		{
			delete_node(root);
			begin_node = NULL;
			end_node = NULL;
			root = NULL;
			_size = 0;
		};

		size_type count_unique(const key_type &k) const
		{
			if (find(k) != end())
				return 1;

			return 0;
		};

		allocator_type get_allocator() const { return _alloc; };
	};
} // namespace ft

#endif