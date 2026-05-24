#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace Signals{

    float FatJet_pt;
    float FatJet_msoftdrop;
    bool Has_leptonic_top;
}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupSignals() {

    //======SETUP CUTFLOW==========================================================================
    _cutFlow.insert(pair<string,double>("01_NfatJets_more_0", 0) );

    //======SETUP HISTOGRAMS=======================================================================
    //makeHist( "histogram1DName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeHist( "histogram2DName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP SYSTEMATIC HISTOGRAMS============================================================
    //sys_regions = { 0, 1, 2 }; [example] // Choose regions as defined in RegionID. Empty vector means that all events will be used.
    //makeSysHist( "histogram1DSysName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeSysHist( "histogram2DSysName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP OUTPUT BRANCHES==================================================================
    //_outputTree->Branch("variable1NameInTheTree", &Signals::variable1Name );  [example]

    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    HDF_insert( "HT", &HT );
    HDF_insert( "OmegaMin", &OmegaMin );
    HDF_insert( "MHT", &MHT );
    HDF_insert( "MET_pt", &PFMET_pt );
    HDF_insert( "MET_FatJet_deltaPhi", &MET_FatJet_deltaPhi );
    HDF_insert( "MET_FatJet_Mt", &MET_FatJet_Mt );
    HDF_insert( "NfatJets", &NfatJets );
    HDF_insert( "Nleptons", &Nleptons );
    HDF_insert( "FatJet_pt", &Signals::FatJet_pt );
    HDF_insert( "FatJet_msoftdrop", &Signals::FatJet_msoftdrop );

    HDF_insert( "LHE_Njets", &LHE_Njets );
    HDF_insert( "LHE_Nb", &LHE_Nb );
    HDF_insert( "idxFatJet", &idxFatJet );
    HDF_insert( "Has_leptonic_top", &Signals::Has_leptonic_top );

    HDF_insert( "Nbjets", &Nbjets );
    HDF_insert( "Nbjets30", &Nbjets30 );
    HDF_insert( "Njets", &Njets );
    HDF_insert( "Njets30", &Njets30 );
    HDF_insert( "NISRbjets", &NISRbjets );
    HDF_insert( "NISRbjets30", &NISRbjets30 );
    HDF_insert( "NISRjets", &NISRjets );
    HDF_insert( "NISRjets30", &NISRjets30 );
    HDF_insert( "LeadingISRJet_pt", &LeadingISRJet_pt );
    HDF_insert( "SubLeadingISRJet_pt", &SubLeadingISRJet_pt );
    HDF_insert( "LeadingISRJet_mass", &LeadingISRJet_mass );
    HDF_insert( "SubLeadingISRJet_mass", &SubLeadingISRJet_mass );
    HDF_insert( "LeadingISRJet_MET_deltaPhi", &LeadingISRJet_MET_deltaPhi );
    HDF_insert( "LeadingISRJet_FatJet_deltaPhi", &LeadingISRJet_FatJet_deltaPhi );

    HDF_insert( "HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight );
    HDF_insert( "HLT_PFHT500_PFMET100_PFMHT100_IDTight", &HLT_PFHT500_PFMET100_PFMHT100_IDTight );

    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::SignalsRegion() {

    LeptonSelection();
    FatjetSelection();
    JetSelection();

    if ( !(NfatJets>0) ) return false;
    _cutFlow.at("01_NfatJets_more_0") += evtWeight;

    Get_Jet_Angular_Variables();

    Signals::FatJet_msoftdrop = FatJet_msoftdrop[idxFatJet];
    Signals::FatJet_pt = FatJet_pt[idxFatJet];


    Signals::Has_leptonic_top = false;
    for(int igen = 0; igen < nGenPart; ++igen){
        if( (abs(GenPart_pdgId[igen]) >= 11) && (abs(GenPart_pdgId[igen]) <= 16) && ((abs(GenPart_pdgId[GenPart_genPartIdxMother[igen]]) == 6) || (abs(GenPart_pdgId[GenPart_genPartIdxMother[igen]]) == 24)) ){
            Signals::Has_leptonic_top = true;
            break;
        }
    }

    return true;
}


//-------------------------------------------------------------------------------------------------
// Write your analysis code here
//-------------------------------------------------------------------------------------------------
void HEPHero::SignalsSelection() {





    //======ASSIGN VALUES TO THE OUTPUT VARIABLES==================================================
    //Signals::variable1Name = 100;      [Example]

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
void HEPHero::SignalsSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishSignals() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
