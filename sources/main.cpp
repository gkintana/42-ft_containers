/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:05:25 by gkintana          #+#    #+#             */
/*   Updated: 2022/11/26 23:41:09 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>

#include <vector.hpp>
#include <stack.hpp>

#include "pair.hpp"
#include "avl_tree.hpp"
#include "map.hpp"

#define DEFAULT		"\033[0m"
#define RED			"\033[1;31m"
#define GREEN		"\033[1;4;32m"
#define YELLOW		"\033[0;33m"
#define CYAN		"\033[0;36m"

// using namespace std;

template <typename T>
void pushValues(NAMESPACE::vector<T> &container, size_t size) {
	for (size_t i = 0; i < size; i++) {
		container.push_back(i + 1);
	}
}

template <typename T>
void printInfo(NAMESPACE::vector<T> &container, bool printContent) {
	if (printContent) {
		std::cout << CYAN "vector contents: " DEFAULT;
		for (size_t i = 0; i < container.size(); i++) {
			std::cout << container[i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "size = " << container.size() << std::endl
              << "capacity = " << container.capacity() << std::endl;
}

int main() {
	// std::cout << GREEN "vector construction tests" DEFAULT << std::endl;
	// {
	// 	NAMESPACE::vector<int> v1;
	// 	printInfo(v1, true);
	// 	std::cout << "empty = " << std::boolalpha << v1.empty() << std::endl
	// 		      << "max size = " << v1.max_size() << std::endl;

	// 	NAMESPACE::vector<int> v2(5, 42);
	// 	printInfo(v2, true);
	// 	std::cout << "empty = " << std::boolalpha << v2.empty() << std::endl
	// 			  << "max size = " << v2.max_size() << std::endl;
	// }

	// /*-----------------------------------------------------------------------*/

	// std::cout << GREEN "vector construction tests" DEFAULT << std::endl;
	// {
	// 	NAMESPACE::vector<int> vec(5, 5);
	// 	printInfo(vec, true);

	// 	NAMESPACE::vector<int> vec_copy = vec;
	// 	printInfo(vec_copy, true);

	// 	NAMESPACE::vector<int> vec_copy2;
	// 	printInfo(vec_copy2, true);
	// 	vec_copy2 = vec;
	// 	printInfo(vec_copy2, true);
	// 	vec_copy2 = vec_copy;
	// 	printInfo(vec_copy2, true);

	// 	NAMESPACE::vector<int> vec_copy3(vec_copy2);
	// 	printInfo(vec_copy3, true);
	// 	pushValues(vec_copy3, 5);

	// 	vec_copy2 = vec_copy3;
	// 	printInfo(vec_copy2, true);
	// }

	// /*-----------------------------------------------------------------------*/
	
	// std::cout << GREEN "vector::push_back tests" DEFAULT << std::endl;
	// {
	// 	NAMESPACE::vector<int> test_push_back;

	// 	printInfo(test_push_back, true);
	// 	pushValues(test_push_back, 5);
	// 	printInfo(test_push_back, true);
	// }

	// /*-----------------------------------------------------------------------*/

	// std::cout << GREEN "vector::pop_back tests" DEFAULT << std::endl;
	// {
	// 	NAMESPACE::vector<int> test_pop_back;

	// 	pushValues(test_pop_back, 5);
	// 	printInfo(test_pop_back, true);
	// 	for (size_t i = test_pop_back.size(); i > 0; i--) {
	// 		test_pop_back.pop_back();
	// 	}
	// 	printInfo(test_pop_back, true);
	// }

	// /*-----------------------------------------------------------------------*/

	// std::cout << GREEN "vector::at tests" DEFAULT << std::endl;
	// {
	// 	NAMESPACE::vector<int> test_at;

	// 	pushValues(test_at, 9);
	// 	printInfo(test_at, true);
	// 	std::cout << YELLOW "printing values at each position" DEFAULT << std::endl;
	// 	for (size_t i = 0; i < test_at.size(); i++) {
	// 		std::cout << "at(" << i << ") = " << test_at.at(i) << std::endl;
	// 	}

	// 	try {
			
	// 	} catch (std::exception &e) {
			
	// 	}
	// }
	
	// /*-----------------------------------------------------------------------*/

	// std::cout << GREEN "vector::insert tests" DEFAULT << std::endl;
	// {
	// 	NAMESPACE::vector<int> insert_int;

	// 	// pushValues(insert_int, 6);
	// 	pushValues(insert_int, 16);
	// 	// pushValues(insert_int, 17);
	// 	printInfo(insert_int, true);
	// 	insert_int.insert(insert_int.begin() + 3, 30);
	// 	printInfo(insert_int, true);


	// 	NAMESPACE::vector<std::string> insert_str;

	// 	insert_str.push_back("Hello");
	// 	insert_str.push_back("World");
	// 	insert_str.push_back("!");
	// 	printInfo(insert_str, true);
	// 	// insert_str.insert(insert_str.begin() - 1, "QWEWQE");
	// 	insert_str.insert(insert_str.begin() + 3, "QWEWQE");
	// 	// insert_str.insert(insert_str.begin() + 100, "QWEWQE");
	// 	printInfo(insert_str, true);
	// }

	// /*-----------------------------------------------------------------------*/

	// std::cout << GREEN "vector::insert range tests" DEFAULT << std::endl;
	// {
	// 	NAMESPACE::vector<int> insert_int;

	// 	pushValues(insert_int, 8);
	// 	// pushValues(insert_int, 6);
	// 	// pushValues(insert_int, 16);
	// 	// pushValues(insert_int, 17);
	// 	printInfo(insert_int, true);
	// 	insert_int.insert(insert_int.begin() + 3, 3, 42);
	// 	// insert_int.insert(insert_int.begin() + 3, 12, 42);
	// 	// insert_int.insert(insert_int.begin() + 3, 1, 42);
	// 	// insert_int.insert(insert_int.begin() + 3, 0, 42);
	// 	printInfo(insert_int, true);
	// }

	// /*-----------------------------------------------------------------------*/

	// std::cout << GREEN "vector::assign tests" DEFAULT << std::endl;
	// {
	// 	NAMESPACE::vector<int> vec(10, 10);
	// 	printInfo(vec, true);

	// 	vec.assign(10, 2);
	// 	vec.assign(5, 2);
	// 	printInfo(vec, true);
	// }

	// /*-----------------------------------------------------------------------*/

	// std::cout << GREEN "vector::assign iterator tests" DEFAULT << std::endl;
	// {
	// 	NAMESPACE::vector<int> vec(5, 5);
	// 	printInfo(vec, true);
	// 	NAMESPACE::vector<int> vec_copy(vec);

	// 	NAMESPACE::vector<int> vec2;
	// 	pushValues(vec2, 10);
	// 	printInfo(vec2, true);

	// 	NAMESPACE::vector<int>::iterator first = vec2.begin();
	// 	NAMESPACE::vector<int>::iterator last = vec2.end();
	// 	vec2.assign(first, last);
	// 	printInfo(vec2, true);

	// 	// first = vec_copy.begin() + 4;
	// 	// last = vec_copy.end() - 2;

	// 	first = vec_copy.begin() + 5;
	// 	last = vec_copy.end() - 5;
	// 	try {
	// 		vec.assign(first, last);
	// 		printInfo(vec, true);
	// 	} catch (std::exception &e) {
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }

	// /*-----------------------------------------------------------------------*/

	// std::cout << GREEN "vector iterator constructor test" DEFAULT << std::endl;
	// {
	// 	// constructors used in the same order as described above:
	// 	// NAMESPACE::vector<int> first;                                // empty vector of ints
	// 	NAMESPACE::vector<int> second (4,100);                       // four ints with value 100
	// 	NAMESPACE::vector<int> third (second.begin(),second.end());  // iterating through second
	// 	printInfo(third, true);

	// 	// NAMESPACE::vector<int> fourth (third);                       // a copy of third

	// 	// // the iterator constructor can also be used to construct from arrays:
	// 	// int myints[] = {16,2,77,29};
	// 	// NAMESPACE::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	// 	// std::cout << "The contents of fifth are:";
	// 	// for (NAMESPACE::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	// 	// 	std::cout << ' ' << *it;
	// 	// std::cout << '\n';
	// }

	// /*-----------------------------------------------------------------------*/

	// std::cout << GREEN "vector reverse_iterator test" DEFAULT << std::endl;
	// {
	// 	NAMESPACE::vector<int> vec;
	// 	pushValues(vec, 20);

	// 	std::cout << "rbegin value = " << *vec.rbegin() << std::endl;
	// 	std::cout << "rend value = " << *(vec.rend() - 1)<< std::endl;

	// 	for (NAMESPACE::vector<int>::reverse_iterator i = vec.rbegin(); i != vec.rend(); i++) {
	// 		std::cout << *i << " ";
	// 	}
	// 	std::cout << std::endl;
	// 	for (NAMESPACE::vector<int>::reverse_iterator i = vec.rend() - 1; i != vec.rbegin() - 1; i--) {
	// 		std::cout << *i << " ";
	// 	}
	// 	std::cout << std::endl;



	// 	NAMESPACE::vector<std::string> vec2;
	// 	vec2.push_back("Hello");
	// 	vec2.push_back("World");
	// 	vec2.push_back("!");
	// 	vec2.push_back("Hello");
	// 	vec2.push_back("World");
	// 	vec2.push_back("!");
	// 	for (NAMESPACE::vector<std::string>::reverse_iterator i = vec2.rend() - 1; i > vec2.rbegin() - 1; i--) {
	// 		std::cout << *i << " ";
	// 	}
	// 	std::cout << std::endl;
	// 	for (NAMESPACE::vector<std::string>::iterator i = vec2.begin(); i != vec2.end(); i++) {
	// 		std::cout << *i << " ";
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << vec2.size() << std::endl;
	// 	std::cout << vec2.capacity() << std::endl;
	// }

	// {
	// 	NAMESPACE::vector<char> ft_vec;
	// 	// std::vector<char> std_vec;
	// 	// testVectors(ft_vec, std_vec);
	// 	printInfo(ft_vec, true);
	// 	std::cout << ft_vec.max_size() << std::endl;
		
	// }


	// NAMESPACE::vector<int> vec(5, 10);
	// // std::cout << *vec.begin() << std::endl;
	// // std::cout << *(vec.end() - 1) << std::endl;

	// // std::cout << *(vec.rend() - 1) << std::endl;
	// // std::cout << *vec.rbegin() << std::endl;
	

	// // NAMESPACE::vector<int> vec2(vec.begin(), vec.end());
	// try {
	// 	NAMESPACE::vector<int> vec3(vec.rend(), vec.rbegin());
	// } catch (std::exception &e) {}


	// // simple pair test
	// NAMESPACE::pair <std::string,double> product1;                     // default constructor
	// NAMESPACE::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
	// NAMESPACE::pair <std::string,double> product3 (product2);          // copy constructor

	// product1 = NAMESPACE::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

	// product2.first = "shoes";                  // the type of first is string
	// product2.second = 39.90;                   // the type of second is double

	// std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
	// std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
	// std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';


	// // simple stack test
	// NAMESPACE::stack<int> s;

	// std::cout << "stack::empty() = " << std::boolalpha << s.empty() << std::endl;
	// std::cout << "stack::top() = " << s.top() << std::endl;
	// for(size_t i = 0; i < 100; i++) {
	// 	if (i && !(i % 20)) {
	// 		std::cout << "stack::top() = " << s.top() << std::endl;
	// 	}
	// 	s.push(i + 1);
	// }
	// std::cout << "stack::top() = " << s.top() << std::endl;
	// std::cout << "stack::empty() = " << std::boolalpha << s.empty() << std::endl;
	// std::cout << "stack::size() = " << s.size() << std::endl;

	// for(size_t i = 0; i < 100; i++) {
	// 	s.pop();
	// }
	// std::cout << "stack::size() = " << s.size() << std::endl;
	// std::cout << "stack::empty() = " << std::boolalpha << s.empty() << std::endl;

	ft::avl_tree<int, int> avl;
	ft::avl_tree<int, int>::pointer root = NULL;
	root = avl.insertNode(root, ft::pair<int, int>(2, 20));
	root = avl.insertNode(root, ft::pair<int, int>(1, 10));
	root = avl.insertNode(root, ft::pair<int, int>(3, 30));
	root = avl.insertNode(root, ft::pair<int, int>(6, 25));
	root = avl.insertNode(root, ft::pair<int, int>(5, 50));
	root = avl.insertNode(root, ft::pair<int, int>(4, 40));

	// root = avl.insertNode(root, ft::pair<int, int>(5, 5));
	// root = avl.insertNode(root, ft::pair<int, int>(3, 3));
	// root = avl.insertNode(root, ft::pair<int, int>(7, 7));
	// root = avl.insertNode(root, ft::pair<int, int>(10, 10));
	// root = avl.insertNode(root, ft::pair<int, int>(12, 12));
	// root = avl.deleteNode(root, ft::pair<int, int>(3, 3));
	// root = avl.insertNode(root, ft::pair<int, int>(11, 11));
	// root = avl.insertNode(root, ft::pair<int, int>(13, 13));

	// ft::avl_tree<int, int>::iterator it = avl.begin();
	// for (size_t i = 0; i < avl.size(); i++) {
	// 	std::cout << "Key = " << it->first << std::endl;
	// 	std::cout << "Value = " << it->second << std::endl;
	// 	++it;
	// 	// it++;
	// }

	// std::cout << "Decrement" << std::endl;
	// std::cout << "Key = " << it->first << std::endl;
	// std::cout << "Value = " << it->second << std::endl;

	std::cout << "--------------- Decrement ---------------" << std::endl;
	// it = avl.end();
	// for (size_t i = avl.size(); i > 0; i--) {
	// 	std::cout << "Key = " << it->first << std::endl;
	// 	std::cout << "Value = " << it->second << std::endl;
	// 	// --it;
	// 	it--;
	// }

	// ft::avl_tree<int, int>::pointer node = avl.search(root, 30);
	// std::cout << "node->value = " << node->value << std::endl;
	// std::cout << "node->parent = " << node->parent << std::endl;
	// std::cout << "node->left = " << node->left->value << std::endl;
	// std::cout << "node->right = " << node->right->value << std::endl;

	std::cout << "size = " <<  avl.size() << std::endl;
	std::cout << "max size = " << avl.max_size() << std::endl;
	std::cout << "empty = " << std::boolalpha << avl.empty() << std::endl;
	// root = avl.deleteNode(root, 10);
	// root = avl.deleteNode(root, 20);
	// root = avl.deleteNode(root, ft::pair<int, int>(1, 10));
	// root = avl.deleteNode(root, ft::pair<int, int>(3, 30));
	// root = avl.deleteNode(root, ft::pair<int, int>(4, 40));
	// root = avl.deleteNode(root, ft::pair<int, int>(5, 50));
	// root = avl.deleteNode(root, ft::pair<int, int>(6, 25));
	// root = avl.deleteNode(root, 40);
	// root = avl.deleteNode(root, 50);
	// root = avl.deleteNode(root, 25);
	std::cout << "Printing AVL Contents (Pre Order Traversal)" << std::endl;
	avl.printPreOrder(root);
	std::cout << "Printing AVL Contents (In Order Traversal)" << std::endl;
	avl.printInOrder(root);
	std::cout << "size = " << avl.size() << std::endl;

	avl.free_all(root);
	// ft::avl_tree<int, int>::iterator it = avl.begin();
	// std::cout << "ft::map::begin()->key = " << it->first << std::endl;
	// std::cout << "ft::map::begin()->value = " << it->second << std::endl;

	std::map<int, int> m;
	// m.insert(std::pair<int, int>(2, 20));
	// m.insert(std::pair<int, int>(5, 50));
	// m.insert(std::pair<int, int>(3, 30));
	// m.insert(std::pair<int, int>(6, 25));
	// m.insert(std::pair<int, int>(4, 40));
	// m.insert(std::pair<int, int>(1, 10));
	std::map<int, int>::iterator m_iter;
	for (m_iter = m.begin(); m_iter != m.end(); m_iter++) {
		std::cout << "Iterator Key = " << m_iter->first << std::endl;
		std::cout << "Iterator Value = " << m_iter->second << std::endl;
	}
	// std::map<char, std::string> ms;
	// ms.insert();

	// NAMESPACE::map<int, int> test_map;

	// std::cout << "Empty: " << test_map.empty() << std::endl
	//           << "Size: " << test_map.size() << std::endl
	// 		  << "Max Size: " << test_map.max_size() << std::endl;

	// test_map.insert(NAMESPACE::pair<int, int>(2, 20));
	// test_map.insert(NAMESPACE::pair<int, int>(1, 10));
	// test_map.insert(NAMESPACE::pair<int, int>(3, 30));
	// test_map.insert(NAMESPACE::pair<int, int>(6, 25));
	// test_map.insert(NAMESPACE::pair<int, int>(5, 50));
	// test_map.insert(NAMESPACE::pair<int, int>(4, 40));

	// // test_map.erase(test_map.begin());
	// test_map.erase(++test_map.begin());
	// // test_map.erase(++++++test_map.begin());
	// // test_map.erase(--test_map.end());
	// // NAMESPACE::map<int, int>::iterator it_map = test_map.begin();
	// std::cout << "---------- INCREMENT ----------" << std::endl;
	// for (NAMESPACE::map<int, int>::iterator it_map = test_map.begin(); it_map != test_map.end(); it_map++) {
	// 	std::cout << "Iterator Key = " << it_map->first << std::endl;
	// 	std::cout << "Iterator Value = " << it_map->second << std::endl;
	// }

	// std::cout << "---------- DECREMENT ----------" << std::endl;
	// for (NAMESPACE::map<int, int>::iterator it_map = --test_map.end(); it_map != test_map.begin(); it_map--) {
	// 	std::cout << "Iterator Key = " << it_map->first << std::endl;
	// 	std::cout << "Iterator Value = " << it_map->second << std::endl;
	// }


    // std::cout << "---------- REVERSE INCREMENT ----------" << std::endl;
	// for (NAMESPACE::map<int, int>::reverse_iterator it_map = test_map.rbegin(); it_map != test_map.rend(); it_map++) {
	// 	std::cout << "Iterator Key = " << it_map->first << std::endl;
	// 	std::cout << "Iterator Value = " << it_map->second << std::endl;
	// }

	// std::cout << "---------- REVERSE DECREMENT ----------" << std::endl;
	// for (NAMESPACE::map<int, int>::reverse_iterator it_map = --test_map.rend(); it_map != test_map.rbegin(); it_map--) {
	// 	std::cout << "Iterator Key = " << it_map->first << std::endl;
	// 	std::cout << "Iterator Value = " << it_map->second << std::endl;
	// }

	// // if (test_map.find(2) != test_map.end()) {
	// // 	std::cout << "test_map[2] key = " << test_map.find(2)->first << std::endl;
	// // 	std::cout << "test_map[2] value = " << test_map.find(2)->second << std::endl;
	// // }
	// // // test_map.clear();
	// // // test_map.erase(test_map.begin());

	// // std::cout << "test_map::at(2) = " << test_map.at(2) << std::endl;

	// std::cout << "---------- INCREMENT ----------" << std::endl;
	// for (NAMESPACE::map<int, int>::iterator it_map = test_map.begin(); it_map != test_map.end(); it_map++) {
	// 	std::cout << "Iterator Key = " << it_map->first << std::endl;
	// 	std::cout << "Iterator Value = " << it_map->second << std::endl;
	// }

	// std::cout << "Empty: " << test_map.empty() << std::endl
	//           << "Size: " << test_map.size() << std::endl
	// 		  << "Max Size: " << test_map.max_size() << std::endl;

	// (void)i;

	return 0;
}

