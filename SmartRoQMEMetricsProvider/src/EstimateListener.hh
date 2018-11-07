#ifndef _ESTIMATELISTENER_HH
#define _ESTIMATELISTENER_HH

#include "CommRoQMEObjects/CommQoSMetrics.hh"
#include <RoqmeReaderImpl.h>

using namespace Roqme;

class EstimateListener:  public RoqmeDDSListener<RoqmeDDSTopics::RoqmeEstimate>
{
public:
	EstimateListener();
	void dataAvailable(dds::sub::DataReader<RoqmeDDSTopics::RoqmeEstimate>& dr);
	void dataAvailable(const RoqmeDDSTopics::RoqmeEstimate& data, const dds::sub::SampleInfo& sampleInfo);

private:
	CommRoQMEObjects::CommQoSMetrics metrics;
	unsigned int pos;
};

#endif
