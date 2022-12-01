/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:10:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/01 23:51:53 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

// https://stackoverflow.com/questions/9597817/c-avl-tree-iterator-will-not-increment-properly

#include "iterator_traits.hpp"
#include "tree_node.hpp"

namespace ft {

template <class T, class AVL>
class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {

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

	private:
		node_pointer m_node;
		tree_type m_tree;

	public:
		map_iterator() : m_node() {}

		map_iterator(node_pointer node, tree_type tree) : m_node(node),
		                                                  m_tree(tree) {}

		map_iterator(const map_iterator &other) : m_node(other.m_node),
		                                          m_tree(other.m_tree) {}

		map_iterator &operator=(const map_iterator &other) {
			if (this != &other) {
				m_node = other.m_node;
				m_tree = other.m_tree;
			}
			return *this;
		}

		~map_iterator() {}

		reference operator*() const {
			return m_node->value;
		}

		pointer operator->() const {
			if (m_node != NULL) {
				return &m_node->value;
			}
			return &m_tree.getSentinel()->value;
		}

		node_pointer base() const {
			return m_node;
		}

		tree_type getTree() const {
			return m_tree;
		}

		map_iterator &operator++() {
			m_node = m_tree.getNodeSuccessor(m_tree.getRoot(), m_node);
			return *this;
		}

		map_iterator operator++(int) {
			map_iterator temp = *this;
			++(*this);
			return temp;
		}

		map_iterator &operator--() {
			m_node = m_tree.getNodePredecessor(m_tree.getRoot(), m_node);
			return *this;
		}

		map_iterator operator--(int) {
			map_iterator temp = *this;
			--(*this);
			return temp;
		}

};

template <class T, class AVL>
bool operator==(const ft::map_iterator<T, AVL> &lhs, const ft::map_iterator<T, AVL> &rhs) {
	return lhs.base() == rhs.base();
}

template <class T, class AVL>
bool operator!=(const ft::map_iterator<T, AVL> &lhs, const ft::map_iterator<T, AVL> &rhs) {
	return !(lhs == rhs);
}

/***********************************************************************************************************/

template <class T, class AVL>
class const_map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {

	public:
		typedef ft::iterator<std::bidirectional_iterator_tag, T>    traits_type;
		typedef typename traits_type::value_type                    value_type;
		typedef typename traits_type::difference_type               difference_type;
		typedef typename traits_type::iterator_category             iterator_category;
		typedef const value_type*                                   pointer;
		typedef const value_type&                                   reference;
		typedef tree_node<value_type>                               node_type;
		typedef node_type*                                          node_pointer;
		typedef AVL                                                 tree_type;
		typedef map_iterator<value_type, tree_type>                 iterator;

	private:
		node_pointer m_node;
		tree_type m_tree;

	public:
		const_map_iterator() : m_node() {}

		const_map_iterator(const node_pointer node, tree_type tree) : m_node(node),
		                                                              m_tree(tree) {}

		const_map_iterator(const iterator &other) : m_node(other.base()),
		                                            m_tree(other.getTree()) {}

		const_map_iterator(const const_map_iterator &other) : m_node(other.m_node),
		                                                      m_tree(other.m_tree) {}

		const_map_iterator &operator=(const const_map_iterator &other) {
			if (this != &other) {
				m_node = other.m_node;
				m_tree = other.m_tree;
			}
			return *this;
		}

		~const_map_iterator() {}

		reference operator*() const {
			return m_node->value;
		}

		pointer operator->() const {
			if (m_node != NULL) {
				return &m_node->value;
			}
			return &m_tree.getSentinel()->value;
		}

		node_pointer base() const {
			return m_node;
		}

		tree_type getTree() const {
			return m_tree;
		}

		const_map_iterator &operator++() {
			m_node = m_tree.getNodeSuccessor(m_tree.getRoot(), m_node);
			return *this;
		}

		const_map_iterator operator++(int) {
			const_map_iterator temp = *this;
			++(*this);
			return temp;
		}

		const_map_iterator &operator--() {
			m_node = m_tree.getNodePredecessor(m_tree.getRoot(), m_node);
			return *this;
		}

		const_map_iterator operator--(int) {
			const_map_iterator temp = *this;
			--(*this);
			return temp;
		}

};

template <class T, class AVL>
bool operator==(const ft::const_map_iterator<T, AVL> &lhs, const ft::const_map_iterator<T, AVL> &rhs) {
	return lhs.base() == rhs.base();
}

template <class T, class AVL>
bool operator!=(const ft::const_map_iterator<T, AVL> &lhs, const ft::const_map_iterator<T, AVL> &rhs) {
	return !(lhs == rhs);
}

/***********************************************************************************************************/

template <class T, class AVL>
bool operator==(const ft::map_iterator<T, AVL> &lhs, const ft::const_map_iterator<T, AVL> &rhs) {
	return lhs.base() == rhs.base();
}

template <class T, class AVL>
bool operator!=(const ft::map_iterator<T, AVL> &lhs, const ft::const_map_iterator<T, AVL> &rhs) {
	return !(lhs == rhs);
}

template <class T, class AVL>
bool operator==(const ft::const_map_iterator<T, AVL> &lhs, const ft::map_iterator<T, AVL> &rhs) {
	ft::const_map_iterator<T, AVL> const_rhs(rhs);
	return lhs.base() == const_rhs.base();
}

template <class T, class AVL>
bool operator!=(const ft::const_map_iterator<T, AVL> &lhs, const ft::map_iterator<T, AVL> &rhs) {
	ft::const_map_iterator<T, AVL> const_rhs(rhs);
	return !(lhs.base() == const_rhs.base());
}

}    // namespace ft

#endif    // MAP_ITERATOR_HPP
