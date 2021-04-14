/*
 * Building.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: Jacob
 */

#include "Building.hpp"

Building::Building(float xCoord, float yCoord) {
	this->xCoord = xCoord;
	this->yCoord = yCoord;
}

float Building::getXCoord() const {
	return this->xCoord;
}

float Building::getYCoord() const {
	return this->yCoord;
}
