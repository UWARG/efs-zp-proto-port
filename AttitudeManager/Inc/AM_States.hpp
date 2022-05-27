/*
 * attitudeManager.cpp
 *
 *  Created on: May 24, 2022
 *      Author: Anthony (Anni) Luo
 */

#ifndef ATTITUDE_STATE_CLASSES_HPP
#define ATTITUDE_STATE_CLASSES_HPP

#include "../../Interfaces/Inc/interface_datatypes.hpp"

class fetchInstructionsMode : public attitudeState {
    public:
        void enter(attitudeManager *attMgr) {(void) attMgr;}
        void execute(attitudeManager *attMgr);
        void exit(attitudeManager *attMgr) {(void) attMgr;}
        static attitudeState& getInstance();
        static Teleop_Instructions_t *getTeleopInstructions(void) {return &_teleop_instructions};
    private:
        fetchInstructionsMode() {
            // to be implemented
        }
        fetchInstructionsMode(const fetchInstructionsMode& other);
        fetchInstructionsMode& operator =(const fetchInstructionsMode& other);
        static bool ReceiveTeleopInstructions(attitudeManager* attitudeMgr);
        static bool isArmed();
        static Teleop_Instructions_t _teleop_instructions;
        static bool _isAutonomous;
        static uint8_t teleop_timeout_count;
}

#endif //ATTITUDE_STATE_CLASSES_HPP
