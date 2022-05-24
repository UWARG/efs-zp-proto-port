/*
 * attitudeManagerInterface.cpp
 *
 * Interface for Attman (needed for rtos)
 *
 *  Created on: May 24, 2022
 *      Author: Anthony (Anni) Luo
 */

#include "../Inc/AttitudeManagerInterface.h"
#include "../Inc/AttitudeManager.hpp"

attitudeManager *attMng;
PPMChannel *ppm;
PWMChannel *pwm;

void attitudeManagerInterfaceInit(void) {
    ppm = new PPMChannel(MAX_PPM_CHANNELS);
    pwm = new PWMChannel();
    attMng = new attitudeManager(ppm, pwm);
}

void attitudeManagerInterfaceExecute(void) {
    attMng->execute();
}