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
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------
#ifndef _MONITORINGTASK_HH
#define _MONITORINGTASK_HH

#include "MonitoringTaskCore.hh"
#include <RoqmeWriterImpl.h>
#include <random>


using namespace Roqme;

class MonitoringTask  : public MonitoringTaskCore
{

private:
	RoqmeDoubleWriter doubleWriter;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution;

public:
	MonitoringTask(CHS::SmartComponent *comp);
	virtual ~MonitoringTask();
	
	virtual int on_entry();
	virtual int on_execute();
	virtual int on_exit();
};





#endif
