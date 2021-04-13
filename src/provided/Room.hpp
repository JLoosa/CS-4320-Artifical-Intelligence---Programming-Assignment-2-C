/*
 * Room.hpp
 *
 *  Created on: Apr 12, 2021
 *      Author: Jacob
 */

#include "Building.hpp"

#ifndef PROVIDED_ROOM_HPP_
#define PROVIDED_ROOM_HPP_

class Room {

private:
	Building* building;
	short capacity;

public:

	Room(Building*, short);

	Building* getBuilding() const;

	short getCapacity() const;

};

#endif /* PROVIDED_ROOM_HPP_ */
