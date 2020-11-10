
#include <iostream>
#include "avl/avl.h"

using namespace std;

int main() {
	log("Hello world");
	auto avl = new AVL<int>();
	avl->insert(3);
	avl->insert(5);
	avl->insert(4);
	avl->insert(2);
	avl->insert(1);
	string test = avl->to_string();
	cout << test;
}
