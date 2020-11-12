
#ifndef PARSE_H
#define PARSE_H

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Person {
	vector<int> skills;
	string availability;
};

struct Input {
	vector<vector<int>> required_roles;
	vector<Person> people;
};

const int WEEKLY_SHIFTS = 8 * 7; // 56 weekly shifts

Person read_person(ifstream &file) {
	int num_skills;
	file >> num_skills;
	vector<int> skills = vector<int>(0);
	for (int i = 0; i < num_skills; ++i) {
		int skill;
		file >> skill;
		skills.push_back(skill);
	}
	string availability;
	file >> availability;
	return Person{skills, availability};
}

Input read_schedule(string filepath) {
	ifstream file(filepath);
	int num_people;
	file >> num_people;
	vector<vector<int>> required(56, vector<int>(0));
	vector<Person> people = vector<Person>(0);
	for (int i = 0; i < WEEKLY_SHIFTS; ++i) {
		int num_positions;
		file >> num_positions;
		for (int j = 0; j < num_positions; ++j) {
			int role;
			file >> role;
			required[i].push_back(role);
		}
	}
	for (int i = 0; i < num_people; ++i) {
		Person person = read_person(file);
		people.push_back(person);
	}
	file.close();
	return Input{required, people};
}

#endif
