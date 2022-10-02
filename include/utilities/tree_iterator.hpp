/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:10:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/10/03 00:28:45 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "red_black_tree.hpp"

namespace ft {

template <class T>
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
		typedef const node_pointer                                  const_node_pointer;

	private:
		node_pointer m_ptr;

	public:
		tree_iterator() : node() {}
		~tree_iterator() {}

};

}    // namespace ft

#endif    // TREE_ITERATOR_HPP
