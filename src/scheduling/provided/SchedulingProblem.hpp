/*
 * SchedulingProblem.hpp
 *
 *  Created on: Apr 12, 2021
 *      Author: Jacob
 */
class Building;
class Course;
class Room;
class Schedule;

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

	Schedule* getRandomSchedule();

	float evaluateSchedule(Schedule*);

	const int getNumBuildings();

	Building* getBuilding(int);

	const int getNumRooms();

	Room* getRoom(int);

	const int getNumCourses();

	Course* getCourse(int);

};

#endif /* PROVIDED_SCHEDULINGPROBLEM_HPP_ */
