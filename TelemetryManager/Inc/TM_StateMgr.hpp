#ifndef TM_STATEMGR_HPP
#define TM_STATEMGR_HPP

#include "TM.hpp"

class TelemetryManager;

class TelemetryState
{
public:
    virtual void enter(TelemetryManager* attitudeMgr) = 0;
    virtual void execute(TelemetryManager* attitudeMgr) = 0;
    virtual void exit(TelemetryManager* attitudeMgr) = 0;
};

#endif // TM_STATEMGR_HPP
