/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:07 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/17 13:52:30 by gkintana         ###   ########.fr       */
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
// https://cplusplus.com/reference/memory/allocator/
// https://codereview.stackexchange.com/questions/255149/stdvector-allocator-aware-implementation
// https://codereview.stackexchange.com/questions/240457/stdvector-implementation-c?rq=1
// https://codereview.stackexchange.com/questions/94211/implementation-of-stdvector-class?rq=1
// https://codereview.stackexchange.com/questions/96253/second-implementation-of-stdvector?rq=1
// https://codereview.stackexchange.com/questions/240457/stdvector-implementation-c?rq=1

namespace ft {

	template < class T, class Allocator = std::allocator<T> >
	class vector {

		public:

			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			// typedef implementation-defined						iterator;
			// typedef implementation-defined						const_iterator;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			// typedef std::reverse_iterator<iterator>				reverse_iterator;
			// typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

			/*
			** Member Functions
			**
			** constructor		constructs the vector
			** destructor		destructs the vector
			** operator=		assigns values to the container
			** assign			assigns values to the container
			** get_allocator	returns the associated allocator
			*/

			explicit vector(const allocator_type &alloc = allocator_type()) :	_data(NULL),
																				_alloc(alloc),
																				_size(0),
																				_capacity(0) {}

			explicit vector(size_type n, const value_type &val = value_type(), 
							const allocator_type &alloc = allocator_type()) {
				_size = n;
				_capacity = n * 2;
				_alloc = alloc;
				_data = _alloc.allocate(_capacity, NULL);
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(_data + i, val);
				}
			}

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

			// reference at(size_type pos) {
			// 	return _data[]
			// }

			reference operator[](size_type pos)				{ return _data[pos]; }
			const_reference operator[](size_type pos) const	{ return _data[pos]; }
			reference front()								{ return _data[0]; }
			const_reference front() const					{ return _data[0]; }
			reference back()								{ return _data[_size - 1]; }
			const_reference back() const					{ return _data[_size - 1]; }
			T* data()										{ return _data; }

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

			void pop_back() {
				
			}

		private:
			pointer			_data;
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;

	};

	/*
	** Non-Member Functions
	*/

}

#endif
