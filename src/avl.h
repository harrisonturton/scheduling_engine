/**
 * You might notice that I have all my implementation inside the header file,
 * which is a bit gross. However, this is required by C++ since generics are
 * done through templates. I could seperate out the implementation into a
 * separate .cpp file, but I would need to explicitly define instances of the
 * generic class, e.g.  AVL<int> or AVL<string>, and I'd only be able to use
 * those int and string trees in the rest of my project, which defeats the
 * purpose of generics. Gross C++! I thought you were cooler this this.
 */

#ifndef AVL_H
#define AVL_H

#include <sstream>

using namespace std;

template <class T>
class AVL {

	/**
	 * node is an internal structure that holds each element in the tree, with
	 * the corresponding rotation methods and metadata.
	 */
	struct node {
		T data;
		node* left;
		node* right;
		int height;
	};

	node* root;

	int current_size;

	node* insert(node* t, T key) {
		if (t == nullptr) {
			t = new AVL<T>::node;
			t->data = key;
			t->height = 0;
			t->left = t->right = nullptr;
		}	
		if (key < t->data) {
			t->left = insert(t->left, key);
		}
		if (key > t->data) {
			t->right = insert(t->right, key);
		}
		t->height = max(height(t->left), height(t->right))+1;
		return t;
	};

	int height(node* t) {
		return t == nullptr ? -1 : t->height;
	}

	string str(node* t) {
		if (t == nullptr)
			return "_";
		stringstream fmt;
		fmt << "[" << t->data << " " << str(t->left) << " " << str(t->right) << "]";
		return fmt.str();
	}

public:

	AVL() {
		root = nullptr;
		current_size = 0;
	}

	void insert(T key) {
		root = insert(root, key);
		++current_size;
	}

	bool search(T key) {
		node* parent = nullptr;
		node* current = root;
		while (current != nullptr) {
			if (current->key == key) {
				return true;
			}
			parent = current;
			current = current->key < key
				? current->left
				: current->right;
		}
		return false;
	}

	string str() {
		return str(root);
	}

	int size() {
		return current_size;
	}

};

#endif
