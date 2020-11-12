
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <optional>

using namespace std;

const int HASHTABLE_SIZE = 100;

template <typename K, typename V>
class HashTable {
	
	/**
	 * node is a node of the linked list attached to each bin
	 * in the hashtable.
	 */
	struct node {
		K key;
		V value;
		node* next;
	};

	node* bins[HASHTABLE_SIZE];
	int current_size = 0;

	int get_index(K key) {
		hash<K> hasher = hash<K>();
		return hasher(key) % HASHTABLE_SIZE;
	}

	// Walk through the linked list and either update a node
	// if the key already exists, or add the node at the end
	void replace_or_append(node* root, K key, V value) {
		node* parent = nullptr;
		node* current = root;
		while (current != nullptr) {
			if (current->key == key) {
				current->value = value;
				return;
			}
			parent = current;
			current = current->next;
		}
		node* newNode = new node{key, value, nullptr};
		parent->next = newNode;
		++current_size;
	}

public:

	void insert(K key, V value) {
		int index = get_index(key);
		// If nothing in that bin
		if (bins[index] == nullptr) {
			node *newNode = new node{key, value, nullptr};
			bins[index] = newNode;
			++current_size;
			return;
		}
		// Otherwise if the bin already has something...
		replace_or_append(bins[index], key, value);
	}

	optional<V> get(K key) {
		int index = get_index(key);
		node *bin = bins[index];
		if (bin == nullptr) {
			return nullopt;
		}
		return bin->value;
	}

	void remove(K key) {
		int index = get_index(key);
		if (bins[index] == nullptr)
			return;
		node* parent = nullptr;
		node* current = bins[index];
		while (current != nullptr) {
			if (current->key == key) {
				if (parent != nullptr) {
					parent->next = current->next;
					delete current;
					--current_size;
					return;
				} else {
					delete current;
					bins[index] = nullptr;
					--current_size;
					return;
				}
			}
			parent = current;
			current = current->next;
		}
	}

	int size() {
		return current_size;
	}

};

#endif
