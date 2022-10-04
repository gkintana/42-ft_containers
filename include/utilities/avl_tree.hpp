/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:39:21 by gkintana          #+#    #+#             */
/*   Updated: 2022/10/05 00:03:10 by gkintana         ###   ########.fr       */
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

template < class T, class Compare, class Allocator = std::allocator<T> >
class avl_tree {

	public:
		typedef T                        value_type;
		typedef Compare                  value_compare;
		typedef Allocator                allocator_type;
		typedef std::ptrdiff_t           difference_type;
		typedef std::size_t              size_type;
		// add iterators

	private:
		typedef tree_node<value_type>    node_type;
		typedef node_type*               pointer;
		typedef const pointer            const_pointer;

		pointer m_root;
		// pointer m_node;
		allocator_type m_alloc;
		size_type m_size;

	public:
		avl_tree(const value_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());

		avl_tree &operator=(const avl_tree &x);

		~avl_tree();

		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;

		bool empty() const { return !m_size; }
		size_type size() const { return m_size; }
		size_type max_size() const { return m_alloc.max_size(); }

	private:
		pointer createNode(value_type value) {
			pointer node = m_alloc.allocate(sizeof(tree_node));
			m_alloc.construct(node, tree_node(value));
			m_size++;
			return node;
		}

		size_type getHeight(pointer node) { return (!node) ? 0 : node->height; }

		size_type checkBalanceFactor(pointer node) { return (!node) ? 0 : getHeight(node->left) - getHeight(node->right); }

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

		pointer rotateLeft(pointer sub_root) {
			pointer left_node = sub_root->left,
			        right_node = sub_root->right;

			left_node->right = sub_root;
			sub_root->left = right_node;

			sub_root->height = std::max(getHeight(sub_root->left), getHeight(sub_root->right)) + 1;
			left_node->height = std::max(getHeight(left_node->left), getHeight(left_node->right)) + 1;

			return left_node;
		}
};

}    // namespace ft

#endif    // RED_BLACK_TREE_HPP
