#include "HEPHero.h"


//-------------------------------------------------------------------------------------------------
// FILL CONTROL VARIABLES WITH INPUT FILE LINES
//-------------------------------------------------------------------------------------------------
void HEPHero::FillControlVariables( string key, string value){

    //----CORRECTIONS------------------------------------------------------------------------------
    // if( key == "PILEUP_WGT"                 )   apply_pileup_wgt = ( atoi(value.c_str()) == 1 );
    // if( key == "ELECTRON_ID_WGT"            )   apply_electron_wgt = ( atoi(value.c_str()) == 1 );
    // if( key == "MUON_ID_WGT"                )   apply_muon_wgt = ( atoi(value.c_str()) == 1 );
    // if( key == "JET_PUID_WGT"               )   apply_jet_puid_wgt = ( atoi(value.c_str()) == 1 );
    // if( key == "BTAG_WGT"                   )   apply_btag_wgt = ( atoi(value.c_str()) == 1 );
    // if( key == "TRIGGER_WGT"                )   apply_trigger_wgt = ( atoi(value.c_str()) == 1 );
    // if( key == "PREFIRING_WGT"              )   apply_prefiring_wgt = ( atoi(value.c_str()) == 1 );
    // if( key == "JER_CORR"                   )   apply_jer_corr = ( atoi(value.c_str()) == 1 );
    // if( key == "MET_XY_CORR"                )   apply_met_xy_corr = ( atoi(value.c_str()) == 1 );
    // if( key == "MET_RECOIL_CORR"            )   apply_met_recoil_corr = ( atoi(value.c_str()) == 1 );
    // if( key == "TOP_PT_WGT"                 )   apply_top_pt_wgt = ( atoi(value.c_str()) == 1 );
    // if( key == "W_PT_WGT"                   )   apply_w_pt_wgt = ( atoi(value.c_str()) == 1 );
    // if( key == "VJETS_HT_WGT"               )   apply_vjets_HT_wgt = ( atoi(value.c_str()) == 1 );
    // if( key == "MUON_ROC_CORR"              )   apply_muon_roc_corr = ( atoi(value.c_str()) == 1 );

    //----METADATA FILES---------------------------------------------------------------------------
    // if( key == "lumi_certificate"           )   certificate_file = value;
    // if( key == "pdf_type"                   )   PDF_file = value;
    // if( key == "pileup"                     )   pileup_file = value;
    // if( key == "electron"                   )   electron_file = value;
    // if( key == "muon"                       )   muon_file = value;
    // if( key == "JES_MC"                     )   JES_MC_file = value;
    // if( key == "jet_puID"                   )   jet_puid_file = value;
    // if( key == "btag_SF"                    )   btag_SF_file = value;
    // if( key == "btag_eff"                   )   btag_eff_file = value;
    // if( key == "trigger"                    )   trigger_SF_file = value;
    // //if( key == "JER_MC"                     )   JER_file = value;
    // //if( key == "JER_SF_MC"                  )   JER_SF_file = value;
    // if( key == "JERC"                       )   jet_jerc_file = value;
    // if( key == "mu_RoccoR"                  )   muon_roc_file = value;
    // if( key == "Z_recoil"                   )   Z_recoil_file = value;
    // if( key == "NN_prep_keras"              )   preprocessing_keras_file = value;
    // if( key == "NN_model_keras"             )   model_keras_file = value;
    if( key == "NN_model"                      )   NN_model_file = value;

    //----SELECTION--------------------------------------------------------------------------------
    if( key == "JET_ETA_CUT"                )   JET_ETA_CUT = atof(value.c_str());
    if( key == "JET_PT_CUT"                 )   JET_PT_CUT = atof(value.c_str());
    if( key == "JET_ID_WP"                  )   JET_ID_WP = atoi(value.c_str());
    if( key == "JET_PUID_WP"                )   JET_PUID_WP = atoi(value.c_str());
    if( key == "JET_BTAG_WP"                )   JET_BTAG_WP = atoi(value.c_str());
    if( key == "JET_LEP_DR_ISO_CUT"         )   JET_LEP_DR_ISO_CUT = atof(value.c_str());

    if( key == "FAT_JET_PT_CUT"             )   FAT_JET_PT_CUT = atof(value.c_str());
    if( key == "FAT_JET_ETA_CUT"            )   FAT_JET_ETA_CUT = atof(value.c_str());
    if( key == "FAT_JET_ID_WP"              )   FAT_JET_ID_WP = atoi(value.c_str());

    if( key == "ELECTRON_GAP_LOWER_CUT"     )   ELECTRON_GAP_LOWER_CUT = atof(value.c_str());
    if( key == "ELECTRON_GAP_UPPER_CUT"     )   ELECTRON_GAP_UPPER_CUT = atof(value.c_str());
    if( key == "ELECTRON_ETA_CUT"           )   ELECTRON_ETA_CUT = atof(value.c_str());
    if( key == "ELECTRON_PT_CUT"            )   ELECTRON_PT_CUT = atof(value.c_str());
    if( key == "ELECTRON_LOW_PT_CUT"        )   ELECTRON_LOW_PT_CUT = atof(value.c_str());
    if( key == "ELECTRON_ID_WP"             )   ELECTRON_ID_WP = atoi(value.c_str());

    if( key == "MUON_ETA_CUT"               )   MUON_ETA_CUT = atof(value.c_str());
    if( key == "MUON_PT_CUT"                )   MUON_PT_CUT = atof(value.c_str());
    if( key == "MUON_LOW_PT_CUT"            )   MUON_LOW_PT_CUT = atof(value.c_str());
    if( key == "MUON_ID_WP"                 )   MUON_ID_WP = atoi(value.c_str());
    if( key == "MUON_ISO_WP"                )   MUON_ISO_WP = atoi(value.c_str());

    if( key == "TAU_VS_ELE_ISO_WP"          )   TAU_VS_ELE_ISO_WP = atoi(value.c_str());
    if( key == "TAU_VS_JET_ISO_WP"          )   TAU_VS_JET_ISO_WP = atoi(value.c_str());
    if( key == "TAU_VS_MU_ISO_WP"           )   TAU_VS_MU_ISO_WP = atoi(value.c_str());
    if( key == "TAU_PT_CUT"                 )   TAU_PT_CUT = atoi(value.c_str());
    if( key == "TAU_ETA_CUT"                )   TAU_ETA_CUT = atoi(value.c_str());

    if( key == "OMEGA_CUT"                  )   OMEGA_CUT = atof(value.c_str());

}


