/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:10:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/11/29 10:09:13 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

// https://stackoverflow.com/questions/9597817/c-avl-tree-iterator-will-not-increment-properly

namespace ft {

/**
 * @brief    parent node will always be NULL, it only exists to ensure that
 *           ft::map::max_size and std::map::max_size will return the same value.
*/
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

	tree_node() : value(),
	              parent(0),
	              left(0),
	              right(0),
	              height(0) {}

	tree_node(value_type val) : value(val),
	                            parent(0),
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

		tree_iterator(const tree_iterator &other) : m_node(other.m_node),
		                                            m_tree(other.m_tree) {}

		tree_iterator &operator=(const tree_iterator &other) {
			if (this != &other) {
				m_node = other.m_node;
				m_tree = other.m_tree;
			}
			return *this;
		}

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
			m_node = m_tree.getNodeSuccessor(m_tree.getRoot(), m_node);
			// if (m_node->right) {
			// 	m_node = m_node->right;
			// 	while (m_node->left) {
			// 		m_node = m_node->left;
			// 	}
			// } else {
			// 	while (m_node->parent && m_node == m_node->parent->right) {
			// 		m_node = m_node->parent;
			// 	}
			// 	m_node = m_node->parent;

				// node_pointer temp;
				// do {
				// 	temp = m_node;
				// 	m_node = m_node->parent;
				// 	if (m_node && m_node->left == temp) {
				// 		break;
				// 	}
				// } while (m_node->parent);
			// }
			return *this;
		}

		tree_iterator operator++(int) {
			tree_iterator temp = *this;
			++(*this);
			return temp;
		}

		tree_iterator &operator--() {
			m_node = m_tree.getNodePredecessor(m_tree.getRoot(), m_node);
			// if (!m_node) {
			// 	m_node = m_tree.getRoot();
			// 	while (m_node->right)
			// 		m_node = m_node->right;
			// } else if (m_node->left) {
			// 	m_node = m_node->left;
			// 	while (m_node->right) {
			// 		m_node = m_node->right;
			// 	}
			// } else {
			// 	while (m_node->parent && m_node == m_node->parent->left) {
			// 		m_node = m_node->parent;
			// 	}
			// 	m_node = m_node->parent;
			// }
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


template <class T, class AVL>
class const_tree_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {

	public:
		typedef ft::iterator<std::bidirectional_iterator_tag, T>    traits_type;
		typedef typename traits_type::value_type                    value_type;
		typedef typename traits_type::pointer                       non_const_pointer;
		typedef typename traits_type::reference                     non_const_reference;
		typedef typename traits_type::difference_type               difference_type;
		typedef typename traits_type::iterator_category             iterator_category;
		typedef const non_const_pointer                             pointer;
		typedef const non_const_reference                           reference;
		typedef tree_node<value_type>                               node_type;
		typedef node_type*                                          node_pointer;
		typedef AVL                                                 tree_type;
		// typedef const node_pointer                                  const_node_pointer;

	private:
		node_pointer m_node;
		tree_type m_tree;

	public:
		const_tree_iterator() : m_node() {}

		const_tree_iterator(node_pointer node, tree_type tree) : m_node(node),
		                                                         m_tree(tree) {}

		const_tree_iterator(const const_tree_iterator &other) : m_node(other.m_node),
		                                                        m_tree(other.m_tree) {}

		const_tree_iterator &operator=(const const_tree_iterator &other) {
			if (this != &other) {
				m_node = other.m_node;
				m_tree = other.m_tree;
			}
			return *this;
		}

		~const_tree_iterator() {}

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

		const_tree_iterator &operator++() {
			m_node = m_tree.getNodeSuccessor(m_tree.getRoot(), m_node);
			// if (m_node->right) {
			// 	m_node = m_node->right;
			// 	while (m_node->left) {
			// 		m_node = m_node->left;
			// 	}
			// } else {
			// 	while (m_node->parent && m_node == m_node->parent->right) {
			// 		m_node = m_node->parent;
			// 	}
			// 	m_node = m_node->parent;

				// node_pointer temp;
				// do {
				// 	temp = m_node;
				// 	m_node = m_node->parent;
				// 	if (m_node && m_node->left == temp) {
				// 		break;
				// 	}
				// } while (m_node->parent);
			// }
			return *this;
		}

		const_tree_iterator operator++(int) {
			const_tree_iterator temp = *this;
			++(*this);
			return temp;
		}

		const_tree_iterator &operator--() {
			m_node = m_tree.getNodePredecessor(m_tree.getRoot(), m_node);
			// if (!m_node) {
			// 	m_node = m_tree.getRoot();
			// 	while (m_node->right)
			// 		m_node = m_node->right;
			// } else if (m_node->left) {
			// 	m_node = m_node->left;
			// 	while (m_node->right) {
			// 		m_node = m_node->right;
			// 	}
			// } else {
			// 	while (m_node->parent && m_node == m_node->parent->left) {
			// 		m_node = m_node->parent;
			// 	}
			// 	m_node = m_node->parent;
			// }
			return *this;
		}

		const_tree_iterator operator--(int) {
			const_tree_iterator temp = *this;
			--(*this);
			return temp;
		}

};

template <class T, class AVL>
bool operator==(const const_tree_iterator<T, AVL> &lhs, const const_tree_iterator<T, AVL> &rhs) {
	return lhs.base() == rhs.base();
}

template <class T, class AVL>
bool operator!=(const const_tree_iterator<T, AVL> &lhs, const const_tree_iterator<T, AVL> &rhs) {
	return !(lhs == rhs);
}

}    // namespace ft

#endif    // TREE_ITERATOR_HPP
