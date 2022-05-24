/*
 * attitudeManagerInterface.h
 *
 * Interface exists so freeRTOS can call C-style functions while our dev is in c++
 *
 *  Created on: May 24, 2022
 *      Author: Anthony (Anni) Luo
 */

#ifndef ATTITUDE_MANAGER_INTERFACE_H
#define ATTITUDE_MANAGER_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

void AttitudeManagerInterfaceInit(void);
void AttitudeManagerInterfaceExecute(void);

#ifdef __cplusplus
}
#endif

#endif //ATTITUDE_MANAGER_INTERFACE_H
