
#include <iostream>
#include <vector>
#include "avl.h"
#include "parse.h"
#include <map>
#include <functional>

using namespace std;

void print_help(char** argv) {
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
		"  -g, --gen <input file>\n"
		"  -c, --complete <input file> <schedule file>\n"
		"\n";
}

map<string, function<void(char**)>> handle = {
	{ "-h",        print_help },
	{ "--help",    print_help },
	{ "-g",        print_help },
	{ "-gen",      print_help },
	{ "-c",        print_help },
	{ "-complete", print_help }
};

int main(int argc, char** argv) {
	// No flags, so print help
	if (argc == 1) {
		print_help(argv);
		return 0;
	}
	// If unknown command, direct to help
	if (handle.find(argv[1]) == handle.end()) {
		cout << "Command \"" << argv[1] << "\" not found. Run \"./main help\" to see the usage guide." << endl;
		return 1;
	}
	// Run the relevant command defined in the "handle" map
	// with the given arguments.
	handle[argv[1]](argv);
}
