
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/avl.h"

TEST_CASE("Make sure sizing works", "[AVL]") {
	auto avl = AVL<int>();

	REQUIRE(avl.size() == 0);

	SECTION("Testing single insert") {
		avl.insert(5);
		REQUIRE(avl.size() == 1);
	}

	SECTION("Testing 100 inserts") {
		for (int i = 0; i < 100; i++) {
			avl.insert(1);	
		}
		REQUIRE(avl.size() == 100);
	}
}

TEST_CASE("Make sure insertions work", "[AVL]") {
	auto avl = AVL<int>();

	REQUIRE(avl.str() == "_");

	SECTION("With single item") {
		avl.insert(5);
		REQUIRE(avl.str() == "[5 _ _]");
	}

	SECTION("With two children") {
		avl.insert(5);
		avl.insert(4);
		avl.insert(6);
		REQUIRE(avl.str() == "[5 [4 _ _] [6 _ _]]");
	}
}
