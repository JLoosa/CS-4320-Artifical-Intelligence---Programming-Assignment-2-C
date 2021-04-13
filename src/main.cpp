/*
 * Main.cpp
 *
 *  Created on: Apr 13, 2021
 *      Author: Jacob
 */

#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <exception>
#include <string>

#include "provided/Schedule.hpp"
#include "provided/SchedulingProblem.hpp"
#include "provided/SearchAlgorithm.hpp"
#include "provided/SearchAlgorithmNaive.hpp"

/**
 * Add your algorithms as cases
 // */
SearchAlgorithm* searchByID(int id) {
	switch (id) {
	case 0:
		return new SearchAlgorithmNaive();
	default:
		return nullptr;
	}
}

int main(int argc, char **argv) {

	setvbuf((_iobuf*) stdout, (char *)NULL, _IONBF, 0 );

	// Check for correct input size
	if (argc != 7) {
		printf("Error: Expected 6 arguments, received %d.\n", argc);
		for (int i = 0; i < argc; i++)
			printf("Argument %d: %s\n", i, argv[i]);
		exit(1);
	}

	// Create local variables
	int nBuildings = 0;
	int nRooms = 0;
	int nCourses = 0;
	int nTimeLimitSeconds = 0;
	int nAlgorithm = 0;
	long lSeed = 0;

	// Parse input into local variables
	try {

		nBuildings = std::stoi(argv[1]);
		nRooms = std::stoi(argv[2]);
		nCourses = std::stoi(argv[3]);
		nTimeLimitSeconds = std::stoi(argv[4]);
		nAlgorithm = std::stoi(argv[5]);
		lSeed = std::stol(argv[6]);

	} catch (const std::exception &e) {
		printf("Failed to parse inputs: %s", e.what());
		exit(1);
	}

	SearchAlgorithm *algorithm = searchByID(nAlgorithm);
	if (algorithm == nullptr) {
		printf("Algorithm with ID %d does not exist!", nAlgorithm);
		exit(1);
	}

	// Print local variables to console for user
	printf("Number of Buildings: %d\n", nBuildings);
	printf("Number of Rooms: %d\n", nRooms);
	printf("Number of Courses: %d\n", nCourses);
	printf("Time Limit (s): %d\n", nTimeLimitSeconds);
	printf("Algorithm Number: %d\n", nAlgorithm);
	printf("Random Seed: %ld\n", lSeed);

	// Generate a Scheduling Problem
	SchedulingProblem schedulingProblem(lSeed);
	schedulingProblem.createRandomInstance(nBuildings, nRooms, nCourses);
	printf("Scheduling Problem generated.\n");

	Schedule *solution;

	// Import timings
	using std::chrono::milliseconds;
	using std::chrono::duration_cast;
	using std::chrono::system_clock;

	// Define the deadline
	milliseconds startTime = duration_cast<milliseconds>(
			system_clock::now().time_since_epoch());
	milliseconds deadline = startTime + std::chrono::seconds(nTimeLimitSeconds);
	const long lDeadline = deadline.count();
	solution = algorithm->solve(&schedulingProblem, lDeadline);
	milliseconds endTime = duration_cast<milliseconds>(
			system_clock::now().time_since_epoch());
	const long lEndTime = endTime.count();

	printf("Deadline: %ld\n", lDeadline);
	printf("Current: %ld\n", lEndTime);
	printf("Time remaining: %ld ms\n", lDeadline - lEndTime);

	if (endTime > deadline)
		printf("Algorithm exceeded deadline.\n");

	printf("Score: %f\n", schedulingProblem.evaluateSchedule(solution));

}

