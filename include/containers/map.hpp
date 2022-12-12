/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:49 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/12 15:57:01 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <map>

#include "stack.hpp"
#include "../utilities/avl_tree.hpp"
#include "../utilities/equal.hpp"
#include "../utilities/lexicographical_compare.hpp"
#include "../utilities/reverse_iterator.hpp"

namespace ft {

template < class Key, class T, class Compare = std::less<Key>,
			class Allocator = std::allocator< ft::pair<const Key, T> > >
class map {

	public:
		typedef Key                                         key_type;
		typedef T                                           mapped_type;
		typedef ft::pair<const key_type, mapped_type>       value_type;
		typedef Compare                                     key_compare;
		typedef Allocator                                   allocator_type;
		// typedef typename allocator_type::reference          reference;
		// typedef typename allocator_type::const_reference    const_reference;
		// typedef typename allocator_type::pointer            pointer;
		// typedef typename allocator_type::const_pointer      const_pointer;
		typedef typename allocator_type::size_type          size_type;
		typedef typename allocator_type::difference_type    difference_type;

		typedef tree_node<value_type>                       node_type;
		typedef node_type*                                  pointer;
		typedef avl_tree<key_type, mapped_type,
		                 key_compare, allocator_type>       tree_type;
		typedef map_iterator<value_type, key_compare>         iterator;
		typedef const_map_iterator<value_type, key_compare>   const_iterator;
		typedef ft::reverse_iterator<iterator>              reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

		class value_compare : public std::binary_function<value_type, value_type, bool> {
			friend class map;
			protected:
				key_compare m_comp;

				value_compare(key_compare c) : m_comp(c) {}

			public:
				bool operator()(const value_type &x, const value_type &y) const {
					return m_comp(x.first, y.first);
				}
		};    // class value_compare

	private:
		tree_type         m_tree;
		key_compare       m_comp;
		allocator_type    m_alloc;
		// pointer           m_root;
		size_type         m_size;

	public:

	explicit map(const key_compare &comp = key_compare(),
	             const allocator_type &alloc = allocator_type()) : m_comp(comp),
	                                                               m_alloc(alloc),
	                                                            //    m_root(0),
	                                                               m_size(0) {}

	template < class InputIterator >
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
	    const allocator_type &alloc = allocator_type()) : m_comp(comp),
	                                                      m_alloc(alloc),
	                                                      m_size(0) {
		this->insert(first, last);
	}

	map(const map &x) : m_comp(x.m_comp),
	                    m_alloc(x.m_alloc),
						m_size(0) {
		this->insert(x.begin(), x.end());
	}

	map &operator=(const map &x) {
		this->clear();
		if (this != &x) {
			// m_tree = x.m_tree;
			m_comp = x.m_comp;
			m_alloc = x.m_alloc;
			// m_size = x.m_size;
		}
		this->insert(x.begin(), x.end());
		return *this;
	}

	~map() {
		// if (m_tree.empty() == false) {
		m_tree.clear(m_tree.getRoot(), true);
			// m_tree.clear(true);
		// }
		// m_tree.freeSentinelNode();
	}


	iterator begin() {
		if (m_tree.getRoot() == NULL) {
			return iterator(m_tree.getSentinel(), m_tree.getRoot(), m_tree.getSentinel());
		}
		return iterator(m_tree.getMinimum(m_tree.getRoot()), m_tree.getRoot(), m_tree.getSentinel());
	}

	const_iterator begin() const {
		if (m_tree.getRoot() == NULL) {
			return const_iterator(m_tree.getSentinel(), m_tree.getRoot(), m_tree.getSentinel());
		}
		return const_iterator(m_tree.getMinimum(m_tree.getRoot()), m_tree.getRoot(), m_tree.getSentinel());
	}

	iterator end() {
		// if (m_tree.getRoot() == NULL) {
		// 	return iterator(NULL, m_tree);
		// }
		return iterator(m_tree.getSentinel(), m_tree.getRoot(), m_tree.getSentinel());
	}

	const_iterator end() const {
		// if (m_tree.getRoot() == NULL) {
		// 	return const_iterator(NULL, m_tree);
		// }
		return const_iterator(m_tree.getSentinel(), m_tree.getRoot(), m_tree.getSentinel());
	}