// int main() {
// 	// vector<int> v;

// 	// v.push_back(2);
// 	// cout << v.size() << endl;

// 	// cout << "Element Access Tests" << endl;
// 	// try {
// 	// 	cout << "\tat(42) = "<< v.at(42) << endl;
// 	// } catch (exception &e) {
// 	// 	cerr << e.what() << endl;
// 	// }
// 	// cout << "\toperator[-42] = "<< v[-42] << endl;
// 	// cout << "\toperator[42] = "<< v[42] << endl;
// 	// // cout << "\tfront() = " << v.front() << endl;
// 	// cout << "\tback() = " << v.back() << endl;
// 	// cout << v[123212312231239] << endl;


// 	vector<int> v(5, 20);

// 	cout << boolalpha << v.empty() << endl
// 		 << v.capacity() << endl
// 		 << v.max_size() << endl
// 		 << v[3] << endl;

// 	ft::vector<int> v2(5, 20);

// 	cout << boolalpha << v2.empty() << endl
// 		 << v2.capacity() << endl
// 		 << v2.max_size() << endl
// 		 << v2[3] << endl;

// 	/*-----------------------------------------------------------------------*/
	
// 	cout << GREEN "\n::Pop_Back() Tests" DEFAULT << endl;

// 	vector<int> std_pop(10, 42);
// 	ft::vector<int> ft_pop(10, 42);

