
#ifndef GENERATE_H
#define GENERATE_H

#include <iostream>
#include "parse.h"

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
	if (argc < 3) {
		cout <<
			"\n"
			"  Usage: ./main --gen <input file>\n"
			"\n"
			"  This function will take the scheduling requirements and availability preferences\n"
			"  to automatically generate a best-effort roster to fit these soft constraints.\n"
			"\n";
		return 1;
	}
	auto input = read_schedule(argv[2]);
	cout << input.required_roles.size() << endl;
	return 0;
}

#endif
