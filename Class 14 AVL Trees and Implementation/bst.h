/*
 * Binary search tree of ints. Values do not repeat.
 * Complete the private methods marked with TODO. Do not change the rest of the class.
 * Start with insert and preorder: the tests use them to build and show the trees.
 *
 * Student ID:
 * Date:
 */

#ifndef BST_H
#define BST_H

#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int info;
	Node *left;
	Node *right;
};

class BST {
public:
	BST() = default;
	~BST() { destroy(root); }

	// Copying is disabled so that two trees never own the same nodes.
	BST(const BST &) = delete;
	BST &operator=(const BST &) = delete;

	// Each public method calls the private method with the same name, starting at root.
	bool insert(int x) { return insert(root, x); }
	Node *search(int x) const { return search(root, x); }
	int height() const { return height(root); }
	int depth(int x) const { return depth(root, x); }
	bool remove(int x) { return remove(root, x); }

	// The public methods that print also end the line.
	void preorder() const {
		preorder(root);
		cout << "\n";
	}

	void inorder() const {
		inorder(root);
		cout << "\n";
	}

	void postorder() const {
		postorder(root);
		cout << "\n";
	}

	void levelOrder() const {
		levelOrder(root);
		cout << "\n";
	}

private:
	Node *root = nullptr;

	// Adds x where a search for it ends. Returns false if x was already in the tree.
	bool insert(Node *&n, int x) {
		if (n == nullptr) {
			n = new Node{x, nullptr, nullptr};
			return true;
		}
		if (n->info == x) {
			return false;
		}
		if (x < n->info) {
			return insert(n->left, x);
		}
		return insert(n->right, x);
	}

	// Prints the node, then its left subtree, then its right subtree. Each value is followed by one space.
	void preorder(Node *n) const {
		if (n == nullptr) return;
		cout << n->info << " ";
		preorder(n->left);
		preorder(n->right);
	}

	// Prints the left subtree, then the node, then the right subtree.
	void inorder(Node *n) const {
		if (n == nullptr) return;
		inorder(n->left);
		cout << n->info << " ";
		inorder(n->right);
	}

	// Prints the left subtree, then the right subtree, then the node.
	void postorder(Node *n) const {
		if (n == nullptr) return;
		postorder(n->left);
		postorder(n->right);
		cout << n->info << " ";
	}

	// Returns the node that holds x, or nullptr if x is not in the tree.
	Node* search(Node* n, int x) const {
		if (n == nullptr) {
			return nullptr;
		}
		if (n->info == x) {
			return n;
		}
		if (x < n->info) {
			return search(n->left, x);
		}
		return search(n->right, x);
	}

	// Returns the number of edges on the longest path down to a leaf. An empty tree has height -1.
	int height(Node *n) const {
		if (n == nullptr) return -1;
		return 1 + max(height(n->left), height(n->right));
	}

	// Returns the number of edges from the root to the node that holds x, or -1 if x is not in the tree.
	int depth(Node *n, int x) const {
		if (n == nullptr) return -1;
		if (n->info == x) return 0;

		int result;
		if (x < n->info){
			result = depth(n->left, x);
		}
		else{
			result = depth(n->right, x);
		}

		if(result == -1) return -1;

		return result + 1;
	}

	// Prints the values level by level, from left to right. Use a queue<Node *>.
	void levelOrder(Node *n) const {
		if (n == nullptr) return;

		queue<Node *> nodes;
		nodes.push(n);
		while (!nodes.empty()) {
			Node *current = nodes.front();
			nodes.pop();
			cout << current->info << " ";
			if (current->left != nullptr) nodes.push(current->left);
			if (current->right != nullptr) nodes.push(current->right);
		}
	}

	// Deletes x. Returns false if x was not in the tree.
	// A node with two children takes the smallest value of its right subtree.
	bool remove(Node *&n, int x) {
		if (n == nullptr) return false;
		if (x < n->info) return remove(n->left, x);
		if (x > n->info) return remove(n->right, x);

		if (n->left == nullptr) {
			Node *removed = n;
			n = n->right;
			delete removed;
		} else if (n->right == nullptr) {
			Node *removed = n;
			n = n->left;
			delete removed;
		} else {
			Node *successor = n->right;
			while (successor->left != nullptr) {
				successor = successor->left;
			}
			n->info = successor->info;
			return remove(n->right, successor->info);
		}
		return true;
	}

	// Frees every node of the subtree. Already written.
	void destroy(Node *n) {
		if (n == nullptr) return;
		destroy(n->left);
		destroy(n->right);
		delete n;
	}
};

#endif
