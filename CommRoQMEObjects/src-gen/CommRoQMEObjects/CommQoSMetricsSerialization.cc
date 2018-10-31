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
#include "CommRoQMEObjects/CommQoSMetricsSerialization.hh"


// serialization operator for element CommQoSMetrics
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const CommRoQMEObjectsIDL::CommQoSMetrics &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element metricNames
	good_bit = good_bit && cdr << ACE_Utils::truncate_cast<ACE_CDR::ULong>(data.metricNames.size());
	std::vector<ACE_CString>::const_iterator data_metricNamesIt;
	for(data_metricNamesIt=data.metricNames.begin(); data_metricNamesIt!=data.metricNames.end(); data_metricNamesIt++) {
		good_bit = good_bit && cdr << *data_metricNamesIt;
	}
	// serialize list-element values
	good_bit = good_bit && cdr << ACE_Utils::truncate_cast<ACE_CDR::ULong>(data.values.size());
	good_bit = good_bit && cdr.write_double_array(data.values.data(), data.values.size());
	
	return good_bit;
}

// de-serialization operator for element CommQoSMetrics
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, CommRoQMEObjectsIDL::CommQoSMetrics &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize list-type element metricNames
	ACE_CDR::ULong data_metricNamesNbr;
	good_bit = good_bit && cdr >> data_metricNamesNbr;
	data.metricNames.clear();
	ACE_CString data_metricNamesItem;
	for(ACE_CDR::ULong i=0; i<data_metricNamesNbr; ++i) {
		good_bit = good_bit && cdr >> data_metricNamesItem;
		data.metricNames.push_back(data_metricNamesItem);
	}
	// deserialize list-type element values
	ACE_CDR::ULong data_valuesNbr;
	good_bit = good_bit && cdr >> data_valuesNbr;
	data.values.resize(data_valuesNbr);
	good_bit = good_bit && cdr.read_double_array(data.values.data(), data_valuesNbr);
	
	return good_bit;
}
