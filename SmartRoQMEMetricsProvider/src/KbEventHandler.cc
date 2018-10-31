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
#include "KbEventHandler.hh"
#include "SmartRoQMEMetricsProvider.hh"

#include <iostream>

void KbEventHandler::handleEvent(const CHS::EventId id, const CommBasicObjects::CommKBEventResult &r) throw() 
{
	std::cout << "KbEventHandler event handler: event received: " << std::endl;


	if(id == COMP->jobKbEventID){
		std::cout<<"Job Event: "<<r.getFormatedResult()<<std::endl;
	} else if (id == COMP->robotKbEventID){
		std::cout<<"Robot State Event: "<<r.getFormatedResult()<<std::endl;
	} else {
		std::cout<<"unkown event, this should not have happend!"<<std::endl;
	}

	/*
	 * NOTE:
	 * This event handler should only be used handle the event data.
	 * It should not be used to process the data or to call ANY other blocking function.
	 * Blocking this handler would result in blocked component communication!
	 *
	 */

	CHS::SmartGuard g(this->lock);
	this->curentRes = r;
}


CommBasicObjects::CommKBEventResult KbEventHandler::getCurrentEventResult(){
	CHS::SmartGuard g(this->lock);
	return this->curentRes;
}