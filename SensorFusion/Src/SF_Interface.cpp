#include "../Inc/SF_Interface.h"

#include "../Inc/SensorFusion.hpp"

void SensorFusionInterfaceInit(void) {
    SF_Init();
}

void SensorFusionInterfaceExecute(void) {
    SFError_t err = SF_GenerateNewResult();
}
