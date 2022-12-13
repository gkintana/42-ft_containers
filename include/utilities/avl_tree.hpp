/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:39:21 by gkintana          #+#    #+#             */
/*   Updated: 2022/12/13 23:09:17 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "pair.hpp"
#include "map_iterator.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<ft::pair<const Key, T> > >
class avl_tree {

	public:
		typedef Key                                                           key_type;
		typedef T                                                             mapped_type;
		typedef ft::pair<const key_type, mapped_type>                         value_type;
		typedef Compare                                                       key_compare;
		typedef Allocator                                                     allocator_base;
		typedef tree_node<value_type>                                         node_type;
		typedef node_type*                                                    pointer;
		typedef const pointer                                                 const_pointer;
		typedef typename allocator_base::template rebind<node_type>::other    allocator_type;
		typedef std::size_t                                                   size_type;

	private:
		key_compare m_comp;
		allocator_type m_alloc;
		allocator_base m_base;
		pointer m_root;
		pointer m_sentinel;

	public:
		avl_tree(const key_compare &comp = key_compare(),
		         const allocator_type &alloc = allocator_type()) : m_comp(comp),
				                                                   m_alloc(alloc),
				                                                   m_root(0) {
			m_sentinel = m_alloc.allocate(1 * sizeof(node_type));
			m_alloc.construct(m_sentinel, node_type());
		}

		~avl_tree() {}

		pointer getRoot() const {
			return m_root;
		}

		pointer getSentinel() const {
			return m_sentinel;
		}

		size_type max_size() const {
			return m_alloc.max_size();
		}

		void updateRoot(pointer new_root) {
			m_root = new_root;
		}

		pointer insertNode(pointer node, value_type value) {
			if (!node) {
				return createNode(value);
			} else if (m_comp(value.first, node->value.first)) {
				node->left = insertNode(node->left, value);
			} else if (m_comp(node->value.first, value.first)) {
				node->right = insertNode(node->right, value);
			}

			updateHeight(node);
			int balance = getBalanceFactor(node);
			return (balance > 1 && m_comp(value.first, node->left->value.first)) ? rightRotate(node) :
			       (balance > 1 && m_comp(node->left->value.first, value.first)) ? leftThenRightRotate(node) :
			       (balance < -1 && m_comp(node->right->value.first, value.first)) ? leftRotate(node) :
			       (balance < -1 && m_comp(value.first, node->right->value.first)) ? rightThenLeftRotate(node) : node;
		}

		pointer deleteNode(pointer node, value_type value) {
			if (!node) {
				return node;
			} else if (m_comp(value.first, node->value.first)) {
				node->left = deleteNode(node->left, value);
			} else if (m_comp(node->value.first, value.first)) {
				node->right = deleteNode(node->right, value);
			} else {
				if (!node->left && !node->right) {
					return node = freeNode(node);
				} else if (!node->left && node->right) {
					pointer new_node = node->right;
					node = freeNode(node);
					return new_node;
				} else if (node->left && !node->right) {
					pointer new_node = node->left;
					node = freeNode(node);
					return new_node;
				} else {
					pointer temp = getMinimum(node->right);
					m_base.destroy(&node->value);
					m_base.construct(&node->value, temp->value);
					node->right = deleteNode(node->right, temp->value);
				}
			}

			if (!node) {
				return node;
			}
			updateHeight(node);
			int balance = getBalanceFactor(node);
			return (balance > 1 && getBalanceFactor(node->left) >= 0) ? rightRotate(node) :
			       (balance > 1 && getBalanceFactor(node->left) < 0) ? leftThenRightRotate(node) :
			       (balance < -1 && getBalanceFactor(node->right) <= 0) ? leftRotate(node) :
			       (balance < -1 && getBalanceFactor(node->right) > 0) ? rightThenLeftRotate(node) : node;
		}

		pointer search(pointer node, key_type value) const {
			return !node ? m_sentinel :
			       m_comp(value, node->value.first) ? this->search(node->left, value) :
			       m_comp(node->value.first, value) ? this->search(node->right, value) : node;
		}

		pointer getKeySuccessor(pointer root, const key_type &key) const {
			pointer node = this->search(m_root, key);
			if (node->right) {
				return getMinimum(node->right);
			}
			pointer successor = m_sentinel;
			while (root) {
				if (m_comp(key, root->value.first)) {
					successor = root;
					root = root->left;
				} else if (m_comp(root->value.first, key)) {
					root = root->right;
				} else {
					break;
				}
			}
			return successor;
		}

		void printPreOrder(pointer node) {
			if (node) {
				std::cout << "Key = " << node->value.first
				          << "\t\tValue = " << node->value.second << std::endl;
				printPreOrder(node->left);
				printPreOrder(node->right);
			}
		}

		void printInOrder(pointer node) {
			if (node) {
				printInOrder(node->left);
				std::cout << "Key = " << node->value.first
				          << "\t\tValue = " << node->value.second;
				std::cout << std::endl;
				printInOrder(node->right);
			}
		}

		pointer getMinimum(pointer node) const {
			pointer min = node;
			while (min && min->left) {
				min = min->left;
			}
			return min;
		}

		void freeSentinelNode() {
			if (m_sentinel) {
				m_alloc.destroy(m_sentinel);
				m_alloc.deallocate(m_sentinel, 1 * sizeof(node_type));
				m_sentinel = NULL;
			}
		}

		void clear(pointer node, bool free_sentinel) {
			if (free_sentinel == true) {
				freeSentinelNode();
			}

			if (node) {
				clear(node->left, false);
				clear(node->right, false);
				m_alloc.destroy(node);
				m_alloc.deallocate(node, 1 * sizeof(node_type));
				m_root = node = NULL;
			}
		}

	private:
		pointer createNode(value_type value) {
			pointer node = m_alloc.allocate(1 * sizeof(node_type));
			m_alloc.construct(node, node_type(value));
			return node;
		}

		size_type getHeight(pointer node) {
			return (!node) ? 0 : node->height;
		}

		int getBalanceFactor(pointer node) {
			return (!node) ? 0 : getHeight(node->left) - getHeight(node->right);
		}

		void updateHeight(pointer node) {
			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
		}

		pointer leftRotate(pointer node) {
			pointer x = node->right,
			        y = x->left;

			x->left = node;
			node->right = y;

			updateHeight(node);
			updateHeight(x);
			return x;
		}

		pointer rightRotate(pointer node) {
			pointer x = node->left,
			        y = x->right;

			x->right = node;
			node->left = y;

			updateHeight(node);
			updateHeight(x);
			return x;
		}

		pointer leftThenRightRotate(pointer node) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		pointer rightThenLeftRotate(pointer node) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		pointer freeNode(pointer node) {
			m_alloc.destroy(node);
			m_alloc.deallocate(node, 1 * sizeof(node_type));
			return node = NULL;
		}

};

}    // namespace ft

#endif    // AVL_TREE_HPP
