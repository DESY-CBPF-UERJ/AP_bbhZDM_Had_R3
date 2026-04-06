#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace HEPWeights{

    //int variable1Name;   [example]

	bool METFilter;
	float FatJet_pt;
    	float FatJet_msoftdrop;
}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupHEPWeights() {

//======SETUP CUTFLOW==========================================================================

	_cutFlow.insert(pair<string,double>("00_trigger", 0) );
	_cutFlow.insert(pair<string,double>("01_METFilter", 0) );
	_cutFlow.insert(pair<string,double>("02_NLeptons_g_0", 0) );
	_cutFlow.insert(pair<string,double>("03_NbJets_g_0", 0) );
	_cutFlow.insert(pair<string,double>("04_MET_MHT_g_200", 0) );
	_cutFlow.insert(pair<string,double>("05_NFatJets_g_0", 0) );
	_cutFlow.insert(pair<string,double>("06_FatJet_Pt_g_200", 0) );
	_cutFlow.insert(pair<string,double>("07_Omega_g_0p3", 0) );
	_cutFlow.insert(pair<string,double>("08_Signal_like", 0) );

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
    //_outputTree->Branch("variable1NameInTheTree", &HEPWeights::variable1Name );  [example]

    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    //HDF_insert("variable1NameInTheTree", &HEPWeights::variable1Name );  [example]


    HDF_insert("pileup_wgt", &pileup_wgt );
    HDF_insert("electron_wgt", &electron_wgt );
    HDF_insert("muon_wgt", &muon_wgt );
    HDF_insert("jet_puid_wgt",&jet_puid_wgt);


    HDF_insert("Nelectrons", &Nelectrons);
    HDF_insert("Nmuons", &Nmuons);
    HDF_insert("Ntaus", &Ntaus);
    HDF_insert("Nleptons", &Nleptons);


    HDF_insert("NfatJets", &NfatJets);


    HDF_insert("MET_pt", &PFMET_pt);
    

    HDF_insert("METFilter",&HEPWeights::METFilter);
    HDF_insert("FatJet_pt", &HEPWeights::FatJet_pt);


    HDF_insert("FatJet_msoftdrop", &HEPWeights::FatJet_msoftdrop);


    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::HEPWeightsRegion() {

    //-------------------------------------------------------------------------
    // Cut description
    //-------------------------------------------------------------------------

	if( !Trigger() ) return false;                                              // Selected by triggers
	_cutFlow.at("00_trigger") += evtWeight;
	
	
//	if( !METFilters() ) return false;                                           // Selected by MET filters
    	_cutFlow.at("01_METFilter") += evtWeight;

	
	LeptonSelection();
    
    
	if (!(Nleptons==0) ) return false;
        _cutFlow.at("02_NLeptons_g_0") += evtWeight;
	   
	JetSelection();
	        
	if ( !(Nbjets>0) ) return false;	    
	_cutFlow.at("03_NbJets_g_0") += evtWeight;

		        
	if (!(PFMET_pt > 200 && MHT > 200) ) return false;
	_cutFlow.at("04_MET_MHT_g_200") += evtWeight;

			        
	FatjetSelection();

				    
	if ( !(NfatJets>0) ) return false;				        
	_cutFlow.at("05_NFatJets_g_0") += evtWeight;

					  
	if ( !(LeadingFatJet_pt>200) ) return false;					    
	_cutFlow.at("06_FatJet_Pt_g_200") += evtWeight;

						    
	Get_Jet_Angular_Variables();

						        
	if ( !(OmegaMin>OMEGA_CUT) ) return false;						    
	_cutFlow.at("07_Omega_g_0p3") += evtWeight;

							        
	Get_Jet_Shape_Variables();								    
	Get_Signal_Taggers();
								       
	if ( !(signal_tag>0.8) ) return false;								    
	_cutFlow.at("08_Signal_like") += evtWeight;
	

	bool GoodEvent = lumi_certificate.GoodLumiSection( _datasetName, run, luminosityBlock );
    	if( !GoodEvent ) return false;




	Weight_corrections();

										   
	HEPWeights::FatJet_pt = FatJet_pt[selectedFatJet.at(0)];
    	HEPWeights::FatJet_msoftdrop = FatJet_msoftdrop[selectedFatJet.at(0)];




    return true;
}


//-------------------------------------------------------------------------------------------------
// Write your analysis code here
//-------------------------------------------------------------------------------------------------
void HEPHero::HEPWeightsSelection() {




HEPWeights::METFilter = METFilters();







    //======ASSIGN VALUES TO THE OUTPUT VARIABLES==================================================
    //HEPWeights::variable1Name = 100;      [Example]

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
void HEPHero::HEPWeightsSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishHEPWeights() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
