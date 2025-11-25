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

        _inputTree->SetBranchAddress("GenMET_phi", &GenMET_phi);
        _inputTree->SetBranchAddress("MET_phi", &MET_phi);
        _inputTree->SetBranchAddress("MET_pt", &MET_pt);

        

        //-----------------------------------------------------------------------------------------

        _inputTree->SetBranchAddress("nTau", &nTau);
        _inputTree->SetBranchAddress("Tau_decayMode", Tau_decayMode);
        _inputTree->SetBranchAddress("Tau_idAntiEleDeadECal", Tau_idAntiEleDeadECal);
        _inputTree->SetBranchAddress("Tau_idAntiMu", Tau_idAntiMu);
        _inputTree->SetBranchAddress("Tau_idDecayModeNewDMs", Tau_idDecayModeNewDMs);
        _inputTree->SetBranchAddress("Tau_idDecayModeOldDMs", Tau_idDecayModeOldDMs);
        _inputTree->SetBranchAddress("Tau_idDeepTau2017v2p1VSe", Tau_idDeepTau2017v2p1VSe);
        _inputTree->SetBranchAddress("Tau_idDeepTau2017v2p1VSjet", Tau_idDeepTau2017v2p1VSjet);
        _inputTree->SetBranchAddress("Tau_idDeepTau2017v2p1VSmu", Tau_idDeepTau2017v2p1VSmu);
        _inputTree->SetBranchAddress("Tau_idDeepTau2018v2p5VSe", Tau_idDeepTau2018v2p5VSe);
        _inputTree->SetBranchAddress("Tau_idDeepTau2018v2p5VSjet", Tau_idDeepTau2018v2p5VSjet);
        _inputTree->SetBranchAddress("Tau_idDeepTau2018v2p5VSmu", Tau_idDeepTau2018v2p5VSmu);
        _inputTree->SetBranchAddress("Tau_nSVs", Tau_nSVs);
        _inputTree->SetBranchAddress("Tau_charge", Tau_charge);
        _inputTree->SetBranchAddress("Tau_decayModePNet", Tau_decayModePNet);
        _inputTree->SetBranchAddress("Tau_eleIdx", Tau_eleIdx);
        _inputTree->SetBranchAddress("Tau_jetIdx", Tau_jetIdx);
        _inputTree->SetBranchAddress("Tau_muIdx", Tau_muIdx);
        _inputTree->SetBranchAddress("Tau_svIdx1", Tau_svIdx1);
        _inputTree->SetBranchAddress("Tau_svIdx2", Tau_svIdx2);
        _inputTree->SetBranchAddress("Tau_chargedIso", Tau_chargedIso);
        _inputTree->SetBranchAddress("Tau_dxy", Tau_dxy);
        _inputTree->SetBranchAddress("Tau_dz", Tau_dz);
        _inputTree->SetBranchAddress("Tau_eta", Tau_eta);
        _inputTree->SetBranchAddress("Tau_leadTkDeltaEta", Tau_leadTkDeltaEta);
        _inputTree->SetBranchAddress("Tau_leadTkDeltaPhi", Tau_leadTkDeltaPhi);
        _inputTree->SetBranchAddress("Tau_leadTkPtOverTauPt", Tau_leadTkPtOverTauPt);
        _inputTree->SetBranchAddress("Tau_mass", Tau_mass);
        _inputTree->SetBranchAddress("Tau_neutralIso", Tau_neutralIso);
        _inputTree->SetBranchAddress("Tau_phi", Tau_phi);
        _inputTree->SetBranchAddress("Tau_photonsOutsideSignalCone", Tau_photonsOutsideSignalCone);
        _inputTree->SetBranchAddress("Tau_probDM0PNet", Tau_probDM0PNet);
        _inputTree->SetBranchAddress("Tau_probDM10PNet", Tau_probDM10PNet);
        _inputTree->SetBranchAddress("Tau_probDM11PNet", Tau_probDM11PNet);
        _inputTree->SetBranchAddress("Tau_probDM1PNet", Tau_probDM1PNet);
        _inputTree->SetBranchAddress("Tau_probDM2PNet", Tau_probDM2PNet);
        _inputTree->SetBranchAddress("Tau_pt", Tau_pt);
        _inputTree->SetBranchAddress("Tau_ptCorrPNet", Tau_ptCorrPNet);
        _inputTree->SetBranchAddress("Tau_puCorr", Tau_puCorr);
        _inputTree->SetBranchAddress("Tau_qConfPNet", Tau_qConfPNet);
        _inputTree->SetBranchAddress("Tau_rawDeepTau2017v2p1VSe", Tau_rawDeepTau2017v2p1VSe);
        _inputTree->SetBranchAddress("Tau_rawDeepTau2017v2p1VSjet", Tau_rawDeepTau2017v2p1VSjet);
        _inputTree->SetBranchAddress("Tau_rawDeepTau2017v2p1VSmu", Tau_rawDeepTau2017v2p1VSmu);
        _inputTree->SetBranchAddress("Tau_rawDeepTau2018v2p5VSe", Tau_rawDeepTau2018v2p5VSe);
        _inputTree->SetBranchAddress("Tau_rawDeepTau2018v2p5VSjet", Tau_rawDeepTau2018v2p5VSjet);
        _inputTree->SetBranchAddress("Tau_rawDeepTau2018v2p5VSmu", Tau_rawDeepTau2018v2p5VSmu);
        _inputTree->SetBranchAddress("Tau_rawIso", Tau_rawIso);
        _inputTree->SetBranchAddress("Tau_rawIsodR03", Tau_rawIsodR03);
        _inputTree->SetBranchAddress("Tau_rawPNetVSe", Tau_rawPNetVSe);
        _inputTree->SetBranchAddress("Tau_rawPNetVSjet", Tau_rawPNetVSjet);
        _inputTree->SetBranchAddress("Tau_rawPNetVSmu", Tau_rawPNetVSmu);



        //-----------------------------------------------------------------------------------------

        _inputTree->SetBranchAddress("nMuon", &nMuon);
        _inputTree->SetBranchAddress("Muon_highPtId", &Muon_highPtId);
        _inputTree->SetBranchAddress("Muon_highPurity", &Muon_highPurity);
        _inputTree->SetBranchAddress("Muon_inTimeMuon", &Muon_inTimeMuon);
        _inputTree->SetBranchAddress("Muon_isGlobal", &Muon_isGlobal);
        _inputTree->SetBranchAddress("Muon_isPFcand", &Muon_isPFcand);
        _inputTree->SetBranchAddress("Muon_isStandalone", &Muon_isStandalone);
        _inputTree->SetBranchAddress("Muon_isTracker", &Muon_isTracker);
        _inputTree->SetBranchAddress("Muon_jetNDauCharged", &Muon_jetNDauCharged);
        _inputTree->SetBranchAddress("Muon_looseId", &Muon_looseId);
        _inputTree->SetBranchAddress("Muon_mediumId", &Muon_mediumId);
        _inputTree->SetBranchAddress("Muon_mediumPromptId", &Muon_mediumPromptId);
        _inputTree->SetBranchAddress("Muon_miniIsoId", &Muon_miniIsoId);
        _inputTree->SetBranchAddress("Muon_multiIsoId", &Muon_multiIsoId);
        _inputTree->SetBranchAddress("Muon_mvaMuID_WP", &Muon_mvaMuID_WP);
        _inputTree->SetBranchAddress("Muon_nStations", &Muon_nStations);
        _inputTree->SetBranchAddress("Muon_nTrackerLayers", &Muon_nTrackerLayers);
        _inputTree->SetBranchAddress("Muon_pfIsoId", &Muon_pfIsoId);
        _inputTree->SetBranchAddress("Muon_puppiIsoId", &Muon_puppiIsoId);
        _inputTree->SetBranchAddress("Muon_softId", &Muon_softId);
        _inputTree->SetBranchAddress("Muon_softMvaId", &Muon_softMvaId);
        _inputTree->SetBranchAddress("Muon_tightCharge", &Muon_tightCharge);
        _inputTree->SetBranchAddress("Muon_tightId", &Muon_tightId);
        _inputTree->SetBranchAddress("Muon_tkIsoId", &Muon_tkIsoId);
        _inputTree->SetBranchAddress("Muon_triggerIdLoose", &Muon_triggerIdLoose);
        _inputTree->SetBranchAddress("Muon_jetIdx", &Muon_jetIdx);
        _inputTree->SetBranchAddress("Muon_svIdx", &Muon_svIdx);
        _inputTree->SetBranchAddress("Muon_fsrPhotonIdx", &Muon_fsrPhotonIdx);
        _inputTree->SetBranchAddress("Muon_charge", &Muon_charge);
        _inputTree->SetBranchAddress("Muon_pdgId", &Muon_pdgId);
        _inputTree->SetBranchAddress("Muon_dxy", &Muon_dxy);
        _inputTree->SetBranchAddress("Muon_dxyErr", &Muon_dxyErr);
        _inputTree->SetBranchAddress("Muon_dxybs", &Muon_dxybs);
        _inputTree->SetBranchAddress("Muon_dz", &Muon_dz);
        _inputTree->SetBranchAddress("Muon_dzErr", &Muon_dzErr);
        _inputTree->SetBranchAddress("Muon_eta", &Muon_eta);
        _inputTree->SetBranchAddress("Muon_ip3d", &Muon_ip3d);
        _inputTree->SetBranchAddress("Muon_jetPtRelv2", &Muon_jetPtRelv2);
        _inputTree->SetBranchAddress("Muon_jetRelIso", &Muon_jetRelIso);
        _inputTree->SetBranchAddress("Muon_mass", &Muon_mass);
        _inputTree->SetBranchAddress("Muon_miniPFRelIso_all", &Muon_miniPFRelIso_all);
        _inputTree->SetBranchAddress("Muon_miniPFRelIso_chg", &Muon_miniPFRelIso_chg);
        _inputTree->SetBranchAddress("Muon_mvaMuID", &Muon_mvaMuID);
        _inputTree->SetBranchAddress("Muon_pfRelIso03_all", &Muon_pfRelIso03_all);
        _inputTree->SetBranchAddress("Muon_pfRelIso03_chg", &Muon_pfRelIso03_chg);
        _inputTree->SetBranchAddress("Muon_pfRelIso04_all", &Muon_pfRelIso04_all);
        _inputTree->SetBranchAddress("Muon_phi", &Muon_phi);
        _inputTree->SetBranchAddress("Muon_pt", &Muon_pt);
        _inputTree->SetBranchAddress("Muon_ptErr", &Muon_ptErr);
        _inputTree->SetBranchAddress("Muon_segmentComp", &Muon_segmentComp);
        _inputTree->SetBranchAddress("Muon_sip3d", &Muon_sip3d);
        _inputTree->SetBranchAddress("Muon_softMva", &Muon_softMva);
        _inputTree->SetBranchAddress("Muon_tkRelIso", &Muon_tkRelIso);
        _inputTree->SetBranchAddress("Muon_tunepRelPt", &Muon_tunepRelPt);
        _inputTree->SetBranchAddress("Muon_bsConstrainedChi2", &Muon_bsConstrainedChi2);
        _inputTree->SetBranchAddress("Muon_bsConstrainedPt", &Muon_bsConstrainedPt);
        _inputTree->SetBranchAddress("Muon_bsConstrainedPtErr", &Muon_bsConstrainedPtErr);
        _inputTree->SetBranchAddress("Muon_mvaLowPt", &Muon_mvaLowPt);
        _inputTree->SetBranchAddress("Muon_mvaTTH", &Muon_mvaTTH);

        //-----------------------------------------------------------------------------------------

        _inputTree->SetBranchAddress("nElectron", &nElectron);
        _inputTree->SetBranchAddress("Electron_seediEtaOriX", &Electron_seediEtaOriX);
        _inputTree->SetBranchAddress("Electron_convVeto", &Electron_convVeto);
        _inputTree->SetBranchAddress("Electron_cutBased", &Electron_cutBased);
        _inputTree->SetBranchAddress("Electron_cutBased_HEEP", &Electron_cutBased_HEEP);
        _inputTree->SetBranchAddress("Electron_isPFcand", &Electron_isPFcand);
        _inputTree->SetBranchAddress("Electron_jetNDauCharged", &Electron_jetNDauCharged);
        _inputTree->SetBranchAddress("Electron_lostHits", &Electron_lostHits);
        _inputTree->SetBranchAddress("Electron_mvaIso_WP80", &Electron_mvaIso_WP80);
        _inputTree->SetBranchAddress("Electron_mvaIso_WP90", &Electron_mvaIso_WP90);
        _inputTree->SetBranchAddress("Electron_mvaNoIso_WP80", &Electron_mvaNoIso_WP80);
        _inputTree->SetBranchAddress("Electron_mvaNoIso_WP90", &Electron_mvaNoIso_WP90);
        _inputTree->SetBranchAddress("Electron_seedGain", &Electron_seedGain);
        _inputTree->SetBranchAddress("Electron_tightCharge", &Electron_tightCharge);
        _inputTree->SetBranchAddress("Electron_jetIdx", &Electron_jetIdx);
        _inputTree->SetBranchAddress("Electron_photonIdx", &Electron_photonIdx);
        _inputTree->SetBranchAddress("Electron_svIdx", &Electron_svIdx);
        _inputTree->SetBranchAddress("Electron_fsrPhotonIdx", &Electron_fsrPhotonIdx);
        _inputTree->SetBranchAddress("Electron_charge", &Electron_charge);
        _inputTree->SetBranchAddress("Electron_pdgId", &Electron_pdgId);
        _inputTree->SetBranchAddress("Electron_seediPhiOriY", &Electron_seediPhiOriY);
        _inputTree->SetBranchAddress("Electron_vidNestedWPBitmap", &Electron_vidNestedWPBitmap);
        _inputTree->SetBranchAddress("Electron_vidNestedWPBitmapHEEP", &Electron_vidNestedWPBitmapHEEP);
        _inputTree->SetBranchAddress("Electron_deltaEtaSC", &Electron_deltaEtaSC);
        _inputTree->SetBranchAddress("Electron_dr03EcalRecHitSumEt", &Electron_dr03EcalRecHitSumEt);
        _inputTree->SetBranchAddress("Electron_dr03HcalDepth1TowerSumEt", &Electron_dr03HcalDepth1TowerSumEt);
        _inputTree->SetBranchAddress("Electron_dr03TkSumPt", &Electron_dr03TkSumPt);
        _inputTree->SetBranchAddress("Electron_dr03TkSumPtHEEP", &Electron_dr03TkSumPtHEEP);
        _inputTree->SetBranchAddress("Electron_dxy", &Electron_dxy);
        _inputTree->SetBranchAddress("Electron_dxyErr", &Electron_dxyErr);
        _inputTree->SetBranchAddress("Electron_dz", &Electron_dz);
        _inputTree->SetBranchAddress("Electron_dzErr", &Electron_dzErr);
        _inputTree->SetBranchAddress("Electron_eInvMinusPInv", &Electron_eInvMinusPInv);
        _inputTree->SetBranchAddress("Electron_energyErr", &Electron_energyErr);
        _inputTree->SetBranchAddress("Electron_eta", &Electron_eta);
        _inputTree->SetBranchAddress("Electron_hoe", &Electron_hoe);
        _inputTree->SetBranchAddress("Electron_ip3d", &Electron_ip3d);
        _inputTree->SetBranchAddress("Electron_jetPtRelv2", &Electron_jetPtRelv2);
        _inputTree->SetBranchAddress("Electron_jetRelIso", &Electron_jetRelIso);
        _inputTree->SetBranchAddress("Electron_mass", &Electron_mass);
        _inputTree->SetBranchAddress("Electron_miniPFRelIso_all", &Electron_miniPFRelIso_all);
        _inputTree->SetBranchAddress("Electron_miniPFRelIso_chg", &Electron_miniPFRelIso_chg);
        _inputTree->SetBranchAddress("Electron_mvaHZZIso", &Electron_mvaHZZIso);
        _inputTree->SetBranchAddress("Electron_mvaIso", &Electron_mvaIso);
        _inputTree->SetBranchAddress("Electron_mvaNoIso", &Electron_mvaNoIso);
        _inputTree->SetBranchAddress("Electron_pfRelIso03_all", &Electron_pfRelIso03_all);
        _inputTree->SetBranchAddress("Electron_pfRelIso03_chg", &Electron_pfRelIso03_chg);
        _inputTree->SetBranchAddress("Electron_phi", &Electron_phi);
        _inputTree->SetBranchAddress("Electron_pt", &Electron_pt);
        _inputTree->SetBranchAddress("Electron_r9", &Electron_r9);
        _inputTree->SetBranchAddress("Electron_scEtOverPt", &Electron_scEtOverPt);
        _inputTree->SetBranchAddress("Electron_sieie", &Electron_sieie);
        _inputTree->SetBranchAddress("Electron_sip3d", &Electron_sip3d);
        _inputTree->SetBranchAddress("Electron_mvaTTH", &Electron_mvaTTH);
        
        
        
        
        
        //-----------------------------------------------------------------------------------------
        _inputTree->SetBranchAddress("nFatJet", &nFatJet);
        _inputTree->SetBranchAddress("FatJet_jetId", &FatJet_jetId);
        _inputTree->SetBranchAddress("FatJet_nConstituents", &FatJet_nConstituents);
        _inputTree->SetBranchAddress("FatJet_subJetIdx1", &FatJet_subJetIdx1);
        _inputTree->SetBranchAddress("FatJet_subJetIdx2", &FatJet_subJetIdx2);
        _inputTree->SetBranchAddress("FatJet_electronIdx3SJ", &FatJet_electronIdx3SJ);
        _inputTree->SetBranchAddress("FatJet_muonIdx3SJ", &FatJet_muonIdx3SJ);
        _inputTree->SetBranchAddress("FatJet_area", &FatJet_area);
        _inputTree->SetBranchAddress("FatJet_btagDDBvLV2", &FatJet_btagDDBvLV2);
        _inputTree->SetBranchAddress("FatJet_btagDDCvBV2", &FatJet_btagDDCvBV2);
        _inputTree->SetBranchAddress("FatJet_btagDDCvLV2", &FatJet_btagDDCvLV2);
        _inputTree->SetBranchAddress("FatJet_btagDeepB", &FatJet_btagDeepB);
        _inputTree->SetBranchAddress("FatJet_btagHbb", &FatJet_btagHbb);
        _inputTree->SetBranchAddress("FatJet_eta", &FatJet_eta);
        _inputTree->SetBranchAddress("FatJet_mass", &FatJet_mass);
        _inputTree->SetBranchAddress("FatJet_msoftdrop", &FatJet_msoftdrop);
        _inputTree->SetBranchAddress("FatJet_n2b1", &FatJet_n2b1);
        _inputTree->SetBranchAddress("FatJet_n3b1", &FatJet_n3b1);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_H4qvsQCD", &FatJet_particleNetWithMass_H4qvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_HbbvsQCD", &FatJet_particleNetWithMass_HbbvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_HccvsQCD", &FatJet_particleNetWithMass_HccvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_QCD", &FatJet_particleNetWithMass_QCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_TvsQCD", &FatJet_particleNetWithMass_TvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_WvsQCD", &FatJet_particleNetWithMass_WvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNetWithMass_ZvsQCD", &FatJet_particleNetWithMass_ZvsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_QCD", &FatJet_particleNet_QCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_QCD0HF", &FatJet_particleNet_QCD0HF);
        _inputTree->SetBranchAddress("FatJet_particleNet_QCD1HF", &FatJet_particleNet_QCD1HF);
        _inputTree->SetBranchAddress("FatJet_particleNet_QCD2HF", &FatJet_particleNet_QCD2HF);
        _inputTree->SetBranchAddress("FatJet_particleNet_XbbVsQCD", &FatJet_particleNet_XbbVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XccVsQCD", &FatJet_particleNet_XccVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XggVsQCD", &FatJet_particleNet_XggVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XqqVsQCD", &FatJet_particleNet_XqqVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XteVsQCD", &FatJet_particleNet_XteVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XtmVsQCD", &FatJet_particleNet_XtmVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_XttVsQCD", &FatJet_particleNet_XttVsQCD);
        _inputTree->SetBranchAddress("FatJet_particleNet_massCorr", &FatJet_particleNet_massCorr);
        _inputTree->SetBranchAddress("FatJet_phi", &FatJet_phi);
        _inputTree->SetBranchAddress("FatJet_pt", &FatJet_pt);
        _inputTree->SetBranchAddress("FatJet_rawFactor", &FatJet_rawFactor);
        _inputTree->SetBranchAddress("FatJet_tau1", &FatJet_tau1);
        _inputTree->SetBranchAddress("FatJet_tau2", &FatJet_tau2);
        _inputTree->SetBranchAddress("FatJet_tau3", &FatJet_tau3);
        _inputTree->SetBranchAddress("FatJet_tau4", &FatJet_tau4);
        _inputTree->SetBranchAddress("FatJet_lsf3", &FatJet_lsf3);

        _inputTree->SetBranchAddress("nJet", &nJet);
        _inputTree->SetBranchAddress("Jet_jetId", &Jet_jetId);
        _inputTree->SetBranchAddress("Jet_nConstituents", &Jet_nConstituents);
        _inputTree->SetBranchAddress("Jet_nElectrons", &Jet_nElectrons);
        _inputTree->SetBranchAddress("Jet_nMuons", &Jet_nMuons);
        _inputTree->SetBranchAddress("Jet_nSVs", &Jet_nSVs);
        _inputTree->SetBranchAddress("Jet_electronIdx1", &Jet_electronIdx1);
        _inputTree->SetBranchAddress("Jet_electronIdx2", &Jet_electronIdx2);
        _inputTree->SetBranchAddress("Jet_muonIdx1", &Jet_muonIdx1);
        _inputTree->SetBranchAddress("Jet_muonIdx2", &Jet_muonIdx2);
        _inputTree->SetBranchAddress("Jet_svIdx1", &Jet_svIdx1);
        _inputTree->SetBranchAddress("Jet_svIdx2", &Jet_svIdx2);
        _inputTree->SetBranchAddress("Jet_hfadjacentEtaStripsSize", &Jet_hfadjacentEtaStripsSize);
        _inputTree->SetBranchAddress("Jet_hfcentralEtaStripSize", &Jet_hfcentralEtaStripSize);
        _inputTree->SetBranchAddress("Jet_PNetRegPtRawCorr", &Jet_PNetRegPtRawCorr);
        _inputTree->SetBranchAddress("Jet_PNetRegPtRawCorrNeutrino", &Jet_PNetRegPtRawCorrNeutrino);
        _inputTree->SetBranchAddress("Jet_PNetRegPtRawRes", &Jet_PNetRegPtRawRes);
        _inputTree->SetBranchAddress("Jet_area", &Jet_area);
        _inputTree->SetBranchAddress("Jet_btagDeepFlavB", &Jet_btagDeepFlavB);
        _inputTree->SetBranchAddress("Jet_btagDeepFlavCvB", &Jet_btagDeepFlavCvB);
        _inputTree->SetBranchAddress("Jet_btagDeepFlavCvL", &Jet_btagDeepFlavCvL);
        _inputTree->SetBranchAddress("Jet_btagDeepFlavQG", &Jet_btagDeepFlavQG);
        _inputTree->SetBranchAddress("Jet_btagPNetB", &Jet_btagPNetB);
        _inputTree->SetBranchAddress("Jet_btagPNetCvB", &Jet_btagPNetCvB);
        _inputTree->SetBranchAddress("Jet_btagPNetCvL", &Jet_btagPNetCvL);
        _inputTree->SetBranchAddress("Jet_btagPNetQvG", &Jet_btagPNetQvG);
        _inputTree->SetBranchAddress("Jet_btagPNetTauVJet", &Jet_btagPNetTauVJet);
        _inputTree->SetBranchAddress("Jet_btagRobustParTAK4B", &Jet_btagRobustParTAK4B);
        _inputTree->SetBranchAddress("Jet_btagRobustParTAK4CvB", &Jet_btagRobustParTAK4CvB);
        _inputTree->SetBranchAddress("Jet_btagRobustParTAK4CvL", &Jet_btagRobustParTAK4CvL);
        _inputTree->SetBranchAddress("Jet_btagRobustParTAK4QG", &Jet_btagRobustParTAK4QG);
        _inputTree->SetBranchAddress("Jet_chEmEF", &Jet_chEmEF);
        _inputTree->SetBranchAddress("Jet_chHEF", &Jet_chHEF);
        _inputTree->SetBranchAddress("Jet_eta", &Jet_eta);
        _inputTree->SetBranchAddress("Jet_hfsigmaEtaEta", &Jet_hfsigmaEtaEta);
        _inputTree->SetBranchAddress("Jet_hfsigmaPhiPhi", &Jet_hfsigmaPhiPhi);
        _inputTree->SetBranchAddress("Jet_mass", &Jet_mass);
        _inputTree->SetBranchAddress("Jet_muEF", &Jet_muEF);
        _inputTree->SetBranchAddress("Jet_muonSubtrFactor", &Jet_muonSubtrFactor);
        _inputTree->SetBranchAddress("Jet_neEmEF", &Jet_neEmEF);
        _inputTree->SetBranchAddress("Jet_neHEF", &Jet_neHEF);
        _inputTree->SetBranchAddress("Jet_phi", &Jet_phi);
        _inputTree->SetBranchAddress("Jet_pt", &Jet_pt);
        _inputTree->SetBranchAddress("Jet_rawFactor", &Jet_rawFactor);
        


        if (dataset_year == "24"){
            _inputTree->SetBranchAddress("Jet_btagUParTAK4B",&Jet_btagUParTAK4B);
        }
        
        
        //-----------------------------------------------------------------------------------------

        if( dataset_year == "22" ){
            HLT_AK8PFJet500 = false;
            HLT_AK8PFJet550 = false;
            HLT_AK8PFJet420_TrimMass30 = false;
            HLT_AK8PFHT800_TrimMass50 = false;
            HLT_AK8PFHT850_TrimMass50 = false;
            HLT_AK8PFHT900_TrimMass50 = false;
            HLT_AK8PFJetFwd400 = false;
            HLT_AK8PFJetFwd450 = false;
            HLT_AK8PFJetFwd500 = false;
            HLT_PFMET120_PFMHT120_IDTight = false;
            HLT_MET105_IsoTrk50 = false;
            HLT_BTagMu_AK8Jet170_DoubleMu5 = false;
            HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35 = false;
            HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35 = false;
            HLT_AK8PFJet425_SoftDropMass40 = false;
            HLT_AK8PFJet450_SoftDropMass40 = false;
            HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30 = false;
            HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30 = false;
            HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30 = false;


            _inputTree->SetBranchAddress("HLT_AK8PFJet500", &HLT_AK8PFJet500 );
            _inputTree->SetBranchAddress("HLT_AK8PFJet550", &HLT_AK8PFJet550 );
            _inputTree->SetBranchAddress("HLT_AK8PFJet420_TrimMass30", &HLT_AK8PFJet420_TrimMass30 );
            _inputTree->SetBranchAddress("HLT_AK8PFHT800_TrimMass50", &HLT_AK8PFHT800_TrimMass50 );
            _inputTree->SetBranchAddress("HLT_AK8PFHT850_TrimMass50", &HLT_AK8PFHT850_TrimMass50 );
            _inputTree->SetBranchAddress("HLT_AK8PFHT900_TrimMass50", &HLT_AK8PFHT900_TrimMass50 );
            _inputTree->SetBranchAddress("HLT_AK8PFJetFwd400", &HLT_AK8PFJetFwd400 );
            _inputTree->SetBranchAddress("HLT_AK8PFJetFwd450", &HLT_AK8PFJetFwd450 );
            _inputTree->SetBranchAddress("HLT_AK8PFJetFwd500", &HLT_AK8PFJetFwd500 );
            _inputTree->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight );
            _inputTree->SetBranchAddress("HLT_MET105_IsoTrk50", &HLT_MET105_IsoTrk50 );
            _inputTree->SetBranchAddress("HLT_BTagMu_AK8Jet170_DoubleMu5", &HLT_BTagMu_AK8Jet170_DoubleMu5 );
            _inputTree->SetBranchAddress("HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetBB0p35 );
            _inputTree->SetBranchAddress("HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35", &HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetBB0p35 );
            _inputTree->SetBranchAddress("HLT_AK8PFJet425_SoftDropMass40", &HLT_AK8PFJet425_SoftDropMass40 );
            _inputTree->SetBranchAddress("HLT_AK8PFJet450_SoftDropMass40", &HLT_AK8PFJet450_SoftDropMass40 );
            _inputTree->SetBranchAddress("HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet230_SoftDropMass40_PFAK8ParticleNetTauTau0p30 );
            _inputTree->SetBranchAddress("HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet250_SoftDropMass40_PFAK8ParticleNetTauTau0p30 );
            _inputTree->SetBranchAddress("HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30", &HLT_AK8PFJet275_SoftDropMass40_PFAK8ParticleNetTauTau0p30 );
            _inputTree->SetBranchAddress("HLT_PFHT500_PFMET100_PFMHT100_IDTight", &HLT_PFHT500_PFMET100_PFMHT100_IDTight );
            _inputTree->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 );
            _inputTree->SetBranchAddress("HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepJet_4p5", &HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepJet_4p5 );
            _inputTree->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight );



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

            _inputTree->SetBranchAddress("genWeight", &genWeight);
            _inputTree->SetBranchAddress("LHEWeight_originalXWGTUP", &LHEWeight_originalXWGTUP);
            _inputTree->SetBranchAddress("nLHEPdfWeight", &nLHEPdfWeight);
            _inputTree->SetBranchAddress("LHEPdfWeight", &LHEPdfWeight);
            _inputTree->SetBranchAddress("nLHEReweightingWeight", &nLHEReweightingWeight);
            _inputTree->SetBranchAddress("LHEReweightingWeight", &LHEReweightingWeight);
            _inputTree->SetBranchAddress("nLHEScaleWeight", &nLHEScaleWeight);
            _inputTree->SetBranchAddress("LHEScaleWeight", &LHEScaleWeight);
            _inputTree->SetBranchAddress("nPSWeight", &nPSWeight);
            _inputTree->SetBranchAddress("PSWeight", &PSWeight);


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
   
