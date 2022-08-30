/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:55:16 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/30 22:51:29 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {

	template< class Iterator1, class Iterator2 >
	bool lexicographical_compare(Iterator1 first1, Iterator1 last1,
	                             Iterator2 first2, Iterator2 last2) {
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void)++first2) {
			if (*first1 < *first2) {
				return true;
			}
			if (*first2 < *first1) {
				return false;
			}
		}
		return first1 == last1 && first2 != last2;
	}

}

#endif
