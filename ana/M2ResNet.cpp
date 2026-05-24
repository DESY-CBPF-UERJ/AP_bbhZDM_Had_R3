#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace M2ResNet{

    vector<double> lightJet_vector;
    vector<double> bJet_vector;
}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupM2ResNet() {

    //======SETUP CUTFLOW==========================================================================
    _cutFlow.insert(pair<string,double>("00_Leptons_equal_0", 0) );
    _cutFlow.insert(pair<string,double>("01_MET_PT_more_200_and_MHT_more_200", 0) );
    _cutFlow.insert(pair<string,double>("02_NfatJets_more_0", 0) );
    _cutFlow.insert(pair<string,double>("03_LeadingFatPt_more_200", 0) );
    _cutFlow.insert(pair<string,double>("05_Omega_more_0p3", 0) );
    _cutFlow.insert(pair<string,double>("06_LeadingFatM_more_30", 0) );
    _cutFlow.insert(pair<string,double>("07_NJets_more_0", 0) );

    //======SETUP HISTOGRAMS=======================================================================
    //makeHist( "histogram1DName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeHist( "histogram2DName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP SYSTEMATIC HISTOGRAMS============================================================
    //sys_regions = { 0, 1, 2 }; [example] // Choose regions as defined in RegionID. Empty vector means that all events will be used.
    //makeSysHist( "histogram1DSysName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeSysHist( "histogram2DSysName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP OUTPUT BRANCHES==================================================================
    //_outputTree->Branch("variable1NameInTheTree", &M2ResNet::variable1Name );  [example]

    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    HDF_insert( "lightJet_vector", &M2ResNet::lightJet_vector );
    HDF_insert( "bJet_vector", &M2ResNet::bJet_vector );

    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::M2ResNetRegion() {

    LeptonSelection();

    if (!(Nleptons==0) ) return false;
    _cutFlow.at("00_Leptons_equal_0") += evtWeight;

    JetSelection();

    if (!(PFMET_pt > 200 && MHT > 200) ) return false;
    _cutFlow.at("01_MET_PT_more_200_and_MHT_more_200") += evtWeight;

    FatjetSelection();

    if ( !(NfatJets > 0) ) return false;
    _cutFlow.at("02_NfatJets_more_0") += evtWeight;

    if ( !(LeadingFatJet_pt>200) ) return false;
    _cutFlow.at("03_LeadingFatPt_more_200") += evtWeight;

    Get_Jet_Angular_Variables();

    if ( !(OmegaMin>OMEGA_CUT) ) return false;
    _cutFlow.at("05_Omega_more_0p3") += evtWeight;

    Weight_corrections();

    float FatJet_mSD = FatJet_msoftdrop[idxFatJet];

    if ( !(FatJet_mSD > 30) ) return false;
    _cutFlow.at("06_LeadingFatM_more_30") += evtWeight;

    if ( !(Njets > 0) ) return false;
    _cutFlow.at("07_NJets_more_0") += evtWeight;

    M2ResNet::bJet_vector.clear();
    M2ResNet::lightJet_vector.clear();
    for( unsigned int iseljet = 0; iseljet < selectedISRJet.size(); ++iseljet ) {
        unsigned int ijet = selectedISRJet[iseljet];
        TLorentzVector jetTL;
        if( JetBTAG( ijet, JET_BTAG_WP ) ){
            jetTL.SetPtEtaPhiM(Jet_pt[ijet], Jet_eta[ijet], Jet_phi[ijet], 4.7);
            M2ResNet::bJet_vector.insert(M2ResNet::bJet_vector.end(), {jetTL.Phi(), jetTL.Eta(), jetTL.E(), jetTL.Pt(), jetTL.Pz()});  
        }else{
            jetTL.SetPtEtaPhiM(Jet_pt[ijet], Jet_eta[ijet], Jet_phi[ijet], 0);
            M2ResNet::lightJet_vector.insert(M2ResNet::lightJet_vector.end(), {jetTL.Phi(), jetTL.Eta(), jetTL.E(), jetTL.Pt(), jetTL.Pz()});
        }
    }

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
void HEPHero::M2ResNetSelection() {













    //======ASSIGN VALUES TO THE OUTPUT VARIABLES==================================================
    //M2ResNet::variable1Name = 100;      [Example]

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
void HEPHero::M2ResNetSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishM2ResNet() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
