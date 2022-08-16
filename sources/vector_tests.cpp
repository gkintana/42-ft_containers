/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:05:25 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/16 22:49:19 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include <vector.hpp>

int main() {
	std::vector<int> v;

	v.push_back(2);
	std::cout << v.size() << std::endl << std::endl;

	ft::vector<int> v2;

	// v.push_back(2);
	std::cout << std::boolalpha << v2.empty() << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
}