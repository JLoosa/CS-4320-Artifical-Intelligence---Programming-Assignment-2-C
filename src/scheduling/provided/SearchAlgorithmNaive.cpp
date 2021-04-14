/*
 * SearchAlgorithmNaive.cpp
 *
 *  Created on: Apr 13, 2021
 *      Author: Jacob
 */

#include "SearchAlgorithmNaive.hpp"

#include <stdio.h>

#include "Course.hpp"
#include "Schedule.hpp"
#include "SchedulingProblem.hpp"

Schedule* SearchAlgorithmNaive::solve(SchedulingProblem *problem,
		long deadline) {
	printf("Executing Naive Baseline.\n");
	Schedule *schedule = problem->getEmptySchedule();
	Course *course;
	bool scheduled;
	for (int courseIndex = 1; courseIndex < problem->getNumCourses();
			courseIndex++) {
		course = problem->getCourse(courseIndex);
		scheduled = false;
		for (int time = 0; time < problem->nTimeSlots; time++) {
			if (scheduled)
				break;
			if (course->getTimeSlot(time) > 0) {
				for (int roomIndex = 0; roomIndex < problem->getNumRooms();
						roomIndex++) {
					if (schedule->getCourse(roomIndex, time) < 0) {
						scheduled = schedule->setCourse(roomIndex, time,
								courseIndex);
						if (scheduled)
							break;
					}
				}
			}
		}
	}

	return schedule;
}

SearchAlgorithmNaive::~SearchAlgorithmNaive() {
}
