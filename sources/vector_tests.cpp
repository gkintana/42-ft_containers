/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:05:25 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/17 22:49:03 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include <vector.hpp>

using namespace std;

int main() {
	vector<int> v;

	v.push_back(2);
	// cout << v.size() << endl;

	// cout << "Element Access Tests" << endl;
	// try {
	// 	cout << "\tat(42) = "<< v.at(42) << endl;
	// } catch (exception &e) {
	// 	cerr << e.what() << endl;
	// }
	// cout << "\toperator[-42] = "<< v[-42] << endl;
	// cout << "\toperator[42] = "<< v[42] << endl;
	// // cout << "\tfront() = " << v.front() << endl;
	// cout << "\tback() = " << v.back() << endl;
	// cout << v[123212312231239] << endl;


	ft::vector<int> v2(5, 20);

	cout << boolalpha << v2.empty() << endl;
	cout << v2.capacity() << endl;
	cout << v2[3] << endl;

	/*-----------------------------------------------------------------------*/
	cout << "\nPop Back Tests" << endl;
	vector<int> std_vPop(5, 42);
	ft::vector<int> ft_vPop(5, 42);
	
	cout << "std\tft\n-----\t-----" << endl;
	for (size_t i = 0; std_vPop.size(); i++) {
		cout << std_vPop.size();
		std_vPop.pop_back();
		cout << "\t" << ft_vPop.size() << endl;
		ft_vPop.pop_back();
	}
	for (size_t i = 0; i < 3; i++) {
		cout << std_vPop.size();
		std_vPop.pop_back();
		cout << "\t" << ft_vPop.size() << endl;
		ft_vPop.pop_back();
	}
	/*-----------------------------------------------------------------------*/

}
