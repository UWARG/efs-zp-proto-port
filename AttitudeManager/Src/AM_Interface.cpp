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

AttitudeManager *attMng;
LOS_Link *link;
LOS_Actuators *output;
//PPMChannel *ppm;
//PWMChannel *pwm;

void AM_interfaceInit(void) {
	link = new LOS_Link(8);
	output = new LOS_Actuators();
	attMng = new AttitudeManager(link, output);
}

void AM_interfaceExecute(void) {
	attMng->execute();
	//int x = 5;
	//int y = x + 5;
}