// 	cout << "std\tft\n-----\t-----" << endl;
// 	for (size_t i = 0; std_pop.size(); i++) {
// 		cout << std_pop.size();
// 		std_pop.pop_back();
// 		cout << "\t" << ft_pop.size() << endl;
// 		ft_pop.pop_back();
// 	}
// 	// for (size_t i = 0; i < 3; i++) {
// 	// 	cout << std_pop.size();
// 	// 	std_pop.pop_back();
// 	// 	cout << "\t" << ft_pop.size() << endl;
// 	// 	ft_pop.pop_back();
// 	// }

// 	/*-----------------------------------------------------------------------*/
	
// 	cout << GREEN "\n::At() Tests" DEFAULT << endl;
	
// 	cout << YELLOW "Bounds Checking" DEFAULT << endl;
// 	{
// 		vector<int> std_at;
// 		ft::vector<int> ft_at;

// 		try {
// 			cout << std_at.at(42) << endl;	// terminate called after throwing an instance of 'std::out_of_range'
// 		} catch (exception &e) {
// 			cerr << e.what() << endl;
// 		}
// 		try {
// 			cout << ft_at.at(42) << endl;
// 		} catch (exception &e) {
// 			cerr << e.what() << endl;
// 		}
// 	}

// 	cout << YELLOW "Standard Tests" DEFAULT << endl;
// 	{
// 		vector<int> std_at(5, 42);
// 		ft::vector<int> ft_at(5, 42);

