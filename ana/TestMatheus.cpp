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

    HDF_insert("LeadingJet_pt", &LeadingJet_pt);
    HDF_insert("SubLeadingJet_pt", &SubLeadingJet_pt);
    HDF_insert("ThirdLeadingJet_pt", &ThirdLeadingJet_pt);
    HDF_insert("FourthLeadingJet_pt", &FourthLeadingJet_pt);




    HDF_insert("HLT_AK8PFJet420_TrimMass30", &HLT_AK8PFJet420_TrimMass30);
    HDF_insert("HLT_AK8PFHT800_TrimMass50", &HLT_AK8PFHT800_TrimMass50);
    HDF_insert("HLT_AK8PFHT850_TrimMass50", &HLT_AK8PFHT850_TrimMass50);
    HDF_insert("HLT_AK8PFHT900_TrimMass50", &HLT_AK8PFHT900_TrimMass50);
    HDF_insert("HLT_CaloJet500_NoJetID", &HLT_CaloJet500_NoJetID);
    HDF_insert("HLT_CaloJet550_NoJetID", &HLT_CaloJet550_NoJetID);
    HDF_insert("HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL", &HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL);
    HDF_insert("HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon", &HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon);
    HDF_insert("HLT_Trimuon5_3p5_2_Upsilon_Muon", &HLT_Trimuon5_3p5_2_Upsilon_Muon);
    HDF_insert("HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon", &HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon);
    HDF_insert("HLT_DoubleEle25_CaloIdL_MW", &HLT_DoubleEle25_CaloIdL_MW);
    HDF_insert("HLT_DoubleEle27_CaloIdL_MW", &HLT_DoubleEle27_CaloIdL_MW);
    HDF_insert("HLT_DoubleEle33_CaloIdL_MW", &HLT_DoubleEle33_CaloIdL_MW);
    HDF_insert("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350", &HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350);
    HDF_insert("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350", &HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350);
    HDF_insert("HLT_Mu27_Ele37_CaloIdL_MW", &HLT_Mu27_Ele37_CaloIdL_MW);
    HDF_insert("HLT_Mu37_Ele27_CaloIdL_MW", &HLT_Mu37_Ele27_CaloIdL_MW);
    HDF_insert("HLT_Mu37_TkMu27", &HLT_Mu37_TkMu27);
    HDF_insert("HLT_DoubleMu4_3_Bs", &HLT_DoubleMu4_3_Bs);
    HDF_insert("HLT_DoubleMu3_TkMu_DsTau3Mu", &HLT_DoubleMu3_TkMu_DsTau3Mu);
    HDF_insert("HLT_DoubleMu4_Mass3p8_DZ_PFHT350", &HLT_DoubleMu4_Mass3p8_DZ_PFHT350);
    HDF_insert("HLT_DoubleMu4_MuMuTrk_Displaced", &HLT_DoubleMu4_MuMuTrk_Displaced);
    HDF_insert("HLT_DoublePhoton70", &HLT_DoublePhoton70);
    HDF_insert("HLT_DoublePhoton85", &HLT_DoublePhoton85);
    HDF_insert("HLT_DiEle27_WPTightCaloOnly_L1DoubleEG", &HLT_DiEle27_WPTightCaloOnly_L1DoubleEG);
    HDF_insert("HLT_Ele30_WPTight_Gsf", &HLT_Ele30_WPTight_Gsf);
    HDF_insert("HLT_Ele32_WPTight_Gsf", &HLT_Ele32_WPTight_Gsf);
    HDF_insert("HLT_Ele35_WPTight_Gsf", &HLT_Ele35_WPTight_Gsf);
    HDF_insert("HLT_Ele35_WPTight_Gsf_L1EGMT", &HLT_Ele35_WPTight_Gsf_L1EGMT);
    HDF_insert("HLT_Ele38_WPTight_Gsf", &HLT_Ele38_WPTight_Gsf);
    HDF_insert("HLT_Ele40_WPTight_Gsf", &HLT_Ele40_WPTight_Gsf);
    HDF_insert("HLT_Ele32_WPTight_Gsf_L1DoubleEG", &HLT_Ele32_WPTight_Gsf_L1DoubleEG);
    HDF_insert("HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1", &HLT_IsoMu20_eta2p1_TightChargedIsoPFTauHPS27_eta2p1_TightID_CrossL1);
    HDF_insert("HLT_IsoMu24", &HLT_IsoMu24);
    HDF_insert("HLT_IsoMu24_eta2p1", &HLT_IsoMu24_eta2p1);
    HDF_insert("HLT_IsoMu27", &HLT_IsoMu27);
    HDF_insert("HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4", &HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4);
    HDF_insert("HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4", &HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4);
    HDF_insert("HLT_DoubleL2Mu50", &HLT_DoubleL2Mu50);
    HDF_insert("HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed", &HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed);
    HDF_insert("HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed", &HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed);
    HDF_insert("HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4", &HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4);
    HDF_insert("HLT_DoubleL2Mu23NoVtx_2Cha", &HLT_DoubleL2Mu23NoVtx_2Cha);
    HDF_insert("HLT_DoubleL2Mu25NoVtx_2Cha", &HLT_DoubleL2Mu25NoVtx_2Cha);
    HDF_insert("HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4", &HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4);
    HDF_insert("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL);
    HDF_insert("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL);
    HDF_insert("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ);
    HDF_insert("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ);
    HDF_insert("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8);
    HDF_insert("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8);
    HDF_insert("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8);
    HDF_insert("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8);
    HDF_insert("HLT_Mu30_TkMu0_Psi", &HLT_Mu30_TkMu0_Psi);
    HDF_insert("HLT_Mu30_TkMu0_Upsilon", &HLT_Mu30_TkMu0_Upsilon);
    HDF_insert("HLT_Mu25_TkMu0_Phi", &HLT_Mu25_TkMu0_Phi);
    HDF_insert("HLT_Mu50", &HLT_Mu50);
    HDF_insert("HLT_Mu55", &HLT_Mu55);
    HDF_insert("HLT_CascadeMu100", &HLT_CascadeMu100);
    HDF_insert("HLT_HighPtTkMu100", &HLT_HighPtTkMu100);
    HDF_insert("HLT_DiPFJetAve300_HFJEC", &HLT_DiPFJetAve300_HFJEC);
    HDF_insert("HLT_AK8PFJet500", &HLT_AK8PFJet500);
    HDF_insert("HLT_AK8PFJet550", &HLT_AK8PFJet550);
    HDF_insert("HLT_PFJet500", &HLT_PFJet500);
    HDF_insert("HLT_PFJet550", &HLT_PFJet550);
    HDF_insert("HLT_PFJetFwd40", &HLT_PFJetFwd40);
    HDF_insert("HLT_PFJetFwd400", &HLT_PFJetFwd400);
    HDF_insert("HLT_PFJetFwd450", &HLT_PFJetFwd450);
    HDF_insert("HLT_PFJetFwd500", &HLT_PFJetFwd500);
    HDF_insert("HLT_AK8PFJetFwd400", &HLT_AK8PFJetFwd400);
    HDF_insert("HLT_AK8PFJetFwd450", &HLT_AK8PFJetFwd450);
    HDF_insert("HLT_AK8PFJetFwd500", &HLT_AK8PFJetFwd500);
    HDF_insert("HLT_PFHT1050", &HLT_PFHT1050);
    HDF_insert("HLT_PFHT500_PFMET100_PFMHT100_IDTight", &HLT_PFHT500_PFMET100_PFMHT100_IDTight);
    HDF_insert("HLT_PFHT500_PFMET110_PFMHT110_IDTight", &HLT_PFHT500_PFMET110_PFMHT110_IDTight);
    HDF_insert("HLT_PFHT700_PFMET85_PFMHT85_IDTight", &HLT_PFHT700_PFMET85_PFMHT85_IDTight);
    HDF_insert("HLT_PFHT800_PFMET75_PFMHT75_IDTight", &HLT_PFHT800_PFMET75_PFMHT75_IDTight);
    HDF_insert("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight);
    HDF_insert("HLT_PFMET130_PFMHT130_IDTight", &HLT_PFMET130_PFMHT130_IDTight);
    HDF_insert("HLT_PFMET140_PFMHT140_IDTight", &HLT_PFMET140_PFMHT140_IDTight);
    HDF_insert("HLT_PFMET120_PFMHT120_IDTight_PFHT60", &HLT_PFMET120_PFMHT120_IDTight_PFHT60);
    HDF_insert("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60);
    HDF_insert("HLT_PFMETTypeOne140_PFMHT140_IDTight", &HLT_PFMETTypeOne140_PFMHT140_IDTight);
    HDF_insert("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight);
    HDF_insert("HLT_PFMETNoMu130_PFMHTNoMu130_IDTight", &HLT_PFMETNoMu130_PFMHTNoMu130_IDTight);
    HDF_insert("HLT_PFMETNoMu140_PFMHTNoMu140_IDTight", &HLT_PFMETNoMu140_PFMHTNoMu140_IDTight);
    HDF_insert("HLT_CaloMET350_NotCleaned", &HLT_CaloMET350_NotCleaned);
    HDF_insert("HLT_PFMET250_NotCleaned", &HLT_PFMET250_NotCleaned);
    HDF_insert("HLT_PFMET300_NotCleaned", &HLT_PFMET300_NotCleaned);
    HDF_insert("HLT_PFMET200_BeamHaloCleaned", &HLT_PFMET200_BeamHaloCleaned);
    HDF_insert("HLT_PFMETTypeOne200_BeamHaloCleaned", &HLT_PFMETTypeOne200_BeamHaloCleaned);
    HDF_insert("HLT_MET105_IsoTrk50", &HLT_MET105_IsoTrk50);
    HDF_insert("HLT_MET120_IsoTrk50", &HLT_MET120_IsoTrk50);
    HDF_insert("HLT_Mu12_DoublePFJets40MaxDeta1p6_DoublePFBTagDeepJet_p71", &HLT_Mu12_DoublePFJets40MaxDeta1p6_DoublePFBTagDeepJet_p71);
    HDF_insert("HLT_Mu12_DoublePFJets54MaxDeta1p6_DoublePFBTagDeepJet_p71", &HLT_Mu12_DoublePFJets54MaxDeta1p6_DoublePFBTagDeepJet_p71);
    HDF_insert("HLT_DoublePFJets116MaxDeta1p6_DoublePFBTagDeepJet_p71", &HLT_DoublePFJets116MaxDeta1p6_DoublePFBTagDeepJet_p71);
    HDF_insert("HLT_DoublePFJets128MaxDeta1p6_DoublePFBTagDeepJet_p71", &HLT_DoublePFJets128MaxDeta1p6_DoublePFBTagDeepJet_p71);
    HDF_insert("HLT_Photon300_NoHE", &HLT_Photon300_NoHE);
    HDF_insert("HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ", &HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ);
    HDF_insert("HLT_Mu8_DiEle12_CaloIdL_TrackIdL", &HLT_Mu8_DiEle12_CaloIdL_TrackIdL);
    HDF_insert("HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ", &HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ);
    HDF_insert("HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350", &HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350);
    HDF_insert("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
    HDF_insert("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30);
    HDF_insert("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30);
    HDF_insert("HLT_BTagMu_AK4Jet300_Mu5", &HLT_BTagMu_AK4Jet300_Mu5);
    HDF_insert("HLT_BTagMu_AK8Jet170_DoubleMu5", &HLT_BTagMu_AK8Jet170_DoubleMu5);
    HDF_insert("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
    HDF_insert("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL);
    HDF_insert("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
    HDF_insert("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL", &HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL);
    HDF_insert("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL", &HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);
    HDF_insert("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
    HDF_insert("HLT_Photon20", &HLT_Photon20);
    HDF_insert("HLT_Photon200", &HLT_Photon200);
    HDF_insert("HLT_Photon110EB_TightID_TightIso", &HLT_Photon110EB_TightID_TightIso);
    HDF_insert("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90", &HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90);
    HDF_insert("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95", &HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95);
    HDF_insert("HLT_Photon35_TwoProngs35", &HLT_Photon35_TwoProngs35);
    HDF_insert("HLT_IsoMu24_TwoProngs35", &HLT_IsoMu24_TwoProngs35);
    HDF_insert("HLT_Dimuon0_Jpsi", &HLT_Dimuon0_Jpsi);
    HDF_insert("HLT_Dimuon0_Jpsi3p5_Muon2", &HLT_Dimuon0_Jpsi3p5_Muon2);
    HDF_insert("HLT_TripleMu_5_3_3_Mass3p8_DZ", &HLT_TripleMu_5_3_3_Mass3p8_DZ);
    HDF_insert("HLT_TripleMu_10_5_5_DZ", &HLT_TripleMu_10_5_5_DZ);
    HDF_insert("HLT_TripleMu_12_10_5", &HLT_TripleMu_12_10_5);
    HDF_insert("HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15);
    HDF_insert("HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1);
    HDF_insert("HLT_DoubleMu3_DZ_PFMET50_PFMHT60", &HLT_DoubleMu3_DZ_PFMET50_PFMHT60);
    HDF_insert("HLT_DoubleMu3_DZ_PFMET70_PFMHT70", &HLT_DoubleMu3_DZ_PFMET70_PFMHT70);
    HDF_insert("HLT_DoubleMu3_DZ_PFMET90_PFMHT90", &HLT_DoubleMu3_DZ_PFMET90_PFMHT90);
    HDF_insert("HLT_DoubleMu4_JpsiTrkTrk_Displaced", &HLT_DoubleMu4_JpsiTrkTrk_Displaced);
    HDF_insert("HLT_DoubleMu43NoFiltersNoVtx", &HLT_DoubleMu43NoFiltersNoVtx);
    HDF_insert("HLT_DoubleMu48NoFiltersNoVtx", &HLT_DoubleMu48NoFiltersNoVtx);
    HDF_insert("HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL", &HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL);
    HDF_insert("HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL", &HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL);
    HDF_insert("HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL", &HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL);
    HDF_insert("HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL", &HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL);
    HDF_insert("HLT_HT430_DisplacedDijet40_DisplacedTrack", &HLT_HT430_DisplacedDijet40_DisplacedTrack);
    HDF_insert("HLT_HT500_DisplacedDijet40_DisplacedTrack", &HLT_HT500_DisplacedDijet40_DisplacedTrack);
    HDF_insert("HLT_HT430_DisplacedDijet60_DisplacedTrack", &HLT_HT430_DisplacedDijet60_DisplacedTrack);
    HDF_insert("HLT_HT650_DisplacedDijet60_Inclusive", &HLT_HT650_DisplacedDijet60_Inclusive);
    HDF_insert("HLT_DiJet110_35_Mjj650_PFMET110", &HLT_DiJet110_35_Mjj650_PFMET110);
    HDF_insert("HLT_DiJet110_35_Mjj650_PFMET120", &HLT_DiJet110_35_Mjj650_PFMET120);
    HDF_insert("HLT_DiJet110_35_Mjj650_PFMET130", &HLT_DiJet110_35_Mjj650_PFMET130);
    HDF_insert("HLT_TripleJet110_35_35_Mjj650_PFMET110", &HLT_TripleJet110_35_35_Mjj650_PFMET110);
    HDF_insert("HLT_TripleJet110_35_35_Mjj650_PFMET120", &HLT_TripleJet110_35_35_Mjj650_PFMET120);
    HDF_insert("HLT_TripleJet110_35_35_Mjj650_PFMET130", &HLT_TripleJet110_35_35_Mjj650_PFMET130);
    HDF_insert("HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned", &HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned);
    HDF_insert("HLT_Ele28_eta2p1_WPTight_Gsf_HT150", &HLT_Ele28_eta2p1_WPTight_Gsf_HT150);
    HDF_insert("HLT_Ele28_HighEta_SC20_Mass55", &HLT_Ele28_HighEta_SC20_Mass55);
    HDF_insert("HLT_Ele15_IsoVVVL_PFHT450_PFMET50", &HLT_Ele15_IsoVVVL_PFHT450_PFMET50);
    HDF_insert("HLT_Ele15_IsoVVVL_PFHT450", &HLT_Ele15_IsoVVVL_PFHT450);
    HDF_insert("HLT_Ele50_IsoVVVL_PFHT450", &HLT_Ele50_IsoVVVL_PFHT450);
    HDF_insert("HLT_Ele15_IsoVVVL_PFHT600", &HLT_Ele15_IsoVVVL_PFHT600);
    HDF_insert("HLT_Mu4_TrkIsoVVL_DiPFJet90_40_DEta3p5_MJJ750_HTT300_PFMETNoMu60", &HLT_Mu4_TrkIsoVVL_DiPFJet90_40_DEta3p5_MJJ750_HTT300_PFMETNoMu60);
    HDF_insert("HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60", &HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60);
    HDF_insert("HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60", &HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60);
    HDF_insert("HLT_Mu15_IsoVVVL_PFHT450_PFMET50", &HLT_Mu15_IsoVVVL_PFHT450_PFMET50);
    HDF_insert("HLT_Mu15_IsoVVVL_PFHT450", &HLT_Mu15_IsoVVVL_PFHT450);
    HDF_insert("HLT_Mu50_IsoVVVL_PFHT450", &HLT_Mu50_IsoVVVL_PFHT450);
    HDF_insert("HLT_Mu15_IsoVVVL_PFHT600", &HLT_Mu15_IsoVVVL_PFHT600);
    HDF_insert("HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight);
    HDF_insert("HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight);
    HDF_insert("HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight", &HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight);
    HDF_insert("HLT_Dimuon12_Upsilon_y1p4", &HLT_Dimuon12_Upsilon_y1p4);
    HDF_insert("HLT_Dimuon14_Phi_Barrel_Seagulls", &HLT_Dimuon14_Phi_Barrel_Seagulls);
    HDF_insert("HLT_Dimuon25_Jpsi", &HLT_Dimuon25_Jpsi);
    HDF_insert("HLT_Dimuon18_PsiPrime", &HLT_Dimuon18_PsiPrime);
    HDF_insert("HLT_Dimuon18_PsiPrime_noCorrL1", &HLT_Dimuon18_PsiPrime_noCorrL1);
    HDF_insert("HLT_Dimuon24_Upsilon_noCorrL1", &HLT_Dimuon24_Upsilon_noCorrL1);
    HDF_insert("HLT_Dimuon24_Phi_noCorrL1", &HLT_Dimuon24_Phi_noCorrL1);
    HDF_insert("HLT_Dimuon25_Jpsi_noCorrL1", &HLT_Dimuon25_Jpsi_noCorrL1);
    HDF_insert("HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8", &HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8);
    HDF_insert("HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ", &HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ);
    HDF_insert("HLT_DiMu9_Ele9_CaloIdL_TrackIdL", &HLT_DiMu9_Ele9_CaloIdL_TrackIdL);
    HDF_insert("HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx", &HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx);
    HDF_insert("HLT_Mu17_Photon30_IsoCaloId", &HLT_Mu17_Photon30_IsoCaloId);
    HDF_insert("HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165", &HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165);
    HDF_insert("HLT_Ele115_CaloIdVT_GsfTrkIdT", &HLT_Ele115_CaloIdVT_GsfTrkIdT);
    HDF_insert("HLT_Ele135_CaloIdVT_GsfTrkIdT", &HLT_Ele135_CaloIdVT_GsfTrkIdT);
    HDF_insert("HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15", &HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15);
    HDF_insert("HLT_ECALHT800", &HLT_ECALHT800);
    HDF_insert("HLT_HcalNZS", &HLT_HcalNZS);
    HDF_insert("HLT_HcalPhiSym", &HLT_HcalPhiSym);
    HDF_insert("HLT_HcalIsolatedbunch", &HLT_HcalIsolatedbunch);
    HDF_insert("HLT_IsoTrackHE", &HLT_IsoTrackHE);
    HDF_insert("HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL", &HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL);
    HDF_insert("HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3", &HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3);
    HDF_insert("HLT_Mu18_Mu9_SameSign", &HLT_Mu18_Mu9_SameSign);
    HDF_insert("HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05", &HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05);
    HDF_insert("HLT_DoubleMu3_DCA_PFMET50_PFMHT60", &HLT_DoubleMu3_DCA_PFMET50_PFMHT60);
    HDF_insert("HLT_TripleMu_5_3_3_Mass3p8_DCA", &HLT_TripleMu_5_3_3_Mass3p8_DCA);
    HDF_insert("HLT_Ele24_eta2p1_WPTight_Gsf_LooseDeepTauPFTauHPS30_eta2p1_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_LooseDeepTauPFTauHPS30_eta2p1_CrossL1);
    HDF_insert("HLT_IsoMu20_eta2p1_LooseDeepTauPFTauHPS27_eta2p1_CrossL1", &HLT_IsoMu20_eta2p1_LooseDeepTauPFTauHPS27_eta2p1_CrossL1);
    HDF_insert("HLT_IsoMu24_eta2p1_LooseDeepTauPFTauHPS180_eta2p1", &HLT_IsoMu24_eta2p1_LooseDeepTauPFTauHPS180_eta2p1);
    HDF_insert("HLT_IsoMu24_eta2p1_LooseDeepTauPFTauHPS30_eta2p1_CrossL1", &HLT_IsoMu24_eta2p1_LooseDeepTauPFTauHPS30_eta2p1_CrossL1);
    HDF_insert("HLT_IsoMu24_eta2p1_MediumDeepTauPFTauHPS35_L2NN_eta2p1_CrossL1", &HLT_IsoMu24_eta2p1_MediumDeepTauPFTauHPS35_L2NN_eta2p1_CrossL1);
    HDF_insert("HLT_LooseDeepTauPFTauHPS180_L2NN_eta2p1", &HLT_LooseDeepTauPFTauHPS180_L2NN_eta2p1);
    HDF_insert("HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepJet_4p5", &HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepJet_4p5);
    HDF_insert("HLT_PFHT400_FivePFJet_100_100_60_30_30_DoublePFBTagDeepJet_4p5", &HLT_PFHT400_FivePFJet_100_100_60_30_30_DoublePFBTagDeepJet_4p5);
    HDF_insert("HLT_PFHT400_FivePFJet_120_120_60_30_30_DoublePFBTagDeepJet_4p5", &HLT_PFHT400_FivePFJet_120_120_60_30_30_DoublePFBTagDeepJet_4p5);
    HDF_insert("HLT_PFHT400_SixPFJet32_DoublePFBTagDeepJet_2p94", &HLT_PFHT400_SixPFJet32_DoublePFBTagDeepJet_2p94);
    HDF_insert("HLT_PFHT450_SixPFJet36_PFBTagDeepJet_1p59", &HLT_PFHT450_SixPFJet36_PFBTagDeepJet_1p59);
    HDF_insert("HLT_QuadPFJet103_88_75_15_DoublePFBTagDeepJet_1p3_7p7_VBF1", &HLT_QuadPFJet103_88_75_15_DoublePFBTagDeepJet_1p3_7p7_VBF1);
    HDF_insert("HLT_QuadPFJet103_88_75_15_PFBTagDeepJet_1p3_VBF2", &HLT_QuadPFJet103_88_75_15_PFBTagDeepJet_1p3_VBF2);
    HDF_insert("HLT_QuadPFJet105_88_76_15_DoublePFBTagDeepJet_1p3_7p7_VBF1", &HLT_QuadPFJet105_88_76_15_DoublePFBTagDeepJet_1p3_7p7_VBF1);
    HDF_insert("HLT_QuadPFJet105_88_76_15_PFBTagDeepJet_1p3_VBF2", &HLT_QuadPFJet105_88_76_15_PFBTagDeepJet_1p3_VBF2);
    HDF_insert("HLT_QuadPFJet111_90_80_15_DoublePFBTagDeepJet_1p3_7p7_VBF1", &HLT_QuadPFJet111_90_80_15_DoublePFBTagDeepJet_1p3_7p7_VBF1);
    HDF_insert("HLT_QuadPFJet111_90_80_15_PFBTagDeepJet_1p3_VBF2", &HLT_QuadPFJet111_90_80_15_PFBTagDeepJet_1p3_VBF2);
    HDF_insert("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepJet_1p5", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepJet_1p5);
    HDF_insert("HLT_QuadPFJet70_50_40_35_PFBTagParticleNet_2BTagSum0p65", &HLT_QuadPFJet70_50_40_35_PFBTagParticleNet_2BTagSum0p65);
    HDF_insert("HLT_QuadPFJet70_50_45_35_PFBTagParticleNet_2BTagSum0p65", &HLT_QuadPFJet70_50_45_35_PFBTagParticleNet_2BTagSum0p65);
    HDF_insert("HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35);
    HDF_insert("HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35);
    HDF_insert("HLT_AK8PFJet425_SoftDropMass40", &HLT_AK8PFJet425_SoftDropMass40);
    HDF_insert("HLT_AK8PFJet450_SoftDropMass40", &HLT_AK8PFJet450_SoftDropMass40);
    HDF_insert("HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30);
    HDF_insert("HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30);
    HDF_insert("HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30);
    HDF_insert("HLT_DoubleL2Mu10NoVtx_2Cha_VetoL3Mu0DxyMax1cm", &HLT_DoubleL2Mu10NoVtx_2Cha_VetoL3Mu0DxyMax1cm);
    HDF_insert("HLT_DoubleL3Mu16_10NoVtx_DxyMin0p01cm", &HLT_DoubleL3Mu16_10NoVtx_DxyMin0p01cm);
    HDF_insert("HLT_Mu20NoFiltersNoVtxDisplaced_Photon20_CaloCustomId", &HLT_Mu20NoFiltersNoVtxDisplaced_Photon20_CaloCustomId);
    HDF_insert("HLT_DoubleMediumChargedIsoDisplacedPFTauHPS32_Trk1_eta2p1", &HLT_DoubleMediumChargedIsoDisplacedPFTauHPS32_Trk1_eta2p1);
    HDF_insert("HLT_Mu6HT240_DisplacedDijet30_Inclusive1PtrkShortSig5_DisplacedLoose", &HLT_Mu6HT240_DisplacedDijet30_Inclusive1PtrkShortSig5_DisplacedLoose);
    HDF_insert("HLT_Mu6HT240_DisplacedDijet35_Inclusive0PtrkShortSig5", &HLT_Mu6HT240_DisplacedDijet35_Inclusive0PtrkShortSig5);
    HDF_insert("HLT_Mu6HT240_DisplacedDijet35_Inclusive1PtrkShortSig5_DisplacedLoose", &HLT_Mu6HT240_DisplacedDijet35_Inclusive1PtrkShortSig5_DisplacedLoose);
    HDF_insert("HLT_Mu6HT240_DisplacedDijet40_Inclusive0PtrkShortSig5", &HLT_Mu6HT240_DisplacedDijet40_Inclusive0PtrkShortSig5);
    HDF_insert("HLT_Mu6HT240_DisplacedDijet40_Inclusive1PtrkShortSig5_DisplacedLoose", &HLT_Mu6HT240_DisplacedDijet40_Inclusive1PtrkShortSig5_DisplacedLoose);
    HDF_insert("HLT_HT430_DisplacedDijet40_Inclusive1PtrkShortSig5", &HLT_HT430_DisplacedDijet40_Inclusive1PtrkShortSig5);
    HDF_insert("HLT_CaloMET60_DTClusterNoMB1S50", &HLT_CaloMET60_DTClusterNoMB1S50);
    HDF_insert("HLT_L1MET_DTClusterNoMB1S50", &HLT_L1MET_DTClusterNoMB1S50);
    HDF_insert("HLT_PFMET105_IsoTrk50", &HLT_PFMET105_IsoTrk50);






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
