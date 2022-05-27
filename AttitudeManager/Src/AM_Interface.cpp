/*
 * attitudeManagerInterface.cpp
 *
 * Interface for Attman (needed for rtos)
 *
 *  Created on: May 24, 2022
 *      Author: Anthony (Anni) Luo
 */

#include "../Inc/AM_Interface.h"

#include "../Inc/AM.hpp"

attitudeManager *attMng;
LOS_Link *link;
LOS_Actuators *output;
//PPMChannel *ppm;
//PWMChannel *pwm;

void attitudeManagerInterfaceInit(void) {
   link = new LOS_Link(MAX_PPM_CHANNELS);
   output = new LOS_Actuators();
   attMng = new attitudeManager(link, output);
}

void attitudeManagerInterfaceExecute(void) {
   attMng->execute();
}