	reverse_iterator rbegin() {
		return reverse_iterator(this->end());
	}

	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(this->end());
	}

	reverse_iterator rend() {
		return reverse_iterator(this->begin());
	}

	const_reverse_iterator rend() const {
		return const_reverse_iterator(this->begin());
	}

	bool empty() const {
		return m_size == 0;
	}

	size_type size() const {
		return m_size;
	}

	size_type max_size() const {
		return m_tree.max_size();
	}

	mapped_type &at(const key_type &k) {
		iterator it = this->find(k);
		if (it.base() == m_tree.getSentinel()) {
			throw std::out_of_range("map::at");
		}
		return it->second;
	}

	// const mapped_type &at(const key_type &k) const;

	mapped_type &operator[](const key_type &k) {
		this->insert(ft::make_pair(k, mapped_type()));
		return this->find(k)->second;
	}

	ft::pair<iterator, bool> insert(const value_type value) {
		// m_root = m_tree.insertNode(m_root, val);
		// m_tree.insertNode(val);
		if (this->find(value.first).base() == m_tree.getSentinel()) {
			m_tree.updateRoot(m_tree.insertNode(m_tree.getRoot(), value));
			m_size++;
			return ft::pair<iterator, bool>(this->find(value.first), true);
		}
		return ft::pair<iterator, bool>(iterator(m_tree.getRoot(), m_tree.getRoot(), m_tree.getSentinel()), false);
	}

	iterator insert(iterator position, const value_type &val) {
		(void)position;
		insert(val);
		return find(val.first);
	}

	template < class InputIterator >
	void insert(InputIterator first, InputIterator last) {
		while (first != last) {
			this->insert(ft::make_pair(first->first, first->second));
			first++;
		}
	}

	void erase(iterator position) {
		if (position.base() == m_tree.getSentinel()) {
			// position = iterator(NULL, m_tree);
			// pointer temp = position.base()->right;
			std::cout << position.base()->right->value.first << std::endl;
			// std::cout << "Should segfault here" << std::endl;
			// m_tree.updateRoot(m_tree.deleteNode(m_tree.getRoot(), ft::make_pair(NULL, NULL)));
		}
		m_tree.updateRoot(m_tree.deleteNode(m_tree.getRoot(), ft::make_pair(position->first, position->second)));
		m_size--;
	}

	size_type erase(const key_type &k) {
		if (this->find(k).base() != m_tree.getSentinel()) {
			this->erase(this->find(k));
			return 1;
		}
		return 0;
	}

	void erase(iterator first, iterator last) {
		ft::stack<key_type> temp;
		for (iterator it = first; it != last; it++) {
			temp.push(it->first);
		}
		for ( ; !temp.empty(); temp.pop()) {
			this->erase(temp.top());
		}
	}

	void swap(map &x) {
		tree_type temp_tree = m_tree;
		key_compare temp_comp = m_comp;
		allocator_type temp_alloc = m_alloc;
		size_type temp_size = m_size;

		m_tree = x.m_tree;
		m_comp = x.m_comp;
		m_alloc = x.m_alloc;
		m_size = x.m_size;

		x.m_tree = temp_tree;
		x.m_comp = temp_comp;
		x.m_alloc = temp_alloc;
		x.m_size = temp_size;
	}

	void clear() {
		// for (iterator it = --this->end(); it != this->begin(); it--) {
		// 	this->erase(it);
		// }

		// this->erase(iterator(m_root, m_tree));

		// m_tree.clear(false);
		m_tree.clear(m_tree.getRoot(), false);
		m_size = 0;
		// m_tree.getRoot() = NULL;
	}

	key_compare key_comp() const {
		return m_comp;
	}

	value_compare value_comp() const {
		return value_compare(this->key_comp());
	}

	iterator find(const key_type &k) {
		return iterator(m_tree.search(m_tree.getRoot(), k), m_tree.getRoot(), m_tree.getSentinel());
	}

	const_iterator find(const key_type &k) const {
		return const_iterator(m_tree.search(m_tree.getRoot(), k), m_tree.getRoot(), m_tree.getSentinel());
	}

	size_type count(const key_type &k) const {
		return this->find(k).base() == m_tree.getSentinel() ? 0 : 1;
	}

	iterator lower_bound(const key_type &k) {
		if (this->find(k).base() != m_tree.getSentinel()) {
			return this->find(k);
		}
		return iterator(m_tree.getKeySuccessor(m_tree.getRoot(), k), m_tree.getRoot(), m_tree.getSentinel());
	}

	const_iterator lower_bound(const key_type &k) const {
		if (this->find(k).base() != m_tree.getSentinel()) {
			return this->find(k);
		}
		return const_iterator(m_tree.getKeySuccessor(m_tree.getRoot(), k), m_tree.getRoot(), m_tree.getSentinel());
	}

	iterator upper_bound(const key_type &k) {
		return iterator(m_tree.getKeySuccessor(m_tree.getRoot(), k), m_tree.getRoot(), m_tree.getSentinel());
	}

	const_iterator upper_bound(const key_type &k) const {
		return const_iterator(m_tree.getKeySuccessor(m_tree.getRoot(), k), m_tree.getRoot(), m_tree.getSentinel());
	}

	ft::pair<iterator, iterator> equal_range(const key_type &k) {
		return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
	}

	ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const {
		return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
	}

	allocator_type get_allocator() const {
		return m_alloc;
	}

};

/**
 * @REMINDER: add ft::equal
*/
template <class Key, class T, class Compare, class Allocator>
bool operator==(const ft::map<Key, T, Compare, Allocator> &lhs,
                const ft::map<Key, T, Compare, Allocator> &rhs) {
	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class Key, class T, class Compare, class Allocator>
bool operator!=(const ft::map<Key, T, Compare, Allocator> &lhs,
                const ft::map<Key, T, Compare, Allocator> &rhs) {
	return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Allocator>
bool operator<(const ft::map<Key, T, Compare, Allocator> &lhs,
               const ft::map<Key, T, Compare, Allocator> &rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class Key, class T, class Compare, class Allocator>
bool operator<=(const ft::map<Key, T, Compare, Allocator> &lhs,
                const ft::map<Key, T, Compare, Allocator> &rhs) {
	return !(rhs < lhs);
}

template <class Key, class T, class Compare, class Allocator>
bool operator>(const ft::map<Key, T, Compare, Allocator> &lhs,
               const ft::map<Key, T, Compare, Allocator> &rhs) {
	return rhs < lhs;
}

template <class Key, class T, class Compare, class Allocator>
bool operator>=(const ft::map<Key, T, Compare, Allocator> &lhs,
                const ft::map<Key, T, Compare, Allocator> &rhs) {
	return !(lhs < rhs);
}

}    // namespace ft

#endif    // MAP_HPP