// 		cout << "at(3)" << endl;
// 		try {
// 			cout << "std::vector = " << std_at.at(3) << endl;
// 		} catch (exception &e) {
// 			cerr << e.what() << endl;
// 		}
// 		try {
// 			cout << "ft::vector = " << ft_at.at(3) << endl;
// 		} catch (exception &e) {
// 			cerr << e.what() << endl;
// 		}

// 		cout << "at(0)" << endl;
// 		try {
// 			cout << "std::vector = " << std_at.at(0) << endl;
// 		} catch (exception &e) {
// 			cerr << e.what() << endl;
// 		}
// 		try {
// 			cout << "ft::vector = " << ft_at.at(0) << endl;
// 		} catch (exception &e) {
// 			cerr << e.what() << endl;
// 		}

// 		cout << "at(5)" << endl;
// 		try {
// 			cout << "std::vector = " << std_at.at(5) << endl;
// 		} catch (exception &e) {
// 			cerr << e.what() << endl;
// 		}
// 		try {
// 			cout << "ft::vector = " << ft_at.at(5) << endl;
// 		} catch (exception &e) {
// 			cerr << e.what() << endl;
// 		}
// 	}

// 	/*-----------------------------------------------------------------------*/
// 	// ft::vector<int> vOrig(3, 20);
// 	// ft::vector<int> vCopy = vOrig;

