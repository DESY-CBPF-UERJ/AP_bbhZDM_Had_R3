#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace Test{

    //int variable1Name;   [example]
}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupTest() {

    //======SETUP CUTFLOW==========================================================================
    //_cutFlow.insert(pair<string,double>("CutName", 0) );   [example]

    //======SETUP HISTOGRAMS=======================================================================
    //makeHist( "histogram1DName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeHist( "histogram2DName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP SYSTEMATIC HISTOGRAMS============================================================
    //sys_regions = { 0, 1, 2 }; [example] // Choose regions as defined in RegionID. Empty vector means that all events will be used.
    //makeSysHist( "histogram1DSysName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeSysHist( "histogram2DSysName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP OUTPUT BRANCHES==================================================================
    //_outputTree->Branch("variable1NameInTheTree", &Test::variable1Name );  [example]

    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    //HDF_insert("variable1NameInTheTree", &Test::variable1Name );  [example]
    // HDF_insert("JetMass", &weights::JetMass);

    HDF_insert("event", &event);
   
    HDF_insert("nGenJet", &nGenJet);
    HDF_insert("GenJet_eta", GenJet_eta);
    HDF_insert("GenJet_mass", GenJet_mass);
    HDF_insert("GenJet_phi", GenJet_phi);
    HDF_insert("GenJet_pt", GenJet_pt);

    HDF_insert("nGenPart", &nGenPart);
    HDF_insert("GenPart_pdgId", GenPart_pdgId);
    HDF_insert("GenPart_status", GenPart_status);
    HDF_insert("GenPart_eta", GenPart_eta);
    HDF_insert("GenPart_mass", GenPart_mass);
    HDF_insert("GenPart_phi", GenPart_phi);
    HDF_insert("GenPart_pt", GenPart_pt);
    HDF_insert("genWeight", &genWeight);

    HDF_insert("nFatJet", &nFatJet);
    HDF_insert("FatJet_jetId", FatJet_jetId);
    HDF_insert("FatJet_nConstituents", FatJet_nConstituents);
    // HDF_insert("FatJet_subJetIdx1", FatJet_subJetIdx1);
    // HDF_insert("FatJet_subJetIdx2", FatJet_subJetIdx2);
    HDF_insert("FatJet_phi", FatJet_phi);
    HDF_insert("FatJet_pt", FatJet_pt);
    HDF_insert("FatJet_mass", FatJet_mass);
    HDF_insert("FatJet_particleNet_QCD", FatJet_particleNet_QCD);
    HDF_insert("FatJet_particleNet_QCD0HF", FatJet_particleNet_QCD0HF);
    HDF_insert("FatJet_particleNet_QCD1HF", FatJet_particleNet_QCD1HF);
    HDF_insert("FatJet_particleNet_QCD2HF", FatJet_particleNet_QCD2HF);
    HDF_insert("FatJet_particleNet_XbbVsQCD", FatJet_particleNet_XbbVsQCD);
    HDF_insert("FatJet_particleNet_XccVsQCD", FatJet_particleNet_XccVsQCD);
    HDF_insert("FatJet_particleNet_XggVsQCD", FatJet_particleNet_XggVsQCD);
    HDF_insert("FatJet_particleNet_XqqVsQCD", FatJet_particleNet_XqqVsQCD);
    HDF_insert("FatJet_particleNet_XtmVsQCD", FatJet_particleNet_XtmVsQCD);
    HDF_insert("FatJet_particleNet_XttVsQCD", FatJet_particleNet_XttVsQCD);
    HDF_insert("FatJet_particleNet_massCorr", FatJet_particleNet_massCorr);
    HDF_insert("FatJet_hadronFlavour", FatJet_hadronFlavour);
    HDF_insert("FatJet_nBHadrons", FatJet_nBHadrons);

    HDF_insert("LHEWeight_originalXWGTUP", &LHEWeight_originalXWGTUP);
    HDF_insert("nLHEPdfWeight", &nLHEPdfWeight);
    HDF_insert("LHEPdfWeight", LHEPdfWeight);
    HDF_insert("nLHEReweightingWeight", &nLHEReweightingWeight);
    HDF_insert("LHEReweightingWeight", LHEReweightingWeight);
    HDF_insert("nLHEScaleWeight", &nLHEScaleWeight);
    HDF_insert("LHEScaleWeight", LHEScaleWeight);
    HDF_insert("nPSWeight", &nPSWeight);
    HDF_insert("PSWeight", PSWeight);
    
    HDF_insert("nJet", &nJet);
    HDF_insert("Jet_jetId", Jet_jetId);
    HDF_insert("Jet_nElectrons", Jet_nElectrons);
    HDF_insert("Jet_nMuons", Jet_nMuons);
    HDF_insert("Jet_area", Jet_area);
    HDF_insert("Jet_eta", Jet_eta);
    HDF_insert("Jet_phi", Jet_phi);
    HDF_insert("Jet_pt", Jet_pt);
    HDF_insert("Jet_mass", Jet_mass);

    HDF_insert("GenMET_phi", &GenMET_phi);
    HDF_insert("GenMET_pt", &GenMET_pt);

    HDF_insert("MET_phi", &MET_phi);
    HDF_insert("MET_pt", &MET_pt);

    HDF_insert("Pileup_sumEOOT", &Pileup_sumEOOT);
    HDF_insert("Pileup_sumLOOT", &Pileup_sumLOOT);
    HDF_insert("Pileup_nTrueInt", &Pileup_nTrueInt);

    HDF_insert("PuppiMET_phi", &PuppiMET_phi);
    HDF_insert("PuppiMET_pt", &PuppiMET_pt);

    HDF_insert("RawMET_phi", &RawMET_phi);
    HDF_insert("RawMET_pt", &RawMET_pt);

    HDF_insert("PV_x", &PV_x);
    HDF_insert("PV_y", &PV_y);
    HDF_insert("PV_z", &PV_z);

    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::TestRegion() {

    //-------------------------------------------------------------------------
    // Cut description
    //-------------------------------------------------------------------------
    //if( !(CutCondition) ) return false;           [Example]
    //_cutFlow.at("CutName") += evtWeight;          [Example]

    return true;
}


//-------------------------------------------------------------------------------------------------
// Write your analysis code here
//-------------------------------------------------------------------------------------------------
void HEPHero::TestSelection() {













    //======ASSIGN VALUES TO THE OUTPUT VARIABLES==================================================
    //Test::variable1Name = 100;      [Example]

    //======FILL THE HISTOGRAMS====================================================================
    //_histograms1D.at("histogram1DName").Fill( var, evtWeight );               [Example]
    //_histograms2D.at("histogram2DName").Fill( var1, var2, evtWeight );        [Example]

    //======FILL THE OUTPUT TREE===================================================================
    //_outputTree->Fill();

    //======FILL THE OUTPUT HDF5 INFO===============================================================
    HDF_fill();

    return;
}


//-------------------------------------------------------------------------------------------------
// Produce systematic histograms
//-------------------------------------------------------------------------------------------------
void HEPHero::TestSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishTest() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
