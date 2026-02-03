#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace HEPWeights{

    //int variable1Name;   [example]


}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupHEPWeights() {

//======SETUP CUTFLOW==========================================================================
        _cutFlow.insert(pair<string,double>("00_NLeptons_g_0", 0) );
	_cutFlow.insert(pair<string,double>("01_NbJets_g_0", 0) );
	_cutFlow.insert(pair<string,double>("02_MET_MHT_g_200", 0) );
	_cutFlow.insert(pair<string,double>("03_NFatJets_g_0", 0) );
	_cutFlow.insert(pair<string,double>("04_FatJet_Pt_g_200", 0) );
	_cutFlow.insert(pair<string,double>("05_Omega_g_0p3", 0) );
	_cutFlow.insert(pair<string,double>("06_Signal_like", 0) );

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


    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::HEPWeightsRegion() {

    //-------------------------------------------------------------------------
    // Cut description
    //-------------------------------------------------------------------------

LeptonSelection();
    
    
	if (!(Nleptons==0) ) return false;
        _cutFlow.at("00_NLeptons_g_0") += evtWeight;
	   
	JetSelection();
	        
	if ( !(Nbjets>0) ) return false;	    
	_cutFlow.at("01_NbJets_g_0") += evtWeight;

		        
	if (!(PFMET_pt > 200 && MHT > 200) ) return false;
	_cutFlow.at("02_MET_MHT_g_200") += evtWeight;

			        
	FatjetSelection();

				    
	if ( !(NfatJets>0) ) return false;				        
	_cutFlow.at("03_NFatJets_g_0") += evtWeight;

					  
	if ( !(LeadingFatJet_pt>200) ) return false;					    
	_cutFlow.at("04_FatJet_Pt_g_200") += evtWeight;

						    
	Get_Jet_Angular_Variables();

						        
	if ( !(OmegaMin>OMEGA_CUT) ) return false;						    
	_cutFlow.at("05_Omega_g_0p3") += evtWeight;

							        
	Get_Jet_Shape_Variables();								    
	Get_Signal_Taggers();
								       
	if ( !(signal_tag>0.8) ) return false;								    
	_cutFlow.at("06_Signal_like") += evtWeight;
								       
	Weight_corrections();

										   





    return true;
}


//-------------------------------------------------------------------------------------------------
// Write your analysis code here
//-------------------------------------------------------------------------------------------------
void HEPHero::HEPWeightsSelection() {













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