//-------------------------------------------------------------------------------------------------
// Init
//-------------------------------------------------------------------------------------------------
bool HEPHero::Init() {
    
    //======SET HISTOGRAMS STYLE===================================================================
    setStyle(1.0,true,0.15);

    if( _ANALYSIS != "GEN" ){
        //======SET THE BRANCH ADDRESSES===========================================================
        _inputTree->SetBranchAddress("run", &run);
        _inputTree->SetBranchAddress("luminosityBlock", &luminosityBlock);
        _inputTree->SetBranchAddress("event", &event);
        _inputTree->SetBranchAddress("bunchCrossing", &bunchCrossing);
        
        _inputTree->SetBranchAddress("nElectron", &nElectron);
        _inputTree->SetBranchAddress("Electron_cutBased", Electron_cutBased);
        _inputTree->SetBranchAddress("Electron_mvaIso_WP80", Electron_mvaIso_WP80);
        _inputTree->SetBranchAddress("Electron_mvaIso_WP90", Electron_mvaIso_WP90);
        _inputTree->SetBranchAddress("Electron_charge", Electron_charge);
        _inputTree->SetBranchAddress("Electron_mass", Electron_mass);
        _inputTree->SetBranchAddress("Electron_phi", Electron_phi);
        _inputTree->SetBranchAddress("Electron_pt", Electron_pt);
        _inputTree->SetBranchAddress("Electron_deltaEtaSC", Electron_deltaEtaSC);
        _inputTree->SetBranchAddress("Electron_eta", Electron_eta);
        
        _inputTree->SetBranchAddress("nFatJet", &nFatJet);
        _inputTree->SetBranchAddress("FatJet_eta", FatJet_eta);
        _inputTree->SetBranchAddress("FatJet_mass", FatJet_mass);
        _inputTree->SetBranchAddress("FatJet_msoftdrop", FatJet_msoftdrop);
        
        _inputTree->SetBranchAddress("FatJet_particleNetLegacy_QCD", FatJet_particleNetLegacy_QCD);
        _inputTree->SetBranchAddress("FatJet_particleNetLegacy_Xbb", FatJet_particleNetLegacy_Xbb);
        _inputTree->SetBranchAddress("FatJet_particleNetLegacy_Xcc", FatJet_particleNetLegacy_Xcc);
        _inputTree->SetBranchAddress("FatJet_particleNetLegacy_Xqq", FatJet_particleNetLegacy_Xqq);
        
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_H4qvsQCD", FatJet_particleNetWithMass_H4qvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_HbbvsQCD", FatJet_particleNetWithMass_HbbvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_HccvsQCD", FatJet_particleNetWithMass_HccvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_QCD", FatJet_particleNetWithMass_QCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_TvsQCD", FatJet_particleNetWithMass_TvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_WvsQCD", FatJet_particleNetWithMass_WvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_ZvsQCD", FatJet_particleNetWithMass_ZvsQCD);
        
        _inputTree->SetBranchAddress("FatJet_particleNet_WVsQCD", FatJet_particleNet_WVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XbbVsQCD", FatJet_particleNet_XbbVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XccVsQCD", FatJet_particleNet_XccVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XggVsQCD", FatJet_particleNet_XggVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XqqVsQCD", FatJet_particleNet_XqqVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XteVsQCD", FatJet_particleNet_XteVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XtmVsQCD", FatJet_particleNet_XtmVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XttVsQCD", FatJet_particleNet_XttVsQCD);
        
        _inputTree->SetBranchAddress("FatJet_phi", FatJet_phi);
        _inputTree->SetBranchAddress("FatJet_pt", FatJet_pt);


        _inputTree->SetBranchAddress("nGenPart", &nGenPart);
        _inputTree->SetBranchAddress("GenPart_genPartIdxMother", GenPart_genPartIdxMother);
        _inputTree->SetBranchAddress("GenPart_statusFlags", GenPart_statusFlags);
        _inputTree->SetBranchAddress("GenPart_pdgId", GenPart_pdgId);
        _inputTree->SetBranchAddress("GenPart_status", GenPart_status);
        _inputTree->SetBranchAddress("GenPart_eta", GenPart_eta);
        _inputTree->SetBranchAddress("GenPart_mass", GenPart_mass);
        _inputTree->SetBranchAddress("GenPart_phi", GenPart_phi);
        _inputTree->SetBranchAddress("GenPart_pt", GenPart_pt);
        
        _inputTree->SetBranchAddress("nIsoTrack", &nIsoTrack);
        
        _inputTree->SetBranchAddress("nJet", &nJet);
        _inputTree->SetBranchAddress("Jet_btagUParTAK4B", Jet_btagUParTAK4B);
        _inputTree->SetBranchAddress("Jet_eta", Jet_eta);
        _inputTree->SetBranchAddress("Jet_mass", Jet_mass);
        _inputTree->SetBranchAddress("Jet_phi", Jet_phi);
        _inputTree->SetBranchAddress("Jet_pt", Jet_pt);
        
        _inputTree->SetBranchAddress("LHE_HT", &LHE_HT);
        _inputTree->SetBranchAddress("LHE_Vpt", &LHE_Vpt);
        
        _inputTree->SetBranchAddress("GenMET_phi", &GenMET_phi);
        _inputTree->SetBranchAddress("GenMET_pt", &GenMET_pt);
        
        _inputTree->SetBranchAddress("nMuon", &nMuon);
        _inputTree->SetBranchAddress("Muon_looseId", Muon_looseId);
        _inputTree->SetBranchAddress("Muon_mediumId", Muon_mediumId);
        _inputTree->SetBranchAddress("Muon_mediumPromptId", Muon_mediumPromptId);
        _inputTree->SetBranchAddress("Muon_charge", Muon_charge);
        _inputTree->SetBranchAddress("Muon_eta", Muon_eta);
        _inputTree->SetBranchAddress("Muon_mass", Muon_mass);
        _inputTree->SetBranchAddress("Muon_phi", Muon_phi);
        _inputTree->SetBranchAddress("Muon_pt", Muon_pt);
        _inputTree->SetBranchAddress("Muon_promptMVA", Muon_promptMVA);
        _inputTree->SetBranchAddress("Muon_tightId", Muon_tightId);
        _inputTree->SetBranchAddress("Muon_softId", Muon_softId);
        _inputTree->SetBranchAddress("Muon_highPtId", Muon_highPtId);
        _inputTree->SetBranchAddress("Muon_pfIsoId", Muon_pfIsoId);
        
        _inputTree->SetBranchAddress("PFMET_phi", &PFMET_phi);
        _inputTree->SetBranchAddress("PFMET_pt", &PFMET_pt);
        _inputTree->SetBranchAddress("PFMET_sumEt", &PFMET_sumEt);
        
        _inputTree->SetBranchAddress("Pileup_nPU", &Pileup_nPU);
        _inputTree->SetBranchAddress("Pileup_nTrueInt", &Pileup_nTrueInt);
        
        _inputTree->SetBranchAddress("PuppiMET_phi", &PuppiMET_phi);
        _inputTree->SetBranchAddress("PuppiMET_pt", &PuppiMET_pt);

        _inputTree->SetBranchAddress("nTau", &nTau);
        
        _inputTree->SetBranchAddress("Tau_idDeepTau2018v2p5VSe", Tau_idDeepTau2018v2p5VSe);
        _inputTree->SetBranchAddress("Tau_idDeepTau2018v2p5VSjet", Tau_idDeepTau2018v2p5VSjet);
        _inputTree->SetBranchAddress("Tau_idDeepTau2018v2p5VSmu", Tau_idDeepTau2018v2p5VSmu);
        
        _inputTree->SetBranchAddress("Tau_eta", Tau_eta);
        _inputTree->SetBranchAddress("Tau_phi", Tau_phi);
        _inputTree->SetBranchAddress("Tau_pt", Tau_pt);
        
        _inputTree->SetBranchAddress("nSV", &nSV);



        if (dataset_year == "24"){
            HLT_AK8PFJet380_SoftDropMass30 = false;
            HLT_AK8PFJet400_SoftDropMass30 = false;
            HLT_AK8PFJet425_SoftDropMass30 = false;
            HLT_AK8PFJet450_SoftDropMass30 = false;
            
            HLT_AK8DiPFJet250_250_SoftDropMass40 = false;
            HLT_AK8DiPFJet250_250_SoftDropMass50 = false;
            HLT_AK8DiPFJet260_260_SoftDropMass30 = false;
            HLT_AK8DiPFJet260_260_SoftDropMass40 = false;
            HLT_AK8DiPFJet270_270_SoftDropMass30 = false;
            HLT_AK8DiPFJet280_280_SoftDropMass30 = false;
            HLT_AK8DiPFJet290_290_SoftDropMass30 = false;
            
            HLT_AK8PFJet500 = false;
            HLT_AK8PFJet550 = false;
            HLT_AK8PFJetFwd400 = false;
            HLT_AK8PFJetFwd450 = false;
            HLT_AK8PFJetFwd500 = false;
            
            HLT_PFMET120_PFMHT120_IDTight = false;
            HLT_PFMETNoMu120_PFMHTNoMu120_IDTight = false;
            HLT_PFHT500_PFMET100_PFMHT100_IDTight = false;
            HLT_PFHT500_PFMET110_PFMHT110_IDTight = false;
            HLT_PFHT700_PFMET85_PFMHT85_IDTight = false;
            HLT_PFHT800_PFMET75_PFMHT75_IDTight = false;
            HLT_PFMET130_PFMHT130_IDTight = false;
            HLT_PFMET140_PFMHT140_IDTight = false;
            HLT_PFMETTypeOne140_PFMHT140_IDTight = false;
            HLT_PFMET120_PFMHT120_IDTight_PFHT60 = false;
            HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 = false;
            HLT_PFMETNoMu130_PFMHTNoMu130_IDTight = false;
            HLT_PFMETNoMu140_PFMHTNoMu140_IDTight = false;
            
            HLT_MET105_IsoTrk50 = false;
            HLT_MET120_IsoTrk50 = false;
            HLT_CaloMET350_NotCleaned = false;
            HLT_PFMET250_NotCleaned = false;
            HLT_PFMET300_NotCleaned = false;
            HLT_PFMET200_BeamHaloCleaned = false;
            HLT_PFMETTypeOne200_BeamHaloCleaned = false;
            
            HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_FilterHF = false;
            HLT_PFMETNoMu130_PFMHTNoMu130_IDTight_FilterHF = false;
            HLT_PFMETNoMu140_PFMHTNoMu140_IDTight_FilterHF = false;
            
            HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p50 = false;
            HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p53 = false;
            HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p55 = false;
            HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p60 = false;
            
            HLT_AK8PFJet230_SoftDropMass40_PNetBB0p06 = false;
            HLT_AK8PFJet230_SoftDropMass40_PNetBB0p10 = false;
            HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p03 = false;
            HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p05 = false;
            
            HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p03 = false;
            HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p05 = false;
            HLT_AK8PFJet250_SoftDropMass40_PNetBB0p06 = false;
            HLT_AK8PFJet250_SoftDropMass40_PNetBB0p10 = false;
            
            HLT_AK8PFJet275_SoftDropMass40_PNetBB0p06 = false;
            HLT_AK8PFJet275_SoftDropMass40_PNetBB0p10 = false;
            HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p03 = false;
            HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p05 = false;
            
            HLT_AK8PFJet275_Nch45 = false;
            HLT_AK8PFJet275_Nch40 = false;
            
            HLT_PFMET105_IsoTrk50 = false;
            
            HLT_CaloJet500_NoJetID = false;
            HLT_PFJet500 = false;
            HLT_DiPFJetAve300_HFJEC = false;
            HLT_CaloJet550_NoJetID = false;
            
            HLT_PFJet550 = false;
            HLT_PFJetFwd400 = false;
            HLT_PFJetFwd450 = false;
            HLT_PFJetFwd500 = false;
            
            HLT_PFHT1050 = false;
            HLT_DiPFJetAve260_HFJEC = false;
            HLT_DiPFJetAve180_PPSMatch_Xi0p3_QuadJet_Max2ProtPerRP = false;
            
            HLT_Mu12_DoublePFJets40MaxDeta1p6_PNet2BTag_0p11 = false;
            HLT_Mu12_DoublePFJets54MaxDeta1p6_PNet2BTag_0p11 = false;
            HLT_DoublePFJets116MaxDeta1p6_PNet2BTag_0p11 = false;
            HLT_DoublePFJets128MaxDeta1p6_PNet2BTag_0p11 = false;


            
            _inputTree->SetBranchAddress("HLT_AK8PFJet380_SoftDropMass30", &HLT_AK8PFJet380_SoftDropMass30);
            _inputTree->SetBranchAddress("HLT_AK8PFJet400_SoftDropMass30", &HLT_AK8PFJet400_SoftDropMass30);
            _inputTree->SetBranchAddress("HLT_AK8PFJet425_SoftDropMass30", &HLT_AK8PFJet425_SoftDropMass30);
            _inputTree->SetBranchAddress("HLT_AK8PFJet450_SoftDropMass30", &HLT_AK8PFJet450_SoftDropMass30);
            
            _inputTree->SetBranchAddress("HLT_AK8DiPFJet250_250_SoftDropMass40", &HLT_AK8DiPFJet250_250_SoftDropMass40);
            _inputTree->SetBranchAddress("HLT_AK8DiPFJet250_250_SoftDropMass50", &HLT_AK8DiPFJet250_250_SoftDropMass50);
            _inputTree->SetBranchAddress("HLT_AK8DiPFJet260_260_SoftDropMass30", &HLT_AK8DiPFJet260_260_SoftDropMass30);
            _inputTree->SetBranchAddress("HLT_AK8DiPFJet260_260_SoftDropMass40", &HLT_AK8DiPFJet260_260_SoftDropMass40);
            _inputTree->SetBranchAddress("HLT_AK8DiPFJet270_270_SoftDropMass30", &HLT_AK8DiPFJet270_270_SoftDropMass30);
            _inputTree->SetBranchAddress("HLT_AK8DiPFJet280_280_SoftDropMass30", &HLT_AK8DiPFJet280_280_SoftDropMass30);
            _inputTree->SetBranchAddress("HLT_AK8DiPFJet290_290_SoftDropMass30", &HLT_AK8DiPFJet290_290_SoftDropMass30);
            
            _inputTree->SetBranchAddress("HLT_AK8PFJet500", &HLT_AK8PFJet500);
            _inputTree->SetBranchAddress("HLT_AK8PFJet550", &HLT_AK8PFJet550);
            _inputTree->SetBranchAddress("HLT_AK8PFJetFwd400", &HLT_AK8PFJetFwd400);
            _inputTree->SetBranchAddress("HLT_AK8PFJetFwd450", &HLT_AK8PFJetFwd450);
            _inputTree->SetBranchAddress("HLT_AK8PFJetFwd500", &HLT_AK8PFJetFwd500);
            
            _inputTree->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight);
            _inputTree->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight);
            _inputTree->SetBranchAddress("HLT_PFHT500_PFMET100_PFMHT100_IDTight", &HLT_PFHT500_PFMET100_PFMHT100_IDTight);
            _inputTree->SetBranchAddress("HLT_PFHT500_PFMET110_PFMHT110_IDTight", &HLT_PFHT500_PFMET110_PFMHT110_IDTight);
            _inputTree->SetBranchAddress("HLT_PFHT700_PFMET85_PFMHT85_IDTight", &HLT_PFHT700_PFMET85_PFMHT85_IDTight);
            _inputTree->SetBranchAddress("HLT_PFHT800_PFMET75_PFMHT75_IDTight", &HLT_PFHT800_PFMET75_PFMHT75_IDTight);
            _inputTree->SetBranchAddress("HLT_PFMET130_PFMHT130_IDTight", &HLT_PFMET130_PFMHT130_IDTight);
            _inputTree->SetBranchAddress("HLT_PFMET140_PFMHT140_IDTight", &HLT_PFMET140_PFMHT140_IDTight);
            _inputTree->SetBranchAddress("HLT_PFMETTypeOne140_PFMHT140_IDTight", &HLT_PFMETTypeOne140_PFMHT140_IDTight);
            _inputTree->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight_PFHT60", &HLT_PFMET120_PFMHT120_IDTight_PFHT60);
            _inputTree->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60);
            _inputTree->SetBranchAddress("HLT_PFMETNoMu130_PFMHTNoMu130_IDTight", &HLT_PFMETNoMu130_PFMHTNoMu130_IDTight);
            _inputTree->SetBranchAddress("HLT_PFMETNoMu140_PFMHTNoMu140_IDTight", &HLT_PFMETNoMu140_PFMHTNoMu140_IDTight);
            
            _inputTree->SetBranchAddress("HLT_MET105_IsoTrk50", &HLT_MET105_IsoTrk50);
            _inputTree->SetBranchAddress("HLT_MET120_IsoTrk50", &HLT_MET120_IsoTrk50);
            _inputTree->SetBranchAddress("HLT_CaloMET350_NotCleaned", &HLT_CaloMET350_NotCleaned);
            _inputTree->SetBranchAddress("HLT_PFMET250_NotCleaned", &HLT_PFMET250_NotCleaned);
            _inputTree->SetBranchAddress("HLT_PFMET300_NotCleaned", &HLT_PFMET300_NotCleaned);
            _inputTree->SetBranchAddress("HLT_PFMET200_BeamHaloCleaned", &HLT_PFMET200_BeamHaloCleaned);
            _inputTree->SetBranchAddress("HLT_PFMETTypeOne200_BeamHaloCleaned", &HLT_PFMETTypeOne200_BeamHaloCleaned);
            
            _inputTree->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_FilterHF", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_FilterHF);
            _inputTree->SetBranchAddress("HLT_PFMETNoMu130_PFMHTNoMu130_IDTight_FilterHF", &HLT_PFMETNoMu130_PFMHTNoMu130_IDTight_FilterHF);
            _inputTree->SetBranchAddress("HLT_PFMETNoMu140_PFMHTNoMu140_IDTight_FilterHF", &HLT_PFMETNoMu140_PFMHTNoMu140_IDTight_FilterHF);
            
            _inputTree->SetBranchAddress("HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p50", &HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p50);
            _inputTree->SetBranchAddress("HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p53", &HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p53);
            _inputTree->SetBranchAddress("HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p55", &HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p55);
            _inputTree->SetBranchAddress("HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p60", &HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p60);
            
            _inputTree->SetBranchAddress("HLT_AK8PFJet230_SoftDropMass40_PNetBB0p06", &HLT_AK8PFJet230_SoftDropMass40_PNetBB0p06);
            _inputTree->SetBranchAddress("HLT_AK8PFJet230_SoftDropMass40_PNetBB0p10", &HLT_AK8PFJet230_SoftDropMass40_PNetBB0p10);
            _inputTree->SetBranchAddress("HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p03", &HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p03);
            _inputTree->SetBranchAddress("HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p05", &HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p05);
            
            _inputTree->SetBranchAddress("HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p03", &HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p03);
            _inputTree->SetBranchAddress("HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p05", &HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p05);
            _inputTree->SetBranchAddress("HLT_AK8PFJet250_SoftDropMass40_PNetBB0p06", &HLT_AK8PFJet250_SoftDropMass40_PNetBB0p06);
            _inputTree->SetBranchAddress("HLT_AK8PFJet250_SoftDropMass40_PNetBB0p10", &HLT_AK8PFJet250_SoftDropMass40_PNetBB0p10);
            
            _inputTree->SetBranchAddress("HLT_AK8PFJet275_SoftDropMass40_PNetBB0p06", &HLT_AK8PFJet275_SoftDropMass40_PNetBB0p06);
            _inputTree->SetBranchAddress("HLT_AK8PFJet275_SoftDropMass40_PNetBB0p10", &HLT_AK8PFJet275_SoftDropMass40_PNetBB0p10);
            _inputTree->SetBranchAddress("HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p03", &HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p03);
            _inputTree->SetBranchAddress("HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p05", &HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p05);
            
            _inputTree->SetBranchAddress("HLT_AK8PFJet275_Nch45", &HLT_AK8PFJet275_Nch45);
            _inputTree->SetBranchAddress("HLT_AK8PFJet275_Nch40", &HLT_AK8PFJet275_Nch40);
            
            _inputTree->SetBranchAddress("HLT_PFMET105_IsoTrk50", &HLT_PFMET105_IsoTrk50);
            
            _inputTree->SetBranchAddress("HLT_CaloJet500_NoJetID", &HLT_CaloJet500_NoJetID);
            _inputTree->SetBranchAddress("HLT_PFJet500", &HLT_PFJet500);
            _inputTree->SetBranchAddress("HLT_DiPFJetAve300_HFJEC", &HLT_DiPFJetAve300_HFJEC);
            _inputTree->SetBranchAddress("HLT_CaloJet550_NoJetID", &HLT_CaloJet550_NoJetID);
            
            _inputTree->SetBranchAddress("HLT_PFJet550", &HLT_PFJet550);
            _inputTree->SetBranchAddress("HLT_PFJetFwd400", &HLT_PFJetFwd400);
            _inputTree->SetBranchAddress("HLT_PFJetFwd450", &HLT_PFJetFwd450);
            _inputTree->SetBranchAddress("HLT_PFJetFwd500", &HLT_PFJetFwd500);
            
            _inputTree->SetBranchAddress("HLT_PFHT1050", &HLT_PFHT1050);
            _inputTree->SetBranchAddress("HLT_DiPFJetAve260_HFJEC", &HLT_DiPFJetAve260_HFJEC);
            _inputTree->SetBranchAddress("HLT_DiPFJetAve180_PPSMatch_Xi0p3_QuadJet_Max2ProtPerRP", &HLT_DiPFJetAve180_PPSMatch_Xi0p3_QuadJet_Max2ProtPerRP);
            
            _inputTree->SetBranchAddress("HLT_Mu12_DoublePFJets40MaxDeta1p6_PNet2BTag_0p11", &HLT_Mu12_DoublePFJets40MaxDeta1p6_PNet2BTag_0p11);
            _inputTree->SetBranchAddress("HLT_Mu12_DoublePFJets54MaxDeta1p6_PNet2BTag_0p11", &HLT_Mu12_DoublePFJets54MaxDeta1p6_PNet2BTag_0p11);
            _inputTree->SetBranchAddress("HLT_DoublePFJets116MaxDeta1p6_PNet2BTag_0p11", &HLT_DoublePFJets116MaxDeta1p6_PNet2BTag_0p11);
            _inputTree->SetBranchAddress("HLT_DoublePFJets128MaxDeta1p6_PNet2BTag_0p11", &HLT_DoublePFJets128MaxDeta1p6_PNet2BTag_0p11);

        }
        
        
       


        //-----------------------------------------------------------------------------------------
        if( dataset_group != "Data" ) {
            _inputTree->SetBranchAddress("nGenJetAK8", &nGenJetAK8);
            _inputTree->SetBranchAddress("GenJetAK8_eta", &GenJetAK8_eta);
            _inputTree->SetBranchAddress("GenJetAK8_mass", &GenJetAK8_mass);
            _inputTree->SetBranchAddress("GenJetAK8_phi", &GenJetAK8_phi);
            _inputTree->SetBranchAddress("GenJetAK8_pt", &GenJetAK8_pt);

            _inputTree->SetBranchAddress("nGenJet", &nGenJet);
            _inputTree->SetBranchAddress("GenJet_eta", &GenJet_eta);
            _inputTree->SetBranchAddress("GenJet_mass", &GenJet_mass);
            _inputTree->SetBranchAddress("GenJet_phi", &GenJet_phi);
            _inputTree->SetBranchAddress("GenJet_pt", &GenJet_pt);

            _inputTree->SetBranchAddress("nGenPart", &nGenPart);
            _inputTree->SetBranchAddress("GenPart_genPartIdxMother", &GenPart_genPartIdxMother);
            _inputTree->SetBranchAddress("GenPart_statusFlags", &GenPart_statusFlags);
            _inputTree->SetBranchAddress("GenPart_pdgId", &GenPart_pdgId);
            _inputTree->SetBranchAddress("GenPart_status", &GenPart_status);
            _inputTree->SetBranchAddress("GenPart_eta", &GenPart_eta);
            _inputTree->SetBranchAddress("GenPart_mass", &GenPart_mass);
            _inputTree->SetBranchAddress("GenPart_phi", &GenPart_phi);
            _inputTree->SetBranchAddress("GenPart_pt", &GenPart_pt);

            _inputTree->SetBranchAddress("nSubGenJetAK8", &nSubGenJetAK8);
            _inputTree->SetBranchAddress("SubGenJetAK8_eta", &SubGenJetAK8_eta);
            _inputTree->SetBranchAddress("SubGenJetAK8_mass", &SubGenJetAK8_mass);
            _inputTree->SetBranchAddress("SubGenJetAK8_phi", &SubGenJetAK8_phi);
            _inputTree->SetBranchAddress("SubGenJetAK8_pt", &SubGenJetAK8_pt);

           // _inputTree->SetBranchAddress("genWeight", &genWeight);
           // _inputTree->SetBranchAddress("LHEWeight_originalXWGTUP", &LHEWeight_originalXWGTUP);
           // _inputTree->SetBranchAddress("nLHEPdfWeight", &nLHEPdfWeight);
            //_inputTree->SetBranchAddress("LHEPdfWeight", &LHEPdfWeight);
           // _inputTree->SetBranchAddress("nLHEReweightingWeight", &nLHEReweightingWeight);
            //_inputTree->SetBranchAddress("LHEReweightingWeight", &LHEReweightingWeight);
            //_inputTree->SetBranchAddress("nLHEScaleWeight", &nLHEScaleWeight);
            //_inputTree->SetBranchAddress("LHEScaleWeight", &LHEScaleWeight);
            //_inputTree->SetBranchAddress("nPSWeight", &nPSWeight);
            //_inputTree->SetBranchAddress("PSWeight", &PSWeight);


            _inputTree->SetBranchAddress("LHE_HT", &LHE_HT );
            _inputTree->SetBranchAddress("LHE_Vpt", &LHE_Vpt );
            _inputTree->SetBranchAddress("LHE_Njets", &LHE_Njets );
            

        }

    }

    return true;
}


//-------------------------------------------------------------------------------------------------
// ANAFILES' ROUTINES
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupAna(){
    if( false );
    else if( _SELECTION == "Test" ) SetupTest();
    // SETUP YOUR SELECTION HERE
    else {
      cout << "Unknown selection requested. Exiting. " << endl;
      return;
    }
}

bool HEPHero::AnaRegion(){
    bool Selected = true;
    if( _SELECTION == "Test" && !TestRegion() ) Selected = false;
    // SET THE REGION OF YOUR SELECTION HERE

    return Selected;
}

void HEPHero::AnaSelection(){
    if( _SELECTION == "Test" ) TestSelection();
    // CALL YOUR SELECTION HERE
}

void HEPHero::AnaSystematic(){
    if( _SELECTION == "Test" ) TestSystematic();
    // PRODUCE THE SYSTEMATIC OF YOUR SELECTION HERE
}

void HEPHero::FinishAna(){
    if( _SELECTION == "Test" ) FinishTest();
    // FINISH YOUR SELECTION HERE
}
   
