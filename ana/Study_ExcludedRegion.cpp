#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace Study_ExcludedRegion{

    //int variable1Name;   [example]
}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupStudy_ExcludedRegion() {

	_cutFlow.insert(pair<string,double>("00_trigger", 0) );
	_cutFlow.insert(pair<string,double>("01_METFilter", 0) );
	_cutFlow.insert(pair<string,double>("02_Leptons_equal_0", 0) );
	_cutFlow.insert(pair<string,double>("03_NbJets_more_0", 0) );
	_cutFlow.insert(pair<string,double>("04_MET_PT_more_200_and_MHT_more_200", 0) );
	_cutFlow.insert(pair<string,double>("05_NfatJets_more_0", 0) );
	_cutFlow.insert(pair<string,double>("06_LeadingFatPt_more_200", 0) );
	_cutFlow.insert(pair<string,double>("07_Omega_more_0p3", 0) );
	_cutFlow.insert(pair<string,double>("08_Signal_like",0) );
	_cutFlow.insert(pair<string,double>("09_FatJet_msoftdrop_more_30", 0) );


	
	
	//======SETUP SYSTEMATIC HISTOGRAMS============================================================
	sys_regions = {0};
	makeSysHist("signal_tag", 100, 0., 1, "xlabel", "ylabel" );
    makeSysHist("signal_tag_run3", 100, 0., 1, "xlabel", "ylabel" );



    //======SETUP OUTPUT BRANCHES==================================================================
    //_outputTree->Branch("variable1NameInTheTree", &Study_ExcludedRegion::variable1Name );  [example]

    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    //HDF_insert("variable1NameInTheTree", &Study_ExcludedRegion::variable1Name );  [example]

    HDF_insert("MET_pt", &PFMET_pt);
    HDF_insert("signal_tag", &signal_tag);
    HDF_insert("signal_tag_run3", &signal_tag_run3);
    HDF_insert("RegionID",&RegionID);
    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::Study_ExcludedRegionRegion() {

    Regions();

    if( !Trigger() ) return false;                                              // Selected by triggers
    _cutFlow.at("00_trigger") += evtWeight;

    if( !METFilters() ) return false;                                           // Selected by MET filters
    _cutFlow.at("01_METFilter") += evtWeight;
    
    LeptonSelection();

    if (!(Nleptons==0) ) return false;
    _cutFlow.at("02_Leptons_equal_0") += evtWeight;

    JetSelection();

    if ( !(Nbjets>0) ) return false;
    _cutFlow.at("03_NbJets_more_0") += evtWeight;

    if (!(PFMET_pt > 200 && MHT > 200) ) return false;
    _cutFlow.at("04_MET_PT_more_200_and_MHT_more_200") += evtWeight;

    FatjetSelection();

    if ( !(NfatJets>0) ) return false;
    _cutFlow.at("05_NfatJets_more_0") += evtWeight;

    if ( !(LeadingFatJet_pt>200) ) return false;
    _cutFlow.at("06_LeadingFatPt_more_200") += evtWeight;

    Get_Jet_Angular_Variables();

    if ( !(OmegaMin>OMEGA_CUT) ) return false;
    _cutFlow.at("07_Omega_more_0p3") += evtWeight;

    Get_Jet_Shape_Variables();
    Weight_corrections();

    Get_Signal_Taggers();
    Get_Signal_Taggers_Run3();
								       
//    if ( !(signal_tag>0.8) ) return false;								    
    _cutFlow.at("08_Signal_like") += evtWeight;



    if ( !( FatJet_msoftdrop[selectedFatJet.at(0)] > 30 ) )  return false;
    _cutFlow.at("09_FatJet_msoftdrop_more_30") += evtWeight;




    return true;
}


//-------------------------------------------------------------------------------------------------
// Write your analysis code here
//-------------------------------------------------------------------------------------------------
void HEPHero::Study_ExcludedRegionSelection() {






    //======ASSIGN VALUES TO THE OUTPUT VARIABLES==================================================
    //Study_ExcludedRegion::variable1Name = 100;      [Example]

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
void HEPHero::Study_ExcludedRegionSystematic() {

    FillSystematic( "signal_tag",signal_tag, evtWeight );
    if( !NN_model_run3_file.empty() ) FillSystematic("signal_tag_run3", signal_tag_run3, evtWeight);
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishStudy_ExcludedRegion() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
