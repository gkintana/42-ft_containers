/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:42:27 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/28 22:51:31 by gkintana         ###   ########.fr       */
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
			typedef T							value_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef std::ptrdiff_t				difference_type;
			typedef std::forward_iterator_tag	iterator_category;

			iterator() : _m_ptr(NULL) {}

			iterator(pointer _ptr) : _m_ptr(_ptr) {}

			// ~iterator() {}

			iterator &operator=(const iterator& _value) {
				this->_m_ptr = _value._m_ptr;
				return *this;
			}

			reference operator*() const { return *_m_ptr; }

			pointer operator->() const { return _m_ptr; }

			pointer base() const { return _m_ptr; }

			reference operator[](difference_type _n) const { return _m_ptr[_n]; }

			iterator operator+(difference_type _n) const { return iterator(_m_ptr + _n); }

			iterator operator-(difference_type _n) const { return iterator(_m_ptr - _n); }

			iterator &operator++() {
				_m_ptr++;
				return *this;
			}

			iterator operator++(int) {
				iterator _temp = *this;
				++(*this);
				return _temp;
			}

			iterator &operator--() {
				_m_ptr--;
				return *this;
			}

			iterator operator--(int) {
				iterator _temp = *this;
				--(*this);
				return _temp;
			}

			iterator &operator+=(difference_type _n) {
				_m_ptr += _n;
				return *this;
			}

			iterator &operator-=(difference_type _n) {
				_m_ptr -= _n;
				return *this;
			}

		private:
			pointer	_m_ptr;

	};

	template < typename _iterator >
	inline bool
	operator==(const iterator<_iterator> &_lhs, const iterator<_iterator> &_rhs) {
		return _lhs.base() == _rhs.base();
	}

	template < typename _iterator >
	inline bool
	operator!=(const iterator<_iterator> &_lhs, const iterator<_iterator> &_rhs) {
		return _lhs.base() != _rhs.base();
	}

	template < typename _iterator >
	inline bool
	operator<(const iterator<_iterator> &_lhs, const iterator<_iterator> &_rhs) {
		return _lhs.base() < _rhs.base();
	}

	template < typename _iterator >
	inline bool
	operator<=(const iterator<_iterator> &_lhs, const iterator<_iterator> &_rhs) {
		return _lhs.base() <= _rhs.base();
	}

	template < typename _iterator >
	inline bool
	operator>(const iterator<_iterator> &_lhs, const iterator<_iterator> &_rhs) {
		return _lhs.base() > _rhs.base();
	}

	template < typename _iterator >
	inline bool
	operator>=(const iterator<_iterator> &_lhs, const iterator<_iterator> &_rhs) {
		return _lhs.base() >= _rhs.base();
	}

	template < typename _iterator >
	inline typename iterator<_iterator>::difference_type
	operator-(const iterator<_iterator> &_lhs, const iterator<_iterator> &_rhs) {
		return _lhs.base() - _rhs.base();
	}

	template < typename _iterator >
	inline typename iterator<_iterator>::difference_type
	operator+(const iterator<_iterator> &_lhs, const iterator<_iterator> &_rhs) {
		return _lhs.base() + _rhs.base();
	}


	// template < class T >
	// class const_iterator {
		
	// };

}

#endif
