/**
 * You might notice that I have all my implementation inside the header file,
 * which is a bit gross. However, this is required by C++ since generics are
 * done through templates. I could seperate out the implementation into a
 * separate .cpp file, but I would need to explicitly define instances of the
 * generic class, e.g.  AVL<int> or AVL<string>, and I'd only be able to use
 * those int and string trees in the rest of my project, which defeats the
 * purpose of generics. C'mon C++ I thought you were cooler this this.
 */

#ifndef AVL_H
#define AVL_H

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

	node* insert(node* t, T key) {
		if (t == nullptr) {
			t = new AVL<T>::node;
			t->data = key;
			t->height = 0;
			t->left = t->right = nullptr;
		}	
	}

	int height(node* t) {
		return t == nullptr ? -1 : t->height;
	}

	string to_string(node* t) {
		if (t == nullptr)
			return "_";
		stringstream fmt;
		fmt << "[" << t->data << " " << to_string(t->left) << " " << to_string(t->right) << "]";
		return fmt.str();
	}

public:

	AVL() {
		root = nullptr;
	}

	void insert(T key) {
		root = insert(root, key);
	}

	string to_string() {
		return to_string(root);
	}

};

#endif
