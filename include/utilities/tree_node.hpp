/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_node.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:43:44 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/13 23:11:34 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

namespace ft {

/**
 * @brief    parent node will always be NULL, it only exists to increase the
 *           chances that ft::map::max_size and std::map::max_size will
 *           return the same value in macOS.
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

	~tree_node() {}
};

}    // namespace ft

#endif    // TREE_NODE_HPP
