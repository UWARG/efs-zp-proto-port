/*
 * attitudeManagerInterface.h
 *
 * Interface exists so freeRTOS can call C-style functions while our dev is in c++
 *
 *  Created on: May 24, 2022
 *      Author: Anthony (Anni) Luo
 */

#ifndef ZP_PROTO_PORT_ATTITUDEMANAGERINTERFACE_H
#define ZP_PROTO_PORT_ATTITUDEMANAGERINTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

void AttitudeManagerInterfaceInit(void);
void AttitudeManagerInterfaceExecute(void);

#ifdef __cplusplus
}
#endif

#endif //ZP_PROTO_PORT_ATTITUDEMANAGERINTERFACE_H
