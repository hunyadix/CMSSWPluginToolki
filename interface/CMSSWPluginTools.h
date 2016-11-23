#ifndef CMSSW_PLUGIN_TOOLS_H
#define CMSSW_PLUGIN_TOOLS_H

#include "FWCore/Framework/interface/Frameworkfwd.h"
// #include "FWCore/Framework/interface/EDAnalyzer.h"
// #include "FWCore/Framework/interface/MakerMacros.h"
// #include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "TrackingTools/PatternTools/interface/TrajTrackAssociation.h"
#include "Geometry/Records/interface/TrackerTopologyRcd.h"
#include "DataFormats/TrackerCommon/interface/TrackerTopology.h"

#include "DataFormats/SiPixelDigi/interface/PixelDigi.h"
#include "DataFormats/SiPixelCluster/interface/SiPixelCluster.h"
#include "DataFormats/TrackReco/interface/Track.h"

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
	void printDigiCollectionInfo(const edm::Handle<edm::DetSetVector<PixelDigi>>& digiCollection);
	int getNumDigiCollectionEntries(const edm::Handle<edm::DetSetVector<PixelDigi>>& digiCollection);
	void plotAdcDistributionFromDigiCollection(const edm::Handle<edm::DetSetVector<PixelDigi>>& digiCollection, const std::string& histogramName, const std::string& histogramTitle, const std::string& saveName);
	int getNumClusterCollectionEntries(const edm::Handle<edmNew::DetSetVector<SiPixelCluster>>& clusterCollection);
	int getNumTrajCollectionEntries(const edm::Handle<TrajTrackAssociationCollection>& trajTrackCollection);
}

#endif