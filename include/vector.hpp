/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:07 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/27 23:06:52 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
#include <sstream>

#include <vector>
#include <iterator>

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

	/**
	** iterator_tags
	**
	** empty types used to distinguish different iterators. Different underlying
	** algorithms can then be used based on the different operations supported
	** by different iterator types
	*/

	///  Marking input iterators.
	struct input_iterator_tag { };
	///  Marking output iterators.
	struct output_iterator_tag { };
	/// Forward iterators support a superset of input iterator operations.
	struct forward_iterator_tag : public input_iterator_tag { };
	/// Bidirectional iterators support a superset of forward iterator
	/// operations.
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	/// Random-access iterators support a superset of bidirectional
	/// iterator operations.
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	/**
	** traits class for iterators
	**
	** simplifies nested typedefs
	*/
	template <typename Iterator>
	struct iterator_traits {
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	/**
	** partial specialization for pointer types
	*/
	template <typename ItPointer>
	struct iterator_traits<ItPointer*> {
		typedef ItPointer						value_type;
		typedef ItPointer*						pointer;
		typedef ItPointer&						reference;
		typedef std::ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	/**
	** partial specialization for const pointer types
	*/
	template <typename ItPointer>
	struct iterator_traits<const ItPointer*> {
		typedef ItPointer						value_type;
		typedef const ItPointer*				pointer;
		typedef const ItPointer&				reference;
		typedef std::ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag	iterator_category;
	};


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
				_data = _alloc.allocate(_capacity, NULL);
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(_data + i, val);
				}
			}

			// NEEDS REVISION
			~vector() {
				for (size_type i = 0; i < _size; i++) {
					_alloc.destroy(_data + i);
				}
				_alloc.deallocate(_data, _capacity);
			}

			// NEEDS REVISION
			vector(const vector& x) {
				std::cout << "COPY OP" << std::endl;
				*this = x;
			}

			// NEEDS REVISION
			vector &operator=(const vector &x) {
				std::cout << "ASSIGNEMNT OP" << std::endl;
				if (this != &x) {
					_data = x._data;
					_alloc = x._alloc;
					_size = x._size;
					_capacity = x._capacity;
				}
				return *this;
			}

			// template <class InputIterator>
			// void assign(InputIterator first, InputIterator last) {
				
			// }

			// void assign(size_type n, const value_type& val) {
				
			// }

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
				size_type range = size_type(offset) + n;
				size_type new_size = _size + n;
				
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
					_alloc.construct(_data + i, *(temp_data + i - range + offset));
				}
				for (size_type i = offset; i < range; i++) {
					_alloc.construct(_data + i, val);
				}
				
				for (size_type i = 0; i < _size; i++) {
					temp_alloc.destroy(temp_data + i);
				}
				temp_alloc.deallocate(temp_data, _size);
				// (void)val;
				_size += n;
				// return position;
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
				size_type temp_size = _size;
				size_type temp_capacity = _capacity;

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
