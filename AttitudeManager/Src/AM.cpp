//
// Created by Anthony Luo on 2022-05-24.
//

#include "../Inc/AM.hpp"

#include "../Inc/AM_States.hpp"

#include "../Inc/AM_Interface.h"

AttitudeManager::AttitudeManager(LOS_Link *los_link,
		LOS_Actuators *los_output) {
	currentState = &FetchInstructionsMode::getInstance();
	status = AttMan::COMPLETED_CYCLE;
	link = los_link;
	output = los_output;
}

void AttitudeManager::setState(AttitudeState &newState) {
	currentState->exit(this);
	currentState = &newState;

	// Changes status variable so we can easily check if attitude manager has completed a cycle or not
	if (*currentState == FetchInstructionsMode::getInstance()) {
		status = AttMan::COMPLETED_CYCLE;
	} else if (*currentState == FatalFailureMode::getInstance()) {
		status = AttMan::FAILURE_MODE;
	} else {
		status = AttMan::IN_CYCLE;
	}

	currentState->enter(this);
}

void AttitudeManager::execute() {
    currentState->execute(this);
}
