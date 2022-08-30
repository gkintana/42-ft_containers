/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:55:18 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/30 10:30:10 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iterator_traits.hpp>
#include <iterator.hpp>

namespace ft {

	template < class Iterator >
	// class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
	//                                          typename iterator_traits<Iterator>::value_type,
	//                                          typename iterator_traits<Iterator>::difference_type,
	//                                          typename iterator_traits<Iterator>::pointer,
	//                                          typename iterator_traits<Iterator>::reference> {
	class reverse_iterator {

		public:
			typedef Iterator                                 iterator_type;
			typedef iterator_traits<iterator_type>           traits_type;
			typedef typename traits_type::pointer            pointer;
			typedef typename traits_type::reference          reference;
			typedef typename traits_type::difference_type    difference_type;

			

		private:
			iterator_type    m_iter;

	};

}

#endif
