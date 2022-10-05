/*
 * attitudeManager.hpp
 *
 * Attitude Manager Header
 *
 *  Created on: May 24, 2022
 *      Author: Anthony (Anni) Luo
 */

#ifndef ATTITUDE_MANAGER_HPP
#define ATTITUDE_MANAGER_HPP

#include "../../LaminarOS/Interfaces/Inc/LOS_Link.hpp"
#include "../../LaminarOS/Interfaces/Inc/LOS_Actuators.hpp"
#include "AM_StateMgr.hpp"

class AttitudeState;

namespace AttMan {
// Gives status of attitude manager so we know when it has completed a cycle (its state is FetchInstructionsMode) or entered failure mode
enum _Attitude_Manager_Cycle_Status {
	COMPLETED_CYCLE = 0, IN_CYCLE, FAILURE_MODE
};
}

class AttitudeManager {
public:
	AttitudeManager(LOS_Link *link, LOS_Actuators *output);
	inline AttitudeState* getCurrentState() const { return currentState;}
	void execute();
	void setState(AttitudeState &newState);
	AttMan::_Attitude_Manager_Cycle_Status getStatus() { return status;}
	LOS_Link *link;
	LOS_Actuators *output;
private:
	AttitudeState *currentState;
	AttMan::_Attitude_Manager_Cycle_Status status;
	AttitudeManager();
};

#endif //ATTITUDE_MANAGER_HPP
