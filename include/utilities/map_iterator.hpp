/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:10:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/13 23:09:57 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "tree_node.hpp"

namespace ft {

template <class T, class Compare>
class map_traverser {

	public:
		typedef T                        value_type;
		typedef Compare                  key_compare;
		typedef tree_node<value_type>    node_type;
		typedef node_type*               node_pointer;

	private:
		node_pointer m_node;
		node_pointer m_root;
		node_pointer m_sentinel;
		key_compare m_comp;

	public:
		map_traverser() : m_node(),
		                  m_root(),
		                  m_sentinel(),
		                  m_comp() {}

		map_traverser(node_pointer node, node_pointer root, node_pointer sentinel,
		              const key_compare &comp = key_compare()) : m_node(node),
		                                                         m_root(root),
		                                                         m_sentinel(sentinel),
		                                                         m_comp(comp) {}

		~map_traverser() {}

		node_pointer getNodeSuccessor(node_pointer root, node_pointer node) {
			if (node == m_sentinel || !node) {
				return m_sentinel;
			} else if (node->right) {
				return getMinimum(node->right);
			}

			node_pointer successor = m_sentinel;
			while (root) {
				if (m_comp(node->value.first, root->value.first)) {
					successor = root;
					root = root->left;
				} else if (m_comp(root->value.first, node->value.first)) {
					root = root->right;
				} else {
					break;
				}
			}
			return successor;
		}

		node_pointer getNodePredecessor(node_pointer root, node_pointer node) {
			if (!node) {
				return m_sentinel;
			} else if (node == m_sentinel) {
				return getMaximum(root);
			} else if (node->left) {
				return getMaximum(node->left);
			}

			node_pointer predecessor = m_sentinel;
			while (root) {
				if (m_comp(root->value.first, node->value.first)) {
					predecessor = root;
					root = root->right;
				} else if (m_comp(node->value.first, root->value.first)) {
					root = root->left;
				} else {
					break;
				}
			}
			return predecessor;
		}

		node_pointer getMinimum(node_pointer node) {
			node_pointer min = node;
			while (min->left) {
				min = min->left;
			}
			return min;
		}

		node_pointer getMaximum(node_pointer node) {
			node_pointer max = node;
			while (max->right) {
				max = max->right;
			}
			return max;
		}

};    // class map_traverser

/***********************************************************************************************************/

template <class T, class Compare>
class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {

	public:
		typedef Compare                                            	key_compare;
		typedef ft::iterator<std::bidirectional_iterator_tag, T>    traits_type;
		typedef typename traits_type::value_type                    value_type;
		typedef typename traits_type::pointer                       pointer;
		typedef typename traits_type::reference                     reference;
		typedef typename traits_type::difference_type               difference_type;
		typedef typename traits_type::iterator_category             iterator_category;
		typedef tree_node<value_type>                               node_type;
		typedef node_type*                                          node_pointer;
		typedef map_traverser<value_type, key_compare>              node_finder;

	private:
		node_pointer m_node;
		node_pointer m_root;
		node_pointer m_sentinel;
		key_compare m_comp;
		node_finder m_find;

	public:
		map_iterator() : m_node(),
		                 m_root(),
		                 m_sentinel(),
		                 m_comp(),
		                 m_find() {}

		map_iterator(node_pointer node, node_pointer root, node_pointer sentinel,
		             const key_compare &comp = key_compare()) : m_node(node),
		                                                        m_root(root),
		                                                        m_sentinel(sentinel),
		                                                        m_comp(comp),
		                                                        m_find(m_node, m_root, m_sentinel, m_comp) {}

		map_iterator(const map_iterator &other) : m_node(other.m_node),
		                                          m_root(other.m_root),
		                                          m_sentinel(other.m_sentinel),
		                                          m_comp(other.m_comp),
		                                          m_find(m_node, m_root, m_sentinel, m_comp) {}

		map_iterator &operator=(const map_iterator &other) {
			if (this != &other) {
				m_node = other.m_node;
				m_root = other.m_root;
				m_sentinel = other.m_sentinel;
				m_comp = other.m_comp;
				m_find = node_finder(m_node, m_root, m_sentinel, m_comp);
			}
			return *this;
		}

		~map_iterator() {}

		reference operator*() const {
			return m_node->value;
		}

		pointer operator->() const {
			return m_node ? &m_node->value : &m_sentinel->value;
		}

		node_pointer base() const {
			return m_node;
		}

		node_pointer getRoot() const {
			return m_root;
		}

		node_pointer getSentinel() const {
			return m_sentinel;
		}

		key_compare getComp() const {
			return m_comp;
		}

		map_iterator &operator++() {
			m_node = m_find.getNodeSuccessor(m_root, m_node);
			return *this;
		}

		map_iterator operator++(int) {
			map_iterator temp = *this;
			++(*this);
			return temp;
		}

		map_iterator &operator--() {
			m_node = m_find.getNodePredecessor(m_root, m_node);
			return *this;
		}

