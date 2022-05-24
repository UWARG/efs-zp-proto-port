/*
 * attitudeStateManager.hpp
 *
 * Attitude State-Machine Header
 *
 *  Created on: May 24, 2022
 *      Author: Anthony (Anni) Luo
 */

#ifndef ZP_PROTO_PORT_ATTITUDESTATEMANAGER_HPP
#define ZP_PROTO_PORT_ATTITUDESTATEMANAGER_HPP

#include "attitudeManager.hpp"

class attitudeManager;

class attitudeState
{
public:
    virtual void enter(attitudeManager* attitudeMgr) = 0;
    virtual void execute(attitudeManager* attitudeMgr) = 0;
    virtual void exit(attitudeManager* attitudeMgr) = 0;

    bool operator==(const attitudeState& rhs) const {return (this == &rhs);}

    virtual ~attitudeState() {}

};

#endif //ZP_PROTO_PORT_ATTITUDESTATEMANAGER_HPP
