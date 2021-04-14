/*
 * SearchAlgorithmNaive.hpp
 *
 *  Created on: Apr 13, 2021
 *      Author: Jacob
 */

#include "SearchAlgorithm.hpp"

class Schedule;
class SchedulingProblem;

#ifndef PROVIDED_SEARCHALGORITHMNAIVE_HPP_
#define PROVIDED_SEARCHALGORITHMNAIVE_HPP_

class SearchAlgorithmNaive: public SearchAlgorithm {

	Schedule* solve(SchedulingProblem*, long);

	~SearchAlgorithmNaive();

};

#endif /* PROVIDED_SEARCHALGORITHMNAIVE_HPP_ */
