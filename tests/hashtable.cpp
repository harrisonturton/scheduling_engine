
#include "catch.hpp"
#include "../src/hashtable.h"
#include <optional>

using namespace std;

TEST_CASE("Hashtable insert()", "[HashTable]") {
	auto ht = HashTable<string, int>();

	REQUIRE(ht.size() == 0);

	SECTION("Testing single insert") {
		ht.insert("Johhny", 0);
		REQUIRE(ht.size() == 1);
	}

	SECTION("Test inserting with same key") {
		ht.insert("Johhny", 1);
		ht.insert("Johhny", 2);
		ht.insert("Johhny", 3);
		REQUIRE(ht.size() == 1);
	}

	SECTION("Testing more inserts than default size") {
		for (int i = 0; i < HASHTABLE_SIZE + 10; i++) {
			ht.insert(to_string(i), 0);	
		}
		REQUIRE(ht.size() == HASHTABLE_SIZE + 10); // Take into account early case
	}
}

TEST_CASE("HashTable get()", "[HashTable]") {
	auto ht = HashTable<string, int>();

	SECTION("Testing empty get()") {
		optional<int> age = ht.get("Harry");
		REQUIRE(age == nullopt);
	}

	SECTION("Testing single item get()") {
		ht.insert("Harry", 100);
		optional<int> age = ht.get("Harry");
		REQUIRE(age == 100);
	}

	SECTION("Test inserting with same key") {
		ht.insert("Harry", 1);
		ht.insert("Harry", 2);
		ht.insert("Harry", 3);
		optional<int> age = ht.get("Harry");
		REQUIRE(age == 3);
	}
}

TEST_CASE("HashTable remove()", "[HashTable]") {
	auto ht = HashTable<string, int>();

	ht.remove("Harry");
	REQUIRE(ht.size() == 0);

	SECTION("Testing single item remove()") {
		ht.insert("Harry", 100);
		ht.remove("Harry");
		REQUIRE(ht.size() == 0);
		optional<int> value = ht.get("Harry");
		REQUIRE(value == nullopt);
	}

	SECTION("Testing multiple item remove()") {
		ht.insert("Harry", 1);
		ht.insert("Tim", 2);
		ht.insert("Connor", 3);
		REQUIRE(ht.size() == 3);
		ht.remove("Connor");
		REQUIRE(ht.size() == 2);
		optional<int> value = ht.get("connor");
		REQUIRE(value == nullopt);
	}
}