// 	// cout << vCopy.size() << endl;
// 	// cout << vCopy.capacity() << endl;
// 	// cout << vCopy[2] << endl;
// 	/*-----------------------------------------------------------------------*/

// 	cout << GREEN "\nIterator ::begin() & ::end() Tests" DEFAULT << endl;

// 	{
// 		vector<int> std_iter(3, 5);
// 		cout << "std.begin() = " << *std_iter.begin() << endl;
// 		// cout << "std.end() = " << *std_iter.end() << endl;

// 		ft::vector<int> ft_iter(3, 5);
// 		cout << "ft.begin() = " << *ft_iter.begin() << endl;
// 		// cout << "ft.end() = " << *ft_iter.end() << endl;
// 	}

// 	/*-----------------------------------------------------------------------*/

// 	cout << GREEN "\nIterator Tests" DEFAULT << endl;

// 	{
// 		vector<int> std_iter(3, 5);
// 		vector<int> ::iterator std;

// 		for (std = std_iter.begin(); std != std_iter.end(); std++) {
// 			cout << *std << endl;
// 		}
// 		// cout << *std << endl;

// 		ft::vector<int> ft_iter(3, 5);
// 		ft::vector<int> ::iterator ft;

// 		for (ft = ft_iter.begin(); ft != ft_iter.end(); ft++) {
// 			cout << *ft << endl;
// 		}
// 		// cout << *ft << endl;
// 	}
	
