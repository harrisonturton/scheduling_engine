
#include <iostream>
#include <map>
#include <functional>
#include "generate.h"

using namespace std;

/**
 * Print the help string
 *
 * @param argc The number of arguments passed to the commandline function.
 *             Ignored here, but required by the type signature of the
 *             function handler map.
 * @param argv The array of arguments passed to the commandline function.
 *             Ignored here, but required by the type signature of the
 *             function handler map.
 * @return     An integer, as in the main() function
 */
int print_help(int argc, char** argv) {
	cout <<
		"\n"
		"  Usage: ./main [command] [args]\n"
		"\n"
		"  This is a commandline tool that automatically generates weekly roster schedules,\n"
		"  finishes partially-compeleted schedules, and makes hiring recommendations based\n"
		"  on a list of people and their availabilities.\n"
		"\n"
		"  Commands\n"
		"  -h, --help\n"
		"  -g, --gen <requirements file> <availability file>\n"
		"  -c, --complete <input file> <schedule file>\n"
		"\n";
	return 0;
}

/**
 * Map the first commandline flag to the function that
 * should handle the remaining input.
 */
map<string, function<int(int, char**)>> handle = {
	{ "-h",        print_help },
	{ "--help",    print_help },
	{ "-g",        generate_roster },
	{ "-gen",      generate_roster },
	{ "-c",        print_help },
	{ "-complete", print_help }
};

int main(int argc, char** argv) {
	// No flags, so print help
	if (argc == 1) {
		print_help(argc, argv);
		return 0;
	}
	// If unknown command, direct to help
	if (handle.find(argv[1]) == handle.end()) {
		cout << "Command \"" << argv[1] << "\" not found. Run \"./main help\" to see the usage guide." << endl;
		return 1;
	}
	// Run the relevant command defined in the "handle" map
	// with the given arguments.
	return handle[argv[1]](argc, argv);
}
