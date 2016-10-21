#include "../interface/CMSSWPluginTools.h"


namespace CMSSWPluginTools
{
	int getNumDigiCollectionEntries(const edm::Handle<edm::DetSetVector<PixelDigi>>& digiCollection)
	{
		int numDigis = 0;
		for(const edm::DetSet<PixelDigi>& digisOnModulePtr: *digiCollection)
		{
			numDigis += digisOnModulePtr.size();
		}
		return numDigis;
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