// 	/*-----------------------------------------------------------------------*/

// 	cout << GREEN "\nClear Test" DEFAULT << endl;

// 	vector<int> std_clear(3, 42);
// 	vector<int> ::iterator std_iter;
// 	cout << "std.size() = " << std_clear.size() << endl
// 		 << "std.capacity() = " << std_clear.capacity() << endl
// 		 << YELLOW "Contents of STD before ::clear()" DEFAULT << endl;
// 	for (std_iter = std_clear.begin(); std_iter != std_clear.end(); std_iter++) {
// 		cout << *std_iter << endl;
// 	}
// 	cout << "std.clear()" << endl;
// 	std_clear.clear();
// 	cout << "std.size() = " << std_clear.size() << endl
// 		 << YELLOW "Contents of STD after ::clear()" DEFAULT << endl;
// 	for (std_iter = std_clear.begin(); std_iter != std_clear.end(); std_iter++) {
// 		cout << *std_iter << endl;
// 	}
	
// 	ft::vector<int> ft_clear(3, 42);
// 	ft::vector<int> ::iterator ft_iter;
// 	cout << "\nft.size() = " << ft_clear.size() << endl
// 		 << "ft.capacity() = " << ft_clear.capacity() << endl
// 		 << YELLOW "Contents of FT before ::clear()" DEFAULT << endl;
// 	for (ft_iter = ft_clear.begin(); ft_iter != ft_clear.end(); ft_iter++) {
// 		cout << *ft_iter << endl;
// 	}
// 	cout << "ft.clear()" << endl;
// 	ft_clear.clear();
// 	cout << "ft.size() = " << ft_clear.size() << endl
// 		 << YELLOW "Contents of FT after ::clear()" DEFAULT << endl;
// 	for (ft_iter = ft_clear.begin(); ft_iter != ft_clear.end(); ft_iter++) {
// 		cout << *ft_iter << endl;
// 	}
	

// 	/*-----------------------------------------------------------------------*/

// 	cout << GREEN "\nSwap Test" DEFAULT << endl;

// 	std::vector<int> std_sample1(3, 3);
// 	std::vector<int> std_sample2(5, 5);
	
