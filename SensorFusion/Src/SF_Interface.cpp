#include "../Inc/SF_Interface.h"

#include "../Inc/SensorFusion.hpp"

#include "../../Drivers/Sensors/Inc/imu.hpp"

void SensorFusionInterfaceInit(void) {
	SF_Init();
}

void SensorFusionInterfaceExecute(void) {
	/*IMUData_t imuData;
	 IMU *imuObj;
	 imuObj = &BMX160::getInstance();
	 imuObj->GetResult(imuData);
	 */

	SFError_t err = SF_GenerateNewResult();
}
