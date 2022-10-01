/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:47:12 by gkintana          #+#    #+#             */
/*   Updated: 2022/10/01 23:28:42 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft {

/**
** iterator_tags
**
** empty types used to distinguish different iterators. Different underlying
** algorithms can then be used based on the different operations supported
** by different iterator types
*/

///  Marking input iterators.
struct input_iterator_tag { };
///  Marking output iterators.
struct output_iterator_tag { };
/// Forward iterators support a superset of input iterator operations.
struct forward_iterator_tag : public input_iterator_tag { };
/// Bidirectional iterators support a superset of forward iterator
/// operations.
struct bidirectional_iterator_tag : public forward_iterator_tag { };
/// Random-access iterators support a superset of bidirectional
/// iterator operations.
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

/**
** traits class for iterators
**
** simplifies nested typedefs
*/
template <class Iterator>
struct iterator_traits {
	typedef typename Iterator::value_type           value_type;
	typedef typename Iterator::pointer              pointer;
	typedef typename Iterator::reference            reference;
	typedef typename Iterator::difference_type      difference_type;
	typedef typename Iterator::iterator_category    iterator_category;
};

/**
** partial specialization for pointer types
*/
template <class IterPointer>
struct iterator_traits<IterPointer*> {
	typedef IterPointer                        value_type;
	typedef IterPointer*                       pointer;
	typedef IterPointer&                       reference;
	typedef std::ptrdiff_t                     difference_type;
	typedef ft::random_access_iterator_tag     iterator_category;
};

/**
** specialization for const pointer types
*/
template <class IterPointer>
struct iterator_traits<const IterPointer*> {
	typedef IterPointer                        value_type;
	typedef const IterPointer*                 pointer;
	typedef const IterPointer&                 reference;
	typedef std::ptrdiff_t                     difference_type;
	typedef ft::random_access_iterator_tag     iterator_category;
};

template <class Category, class T, class Distance = std::ptrdiff_t,
          class Pointer = T*, class Reference = T&>
struct iterator {
	typedef T            value_type;
	typedef Pointer      pointer;
	typedef Reference    reference;
	typedef Distance     difference_type;
	typedef Category     iterator_category;
};

}    // namespace ft

#endif    // ITERATOR_TRAITS_HPP
