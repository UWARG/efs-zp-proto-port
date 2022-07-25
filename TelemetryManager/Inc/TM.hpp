#ifndef TM_HPP
#define TM_HPP

#include "TM_StateMgr.hpp"

class TelemetryState;

namespace TelemMan {
	enum _Telemetry_Manager_Cycle_Status {COMPLETED_CYCLE=0, IN_CYCLE, FAILURE_MODE};
}

class TelemetryManager {
public:
	TelemetryManager();
	inline TelemetryState* getCurrentState() const{return currentState;}
	void setState(TelemetryState& newState);
	TelemMan::_Telemetry_Manager_Cycle_Status getStatus() {return status;}
    //LOS_Telem *telem;
    //LOS_Comms *comms;
private:
	TelemetryState* currentState;
	TelemMan::_Telemetry_Manager_Cycle_Status status;
};

#endif // TM_HPP
