/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:55 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/28 23:26:35 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <vector.hpp>
// #include <stack>

namespace ft {

template < class T, class Container = ft::vector<T> >
class stack {

	public:
		typedef Container                                   container_type;
		typedef typename container_type::value_type         value_type;
		typedef typename container_type::size_type          size_type;
		typedef typename container_type::reference          reference;
		typedef typename container_type::const_reference    const_reference;

	protected:
		container_type    container;

	public:
		explicit stack(const container_type& cont = container_type()) : container(cont) {}

		/**
		** Element Access
		**
		** top    accesses the top element
		*/

		reference top() { return container.back(); }

		const reference top() const { return container.back(); }

		/**
		** Capacity
		**
		** empty    checks whether the underlying container is empty
		** size     returns the number of elements
		*/

		bool empty() const { return container.empty(); }

		size_type size() const { return container.size(); }

		/**
		** Modifiers
		**
		** push    inserts element at the top
		** pop     removes the top element
		*/

		void push(const value_type &value) { container.push_back(value); }

		void pop() { container.pop_back(); }

};

/**
** Non-Member Functions
*/

template <class T, class Container>
inline bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return lhs.container == rhs.container;
}

template <class T, class Container>
inline bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return !(lhs == rhs);
}

template <class T, class Container>
inline bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return lhs.container < rhs.container;
}

template <class T, class Container>
inline bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return !(rhs < lhs);
}

template <class T, class Container>
inline bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return rhs < lhs;
}

template <class T, class Container>
inline bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return !(lhs < rhs);
}

}    // namespace ft

#endif    // STACK_HPP
