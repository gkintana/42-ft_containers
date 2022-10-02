/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:39:21 by gkintana          #+#    #+#             */
/*   Updated: 2022/10/02 23:32:35 by gkintana         ###   ########.fr       */
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

#include <map>

namespace ft {

enum tree_color { RED = 0, BLACK = 1 };

template <class T>
struct tree_node {
	typedef tree_node*       pointer;
	typedef const pointer    const_pointer;

	T          value_type;
	pointer    parent;
	pointer    left;
	pointer    right;
	enum tree_color color;

	pointer minimum(pointer root) {
		pointer node = root;
		while (node->left) {
			node = node->left;
		}
		return node;
	}

	const_pointer minimum(const_pointer root) {
		const_pointer node = root;
		while (node->left) {
			node = node->left;
		}
		return node;
	}

	pointer maximum(pointer root) {
		pointer node = root;
		while (node->right) {
			node = node->right;
		}
		return node;
	}

	const_pointer maximum(const_pointer root) {
		const_pointer node = root;
		while (node->right) {
			node = node->right;
		}
		return node;
	}
};

#define REBIND_NODE allocator_type::template rebind<node>::other

template < class T, class Compare, class Allocator >
class red_black_tree {

	public:
		typedef T                        value_type;
		typedef Compare                  value_compare;
		typedef Allocator                allocator_type;
		typedef std::ptrdiff_t           difference_type;
		typedef std::size_t              size_type;
		typedef tree_node<value_type>    node_type;
		typedef node_type*               node_pointer;
		typedef const node_type*         const_node_pointer;
		typedef typename REBIND_NODE     node_allocator;
		// add iterators

	private:
		node_pointer m_root;
		node_pointer m_node;
		allocator_type m_alloc;
		size_type m_size;

	public:
		red_black_tree(const value_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());

		red_black_tree &operator=(const red_black_tree &x);

		~red_black_tree();

		iterator begin();

		const_iterator begin() const;

		iterator end();

		const_iterator end() const;


};

}    // namespace ft

#endif    // RED_BLACK_TREE_HPP
