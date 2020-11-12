
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "requirements.h"
#include "availability.h"
#include "constants.h"
#include <set>
#include <vector>

using namespace std;

/**
 * Schedule represents a `schedule` file. Each entry represents a single shift;
 * it is a vector of integers, each representing the list of people working
 * that day. The integer is an index into where that person was defined in the
 * `availability` file.
 */
typedef vector<set<int>> Schedule;

/**
 * Parse a `.schedule` file into the `Schedule` type. Assumes the file
 * is valid.
 *
 * @param filepath The path to the schedule file.
 * @return         The schedule that has been read.
 */
Schedule read_schedule(string filepath) {
	ifstream file(filepath);
	Schedule schedule(WEEKLY_SHIFTS, set<int>());
	for (int i = 0; i < WEEKLY_SHIFTS; ++i) {
		int num_people;
		file >> num_people;
		for (int j = 0; j < num_people; ++j) {
			int role;
			file >> role;
			schedule[i].insert(role);
		}
	}
	file.close();
	return schedule;
}

/**
 * Constructs an empty schedule.
 *
 * @return A `Schedule` with 56 shifts, but no-one assigned.
 */
Schedule make_empty_schedule() {
	return Schedule(WEEKLY_SHIFTS, set<int>());
}

/**
 * Assign a person to a shift. Modifies a given schedule in-place.
 *
 * @param schedule    A pointer to the schedule to be modified.
 * @param shiftIndex  The shift to assign the person to.
 * @param personIndex The person to assign to the shift.
 */
void assign_shift(Schedule *schedule, int shiftIndex, int personIndex) {
	schedule->at(shiftIndex).insert(personIndex);
}

/**
 * This will "score" the optimisation of a schedule. A score of 0 is a perfect
 * roster; all shifts and roles are filled, and no availabilities are violated.
 * As the score gets further away from 0, the worse the schedule becomes. This
 * allows us to create an ordering of schedules and pick the best one. The
 * weights `rw` and `aw` are how strongly the number of filled shifts, versus
 * the violated availabilities, affects the final score. If `rw > aw` then the
 * business schedules more according to their needs, where if `rw < aw` they
 * care more about the availability of their employees than filling shifts.
 *
 * @param schedule     The schedule to score
 * @param requirements The requirements for each shift
 * @param availability The employee availabilities
 * @param rw           The weighting assigned to how shifts are filled
 * @param aw           The weight assigned to how availability is taken into account
 * @return             A floating point score representing how far the schedule
 *                     is from the ideal.
 */
double score_schedule(Schedule schedule, Requirements requirements, Availability availability, double rw, double aw) {
	double score = 0;			
	for (int i = 0; i < schedule.size(); ++i) {
		// TODO take into account each shift
	}
	return score;
}

#endif
