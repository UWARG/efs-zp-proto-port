#ifndef TM_STATES_HPP
#define TM_STATES_HPP

#include "TM_StateMgr.hpp"

class InitialMode: public TelemetryState {
public:
	void enter(TelemetryManager *telemMgr) {(void) telemMgr;}
	void execute(TelemetryManager *telemMgr);
	void exit(TelemetryManager *telemMgr) {(void) telemMgr;}
	static TelemetryState& getInstance();
};

class GetFromFWMode: public TelemetryState {
public:
	void enter(TelemetryManager *telemMgr) {(void) telemMgr;}
	void execute(TelemetryManager *telemMgr);
	void exit(TelemetryManager *telemMgr) {(void) telemMgr;}
	static TelemetryState& getInstance();
};

class GetFromCVMode: public TelemetryState {
public:
	void enter(TelemetryManager *telemMgr) {(void) telemMgr;}
	void execute(TelemetryManager *telemMgr);
	void exit(TelemetryManager *telemMgr) {(void) telemMgr;}
	static TelemetryState& getInstance();
};

class GetFromGroundMode: public TelemetryState {
public:
	void enter(TelemetryManager *telemMgr) {(void) telemMgr;}
	void execute(TelemetryManager *telemMgr);
	void exit(TelemetryManager *telemMgr) {(void) telemMgr;}
	static TelemetryState& getInstance();
};

class SendToFWMode: public TelemetryState {
public:
	void enter(TelemetryManager *telemMgr) {(void) telemMgr;}
	void execute(TelemetryManager *telemMgr);
	void exit(TelemetryManager *telemMgr) {(void) telemMgr;}
	static TelemetryState& getInstance();
};

class SendToCVMode: public TelemetryState {
public:
	void enter(TelemetryManager *telemMgr) {(void) telemMgr;}
	void execute(TelemetryManager *telemMgr);
	void exit(TelemetryManager *telemMgr) {(void) telemMgr;}
	static TelemetryState& getInstance();
};

class SendToGroundMode: public TelemetryState {
public:
	void enter(TelemetryManager *telemMgr) {(void) telemMgr;}
	void execute(TelemetryManager *telemMgr);
	void exit(TelemetryManager *telemMgr) {(void) telemMgr;}
	static TelemetryState& getInstance();
};

class FailureMode: public TelemetryState {
public:
	void enter(TelemetryManager *telemMgr) {(void) telemMgr;}
	void execute(TelemetryManager *telemMgr);
	void exit(TelemetryManager *telemMgr) {(void) telemMgr;}
	static TelemetryState& getInstance();
};
#endif // TM_STATES_HPP
