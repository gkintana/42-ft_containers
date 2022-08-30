/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:42:27 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/30 11:11:45 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

// #include <iterator_traits.hpp>

namespace ft {

	// template <class Category, class T, class Distance = std::ptrdiff_t,
    //           class Pointer = T*, class Reference = T&>
	template < class T >
	class iterator {
		// C11
		// using iterator_category = std::forward_iterator_tag;
		// using difference_type   = std::ptrdiff_t;
		// using value_type        = T;
		// using pointer           = T*;
		// using reference         = T&;

		public:
			typedef T                             value_type;
			typedef T*                            pointer;
			typedef T&                            reference;
			typedef std::ptrdiff_t                difference_type;
			typedef random_access_iterator_tag    iterator_category;

			iterator() : m_ptr(NULL) {}

			iterator(pointer ptr) : m_ptr(ptr) {}

			// ~iterator() {}

			iterator &operator=(const iterator& value) {
				this->m_ptr = value.m_ptr;
				return *this;
			}

			reference operator*() const { return *m_ptr; }

			pointer operator->() const { return m_ptr; }

			pointer base() const { return m_ptr; }

			reference operator[](difference_type n) const { return m_ptr[n]; }

			iterator operator+(difference_type n) const { return iterator(m_ptr + n); }

			iterator operator-(difference_type n) const { return iterator(m_ptr - n); }

			iterator &operator++() {
				m_ptr++;
				return *this;
			}

			iterator operator++(int) {
				iterator temp = *this;
				++(*this);
				return temp;
			}

			iterator &operator--() {
				m_ptr--;
				return *this;
			}

			iterator operator--(int) {
				iterator temp = *this;
				--(*this);
				return temp;
			}

			iterator &operator+=(difference_type n) {
				m_ptr += n;
				return *this;
			}

			iterator &operator-=(difference_type n) {
				m_ptr -= n;
				return *this;
			}

		private:
			pointer	m_ptr;

	};

	template < class Iterator >
	inline bool
	operator==(const iterator<Iterator> &lhs, const iterator<Iterator> &rhs) {
		return lhs.base() == rhs.base();
	}

	template < class Iterator >
	inline bool
	operator!=(const iterator<Iterator> &lhs, const iterator<Iterator> &rhs) {
		return lhs.base() != rhs.base();
	}

	template < class Iterator >
	inline bool
	operator<(const iterator<Iterator> &lhs, const iterator<Iterator> &rhs) {
		return lhs.base() < rhs.base();
	}

	template < class Iterator >
	inline bool
	operator<=(const iterator<Iterator> &lhs, const iterator<Iterator> &rhs) {
		return lhs.base() <= rhs.base();
	}

	template < class Iterator >
	inline bool
	operator>(const iterator<Iterator> &lhs, const iterator<Iterator> &rhs) {
		return lhs.base() > rhs.base();
	}

	template < class Iterator >
	inline bool
	operator>=(const iterator<Iterator> &lhs, const iterator<Iterator> &rhs) {
		return lhs.base() >= rhs.base();
	}

	template < class Iterator >
	inline typename iterator<Iterator>::difference_type
	operator-(const iterator<Iterator> &lhs, const iterator<Iterator> &rhs) {
		return lhs.base() - rhs.base();
	}

	template < typename Iterator >
	inline typename iterator<Iterator>::difference_type
	operator+(const iterator<Iterator> &lhs, const iterator<Iterator> &rhs) {
		return lhs.base() + rhs.base();
	}


	// template < class T >
	// class const_iterator {
		
	// };

}

#endif
