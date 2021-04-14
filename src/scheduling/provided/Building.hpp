/*
 * Building.hpp
 *
 *  Created on: Apr 12, 2021
 *      Author: Jacob
 */

#ifndef PROVIDED_BUILDING_HPP_
#define PROVIDED_BUILDING_HPP_

class Building {

private:
	float xCoord;
	float yCoord;

public:
	/**
	 * Constructor
	 */
	Building(float, float);

	float getXCoord() const;

	float getYCoord() const;

};

#endif /* PROVIDED_BUILDING_HPP_ */
