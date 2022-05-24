/*
 * attitudeManager.hpp
 *
 * Attitude Manager Header
 *
 *  Created on: May 24, 2022
 *      Author: Anthony (Anni) Luo
 */

#ifndef ZP_PROTO_PORT_ATTITUDEMANAGER_HPP
#define ZP_PROTO_PORT_ATTITUDEMANAGER_HPP

#include "attitudeStateManager.hpp"
#include "../../LaminarOS/Interfaces/Inc/LOS_Link.hpp"

class attitudeState;

namespace AttMan {
    // Gives status of attitude manager so we know when it has completed a cycle (its state is FetchInstructionsMode) or entered failure mode
    enum _Attitude_Manager_Cycle_Status {COMPLETED_CYCLE = 0, IN_CYCLE, FAILURE_MODE};
}

class attitudeManager {
public:
    attitudeManager(PPMChannel *ppm, PWMChannel *pwm);
    inline attitudeState* getCurrentState() const {return currentState;}
    void execute();
    void setState(attitudeState& newState);
    AttMan::_Attitude_Manager_Cycle_Status getStatus() {return status;}
    PPMChannel *ppm;
    PWMChannel *pwm;
private:
    attitudeState* currentState;
    AttMan::_Attitude_Manager_Cycle_Status status;
    attitudeManager();
};

#endif //ZP_PROTO_PORT_ATTITUDEMANAGER_HPP
