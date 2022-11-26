/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:49 by gkintana          #+#    #+#             */
/*   Updated: 2022/11/26 23:02:36 by gkintana         ###   ########.fr       */
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
		pointer           m_root;
		// size_type         m_size;

	public:

	explicit map(const key_compare &comp = key_compare(),
	             const allocator_type &alloc = allocator_type()) : m_comp(comp),
	                                                               m_alloc(alloc),
	                                                               m_root(0) {}

	// template < class InputIterator >
	// map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
	//     const allocator_type &alloc = allocator_type());

	// map(const map &x);

	// map &operator=(const map &x);

	~map() {
		// m_tree.~avl_tree();
		if (m_tree.empty() == false) {
			m_tree.free_all(m_root);
		}
	}


	iterator begin() {
		return iterator(m_tree.getMinimum(m_root), m_tree);
	}

	// const_iterator begin() const { return tree.begin(); }

	iterator end() {
		return iterator(NULL, m_tree);
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
		return m_tree.empty();
	}

	size_type size() const {
		return m_tree.size();
	}

	size_type max_size() const {
		return m_tree.max_size();
	}

	mapped_type &at(const key_type &k) {
		return this->find(k)->second;
	}

	// const mapped_type &at(const key_type &k) const;

	// ft::pair<iterator, bool> insert(const value_type val) {
	// 	m_root = m_tree.insertNode(m_root, NULL, val);

	// 	return ft::pair<iterator, bool>(iterator(NULL, m_tree), false);
	// }
	// // iterator insert(iterator position, const value_type &val);
	// // template < class InputIterator >
	// // void insert(InputIterator first, InputIterator last);

	// void erase(iterator position) {
	// 	m_tree.deleteNode(position.base(), ft::make_pair(position->first, position->second));
	// }
	// size_type erase(const key_type &k);
	// void erase(iterator first, iterator last);

	void swap(map &x) {
		m_tree.swap(x);
	}

	void clear() {
		// for (iterator it = --this->end(); it != this->begin(); it--) {
		// 	this->erase(it);
		// }

		// this->erase(iterator(m_root, m_tree));

		m_tree.free_all(m_root);
		m_root = NULL;
	}

	key_compare key_comp() const {
		return m_comp;
	}

	// value_compare value_comp() const;


	iterator find(const key_type &k) {
		return iterator(m_tree.search(m_root, k), m_tree);
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
