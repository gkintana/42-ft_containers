/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:07 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/29 00:18:18 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
#include <sstream>

#include <vector>
// #include <iterator>
#include <type_traits.hpp>
#include <iterator.hpp>

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

// https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
// https://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators#

// https://stackoverflow.com/questions/61557539/how-can-i-use-my-custom-enable-if-in-c98
// https://www.boost.org/doc/libs/1_55_0/libs/utility/enable_if.html
// https://medium.com/@sidbhasin82/c-templates-what-is-std-enable-if-and-how-to-use-it-fd76d3abbabe

namespace ft {

	template < class T, class Allocator = std::allocator<T> >
	class vector {

		public:

			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::iterator<value_type>					iterator;
			typedef ft::iterator<const value_type>				const_iterator;
			// typedef implementation-defined						iterator;
			// typedef implementation-defined						const_iterator;
			// typedef std::reverse_iterator<iterator>				reverse_iterator;
			// typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

			/**
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
							const allocator_type &alloc = allocator_type()) :	_alloc(alloc),
																				_size(n),
																				_capacity(n) {
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(_data + i, val);
				}
			}

			~vector() {
				// for (size_type i = 0; i < _size; i++) {
				// 	_alloc.destroy(_data + i);
				// }
				this->clear();
				_alloc.deallocate(_data, _capacity);
				_capacity = 0;
			}

			vector(const vector& x) : _data(NULL),
			                          _alloc(x._alloc),
									  _size(0),
									  _capacity(0) {
				*this = x;
			}

			vector &operator=(const vector &x) {
				if (!this->empty()) {
					this->~vector();
				}

				if (this != &x) {
					_data = _alloc.allocate(x._capacity);
					_size = x._size;
					_capacity = x._capacity;

					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(_data + i, *(x._data + i));
					}
				}
				return *this;
			}

			// template <class InputIterator>
			// void assign(InputIterator first, InputIterator last) {
				
			// }

			void assign(size_type n, const value_type& val) {
				this->clear();
				// if (n > _capacity) {
				// 	this->reserve(n);
				// }
				// _size = n;
				this->insert(this->begin(), n, val);
				// for (size_type i = 0; i < _size; i++) {
				// 	_alloc.construct(_data + i, val);
				// }
				
			}

			allocator_type get_allocator() const { return _alloc; }


			/**
			** Element Access
			**
			** at				access specified element with bounds checking
			** operator[]		access specified element
			** front			access the first element
			** back				access the last element
			** data				direct access to the underlying array
			*/

			reference at(size_type pos) {
				if (pos >= _size) {
					std::stringstream str;
					str << "vector::range_check: pos (which is " << pos << ") >= this->m_size() (which is " << _size << ")";
					throw std::out_of_range(str.str());
				}
				return *(_data + pos);
			}

			const_reference at(size_type pos) const {
				if (pos >= _size) {
					std::stringstream str;
					str << "ft::vector::at(): pos (which is " << pos << ") >= this->size() (which is " << _size << ")";
					throw std::out_of_range(str.str());
				}
				return *(_data + pos);
			}

			reference operator[](size_type pos) { return *(_data + pos); }

			const_reference operator[](size_type pos) const { return *(_data + pos); }

			reference front() { return *this->begin(); }

			const_reference front() const { return *this->begin(); }

			reference back() { return *(this->end() - 1); }

			const_reference back() const { return *(this->end() - 1); }

			T* data() { return _data; }

			const T* data() const { return _data; }


			/**
			** Iterators
			**
			** begin		returns an iterator to the beginning
			** end			returns an iterator to the end
			** rbegin		returns a reverse iterator to the beginning
			** rend			returns a reverse iterator to the end
			*/

			iterator begin() { return iterator(_data); }

			const_iterator begin() const { return const_iterator(_data); }

			iterator end() { return iterator(_data + _size); }

			const_iterator end() const { return const_iterator(_data + _size); }

			// reverse_iterator rbegin() {}

			// const_reverse_iterator rbegin() {}

			// reverse_iterator rend() {}

			// const_reverse_iterator rend() {}


			/**
			** Capacity
			**
			** empty			checks whether the container is empty
			** size				returns the number of elements
			** max_size			returns the maximum possible number of elements
			** capacity			returns the number of elements that can be held in currently allocated storage
			** reserve			reserves storage
			*/

			bool empty() { return !_size ? true : false; }

			size_type size() { return _size; }

			size_type max_size() const { return _alloc.max_size(); }

			size_type capacity() { return _capacity; }

			void reserve(size_type new_cap) {
				if (new_cap > this->max_size()) {
					throw std::length_error("ft::vector::reserve");
				} else if (_capacity < new_cap) {
					allocator_type _temp_alloc;
					pointer _temp_data = _temp_alloc.allocate(new_cap);

					for (size_type i = 0; i < _size; i++) {
						_temp_alloc.construct(_temp_data + i, *(_data + i));
						_alloc.destroy(_data + i);
					}
					// for (size_type i = 0; i < _size; i++) {
					// 	_alloc.destroy(_data + i);
					// }
					_alloc.deallocate(_data, _capacity);

					_data = _temp_data;
					_alloc = _temp_alloc;
					_capacity = new_cap;
				}
			}


