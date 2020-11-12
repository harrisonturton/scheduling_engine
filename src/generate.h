
#ifndef GENERATE_H
#define GENERATE_H

#include <iostream>
#include "requirements.h"
#include "availability.h"

using namespace std;

/**
 * Take the commandline args and generate a schedule from the input files.
 *
 * @param argc The number of arguments passed to the commandline function.
 *             Ignored here, but required by the type signature of the
 *             function handler map.
 * @param argv The array of arguments passed to the commandline function.
 *             Ignored here, but required by the type signature of the
 *             function handler map.
 * @return     An integer, as in the main() function
 */
int generate_roster(int argc, char** argv) {
	if (argc < 4) {
		cout <<
			"\n"
			"  Usage: ./main --gen <requirements file> <availability file>\n"
			"\n"
			"  This function will take the scheduling requirements and availability preferences\n"
			"  to automatically generate a best-effort roster to fit these soft constraints.\n"
			"\n";
		return 1;
	}
	auto requirements = read_requirements(argv[2]);
	cout << requirements.size() << endl;
	auto availability = read_availability(argv[3]);
	cout << availability.size() << endl;
	for (int i = 0; i < availability.size(); ++i) {
		for (int j = 0; j < availability[i].second.size(); ++j) {
			cout << availability[i].second[j] << " ";
		}
		cout << endl;
	}
	cout << has_skill(availability, 0, 3) << endl;
	return 0;
}

#endif
