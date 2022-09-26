/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:33:20 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/26 23:45:28 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

#include <utility>

namespace ft {

	template <class T1, class T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair() : first(), second() {}

		template <class U1, class U2>
		pair(const pair<U1, U2> &other) : first(other.first), second(other.second) {}

		pair(const first_type &a, const second_type &b) : first(a), second(b) {}

		pair &operator=(const pair &other) {
			if (this != &other) {
				this->first = other.first;
				this->second = other.second;
			}
			return *this;
		}
	};

	template <class T1, class T2>
	inline bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	inline bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	inline bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	inline bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	inline bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return rhs < lhs;
	}

	template <class T1, class T2>
	inline bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return !(lhs < rhs);
	}

}

#endif
