/*
 * SearchAlgorithmSimulatedAnnealing.cpp
 *
 *  Created on: Apr 13, 2021
 *      Author: Jacob
 */

#include "SearchAlgorithmSimulatedAnnealing.hpp"

#include <stdio.h>
#include <chrono>
#include <cmath>
#include <cstdlib>

#include "provided/Schedule.hpp"

extern float randFloat();

const bool SearchAlgorithmSimulatedAnnealing::isSwapValid(Schedule* schedule, const int indexA, const int indexB) {
	int* raw = schedule->rawDataPointer();
	if (raw[indexA] < 0 && raw[indexB] < 0) return false;
}

const float SearchAlgorithmSimulatedAnnealing::getProbability(float deltaE, float tempAdjusted) {
	if (deltaE <= 0) return 1;
	return 1.0/ (1 + std::exp(-deltaE / tempAdjusted));
}

Schedule* SearchAlgorithmSimulatedAnnealing::getNeighborSchedule(Schedule* parent) {
	Schedule* cp = parent->copy();
	if (cp == nullptr) {
		printf("Null copy\n");
	}
	// Get two random indexes
	int indexA = rand() % (cp->getNumRooms() * cp->getNumTimeSlots());
	int indexB = rand() % (cp->getNumRooms() * cp->getNumTimeSlots());
	// TODO: Check that the result will be valid
	// Swap the indexes
	int courseTemp = cp->rawDataPointer()[indexA];
	cp->rawDataPointer()[indexA] = cp->rawDataPointer()[indexB];
	cp->rawDataPointer()[indexB] = courseTemp;
	return cp;
}

Schedule* SearchAlgorithmSimulatedAnnealing::solve(SchedulingProblem* problem, long deadline) {
	printf("Executing Simulated Annealing.\n");

	Schedule* scheduleCurrent = problem->getRandomSchedule();
	Schedule* scheduleNeighbor;

	float scoreCurrent = problem->evaluateSchedule(scheduleCurrent);

	if (scoreCurrent == -INFINITY){
		printf("Bad Initial Schedule.\n");
		return nullptr;
	}

	float scoreNeighbor;
	float scoreDelta;
	float temperature = 100;
	float alpha = 0.4; // Used for cooling

	short iterationsPerCoolingCycle = 5;
	short iterationCounter;

	using std::chrono::system_clock;
	using std::chrono::duration_cast;
	using std::chrono::milliseconds;

	deadline -= 10; // Save ms to return
	long currentTime;

	currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

	while (currentTime < deadline && temperature > 0) {

		for (iterationCounter = 0; iterationCounter < iterationsPerCoolingCycle; iterationCounter++) {
			// Get a random neighbor
			scheduleNeighbor = getNeighborSchedule(scheduleCurrent);
			scoreNeighbor = problem->evaluateSchedule(scheduleNeighbor);
			if (scoreNeighbor == -INFINITY){
				printf("Bad Schedule.\n");
				continue;
			}
			scoreDelta = scoreCurrent - scoreNeighbor;
			if (getProbability(scoreDelta, temperature/iterationCounter) > randFloat()) {
				scheduleCurrent->~Schedule();
				scheduleCurrent = scheduleNeighbor;
				scoreCurrent = scoreNeighbor;
			}
			temperature -= alpha;
		}

		// At the end of each cycle, update the time and temperature
		currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	}

	return scheduleCurrent;
}