		map_iterator operator--(int) {
			map_iterator temp = *this;
			--(*this);
			return temp;
		}

};    // class map_iterator

template <class T, class Compare>
bool operator==(const ft::map_iterator<T, Compare> &lhs, const ft::map_iterator<T, Compare> &rhs) {
	return lhs.base() == rhs.base();
}

template <class T, class Compare>
bool operator!=(const ft::map_iterator<T, Compare> &lhs, const ft::map_iterator<T, Compare> &rhs) {
	return !(lhs == rhs);
}

/***********************************************************************************************************/

template <class T, class Compare>
class const_map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {

	public:
		typedef Compare                                             key_compare;
		typedef ft::iterator<std::bidirectional_iterator_tag, T>    traits_type;
		typedef typename traits_type::value_type                    value_type;
		typedef typename traits_type::difference_type               difference_type;
		typedef typename traits_type::iterator_category             iterator_category;
		typedef const value_type*                                   pointer;
		typedef const value_type&                                   reference;
		typedef tree_node<value_type>                               node_type;
		typedef node_type*                                          node_pointer;
		typedef map_iterator<value_type, key_compare>               iterator;
		typedef map_traverser<value_type, key_compare>              node_finder;

	private:
		node_pointer m_node;
		node_pointer m_root;
		node_pointer m_sentinel;
		key_compare m_comp;
		node_finder m_find;

	public:
		const_map_iterator() : m_node(),
		                       m_root(),
		                       m_sentinel(),
		                       m_comp(),
		                       m_find() {}

		const_map_iterator(const node_pointer node, node_pointer root, node_pointer sentinel,
		                   const key_compare &comp = key_compare()) : m_node(node),
		                                                              m_root(root),
		                                                              m_sentinel(sentinel),
		                                                              m_comp(comp),
		                                                              m_find(m_node, m_root, m_sentinel, m_comp) {}

		const_map_iterator(const iterator &other) : m_node(other.base()),
		                                            m_root(other.getRoot()),
		                                            m_sentinel(other.getSentinel()),
		                                            m_comp(other.getComp()),
		                                            m_find(m_node, m_root, m_sentinel, m_comp) {}

		const_map_iterator(const const_map_iterator &other) : m_node(other.m_node),
		                                                      m_root(other.m_root),
		                                                      m_sentinel(other.m_sentinel),
		                                                      m_comp(other.m_comp),
		                                                      m_find(m_node, m_root, m_sentinel, m_comp) {}

		const_map_iterator &operator=(const const_map_iterator &other) {
			if (this != &other) {
				m_node = other.m_node;
				m_root = other.m_root;
				m_sentinel = other.m_sentinel;
				m_comp = other.m_comp;
				m_find = node_finder(m_node, m_root, m_sentinel, m_comp);
			}
			return *this;
		}

		~const_map_iterator() {}

		reference operator*() const {
			return m_node->value;
		}

		pointer operator->() const {
			return m_node ? &m_node->value : &m_sentinel->value;
		}

		node_pointer base() const {
			return m_node;
		}

		const_map_iterator &operator++() {
			m_node = m_find.getNodeSuccessor(m_root, m_node);
			return *this;
		}

		const_map_iterator operator++(int) {
			const_map_iterator temp = *this;
			++(*this);
			return temp;
		}

		const_map_iterator &operator--() {
			m_node = m_find.getNodePredecessor(m_root, m_node);
			return *this;
		}

		const_map_iterator operator--(int) {
			const_map_iterator temp = *this;
			--(*this);
			return temp;
		}

};    // class const_map_iterator

template <class T, class Compare>
bool operator==(const ft::const_map_iterator<T, Compare> &lhs, const ft::const_map_iterator<T, Compare> &rhs) {
	return lhs.base() == rhs.base();
}

template <class T, class Compare>
bool operator!=(const ft::const_map_iterator<T, Compare> &lhs, const ft::const_map_iterator<T, Compare> &rhs) {
	return !(lhs == rhs);
}

/***********************************************************************************************************/

template <class T, class Compare>
bool operator==(const ft::map_iterator<T, Compare> &lhs, const ft::const_map_iterator<T, Compare> &rhs) {
	return lhs.base() == rhs.base();
}

template <class T, class Compare>
bool operator!=(const ft::map_iterator<T, Compare> &lhs, const ft::const_map_iterator<T, Compare> &rhs) {
	return !(lhs == rhs);
}

template <class T, class Compare>
bool operator==(const ft::const_map_iterator<T, Compare> &lhs, const ft::map_iterator<T, Compare> &rhs) {
	ft::const_map_iterator<T, Compare> const_rhs(rhs);
	return lhs.base() == const_rhs.base();
}

template <class T, class Compare>
bool operator!=(const ft::const_map_iterator<T, Compare> &lhs, const ft::map_iterator<T, Compare> &rhs) {
	ft::const_map_iterator<T, Compare> const_rhs(rhs);
	return !(lhs.base() == const_rhs.base());
}

}    // namespace ft

#endif    // MAP_ITERATOR_HPP
