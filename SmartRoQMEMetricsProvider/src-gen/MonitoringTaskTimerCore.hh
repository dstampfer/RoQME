//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Christian Schlegel (schlegel@hs-ulm.de)
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------
#ifndef _MONITORINGTASKTIMER_CORE_HH
#define _MONITORINGTASKTIMER_CORE_HH
	
#include "smartSoft.hh"

class MonitoringTaskTimerCore : public Smart::TimerHandler
{
private:
	long timerId;

	// create mutex
	CHS::SmartMutex mutex;
	// create condition mutex
	CHS::SmartConditionMutex cond;

protected:
	virtual void timerExpired(const ACE_Time_Value & absolute_time,
			const void * arg);

public:
	MonitoringTaskTimerCore()
	: timerId(0)
	, mutex()
	, cond(mutex)
	{  }

	virtual void timerExpired(const ACE_Time_Value & absolute_time) {
		// overload this method in derived classes
	}

	virtual void waitTimer();

	virtual void start();
	virtual void stop();
};
#endif