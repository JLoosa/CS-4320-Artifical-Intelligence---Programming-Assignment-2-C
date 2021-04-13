/*
 * Room.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: Jacob
 */

#include "Room.hpp"

Room::Room(Building *building, short capacity) {
	this->building = building;
	this->capacity = capacity;
}

Building* Room::getBuilding() const {
	return this->building;
}

short Room::getCapacity() const {
	return this->capacity;
}
