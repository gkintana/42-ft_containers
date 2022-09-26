/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:49 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/26 18:51:49 by gkintana         ###   ########.fr       */
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
			typedef pair<const key_type, mapped_type>        value_type;
			typedef Compare                                  key_compare;
			typedef Allocator                                allocator_type;
			typedef typename allocator_type::reference       reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer         pointer;
			typedef typename allocator_type::const_pointer   const_pointer;
			typedef typename allocator_type::size_type       size_type;
			typedef typename allocator_type::difference_type difference_type;

			// typedef implementation-defined                   iterator;
			// typedef implementation-defined                   const_iterator;
			// typedef std::reverse_iterator<iterator>          reverse_iterator;
			// typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
			// typedef unspecified                              node_type;              // C++17
			// typedef INSERT_RETURN_TYPE<iterator, node_type>  insert_return_type;

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
		template < class InputIterator >
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
		map(const map &x);
		map &operator=(const map &x);
		~map();


		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;


		bool empty() const;
		size_type size() const;
		size_type max_size() const;

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

		allocator_type get_allocator() const;
	};

}

#endif
