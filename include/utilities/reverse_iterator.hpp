/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:55:18 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/30 18:14:53 by gkintana         ###   ########.fr       */
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

			reverse_iterator() : m_current(NULL) {}

			explicit reverse_iterator(iterator_type x) : m_current(x) {}

			reverse_iterator& operator=(const reverse_iterator &value) {
				m_current = value.base();
				return *this;
			}

			iterator_type base() const { return m_current; }

			reference operator*() const {
				iterator_type temp = m_current;
				return *--temp;
			}

			pointer operator->() const { return &this->operator*(); }

			reference operator[](difference_type n) const { return *(m_current + n); };

			reverse_iterator operator+(difference_type n) const { return reverse_iterator(m_current - n); }

			reverse_iterator &operator+=(difference_type n) {
				m_current -= n;
				return *this;
			}

			reverse_iterator &operator++() {
				--m_current;
				return *this;
			}

			reverse_iterator operator++(int) {
				reverse_iterator temp(*this);
				--m_current;
				return temp;
			}

			reverse_iterator operator-(difference_type n) const { return reverse_iterator(m_current + n); }

			reverse_iterator &operator-=(difference_type n) {
				m_current += n;
				return *this;
			}

			reverse_iterator &operator--() {
				++m_current;
				return *this;
			}

			reverse_iterator operator--(int) {
				reverse_iterator temp(*this);
				++m_current;
				return *this;
			}

		private:
			iterator_type    m_current;

	};

	template < class Iterator1, class Iterator2 >
	inline bool
	operator==(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
		return x.base() == y.base();
	}

	template < class Iterator1, class Iterator2 >
	inline bool
	operator!=(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
		return x.base() != y.base();
	}

	template < class Iterator1, class Iterator2 >
	inline bool
	operator<(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
		return x.base() > y.base();
	}

	template < class Iterator1, class Iterator2 >
	inline bool
	operator<=(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
		return x.base() >= y.base();
	}

	template < class Iterator1, class Iterator2 >
	inline bool
	operator>(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
		return x.base() < y.base();
	}

	template < class Iterator1, class Iterator2 >
	inline bool
	operator>=(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
		return x.base() <= y.base();
	}

	// template < class Iterator1, class Iterator2 >
	// inline 
	// operator-(const reverse_iterator<Iterator1> &x, const reverse_iterator<Iterator2> &y) {
	// 	return y.base() - x.base();
	// }

	template < class Iterator >
	inline reverse_iterator<Iterator>
	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &x) {
		return reverse_iterator<Iterator>(x.base() - n);
	}

}

#endif
