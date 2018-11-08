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
#include "MonitoringTask.hh"
#include "SmartRoQMEMetricsProvider.hh"

#include <iostream>

using namespace CHS;

MonitoringTask::MonitoringTask(CHS::SmartComponent *comp) 
:	MonitoringTaskCore(comp)
{
	std::cout << "constructor MonitoringTask\n";
}
MonitoringTask::~MonitoringTask() 
{
	std::cout << "destructor MonitoringTask\n";
}


int MonitoringTask::on_entry()
{
	// do initialization procedures here, which are called once, each time the task is started

	/*
	 * NOTE:
	 * Subscribe for bumper events
	 */
	CommBasicObjects::CommBumperEventParameter param;
	param.setOldState(CommBasicObjects::BumperEventType::BUMPER_UNKNOWN);
	COMP->baseBumperEventClient->activate(CHS::EventMode::continuous,param,COMP->bumperEventID);




	/*
	 * NOTE:
	 * Subscribe for KB events, this is a bit more complicated as we will need to subscribe to multiple events!
	 * THIS IS AN EXAMPLE ONLY we need to change this parts to the needs in RoQME!!!
	 */
/*	CommBasicObjects::CommKBEventParam jobKbParam;
	jobKbParam.setQuery("(kb-query-all :key '(is-a) :value '((is-a job)))");
	jobKbParam.setFormatingClause(""
					"(lambda (jobs)"
					  "(let ((str (make-string-output-stream)))"
					  "(flet ((helper (obj)"
					   "(cond "
	                      "((equal (get-value obj 'type) 'GotoPosition)"
					         "(format nil \"id:~s type:~a error-state:~a state:~s robotid:~s goal-location:~s\""
	   				  	     "(get-value obj 'id)(get-value obj 'type)"
					  	     "(get-value obj 'error-state) (get-value obj 'state) (get-value obj 'robotid) (get-value obj 'goal-pose)))"
					      "((equal (get-value obj 'type) 'DeliverFromTo)"
	                         "(format nil \"id:~s type:~a error-state:~a state:~s robotid:~s start-location:~s end-location:~s\""
					         "(get-value obj 'id)(get-value obj 'type)"
						     "(get-value obj 'error-state) (get-value obj 'state) (get-value obj 'robotid) (get-value obj 'start-location) (get-value obj 'end-location)))"
					      "(T"
					         "(format nil \"id:~s type:~a error-state:~a state:~s robotid:~s\""
					         "(get-value obj 'id)(get-value obj 'type)"
					         "(get-value obj 'error-state) (get-value obj 'state) (get-value obj 'robotid))))))"
					    "(format str \"Jobs \")"
					    "(loop for obj in (butlast jobs 1)"
					      "do"
					      "(format str \"~a , \" (helper obj)))"
					   "(let ((obj (first (last jobs))))"
					      "(if (not (null obj))"
					        "(format str \"~a\" (helper obj))))"
					   "(get-output-stream-string str))))");
	COMP->kbEventClient->activate(CHS::EventMode::continuous,jobKbParam,COMP->jobKbEventID);
*/

	/*
	 * NOTE:
	 * Subscribe for KB events, this is a bit more complicated as we will need to subscribe to multiple events!
	 * THIS IS AN EXAMPLE ONLY we need to change this parts to the needs in RoQME!!!
	 */

	CommBasicObjects::CommKBEventParam robotKbParam;
	robotKbParam.setQuery("(kb-query-all :key '(is-a) :value '((is-a robot)))");
	robotKbParam.setFormatingClause(""
			"(lambda (robots)"
			  "(let ((str (make-string-output-stream)))"
			  "(flet ((helper (obj)"
			   "(cond"
                "((and (equal (get-value obj 'state) 'BUSY) (equal (get-value obj 'box-loaded) 1))"
                   "(format nil \"BUSY_DRIVING_WITH_LOAD\"))"
                "((and (equal (get-value obj 'state) 'BUSY) (equal (get-value obj 'box-loaded) 0))"
                   "(format nil \"BUSY_DRIVING_EMPTY\"))"
                "((and (equal (get-value obj 'state) 'IDLE) (equal (get-value obj 'is-docked) '(T CHARGER)))"
                   "(format nil \"IDLE_CHARGING\"))"
                "((and (equal (get-value obj 'state) 'IDLE))"
                   "(format nil \"IDLE_NOT_CHARGING\"))"
                "((and (equal (get-value obj 'state) 'ERROR))"
                   "(format nil \"ERROR\")))))"
			    "(loop for obj in (butlast robots 1)"
			      "do"
			      "(format str \"~a , \" (helper obj)))"
			   "(let ((obj (first (last robots))))"
			      "(if (not (null obj))"
			        "(format str \"~a\" (helper obj))))"
			   "(get-output-stream-string str))))");
	COMP->kbEventClient->activate(CHS::EventMode::continuous,robotKbParam,COMP->robotKbEventID);


	CommBasicObjects::CommKBEventParam personKbParam;
	personKbParam.setQuery("(kb-query :key '(is-a) :value '((is-a person-in-room)))");
	personKbParam.setFormatingClause(""
			"(lambda (person)"
			  "(let ((str (make-string-output-stream)))"
			  "(flet ((helper (obj)"
			   "(cond"
                "((equal (get-value obj 'state) 'T)"
                   "(format nil \"PERSON_IN\"))"
                "((equal (get-value obj 'state) 'NIL)"
                   "(format nil \"PERSON_NOT_IN\")))))"
			    "(loop for obj in (butlast persons 1)"
			      "do"
			      "(format str \"~a , \" (helper obj)))"
			   "(let ((obj (first (last person))))"
			      "(if (not (null obj))"
			        "(format str \"~a\" (helper obj))))"
			   "(get-output-stream-string str))))");
	COMP->kbEventClient->activate(CHS::EventMode::continuous,personKbParam,COMP->personKbEventID);

	return 0;
}

int MonitoringTask::on_execute()
{

	// this method is called from an outside loop,
	// hence, NEVER use an infinite loop (like "while(1)") here inside!!!
	// also do not use blocking calls which do not result from smartsoft kernel
	

	std::cout << "on_execute: \n";

	/*
	 * NOTE:
	 * fetch the data (velocity) pushed to the component
	 * Dependent on how to process the data. This could also be done in a separated task(thread).
	 */

	CommBasicObjects::CommBaseState baseState;
	COMP->baseStateClient->getUpdate(baseState);
	CommBasicObjects::CommBaseVelocity velocity = baseState.getBaseVelocity();

	double vx = velocity.get_vX(1); // m/s
	//double vy = velocity.get_vY(1); // m/s
	//double vw = velocity.getWZ(); // rad/s

	try
	{
		RoqmeDDSTopics::RoqmeDoubleContext velocityContext;//, vyContext, vwContext;
		velocityContext.name("VelocityEvent");
		velocityContext.value().push_back(vx);

		doubleWriter.write(velocityContext);
		std::cout << "Velocity context published:" << vx << std::endl;
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// it is possible to return != 0 (e.g. when the task detects errors), then the outer loop breaks and the task stops
	return 0;
}
int MonitoringTask::on_exit()
{
	// use this method to clean-up resources which are initialized in on_entry() and needs to be freed before the on_execute() can be called again
	return 0;
}

