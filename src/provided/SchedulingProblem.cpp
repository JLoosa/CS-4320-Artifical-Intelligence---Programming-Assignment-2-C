/*
 * SchedulingProblem.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: Jacob
 */

#include "SchedulingProblem.hpp"

#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>

const int randInt(const int max) {
	return rand() % max;
}

const int randRange(const int min, const int max) {
	return min + (rand() % (max - min));
}

const float randFloat() {
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

SchedulingProblem::SchedulingProblem(long seed) {
	printf("Scheduling Problem has seed: %ld.\n", seed);
	if (seed > 0)
		srand(seed);
	else
		srand(static_cast<unsigned>(time(0)));

	nBuildings = 0;
	buildings = 0;

	nRooms = 0;
	rooms = 0;

	nCourses = 0;
	courses = 0;
}

void SchedulingProblem::createRandomInstance(int nBuildings, int nRooms,
		int nCourses) {
	printf("Scheduling Problem: Clearing old data.\n");
	// Clear the old data first
	if (this->nBuildings)
		free(buildings);
	if (this->nRooms)
		free(rooms);
	if (this->nCourses)
		free(courses);

	// Create the Buildings
	printf("Scheduling Problem: Creating %d buildings.\n", nBuildings);
	this->nBuildings = nBuildings;
	this->buildings = (Building*) malloc(nBuildings * sizeof(Building));
	for (int i = 0; i < nBuildings; i++) {
		float xCoord = randFloat() * fMaxXCoord;
		float yCoord = randFloat() * fMaxYCoord;
		Building building(xCoord, yCoord);
		buildings[i] = building;
	}

	// Create the Rooms
	printf("Scheduling Problem: Creating %d rooms.\n", nRooms);
	this->nRooms = nRooms;
	this->rooms = (Room*) malloc(nRooms * sizeof(Room));
	for (int i = 0; i < nRooms; i++) {
		Building *building = &buildings[randInt(nBuildings)];
		short capacity = randRange(30, 100);
		Room room(building, capacity);
		rooms[i] = room;
	}

	// Create the Courses
	printf("Scheduling Problem: Creating %d courses.\n", nCourses);
	this->nCourses = nCourses;
	this->courses = (Course*) malloc(nCourses * sizeof(Course));
	for (int i = 0; i < nCourses; i++) {
		float value = randFloat() * 100;
		Building *preferredLocation = &buildings[randInt(nBuildings)];
		float *timeSlotValues = (float*) malloc(nTimeSlots * sizeof(float));
		short enrolledStudents = randRange(30, 100);
		for (int j = 0; j < nTimeSlots; j++) {
			if (randFloat() < 0.3) {
				timeSlotValues[j] = 0;
			} else {
				timeSlotValues[j] = randFloat() * 10;
			}
		}
		Course course(value, preferredLocation, timeSlotValues,
				enrolledStudents);
		courses[i] = course;
	}
}

Schedule* SchedulingProblem::getEmptySchedule() {
	printf("Scheduling Problem: Creating empty schedule.\n");
	Schedule *schedule = new Schedule(nRooms, nTimeSlots);
	for (int r = 0; r < nRooms; r++) {
		for (int t = 0; t < nTimeSlots; t++) {
			schedule->setCourse(r, t, -1);
		}
	}
	return schedule;
}

float SchedulingProblem::evaluateSchedule(Schedule *schedule) {
	// Check Schedule Dimensions
	if (schedule->getNumRooms() != nRooms)
		return -INFINITY;
	if (schedule->getNumTimeSlots() != nTimeSlots)
		return -INFINITY;

	// Check that all classes are only assigned once
	bool assignedCourses[nCourses];
	std::memset(assignedCourses, false, nCourses);
	int courseIndex;
	for (int room = 0; room < nRooms; room++) {
		for (int time = 0; time < nTimeSlots; time++) {
			courseIndex = schedule->getCourse(room, time);
			// Skip over invalid classes
			if (courseIndex < 0 || courseIndex >= nCourses)
				continue;
			// Check for double assignment
			if (assignedCourses[courseIndex])
				return -INFINITY;
			assignedCourses[courseIndex] = true;
		}
	}

	// Begin computing the value
	float value = 0;
	Course *course;
	Room *room;
	Building *courseBuilding;
	Building *roomBuilding;
	for (int roomIndex = 0; roomIndex < nRooms; roomIndex++) {
		for (int time = 0; time < nTimeSlots; time++) {
			courseIndex = schedule->getCourse(roomIndex, time);
			// Skip over invalid classes
			if (courseIndex < 0 || courseIndex >= nCourses)
				continue;
			// Lookup the course object in memory
			course = &courses[courseIndex];
			// Check that the course was assigned a feasible time slot
			if (course->getTimeSlot(time) <= 0)
				continue;

			// Lookup the room object in memory
			room = &rooms[roomIndex];

			// Check that the room has enough capacity
			if (course->getEnrolledStudents() > room->getCapacity())
				continue;

			// Add the value for the class and time slot
			value += course->getValue();
			value += course->getTimeSlot(time);
			// Calculate the distance penalty
			courseBuilding = course->getPreferredBuilding();
			roomBuilding = room->getBuilding();

			float xDist = courseBuilding->getXCoord()
					- roomBuilding->getXCoord();
			xDist *= xDist;

			float yDist = courseBuilding->getYCoord()
					- roomBuilding->getYCoord();
			yDist *= yDist;

			value -= fDistancePenalty * sqrtf(xDist + yDist);
		}
	}
	return value;
}

const int SchedulingProblem::getNumBuildings() {
	return this->nBuildings;
}

Building* SchedulingProblem::getBuilding(int buildingIndex) {
	if (buildingIndex < 0 || buildingIndex >= nBuildings)
		return nullptr;
	return &buildings[buildingIndex];
}

const int SchedulingProblem::getNumRooms() {
	return this->nRooms;
}

Room* SchedulingProblem::getRoom(int roomIndex) {
	if (roomIndex < 0 || roomIndex >= nRooms)
		return nullptr;
	return &rooms[roomIndex];
}

const int SchedulingProblem::getNumCourses() {
	return this->nCourses;
}

Course* SchedulingProblem::getCourse(int courseIndex) {
	if (courseIndex < 0 || courseIndex >= nCourses)
		return nullptr;
	return &courses[courseIndex];
}