			/**
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

			void clear() {
				for (size_type i = 0; i < _size; i++) {
					_alloc.destroy(_data + i);
				}
				_size = 0;
			}

			iterator insert(iterator position, const value_type &val) {
				// faced issues with the iterator position when the size == capacity, position
				// was being invalidated due to the reallocation of the vector
				difference_type offset = position - this->begin();
				// std::cout << "offset = " << offset << std::endl;
				if (offset >= 0) {
					if (_size == _capacity) {
						this->reserve(_capacity * 2);
					}

					if (size_type(offset) > _size) {
						_alloc.construct(_data + _size, *(_data + _size - 1));
					} else {
						for (size_type i = _size; i > size_type(offset); i--) {
							_alloc.construct(_data + i, *(_data + i - 1));
						}
						_alloc.construct(_data + size_type(offset), val);
					}
				}
				_size++;

				return position;
			}

			void insert(iterator position, size_type n, const value_type &val) {
				difference_type offset = position - this->begin();
				size_type range = size_type(offset) + n,
				          old_value = offset - range,
				          new_size = _size + n;

				if (_size + n >= _capacity) {
					// REMINDER: revise _capacity for macos
					this->reserve(std::max(_capacity * 2, _size + n));
				}
				
				allocator_type temp_alloc;
				pointer temp_data = temp_alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++) {
					temp_alloc.construct(temp_data + i, *(_data + i));
				}

				for (size_type i = range; i < new_size; i++) {
					_alloc.construct(_data + i, *(temp_data + i + old_value));
				}
				for (size_type i = offset; i < range; i++) {
					_alloc.construct(_data + i, val);
				}
				
				for (size_type i = 0; i < _size; i++) {
					temp_alloc.destroy(temp_data + i);
				}
				temp_alloc.deallocate(temp_data, _size);
				_size += n;
			}

			// template <class InputIterator>
			// void insert(iterator position, InputIterator first, InputIterator last) {
				
			// }

			iterator erase(iterator pos) {
				// std::cout << "ft::vector.size() = " << this->end() - this->begin() << std::endl;
				// std::cout << "distance of pos from begin() = " << pos - this->begin() << std::endl;

				// ADD RANGE CHECK
				// if (pos - this->begin() > this->end() - this->begin()) {
				// 	std::stringstream str;
				// 	str << "ft::vector::at(): pos (which is " << pos - this->begin() << ") >= this->size() (which is " << _size << ")";
				// 	throw std::out_of_range(str.str());
				// }

				// _alloc.destroy(_data + *pos);
				// for (size_type i = pos - this->begin(); i < _size; i++) {
				// 	_data[i] = _data[i + 1];
				// }
				for (iterator i = pos; i != this->end() - 1; i++) {
					*i = *(i + 1);
				}
				_alloc.destroy(_data + _size - 1);
				_size--;
				// if (pos == this->end()) {
				// 	return this->end();
				// }
				return pos;
			}

			iterator erase(iterator first, iterator last) {
				size_type start = first - this->begin(),
				          end = last - this->begin(),
				          range = last - first,
						  pos = 0;

				for (size_type i = 0; i < _size; i++) {
					if (i >= start && end + pos < _size) {
						_data[i] = _data[end + pos++];
					}
				}
				for (size_type i = start + range; i < _size; i++) {
					_alloc.destroy(_data + i);
				}
				_size -= range;
				return first;
			}

			void push_back(const value_type &value) {
				if (!_capacity) {
					this->reserve(1);
				} else if (_size == _capacity) {
					this->reserve(_capacity * 2);
				}
				_alloc.construct(_data + _size, value);
				_size++;
			}

			void pop_back()	{ _alloc.destroy(&_data[_size-- - 1]); }

			// REMINDER: revise & add destroy
			void resize(size_type new_size, value_type value = value_type()) {
				if (new_size > this->max_size()) {
					throw std::length_error("ft::vector::resize");
				} else if (new_size > _capacity) {
					this->reserve(std::max(_capacity * 2, new_size));
				}
				for (size_type i = _size; i < new_size; i++) {
					if (value) {
						_alloc.construct(_data + i, value);
					} else {
						_alloc.construct(_data + i, 0);
					}
				}
				_size = new_size;
			}

			void swap(vector &x) {
				pointer temp_data = _data;
				allocator_type temp_alloc = _alloc;
				size_type temp_size = _size,
				          temp_capacity = _capacity;

				_data = x._data;
				_alloc = x._alloc;
				_size = x._size;
				_capacity = x._capacity;

				x._data = temp_data;
				x._alloc = temp_alloc;
				x._size = temp_size;
				x._capacity = temp_capacity;
			}

		private:
			pointer			_data;
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
	};

	/**
	** Non-Member Functions
	*/

}

#endif
