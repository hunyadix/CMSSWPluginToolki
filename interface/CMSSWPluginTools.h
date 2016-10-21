#ifndef CMSSW_PLUGIN_TOOLS_H
#define CMSSW_PLUGIN_TOOLS_H

#include "FWCore/Framework/interface/Frameworkfwd.h"
// #include "FWCore/Framework/interface/EDAnalyzer.h"
// #include "FWCore/Framework/interface/MakerMacros.h"
// #include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/SiPixelDigi/interface/PixelDigi.h"
#include "DataFormats/SiPixelCluster/interface/SiPixelCluster.h"

////////////////////
// Root Libraries //
////////////////////

#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>

namespace CMSSWPluginTools
{
		int getNumDigiCollectionEntries(const edm::Handle<edm::DetSetVector<PixelDigi>>& digiCollection);
		void plotAdcDistributionFromDigiCollection(const edm::Handle<edm::DetSetVector<PixelDigi>>& digiCollection, const std::string& histogramName, const std::string& histogramTitle, const std::string& saveName);
}

#endif