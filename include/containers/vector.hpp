/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:02:07 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/20 11:35:33 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
#include "type_traits.hpp"
#include "iterator_traits.hpp"
#include "iterator_validity.hpp"
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.hpp"

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class vector {

	public:
		typedef T                                           value_type;
		typedef Allocator                                   allocator_type;
		typedef typename allocator_type::reference          reference;
		typedef typename allocator_type::const_reference    const_reference;
		typedef typename allocator_type::size_type          size_type;
		typedef typename allocator_type::difference_type    difference_type;
		typedef typename allocator_type::pointer            pointer;
		typedef typename allocator_type::const_pointer      const_pointer;
		typedef ft::vector_iterator<value_type>             iterator;
		typedef ft::vector_iterator<const value_type>       const_iterator;
		typedef ft::reverse_iterator<iterator>              reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

		/**
		** Member Functions
		**
		** constructor      constructs the vector
		** destructor       destructs the vector
		** operator=        assigns values to the container
		** assign           assigns values to the container
		** get_allocator    returns the associated allocator
		*/

		explicit vector(const allocator_type &alloc = allocator_type()) : _data(0),
		                                                                  _alloc(alloc),
		                                                                  _size(0),
		                                                                  _capacity(0) {}

		explicit vector(size_type n, const value_type &val = value_type(),
		                const allocator_type &alloc = allocator_type()) : _data(0),
		                                                                  _alloc(alloc),
		                                                                  _size(n),
		                                                                  _capacity(n) {
			_data = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++) {
				_alloc.construct(_data + i, val);
			}
		}

		template <class Iterator>
		vector(Iterator first, Iterator last, const allocator_type& alloc = allocator_type(),
		       typename ft::enable_if<!ft::is_integral<Iterator>::value, Iterator>::type* = 0) : _data(0),
		                                                                                         _alloc(alloc),
		                                                                                         _size(0),
		                                                                                         _capacity(0) {
			ft::check_range(first, last);
			difference_type range = 0;
			for (Iterator temp = first; temp != last; temp++) {
				range++;
			}

			_size = _capacity = static_cast<size_type>(range);
			_data = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++) {
				_alloc.construct(_data + i, *first++);
			}
		}

		vector(const vector& x) : _data(0),
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

		~vector() {
			this->clear();
			_alloc.deallocate(_data, _capacity);
			_capacity = 0;
		}

		template <class Iterator>
		void assign(Iterator first, Iterator last,
		            typename ft::enable_if<!ft::is_integral<Iterator>::value, Iterator>::type* = 0) {
			ft::check_range(first, last);
			difference_type range = 0;
			for (Iterator temp = first; temp != last; temp++) {
				range++;
			}

			if (static_cast<size_type>(range) > _capacity) {
				this->reserve(range);
			}
			Iterator iter = first;
			_size = static_cast<size_type>(range);
			for (size_type i = 0; i < _size; i++) {
				_alloc.construct(_data + i, *iter++);
			}
		}

		void assign(size_type n, const value_type& value) {
			this->clear();
			if (n > 0) {
				if (n > _capacity) {
					this->reserve(n);
				}
				_size = n;
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(_data + i, value);
				}
			}
		}

		allocator_type get_allocator() const {
			return _alloc;
		}

		/**
		** Element Access
		**
		** at            access specified element with bounds checking
		** operator[]    access specified element
		** front         access the first element
		** back          access the last element
		** data          direct access to the underlying array
		*/

		reference at(size_type pos) {
			if (pos >= _size) {
				throw std::out_of_range("ft::vector::at");
			}
			return *(_data + pos);
		}

		const_reference at(size_type pos) const {
			if (pos >= _size) {
				throw std::out_of_range("ft::vector::at");
			}
			return *(_data + pos);
		}

		reference operator[](size_type pos) {
			return *(_data + pos);
		}

		const_reference operator[](size_type pos) const {
			return *(_data + pos);
		}

		reference front() {
			return *this->begin();
		}

		const_reference front() const {
			return *this->begin();
		}

		reference back() {
			return *(this->end() - 1);
		}

		const_reference back() const {
			return *(this->end() - 1);
		}

		T* data() {
			return _data;
		}

		const T* data() const {
			return _data;
		}

		/**
		** Iterators
		**
		** begin     returns an iterator to the beginning
		** end       returns an iterator to the end
		** rbegin    returns a reverse iterator to the beginning
		** rend      returns a reverse iterator to the end
		*/

		iterator begin() {
			return iterator(_data);
		}

		const_iterator begin() const {
			return const_iterator(_data);
		}

		iterator end() {
			return iterator(_data + _size);
		}

		const_iterator end() const {
			return const_iterator(_data + _size);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(this->end());
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(this->end());
		}

		reverse_iterator rend() {
			return reverse_iterator(this->begin());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(this->begin());
		}

		/**
		** Capacity
		**
		** empty       checks whether the container is empty
		** size        returns the number of elements
		** max_size    returns the maximum possible number of elements
		** capacity    returns the number of elements that can be held in currently allocated storage
		** reserve     reserves storage
		*/

		bool empty() const {
			return _size == 0;
		}

		size_type size() const {
			return _size;
		}

		size_type max_size() const {
			return _alloc.max_size();
		}

		size_type capacity() const {
			return _capacity;
		}

		void reserve(size_type new_cap) {
			if (new_cap > this->max_size()) {
				throw std::length_error("ft::vector::reserve");
			} else if (_capacity < new_cap) {
				allocator_type temp_alloc;
				pointer temp_data = temp_alloc.allocate(new_cap);
				size_type temp_size = _size;

				for (size_type i = 0; i < _size; i++) {
					temp_alloc.construct(temp_data + i, *(_data + i));
				}
				this->~vector();

				_data = temp_data;
				_alloc = temp_alloc;
				_size = temp_size;
				_capacity = new_cap;
			}
		}

		/**
		** Modifiers
		**
		** clear        clears the contents
		** insert       inserts elements
		** erase        erases elements
		** push_back    adds an element to the end
		** pop_back     removes the last element
		** resize       changes the number of elements stored
		** swap         swaps the contents
		*/

		void clear() {
			for (size_type i = 0; i < _size; i++) {
				_alloc.destroy(_data + i);
			}
			_size = 0;
		}

		iterator insert(iterator position, const value_type &val) {
			difference_type offset = position - this->begin();
			if (offset >= 0) {
				if (!_capacity) {
					this->reserve(1);
				} else if (_size == _capacity) {
					this->reserve(_capacity * 2);
				}

				if (static_cast<size_type>(offset) > _size) {
					_alloc.construct(_data + _size, *(_data + _size - 1));
				} else {
					for (size_type i = _size; i > static_cast<size_type>(offset); i--) {
						_alloc.construct(_data + i, *(_data + i - 1));
						_alloc.destroy(_data + i - 1);
					}
					_alloc.construct(_data + size_type(offset), val);
				}
			}
			_size++;
			return position;
		}

		void insert(iterator position, size_type n, const value_type &val) {
			difference_type offset = position - this->begin();
			size_type range = static_cast<size_type>(offset) + n,
			          old_value = static_cast<size_type>(offset) - static_cast<size_type>(range),
			          new_size = _size + n;

			if (_size + n >= _capacity) {
				this->reserve(std::max(_capacity * 2, _size + n));
			}

			allocator_type temp_alloc;
			pointer temp_data = temp_alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++) {
				temp_alloc.construct(temp_data + i, *(_data + i));
			}

			for (size_type i = range; i < new_size; i++) {
				if (i < _size)
					_alloc.destroy(_data + i);
				_alloc.construct(_data + i, *(temp_data + i + old_value));
			}
			for (size_type i = offset; i < range; i++) {
				if (i < _size)
					_alloc.destroy(_data + i);
				_alloc.construct(_data + i, val);
			}

			for (size_type i = 0; i < _size; i++) {
				temp_alloc.destroy(temp_data + i);
			}
			temp_alloc.deallocate(temp_data, _size);
			_size += n;
		}

		template <class Iterator>
		void insert(iterator position, Iterator first, Iterator last,
		            typename ft::enable_if<!ft::is_integral<Iterator>::value, Iterator>::type* = 0) {
			difference_type offset = position - this->begin(),
			                range = offset;
			size_type n = 0;
			for (Iterator temp = first; temp != last; temp++) {
				range++;
				n++;
			}
			size_type old_value =static_cast<size_type>(offset) - static_cast<size_type>(range),
			          new_size = _size + n;
			if (_size + n >= _capacity) {
				this->reserve(std::max(_capacity * 2, _size + n));
			}

			allocator_type temp_alloc;
			pointer temp_data = temp_alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++) {
				temp_alloc.construct(temp_data + i, *(_data + i));
			}

			for (size_type i = static_cast<size_type>(range); i < new_size; i++) {
				if (i < _size)
					_alloc.destroy(_data + i);
				_alloc.construct(_data + i, *(temp_data + i + old_value));
			}
			for (size_type i = static_cast<size_type>(offset); i < static_cast<size_type>(range); i++) {
				if (i < _size)
					_alloc.destroy(_data + i);
				_alloc.construct(_data + i, *first++);
			}

			for (size_type i = 0; i < _size; i++) {
				temp_alloc.destroy(temp_data + i);
			}
			temp_alloc.deallocate(temp_data, _size);
			_size += n;
		}

		iterator erase(iterator pos) {
			for (iterator i = pos; i != this->end() - 1; i++) {
				*i = *(i + 1);
			}
			_alloc.destroy(_data + _size - 1);
			_size--;
			return pos;
		}

		iterator erase(iterator first, iterator last) {
			size_type start = first - this->begin(),
			          end = last - this->begin(),
			          range = last - first,
			          pos = 0;

			for (size_type i = start; end + pos < _size; i++) {
				_data[i] = _data[end + pos++];
			}
			for (size_type i = 0; i < range; i++) {
				_alloc.destroy(_data + --_size);
			}
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

		void pop_back()	{
			_alloc.destroy(&_data[_size - 1]);
			_size--;
		}

		void resize(size_type new_size, value_type value = value_type()) {
			if (new_size > this->max_size()) {
				throw std::length_error("ft::vector::resize");
			} else if (new_size > _capacity) {
				this->reserve(std::max(_capacity * 2, new_size));
			}

			for (size_type i = _size; i < new_size; i++) {
				_alloc.construct(_data + i, value);
			}
			for (size_type i = _size; i > new_size; i--) {
				_alloc.destroy(_data + i - 1);
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
		pointer           _data;
		allocator_type    _alloc;
		size_type         _size;
		size_type         _capacity;
};

/**
** Non-Member Functions
*/

template <class T, class Allocator>
bool operator==(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
	if (lhs.size() != rhs.size()) {
		return false;
	}

	for (size_t i = 0; i < lhs.size(); i++) {
		if (lhs.at(i) != rhs.at(i)) {
			return false;
		}
	}
	return true;
}

template <class T, class Allocator>
bool operator!=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
	return !(lhs == rhs);
}

template <class T, class Allocator>
bool operator<(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Allocator>
bool operator<=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
	return !(rhs < lhs);
}

template <class T, class Allocator>
bool operator>(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
	return rhs < lhs;
}

template <class T, class Allocator>
bool operator>=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
	return !(lhs < rhs);
}

template <class T, class Allocator>
void swap(ft::vector<T, Allocator> &lhs, ft::vector<T, Allocator> &rhs) {
	lhs.swap(rhs);
}

}    // namespace ft

#endif    // VECTOR_HPP
