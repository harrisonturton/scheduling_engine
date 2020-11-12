
#ifndef AVAILABILITY_H
#define AVAILABILITY_H

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include "constants.h"

using namespace std;

/**
 * Represents an `availability` file. Each entry represents a single person.
 * The first element in the pair is a vector of integers, each representing the
 * role that person can perform. The second element is a vector of 56 booleans,
 * representing whether that person can work on the corresponding shift.
 */
typedef vector<pair<set<int>, vector<bool>>> Availability;

/**
 * Parse a `.availability` file into the `Availability` type. Assumes the file
 * is valid.
 *
 * @param filepath The path to the availability file.
 */
Availability read_availability(string filepath) {
	ifstream file(filepath);
	int num_people;
	file >> num_people;
	Availability availability(num_people, make_pair(set<int>(), vector<bool>(0)));
	for (int i = 0; i < num_people; i++) {
		int num_skills;
		file >> num_skills;
		for (int j = 0; j < num_skills; ++j) {
			int skill;
			file >> skill;
			availability[i].first.insert(skill);
		}
		for (int k = 0; k < WEEKLY_SHIFTS; ++k) {
			int can_work;
			file >> can_work;
			availability[i].second.push_back(can_work);
		}
	}
	file.close();
	return availability;
}

/**
 * Check if a person is available to work a given shift
 *
 * @param availability The availability lookup table to read from
 * @param personIndex  The index of the person in the availability table to lookup
 * @param shiftIndex   The shift to see if they can work
 */
bool can_work_shift(Availability availability, int personIndex, int shiftIndex) {
	return availability[personIndex].second[shiftIndex];
}

/**
 * Check if a person has a certain skill
 *
 * @param availability The availability lookup table to read from
 * @param personIndex  The index of the person in the availability table to lookup
 * @param skill        The skill we want to see if they have
 */
bool has_skill(Availability availability, int personIndex, int skill) {
	return availability[personIndex].first.find(skill) != availability[personIndex].first.end();
}

#endif
