/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:05:25 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/17 10:35:08 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include <vector.hpp>

int main() {
	std::vector<int> v;

	v.push_back(2);
	std::cout << v.size() << std::endl;

	std::cout << "Element Access Tests" << std::endl;
	try {
		std::cout << "\tat(42) = "<< v.at(42) << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\toperator[-42] = "<< v[-42] << std::endl;
	std::cout << "\toperator[42] = "<< v[42] << std::endl;
	// std::cout << "\tfront() = " << v.front() << std::endl;
	std::cout << "\tback() = " << v.back() << std::endl;


	// ft::vector<int> v2;

	// // v.push_back(2);
	// std::cout << std::boolalpha << v2.empty() << std::endl;
	// std::cout << v2.size() << std::endl;
	// std::cout << v2.capacity() << std::endl;
	// std::cout << v2[42] << std::endl;
}
