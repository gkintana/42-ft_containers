/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_validity.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:53:38 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/13 23:12:41 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VALIDITY_HPP
#define ITERATOR_VALIDITY_HPP

#include "iterator_traits.hpp"

namespace ft {

template <class Iter>
void iterator_validity(Iter first, Iter last, typename ft::input_iterator_tag) {
	(void)first;
	(void)last;
}

template <class Iter>
void iterator_validity(Iter first, Iter last, typename ft::output_iterator_tag) {
	(void)first;
	(void)last;
}

template <class Iter>
void iterator_validity(Iter first, Iter last, typename ft::forward_iterator_tag) {
	(void)first;
	(void)last;
}

template <class Iter>
void iterator_validity(Iter first, Iter last, typename ft::bidirectional_iterator_tag) {
	(void)first;
	(void)last;
}

template <class Iter>
void iterator_validity(Iter first, Iter last, typename ft::random_access_iterator_tag) {
	if (first > last) {
		throw std::length_error("cannot create std::vector larger than max_size()");
	}
}

template <class Iter>
void iterator_validity(Iter first, Iter last, typename std::input_iterator_tag) {
	(void)first;
	(void)last;
}

template <class Iter>
void iterator_validity(Iter first, Iter last, typename std::output_iterator_tag) {
	(void)first;
	(void)last;
}

template <class Iter>
void iterator_validity(Iter first, Iter last, typename std::forward_iterator_tag) {
	(void)first;
	(void)last;
}

template <class Iter>
void iterator_validity(Iter first, Iter last, typename std::bidirectional_iterator_tag) {
	(void)first;
	(void)last;
}

template <class Iter>
void iterator_validity(Iter first, Iter last, typename std::random_access_iterator_tag) {
	if (first > last) {
		throw std::length_error("cannot create std::vector larger than max_size()");
	}
}

template <class Iter>
void check_range(Iter first, Iter last) {
	iterator_validity(first, last, typename ft::iterator_traits<Iter>::iterator_category());
}

}    // namespace ft

#endif    // ITERATOR_VALIDITY_HPP
