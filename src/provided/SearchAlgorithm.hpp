/*
 * SearchAlgorithm.hpp
 *
 *  Created on: Apr 13, 2021
 *      Author: Jacob
 */
#include "SchedulingProblem.hpp"
#include "Schedule.hpp"
#include <chrono>

#ifndef PROVIDED_SEARCHALGORITHM_HPP_
#define PROVIDED_SEARCHALGORITHM_HPP_

class SearchAlgorithm {

public:

	virtual Schedule* solve(SchedulingProblem*, long) { return nullptr; };

	virtual ~SearchAlgorithm() {};

};

#endif /* PROVIDED_SEARCHALGORITHM_HPP_ */
