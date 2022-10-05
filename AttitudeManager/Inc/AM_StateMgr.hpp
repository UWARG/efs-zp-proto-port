/*
 * attitudeStateManager.hpp
 *
 * Attitude State-Machine Header
 *
 *  Created on: May 24, 2022
 *      Author: Anthony (Anni) Luo
 */

#ifndef ATTITUDE_STATE_MANAGER_HPP
#define ATTITUDE_STATE_MANAGER_HPP

#include "AM.hpp"

class AttitudeManager;

class AttitudeState {
public:
	virtual void enter(AttitudeManager *attitudeMgr) = 0;
	virtual void execute(AttitudeManager *attitudeMgr) = 0;
	virtual void exit(AttitudeManager *attitudeMgr) = 0;

	bool operator==(const AttitudeState &rhs) const {return (this == &rhs);}

	virtual ~AttitudeState() {}

};

#endif //ATTITUDE_STATE_MANAGER_HPP
