
#include "catch.hpp"
#include <vector>
#include "../src/schedule.h"

using namespace std;

TEST_CASE("Schedule assignments", "[Schedule]") {
	Schedule schedule = make_empty_schedule();

	REQUIRE(schedule.size() == 56);
	REQUIRE(schedule.at(0).size() == 0);

	assign_shift(&schedule, 0, 5);
	REQUIRE(schedule.at(0).size() == 1);
}

