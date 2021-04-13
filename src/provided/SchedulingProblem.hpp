/*
 * SchedulingProblem.hpp
 *
 *  Created on: Apr 12, 2021
 *      Author: Jacob
 */
#include "Building.hpp"
#include "Course.hpp"
#include "Room.hpp"
#include "Schedule.hpp"

#ifndef PROVIDED_SCHEDULINGPROBLEM_HPP_
#define PROVIDED_SCHEDULINGPROBLEM_HPP_

class SchedulingProblem {

private:
	int nBuildings;
	Building *buildings;

	int nRooms;
	Room *rooms;

	int nCourses;
	Course *courses;

public:
	const int nTimeSlots = 10;
	const float fMaxXCoord = 10;
	const float fMaxYCoord = 10;
	const float fDistancePenalty = 2.5;

	SchedulingProblem(const long);

	void createRandomInstance(const int, const int, const int);

	Schedule* getEmptySchedule();

	float evaluateSchedule(Schedule*);

	const int getNumBuildings();

	Building* getBuilding(int);

	const int getNumRooms();

	Room* getRoom(int);

	const int getNumCourses() ;

	Course* getCourse(int);

};

#endif /* PROVIDED_SCHEDULINGPROBLEM_HPP_ */
