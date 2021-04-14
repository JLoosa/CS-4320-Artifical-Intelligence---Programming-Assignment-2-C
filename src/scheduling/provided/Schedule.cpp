/*
 * Schedule.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: Jacob
 */

#include "Schedule.hpp"

#include <string.h>

Schedule::Schedule(const int nRooms, const int nTimeSlots) :
		schedule ( new int[nRooms * nTimeSlots] ) {
	this->nRooms = nRooms;
	this->nTimeSlots = nTimeSlots;
}

const int Schedule::getArrayIndex(const int room, const int timeSlot) {
	if (room < 0 || timeSlot < 0)
		return -1;
	if (room >= nRooms || timeSlot >= nTimeSlots)
		return -1;
	return room * nTimeSlots + timeSlot;
}

const int Schedule::getCourse(const int room, const int timeSlot) {
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

const int Schedule::getNumRooms() {
	return this->nRooms;
}

const int Schedule::getNumTimeSlots() {
	return this->nTimeSlots;
}

void Schedule::reset() {
	for (int i = nRooms * nTimeSlots-1; i >= 0; i--) schedule[i] = -1;
}

Schedule* Schedule::copy() {
	Schedule* cp = new Schedule(nRooms, nTimeSlots);
	memcpy(cp->schedule.get(), schedule.get(), nRooms*nTimeSlots);
	return cp;
}

int* Schedule::rawDataPointer() {
	return schedule.get();
}
