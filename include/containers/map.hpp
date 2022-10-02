/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:49 by gkintana          #+#    #+#             */
/*   Updated: 2022/10/03 00:19:52 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <map>

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>,
	           class Allocator = std::allocator<std::pair<const Key, T> > >
	class map {

		public:
			typedef Key                                      key_type;
			typedef T                                        mapped_type;
			typedef ft::pair<const key_type, mapped_type>    value_type;
			typedef Compare                                  key_compare;
			typedef Allocator                                allocator_type;
			typedef typename allocator_type::reference       reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer         pointer;
			typedef typename allocator_type::const_pointer   const_pointer;
			typedef typename allocator_type::size_type       size_type;
			typedef typename allocator_type::difference_type difference_type;

			// TREE TYPE red_black_tree;
			// typedef implementation-defined                   iterator;
			// typedef implementation-defined                   const_iterator;
			// typedef std::reverse_iterator<iterator>          reverse_iterator;
			// typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

			// typedef unspecified                              node_type;              // C++17
			// typedef INSERT_RETURN_TYPE<iterator, node_type>  insert_return_type;

		// private:
			// red_black_tree    tree;

		public:

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
		template < class InputIterator >
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
		map(const map &x);
		map &operator=(const map &x);
		~map();


		iterator begin() { return tree.begin(); }
		const_iterator begin() const { return tree.begin(); }
		iterator end() { return tree.end(); }
		const_iterator end() const { return tree.end(); }
		reverse_iterator rbegin() { return tree.rbegin(); }
		const_reverse_iterator rbegin() const { return tree.rbegin(); }
		reverse_iterator rend() { return tree.rend(); }
		const_reverse_iterator rend() const { return tree.rend(); }

		bool empty() const { return tree.empty(); }
		size_type size() const { return tree.size(); }
		size_type max_size() const { return tree.max_size(); }


		mapped_type &at(const key_type &k);
		const mapped_type &at(const key_type &k) const;


		pair<iterator, bool> insert(const value_type &val);
		iterator insert(iterator position, const value_type &val);
		template < class InputIterator >
		void insert(InputIterator first, InputIterator last);

		void erase(iteraetor position);
		size_type erase(const key_type &k);
		void erase(iterator first, iterator last);

		void swap(map &x);
		void clear();

		key_compare key_comp() const;
		value_compare value_comp() const;


		iterator find(const key_type &k);
		const_iterator find(const key_type &k) const;
		size_type count(const key_type &k) const;
		iterator lower_bound(const key_type &k);
		const_iterator lower_bound(const key_type &) const;


		allocator_type get_allocator() const { return tree.get_allocator(); }
	};

}

#endif
