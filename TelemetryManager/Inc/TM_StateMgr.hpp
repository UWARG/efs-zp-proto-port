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

    bool operator==(const TelemetryState& rhs) const {return (this == &rhs);}
};

#endif // TM_STATEMGR_HPP
