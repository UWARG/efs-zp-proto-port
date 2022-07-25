
#include "../Inc/TM.hpp"

TelemetryManager::TelemetryManager()
{
    //currentState = &InitialMode::getInstance();
    status = TelemMan::COMPLETED_CYCLE;
}


void TelemetryManager::setState(TelemetryState& newState) {
    currentState->exit(this);
    currentState = &newState;

    /*if(*currentState==InitialMode::getInstance()) {
        status=TelemMan::COMPLETED_CYCLE;
    }
    else if(*currentState==failureMode::getInstance()) {
        status=TelemMan::FAILURE_MODE;
    }
    else {
        status=TelemMan::IN_CYCLE;
    }*/

    currentState -> enter(this);
}
