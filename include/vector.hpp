/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:07 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/16 22:59:53 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

#include <vector>

// https://en.cppreference.com/w/cpp/container/vector
// https://stackoverflow.com/questions/5159061/implementation-of-vector-in-c
// https://codereview.stackexchange.com/questions/240457/stdvector-implementation-c
// https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01069_source.html
// https://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators#

namespace ft {

	template < class T, class Allocator = std::allocator<T> >
	class vector {

		public:

			typedef T									value_type;
			typedef Allocator							allocator_type;
			typedef typename allocator_type::pointer	pointer;
			typedef typename allocator_type::size_type	size_type;

			/*
			** Member Functions
			**
			** constructor		constructs the vector
			** destructor		destructs the vector
			** operator=		assigns values to the container
			** assign			assigns values to the container
			** get_allocator	returns the associated allocator
			*/

			explicit vector() :	_data(NULL),
								_size(0),
								_capacity(0) {}

			~vector() {}

			allocator_type get_allocator() const {}


			/*
			** Element Access
			**
			** at				access specified element with bounds checking
			** operator[]		access specified element
			** front			access the first element
			** back				access the last element
			** data				direct access to the underlying array
			*/


			/*
			** Iterators
			*/


			/*
			** Capacity
			**
			** empty			checks whether the container is empty
			** size				returns the number of elements
			** max_size			returns the maximum possible number of elements
			** reserve			reserves storage
			** capacity			returns the number of elements that can be held in currently allocated storage
			*/

			bool empty()					{ return !_size ? true : false; }
			size_type size()				{ return _size; }
			// size_type max_size()			{ return ; }
			size_type capacity()			{ return _capacity; }
			void reserve(size_type new_cap)	{
				(void)new_cap;
			}


			/*
			** Modifiers
			*/



		private:
			pointer		_data;
			size_type	_size;
			size_type	_capacity;

	};

	/*
	** Non-Member Functions
	*/

}

#endif