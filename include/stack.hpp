/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:55 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/22 18:26:44 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <vector.hpp>

#include <stack>

namespace ft {

	template < class T, class Container = ft::vector<T> >
	class stack {

		public:
			typedef Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::size_type			size_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;

			stack() : _ft_vector() {}

			/**
			** Element Access
			**
			** top	accesses the top element
			*/

			reference top() { return _ft_vector.back(); }

			/**
			** Capacity
			**
			** empty	checks whether the underlying container is empty
			** size		returns the number of elements
			*/

			bool empty() { return _ft_vector.empty(); }

			size_type size() { return _ft_vector.size(); }

			/**
			** Modifiers
			**
			** push		inserts element at the top
			** pop		removes the top element
			*/

			void push(const value_type &value) { _ft_vector.push_back(value); }

			void pop() { _ft_vector.pop_back(); }

		private:


		protected:
			container_type	_ft_vector;

	};

	/*
	** Non-Member Functions
	*/


}

#endif
