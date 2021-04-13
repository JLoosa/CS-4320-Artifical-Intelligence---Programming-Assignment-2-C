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

	int getArrayIndex(const int, const int) const;

public:
	Schedule(const int, const int);

	int getCourse(const int, const int) const;

	bool setCourse(const int, const int, const int);

	int getNumRooms() const;

	int getNumTimeSlots() const;

};

#endif /* PROVIDED_SCHEDULE_HPP_ */
