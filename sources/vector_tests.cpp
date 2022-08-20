/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:05:25 by gkintana          #+#    #+#             */
/*   Updated: 2022/08/21 00:28:27 by gkintana         ###   ########.fr       */
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


	vector<int> v(5, 20);

	cout << boolalpha << v.empty() << endl
		 << v.capacity() << endl
		 << v.max_size() << endl
		 << v[3] << endl;

	ft::vector<int> v2(5, 20);

	cout << boolalpha << v2.empty() << endl
		 << v2.capacity() << endl
		 << v2.max_size() << endl
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

	{
		vector<int> std_iter(3, 5);
		cout << "std.begin() = " << *std_iter.begin() << endl;
		// cout << "std.end() = " << *std_iter.end() << endl;

		ft::vector<int> ft_iter(3, 5);
		cout << "ft.begin() = " << *ft_iter.begin() << endl;
		// cout << "ft.end() = " << *ft_iter.end() << endl;
	}

	/*-----------------------------------------------------------------------*/

	cout << GREEN "\nIterator Tests" DEFAULT << endl;

	{
		vector<int> std_iter(3, 5);
		vector<int> ::iterator std;

		for (std = std_iter.begin(); std != std_iter.end(); std++) {
			cout << *std << endl;
		}
		// cout << *std << endl;

		ft::vector<int> ft_iter(3, 5);
		ft::vector<int> ::iterator ft;

		for (ft = ft_iter.begin(); ft != ft_iter.end(); ft++) {
			cout << *ft << endl;
		}
		// cout << *ft << endl;
	}
	
	/*-----------------------------------------------------------------------*/

	cout << GREEN "\nClear Test" DEFAULT << endl;

	vector<int> std_clear(3, 42);
	vector<int> ::iterator std_iter;
	cout << "std.size() = " << std_clear.size() << endl
		 << "std.capacity() = " << std_clear.capacity() << endl
		 << YELLOW "Contents of STD before ::clear()" DEFAULT << endl;
	for (std_iter = std_clear.begin(); std_iter != std_clear.end(); std_iter++) {
		cout << *std_iter << endl;
	}
	cout << "std.clear()" << endl;
	std_clear.clear();
	cout << "std.size() = " << std_clear.size() << endl
		 << YELLOW "Contents of STD after ::clear()" DEFAULT << endl;
	for (std_iter = std_clear.begin(); std_iter != std_clear.end(); std_iter++) {
		cout << *std_iter << endl;
	}
	
	ft::vector<int> ft_clear(3, 42);
	ft::vector<int> ::iterator ft_iter;
	cout << "\nft.size() = " << ft_clear.size() << endl
		 << "ft.capacity() = " << ft_clear.capacity() << endl
		 << YELLOW "Contents of FT before ::clear()" DEFAULT << endl;
	for (ft_iter = ft_clear.begin(); ft_iter != ft_clear.end(); ft_iter++) {
		cout << *ft_iter << endl;
	}
	cout << "ft.clear()" << endl;
	ft_clear.clear();
	cout << "ft.size() = " << ft_clear.size() << endl
		 << YELLOW "Contents of FT after ::clear()" DEFAULT << endl;
	for (ft_iter = ft_clear.begin(); ft_iter != ft_clear.end(); ft_iter++) {
		cout << *ft_iter << endl;
	}
	

	/*-----------------------------------------------------------------------*/

	cout << GREEN "\nSwap Test" DEFAULT << endl;

	std::vector<int> std_sample1(3, 3);
	std::vector<int> std_sample2(5, 5);
	
	std::cout << "std_sample1 contents before ::swap()" << endl;
	for (std::vector<int>::iterator i = std_sample1.begin(); i != std_sample1.end(); i++) {
		cout << *i << endl;
	}
	std::cout << "std_sample2 contents before ::swap()" << endl;
	for (std::vector<int>::iterator i = std_sample2.begin(); i != std_sample2.end(); i++) {
		cout << *i << endl;
	}
	std_sample1.swap(std_sample2);\
	std::cout << "std_sample1 contents after ::swap()" << endl;
	for (std::vector<int>::iterator i = std_sample1.begin(); i != std_sample1.end(); i++) {
		cout << *i << endl;
	}
	std::cout << "std_sample2 contents after ::swap()" << endl;
	for (std::vector<int>::iterator i = std_sample2.begin(); i != std_sample2.end(); i++) {
		cout << *i << endl;
	}
	
	
	ft::vector<int> ft_sample1(3, 3);
	ft::vector<int> ft_sample2(5, 5);
	
	std::cout << "\bft_sample1 contents before ::swap()" << endl;
	for (ft::vector<int>::iterator i = ft_sample1.begin(); i != ft_sample1.end(); i++) {
		cout << *i << endl;
	}
	std::cout << "ft_sample2 contents before ::swap()" << endl;
	for (ft::vector<int>::iterator i = ft_sample2.begin(); i != ft_sample2.end(); i++) {
		cout << *i << endl;
	}
	ft_sample1.swap(ft_sample2);
	std::cout << "\bft_sample1 contents after ::swap()" << endl;
	for (ft::vector<int>::iterator i = ft_sample1.begin(); i != ft_sample1.end(); i++) {
		cout << *i << endl;
	}
	std::cout << "ft_sample2 contents after ::swap()" << endl;
	for (ft::vector<int>::iterator i = ft_sample2.begin(); i != ft_sample2.end(); i++) {
		cout << *i << endl;
	}

	return 0;
}
