#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace TestMatheus{
	
    //int variable1Name;   [example]
}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupTestMatheus() {
    //======SETUP CUTFLOW==========================================================================
    _cutFlow.insert(pair<string,double>("00_BEFORE_ELE_ID", 0) );
    _cutFlow.insert(pair<string,double>("01_Selected", 0) );

//    _cutFlow.insert(pair<string,double>("00_BEFORE_ELE_ID", 0) );
//   _cutFlow.insert(pair<string,double>("01_AFTER_ELE_ID", 0) );
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
    //_outputTree->Branch("variable1NameInTheTree", &TestMatheus::variable1Name );  [example]

    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    //HDF_insert("variable1NameInTheTree", &TestMatheus::variable1Name );  [example]


    HDF_insert("nJet", &nJet);
    HDF_insert("nElectron",&nElectron);
    HDF_insert("Nelectrons_cutted",&Nelectrons);
    HDF_insert("Nmuons_cutted",&Nmuons);
    HDF_insert("nMuon",&nMuon);
    HDF_insert("nTau", &nTau);
    HDF_insert("Ntaus_cutted", &Ntaus);


    HDF_insert("FatJet_phi", FatJet_phi);
    HDF_insert("FatJet_pt", FatJet_pt);
    HDF_insert("nFatJet", &nFatJet);
    HDF_insert("FatJet_mass", FatJet_mass); 

    HDF_insert("NfatJets", &NfatJets);
    HDF_insert("LeadingFatJet_pt", &LeadingFatJet_pt);
    HDF_insert("SubLeadingFatJet_pt", &SubLeadingFatJet_pt);
    HDF_insert("ThirdLeadingFatJet_pt", &ThirdLeadingFatJet_pt);
    HDF_insert("FourthLeadingFatJet_pt", &FourthLeadingFatJet_pt);
    HDF_insert("LeadingFatJet_mass", &LeadingFatJet_mass);
    HDF_insert("SubLeadingFatJet_mass", &SubLeadingFatJet_mass);
    HDF_insert("ThirdLeadingFatJet_mass", &ThirdLeadingFatJet_mass);
    HDF_insert("FourthLeadingFatJet_mass", &FourthLeadingFatJet_mass);


    HDF_insert("HLT_AK8PFJet500", &HLT_AK8PFJet500 );
    HDF_insert("HLT_AK8PFJet550", &HLT_AK8PFJet550 );
    HDF_insert("HLT_AK8PFJet420_TrimMass30", &HLT_AK8PFJet420_TrimMass30 );
    HDF_insert("HLT_AK8PFHT800_TrimMass50", &HLT_AK8PFHT800_TrimMass50 );
    HDF_insert("HLT_AK8PFHT850_TrimMass50", &HLT_AK8PFHT850_TrimMass50 );
    HDF_insert("HLT_AK8PFHT900_TrimMass50", &HLT_AK8PFHT900_TrimMass50 );
    HDF_insert("HLT_AK8PFJetFwd400", &HLT_AK8PFJetFwd400 );
    HDF_insert("HLT_AK8PFJetFwd450", &HLT_AK8PFJetFwd450 );
    HDF_insert("HLT_AK8PFJetFwd500", &HLT_AK8PFJetFwd500 );

    HDF_insert("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight );
    HDF_insert("HLT_MET105_IsoTrk50", &HLT_MET105_IsoTrk50 );
    HDF_insert("HLT_BTagMu_AK8Jet170_DoubleMu5", &HLT_BTagMu_AK8Jet170_DoubleMu5 );
    HDF_insert("HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35 );
    HDF_insert("HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35 );
    HDF_insert("HLT_AK8PFJet425_SoftDropMass40", &HLT_AK8PFJet425_SoftDropMass40 );
    HDF_insert("HLT_AK8PFJet450_SoftDropMass40", &HLT_AK8PFJet450_SoftDropMass40 );
    HDF_insert("HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30 );
    HDF_insert("HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30 );
    HDF_insert("HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30 );



    HDF_insert("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight);
    HDF_insert("HLT_HT430_DisplacedDijet40_DisplacedTrack", &HLT_HT430_DisplacedDijet40_DisplacedTrack);
    HDF_insert("HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepJet_4p5", &HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepJet_4p5);
    HDF_insert("HLT_Mu6HT240_DisplacedDijet30_Inclusive1PtrkShortSig5_DisplacedLoose", &HLT_Mu6HT240_DisplacedDijet30_Inclusive1PtrkShortSig5_DisplacedLoose);
    HDF_insert("HLT_DiJet110_35_Mjj650_PFMET110", &HLT_DiJet110_35_Mjj650_PFMET110);
    HDF_insert("HLT_HT430_DisplacedDijet40_Inclusive1PtrkShortSig5", &HLT_HT430_DisplacedDijet40_Inclusive1PtrkShortSig5);
    HDF_insert("HLT_PFHT500_PFMET100_PFMHT100_IDTight", &HLT_PFHT500_PFMET100_PFMHT100_IDTight);


    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::TestMatheusRegion() {

    _cutFlow.at("00_BEFORE_ELE_ID") += evtWeight;
    LeptonSelection();
    JetSelection();
    FatjetSelection();
    
    if( !Trigger() ) return false;                                              // Selected by triggers
    _cutFlow.at("01_Selected") += evtWeight;


    return true;
}


//-------------------------------------------------------------------------------------------------
// Write your analysis code here
//-------------------------------------------------------------------------------------------------
void HEPHero::TestMatheusSelection() {













    //======ASSIGN VALUES TO THE OUTPUT VARIABLES==================================================
    //TestMatheus::variable1Name = 100;      [Example]

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
void HEPHero::TestMatheusSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishTestMatheus() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
