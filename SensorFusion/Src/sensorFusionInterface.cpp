#include "../Inc/sensorFusionInterface.hpp"
#include "../Inc/SensorFusion.hpp"

void SensorFusionInterfaceInit(void) {
    SF_Init();
}

SFError_t SensorFusionInterfaceExecute(void) {
    SFError_t err = SF_GenerateNewResult();
    return err;
}
