/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:36:50 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/28 22:31:31 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {
	
template <bool, typename T>
struct enable_if {};

template <typename T>
struct enable_if<true, T> { typedef T type; };

template <typename>
struct is_integral { static const bool value = false; };

template <>
struct is_integral<bool> { static const bool value = true; };

template <>
struct is_integral<char> { static const bool value = true; };

template <>
struct is_integral<signed char> { static const bool value = true; };

template <>
struct is_integral<unsigned char> { static const bool value = true; };

template <>
struct is_integral<wchar_t> { static const bool value = true; };

template <>
struct is_integral<short> { static const bool value = true; };

template <>
struct is_integral<unsigned short> { static const bool value = true; };

template <>
struct is_integral<int> { static const bool value = true; };

template <>
struct is_integral<unsigned int> { static const bool value = true; };

template <>
struct is_integral<long> { static const bool value = true; };

template <>
struct is_integral<unsigned long> { static const bool value = true; };

template <>
struct is_integral<long long> { static const bool value = true; };

template <>
struct is_integral<unsigned long long> { static const bool value = true; };

}    // namespace ft

#endif    // TYPE_TRAITS_HPP
