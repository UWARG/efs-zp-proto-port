//
// Created by antho on 10/27/2021.
//

#ifndef ZEROPILOT_SW_CONTROLS_H
#define ZEROPILOT_SW_CONTROLS_H

#include "../../SensorFusion/Inc/SensorFusion.hpp"
#include "../../AttitudeManager/Inc/AM_DataTypes.hpp"

// static volatile global position.
// follows formats from SFOutput_t

struct PositionTargets{
    long double latitude, longitude;    //meters from where we started originally
    float altitude;                     // meters above start point (hopefully the ground?)
    double heading;                     // degree from true north, cw
};

struct StickDistance{
    float f_stick, lr_stick;
    float a_stick;
    float h_stick;
};

struct Instructions_t{
    float input1;
    float input2;
    float input3;
    float input4;
};

/**
 * @brief Translates PPM Signals into linear stick distances.
 *
 * @param instructions outputs from PPM driver
 * @return StickDistance*
 */
StickDistance *translatePPM(Instructions_t *instructions);

/**
 * @brief Updates targets to fly to
 *
 * @param stick StickDistances from translatePPM
 */
void updateTargets(StickDistance *stick);

/**
 * @brief Updates current position from SF.
 *
 */
void updatePosition();

/**
 * @brief N/A. To be used when Controls is threaded
 *
 */
void evalControls();

/**
 * @brief Main Entry point to run controls under single threaded AM model.
 *
 * @param instructions instructions, raw from PPM driver.
 * @param SF_pos Current SF position
 * @return PID_Output_t*
 */
PID_Output_t *runControlsAndGetPWM(Instructions_t * instructions, SFOutput_t * SF_pos);


#endif //ZEROPILOT_SW_CONTROLS_H
