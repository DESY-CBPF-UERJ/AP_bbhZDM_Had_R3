#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace MCData{

    float FatJet_pt;
    float FatJet_msoftdrop;
    int FatJet_nConstituents;
    float FatJet_particleNet_QCD;

    float FatJet_globalParT3_QCD;
    float FatJet_globalParT3_Xbb;
    float FatJet_globalParT3_Xcc;
    float FatJet_globalParT3_Xcs;
    float FatJet_globalParT3_Xqq;
    float FatJet_globalParT3_massCorr;
    float FatJet_globalParT3_withMassTopvsQCD;
    float FatJet_globalParT3_withMassWvsQCD;
    float FatJet_globalParT3_withMassZvsQCD;

    int nFatJets;
    int NgenJets25;
    int NgenJets30;
}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupMCData() {

    //======SETUP CUTFLOW==========================================================================
    _cutFlow.insert(pair<string,double>("00_Leptons_equal_0", 0) );
    _cutFlow.insert(pair<string,double>("01_NbJets_more_0", 0) );
    _cutFlow.insert(pair<string,double>("02_MET_PT_more_200_and_MHT_more_200", 0) );
    _cutFlow.insert(pair<string,double>("03_NfatJets_more_0", 0) );
    _cutFlow.insert(pair<string,double>("04_LeadingFatPt_more_200", 0) );
    _cutFlow.insert(pair<string,double>("05_Omega_more_0p3", 0) );
    _cutFlow.insert(pair<string,double>("06_LeadingFatM_more_30", 0) );

    //======SETUP HISTOGRAMS=======================================================================
    //makeHist( "histogram1DName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeHist( "histogram2DName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP SYSTEMATIC HISTOGRAMS============================================================
    //sys_regions = { 0, 1, 2 }; [example] // Choose regions as defined in RegionID. Empty vector means that all events will be used.
    //makeSysHist( "histogram1DSysName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeSysHist( "histogram2DSysName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP OUTPUT BRANCHES==================================================================
    //_outputTree->Branch("variable1NameInTheTree", &MCData::variable1Name );  [example]

    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    HDF_insert( "Nbjets", &Nbjets );
    HDF_insert( "HT", &HT );
    HDF_insert( "OmegaMin", &OmegaMin );
    HDF_insert( "FMax", &FMax );
    HDF_insert( "MHT", &MHT );
    HDF_insert( "MET_pt", &PFMET_pt );
    HDF_insert( "MDT", &MDT );
    HDF_insert( "MET_FatJet_deltaPhi", &MET_FatJet_deltaPhi );
    HDF_insert( "MET_FatJet_Mt", &MET_FatJet_Mt );
    HDF_insert( "RT_1", &RT_1 );
    HDF_insert( "RT_3", &RT_3 );
    HDF_insert( "tauT", &tauT );

    HDF_insert( "NfatJets", &NfatJets );
    HDF_insert( "Nleptons", &Nleptons );
    HDF_insert( "Nelectrons", &Nelectrons );
    HDF_insert( "Nmuons", &Nmuons );

    HDF_insert( "FatJet_pt", &MCData::FatJet_pt );
    HDF_insert( "FatJet_msoftdrop", &MCData::FatJet_msoftdrop );
    HDF_insert( "FatJet_nConstituents", &MCData::FatJet_nConstituents );
    HDF_insert( "FatJet_particleNet_QCD", &MCData::FatJet_particleNet_QCD );

    HDF_insert( "HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight );
    HDF_insert( "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight );
    HDF_insert( "HLT_PFMET130_PFMHT130_IDTight", &HLT_PFMET130_PFMHT130_IDTight );

    HDF_insert( "LHE_Njets", &LHE_Njets );
    HDF_insert( "nGenJet", &nGenJet );
    HDF_insert( "NgenJets25", &MCData::NgenJets25 );
    HDF_insert( "NgenJets30", &MCData::NgenJets30 );

    HDF_insert( "FatJet_globalParT3_QCD", &MCData::FatJet_globalParT3_QCD );
    HDF_insert( "FatJet_globalParT3_Xbb", &MCData::FatJet_globalParT3_Xbb );
    HDF_insert( "FatJet_globalParT3_Xcc", &MCData::FatJet_globalParT3_Xcc );
    HDF_insert( "FatJet_globalParT3_Xcs", &MCData::FatJet_globalParT3_Xcs );
    HDF_insert( "FatJet_globalParT3_Xqq", &MCData::FatJet_globalParT3_Xqq );
    HDF_insert( "FatJet_globalParT3_massCorr", &MCData::FatJet_globalParT3_massCorr );
    HDF_insert( "FatJet_globalParT3_withMassTopvsQCD", &MCData::FatJet_globalParT3_withMassTopvsQCD );
    HDF_insert( "FatJet_globalParT3_withMassWvsQCD", &MCData::FatJet_globalParT3_withMassWvsQCD );
    HDF_insert( "FatJet_globalParT3_withMassZvsQCD", &MCData::FatJet_globalParT3_withMassZvsQCD );

    HDF_insert( "Njets", &Njets );
    HDF_insert( "Njets30", &Njets30 );

    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::MCDataRegion() {

    LeptonSelection();

    if (!(Nleptons<=2) ) return false;
    _cutFlow.at("00_Leptons_equal_0") += evtWeight;

    JetSelection();

    if ( !(Nbjets>=0) ) return false;
    _cutFlow.at("01_NbJets_more_0") += evtWeight;

    if (!(PFMET_pt > 200 && MHT > 200) ) return false;
    _cutFlow.at("02_MET_PT_more_200_and_MHT_more_200") += evtWeight;

    FatjetSelection();

    if ( !(NfatJets>0) ) return false;
    _cutFlow.at("03_NfatJets_more_0") += evtWeight;

    if ( !(LeadingFatJet_pt>200) ) return false;
    _cutFlow.at("04_LeadingFatPt_more_200") += evtWeight;

    Get_Jet_Angular_Variables();

    if ( !(OmegaMin>OMEGA_CUT) ) return false;
    _cutFlow.at("05_Omega_more_0p3") += evtWeight;

    Get_Jet_Shape_Variables();
    Weight_corrections();

    MCData::FatJet_msoftdrop = FatJet_msoftdrop[selectedFatJet.at(0)];

    if ( !(MCData::FatJet_msoftdrop>30) ) return false;
    _cutFlow.at("06_LeadingFatM_more_30") += evtWeight;


    MCData::FatJet_pt = FatJet_pt[selectedFatJet.at(0)];
    MCData::FatJet_nConstituents = FatJet_nConstituents[selectedFatJet.at(0)];
    MCData::FatJet_particleNet_QCD = FatJet_particleNet_QCD[selectedFatJet.at(0)];

    MCData::FatJet_globalParT3_QCD = FatJet_globalParT3_QCD[selectedFatJet.at(0)];
    MCData::FatJet_globalParT3_Xbb = FatJet_globalParT3_Xbb[selectedFatJet.at(0)];
    MCData::FatJet_globalParT3_Xcc = FatJet_globalParT3_Xcc[selectedFatJet.at(0)];
    MCData::FatJet_globalParT3_Xcs = FatJet_globalParT3_Xcs[selectedFatJet.at(0)];
    MCData::FatJet_globalParT3_Xqq = FatJet_globalParT3_Xqq[selectedFatJet.at(0)];
    MCData::FatJet_globalParT3_massCorr = FatJet_msoftdrop[selectedFatJet.at(0)]*FatJet_globalParT3_massCorrX2p[selectedFatJet.at(0)];
    MCData::FatJet_globalParT3_withMassTopvsQCD = FatJet_globalParT3_withMassTopvsQCD[selectedFatJet.at(0)];
    MCData::FatJet_globalParT3_withMassWvsQCD = FatJet_globalParT3_withMassWvsQCD[selectedFatJet.at(0)];
    MCData::FatJet_globalParT3_withMassZvsQCD = FatJet_globalParT3_withMassZvsQCD[selectedFatJet.at(0)];
    
    bool GoodEvent = lumi_certificate.GoodLumiSection( _datasetName, run, luminosityBlock );
    if( !GoodEvent ) return false;



    MCData::NgenJets25 = 0;
    MCData::NgenJets30 = 0;
    for( unsigned int ijet = 0; ijet < nGenJet; ++ijet ) {
       	if( abs(GenJet_eta[ijet]) >= 2.5 ) continue;
        if( GenJet_pt[ijet] > 25 ) MCData::NgenJets25 += 1;
        if( GenJet_pt[ijet] > 30 ) MCData::NgenJets30 += 1;
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
void HEPHero::MCDataSelection() {


    //======ASSIGN VALUES TO THE OUTPUT VARIABLES==================================================
    //MCData::variable1Name = 100;      [Example]

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
void HEPHero::MCDataSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishMCData() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