// 	std::cout << "std_sample1 contents before ::swap()" << endl;
// 	for (std::vector<int>::iterator i = std_sample1.begin(); i != std_sample1.end(); i++) {
// 		cout << *i << endl;
// 	}
// 	std::cout << "std_sample2 contents before ::swap()" << endl;
// 	for (std::vector<int>::iterator i = std_sample2.begin(); i != std_sample2.end(); i++) {
// 		cout << *i << endl;
// 	}
// 	std_sample1.swap(std_sample2);
// 	std::cout << "std_sample1 contents after ::swap()" << endl;
// 	for (std::vector<int>::iterator i = std_sample1.begin(); i != std_sample1.end(); i++) {
// 		cout << *i << endl;
// 	}
// 	std::cout << "std_sample2 contents after ::swap()" << endl;
// 	for (std::vector<int>::iterator i = std_sample2.begin(); i != std_sample2.end(); i++) {
// 		cout << *i << endl;
// 	}
	
	
// 	ft::vector<int> ft_sample1(3, 3);
// 	ft::vector<int> ft_sample2(5, 5);
	
// 	std::cout << "\bft_sample1 contents before ::swap()" << endl;
// 	for (ft::vector<int>::iterator i = ft_sample1.begin(); i != ft_sample1.end(); i++) {
// 		cout << *i << endl;
// 	}
// 	std::cout << "ft_sample2 contents before ::swap()" << endl;
// 	for (ft::vector<int>::iterator i = ft_sample2.begin(); i != ft_sample2.end(); i++) {
// 		cout << *i << endl;
// 	}
// 	ft_sample1.swap(ft_sample2);
// 	std::cout << "\bft_sample1 contents after ::swap()" << endl;
// 	for (ft::vector<int>::iterator i = ft_sample1.begin(); i != ft_sample1.end(); i++) {
// 		cout << *i << endl;
// 	}
// 	std::cout << "ft_sample2 contents after ::swap()" << endl;
// 	for (ft::vector<int>::iterator i = ft_sample2.begin(); i != ft_sample2.end(); i++) {
// 		cout << *i << endl;
// 	}

// 	/*-----------------------------------------------------------------------*/

// 	cout << GREEN "\nSimple Push Test" DEFAULT << endl;
// 	ft::vector<int> ft_simple_push(3, 1);
// 	cout << ft_simple_push.size() << endl;
// 	cout << ft_simple_push.capacity() << endl;

// 	ft_simple_push.push_back(2);
// 	ft_simple_push.push_back(3);
// 	ft_simple_push.push_back(4);
// 	ft_simple_push.push_back(5);
// 	ft_simple_push.push_back(6);
// 	ft_simple_push.push_back(7);
// 	ft_simple_push.push_back(8);

// 	cout << ft_simple_push.size() << endl;
// 	cout << ft_simple_push.capacity() << endl;
// 	for (ft::vector<int>::iterator i = ft_simple_push.begin(); i != ft_simple_push.end(); i++) {
// 		cout << *i << endl;
// 	}

// 	/*-----------------------------------------------------------------------*/

// 	cout << GREEN "\nvector::erase(iterator pos) Tests" DEFAULT << endl;
// 	{
// 		std::vector<int> std_erase;
// 		for (size_t i = 8; i < 12; i++) {
// 			std_erase.push_back(i + 1);
// 		}
// 		for (size_t i = 0; i < std_erase.size(); i++) {
// 			std::cout << std_erase[i] << std::endl;
// 		}

// 		std::cout << "std::vector::size = " << std_erase.size() << std::endl;
// 		std::cout << "std::vector::capacity = " << std_erase.capacity() << std::endl;

// 		int index = 2;
// 		std::cout << YELLOW "Erased std_erase.begin() + " << index << DEFAULT << std::endl;
// 		std_erase.erase(std_erase.begin() + index);
// 		for (std::vector<int>::iterator i = std_erase.begin(); i != std_erase.end(); i++) {
// 			cout << *i << endl;
// 		}
// 		std::cout << "std::vector::size = " << std_erase.size() << std::endl;
// 		std::cout << "std::vector::capacity = " << std_erase.capacity() << std::endl;


// 		ft::vector<int> ft_erase;
// 		for (size_t i = 8; i < 12; i++) {
// 			ft_erase.push_back(i + 1);
// 		}
// 		for (size_t i = 0; i < ft_erase.size(); i++) {
// 			std::cout << ft_erase[i] << std::endl;
// 		}
// 		std::cout << "ft::vector::size = " << ft_erase.size() << std::endl;
// 		std::cout << "ft::vector::capacity = " << ft_erase.capacity() << std::endl;

// 		std::cout << YELLOW "Erased ft_erase.begin() + 2" DEFAULT << std::endl;
// 		ft_erase.erase(ft_erase.begin() + 2);
// 		for (ft::vector<int>::iterator i = ft_erase.begin(); i != ft_erase.end(); i++) {
// 			cout << *i << endl;
// 		}
// 		std::cout << "ft::vector::size = " << ft_erase.size() << std::endl;
// 		std::cout << "ft::vector::capacity = " << ft_erase.capacity() << std::endl;
// 	}

