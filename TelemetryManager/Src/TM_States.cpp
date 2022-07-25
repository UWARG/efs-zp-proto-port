#include "../Inc/TM_states.hpp"

void InitialMode::execute(TelemetryManager* telemMgr)
{
    // TODO: Start listening with interrupt enabled
	telemMgr -> setState(GetFromFWMode::getInstance());
}

TelemetryState& InitialMode::getInstance() {
    static InitialMode singleton;
    return singleton;
}


void GetFromFWMode::execute(TelemetryManager* telemMgr)
{
    // TODO: Get data from other tasks
	telemMgr -> setState(GetFromCVMode::getInstance());
}

TelemetryState& GetFromFWMode::getInstance() {
    static GetFromFWMode singleton;
    return singleton;
}

void GetFromCVMode::execute(TelemetryManager* telemMgr)
{
    // TODO: Get data from CV
	telemMgr -> setState(GetFromGroundMode::getInstance());
}

TelemetryState& GetFromCVMode::getInstance() {
    static GetFromCVMode singleton;
    return singleton;
}

void GetFromGroundMode::execute(TelemetryManager* telemMgr)
{
    // TODO: Get data from ground
	telemMgr -> setState(SendToFWMode::getInstance());
}

TelemetryState& GetFromGroundMode::getInstance() {
    static GetFromGroundMode singleton;
    return singleton;
}


void SendToFWMode::execute(TelemetryManager* telemMgr)
{
    // TODO: Send data to other tasks
	telemMgr -> setState(SendToFWMode::getInstance());
}

TelemetryState& SendToFWMode::getInstance() {
    static SendToFWMode singleton;
    return singleton;
}

void SendToCVMode::execute(TelemetryManager* telemMgr)
{
    // TODO: Send data to CV
	telemMgr -> setState(SendToGroundMode::getInstance());
}

TelemetryState& SendToCVMode::getInstance() {
    static SendToCVMode singleton;
    return singleton;
}

void SendToGroundMode::execute(TelemetryManager* telemMgr)
{
    // TODO: Send data to ground
	telemMgr -> setState(GetFromFWMode::getInstance());
}

TelemetryState& SendToGroundMode::getInstance() {
    static SendToCVMode singleton;
    return singleton;
}
