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
#ifndef _PARAMUPDATEHANDLER_HH_
#define _PARAMUPDATEHANDLER_HH_

#include "smartSoft.hh"
#include "ParameterStateStruct.hh"

class ParamUpdateHandler: public CHS::ParameterUpdateHandler {
public:
	CHS::CommParameterResponse handleParameter(const CHS::CommParameterRequest& request);

	ParameterStateStruct getGlobalState() const;
	
	void loadParameter(CHS::SmartIniParameter &parameter);

protected:
	//local globale state stuff
	ParameterStateStruct globalState,commitState;
	mutable CHS::SmartMutex globalStateLock;
};

#endif