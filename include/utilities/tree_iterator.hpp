/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:10:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/11/26 23:03:48 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

// https://stackoverflow.com/questions/9597817/c-avl-tree-iterator-will-not-increment-properly

namespace ft {

template <class T>
struct tree_node {
	typedef T              value_type;
	typedef tree_node*     pointer;
	typedef std::size_t    size_type;

	value_type    value;
	// pointer       parent;
	pointer       left;
	pointer       right;
	size_type     height;

	tree_node(value_type val) : value(val),
	                            // parent(0),
	                            left(0),
	                            right(0),
	                            height(1) {}

	// tree_node(value_type val, pointer par) : value(val),
	//                                          parent(par),
	//                                          left(0),
	//                                          right(0),
	//                                          height(1) {}

	~tree_node() {}
};

template <class T, class AVL>
class tree_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {

	public:
		typedef ft::iterator<std::bidirectional_iterator_tag, T>    traits_type;
		typedef typename traits_type::value_type                    value_type;
		typedef typename traits_type::pointer                       pointer;
		typedef typename traits_type::reference                     reference;
		typedef typename traits_type::difference_type               difference_type;
		typedef typename traits_type::iterator_category             iterator_category;
		typedef tree_node<value_type>                               node_type;
		typedef node_type*                                          node_pointer;
		typedef AVL                                                 tree_type;
		// typedef const node_pointer                                  const_node_pointer;

	private:
		node_pointer m_node;
		tree_type m_tree;

	public:
		tree_iterator() : m_node() {}

		tree_iterator(node_pointer node, tree_type tree) : m_node(node), m_tree(tree) {}

		~tree_iterator() {}

		reference operator*() const {
			return m_node->value;
		}

		pointer operator->() const {
			// if (m_node)
				return &m_node->value;
			// return NULL;
		}

		node_pointer base() const {
			return m_node;
		}

		tree_iterator &operator++() {
			if (m_node->right) {
				m_node = m_node->right;
				while (m_node->left) {
					m_node = m_node->left;
				}
			} else {
				while (m_node->parent && m_node == m_node->parent->right) {
					m_node = m_node->parent;
				}
				m_node = m_node->parent;

				// node_pointer temp;
				// do {
				// 	temp = m_node;
				// 	m_node = m_node->parent;
				// 	if (m_node && m_node->left == temp) {
				// 		break;
				// 	}
				// } while (m_node->parent);
			}
			return *this;
		}

		tree_iterator operator++(int) {
			tree_iterator temp = *this;
			++(*this);
			return temp;
		}

		tree_iterator &operator--() {
			if (!m_node) {
				m_node = m_tree.getRoot();
				while (m_node->right)
					m_node = m_node->right;
			} else if (m_node->left) {
				m_node = m_node->left;
				while (m_node->right) {
					m_node = m_node->right;
				}
			} else {
				while (m_node->parent && m_node == m_node->parent->left) {
					m_node = m_node->parent;
				}
				m_node = m_node->parent;
			}
			return *this;
		}

		tree_iterator operator--(int) {
			tree_iterator temp = *this;
			--(*this);
			return temp;
		}

};

template <class T, class AVL>
bool operator==(const tree_iterator<T, AVL> &lhs, const tree_iterator<T, AVL> &rhs) {
	return lhs.base() == rhs.base();
}

template <class T, class AVL>
bool operator!=(const tree_iterator<T, AVL> &lhs, const tree_iterator<T, AVL> &rhs) {
	return !(lhs == rhs);
}

}    // namespace ft

#endif    // TREE_ITERATOR_HPP
