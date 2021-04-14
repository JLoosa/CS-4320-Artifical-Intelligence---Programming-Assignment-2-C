/*
 * SearchAlgorithmSimulatedAnnealing.hpp
 *
 *  Created on: Apr 13, 2021
 *      Author: Jacob
 */
#include "provided/SearchAlgorithm.hpp"
#include "provided/SchedulingProblem.hpp"

#ifndef JLoosaSearchAlgorithmSimulatedAneallingHPP
#define JLoosaSearchAlgorithmSimulatedAneallingHPP

class SearchAlgorithmSimulatedAnnealing : public SearchAlgorithm {

private:
	Schedule* getNeighborSchedule(Schedule*);

	/**
	 * Calculates the acceptance probability for a given delta and temperature
	 */
	const float getProbability(float, float);

	/**
	 * Checks if swapping two locations in the schedule returns a valid configuration
	 */
	const bool isSwapValid(Schedule*, const int, const int);


public:
	Schedule* solve(SchedulingProblem*, long);

};




#endif /* JLoosaSearchAlgorithmSimulatedAneallingHPP */
