/*
 * attitudeStateClasses.cpp
 *
 * Attitude State-Machine Classes
 *
 *  Created on: May 24, 2022
 *      Author: Anthony (anni) Luo
 */

// TODO: this is one hefty file.
#include "../Inc/AM_states.hpp"
#include "../Inc/AM_DataTypes.hpp"
#include "../../LaminarOS/Interfaces/Inc/LOS_link.hpp"
#include "../../LaminarOS/Interfaces/Inc/LOS_Actuators.hpp"
#include "stm32f4xx_hal_gpio.h" // TODO: this should really be removed

#include "../../Controls/Inc/PID.hpp" // does not yet exist.

/*
 * Definitions
 */
float OutputMixingMode::_channel_out[4];
SFOutput_t SensorFusionMode::_sf_output;
PID_Output_t *ControlLoopMode::_pid_output;
Teleop_Instructions_t *_controls_instructions = new Teleop_Instructions_t();
bool FetchInstructionsMode::_is_autonomous = false;
uint8_t FetchInstructionsMode::_teleop_timeout_count;
uint8_t DisarmMode::_arm_disarm_ppm_val;
uint8_t DisarmMode::_arm_disarm_timeout_count;
Teleop_Instructions_t FetchInstructionsMode::_teleop_instructions;

/// SCREAMING for temporary definitions
uint8_t MAX_CHANNEL = 8;
uint8_t TIMEOUT_THRESHOLD = 2;
uint8_t MIN_ARM_VALUE = 50;

/*
 * Code
 */

/********************
 * FetchInstructions Mode
 ********************/

void FetchInstructionsMode::execute(AttitudeManager *attMgr) {
	const uint8_t TIMEOUT_THRESH = 2;
	FetchInstructionsMode::_is_autonomous = false;

	if (receiveTeleopInstructions(attMgr)) {
		_teleop_timeout_count = 0;
	} else {
		if (_teleop_timeout_count < TIMEOUT_THRESH) {
			_teleop_timeout_count++;
		}
	}

	if (_teleop_timeout_count < TIMEOUT_THRESHOLD) { // todo: add && !commsFailed()
		FetchInstructionsMode::_is_autonomous = false;
	} else {
		// abort due to teleop failure
		attMgr->setState(FatalFailureMode::getInstance());
	}
}

AttitudeState& FetchInstructionsMode::getInstance() {
	static FetchInstructionsMode singleton;
	return singleton;
}

bool FetchInstructionsMode::receiveTeleopInstructions(AttitudeManager *attMgr) {
	bool is_dc { true };

	if (is_dc) {
		return false;
	}

	for (int i = 0; i < MAX_CHANNEL; ++i) {
		_teleop_instructions.teleop_inp[i] = attMgr->link->get_input(i);
	}
	return true;
}

bool FetchInstructionsMode::isArmed() {
	bool retval = false;
	if (_teleop_instructions.is_armed >= MIN_ARM_VALUE) {
		retval = true;
	}
	return retval;
}

/********************
 * SensorFusion Mode
 ********************/

// todo: make this when we actually get SF
/********************
 * ControlLoop Mode
 ********************/

// TODO: uncomment out everything
void ControlLoopMode::execute(AttitudeManager *attMgr) {
	// SFOutput_t *SF_output = sensorFusionMode::getSFOutput();

	PID_Output_t *pid_out = nullptr;

	if (FetchInstructionsMode::isAutonomous()) {

	} else {
		Teleop_Instructions_t *_teleop_instructions =
				FetchInstructionsMode::getTeleopInstructions();
		// _pid_output = runControlsAndGetPWM(_teleop_instructions, SF_output);
	}

	attMgr->setState(OutputMixingMode::getInstance());
}

/********************
 * OutputMixing Mode
 ********************/

void OutputMixingMode::execute(AttitudeManager *attMgr) {
	PID_Output_t *PIDOutput = ControlLoopMode::getPIDOutput();

	// match types?
	attMgr->output->set(PIDOutput);
}

/********************
 * FatalFailure Mode
 ********************/

void FatalFailureMode::execute(AttitudeManager* attMgr)
{
    attMgr->setState(FatalFailureMode::getInstance());
}

AttitudeState& FatalFailureMode::getInstance()
{
    static FatalFailureMode singleton;
    return singleton;
}

