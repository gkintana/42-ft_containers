/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:39:21 by gkintana          #+#    #+#             */
/*   Updated: 2022/10/10 18:16:05 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

// https://github.com/llvm/llvm-project/tree/main/libcxx
// https://github.com/gcc-mirror/gcc/tree/master/libstdc%2B%2B-v3/include/bits
// https://www.happycoders.eu/algorithms/red-black-tree-java/
// https://www.cs.auckland.ac.nz/software/AlgAnim/red_black.html
// https://web.stanford.edu/class/archive/cs/cs106l/cs106l.1176/lectures/lecture05/05_Templates.pdf
// https://web.stanford.edu/class/archive/cs/cs106l/cs106l.1176/lectures/

// https://github.com/dbjnbnrj/redblacktrees
// https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html
// https://zarif98sjs.github.io/mindcraft/RedBlackTree/
// https://www.youtube.com/watch?v=vRwi_UcZGjU

#include <map>
#include "pair.hpp"

namespace ft {

template <class T>
struct tree_node {
	typedef T              value_type;
	typedef tree_node*     pointer;
	typedef std::size_t    size_type;

	value_type    value;
	pointer       parent;
	pointer       left;
	pointer       right;
	size_type     height;

	tree_node(value_type data) : value(data), parent(0), left(0), right(0), height(1) {}

	~tree_node() {}
};

template < class Key, class T, class Compare = std::less<Key>,
           class Allocator = std::allocator< ft::pair<const Key, T> > >
class avl_tree {

	public:
		typedef Key                                                           key_type;
		typedef T                                                             mapped_type;
		typedef ft::pair<const key_type, mapped_type>                         value_type;
		typedef Compare                                                       value_compare;
		typedef Allocator                                                     allocator_base;
		typedef tree_node<mapped_type>                                        node_type;
		typedef node_type*                                                    pointer;
		typedef const pointer                                                 const_pointer;
		typedef typename allocator_base::template rebind<node_type>::other    allocator_type;
		typedef std::size_t                                                   size_type;
		// add iterators

	private:
		pointer m_root;
		// pointer m_node;
		allocator_type m_alloc;
		size_type m_size;

	public:
		avl_tree(const value_compare &comp = value_compare(), const allocator_type &alloc = allocator_type()) : m_alloc(alloc) {
			(void)comp;
			// (void)alloc;

			m_root = NULL;
			m_size = 0;
		}

		avl_tree &operator=(const avl_tree &x) {
			(void)x;
		}

		~avl_tree() {}

		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;

		bool empty() const {
			return !m_size;
		}

		size_type size() const {
			return m_size;
		}

		size_type max_size() const {
			return m_alloc.max_size();
		}

		void swap(avl_tree &x) {
			pointer temp_root = m_root;
			size_type temp_size = m_size;

			m_root = x.m_root;
			m_size = x.m_size;

			x.m_root = temp_root;
			x.m_size = temp_size;
		}

		pointer insertNode(pointer node, mapped_type value) {
			if (!node) {
				return createNode(value);
			} else if (value < node->value) {
				node->left = insertNode(node->left, value);
			} else if (value > node->value) {
				node->right = insertNode(node->right, value);
			}

			int balance = checkBalanceFactor(node);
			if (balance > 1) {
				if (value > node->right->value) {
					node->left = leftRotate(node->left);
				}
				return rightRotate(node);
			} else if (balance < -1) {
				if (value < node->right->value) {
					node->right = rightRotate(node->right);
				}
				return leftRotate(node);
			}

			return node;
		}

		void printPreOrder(pointer node) {
			if (node != NULL) {
				std::cout << node->value << std::endl;
				printPreOrder(node->left);
				printPreOrder(node->right);
			}
		}

	private:
		pointer createNode(mapped_type value) {
			pointer node = m_alloc.allocate(1 * sizeof(node_type));
			m_alloc.construct(node, node_type(value));
			m_size++;
			return node;
		}

		size_type getHeight(pointer node) {
			return (!node) ? 0 : node->height;
		}

		size_type checkBalanceFactor(pointer node) {
			return (!node) ? 0 : getHeight(node->left) - getHeight(node->right);
		}

		pointer getMininum(pointer node) {
			pointer min = node;
			while (min->left) {
				min = min->left;
			}
			return min;
		}

		pointer getMaximum(pointer node) {
			pointer max = node;
			while (max->right) {
				max = max->right;
			}
			return max;
		}

		pointer leftRotate(pointer node) {
			pointer x = node->right,
			        y = x->left;

			x->left = node;
			node->right = y;

			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
			x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
			return x;
		}

		pointer rightRotate(pointer node) {
			pointer x = node->left,
			        y = x->right;

			x->right = node;
			node->left = y;

			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
			x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
			return x;
		}

};

}    // namespace ft

#endif    // AVL_TREE_HPP
