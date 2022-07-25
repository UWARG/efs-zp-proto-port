#include "../Inc/TM_states.hpp"
#include "../Inc/TM_DataTypes.hpp"

void InitialMode::execute(TelemetryManager* telemMgr)
{
	telemMgr->comms->init_FW_CV_comms();
	telemMgr->comms->init_TM_AM_comms();
	telemMgr->telem->init_telemetry();
	telemMgr -> setState(GetFromFWMode::getInstance());
}

TelemetryState& InitialMode::getInstance() {
    static InitialMode singleton;
    return singleton;
}

static Data_From_AM_t dataFromAM;
static bool hasDataFromAM = false;

void GetFromFWMode::execute(TelemetryManager* telemMgr)
{
	hasDataFromAM = telemMgr->comms->get_from_AM(dataFromAM);

	telemMgr -> setState(GetFromCVMode::getInstance());
}

TelemetryState& GetFromFWMode::getInstance() {
    static GetFromFWMode singleton;
    return singleton;
}

static Data_From_CV_t dataFromCV;
static bool hasDataFromCV = false;

void GetFromCVMode::execute(TelemetryManager* telemMgr)
{
	hasDataFromCV = telemMgr->comms->get_from_CV(dataFromCV);

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
	Data_To_AM_t dataToAM;
	//TODO: Populate dataToAM

	telemMgr->comms->send_to_AM(dataToAM);

	telemMgr -> setState(SendToFWMode::getInstance());
}

TelemetryState& SendToFWMode::getInstance() {
    static SendToFWMode singleton;
    return singleton;
}

void SendToCVMode::execute(TelemetryManager* telemMgr)
{
	Data_To_CV_t dataToCV;

    // TODO: Send data to CV

	telemMgr -> setState(SendToGroundMode::getInstance());
}

TelemetryState& SendToCVMode::getInstance() {
    static SendToCVMode singleton;
    return singleton;
}

void SendToGroundMode::execute(TelemetryManager* telemMgr)
{
	if(hasDataFromAM){
		Data_To_Ground_t dataToGround;
		dataToGround.latitude = dataFromAM.latitude;
		dataToGround.longitude = dataFromAM.longitude;
		dataToGround.altitude = dataFromAM.altitude;
		dataToGround.yaw = dataFromAM.yaw;
		dataToGround.pitch = dataFromAM.pitch;
		dataToGround.roll = dataFromAM.roll;
		for(int i = 0; i < NUM_MOTOR_OUTPUTS; i++)
		{
			dataToGround.motorOutputs[i] = dataFromAM.motorOutputs[i];
		}

		telemMgr->telem->send_to_ground(dataToGround);
	}

	telemMgr -> setState(GetFromFWMode::getInstance());
}

TelemetryState& SendToGroundMode::getInstance() {
    static SendToGroundMode singleton;
    return singleton;
}

void FailureMode::execute(TelemetryManager* telemMgr)
{
	telemMgr -> setState(FailureMode::getInstance());
}

TelemetryState& FailureMode::getInstance() {
    static FailureMode singleton;
    return singleton;
}