// 	/*-----------------------------------------------------------------------*/

// 	cout << GREEN "\nvector::erase(iterator first, iterator last) Tests" DEFAULT << endl;
// 	{
// 		std::cout << YELLOW "std:_erase initial contents" DEFAULT << std::endl;
// 		std::vector<int> std_erase;

// 		for (size_t i = 0; i < 10; i++) {
// 			std_erase.push_back(i + 1);
// 		}
// 		for (size_t i = 0; i < std_erase.size(); i++) {
// 			std::cout << std_erase[i] << std::endl;
// 		}
// 		std::cout << YELLOW "\nstd_erase new contents" DEFAULT << std::endl;
// 		std_erase.erase(std_erase.begin() + 2, std_erase.begin() + 8);
// 		for (size_t i = 0; i < std_erase.size(); i++) {
// 			std::cout << std_erase[i] << std::endl;
// 		}

// 		std::cout << YELLOW "\nft_erase initial contents" DEFAULT << std::endl;
// 		ft::vector<int> ft_erase;

// 		for (size_t i = 0; i < 10; i++) {
// 			ft_erase.push_back(i + 1);
// 		}
// 		for (ft::vector<int>::iterator i = ft_erase.begin(); i != ft_erase.end(); i++) {
// 			std::cout << *i << std::endl;
// 		}
// 		std::cout << YELLOW "\nft_erase new contents" DEFAULT << std::endl;
// 		ft_erase.erase(ft_erase.begin() + 2, ft_erase.begin() + 8);
// 		for (size_t i = 0; i < ft_erase.size(); i++) {
// 			std::cout << ft_erase[i] << std::endl;
// 		}
// 	}


// 	/*-----------------------------------------------------------------------*/

// 	cout << GREEN "\nvector::resize() Tests" DEFAULT;

// 	std::vector<int> std_resize;

// 	for (size_t i = 1; i < 10; i++) {
// 		std_resize.push_back(i);
// 	}
// 	try {
// 		// std_resize.resize(-1354354354343634634);
// 		// std_resize.resize(0);
// 		// std_resize.resize(5);
// 		// std_resize.resize(8,100);
// 		// std_resize.resize(12);
// 		std_resize.resize(17);
// 		// std_resize.resize(72);
// 		// std_resize.resize(72123213123);
// 	} catch (std::exception &e) {
// 		std::cerr << "\n" << e.what() << std::endl;
// 	}

// 	// size_t n = -1354354354343634634;
// 	// std::cout << std_resize.max_size() << std::endl;
// 	// std::cout << n << std::endl;

// 	std::cout << "\nstd::vector contents:";
// 	for (size_t i = 0; i < std_resize.size(); i++) {
// 		std::cout << ' ' << std_resize[i];
// 	}
// 	std::cout << "\nstd::vector::size() = " << std_resize.size() << std::endl;
// 	std::cout << "std::vector::capacity() = " << std_resize.capacity() << std::endl;


// 	ft::vector<int> ft_resize;

// 	for (size_t i = 1; i < 10; i++) {
// 		ft_resize.push_back(i);
// 	}
// 	try {
// 		// ft_resize.resize(-1354354354343634634);
// 		// ft_resize.resize(0);
// 		// ft_resize.resize(5);
// 		// ft_resize.resize(8,100);
// 		// ft_resize.resize(12);
// 		ft_resize.resize(17);
// 		// ft_resize.resize(72);
// 		// ft_resize.resize(72123213123);
// 	} catch (std::exception &e) {
// 		std::cerr << "\n" << e.what() << std::endl;
// 	}

// 	std::cout << "\nft::vector contents:";
// 	for (size_t i = 0; i < ft_resize.size(); i++) {
// 		std::cout << ' ' << ft_resize[i];
// 	}
// 	std::cout << "\nft::vector::size() = " << ft_resize.size() << std::endl;
// 	std::cout << "ft::vector::capacity() = " << ft_resize.capacity() << std::endl;

// 	/*-----------------------------------------------------------------------*/

// 	// ft::stack<int> s;

// 	// cout << boolalpha << s.empty() << endl;
// 	// cout << s.size() << endl;

// 	// for (size_t i = 0; i < 10; i++) {
// 	// 	s.push(i);
// 	// 	cout << s.top() << endl;
// 	// }
// 	// cout << s.size() << endl;

// 	// for (size_t i = 0; i < 10; i++) {
// 	// 	s.pop();
// 	// 	// cout << s.top() << endl;
// 	// }
// 	// cout << s.size() << endl;

// 	return 0;
// }
