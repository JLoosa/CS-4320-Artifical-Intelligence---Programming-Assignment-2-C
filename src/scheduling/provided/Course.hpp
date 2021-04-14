/*
 * Course.hpp
 *
 *  Created on: Apr 12, 2021
 *      Author: Jacob
 */

class Building;

#ifndef PROVIDED_COURSE_HPP_
#define PROVIDED_COURSE_HPP_

class Course {

private:
	float value;
	Building *preferredLocation;
	float *timeSlotValues;
	short enrolledStudents;

public:

	Course(const float, Building*, float*, const short);

	float getValue();

	Building* getPreferredBuilding();

	float getTimeSlot(int);

	short getEnrolledStudents();

};

#endif /* PROVIDED_COURSE_HPP_ */
