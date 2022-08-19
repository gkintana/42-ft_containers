/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:05:25 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/19 09:49:53 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include <vector.hpp>

# define DEFAULT		"\033[0m"
# define RED			"\033[1;31m"
# define GREEN			"\033[1;4;32m"
# define YELLOW			"\033[3;33m"

using namespace std;

int main() {
	// vector<int> v;

	// v.push_back(2);
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


	ft::vector<int> v(5, 20);

	cout << boolalpha << v.empty() << endl
		 << v.capacity() << endl
		 << v[3] << endl;

	ft::vector<int> v2(5, 20);

	cout << boolalpha << v2.empty() << endl
		 << v2.capacity() << endl
		 << v2[3] << endl;

	/*-----------------------------------------------------------------------*/
	
	cout << GREEN "\n::Pop_Back() Tests" DEFAULT << endl;

	vector<int> std_pop(10, 42);
	ft::vector<int> ft_pop(10, 42);

	cout << "std\tft\n-----\t-----" << endl;
	for (size_t i = 0; std_pop.size(); i++) {
		cout << std_pop.size();
		std_pop.pop_back();
		cout << "\t" << ft_pop.size() << endl;
		ft_pop.pop_back();
	}
	// for (size_t i = 0; i < 3; i++) {
	// 	cout << std_pop.size();
	// 	std_pop.pop_back();
	// 	cout << "\t" << ft_pop.size() << endl;
	// 	ft_pop.pop_back();
	// }

	/*-----------------------------------------------------------------------*/
	
	cout << GREEN "\n::At() Tests" DEFAULT << endl;
	
	cout << YELLOW "Bounds Checking" DEFAULT << endl;
	{
		vector<int> std_at;
		ft::vector<int> ft_at;

		try {
			cout << std_at.at(42) << endl;	// terminate called after throwing an instance of 'std::out_of_range'
		} catch (exception &e) {
			cerr << e.what() << endl;
		}
		try {
			cout << ft_at.at(42) << endl;
		} catch (exception &e) {
			cerr << e.what() << endl;
		}
	}

	cout << YELLOW "Standard Tests" DEFAULT << endl;
	{
		vector<int> std_at(5, 42);
		ft::vector<int> ft_at(5, 42);

		cout << "at(3)" << endl;
		try {
			cout << "std::vector = " << std_at.at(3) << endl;
		} catch (exception &e) {
			cerr << e.what() << endl;
		}
		try {
			cout << "ft::vector = " << ft_at.at(3) << endl;
		} catch (exception &e) {
			cerr << e.what() << endl;
		}

		cout << "at(0)" << endl;
		try {
			cout << "std::vector = " << std_at.at(0) << endl;
		} catch (exception &e) {
			cerr << e.what() << endl;
		}
		try {
			cout << "ft::vector = " << ft_at.at(0) << endl;
		} catch (exception &e) {
			cerr << e.what() << endl;
		}

		cout << "at(5)" << endl;
		try {
			cout << "std::vector = " << std_at.at(5) << endl;
		} catch (exception &e) {
			cerr << e.what() << endl;
		}
		try {
			cout << "ft::vector = " << ft_at.at(5) << endl;
		} catch (exception &e) {
			cerr << e.what() << endl;
		}
	}

	/*-----------------------------------------------------------------------*/
	// ft::vector<int> vOrig(3, 20);
	// ft::vector<int> vCopy = vOrig;

	// cout << vCopy.size() << endl;
	// cout << vCopy.capacity() << endl;
	// cout << vCopy[2] << endl;
	/*-----------------------------------------------------------------------*/

	cout << GREEN "\nIterator ::begin() & ::end() Tests" DEFAULT << endl;

	vector<int> std_iter(3, 5);
	cout << "std.begin() = " << *std_iter.begin() << endl;
	cout << "std.end() = " << *std_iter.end() << endl;

	ft::vector<int> ft_iter(3, 5);
	cout << "ft.begin() = " << *ft_iter.begin() << endl;
	cout << "ft.end() = " << *ft_iter.end() << endl;

	return 0;
}
