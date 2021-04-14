/*
 * Schedule.hpp
 *
 *  Created on: Apr 12, 2021
 *      Author: Jacob
 */

#include <memory>

#ifndef PROVIDED_SCHEDULE_HPP_
#define PROVIDED_SCHEDULE_HPP_

class Schedule {

private:
	int nRooms;
	int nTimeSlots;
	std::unique_ptr<int[]> schedule;

	const int getArrayIndex(const int, const int);

public:
	Schedule(const int, const int);

	const int getCourse(const int, const int);

	bool setCourse(const int, const int, const int);

	const int getNumRooms();

	const int getNumTimeSlots() ;

	void reset();

	Schedule* copy();

	int* rawDataPointer();

};

#endif /* PROVIDED_SCHEDULE_HPP_ */
