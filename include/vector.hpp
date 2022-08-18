/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:07 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/18 21:25:13 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
#include <sstream>

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
// https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp

namespace ft {

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


			iterator(pointer ptr) : m_ptr(ptr) {}

			~iterator() {}

			// reference operator*() const { *return m_ptr; }
			// pointer operator->() { return m_ptr; }
			
			// iterator &operator++() {
			// 	m_ptr++;
			// 	return *this;
			// }

			// iterator operator++(T) {
			// 	iterator temp = *this;
			// 	++(*this);
			// 	return temp;
			// }

			// iterator
			
		private:
			pointer	m_ptr;

		
	};


	template < class T >
	class const_iterator {
		
	};

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

			explicit vector(const allocator_type &alloc = allocator_type()) :	m_data(NULL),
																				m_alloc(alloc),
																				m_size(0),
																				m_capacity(0) {}

			explicit vector(size_type n, const value_type &val = value_type(), 
							const allocator_type &alloc = allocator_type()) :	m_alloc(alloc),
																				m_size(n),
																				m_capacity(n * 2) {
				m_data = m_alloc.allocate(m_capacity, NULL);
				for (size_type i = 0; i < m_size; i++) {
					m_alloc.construct(m_data + i, val);
				}
			}

			vector &operator=(const vector &x) {
				std::cout << "ASSIGNEMNT OP" << std::endl;
				if (this != &x) {
					this->m_data = x.m_data;
					this->m_alloc = x.m_alloc;
					// this->m_alloc.allocate(x.m_capacity, NULL);
					this->m_size = x.m_size;
					this->m_capacity = x.m_capacity;
				}
				return *this;
			}

			vector(const vector& x) {
				std::cout << "COPY OP" << std::endl;
				*this = x;
			}
			

			~vector() {
				for (size_type i = 0; i < m_size; i++) {
					m_alloc.destroy(m_data + i);
				}
				m_alloc.deallocate(m_data, m_capacity);
			}

			allocator_type get_allocator() const { return m_alloc; }


			/*
			** Element Access
			**
			** at				access specified element with bounds checking
			** operator[]		access specified element
			** front			access the first element
			** back				access the last element
			** data				direct access to the underlying array
			*/

			reference at(size_type pos) {
				// REMINDER: add bounds checking
				if (pos >= m_size) {
					std::stringstream str;
					str << "vector::range_check: pos (which is " << pos << ") >= this->m_size() (which is " << m_size << ")";
					throw std::out_of_range(str.str());
				}
				return m_data[pos];
			}
			const_reference at(size_type pos) const {
				// REMINDER: add bounds checking
				if (pos >= m_size) {
					std::stringstream str;
					str << "ft::vector::at(): pos (which is " << pos << ") >= this->size() (which is " << m_size << ")";
					throw std::out_of_range(str.str());
				}
				return m_data[pos];
			}

			reference operator[](size_type pos)				{ return m_data[pos]; }
			const_reference operator[](size_type pos) const	{ return m_data[pos]; }
			reference front()								{ return m_data[0]; }
			const_reference front() const					{ return m_data[0]; }
			reference back()								{ return m_data[m_size - 1]; }
			const_reference back() const					{ return m_data[m_size - 1]; }
			T* data()										{ return m_data; }
			const T* data() const							{ return m_data; }

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

			bool empty()					{ return !m_size ? true : false; }
			size_type size()				{ return m_size; }
			// size_type max_size()			{ return ; }
			size_type capacity()			{ return m_capacity; }
			void reserve(size_type new_cap)	{
				(void)new_cap;
			}


			/*
			** Modifiers
			**
			** clear		clears the contents
			** insert		inserts elements
			** erase		erases elements
			** push_back	adds an element to the end
			** pop_back		removes the last element
			** resize		changes the number of elements stored
			** swap			swaps the contents
			*/

			void pop_back()	{ m_alloc.destroy(&m_data[m_size-- - 1]); }


		private:
			pointer			m_data;
			allocator_type	m_alloc;
			size_type		m_size;
			size_type		m_capacity;

	};

	/*
	** Non-Member Functions
	*/

}

#endif
