#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace Test{

    float FatJet_pt;
    float FatJet_msoftdrop;
    float Muon_pt, Muon_eta;
    float Jet_pt,BJet_pt;
}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupTest() {

    //======SETUP CUTFLOW==========================================================================
    _cutFlow.insert(pair<string,double>("00_NLeptons_g_0", 0) );
    _cutFlow.insert(pair<string,double>("01_NbJets_g_0", 0) );
    _cutFlow.insert(pair<string,double>("02_MET_MHT_g_200", 0) );
    _cutFlow.insert(pair<string,double>("03_NFatJets_g_0", 0) );
    _cutFlow.insert(pair<string,double>("04_FatJet_Pt_g_200", 0) );
    _cutFlow.insert(pair<string,double>("05_Omega_g_0p3", 0) );
    _cutFlow.insert(pair<string,double>("06_Signal_like", 0) );

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
    HDF_insert("Nelectrons", &Nelectrons);
    HDF_insert("Nmuons", &Nmuons);
    HDF_insert("Ntaus", &Ntaus);
    HDF_insert("Nleptons", &Nleptons);

    HDF_insert("Muon_pt",&Test::Muon_pt);
    HDF_insert("Muon_eta",&Test::Muon_eta);

    HDF_insert("NfatJets", &NfatJets);
    HDF_insert("FatJet_b_max_deltaEta",&FatJet_b_max_deltaEta);
    
    HDF_insert("Nbjets", &Nbjets);
    HDF_insert("HT", &HT);
    HDF_insert("OmegaMin", &OmegaMin);
    HDF_insert("FMax", &FMax);
    HDF_insert("MHT", &MHT);
    HDF_insert("MET_pt", &PFMET_pt);
    HDF_insert("MDT", &MDT);
    HDF_insert("MET_FatJet_deltaPhi", &MET_FatJet_deltaPhi);
    HDF_insert("MET_FatJet_Mt", &MET_FatJet_Mt);
    HDF_insert("RT_1", &RT_1);
    HDF_insert("RT_3", &RT_3);
    HDF_insert("tauT", &tauT);

    HDF_insert("FatJet_pt", &Test::FatJet_pt);
    HDF_insert("FatJet_msoftdrop", &Test::FatJet_msoftdrop);

    HDF_insert("Jet_pt", &Test::Jet_pt);
//    HDF_insert("BJet_pt", &Test::BJet_pt);

    HDF_insert("signal_tag", &signal_tag);

    HDF_insert("GenHT", &LHE_HT );
    HDF_insert("GenVpt", &LHE_Vpt );


    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::TestRegion() {

    LeptonSelection();
    if (selectedMu.size()!=0){
    Test::Muon_pt = Muon_pt[selectedMu.at(0)];
    Test::Muon_eta = Muon_eta[selectedMu.at(0)];
    }
    else{
    Test::Muon_pt = -10;
    Test::Muon_eta = -10;
    }

    if (!(Nleptons==0) ) return false;
    _cutFlow.at("00_NLeptons_g_0") += evtWeight;

    JetSelection();

    Test::Jet_pt = LeadingJet_pt;

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

    bool GoodEvent = lumi_certificate.GoodLumiSection( _datasetName, run, luminosityBlock );
    if( !GoodEvent ) return false;


    Weight_corrections();

    Test::FatJet_pt = FatJet_pt[selectedFatJet.at(0)];
    Test::FatJet_msoftdrop = FatJet_msoftdrop[selectedFatJet.at(0)];




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
