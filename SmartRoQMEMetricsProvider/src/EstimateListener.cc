#include "EstimateListener.hh"
#include "SmartRoQMEMetricsProvider.hh"


EstimateListener::EstimateListener(){}

void EstimateListener::dataAvailable(dds::sub::DataReader<RoqmeDDSTopics::RoqmeEstimate>& dr)
{

	std::cout << "Dentro de all" << std::endl;
	dds::sub::LoanedSamples<RoqmeDDSTopics::RoqmeEstimate> samples = dr.take();

	if(samples.length()>0)
	{
		unsigned int numberOfMetrics = samples.length();
		metrics.resizeMetricNames(numberOfMetrics);
		metrics.resizeValues(numberOfMetrics);
		pos = 0;
		if((*samples.begin()).info().valid())
		{
			for (auto sample: samples)
			{
				dataAvailable(sample->data(), sample->info());
			}
		}
		COMP->metricsPushServer->put(metrics);
	}
}

void EstimateListener::dataAvailable(const RoqmeDDSTopics::RoqmeEstimate& data, const dds::sub::SampleInfo& sampleInfo)
{
	std::cout << "---------------------------" << std::endl;
	std::cout << "Estimate disponible:" << std::endl;
	std::cout << "\t name: " << data.name() << std::endl;
	std::cout << "\t " << data.value() << std::endl;

	const dds::core::Time& source_timestamp = sampleInfo.timestamp();
	std::cout << source_timestamp.sec() << ", " << source_timestamp.nanosec() << std::endl;
	std::cout << "---------------------------" << std::endl;

	metrics.setMetricNamesElemAtPos(pos, data.name());
	metrics.setValuesElemAtPos(pos++, data.value());
}
