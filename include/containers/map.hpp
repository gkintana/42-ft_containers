/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:49 by gkintana          #+#    #+#             */
/*   Updated: 2022/11/29 00:18:04 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <map>

#include "pair.hpp"
#include "avl_tree.hpp"
#include "tree_iterator.hpp"

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
		typedef typename allocator_type::reference          reference;
		typedef typename allocator_type::const_reference    const_reference;
		// typedef typename allocator_type::pointer            pointer;
		// typedef typename allocator_type::const_pointer      const_pointer;
		typedef typename allocator_type::size_type          size_type;
		typedef typename allocator_type::difference_type    difference_type;

		typedef tree_node<value_type>                       node_type;
		typedef node_type*                                  pointer;
		typedef avl_tree<key_type, mapped_type,
		                 key_compare, allocator_type>       tree_type;
		typedef tree_iterator<value_type, tree_type>        iterator;
		// typedef implementation-defined                   iterator;
		// typedef implementation-defined                   const_iterator;
		typedef ft::reverse_iterator<iterator>              reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

		// typedef unspecified                              node_type;              // C++17
		// typedef INSERT_RETURN_TYPE<iterator, node_type>  insert_return_type;

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

	// template < class InputIterator >
	// map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
	//     const allocator_type &alloc = allocator_type());

	// map(const map &x);

	map &operator=(const map &x) {
		this->clear();
		if (this != &x) {
			// m_tree = x.m_tree;
			m_comp = x.m_comp;
			m_alloc = x.m_alloc;
			m_size = x.m_size;
		}

		/**
		 * @REMINDER: uncomment once const_iterators are implemented
		*/
		// insert(x.begin(), x.end());
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
			return iterator(NULL, m_tree);
		}
		return iterator(m_tree.getMinimum(m_tree.getRoot()), m_tree);
	}

	// const_iterator begin() const { return tree.begin(); }

	iterator end() {
		if (m_tree.getRoot() == NULL) {
			return iterator(NULL, m_tree);
		}
		return iterator(m_tree.getSentinel(), m_tree);
	}

	// const_iterator end() const { return tree.end(); }

	reverse_iterator rbegin() {
		return reverse_iterator(this->end());
	}

	// const_reverse_iterator rbegin() const { return tree.rbegin(); }

	reverse_iterator rend() {
		return reverse_iterator(this->begin());
	}

	// const_reverse_iterator rend() const { return tree.rend(); }

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
		return this->find(k)->second;
	}

	// const mapped_type &at(const key_type &k) const;

	ft::pair<iterator, bool> insert(const value_type value) {
		// m_root = m_tree.insertNode(m_root, val);
		// m_tree.insertNode(val);
		m_tree.updateRoot(m_tree.insertNode(m_tree.getRoot(), value));
		m_size++;
		return ft::pair<iterator, bool>(iterator(NULL, m_tree), false);
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
		if (this->find(k).base() != NULL) {
			this->erase(this->find(k));
			return 1;
		}
		return 0;
	}

	void erase(iterator first, iterator last) {
		// iterator it(first);
		// while (first != last) {

		// }

		// for (iterator it = first; first != last; ) {
			// std::cout << "Erased Key Value = " << it->first << std::endl;
		// 	this->erase(++it);
		// 	it = first;
		// }


		// iterator i = first;
		// while (first.base()->value.first != last.base()->value.first) {
		// 	std::cout << "Erased Key Value = " << first.base()->value.first << std::endl;
		// 	erase(first);
		// 	first = ++i;
		// }
		iterator it = first;
		size_type count = 0;

		while (it != last) {
			std::cout << "Erased Key Value = " << it.base()->value.first << std::endl;
			it++;
			count++;
		}

		it--;
		while (count > 0) {
			erase(it--);
			count--;
		}

		// iterator j;
		// while (--i != first) {
		// 	j = i;
		// 	std::cout << "Erased Key Value = " << i.base()->value.first << std::endl;
		// 	erase(j);
		// }
			// erase(first);

		// (void)last;
		// iterator i = first;
		// std::cout << "Erased Key Value = " << i.base()->value.first << std::endl;
		// this->erase(++i);
		// i = first;
		// std::cout << "Erased Key Value = " << i.base()->value.first << std::endl;
	}

	void swap(map &x) {
		m_tree.swap(x);
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

	// value_compare value_comp() const;


	iterator find(const key_type &k) {
		return iterator(m_tree.search(m_tree.getRoot(), k), m_tree);
	}
	// const_iterator find(const key_type &k) const;
	// size_type count(const key_type &k) const;
	// iterator lower_bound(const key_type &k);
	// const_iterator lower_bound(const key_type &) const;


	allocator_type get_allocator() const {
		return m_alloc.get_allocator();
	}

};

}    // namespace ft

#endif    // MAP_HPP
