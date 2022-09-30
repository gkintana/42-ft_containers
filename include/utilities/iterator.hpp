/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:42:27 by gkintana          #+#    #+#             */
/*   Updated: 2022/10/01 00:18:15 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_traits.hpp"

#define FT_ITERATOR typename ft::iterator<ft::random_access_iterator_tag, T>

namespace ft {

template <class Category, class T, class Distance = std::ptrdiff_t,
          class Pointer = T*, class Reference = T&>
struct iterator {
	typedef T            value_type;
	typedef Pointer      pointer;
	typedef Reference    reference;
	typedef Distance     difference_type;
	typedef Category     iterator_category;
};

template <class T>
class vector_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {

	public:
		typedef FT_ITERATOR::value_type           value_type;
		typedef FT_ITERATOR::pointer              pointer;
		typedef FT_ITERATOR::reference            reference;
		typedef FT_ITERATOR::difference_type      difference_type;
		typedef FT_ITERATOR::iterator_category    iterator_category;

	private:
		pointer	m_ptr;

	public:
		vector_iterator() : m_ptr(NULL) {}

		vector_iterator(pointer ptr) : m_ptr(ptr) {}

		vector_iterator(const vector_iterator &value) : m_ptr(NULL) {
			// if (this != value)
			*this = value;
		}

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

template <class Iterator>
inline bool operator==(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
	return lhs.base() == rhs.base();
}

template <class Iterator>
inline bool operator!=(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
	return lhs.base() != rhs.base();
}

template <class Iterator>
inline bool operator<(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
	return lhs.base() < rhs.base();
}

template <class Iterator>
inline bool operator<=(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
	return lhs.base() <= rhs.base();
}

template <class Iterator>
inline bool operator>(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
	return lhs.base() > rhs.base();
}

template <class Iterator>
inline bool operator>=(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
	return lhs.base() >= rhs.base();
}

template <class Iterator>
inline typename vector_iterator<Iterator>::difference_type
operator-(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
	return lhs.base() - rhs.base();
}

template <class Iterator>
inline typename vector_iterator<Iterator>::difference_type
operator+(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
	return lhs.base() + rhs.base();
}

}    // namespace ft

#endif    // ITERATOR_HPP
