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
   
    HDF_insert("Nelectrons", &Nelectrons);
    HDF_insert("Nmuons", &Nmuons);
    HDF_insert("Nleptons", &Nleptons);

    //  TODO: Samples DR - SingleTop - TTbar fullyleptonnic
    //  TODO: Explore other Fat Jets variables

    HDF_insert("NfatJets", &NfatJets);
    HDF_insert("LeadingFatJet_jetId", &LeadingFatJet_jetId);
    HDF_insert("SubLeadingFatJet_jetId", &SubLeadingFatJet_jetId);
    HDF_insert("ThirdLeadingFatJet_jetId", &ThirdLeadingFatJet_jetId);
    HDF_insert("FourthLeadingFatJet_jetId", &FourthLeadingFatJet_jetId);
    HDF_insert("LeadingFatJet_pt", &LeadingFatJet_pt);
    HDF_insert("SubLeadingFatJet_pt", &SubLeadingFatJet_pt);
    HDF_insert("ThirdLeadingFatJet_pt", &ThirdLeadingFatJet_pt);
    HDF_insert("FourthLeadingFatJet_pt", &FourthLeadingFatJet_pt);
    HDF_insert("LeadingFatJet_mass", &LeadingFatJet_mass);
    HDF_insert("SubLeadingFatJet_mass", &SubLeadingFatJet_mass);
    HDF_insert("ThirdLeadingFatJet_mass", &ThirdLeadingFatJet_mass);
    HDF_insert("FourthLeadingFatJet_mass", &FourthLeadingFatJet_mass);
    HDF_insert("LeadingFatJet_XbbVsQCD", &LeadingFatJet_XbbVsQCD);
    HDF_insert("SubLeadingFatJet_XbbVsQCD", &SubLeadingFatJet_XbbVsQCD);
    HDF_insert("ThirdLeadingFatJet_XbbVsQCD", &ThirdLeadingFatJet_XbbVsQCD);
    HDF_insert("FourthLeadingFatJet_XbbVsQCD", &FourthLeadingFatJet_XbbVsQCD);
    HDF_insert("LeadingFatJet_XccVsQCD", &LeadingFatJet_XccVsQCD);
    HDF_insert("SubLeadingFatJet_XccVsQCD", &SubLeadingFatJet_XccVsQCD);
    HDF_insert("ThirdLeadingFatJet_XccVsQCD", &ThirdLeadingFatJet_XccVsQCD);
    HDF_insert("FourthLeadingFatJet_XccVsQCD", &FourthLeadingFatJet_XccVsQCD);
    HDF_insert("LeadingFatJet_XggVsQCD", &LeadingFatJet_XggVsQCD);
    HDF_insert("SubLeadingFatJet_XggVsQCD", &SubLeadingFatJet_XggVsQCD);
    HDF_insert("ThirdLeadingFatJet_XggVsQCD", &ThirdLeadingFatJet_XggVsQCD);
    HDF_insert("FourthLeadingFatJet_XggVsQCD", &FourthLeadingFatJet_XggVsQCD);
    HDF_insert("LeadingFatJet_XqqVsQCD", &LeadingFatJet_XqqVsQCD);
    HDF_insert("SubLeadingFatJet_XqqVsQCD", &SubLeadingFatJet_XqqVsQCD);
    HDF_insert("ThirdLeadingFatJet_XqqVsQCD", &ThirdLeadingFatJet_XqqVsQCD);
    HDF_insert("FourthLeadingFatJet_XqqVsQCD", &FourthLeadingFatJet_XqqVsQCD);
    HDF_insert("LeadingFatJet_msoftdrop", &LeadingFatJet_msoftdrop);
    HDF_insert("SubLeadingFatJet_msoftdrop", &SubLeadingFatJet_msoftdrop);
    HDF_insert("ThirdLeadingFatJet_msoftdrop", &ThirdLeadingFatJet_msoftdrop);
    HDF_insert("FourthLeadingFatJet_msoftdrop", &FourthLeadingFatJet_msoftdrop);
    HDF_insert("LeadingFatJet_massCorr", &LeadingFatJet_massCorr);
    HDF_insert("SubLeadingFatJet_massCorr", &SubLeadingFatJet_massCorr);
    HDF_insert("ThirdLeadingFatJet_massCorr", &ThirdLeadingFatJet_massCorr);
    HDF_insert("FourthLeadingFatJet_massCorr", &FourthLeadingFatJet_massCorr);
    HDF_insert("LeadingFatJet_ZvsQCD", &LeadingFatJet_ZvsQCD);
    HDF_insert("SubLeadingFatJet_ZvsQCD", &SubLeadingFatJet_ZvsQCD);
    HDF_insert("ThirdLeadingFatJet_ZvsQCD", &ThirdLeadingFatJet_ZvsQCD);
    HDF_insert("FourthLeadingFatJet_ZvsQCD", &FourthLeadingFatJet_ZvsQCD);


    
    HDF_insert("nJet", &nJet);
    
    HDF_insert("Njets", &Njets);
    HDF_insert("LeadingJet_pt", &LeadingJet_pt);
    HDF_insert("SubLeadingJet_pt", &SubLeadingJet_pt);
    HDF_insert("ThirdLeadingJet_pt", &ThirdLeadingJet_pt);
    HDF_insert("FourthLeadingJet_pt", &FourthLeadingJet_pt);
    HDF_insert("LeadingJet_jetId", &LeadingJet_jetId);
    HDF_insert("SubLeadingJet_jetId", &SubLeadingJet_jetId);
    HDF_insert("ThirdLeadingJet_jetId", &ThirdLeadingJet_jetId);
    HDF_insert("FourthLeadingJet_jetId", &FourthLeadingJet_jetId);
    HDF_insert("LeadingJet_mass", &LeadingJet_mass);
    HDF_insert("SubLeadingJet_mass", &SubLeadingJet_mass);
    HDF_insert("ThirdLeadingJet_mass", &ThirdLeadingJet_mass);
    HDF_insert("FourthLeadingJet_mass", &FourthLeadingJet_mass);

    // HDF_insert("LeadingLep_pt", &LeadingLep_pt);
    // HDF_insert("LeadingLep_eta", &LeadingLep_eta);
    // HDF_insert("TrailingLep_pt", &TrailingLep_pt);
    // HDF_insert("TrailingLep_eta", &TrailingLep_eta);

    HDF_insert("GenMET_phi", &GenMET_phi);
    HDF_insert("GenMET_pt", &GenMET_pt);

    HDF_insert("MET_phi", &MET_phi);
    HDF_insert("MET_pt", &MET_pt);

    HDF_insert("RawMET_phi", &RawMET_phi);
    HDF_insert("RawMET_pt", &RawMET_pt);


    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::TestRegion() {

    LeptonSelection();
    JetSelection();
    FatjetSelection();

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
