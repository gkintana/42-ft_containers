/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:55:16 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/13 16:51:29 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft {

template <class Iter1, class Iter2>
bool lexicographical_compare(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2) {
	for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2) {
		if (*first1 < *first2) {
			return true;
		} else if (*first2 < *first1) {
			return false;
		}
	}
	return first1 == last1 && first2 != last2;
}

}    // namespace ft

#endif    // LEXICOGRAPHICAL_COMPARE_HPP
