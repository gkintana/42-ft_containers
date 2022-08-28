/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:47:12 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/28 22:48:06 by gkintana         ###   ########.fr       */
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
	template <typename Iterator>
	struct iterator_traits {
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	/**
	** partial specialization for pointer types
	*/
	template <typename ItPointer>
	struct iterator_traits<ItPointer*> {
		typedef ItPointer						value_type;
		typedef ItPointer*						pointer;
		typedef ItPointer&						reference;
		typedef std::ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	/**
	** partial specialization for const pointer types
	*/
	template <typename ItPointer>
	struct iterator_traits<const ItPointer*> {
		typedef ItPointer						value_type;
		typedef const ItPointer*				pointer;
		typedef const ItPointer&				reference;
		typedef std::ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag	iterator_category;
	};

}

#endif
