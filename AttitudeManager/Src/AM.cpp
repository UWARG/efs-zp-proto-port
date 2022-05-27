//
// Created by Anthony Luo on 2022-05-24.
//

#include "../Inc/AM.hpp"

#include "../Inc/AM_States.hpp"

//attitudeManager::attitudeManager(PPMChannel *ppmChannel, PWMChannel *pwmChannel) {
//    currentState = &fetchInstructionsMode::getInstance();
//    status = AttMan::COMPLETED_CYCLE;
//    ppm = ppmChannel;
//    pwm = pwmChannel;
//}

void AttitudeManager::setState(AttitudeState &newState) {
//    currentState->exit(this);
//    currentState = &newState;
//
//    // Changes status variable so we can easily check if attitude manager has completed a cycle or not
//    if (*currentState == fetchInstructionsMode::getInstance()) {
//        status = AttMan::COMPLETED_CYCLE;
//    } else if (*currentState == FatalFailureMode::getInstance()) {
//        status = AttMan::FAILURE_MODE;
//    } else {
//        status = AttMan::IN_CYCLE;
//    }
//
//    currentState->enter(this);
}

void AttitudeManager::execute() {
//    currentState->execute(this);
}
