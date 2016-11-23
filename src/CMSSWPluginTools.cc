#include "../interface/CMSSWPluginTools.h"


namespace CMSSWPluginTools
{
	void printDigiCollectionInfo(const edm::Handle<edm::DetSetVector<PixelDigi>>& digiCollection)
	{
		int digiCounter = 0;
		std::map<uint32_t, int> digisOnDetCounter;
		for(const edm::DetSet<PixelDigi>& digiSetOnModule: *digiCollection)
		{
			DetId detId(digiSetOnModule.id);
			unsigned int subdetId = detId.subdetId();
			// Discarding non-pixel digis
			if(subdetId != PixelSubdetector::PixelBarrel && subdetId != PixelSubdetector::PixelEndcap) continue;
			// Looping on digis on the same detector_part
			int numDigisOnModule = digiSetOnModule.size();
			digiCounter += numDigisOnModule;
			if(numDigisOnModule == 0) continue;
			digisOnDetCounter.emplace(std::make_pair(detId, numDigisOnModule));
		}
		std::cout << "Digi collection info:\n";
		std::cout << "Number of digis in the collection: " << digiCounter << "\n";
		if(digiCounter == 0) return;
		std::cout << "Detailed information: \n";
		std::cout << "[\n";
		for(const auto& pair: digisOnDetCounter)
		{
			std::cout << "\tdetid: " << pair.first << ", num digis: " << pair.second << "\n";
		}
		std::cout << "]" << std::endl;
	}
	int getNumDigiCollectionEntries(const edm::Handle<edm::DetSetVector<PixelDigi>>& digiCollection)
	{
		int counter = 0;
		for(const edm::DetSet<PixelDigi>& digisOnModule: *digiCollection)
		{
			counter += digisOnModule.size();
		}
		return counter;
	}

	int getNumClusterCollectionEntries(const edm::Handle<edmNew::DetSetVector<SiPixelCluster>>& clusterCollection)
	{
		int counter = 0;
		for(const auto& clustersOnModule: *clusterCollection)
		{
			counter += clustersOnModule.size();
		}
		return counter;
	}
	int getNumTrajCollectionEntries(const edm::Handle<TrajTrackAssociationCollection>& trajTrackCollection)
	{
		int counter = 0;
		for(const auto& currentTrackKeypair: *trajTrackCollection)
		{
			auto traj = currentTrackKeypair.key ;
			counter += traj -> measurements().size();
		}
		return counter;
	}


	// Plotters
	void plotAdcDistributionFromDigiCollection(const edm::Handle<edm::DetSetVector<PixelDigi>>& digiCollection, const std::string& histogramName, const std::string& histogramTitle, const std::string& saveName)
	{
		TH1D adc_H(histogramName.c_str(), histogramTitle.c_str(), 256, 0, 256);
		for(const edm::DetSet<PixelDigi>& digisOnModulePtr: *digiCollection)
		{
			for(const PixelDigi& digi: digisOnModulePtr)
			{
				adc_H.Fill(digi.adc());
			}
		}
		TCanvas canvas((histogramName + "_canvas").c_str(), adc_H.GetTitle());
		adc_H.Draw();
		canvas.SaveAs("adc_values.eps");
	}
};
