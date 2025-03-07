#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace TestMatheus{
	
    //int variable1Name;   [example]
    int BJet_DeepJetLoose,BJet_robustParticleTransformerLoose,BJet_particleNETLoose;
}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupTestMatheus() {
    //======SETUP CUTFLOW==========================================================================
    _cutFlow.insert(pair<string,double>("00_MET_PT_more_200_and_MHT_more_200", 0) );
    _cutFlow.insert(pair<string,double>("01_NfatJets_more_0", 0) );
    _cutFlow.insert(pair<string,double>("02_LeadingFatPt_more_200", 0) );
    _cutFlow.insert(pair<string,double>("03_NbJets_more_0", 0) );
    _cutFlow.insert(pair<string,double>("04_Leptons_equal_0", 0) );
    _cutFlow.insert(pair<string,double>("05_Omega_more_0p3", 0) );
//==================================================================================================


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

    HDF_insert("LeadingJet_pt", &LeadingJet_pt);
    HDF_insert("SubLeadingJet_pt", &SubLeadingJet_pt);
    HDF_insert("ThirdLeadingJet_pt", &ThirdLeadingJet_pt);
    HDF_insert("FourthLeadingJet_pt", &FourthLeadingJet_pt);

    HDF_insert("MET_phi", &MET_phi);
    HDF_insert("MET_pt", &MET_pt);

    HDF_insert("PuppiMET_phi", &PuppiMET_phi);
    HDF_insert("PuppiMET_pt", &PuppiMET_pt);

    
    HDF_insert("HLT_AK8PFJet500", &HLT_AK8PFJet500);
    HDF_insert("HLT_AK8PFJet550", &HLT_AK8PFJet550);
    HDF_insert("HLT_AK8PFJet420_TrimMass30", &HLT_AK8PFJet420_TrimMass30);
    HDF_insert("HLT_AK8PFHT800_TrimMass50", &HLT_AK8PFHT800_TrimMass50);
    HDF_insert("HLT_AK8PFHT850_TrimMass50", &HLT_AK8PFHT850_TrimMass50);
    HDF_insert("HLT_AK8PFHT900_TrimMass50", &HLT_AK8PFHT900_TrimMass50);
    HDF_insert("HLT_AK8PFJetFwd400", &HLT_AK8PFJetFwd400);
    HDF_insert("HLT_AK8PFJetFwd450", &HLT_AK8PFJetFwd450);
    HDF_insert("HLT_AK8PFJetFwd500", &HLT_AK8PFJetFwd500);
    HDF_insert("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight);
    HDF_insert("HLT_MET105_IsoTrk50", &HLT_MET105_IsoTrk50);
    HDF_insert("HLT_BTagMu_AK8Jet170_DoubleMu5", &HLT_BTagMu_AK8Jet170_DoubleMu5);
    HDF_insert("HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35);
    HDF_insert("HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35);
    HDF_insert("HLT_AK8PFJet425_SoftDropMass40", &HLT_AK8PFJet425_SoftDropMass40);
    HDF_insert("HLT_AK8PFJet450_SoftDropMass40", &HLT_AK8PFJet450_SoftDropMass40);
    HDF_insert("HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30);
    HDF_insert("HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30);
    HDF_insert("HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30);
    HDF_insert("HLT_PFHT500_PFMET100_PFMHT100_IDTight", &HLT_PFHT500_PFMET100_PFMHT100_IDTight);
    HDF_insert("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60);
    HDF_insert("HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepJet_4p5", &HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepJet_4p5);
    HDF_insert("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight);

    HDF_insert("BJet_DeepJetLoose",&TestMatheus::BJet_DeepJetLoose);
    HDF_insert("BJet_robustParticleTransformerLoose",&TestMatheus::BJet_robustParticleTransformerLoose);
    HDF_insert("BJet_particleNETLoose",&TestMatheus::BJet_particleNETLoose);


    HDF_insert("MHT",&MHT);

    HDF_insert("LeadingFatJet_pt",&LeadingFatJet_pt);
    HDF_insert("SubLeadingFatJet_pt",&SubLeadingFatJet_pt);

    HDF_insert("LeadingFatJet_mass",&LeadingFatJet_mass);
    HDF_insert("LeadingFatJet_msoftdrop",&LeadingFatJet_msoftdrop);
    HDF_insert("MET_FatJet_Mt",&MET_FatJet_Mt);

    HDF_insert("OmegaMin",&OmegaMin);

    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::TestMatheusRegion() {

    if( !Trigger() ) return false;
    LeptonSelection();
    JetSelection();
    FatjetSelection();
    Get_Jet_Angular_Variables();
    
    //if (!(MET_pt > 200 && MHT > 200) ) return false;
    _cutFlow.at("00_MET_PT_more_200_and_MHT_more_200") += evtWeight;
  
    //if ( !(NfatJets>0) ) return false;
    _cutFlow.at("01_NfatJets_more_0") += evtWeight;
    
    //if ( !(LeadingFatJet_pt>200) ) return false;
    _cutFlow.at("02_LeadingFatPt_more_200") += evtWeight;
      
    //if ( !(Nbjets>0) ) return false;
    _cutFlow.at("03_NbJets_more_0") += evtWeight;
  
    //if (!(Nelectrons==0 && Nmuons==0) ) return false;
    _cutFlow.at("04_Leptons_equal_0") += evtWeight;

    //if (OmegaMin<0.3) retunr false;
    _cutFlow.at("05_Omega_more_0p3") += evtWeight;
  
  



    return true;
}


//-------------------------------------------------------------------------------------------------
// Write your analysis code here
//-------------------------------------------------------------------------------------------------
void HEPHero::TestMatheusSelection() {

    TestMatheus::BJet_DeepJetLoose = 0;
    TestMatheus::BJet_robustParticleTransformerLoose = 0;
    TestMatheus::BJet_particleNETLoose = 0;


    for(int ijet = 0; ijet < nJet; ++ijet){

        if( Jet_pt[ijet] <= JET_PT_CUT ) continue;
        if( Jet_jetId[ijet] < JET_ID_WP ) continue;
        if( Jet_LepOverlap[ijet] ) continue;
        //if( (Jet_pt[ijet] < 50) && (Jet_puId[ijet] < JET_PUID_WP) ) continue;
        if ( (Jet_pt[ijet] < 50) && ( 2.5 < abs(Jet_eta[ijet]) && 3 > abs(Jet_eta[ijet]) ) ) continue;   // due to eta spikes (since we apply a cut in jet with more than 2.5 eta, this cut is not necessary, but I will leave this here for the future)


        //DeepJet
        if( JetBTAG( ijet, 0 ) ){
            TestMatheus::BJet_DeepJetLoose += 1;  
        }
        //robustParticleTransformer
        if( JetBTAG( ijet, 10 ) ){
            TestMatheus::BJet_robustParticleTransformerLoose += 1;  
        }
        //particleNET
        if( JetBTAG( ijet, 5 ) ){
            TestMatheus::BJet_particleNETLoose += 1;  
        }
  


    }
    











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

