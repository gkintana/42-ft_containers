/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:42:27 by gkintana          #+#    #+#             */
/*   Updated: 2022/10/06 17:18:01 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

template <class T>
class vector_iterator : public ft::iterator<std::random_access_iterator_tag, T> {

	public:
		typedef ft::iterator<std::random_access_iterator_tag, T>    traits_type;
		typedef typename traits_type::value_type                    value_type;
		typedef typename traits_type::pointer                       pointer;
		typedef typename traits_type::reference                     reference;
		typedef typename traits_type::difference_type               difference_type;
		typedef typename traits_type::iterator_category             iterator_category;

	private:
		pointer	m_ptr;

	public:
		vector_iterator() : m_ptr() {}

		vector_iterator(pointer ptr) : m_ptr(ptr) {}

		template <class U>
		vector_iterator(const vector_iterator<U> &value) : m_ptr(value.base()) {}

		~vector_iterator() {}

		vector_iterator &operator=(const vector_iterator& value) {
			this->m_ptr = value.m_ptr;
			return *this;
		}

		reference operator*() const { return *m_ptr; }

		pointer operator->() const { return m_ptr; }

		pointer base() const { return m_ptr; }

		reference operator[](difference_type n) const { return m_ptr[n]; }

		vector_iterator operator+(difference_type n) const { return vector_iterator(m_ptr + n); }

		vector_iterator operator-(difference_type n) const { return vector_iterator(m_ptr - n); }

		vector_iterator &operator++() {
			m_ptr++;
			return *this;
		}

		vector_iterator operator++(int) {
			vector_iterator temp = *this;
			++(*this);
			return temp;
		}

		vector_iterator &operator--() {
			m_ptr--;
			return *this;
		}

		vector_iterator operator--(int) {
			vector_iterator temp = *this;
			--(*this);
			return temp;
		}

		vector_iterator &operator+=(difference_type n) {
			m_ptr += n;
			return *this;
		}

		vector_iterator &operator-=(difference_type n) {
			m_ptr -= n;
			return *this;
		}

};

template <class Iter1, class Iter2>
inline bool operator==(const vector_iterator<Iter1> &x, const vector_iterator<Iter2> &y) {
	return x.base() == y.base();
}

template <class Iter1, class Iter2>
inline bool operator!=(const vector_iterator<Iter1> &x, const vector_iterator<Iter2> &y) {
	return x.base() != y.base();
}

template <class Iter1, class Iter2>
inline bool operator<(const vector_iterator<Iter1> &x, const vector_iterator<Iter2> &y) {
	return x.base() < y.base();
}

template <class Iter1, class Iter2>
inline bool operator<=(const vector_iterator<Iter1> &x, const vector_iterator<Iter2> &y) {
	return x.base() <= y.base();
}

template <class Iter1, class Iter2>
inline bool operator>(const vector_iterator<Iter1> &x, const vector_iterator<Iter2> &y) {
	return x.base() > y.base();
}

template <class Iter1, class Iter2>
inline bool operator>=(const vector_iterator<Iter1> &x, const vector_iterator<Iter2> &y) {
	return x.base() >= y.base();
}

// template <class Iterator>
// inline bool operator==(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
// 	return lhs.base() == rhs.base();
// }

// template <class Iterator>
// inline bool operator!=(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
// 	return lhs.base() != rhs.base();
// }

// template <class Iterator>
// inline bool operator<(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
// 	return lhs.base() < rhs.base();
// }

// template <class Iterator>
// inline bool operator<=(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
// 	return lhs.base() <= rhs.base();
// }

// template <class Iterator>
// inline bool operator>(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
// 	return lhs.base() > rhs.base();
// }

// template <class Iterator>
// inline bool operator>=(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
// 	return lhs.base() >= rhs.base();
// }

template <class Iterator>
inline typename vector_iterator<Iterator>::difference_type
operator-(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
	return lhs.base() - rhs.base();
}

template <class Iterator, class I2>
inline typename vector_iterator<Iterator>::difference_type
operator-(const vector_iterator<Iterator> &lhs, const vector_iterator<I2> &rhs) {
	return lhs.base() - rhs.base();
}

template <class Iterator>
inline vector_iterator<Iterator>
operator+(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator> &it) {
	return vector_iterator<Iterator>(it.base() + n);
}

// template <class Iterator>
// inline vector_iterator<Iterator>
// operator+(std::size_t lhs, const vector_iterator<Iterator> &rhs) {
// 	rhs += lhs;
// 	return rhs.base();
// }

}    // namespace ft

#endif    // ITERATOR_HPP
