/*
 * attitudeManager.cpp
 *
 *  Created on: May 24, 2022
 *      Author: Anthony (Anni) Luo
 */

#ifndef ATTITUDE_STATE_CLASSES_HPP
#define ATTITUDE_STATE_CLASSES_HPP

#include "../../Interfaces/Inc/interface_datatypes.hpp"
#include "AM_DataTypes.hpp"
#include "AM_StateMgr.hpp"
#include "../../SensorFusion/Inc/SensorFusion.hpp"

class FetchInstructionsMode: public AttitudeState {
public:
	void enter(AttitudeManager *attMgr) {(void) attMgr;}
	void execute(AttitudeManager *attMgr);
	void exit(AttitudeManager *attMgr) {(void) attMgr;}
	static AttitudeState& getInstance();
	static bool isAutonomous(void) {return FetchInstructionsMode::_is_autonomous;}
	static Teleop_Instructions_t* getTeleopInstructions(void) {return &_teleop_instructions;}
private:
	FetchInstructionsMode() {
		// to be implemented
	}
	FetchInstructionsMode(const FetchInstructionsMode &other);
	FetchInstructionsMode& operator =(const FetchInstructionsMode &other);
	static bool receiveTeleopInstructions(AttitudeManager *attitudeMgr);
	static bool isArmed();
	static Teleop_Instructions_t _teleop_instructions;
	static bool _is_autonomous;
	static uint8_t _teleop_timeout_count;
};

class SensorFusionMode: public AttitudeState {
public:
	void enter(AttitudeManager *attMgr) {(void) attMgr;}
	void execute(AttitudeManager *attMgr);
	void exit(AttitudeManager *attMgr) {(void) attMgr;}
	static AttitudeState& getInstance();
	static SFOutput_t* getSFOutput(void) {return &_sf_output;}
private:
	SensorFusionMode() {SF_Init();}
	SensorFusionMode(const SensorFusionMode &other);
	SensorFusionMode& operator =(const SensorFusionMode &other);
	static SFOutput_t _sf_output;
};

class ControlLoopMode: public AttitudeState {
	// used to be PIDLoopMode
public:
	void enter(AttitudeManager *attMgr) {(void) attMgr;}
	void execute(AttitudeManager *attMgr);
	void exit(AttitudeManager *attMgr) {(void) attMgr;}
	static AttitudeState& getInstance();
	static PID_Output_t *getPIDOutput(void) {return _pid_output;}
private:
	ControlLoopMode() {}
	ControlLoopMode(const ControlLoopMode& other);
	ControlLoopMode& operator = (const ControlLoopMode& other);
//	PIDController _rollPid{ROLL_PID_KP, ROLL_PID_KI, ROLL_PID_KD, ROLL_PID_INTEGRAL_MAX, ROLL_PID_MIN, ROLL_PID_MAX}; // Proportional, integral, derivative, min, max
//	PIDController _pitchPid{PITCH_PID_KP, PITCH_PID_KI, PITCH_PID_KD, PITCH_PID_INTEGRAL_MAX, PITCH_PID_MIN, PITCH_PID_MAX};
//	PIDController _yawPid{YAW_PID_KP, YAW_PID_KI, YAW_PID_KD, YAW_PID_INTEGRAL_MAX, YAW_PID_MIN, YAW_PID_MAX};
//	PIDController _airspeedPid{AIRSPEED_PID_KP, AIRSPEED_PID_KI, AIRSPEED_PID_KD, AIRSPEED_PID_INTEGRAL_MAX, AIRSPEED_PID_MIN, AIRSPEED_PID_MAX};
	static PID_Output_t *_pid_output;
};

class OutputMixingMode : public AttitudeState {
public:
	void enter(AttitudeManager *attMgr) {(void) attMgr;}
	void execute(AttitudeManager *attMgr);
	void exit(AttitudeManager *attMgr) {(void) attMgr;}
	static AttitudeState& getInstance();
	static float * GetChannelOut(void) {return _channel_out;}
private:
	OutputMixingMode() {}
	OutputMixingMode(const OutputMixingMode& other);
	OutputMixingMode& operator = (const OutputMixingMode& other);
	static float _channel_out[4]; // FIXME: make this a data structure somewhere.
};

class FatalFailureMode : public AttitudeState {
public:
	void enter(AttitudeManager *attMgr) {(void) attMgr;}
	void execute(AttitudeManager *attMgr);
	void exit(AttitudeManager *attMgr) {(void) attMgr;}
	static AttitudeState& getInstance();
private:
	FatalFailureMode() {}
	FatalFailureMode(const FatalFailureMode& other);
	FatalFailureMode& operator =(const FatalFailureMode& other);
};

class DisarmMode : public AttitudeState {
public:
	void enter(AttitudeManager *attMgr) {(void) attMgr;}
	void execute(AttitudeManager *attMgr);
	void exit(AttitudeManager *attMgr) {(void) attMgr;}
	static AttitudeState& getInstance();
private:
	DisarmMode() {}
	DisarmMode(const DisarmMode& other);
	DisarmMode& operator = (const DisarmMode& other);
	static bool ReceieveArmDisarmInstruction(AttitudeManager *attMgr);
	static bool isArmed();
	static uint8_t _arm_disarm_ppm_val;
	static uint8_t _arm_disarm_timeout_count;
};
#endif //ATTITUDE_STATE_CLASSES_HPP
