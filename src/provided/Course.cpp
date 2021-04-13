/*
 * Course.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: Jacob
 */

#include "Course.hpp"

Course::Course(const float value, Building *preferredLocation,
		float *timeSlotValues, const short enrolledStudents) {
	this->value = value;
	this->preferredLocation = preferredLocation;
	this->timeSlotValues = timeSlotValues;
	this->enrolledStudents = enrolledStudents;
}

float Course::getValue() {
	return this->value;
}

Building* Course::getPreferredBuilding() {
	return this->preferredLocation;
}

float Course::getTimeSlot(int timeslot) {
	if (timeslot < 0 || timeslot >= 10)
		return (float) -1;
	return this->timeSlotValues[timeslot];
}

short Course::getEnrolledStudents() {
	return this->enrolledStudents;
}

