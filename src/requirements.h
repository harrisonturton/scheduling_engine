
#ifndef PARSE_H
#define PARSE_H

#include <fstream>
#include <iostream>
#include <vector>
#include "constants.h"

using namespace std;

/**
 * Represents a `requirements` file. Each entry represents a shift; it is a
 * vector of integers, representing the roles that must be assigned. There
 * should be `8*7=56` rows for each shift in the week.
 */
typedef vector<vector<int>> Requirements;

/**
 * Schedule represents a `schedule` file. Each entry represents a single shift;
 * it is a vector of integers, each representing the list of people working
 * that day. The integer is an index into where that person was defined in the
 * `availability` file.
 */
typedef vector<vector<int>> Schedule;

/**
 * Parse a `.requirements` file into the `Requirements` type. Assumes the file
 * is valid.
 *
 * @param filepath The path to the requirements file.
 */
Requirements read_requirements(string filepath) {
	ifstream file(filepath);
	Requirements requirements(WEEKLY_SHIFTS, vector<int>(0));
	for (int i = 0; i < WEEKLY_SHIFTS; ++i) {
		int num_people;
		file >> num_people;
		for (int j = 0; j < num_people; ++j) {
			int role;
			file >> role;
			requirements[i].push_back(role);
		}
	}
	file.close();
	return requirements;
}


#endif
