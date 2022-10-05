/*
 * attitudeDataTypes.hpp
 *
 * Data Types for Attitude Manager
 *
 *  Created on: May 24, 2022
 *      Author: Anthony (Anni) Luo
 */

#ifndef ATTITUDE_DATATYPES_HPP
#define ATTITUDE_DATATYPES_HPP

#include <cstdint>
#include "../../Interfaces/Inc/interface_datatypes.hpp"

// Output of the PID module and input to the OutputMixing module
//typedef struct
//{
//    float frontLeftMotorPercent;
//    float frontRightMotorPercent;
//    float backLeftMotorPercent;
//    float backRightMotorPercent;
//
//} PID_Output_t;

/*
typedef struct {
	float roll, pitch, yaw; //Degrees. Yaw of 180 is north.
	float rollRate, pitchRate, yawRate; //Degrees/second
	float airspeed; //m/s
	float altitude; //m
	float rateOfClimb; //m/s
	long double latitude; //Decimal degrees
	float latitudeSpeed; //m/s
	long double longitude; //Decimal degrees
	float longitudeSpeed; //m/s
	double track; //Degrees. Track of 0 is north.
	float groundSpeed; //m/s
	double heading; //Degrees. Heading of 0 is north.
} SFOutput_t;
*/

typedef struct Output_Mix_t {
	float channel[4];
};

constexpr static uint8_t FRONT_LEFT_MOTOR_CHANNEL { 0 };
constexpr static uint8_t FRONT_RIGHT_MOTOR_CHANNEL { 1 };
constexpr static uint8_t BACK_LEFT_MOTOR_CHANNEL { 2 };
constexpr static uint8_t BACK_RIGHT_MOTOR_CHANNEL { 3 };
constexpr static uint8_t LEFT_GIMBAL { 4 };
constexpr static uint8_t RIGHT_GIMBAL { 5 };
constexpr static uint8_t GRABBER_MOUTH_M1A { 6 };
constexpr static uint8_t GRABBER_MOUTH_M1B { 7 };

constexpr static uint8_t NUM_PWM_CHANNELS { 10 }; // 4 motors plus two actuators for gimbal, and four for grabber

/*
 Commented out for now to allow for just quadcopter channel mapping
 */

// #ifdef SPIKE
//     constexpr static uint8_t L_TAIL_OUT_CHANNEL {0}; // Spike has ruddervators
//     constexpr static uint8_t R_TAIL_OUT_CHANNEL {1};
// #else
//     constexpr static uint8_t ELEVATOR_OUT_CHANNEL {0};
//     constexpr static uint8_t RUDDER_OUT_CHANNEL {1};
// #endif
// constexpr static uint8_t AILERON_OUT_CHANNEL {2};
// constexpr static uint8_t THROTTLE_OUT_CHANNEL {3};
// constexpr static uint8_t NUM_PWM_CHANNELS {8};
#endif //ATTITUDE_DATATYPES_HPP
