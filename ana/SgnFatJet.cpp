#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace SgnFatJet{

    //int variable1Name;   [example]
}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupSgnFatJet() {

    //======SETUP CUTFLOW==========================================================================
    //_cutFlow.insert(pair<string,double>("CutName", 0) );   [example]

    //======SETUP HISTOGRAMS=======================================================================
    makeHist( "Mt_diff", 100, -1000., 1000., "Mt diff [GeV]", "Events" );
    makeHist( "FatJetS", 125, 0., 500., "M [GeV]", "Events" );
    makeHist( "SuperJetS", 125, 0., 500., "M [GeV]", "Events" );
    makeHist( "FatJetB", 125, 0., 500., "M [GeV]", "Events" );
    makeHist( "SuperJetB", 125, 0., 500., "M [GeV]", "Events" );
    makeHist( "Signal_FatJet", 50, 0., 1., 100, 300., 1300., "QCD tag",  "Mt [GeV]", "zlabel", "COLZ" );
    makeHist( "Bkg_FatJet", 50, 0., 1., 100, 300., 1300., "QCD tag",  "Mt [GeV]", "zlabel", "COLZ" );
    //makeHist( "histogram1DName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeHist( "histogram2DName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP SYSTEMATIC HISTOGRAMS============================================================
    //sys_regions = { 0, 1, 2 }; [example] // Choose regions as defined in RegionID. Empty vector means that all events will be used.
    //makeSysHist( "histogram1DSysName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeSysHist( "histogram2DSysName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP OUTPUT BRANCHES==================================================================
    //_outputTree->Branch("variable1NameInTheTree", &SgnFatJet::variable1Name );  [example]

    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    //HDF_insert("variable1NameInTheTree", &SgnFatJet::variable1Name );  [example]

    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::SgnFatJetRegion() {

    TLorentzVector Boson;
    for(int igen = 0; igen < nGenPart; ++igen){
        if( (abs(GenPart_pdgId[igen]) >= 23) && (abs(GenPart_pdgId[igen]) <= 25) && (abs(GenPart_pdgId[GenPart_genPartIdxMother[igen]]) >= 35) && (abs(GenPart_pdgId[GenPart_genPartIdxMother[igen]]) <= 37) ){
                Boson.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],GenPart_mass[igen]);
                break;
        }
    }
    //cout << Boson.M() << " " << endl;

    int JetID = -1;
    double drMin = 99999.;
    for( unsigned int ijet = 0; ijet < nFatJet; ++ijet ) {
        if( FatJet_msoftdrop[ijet] < 30 ) continue;
        double deta = fabs(Boson.Eta() - FatJet_eta[ijet]);
        double dphi = fabs(Boson.Phi() - FatJet_phi[ijet]);
        if( dphi > M_PI ) dphi = 2*M_PI - dphi;
        double dr = sqrt( deta*deta + dphi*dphi );
        if( dr < drMin ){
            drMin = dr;
            JetID = ijet;
        }
    }

    int JetCand2ID = -1;
    for( unsigned int ijet = 0; ijet < nFatJet; ++ijet ) {
        if( FatJet_msoftdrop[ijet] < 30 ) continue;
        if( ijet != JetID ){
            JetCand2ID = ijet;
            break;
        }
    }




    LeptonSelection();
    FatjetSelection();
    JetSelection();
    if( selectedJet.size() >= 1 ){
        int jetID1 = -1;
        int jetID2 = -1;
        double drMin1 = 99999.;
        double drMin2 = 99999.;
        for( unsigned int iseljet = 0; iseljet < selectedJet.size(); ++iseljet ) {
            int ijet = selectedJet[iseljet];

            double deta = fabs(FatJet_eta[JetID] - Jet_eta[ijet]);
            double dphi = fabs(FatJet_phi[JetID] - Jet_phi[ijet]);
            if( dphi > M_PI ) dphi = 2*M_PI - dphi;
            double dr = sqrt( deta*deta + dphi*dphi );
            if( dr < drMin1 ){
                drMin1 = dr;
                jetID1 = ijet;
            }

            deta = fabs(FatJet_eta[JetCand2ID] - Jet_eta[ijet]);
            dphi = fabs(FatJet_phi[JetCand2ID] - Jet_phi[ijet]);
            if( dphi > M_PI ) dphi = 2*M_PI - dphi;
            dr = sqrt( deta*deta + dphi*dphi );
            if( dr < drMin2 ){
                drMin2 = dr;
                jetID2 = ijet;
            }
        }

        if( (JetID >= 0) && (JetCand2ID >= 0) ){

            TLorentzVector FatJetS;
            FatJetS.SetPtEtaPhiM(FatJet_pt[JetID],FatJet_eta[JetID],FatJet_phi[JetID],FatJet_mass[JetID]);
            TLorentzVector FatJetB;
            FatJetB.SetPtEtaPhiM(FatJet_pt[JetCand2ID],FatJet_eta[JetCand2ID],FatJet_phi[JetCand2ID],FatJet_mass[JetCand2ID]);

            TLorentzVector JetS;
            JetS.SetPtEtaPhiM(Jet_pt[jetID1],Jet_eta[jetID1],Jet_phi[jetID1],Jet_mass[jetID1]);
            TLorentzVector JetB;
            JetB.SetPtEtaPhiM(Jet_pt[jetID2],Jet_eta[jetID2],Jet_phi[jetID2],Jet_mass[jetID2]);

            TLorentzVector SuperJetS = FatJetS + JetS;
            TLorentzVector SuperJetB = FatJetB + JetB;


            _histograms1D.at("FatJetS").Fill( FatJetS.M(), evtWeight );
            _histograms1D.at("SuperJetS").Fill( SuperJetS.M(), evtWeight );
            _histograms1D.at("FatJetB").Fill( FatJetB.M(), evtWeight );
            _histograms1D.at("SuperJetB").Fill( SuperJetB.M(), evtWeight );
        }
    }




    if( (JetID >= 0) && (JetCand2ID >= 0) ){
        float MET_FatJet_deltaPhi_1 = abs( FatJet_phi[JetID] - PFMET_phi );
        if( MET_FatJet_deltaPhi_1 > M_PI ) MET_FatJet_deltaPhi_1 = 2*M_PI - MET_FatJet_deltaPhi_1;
        float MET_FatJet_Mt_1 = sqrt( 2 * FatJet_pt[JetID] * PFMET_pt * ( 1 - cos( MET_FatJet_deltaPhi_1 ) ) ) ;

        float MET_FatJet_deltaPhi_2 = abs( FatJet_phi[JetCand2ID] - PFMET_phi );
        if( MET_FatJet_deltaPhi_2 > M_PI ) MET_FatJet_deltaPhi_2 = 2*M_PI - MET_FatJet_deltaPhi_2;
        float MET_FatJet_Mt_2 = sqrt( 2 * FatJet_pt[JetCand2ID] * PFMET_pt * ( 1 - cos( MET_FatJet_deltaPhi_2 ) ) ) ;

        float Mt_diff = MET_FatJet_Mt_1 - MET_FatJet_Mt_2;
        _histograms1D.at("Mt_diff").Fill( Mt_diff, evtWeight );
    }

    for( unsigned int ijet = 0; ijet < nFatJet; ++ijet ) {
        if( FatJet_msoftdrop[ijet] < 30 ) continue;

	float MET_FatJet_deltaPhi_i = abs( FatJet_phi[ijet] - PFMET_phi );
        if( MET_FatJet_deltaPhi_i > M_PI ) MET_FatJet_deltaPhi_i = 2*M_PI - MET_FatJet_deltaPhi_i;
        float MET_FatJet_Mt_i = sqrt( 2 * FatJet_pt[ijet] * PFMET_pt * ( 1 - cos( MET_FatJet_deltaPhi_i ) ) ) ;

        if( (drMin < 0.8) && (ijet == JetID) ){
            _histograms2D.at("Signal_FatJet").Fill( FatJet_globalParT3_QCD[ijet], MET_FatJet_Mt_i, evtWeight );
        }else{
            _histograms2D.at("Bkg_FatJet").Fill( FatJet_globalParT3_QCD[ijet], MET_FatJet_Mt_i, evtWeight );
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
void HEPHero::SgnFatJetSelection() {













    //======ASSIGN VALUES TO THE OUTPUT VARIABLES==================================================
    //SgnFatJet::variable1Name = 100;      [Example]

    //======FILL THE HISTOGRAMS====================================================================
    //_histograms1D.at("histogram1DName").Fill( var, evtWeight );               [Example]
    //_histograms2D.at("histogram2DName").Fill( var1, var2, evtWeight );        [Example]

    //======FILL THE OUTPUT TREE===================================================================
    //_outputTree->Fill();

    //======FILL THE OUTPUT HDF5 INFO===============================================================
    //HDF_fill();

    return;
}


//-------------------------------------------------------------------------------------------------
// Produce systematic histograms
//-------------------------------------------------------------------------------------------------
void HEPHero::SgnFatJetSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishSgnFatJet() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
