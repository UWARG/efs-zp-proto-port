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

class attitudeState;

namespace AttMan {
    // Gives status of attitude manager so we know when it has completed a cycle (its state is FetchInstructionsMode) or entered failure mode
    enum _Attitude_Manager_Cycle_Status {COMPLETED_CYCLE = 0, IN_CYCLE, FAILURE_MODE};
}

class attitudeManager {
public:
   attitudeManager(LOS_Link *link, LOS_Actuators *output);
    inline attitudeState* getCurrentState() const {return currentState;}
    void execute();
    void setState(attitudeState& newState);
    AttMan::_Attitude_Manager_Cycle_Status getStatus() {return status;}
   LOS_Link *link;
   LOS_Actuators *output;
private:
    attitudeState* currentState;
    AttMan::_Attitude_Manager_Cycle_Status status;
    attitudeManager();
};

#endif //ATTITUDE_MANAGER_HPP
