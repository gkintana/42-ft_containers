/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:39:21 by gkintana          #+#    #+#             */
/*   Updated: 2022/11/30 23:53:25 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

// https://github.com/llvm/llvm-project/tree/main/libcxx
// https://github.com/gcc-mirror/gcc/tree/master/libstdc%2B%2B-v3/include/bits
// https://www.happycoders.eu/algorithms/red-black-tree-java/
// https://www.cs.auckland.ac.nz/software/AlgAnim/red_black.html
// https://web.stanford.edu/class/archive/cs/cs106l/cs106l.1176/lectures/lecture05/05_Templates.pdf
// https://web.stanford.edu/class/archive/cs/cs106l/cs106l.1176/lectures/

// https://github.com/dbjnbnrj/redblacktrees
// https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html
// https://zarif98sjs.github.io/mindcraft/RedBlackTree/
// https://www.youtube.com/watch?v=vRwi_UcZGjU

#include <map>
#include "pair.hpp"
#include "tree_iterator.hpp"

namespace ft {

// template <class T>
// struct tree_node {
// 	typedef T              value_type;
// 	typedef tree_node*     pointer;
// 	typedef std::size_t    size_type;

// 	value_type    value;
// 	pointer       parent;
// 	pointer       left;
// 	pointer       right;
// 	size_type     height;

// 	tree_node(value_type data) : value(data), parent(0), left(0), right(0), height(1) {}

// 	~tree_node() {}
// };

template < class Key, class T, class Compare = std::less<Key>,
           class Allocator = std::allocator< ft::pair<const Key, T> > >
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
		// typedef tree_iterator<value_type>                                     iterator;

	private:
		key_compare m_comp;
		allocator_type m_alloc;
		allocator_base m_base;
		pointer m_root;
		pointer m_sentinel;
		// pointer m_free;
		// bool dont_free;
		size_type m_size;

	public:
		avl_tree(const key_compare &comp = key_compare(),
		         const allocator_type &alloc = allocator_type()) : m_comp(comp),
				                                                   m_alloc(alloc),
				                                                   m_root(0),
																//    m_free(0),
																//    dont_free(false),
																   m_size(0) {
			m_sentinel = m_alloc.allocate(1 * sizeof(node_type));
			m_alloc.construct(m_sentinel, node_type());
		}

		// avl_tree &operator=(const avl_tree &x) {
		// 	(void)x;
		// }

		~avl_tree() {
			// m_alloc.destroy(m_sentinel);
			// m_alloc.deallocate(m_sentinel, 1 * sizeof(node_type));
			// m_sentinel = NULL;

			// while (m_size) {
			// 	m_root = deleteNode(m_root, m_root->value);
			// }
			// free_all(m_root);
			// m_alloc.destroy(m_root);
			// m_alloc.deallocate(m_root, 1 * sizeof(node_type));
		}

		// iterator begin() {
		// 	return iterator(getMinimum(m_root));
		// }
		// const_iterator begin() const;
		// iterator end() {
		// 	return iterator(NULL);
		// }
		// const_iterator end() const;

		pointer getRoot() const {
			return m_root;
		}

		pointer getSentinel() const {
			return m_sentinel;
		}

		bool empty() const {
			return !m_size;
		}

		size_type size() const {
			return m_size;
		}

		size_type max_size() const {
			return m_alloc.max_size();
		}

		void swap(avl_tree &x) {
			key_compare temp_comp = m_comp;
			allocator_type temp_alloc = m_alloc;
			pointer temp_root = m_root;
			size_type temp_size = m_size;

			m_comp = x.m_comp;
			m_alloc = x.m_alloc;
			m_root = x.m_root;
			m_size = x.m_size;

			x.m_comp = temp_comp;
			x.m_alloc = temp_alloc;
			x.m_root = temp_root;
			x.m_size = temp_size;
		}

		// pointer insertNode(pointer node, pointer parent, value_type value) {
		// 	if (!node) {
		// 		return m_root = createNode(parent, value);
		// 	} else if (value < node->value) {
		// 		node->left = insertNode(node->left, node, value);
		// 	} else if (value > node->value) {
		// 		node->right = insertNode(node->right, node, value);
		// 	}

		// 	int balance = checkBalanceFactor(node);
		// 	if (balance > 1) {
		// 		if (value > node->left->value) {
		// 			node->left = leftRotate(node->left);
		// 		}
		// 		return m_root = rightRotate(node);
		// 	} else if (balance < -1) {
		// 		if (value < node->right->value) {
		// 			node->right = rightRotate(node->right);
		// 		}
		// 		return m_root = leftRotate(node);
		// 	}
		// 	return m_root = node;
		// }

		// pointer insertNode(pointer node, pointer parent, value_type value) {
		// 	if (node == NULL) {
		// 		node = createNode(parent, value);
		// 	} else if (node->value > value) {
		// 		node->left = insertNode(node->left, node, value);

		// 		if (std::abs(static_cast<int>(getHeight(node->left) - getHeight(node->right))) == 2) {
		// 			if (node->left != NULL && value < node->left->value) {
		// 				node = LLRotate(node);
		// 			} else {
		// 				node = LRRotate(node);
		// 			}
		// 		}
		// 	} else if (node->value < value) {
		// 		node->right = insertNode(node->right, node, value);

		// 		if (std::abs(static_cast<int>(getHeight(node->left) - getHeight(node->right))) == 2) {
		// 			if (node->right != NULL && value < node->right->value) {
		// 				node = RLRotate(node);
		// 			} else {
		// 				node = RRRotate(node);
		// 			}
		// 		}
		// 	}
		// 	updateHeight(node);
		// 	return m_root = node;
		// }

		void updateRoot(pointer new_root) {
			m_root = new_root;
		}

		pointer insertNode(pointer node, value_type value) {
			if (!node) {
				return createNode(value);
			// } else if (value.first < node->value.first) {
			} else if (m_comp(value.first, node->value.first)) {
				node->left = insertNode(node->left, value);
			// } else if (value.first > node->value.first) {
			} else if (m_comp(node->value.first, value.first)) {
				node->right = insertNode(node->right, value);
			}

			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

			int balance = checkBalanceFactor(node);
			if (balance > 1) {
				// if (value.first > node->left->value.first) {
				if (m_comp(node->left->value.first, value.first)) {
					node->left = leftRotate(node->left);
				}
				return rightRotate(node);
			} else if (balance < -1) {
				// if (value.first < node->right->value.first) {
				if (m_comp(value.first, node->right->value.first)) {
					node->right = rightRotate(node->right);
				}
				return leftRotate(node);
			}
			return node;
		}

		// pointer rebalance(pointer node) {
		// 	if (std::abs(static_cast<int>(getHeight(node->left) - getHeight(node->right))) == 2) {
		// 		if (getHeight(node->left) < getHeight(node->right)) {
		// 			if (getHeight(node->right->right) > getHeight(node->right->left)) {
		// 				node = RLRotate(node);
		// 			} else {
		// 				node = RRRotate(node);
		// 			}
		// 		} else {
		// 			if (getHeight(node->left->right) > getHeight(node->left->left)) {
		// 				node = LLRotate(node);
		// 			} else {
		// 				node = LRRotate(node);
		// 			}
		// 		}
		// 	}
		// 	return node;
		// }

		// pointer deleteNode(pointer node, value_type value) {
		// 	if (node != NULL) {
		// 		if (node->value == value) {
		// 			if (node->right == NULL && node->left != NULL) {
		// 				std::cout << "R == NULL & L != NULL" << std::endl;
		// 				if (node->parent != NULL) {
		// 					if (node->parent->value < node->value) {
		// 						node->parent->right = node->left;
		// 					} else {
		// 						node->parent->left = node->left;
		// 					}
		// 					updateHeight(node->parent);
		// 				}
		// 				node->left->parent = node->parent;
		// 				// pointer t = m_alloc.allocate(1 * sizeof(node_type));
		// 				// m_alloc.construct(t, node_type(node->value, node->parent));
		// 				// t->height = node->height;
		// 				// t->left = rebalance(node->left);
		// 				pointer new_node = rebalance(node->left);
		// 				// m_alloc.destroy(node);
		// 				// m_alloc.deallocate(node, 1 * sizeof(node_type));
		// 				// node = t->left;
		// 				// m_alloc.destroy(t);
		// 				m_alloc.destroy(node);
		// 				m_alloc.deallocate(node, 1 * sizeof(node_type));
		// 				m_size--;
		// 				// return node->left = rebalance(node->left);
		// 				return new_node;
		// 			} else if (node->right != NULL && node->left == NULL) {
		// 				std::cout << "R != NULL & L == NULL" << std::endl;

		// 				if (node->parent != NULL) {
		// 					if (node->parent->value < node->value) {
		// 						node->parent->right = node->right;
		// 					} else {
		// 						node->parent->left = node->right;
		// 					}
		// 					updateHeight(node->parent);
		// 				}
		// 				node->right->parent = node->parent;
		// 				pointer new_node = rebalance(node->left);
		// 				m_alloc.destroy(node);
		// 				m_alloc.deallocate(node, 1 * sizeof(node_type));
		// 				m_size--;
		// 				return new_node;
		// 				// return node->right = rebalance(node->right);
		// 			} else if (node->right == NULL && node->left == NULL) {
		// 				std::cout << "R == NULL & L == NULL" << std::endl;

		// 				if (node->parent != NULL) {
		// 					if (node->parent->value < node->value) {
		// 						node->parent->right = NULL;
		// 					} else {
		// 						node->parent->left = NULL;
		// 					}
		// 					updateHeight(node->parent);
		// 				}
		// 				// if (node->parent != NULL) {
		// 				// }
		// 				m_size--;

		// 				if (dont_free == true) {
		// 					if (m_free != NULL && node != NULL) {
		// 						m_alloc.deallocate(m_free, 1 * sizeof(node_type));
		// 						m_free = node;
		// 					}
		// 					else if (m_free == NULL && node != NULL)
		// 						m_free = node;
		// 					else
		// 						m_free = NULL;
		// 				} else
		// 					m_alloc.deallocate(node, 1 * sizeof(node_type));
		// 				return node = NULL;
		// 			} else {
		// 				std::cout << "DELETE ELSE" << std::endl;

		// 				pointer temp = getMinimum(node->right);
		// 				dont_free = true;
		// 				node->right = deleteNode(node->right, temp->value);
		// 				m_base.destroy(&node->value);
		// 				m_base.construct(&node->value, temp->value);
		// 				// free_all(m_free);
		// 				if (m_free) {
		// 					m_alloc.deallocate(m_free, 1 * sizeof(node_type));
		// 					m_free = NULL;
		// 				}
		// 				dont_free = false;
		// 				node = rebalance(node);
		// 			}
		// 		} else if (node->value < value) {
		// 			node->right = deleteNode(node->right, value);
		// 			node = rebalance(node);
		// 		} else if (node->value > value) {
		// 			node->left = deleteNode(node->left, value);
		// 			node = rebalance(node);
		// 		}

		// 		if (node != NULL) {
		// 			updateHeight(node);
		// 		}
		// 	}

		// 	// m_size--;
		// 	return node;
		// }

		pointer deleteNode(pointer node, value_type value) {
			if (!node) {
				return node;
			// } else if (value < node->value) {
			} else if (m_comp(value.first, node->value.first)) {
				node->left = deleteNode(node->left, value);
			// } else if (value > node->value) {
			} else if (m_comp(node->value.first, value.first)) {
				node->right = deleteNode(node->right, value);
			} else {
				if (node->left == NULL && node->right == NULL) {
					return node = freeNode(node);
				} else if (node->left == NULL && node->right != NULL) {
					pointer new_node = node->right;
					node = freeNode(node);
					return new_node;
				} else if (node->left != NULL && node->right == NULL) {
					pointer new_node = node->left;
					node = freeNode(node);
					return new_node;
				} else {
					pointer temp = getMinimum(node->right);
					// node->value = temp->value;
					m_base.destroy(&node->value);
					m_base.construct(&node->value, temp->value);
					node->right = deleteNode(node->right, temp->value);
				}
				// if (!(node->left) || !(node->right)) {
				// 	pointer temp = node->left ? node->left : node->right;
				// 	if (!temp) {
				// 		temp = node;
				// 		node = NULL;
				// 	} else {
				// 		m_base.destroy(&node->value);
				// 	m_base.construct(&node->value, temp->value);
				// 	}
				// 	// m_alloc.destroy(&temp->value);
				// 	m_alloc.deallocate(temp, 1 * sizeof(node_type));
				// 	temp = NULL;
				// 	m_size--;
				// 	// free(temp);
				// } else {
				// 	pointer temp = getMinimum(node->right);
				// 	// node->value = temp->value;
				// 	node->right = deleteNode(node->right, temp->value);
				// 	m_base.destroy(&node->value);
				// 	m_base.construct(&node->value, temp->value);
				// }
			}

			if (!node) {
				return node;
			}

			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

			int balance = checkBalanceFactor(node);
			if (balance > 1) {
				// std::cout << "value = " << value << std::endl;
				// std::cout << "node->value = " << node->value << std::endl;
				// if (value > node->right->value) {
				if (checkBalanceFactor(node->left) < 0) {
					node->left = leftRotate(node->left);
				}
				return rightRotate(node);
			} else if (balance < -1) {
				if (checkBalanceFactor(node->right) > 0) {
					node->right = rightRotate(node->right);
				}
				return leftRotate(node);
			}

			return node;
		}

		pointer search(pointer node, key_type value) const {
			if (!node) {
				return NULL;
			// } else if (value < node->value.first) {
			} else if (m_comp(value, node->value.first)) {
				return search(node->left, value);
			// } else if (value > node->value.first) {
			} else if (m_comp(node->value.first, value)) {
				return search(node->right, value);
			} else {
				return node;
			}
		}

		pointer getKeySuccessor(pointer root, const key_type &key) const {
			// if (k == m_sentinel->value.first) {
			// 	return NULL;
			// } else if (node->right != NULL) {
			// 	return getMinimum(node->right);
			// }

			pointer successor = NULL;
			while (root != NULL) {
				// if (node->value.first < root->value.first) {
				if (m_comp(key, root->value.first)) {
					successor = root;
					root = root->left;
				// } else if (node->value.first > root->value.first) {
				} else if (m_comp(root->value.first, key)) {
					root = root->right;
				} else {
					break;
				}
			}

			if (successor == NULL) {
				return m_sentinel;
			}
			return successor;
		}

		pointer getNodeSuccessor(pointer root, pointer node) {
			if (node == m_sentinel) {
				return NULL;
			} else if (node->right != NULL) {
				return getMinimum(node->right);
			}

			pointer successor = NULL;
			while (root != NULL) {
				// if (node->value.first < root->value.first) {
				if (m_comp(node->value.first, root->value.first)) {
					successor = root;
					root = root->left;
				// } else if (node->value.first > root->value.first) {
				} else if (m_comp(root->value.first, node->value.first)) {
					root = root->right;
				} else {
					break;
				}
			}

			if (successor == NULL) {
				return m_sentinel;
			}
			return successor;
		}

		pointer getNodePredecessor(pointer root, pointer node) {
			if (node == m_sentinel) {
				return getMaximum(root);
			} else if (node->left != NULL) {
				return getMaximum(node->left);
			}

			pointer predecessor = NULL;
			while (root != NULL) {
				// if (node->value > root->value) {
				if (m_comp(root->value.first, node->value.first)) {
					predecessor = root;
					root = root->right;
				// } else if (node->value < root->value) {
				} else if (m_comp(node->value.first, root->value.first)) {
					root = root->left;
				} else {
					break;
				}
			}
			return predecessor;
		}

		void printPreOrder(pointer node) {
			if (node != NULL) {
				std::cout << "Key = " << node->value.first
				          << "\t\tValue = " << node->value.second << std::endl;
				printPreOrder(node->left);
				printPreOrder(node->right);
			}
		}

		void printInOrder(pointer node) {
			if (node != NULL) {
				printInOrder(node->left);
				std::cout << "Key = " << node->value.first
				          << "\t\tValue = " << node->value.second;
				// if (node && node->parent) {
				// 	std::cout << "\tParent = " << node->parent->value.first;
				// }
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
			if (m_sentinel != NULL) {
				m_alloc.destroy(m_sentinel);
				m_alloc.deallocate(m_sentinel, 1 * sizeof(node_type));
				m_sentinel = NULL;
			}
		}

		void clear(pointer node, bool free_sentinel) {
			if (free_sentinel == true) {
				freeSentinelNode();
			}

			if (node != NULL) {
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
			m_size++;
			return node;
		}

		size_type getHeight(pointer node) {
			return (!node) ? 0 : node->height;
		}

		size_type checkBalanceFactor(pointer node) {
			return (!node) ? 0 : getHeight(node->left) - getHeight(node->right);
		}

		pointer getMaximum(pointer node) {
			pointer max = node;
			while (max->right) {
				max = max->right;
			}
			return max;
		}

		void updateHeight(pointer node) {
			if (node != NULL) {
				node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
			}
		}

		// void updateNodeHeights(pointer node) {
		// 	updateHeight(node->left);
		// 	updateHeight(node->right);
		// 	updateHeight(node);
		// 	updateHeight(node->parent);
		// }

		// pointer updateNode(pointer node, pointer temp) {
		// 	temp->parent = node->parent;
		// 	node->parent = temp;

		// 	if (temp->parent != NULL && node->value < temp->parent->value) {
		// 		temp->parent->left = temp;
		// 	} else if (temp->parent != NULL) {
		// 		temp->parent->right = temp;
		// 	}
		// 	node = temp;
		// 	updateNodeHeights(node);
		// 	return node;
		// }

		// pointer LLRotate(pointer node) {
		// 	pointer temp = node->left;
		// 	node->left = temp->right;

		// 	if (temp->right != NULL) {
		// 		temp->right->parent = node;
		// 	}
		// 	temp->right = node;

		// 	return updateNode(node, temp);
		// }

		// pointer RRRotate(pointer node) {
		// 	pointer temp = node->right;
		// 	node->right = temp->left;

		// 	if (temp->left != NULL) {
		// 		temp->left->parent = node;
		// 	}
		// 	temp->left = node;

		// 	return updateNode(node, temp);
		// }

		// pointer LRRotate(pointer node) {
		// 	node->left = RRRotate(node->left);
		// 	return LLRotate(node);
		// }

		// pointer RLRotate(pointer node) {
		// 	node->right = LLRotate(node->right);
		// 	return RRRotate(node);
		// }

		pointer leftRotate(pointer node) {
			pointer x = node->right,
			        y = x->left;

			x->left = node;
			node->right = y;

			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
			x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
			return x;
		}

		pointer rightRotate(pointer node) {
			pointer x = node->left,
			        y = x->right;

			x->right = node;
			node->left = y;

			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
			x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
			return x;
		}

		pointer freeNode(pointer node) {
			m_alloc.destroy(node);
			m_alloc.deallocate(node, 1 * sizeof(node_type));
			return node = NULL;
		}

};

}    // namespace ft

#endif    // AVL_TREE_HPP
