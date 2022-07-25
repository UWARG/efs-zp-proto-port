
#include "../Inc/TM.hpp"
#include "../Inc/TM_States.hpp"

TelemetryManager::TelemetryManager(LOS_Telem *los_telem, LOS_Comms *los_comms)
{
    //currentState = &InitialMode::getInstance();
    status = TelemMan::COMPLETED_CYCLE;
    telem = los_telem;
    comms = los_comms;
}


void TelemetryManager::setState(TelemetryState& newState) {
    currentState->exit(this);
    currentState = &newState;

    if(*currentState==GetFromFWMode::getInstance()) {
        status=TelemMan::COMPLETED_CYCLE;
    }
    else if(*currentState==FailureMode::getInstance()) {
        status=TelemMan::FAILURE_MODE;
    }
    else {
        status=TelemMan::IN_CYCLE;
    }

    currentState -> enter(this);
}
