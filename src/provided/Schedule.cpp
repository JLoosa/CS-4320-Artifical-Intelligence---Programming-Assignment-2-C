/*
 * Schedule.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: Jacob
 */

#include "Schedule.hpp"
#include <memory>

Schedule::Schedule(const int nRooms, const int nTimeSlots)
: schedule{new int[nRooms * nTimeSlots]}
{
	this->nRooms = nRooms;
	this->nTimeSlots = nTimeSlots;
}

int Schedule::getArrayIndex(const int room, const int timeSlot) const {
	if (room < 0 || timeSlot < 0)
		return -1;
	if (room >= nRooms || timeSlot >= nTimeSlots)
		return -1;
	return room * nTimeSlots + timeSlot;
}

int Schedule::getCourse(const int room, const int timeSlot) const {
	int slot = getArrayIndex(room, timeSlot);
	if (slot == -1)
		return -1;
	return this->schedule[slot];
}

bool Schedule::setCourse(const int room, const int timeSlot, const int course) {
	int slot = getArrayIndex(room, timeSlot);
	if (slot == -1)
		return false;
	this->schedule[slot] = course;
	return true;
}

int Schedule::getNumRooms() const {
	return this->nRooms;
}

int Schedule::getNumTimeSlots() const {
	return this->nTimeSlots;
}
