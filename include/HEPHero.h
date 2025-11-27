#ifndef HEPHERO_H
#define HEPHERO_H

#include "HEPBase.h"
#include "CMS.h"
#include "ML.h"
//#include <vector>
//#include "TLorentzVector.h"
#include "onnxruntime_cxx_api.h"
#include "correction.h"


using namespace std;

class HEPHero : public HEPBase {
    public:
        static HEPHero* GetInstance( char* configFileName );
        ~HEPHero() {}
        
        bool Init();
        void RunEventLoop( int nEventsMax = -1);
        void FinishRun();
    
    private:
        static HEPHero* _instance;

        HEPHero() {}
        HEPHero( char* configFileName );

        bool RunRoutines();
        void PreRoutines();
        bool MC_processing();
        void Weight_corrections();
        void VerticalSysSizes();
        void VerticalSys();
        void FillControlVariables( string key, string value);

        void SetupAna();
        bool AnaRegion();
        void AnaSelection();
        void AnaSystematic();
        void FinishAna();

        
        void SetupTest();
        bool TestRegion();
        void TestSelection();
        void TestSystematic();
        void FinishTest();
        // INSERT YOUR SELECTION HERE
        

    //=============================================================================================
    // ANALYSIS SETUP
    //=============================================================================================

        //-------------------------------------------------------------------------------
        // Functions
        //-------------------------------------------------------------------------------

        //----ANALYSIS-----------------------------------------------
        void Jet_lep_overlap(float deltaR_cut);
        void LeptonSelection();
        void JetSelection();
        void FatjetSelection();
        vector<float> SoftmaxHEP( vector<float> input_vec );
        bool Trigger();
        void Get_Jet_Angular_Variables( int pt_cut = 20 );
        void Get_Jet_Shape_Variables();
        void Get_Signal_Taggers();

        //----EXPERIMENT---------------------------------------------
        bool TauVSEletronID( int iobj, int WP );
        bool TauVSJetID( int iobj, int WP );
        bool TauVSMuonID( int iobj, int WP );
        bool MuonID( int iobj, int WP );
        bool MuonISO( int iobj, int WP );
        bool ElectronID( int iobj, int WP );
        bool PileupJet(int iJet);
        bool JetBTAG( int iobj, int WP );

        //----WEIGHTS------------------------------------------------
        //float GetPileupWeight( float Pileup_nTrueInt, string sysType );


        //-------------------------------------------------------------------------------
        // Variables
        //-------------------------------------------------------------------------------

        //----SELECTION----------------------------------------------
        float JET_ETA_CUT;
        float JET_PT_CUT;
        int   JET_ID_WP;
        int   JET_PUID_WP;
        int   JET_BTAG_WP;
        float JET_LEP_DR_ISO_CUT;
        float FAT_JET_PT_CUT;
        float FAT_JET_ETA_CUT;
        int   FAT_JET_ID_WP;
        float ELECTRON_GAP_LOWER_CUT;
        float ELECTRON_GAP_UPPER_CUT;
        float ELECTRON_ETA_CUT;
        float ELECTRON_PT_CUT;
        float ELECTRON_LOW_PT_CUT;
        int   ELECTRON_ID_WP;
        float MUON_ETA_CUT;
        float MUON_PT_CUT;
        float MUON_LOW_PT_CUT;
        int   MUON_ID_WP;
        int   MUON_ISO_WP;
        float TAU_ETA_CUT;
        float TAU_PT_CUT;
        int TAU_VS_ELE_ISO_WP;
        int TAU_VS_JET_ISO_WP;
        int TAU_VS_MU_ISO_WP;
	    float OMEGA_CUT;

        //----JETS---------------------------------------------------
        vector<int> selectedJet;
        vector<bool> Jet_LepOverlap;
        int Nbjets;
        int Nbjets30;
        int Nbjets_LepIso04;
        int Nbjets30_LepIso04;
        int Njets;
        int Njets30;
        int Njets40;
        int Njets_LepIso04;
        int Njets30_LepIso04;
        int Njets40_LepIso04;
        int Njets_forward;
        int Njets30_forward;
        int Njets_tight;
        int Njets_ISR;
        int NPUjets;

        float HT;
        float HT30;
        float HT40;
        float MHT;
        float MHT30;
        float MHT40;
        float MHT_trig;
        float MDT;
        float Jet_abseta_max;
        float OmegaMin;
        float ChiMin;
        float FMax;
        float OmegaMin30;
        float ChiMin30;
        float FMax30;
        float OmegaMin40;
        float ChiMin40;
        float FMax40;
        float LeadingJet_pt;
        float SubLeadingJet_pt;
        float ThirdLeadingJet_pt;
        float FourthLeadingJet_pt;
        float LeadingJet_jetId;
        float SubLeadingJet_jetId;
        float ThirdLeadingJet_jetId;
        float FourthLeadingJet_jetId;
        float LeadingJet_mass;
        float SubLeadingJet_mass;
        float ThirdLeadingJet_mass;
        float FourthLeadingJet_mass;

        //----FATJETS------------------------------------------------
        vector<int> selectedFatJet;
        int NfatJets;
        float LeadingFatJet_jetId;
        float SubLeadingFatJet_jetId;
        float ThirdLeadingFatJet_jetId;
        float FourthLeadingFatJet_jetId;
        float LeadingFatJet_pt;
        float SubLeadingFatJet_pt;
        float ThirdLeadingFatJet_pt;
        float FourthLeadingFatJet_pt;
        float LeadingFatJet_mass;
        float SubLeadingFatJet_mass;
        float ThirdLeadingFatJet_mass;
        float FourthLeadingFatJet_mass;
        float LeadingFatJet_XbbVsQCD;
        float SubLeadingFatJet_XbbVsQCD;
        float ThirdLeadingFatJet_XbbVsQCD;
        float FourthLeadingFatJet_XbbVsQCD;
        float LeadingFatJet_XccVsQCD;
        float SubLeadingFatJet_XccVsQCD;
        float ThirdLeadingFatJet_XccVsQCD;
        float FourthLeadingFatJet_XccVsQCD;
        float LeadingFatJet_XggVsQCD;
        float SubLeadingFatJet_XggVsQCD;
        float ThirdLeadingFatJet_XggVsQCD;
        float FourthLeadingFatJet_XggVsQCD;
        float LeadingFatJet_XqqVsQCD;
        float SubLeadingFatJet_XqqVsQCD;
        float ThirdLeadingFatJet_XqqVsQCD;
        float FourthLeadingFatJet_XqqVsQCD;
        float LeadingFatJet_msoftdrop;
        float SubLeadingFatJet_msoftdrop;
        float ThirdLeadingFatJet_msoftdrop;
        float FourthLeadingFatJet_msoftdrop;
        float LeadingFatJet_massCorr;
        float SubLeadingFatJet_massCorr;
        float ThirdLeadingFatJet_massCorr;
        float FourthLeadingFatJet_massCorr;
        float LeadingFatJet_ZvsQCD;
        float SubLeadingFatJet_ZvsQCD;
        float ThirdLeadingFatJet_ZvsQCD;
        float FourthLeadingFatJet_ZvsQCD;
        int hadronic_channel;
        float FatJet_b_max_deltaEta;
        float MET_FatJet_Mt;
        float MET_FatJet_deltaPhi;

        //----LEPTONS------------------------------------------------
        vector<int> selectedEle;
        vector<int> selectedMu;
        vector<int> selectedTau;
        int Nleptons;
        int Nelectrons;
        int Nmuons;
        int Ntaus;

        //----HADRONIC EVENT SHAPE-----------------------------------
        float RT_1;
        float RT_2;
        float RT_3;
        float RT_4;
        float tauT;

        //----MACHINE LEARNING---------------------------------------
        ONNX_MODEL signal_tagger;
        float signal_tag;
        string NN_model_file;

        //----MET----------------------------------------------------

        //----TRIGGERS-----------------------------------------------

        //----CONSTANTS----------------------------------------------
        //const float Z_pdg_mass = 91.1876; //GeV

        //----VERTICAL SYSTEMATICS-----------------------------------


        //-------------------------------------------------------------------------------
        // Metadata
        //-------------------------------------------------------------------------------

        //----PILEUP---------------------------------------
        //bool    apply_pileup_wgt;
        //double  pileup_wgt;
        //string  pileup_file;
        shared_ptr<correction::Correction const> pileup_corr;

        //----MET XY-------------------------------------------------
        //bool apply_met_xy_corr;
        //string  met_xy_file;
        //shared_ptr<correction::Correction const> met_xy_pt_corr;
        //shared_ptr<correction::Correction const> met_xy_phi_corr;

    
    //=============================================================================================
    // INPUT TREE SETUP - NANOAOD
    //=============================================================================================
    private:

        UInt_t run;
        UInt_t luminosityBlock;
        UInt_t event;
        UInt_t bunchCrossing;


//		UChar_t         HTXS_njets25;
//		UChar_t         HTXS_njets30;
//		Int_t           HTXS_stage1_1_cat_pTjet25GeV;
//		Int_t           HTXS_stage1_1_cat_pTjet30GeV;
//		Int_t           HTXS_stage1_1_fine_cat_pTjet25GeV;
//		Int_t           HTXS_stage1_1_fine_cat_pTjet30GeV;
//		Int_t           HTXS_stage1_2_cat_pTjet25GeV;
//		Int_t           HTXS_stage1_2_cat_pTjet30GeV;
//		Int_t           HTXS_stage1_2_fine_cat_pTjet25GeV;
//		Int_t           HTXS_stage1_2_fine_cat_pTjet30GeV;
//		Int_t           HTXS_stage_0;
//		Int_t           HTXS_stage_1_pTjet25;
//		Int_t           HTXS_stage_1_pTjet30;
//		Float_t         HTXS_Higgs_pt;
//		Float_t         HTXS_Higgs_y;
//		Float_t         HTXS_Mjj;
//		Float_t         HTXS_V_pt;
//		Float_t         HTXS_dPhijj;
//		Float_t         HTXS_ptHjj;
//		Short_t         BeamSpot_type;
//		Float_t         BeamSpot_sigmaZ;
//		Float_t         BeamSpot_sigmaZError;
//		Float_t         BeamSpot_z;
//		Float_t         BeamSpot_zError;

/*
		Int_t           nboostedTau;
		UChar_t         boostedTau_idAntiEle2018[100];   //[nboostedTau]
		UChar_t         boostedTau_idAntiMu[100];   //[nboostedTau]
		UChar_t         boostedTau_idMVAnewDM2017v2[100];   //[nboostedTau]
		UChar_t         boostedTau_idMVAoldDM2017v2[100];   //[nboostedTau]
		Short_t         boostedTau_jetIdx[100];   //[nboostedTau]
		Short_t         boostedTau_rawAntiEleCat2018[100];   //[nboostedTau]
		Int_t           boostedTau_charge[100];   //[nboostedTau]
		Int_t           boostedTau_decayMode[100];   //[nboostedTau]
		Float_t         boostedTau_chargedIso[100];   //[nboostedTau]
		Float_t         boostedTau_eta[100];   //[nboostedTau]
		Float_t         boostedTau_leadTkDeltaEta[100];   //[nboostedTau]
		Float_t         boostedTau_leadTkDeltaPhi[100];   //[nboostedTau]
		Float_t         boostedTau_leadTkPtOverTauPt[100];   //[nboostedTau]
		Float_t         boostedTau_mass[100];   //[nboostedTau]
		Float_t         boostedTau_neutralIso[100];   //[nboostedTau]
		Float_t         boostedTau_phi[100];   //[nboostedTau]
		Float_t         boostedTau_photonsOutsideSignalCone[100];   //[nboostedTau]
		Float_t         boostedTau_pt[100];   //[nboostedTau]
		Float_t         boostedTau_puCorr[100];   //[nboostedTau]
		Float_t         boostedTau_rawAntiEle2018[100];   //[nboostedTau]
		Float_t         boostedTau_rawBoostedDeepTauRunIIv2p0VSe[100];   //[nboostedTau]
		Float_t         boostedTau_rawBoostedDeepTauRunIIv2p0VSjet[100];   //[nboostedTau]
		Float_t         boostedTau_rawBoostedDeepTauRunIIv2p0VSmu[100];   //[nboostedTau]
		Float_t         boostedTau_rawIso[100];   //[nboostedTau]
		Float_t         boostedTau_rawIsodR03[100];   //[nboostedTau]
		Float_t         boostedTau_rawMVAnewDM2017v2[100];   //[nboostedTau]
		Float_t         boostedTau_rawMVAoldDM2017v2[100];   //[nboostedTau]
*/
/*
		Float_t         CaloMET_phi;
		Float_t         CaloMET_pt;
		Float_t         CaloMET_sumEt;
*/
/*
		Int_t           nCorrT1METJet;
		Float_t         CorrT1METJet_EmEF[100];   //[nCorrT1METJet]
		Float_t         CorrT1METJet_area[100];   //[nCorrT1METJet]
		Float_t         CorrT1METJet_eta[100];   //[nCorrT1METJet]
		Float_t         CorrT1METJet_muonSubtrDeltaEta[100];   //[nCorrT1METJet]
		Float_t         CorrT1METJet_muonSubtrDeltaPhi[100];   //[nCorrT1METJet]
		Float_t         CorrT1METJet_muonSubtrFactor[100];   //[nCorrT1METJet]
		Float_t         CorrT1METJet_phi[100];   //[nCorrT1METJet]
		Float_t         CorrT1METJet_rawMass[100];   //[nCorrT1METJet]
		Float_t         CorrT1METJet_rawPt[100];   //[nCorrT1METJet]
*/
/*
		Float_t         DeepMETResolutionTune_phi;
		Float_t         DeepMETResolutionTune_pt;
		Float_t         DeepMETResponseTune_phi;
		Float_t         DeepMETResponseTune_pt;
*/

		Int_t           nElectron;
//		Bool_t          Electron_convVeto[100];   //[nElectron]
		UChar_t         Electron_cutBased[100];   //[nElectron]
//		Bool_t          Electron_cutBased_HEEP[100];   //[nElectron]
//		Bool_t          Electron_isEB[100];   //[nElectron]
//		Bool_t          Electron_isEcalDriven[100];   //[nElectron]
//		Bool_t          Electron_isPFcand[100];   //[nElectron]
//		UChar_t         Electron_jetNDauCharged[100];   //[nElectron]
//		UChar_t         Electron_lostHits[100];   //[nElectron]
		Bool_t          Electron_mvaIso_WP80[100];   //[nElectron]
		Bool_t          Electron_mvaIso_WP90[100];   //[nElectron]
//		Bool_t          Electron_mvaIso_WPHZZ[100];   //[nElectron]
//		Bool_t          Electron_mvaNoIso_WP80[100];   //[nElectron]
//		Bool_t          Electron_mvaNoIso_WP90[100];   //[nElectron]
//		UChar_t         Electron_seedGain[100];   //[nElectron]
//		UChar_t         Electron_tightCharge[100];   //[nElectron]
//		Short_t         Electron_jetIdx[100];   //[nElectron]
//		Short_t         Electron_photonIdx[100];   //[nElectron]
//		Short_t         Electron_seediEtaOriX[100];   //[nElectron]
//		Short_t         Electron_seediPhiOriY[100];   //[nElectron]
//		Short_t         Electron_svIdx[100];   //[nElectron]
//		Short_t         Electron_fsrPhotonIdx[100];   //[nElectron]
		Int_t           Electron_charge[100];   //[nElectron]
//		Int_t           Electron_pdgId[100];   //[nElectron]
//		Int_t           Electron_vidNestedWPBitmap[100];   //[nElectron]
//		Int_t           Electron_vidNestedWPBitmapHEEP[100];   //[nElectron]
//		Float_t         Electron_PreshowerEnergy[100];   //[nElectron]
//		Float_t         Electron_deltaEtaSC[100];   //[nElectron]
//		Float_t         Electron_dr03EcalRecHitSumEt[100];   //[nElectron]
//		Float_t         Electron_dr03HcalDepth1TowerSumEt[100];   //[nElectron]
//		Float_t         Electron_dr03TkSumPt[100];   //[nElectron]
//		Float_t         Electron_dr03TkSumPtHEEP[100];   //[nElectron]
//		Float_t         Electron_dxy[100];   //[nElectron]
//		Float_t         Electron_dxyErr[100];   //[nElectron]
//		Float_t         Electron_dz[100];   //[nElectron]
//		Float_t         Electron_dzErr[100];   //[nElectron]
//		Float_t         Electron_eInvMinusPInv[100];   //[nElectron]
//		Float_t         Electron_ecalEnergy[100];   //[nElectron]
//		Float_t         Electron_ecalEnergyError[100];   //[nElectron]
//		Float_t         Electron_energyErr[100];   //[nElectron]
//		Float_t         Electron_eta[100];   //[nElectron]
//		Float_t         Electron_fbrem[100];   //[nElectron]
//		Float_t         Electron_gsfTrketaMode[100];   //[nElectron]
//		Float_t         Electron_gsfTrkpMode[100];   //[nElectron]
//		Float_t         Electron_gsfTrkpModeErr[100];   //[nElectron]
//		Float_t         Electron_gsfTrkphiMode[100];   //[nElectron]
//		Float_t         Electron_hoe[100];   //[nElectron]
//		Float_t         Electron_ip3d[100];   //[nElectron]
//		Float_t         Electron_jetDF[100];   //[nElectron]
//		Float_t         Electron_jetPtRelv2[100];   //[nElectron]
//		Float_t         Electron_jetRelIso[100];   //[nElectron]
		Float_t         Electron_mass[100];   //[nElectron]
//		Float_t         Electron_miniPFRelIso_all[100];   //[nElectron]
//		Float_t         Electron_miniPFRelIso_chg[100];   //[nElectron]
//		Float_t         Electron_mvaHZZIso[100];   //[nElectron]
//		Float_t         Electron_mvaIso[100];   //[nElectron]
//		Float_t         Electron_mvaNoIso[100];   //[nElectron]
//		Float_t         Electron_pfRelIso03_all[100];   //[nElectron]
//		Float_t         Electron_pfRelIso03_chg[100];   //[nElectron]
//		Float_t         Electron_pfRelIso04_all[100];   //[nElectron]
		Float_t         Electron_phi[100];   //[nElectron]
		Float_t         Electron_pt[100];   //[nElectron]
//		Float_t         Electron_r9[100];   //[nElectron]
//		Float_t         Electron_rawEnergy[100];   //[nElectron]
//		Float_t         Electron_scEtOverPt[100];   //[nElectron]
//		Float_t         Electron_sieie[100];   //[nElectron]
//		Float_t         Electron_sip3d[100];   //[nElectron]
//		Float_t         Electron_superclusterEta[100];   //[nElectron]
//		Float_t         Electron_promptMVA[100];   //[nElectron]
		
		Int_t           nFatJet;
//		UChar_t         FatJet_nConstituents[100];   //[nFatJet]
//		Short_t         FatJet_chMultiplicity[100];   //[nFatJet]
//		Short_t         FatJet_neMultiplicity[100];   //[nFatJet]
//		Short_t         FatJet_subJetIdx1[100];   //[nFatJet]
//		Short_t         FatJet_subJetIdx2[100];   //[nFatJet]
//		Short_t         FatJet_electronIdx3SJ[100];   //[nFatJet]
//		Short_t         FatJet_muonIdx3SJ[100];   //[nFatJet]
//		Float_t         FatJet_area[100];   //[nFatJet]
//		Float_t         FatJet_chEmEF[100];   //[nFatJet]
//		Float_t         FatJet_chHEF[100];   //[nFatJet]
		Float_t         FatJet_eta[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_QCD[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_TopbWev[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_TopbWmv[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_TopbWq[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_TopbWqq[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_TopbWtauhv[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_WvsQCD[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_XWW3q[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_XWW4q[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_XWWqqev[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_XWWqqmv[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_Xbb[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_Xcc[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_Xcs[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_Xqq[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_Xtauhtaue[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_Xtauhtauh[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_Xtauhtaum[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_massCorrGeneric[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_massCorrX2p[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_withMassTopvsQCD[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_withMassWvsQCD[100];   //[nFatJet]
//		Float_t         FatJet_globalParT3_withMassZvsQCD[100];   //[nFatJet]
//		Float_t         FatJet_hfEmEF[100];   //[nFatJet]
//		Float_t         FatJet_hfHEF[100];   //[nFatJet]
		Float_t         FatJet_mass[100];   //[nFatJet]
//		Float_t         FatJet_msoftdrop[100];   //[nFatJet]
//		Float_t         FatJet_muEF[100];   //[nFatJet]
//		Float_t         FatJet_n2b1[100];   //[nFatJet]
//		Float_t         FatJet_n3b1[100];   //[nFatJet]
//		Float_t         FatJet_neEmEF[100];   //[nFatJet]
//		Float_t         FatJet_neHEF[100];   //[nFatJet]
		Float_t         FatJet_particleNetLegacy_QCD[100];   //[nFatJet]
		Float_t         FatJet_particleNetLegacy_Xbb[100];   //[nFatJet]
		Float_t         FatJet_particleNetLegacy_Xcc[100];   //[nFatJet]
		Float_t         FatJet_particleNetLegacy_Xqq[100];   //[nFatJet]
//		Float_t         FatJet_particleNetLegacy_mass[100];   //[nFatJet]
		Float_t         FatJet_particleNetWithMass_H4qvsQCD[100];   //[nFatJet]
		Float_t         FatJet_particleNetWithMass_HbbvsQCD[100];   //[nFatJet]
		Float_t         FatJet_particleNetWithMass_HccvsQCD[100];   //[nFatJet]
		Float_t         FatJet_particleNetWithMass_QCD[100];   //[nFatJet]
		Float_t         FatJet_particleNetWithMass_TvsQCD[100];   //[nFatJet]
		Float_t         FatJet_particleNetWithMass_WvsQCD[100];   //[nFatJet]
		Float_t         FatJet_particleNetWithMass_ZvsQCD[100];   //[nFatJet]
//		Float_t         FatJet_particleNet_QCD[100];   //[nFatJet]
//		Float_t         FatJet_particleNet_QCD0HF[100];   //[nFatJet]
//		Float_t         FatJet_particleNet_QCD1HF[100];   //[nFatJet]
//		Float_t         FatJet_particleNet_QCD2HF[100];   //[nFatJet]
		Float_t         FatJet_particleNet_WVsQCD[100];   //[nFatJet]
		Float_t         FatJet_particleNet_XbbVsQCD[100];   //[nFatJet]
		Float_t         FatJet_particleNet_XccVsQCD[100];   //[nFatJet]
		Float_t         FatJet_particleNet_XggVsQCD[100];   //[nFatJet]
		Float_t         FatJet_particleNet_XqqVsQCD[100];   //[nFatJet]
		Float_t         FatJet_particleNet_XteVsQCD[100];   //[nFatJet]
		Float_t         FatJet_particleNet_XtmVsQCD[100];   //[nFatJet]
		Float_t         FatJet_particleNet_XttVsQCD[100];   //[nFatJet]
//		Float_t         FatJet_particleNet_massCorr[100];   //[nFatJet]
		Float_t         FatJet_phi[100];   //[nFatJet]
		Float_t         FatJet_pt[100];   //[nFatJet]
//		Float_t         FatJet_rawFactor[100];   //[nFatJet]
//		Float_t         FatJet_tau1[100];   //[nFatJet]
//		Float_t         FatJet_tau2[100];   //[nFatJet]
//		Float_t         FatJet_tau3[100];   //[nFatJet]
//		Float_t         FatJet_tau4[100];   //[nFatJet]
//		Float_t         FatJet_lsf3[100];   //[nFatJet]
		
//		Int_t           nFatJetPFCand;
//		Int_t           FatJetPFCand_pfCandIdx[100];   //[nFatJetPFCand]
//		Int_t           FatJetPFCand_jetIdx[100];   //[nFatJetPFCand]
		
//		Int_t           nFsrPhoton;
//		Short_t         FsrPhoton_electronIdx[100];   //[nFsrPhoton]
//		Short_t         FsrPhoton_muonIdx[100];   //[nFsrPhoton]
//		Float_t         FsrPhoton_dROverEt2[100];   //[nFsrPhoton]
//		Float_t         FsrPhoton_eta[100];   //[nFsrPhoton]
//		Float_t         FsrPhoton_phi[100];   //[nFsrPhoton]
//		Float_t         FsrPhoton_pt[100];   //[nFsrPhoton]
//		Float_t         FsrPhoton_relIso03[100];   //[nFsrPhoton]
		
//		Int_t           nGenJetAK8;
//		Float_t         GenJetAK8_eta[100];   //[nGenJetAK8]
//		Float_t         GenJetAK8_mass[100];   //[nGenJetAK8]
//		Float_t         GenJetAK8_phi[100];   //[nGenJetAK8]
//		Float_t         GenJetAK8_pt[100];   //[nGenJetAK8]
		
//		Int_t           nGenJet;
//		Float_t         GenJet_eta[100];   //[nGenJet]
//		Float_t         GenJet_mass[100];   //[nGenJet]
//		Float_t         GenJet_phi[100];   //[nGenJet]
//		Float_t         GenJet_pt[100];   //[nGenJet]
		
		Int_t           nGenPart;
		Short_t         GenPart_genPartIdxMother[24];   //[nGenPart]
		UShort_t        GenPart_statusFlags[24];   //[nGenPart]
		Int_t           GenPart_pdgId[24];   //[nGenPart]
		Int_t           GenPart_status[24];   //[nGenPart]
		Float_t         GenPart_eta[24];   //[nGenPart]
		Float_t         GenPart_mass[24];   //[nGenPart]
		Float_t         GenPart_phi[24];   //[nGenPart]
		Float_t         GenPart_pt[24];   //[nGenPart]
//		Float_t         GenPart_iso[24];   //[nGenPart]
		
//		Int_t           nGenProton;
//		Bool_t          GenProton_isPU[100];   //[nGenProton]
//		Float_t         GenProton_px[100];   //[nGenProton]
//		Float_t         GenProton_py[100];   //[nGenProton]
//		Float_t         GenProton_pz[100];   //[nGenProton]
//		Float_t         GenProton_vz[100];   //[nGenProton]
		/*
		Int_t           nSubGenJetAK8;
		Float_t         SubGenJetAK8_eta[100];   //[nSubGenJetAK8]
		Float_t         SubGenJetAK8_mass[100];   //[nSubGenJetAK8]
		Float_t         SubGenJetAK8_phi[100];   //[nSubGenJetAK8]
		Float_t         SubGenJetAK8_pt[100];   //[nSubGenJetAK8]
		*/
		/*
		Int_t           Generator_id1;
		Int_t           Generator_id2;
		Float_t         Generator_binvar;
		Float_t         Generator_scalePDF;
		Float_t         Generator_weight;
		Float_t         Generator_x1;
		Float_t         Generator_x2;
		Float_t         Generator_xpdf1;
		Float_t         Generator_xpdf2;
		Float_t         GenVtx_x;
		Float_t         GenVtx_y;
		Float_t         GenVtx_z;
		*/
		/*
		Int_t           nGenVisTau;
		UChar_t         GenVisTau_status[100];   //[nGenVisTau]
		Short_t         GenVisTau_charge[100];   //[nGenVisTau]
		Short_t         GenVisTau_genPartIdxMother[100];   //[nGenVisTau]
		Float_t         GenVisTau_eta[100];   //[nGenVisTau]
		Float_t         GenVisTau_mass[100];   //[nGenVisTau]
		Float_t         GenVisTau_phi[100];   //[nGenVisTau]
		Float_t         GenVisTau_pt[100];   //[nGenVisTau]
		Float_t         genWeight;
		*/
		/*
		Float_t         LHEWeight_originalXWGTUP;
		Int_t           nLHEPdfWeight;
		Float_t         LHEPdfWeight[101];   //[nLHEPdfWeight]
		Int_t           nLHEReweightingWeight;
		Float_t         LHEReweightingWeight[100];   //[nLHEReweightingWeight]
		Int_t           nLHEScaleWeight;
		Float_t         LHEScaleWeight[100];   //[nLHEScaleWeight]
		Int_t           nPSWeight;
		Float_t         PSWeight[100];   //[nPSWeight]
		*/
		
		Int_t           nIsoTrack;
//		Bool_t          IsoTrack_isHighPurityTrack[100];   //[nIsoTrack]
//		Bool_t          IsoTrack_isPFcand[100];   //[nIsoTrack]
//		Bool_t          IsoTrack_isFromLostTrack[100];   //[nIsoTrack]
//		Short_t         IsoTrack_charge[100];   //[nIsoTrack]
//		Short_t         IsoTrack_fromPV[100];   //[nIsoTrack]
//		Int_t           IsoTrack_pdgId[100];   //[nIsoTrack]
//		Float_t         IsoTrack_dxy[100];   //[nIsoTrack]
//		Float_t         IsoTrack_dz[100];   //[nIsoTrack]
//		Float_t         IsoTrack_eta[100];   //[nIsoTrack]
//		Float_t         IsoTrack_pfRelIso03_all[100];   //[nIsoTrack]
//		Float_t         IsoTrack_pfRelIso03_chg[100];   //[nIsoTrack]
//		Float_t         IsoTrack_phi[100];   //[nIsoTrack]
//		Float_t         IsoTrack_pt[100];   //[nIsoTrack]
//		Float_t         IsoTrack_miniPFRelIso_all[100];   //[nIsoTrack]
//		Float_t         IsoTrack_miniPFRelIso_chg[100];   //[nIsoTrack]
		
		Int_t           nJet;
//		UChar_t         Jet_chMultiplicity[100];   //[nJet]
//		UChar_t         Jet_nConstituents[100];   //[nJet]
//		UChar_t         Jet_nElectrons[100];   //[nJet]
//		UChar_t         Jet_nMuons[100];   //[nJet]
//		UChar_t         Jet_nSVs[100];   //[nJet]
//		UChar_t         Jet_neMultiplicity[100];   //[nJet]
//		Short_t         Jet_electronIdx1[100];   //[nJet]
//		Short_t         Jet_electronIdx2[100];   //[nJet]
//		Short_t         Jet_muonIdx1[100];   //[nJet]
//		Short_t         Jet_muonIdx2[100];   //[nJet]
//		Short_t         Jet_svIdx1[100];   //[nJet]
//		Short_t         Jet_svIdx2[100];   //[nJet]
//		Int_t           Jet_hfadjacentEtaStripsSize[100];   //[nJet]
//		Int_t           Jet_hfcentralEtaStripSize[100];   //[nJet]
//		Float_t         Jet_PNetRegPtRawCorr[100];   //[nJet]
//		Float_t         Jet_PNetRegPtRawCorrNeutrino[100];   //[nJet]
//		Float_t         Jet_PNetRegPtRawRes[100];   //[nJet]
//		Float_t         Jet_UParTAK4RegPtRawCorr[100];   //[nJet]
//		Float_t         Jet_UParTAK4RegPtRawCorrNeutrino[100];   //[nJet]
//		Float_t         Jet_UParTAK4RegPtRawRes[100];   //[nJet]
//		Float_t         Jet_UParTAK4V1RegPtRawCorr[100];   //[nJet]
//		Float_t         Jet_UParTAK4V1RegPtRawCorrNeutrino[100];   //[nJet]
//		Float_t         Jet_UParTAK4V1RegPtRawRes[100];   //[nJet]
//		Float_t         Jet_area[100];   //[nJet]
//		Float_t         Jet_btagDeepFlavB[100];   //[nJet]
//		Float_t         Jet_btagDeepFlavCvB[100];   //[nJet]
//		Float_t         Jet_btagDeepFlavCvL[100];   //[nJet]
//		Float_t         Jet_btagDeepFlavQG[100];   //[nJet]
//		Float_t         Jet_btagPNetB[100];   //[nJet]
//		Float_t         Jet_btagPNetCvB[100];   //[nJet]
//		Float_t         Jet_btagPNetCvL[100];   //[nJet]
//		Float_t         Jet_btagPNetCvNotB[100];   //[nJet]
//		Float_t         Jet_btagPNetQvG[100];   //[nJet]
//     	Float_t         Jet_btagPNetTauVJet[100];   //[nJet]
		Float_t         Jet_btagUParTAK4B[100];   //[nJet]
//		Float_t         Jet_btagUParTAK4CvB[100];   //[nJet]
//		Float_t         Jet_btagUParTAK4CvL[100];   //[nJet]
//		Float_t         Jet_btagUParTAK4CvNotB[100];   //[nJet]
//		Float_t         Jet_btagUParTAK4Ele[100];   //[nJet]
//		Float_t         Jet_btagUParTAK4Mu[100];   //[nJet]
//		Float_t         Jet_btagUParTAK4QvG[100];   //[nJet]
//		Float_t         Jet_btagUParTAK4SvCB[100];   //[nJet]
//		Float_t         Jet_btagUParTAK4SvUDG[100];   //[nJet]
//		Float_t         Jet_btagUParTAK4TauVJet[100];   //[nJet]
//		Float_t         Jet_btagUParTAK4UDG[100];   //[nJet]
//		Float_t         Jet_btagUParTAK4probb[100];   //[nJet]
//		Float_t         Jet_btagUParTAK4probbb[100];   //[nJet]
//		Float_t         Jet_chEmEF[100];   //[nJet]
//		Float_t         Jet_chHEF[100];   //[nJet]
		Float_t         Jet_eta[100];   //[nJet]
//		Float_t         Jet_hfEmEF[100];   //[nJet]
//		Float_t         Jet_hfHEF[100];   //[nJet]
//		Float_t         Jet_hfsigmaEtaEta[100];   //[nJet]
//		Float_t         Jet_hfsigmaPhiPhi[100];   //[nJet]
		Float_t         Jet_mass[100];   //[nJet]
//		Float_t         Jet_muEF[100];   //[nJet]
//		Float_t         Jet_muonSubtrDeltaEta[100];   //[nJet]
//		Float_t         Jet_muonSubtrDeltaPhi[100];   //[nJet]
//		Float_t         Jet_muonSubtrFactor[100];   //[nJet]
//		Float_t         Jet_neEmEF[100];   //[nJet]
//		Float_t         Jet_neHEF[100];   //[nJet]
		Float_t         Jet_phi[100];   //[nJet]
		Float_t         Jet_pt[100];   //[nJet]
//		Float_t         Jet_puIdDisc[100];   //[nJet]
//		Float_t         Jet_rawFactor[100];   //[nJet]
		
//		UChar_t         LHE_Njets;
//		UChar_t         LHE_Nb;
//		UChar_t         LHE_Nc;
//		UChar_t         LHE_Nuds;
//		UChar_t         LHE_Nglu;
//		UChar_t         LHE_NpNLO;
//		UChar_t         LHE_NpLO;
		Float_t         LHE_HT;
//		Float_t         LHE_HTIncoming;
		Float_t         LHE_Vpt;
//		Float_t         LHE_AlphaS;

/*
		Int_t           nLHEPart;
		Short_t         LHEPart_firstMotherIdx[100];   //[nLHEPart]
		Short_t         LHEPart_lastMotherIdx[100];   //[nLHEPart]
		Int_t           LHEPart_pdgId[100];   //[nLHEPart]
		Int_t           LHEPart_status[100];   //[nLHEPart]
		Int_t           LHEPart_spin[100];   //[nLHEPart]
		Float_t         LHEPart_pt[100];   //[nLHEPart]
		Float_t         LHEPart_eta[100];   //[nLHEPart]
		Float_t         LHEPart_phi[100];   //[nLHEPart]
		Float_t         LHEPart_mass[100];   //[nLHEPart]
		Float_t         LHEPart_incomingpz[100];   //[nLHEPart]
*/
/*		
		Int_t           nLowPtElectron;
		Bool_t          LowPtElectron_convVeto[100];   //[nLowPtElectron]
		UChar_t         LowPtElectron_convWP[100];   //[nLowPtElectron]
		UChar_t         LowPtElectron_lostHits[100];   //[nLowPtElectron]
		Short_t         LowPtElectron_electronIdx[100];   //[nLowPtElectron]
		Short_t         LowPtElectron_photonIdx[100];   //[nLowPtElectron]
		Int_t           LowPtElectron_charge[100];   //[nLowPtElectron]
		Int_t           LowPtElectron_pdgId[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_ID[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_convVtxRadius[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_deltaEtaSC[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_dxy[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_dxyErr[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_dz[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_dzErr[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_eInvMinusPInv[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_energyErr[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_eta[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_hoe[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_mass[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_miniPFRelIso_all[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_miniPFRelIso_chg[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_phi[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_pt[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_ptbiased[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_r9[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_scEtOverPt[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_sieie[100];   //[nLowPtElectron]
		Float_t         LowPtElectron_unbiased[100];   //[nLowPtElectron]
*/		
		Float_t         GenMET_phi;
		Float_t         GenMET_pt;
		
		Int_t           nMuon;
//		UChar_t         Muon_bestTrackType[100];   //[nMuon]
//		UChar_t         Muon_highPtId[100];   //[nMuon]
//		Bool_t          Muon_highPurity[100];   //[nMuon]
//		Bool_t          Muon_inTimeMuon[100];   //[nMuon]
//		Bool_t          Muon_isGlobal[100];   //[nMuon]
//		Bool_t          Muon_isPFcand[100];   //[nMuon]
//		Bool_t          Muon_isStandalone[100];   //[nMuon]
//		Bool_t          Muon_isTracker[100];   //[nMuon]
//		UChar_t         Muon_jetNDauCharged[100];   //[nMuon]
		Bool_t          Muon_looseId[100];   //[nMuon]
		Bool_t          Muon_mediumId[100];   //[nMuon]
		Bool_t          Muon_mediumPromptId[100];   //[nMuon]
//		UChar_t         Muon_miniIsoId[100];   //[nMuon]
//		UChar_t         Muon_multiIsoId[100];   //[nMuon]
//		UChar_t         Muon_mvaMuID_WP[100];   //[nMuon]
//		UChar_t         Muon_nStations[100];   //[nMuon]
//		UChar_t         Muon_nTrackerLayers[100];   //[nMuon]
//		UChar_t         Muon_pfIsoId[100];   //[nMuon]
//		UChar_t         Muon_puppiIsoId[100];   //[nMuon]
//		Bool_t          Muon_softId[100];   //[nMuon]
//		Bool_t          Muon_softMvaId[100];   //[nMuon]
//		UChar_t         Muon_tightCharge[100];   //[nMuon]
//		Bool_t          Muon_tightId[100];   //[nMuon]
//		UChar_t         Muon_tkIsoId[100];   //[nMuon]
//		Bool_t          Muon_triggerIdLoose[100];   //[nMuon]
//		Short_t         Muon_jetIdx[100];   //[nMuon]
//		Short_t         Muon_svIdx[100];   //[nMuon]
//		Short_t         Muon_fsrPhotonIdx[100];   //[nMuon]
		Int_t           Muon_charge[100];   //[nMuon]
//		Int_t           Muon_pdgId[100];   //[nMuon]
//		Float_t         Muon_VXBS_Cov00[100];   //[nMuon]
//		Float_t         Muon_VXBS_Cov03[100];   //[nMuon]
//		Float_t         Muon_VXBS_Cov33[100];   //[nMuon]
//		Float_t         Muon_dxy[100];   //[nMuon]
//		Float_t         Muon_dxyErr[100];   //[nMuon]
//		Float_t         Muon_dxybs[100];   //[nMuon]
//		Float_t         Muon_dxybsErr[100];   //[nMuon]
//		Float_t         Muon_dz[100];   //[nMuon]
//		Float_t         Muon_dzErr[100];   //[nMuon]
		Float_t         Muon_eta[100];   //[nMuon]
//		Float_t         Muon_ip3d[100];   //[nMuon]
//		Float_t         Muon_jetDF[100];   //[nMuon]
//		Float_t         Muon_jetPtRelv2[100];   //[nMuon]
//		Float_t         Muon_jetRelIso[100];   //[nMuon]
		Float_t         Muon_mass[100];   //[nMuon]
//		Float_t         Muon_miniPFRelIso_all[100];   //[nMuon]
//		Float_t         Muon_miniPFRelIso_chg[100];   //[nMuon]
//		Float_t         Muon_mvaMuID[100];   //[nMuon]
//		Float_t         Muon_pfRelIso03_all[100];   //[nMuon]
//		Float_t         Muon_pfRelIso03_chg[100];   //[nMuon]
//		Float_t         Muon_pfRelIso04_all[100];   //[nMuon]
		Float_t         Muon_phi[100];   //[nMuon]
		Float_t         Muon_pt[100];   //[nMuon]
//		Float_t         Muon_ptErr[100];   //[nMuon]
//		Float_t         Muon_segmentComp[100];   //[nMuon]
//		Float_t         Muon_sip3d[100];   //[nMuon]
//		Float_t         Muon_softMva[100];   //[nMuon]
//		Float_t         Muon_softMvaRun3[100];   //[nMuon]
//		Float_t         Muon_tkRelIso[100];   //[nMuon]
//		Float_t         Muon_tuneP_charge[100];   //[nMuon]
//		Float_t         Muon_tuneP_pterr[100];   //[nMuon]
//		Float_t         Muon_tunepRelPt[100];   //[nMuon]
//		Float_t         Muon_bsConstrainedChi2[100];   //[nMuon]
//		Float_t         Muon_bsConstrainedPt[100];   //[nMuon]
//		Float_t         Muon_bsConstrainedPtErr[100];   //[nMuon]
//		Float_t         Muon_mvaLowPt[100];   //[nMuon]
//		Float_t         Muon_pnScore_heavy[100];   //[nMuon]
//		Float_t         Muon_pnScore_light[100];   //[nMuon]
//		Float_t         Muon_pnScore_prompt[100];   //[nMuon]
//		Float_t         Muon_pnScore_tau[100];   //[nMuon]
		Float_t         Muon_promptMVA[100];   //[nMuon]
/*		
		Int_t           nPFCand;
		Int_t           PFCand_pdgId[100];   //[nPFCand]
		Float_t         PFCand_eta[100];   //[nPFCand]
		Float_t         PFCand_mass[100];   //[nPFCand]
		Float_t         PFCand_phi[100];   //[nPFCand]
		Float_t         PFCand_pt[100];   //[nPFCand]
*/		
//		Float_t         PFMET_covXX;
//		Float_t         PFMET_covXY;
//		Float_t         PFMET_covYY;
		Float_t         PFMET_phi;
//		Float_t         PFMET_phiUnclusteredDown;
//		Float_t         PFMET_phiUnclusteredUp;
		Float_t         PFMET_pt;
//		Float_t         PFMET_ptUnclusteredDown;
//		Float_t         PFMET_ptUnclusteredUp;
//		Float_t         PFMET_significance;
		Float_t         PFMET_sumEt;
//		Float_t         PFMET_sumPtUnclustered;
		/*
		Int_t           nPhoton;
		UChar_t         Photon_cutBased[100];   //[nPhoton]
		Bool_t          Photon_electronVeto[100];   //[nPhoton]
		Bool_t          Photon_hasConversionTracks[100];   //[nPhoton]
		Bool_t          Photon_isScEtaEB[100];   //[nPhoton]
		Bool_t          Photon_isScEtaEE[100];   //[nPhoton]
		Bool_t          Photon_mvaID_WP80[100];   //[nPhoton]
		Bool_t          Photon_mvaID_WP90[100];   //[nPhoton]
		Bool_t          Photon_pixelSeed[100];   //[nPhoton]
		UChar_t         Photon_seedGain[100];   //[nPhoton]
		Short_t         Photon_electronIdx[100];   //[nPhoton]
		Short_t         Photon_jetIdx[100];   //[nPhoton]
		Short_t         Photon_seediEtaOriX[100];   //[nPhoton]
		Short_t         Photon_seediPhiOriY[100];   //[nPhoton]
		Int_t           Photon_vidNestedWPBitmap[100];   //[nPhoton]
		Float_t         Photon_ecalPFClusterIso[100];   //[nPhoton]
		Float_t         Photon_energyErr[100];   //[nPhoton]
		Float_t         Photon_energyRaw[100];   //[nPhoton]
		Float_t         Photon_esEffSigmaRR[100];   //[nPhoton]
		Float_t         Photon_esEnergyOverRawE[100];   //[nPhoton]
		Float_t         Photon_eta[100];   //[nPhoton]
		Float_t         Photon_etaWidth[100];   //[nPhoton]
		Float_t         Photon_haloTaggerMVAVal[100];   //[nPhoton]
		Float_t         Photon_hcalPFClusterIso[100];   //[nPhoton]
		Float_t         Photon_hoe[100];   //[nPhoton]
		Float_t         Photon_hoe_PUcorr[100];   //[nPhoton]
		Float_t         Photon_hoe_Tower[100];   //[nPhoton]
		Float_t         Photon_mvaID[100];   //[nPhoton]
		Float_t         Photon_pfChargedIso[100];   //[nPhoton]
		Float_t         Photon_pfChargedIsoPFPV[100];   //[nPhoton]
		Float_t         Photon_pfChargedIsoWorstVtx[100];   //[nPhoton]
		Float_t         Photon_pfPhoIso03[100];   //[nPhoton]
		Float_t         Photon_pfRelIso03_all_quadratic[100];   //[nPhoton]
		Float_t         Photon_pfRelIso03_chg_quadratic[100];   //[nPhoton]
		Float_t         Photon_phi[100];   //[nPhoton]
		Float_t         Photon_phiWidth[100];   //[nPhoton]
		Float_t         Photon_pt[100];   //[nPhoton]
		Float_t         Photon_r9[100];   //[nPhoton]
		Float_t         Photon_s4[100];   //[nPhoton]
		Float_t         Photon_sieie[100];   //[nPhoton]
		Float_t         Photon_sieip[100];   //[nPhoton]
		Float_t         Photon_sipip[100];   //[nPhoton]
		Float_t         Photon_superclusterEta[100];   //[nPhoton]
		Float_t         Photon_trkSumPtHollowConeDR03[100];   //[nPhoton]
		Float_t         Photon_trkSumPtSolidConeDR04[100];   //[nPhoton]
		Float_t         Photon_x_calo[100];   //[nPhoton]
		Float_t         Photon_y_calo[100];   //[nPhoton]
		Float_t         Photon_z_calo[100];   //[nPhoton]
		*/
		Int_t           Pileup_nPU;
//		Int_t           Pileup_sumEOOT;
//		Int_t           Pileup_sumLOOT;
		Float_t         Pileup_nTrueInt;
//		Float_t         Pileup_pudensity;
//		Float_t         Pileup_gpudensity;
//		Float_t         Pileup_pthatmax;
		
//		Float_t         PuppiMET_covXX;
//		Float_t         PuppiMET_covXY;
//		Float_t         PuppiMET_covYY;
		Float_t         PuppiMET_phi;
//		Float_t         PuppiMET_phiUnclusteredDown;
//		Float_t         PuppiMET_phiUnclusteredUp;
		Float_t         PuppiMET_pt;
//		Float_t         PuppiMET_ptUnclusteredDown;
//		Float_t         PuppiMET_ptUnclusteredUp;
//		Float_t         PuppiMET_significance;
//		Float_t         PuppiMET_sumEt;
//		Float_t         PuppiMET_sumPtUnclustered;

/*
		Int_t           nPVBS;
		Float_t         PVBS_chi2[100];   //[nPVBS]
		Float_t         PVBS_cov00[100];   //[nPVBS]
		Float_t         PVBS_cov10[100];   //[nPVBS]
		Float_t         PVBS_cov11[100];   //[nPVBS]
		Float_t         PVBS_cov20[100];   //[nPVBS]
		Float_t         PVBS_cov21[100];   //[nPVBS]
		Float_t         PVBS_cov22[100];   //[nPVBS]
		Float_t         PVBS_x[100];   //[nPVBS]
		Float_t         PVBS_y[100];   //[nPVBS]
		Float_t         PVBS_z[100];   //[nPVBS]
*/

/*
		Float_t         RawPFMET_phi;
		Float_t         RawPFMET_pt;
		Float_t         RawPFMET_sumEt;
		Float_t         RawPuppiMET_phi;
		Float_t         RawPuppiMET_pt;
		Float_t         RawPuppiMET_sumEt;
		Float_t         Rho_fixedGridRhoAll;
		Float_t         Rho_fixedGridRhoFastjetAll;
		Float_t         Rho_fixedGridRhoFastjetCentral;
		Float_t         Rho_fixedGridRhoFastjetCentralCalo;
		Float_t         Rho_fixedGridRhoFastjetCentralChargedPileUp;
		Float_t         Rho_fixedGridRhoFastjetCentralNeutral;
*/
/*
		Int_t           nGenDressedLepton;
		Bool_t          GenDressedLepton_hasTauAnc[100];   //[nGenDressedLepton]
		Int_t           GenDressedLepton_pdgId[100];   //[nGenDressedLepton]
		Float_t         GenDressedLepton_eta[100];   //[nGenDressedLepton]
		Float_t         GenDressedLepton_mass[100];   //[nGenDressedLepton]
		Float_t         GenDressedLepton_phi[100];   //[nGenDressedLepton]
		Float_t         GenDressedLepton_pt[100];   //[nGenDressedLepton]
		Float_t         FiducialMET_phi;
		Float_t         FiducialMET_pt;
*/		
/*
		Int_t           nGenIsolatedPhoton;
		Float_t         GenIsolatedPhoton_eta[100];   //[nGenIsolatedPhoton]
		Float_t         GenIsolatedPhoton_mass[100];   //[nGenIsolatedPhoton]
		Float_t         GenIsolatedPhoton_phi[100];   //[nGenIsolatedPhoton]
		Float_t         GenIsolatedPhoton_pt[100];   //[nGenIsolatedPhoton]
*/
/*
		Int_t           nSoftActivityJet;
		Float_t         SoftActivityJet_eta[100];   //[nSoftActivityJet]
		Float_t         SoftActivityJet_phi[100];   //[nSoftActivityJet]
		Float_t         SoftActivityJet_pt[100];   //[nSoftActivityJet]
		Int_t           SoftActivityJetNjets10;
		Int_t           SoftActivityJetNjets2;
		Int_t           SoftActivityJetNjets5;
		Float_t         SoftActivityJetHT;
		Float_t         SoftActivityJetHT10;
		Float_t         SoftActivityJetHT2;
		Float_t         SoftActivityJetHT5;
*/
/*
		Int_t           nSubJet;
		Float_t         SubJet_UParTAK4RegPtRawCorr[100];   //[nSubJet]
		Float_t         SubJet_UParTAK4RegPtRawCorrNeutrino[100];   //[nSubJet]
		Float_t         SubJet_UParTAK4RegPtRawRes[100];   //[nSubJet]
		Float_t         SubJet_UParTAK4V1RegPtRawCorr[100];   //[nSubJet]
		Float_t         SubJet_UParTAK4V1RegPtRawCorrNeutrino[100];   //[nSubJet]
		Float_t         SubJet_UParTAK4V1RegPtRawRes[100];   //[nSubJet]
		Float_t         SubJet_area[100];   //[nSubJet]
		Float_t         SubJet_btagDeepFlavB[100];   //[nSubJet]
		Float_t         SubJet_btagUParTAK4B[100];   //[nSubJet]
		Float_t         SubJet_eta[100];   //[nSubJet]
		Float_t         SubJet_mass[100];   //[nSubJet]
		Float_t         SubJet_n2b1[100];   //[nSubJet]
		Float_t         SubJet_n3b1[100];   //[nSubJet]
		Float_t         SubJet_phi[100];   //[nSubJet]
		Float_t         SubJet_pt[100];   //[nSubJet]
		Float_t         SubJet_rawFactor[100];   //[nSubJet]
		Float_t         SubJet_tau1[100];   //[nSubJet]
		Float_t         SubJet_tau2[100];   //[nSubJet]
		Float_t         SubJet_tau3[100];   //[nSubJet]
		Float_t         SubJet_tau4[100];   //[nSubJet]
*/
/*
		Int_t           nTauProd;
		Short_t         TauProd_tauIdx[100];   //[nTauProd]
		Int_t           TauProd_pdgId[100];   //[nTauProd]
		Float_t         TauProd_eta[100];   //[nTauProd]
		Float_t         TauProd_phi[100];   //[nTauProd]
		Float_t         TauProd_pt[100];   //[nTauProd]
		Double_t        TauSpinner_weight_cp_0;
		Double_t        TauSpinner_weight_cp_0_alt;
		Double_t        TauSpinner_weight_cp_0p25;
		Double_t        TauSpinner_weight_cp_0p25_alt;
		Double_t        TauSpinner_weight_cp_0p5;
		Double_t        TauSpinner_weight_cp_0p5_alt;
		Double_t        TauSpinner_weight_cp_minus0p25;
		Double_t        TauSpinner_weight_cp_minus0p25_alt;
		Double_t        TauSpinner_weight_cp_0p375;
		Double_t        TauSpinner_weight_cp_0p375_alt;
*/

		Int_t           nTau;
//		UChar_t         Tau_decayMode[100];   //[nTau]
//		Bool_t          Tau_idAntiEleDeadECal[100];   //[nTau]
//		UChar_t         Tau_idAntiMu[100];   //[nTau]
//		Bool_t          Tau_idDecayModeNewDMs[100];   //[nTau]
//		Bool_t          Tau_idDecayModeOldDMs[100];   //[nTau]
		UChar_t         Tau_idDeepTau2018v2p5VSe[100];   //[nTau]
		UChar_t         Tau_idDeepTau2018v2p5VSjet[100];   //[nTau]
		UChar_t         Tau_idDeepTau2018v2p5VSmu[100];   //[nTau]
//		UChar_t         Tau_nSVs[100];   //[nTau]
//		Short_t         Tau_charge[100];   //[nTau]
//		Short_t         Tau_decayModePNet[100];   //[nTau]
//		Short_t         Tau_decayModeUParT[100];   //[nTau]
//		Short_t         Tau_eleIdx[100];   //[nTau]
//		Short_t         Tau_jetIdx[100];   //[nTau]
//		Short_t         Tau_muIdx[100];   //[nTau]
//		Short_t         Tau_svIdx1[100];   //[nTau]
//		Short_t         Tau_svIdx2[100];   //[nTau]
//		Float_t         Tau_chargedIso[100];   //[nTau]
//		Float_t         Tau_dxy[100];   //[nTau]
//		Float_t         Tau_dz[100];   //[nTau]
		Float_t         Tau_eta[100];   //[nTau]
//		Float_t         Tau_leadTkDeltaEta[100];   //[nTau]
//		Float_t         Tau_leadTkDeltaPhi[100];   //[nTau]
//		Float_t         Tau_leadTkPtOverTauPt[100];   //[nTau]
//		Float_t         Tau_mass[100];   //[nTau]
//		Float_t         Tau_neutralIso[100];   //[nTau]
		Float_t         Tau_phi[100];   //[nTau]
//		Float_t         Tau_photonsOutsideSignalCone[100];   //[nTau]
//		Float_t         Tau_probDM0PNet[100];   //[nTau]
//		Float_t         Tau_probDM0UParT[100];   //[nTau]
//		Float_t         Tau_probDM10PNet[100];   //[nTau]
//		Float_t         Tau_probDM10UParT[100];   //[nTau]
//		Float_t         Tau_probDM11PNet[100];   //[nTau]
//		Float_t         Tau_probDM11UParT[100];   //[nTau]
//		Float_t         Tau_probDM1PNet[100];   //[nTau]
//		Float_t         Tau_probDM1UParT[100];   //[nTau]
//		Float_t         Tau_probDM2PNet[100];   //[nTau]
//		Float_t         Tau_probDM2UParT[100];   //[nTau]
		Float_t         Tau_pt[100];   //[nTau]
//		Float_t         Tau_ptCorrPNet[100];   //[nTau]
//		Float_t         Tau_ptCorrUParT[100];   //[nTau]
//		Float_t         Tau_puCorr[100];   //[nTau]
//		Float_t         Tau_qConfPNet[100];   //[nTau]
//		Float_t         Tau_qConfUParT[100];   //[nTau]
//		Float_t         Tau_rawDeepTau2018v2p5VSe[100];   //[nTau]
//		Float_t         Tau_rawDeepTau2018v2p5VSjet[100];   //[nTau]
//		Float_t         Tau_rawDeepTau2018v2p5VSmu[100];   //[nTau]
//		Float_t         Tau_rawIso[100];   //[nTau]
//		Float_t         Tau_rawIsodR03[100];   //[nTau]
//		Float_t         Tau_rawPNetVSe[100];   //[nTau]
//		Float_t         Tau_rawPNetVSjet[100];   //[nTau]
//		Float_t         Tau_rawPNetVSmu[100];   //[nTau]
//		Float_t         Tau_rawUParTVSe[100];   //[nTau]
//		Float_t         Tau_rawUParTVSjet[100];   //[nTau]
//		Float_t         Tau_rawUParTVSmu[100];   //[nTau]
/*		
		Int_t           nTrackGenJetAK4;
		Float_t         TrackGenJetAK4_eta[100];   //[nTrackGenJetAK4]
		Float_t         TrackGenJetAK4_phi[100];   //[nTrackGenJetAK4]
		Float_t         TrackGenJetAK4_pt[100];   //[nTrackGenJetAK4]
*/
/*
		Int_t           nTrigObj;
		Short_t         TrigObj_l1charge[100];   //[nTrigObj]
		UShort_t        TrigObj_id[100];   //[nTrigObj]
		Int_t           TrigObj_l1iso[100];   //[nTrigObj]
		ULong64_t       TrigObj_filterBits[100];   //[nTrigObj]
		Float_t         TrigObj_pt[100];   //[nTrigObj]
		Float_t         TrigObj_eta[100];   //[nTrigObj]
		Float_t         TrigObj_phi[100];   //[nTrigObj]
		Float_t         TrigObj_l1pt[100];   //[nTrigObj]
		Float_t         TrigObj_l1pt_2[100];   //[nTrigObj]
		Float_t         TrigObj_l2pt[100];   //[nTrigObj]
		Float_t         TrkMET_phi;
		Float_t         TrkMET_pt;
		Float_t         TrkMET_sumEt;
		Int_t           genTtbarId;
*/
/*
		Int_t           nOtherPV;
		Float_t         OtherPV_z[100];   //[nOtherPV]
		Float_t         OtherPV_score[100];   //[nOtherPV]
		UChar_t         PV_npvs;
		UChar_t         PV_npvsGood;
		Float_t         PV_ndof;
		Float_t         PV_x;
		Float_t         PV_y;
		Float_t         PV_z;
		Float_t         PV_chi2;
		Float_t         PV_score;
		Float_t         PV_sumpt2;
		Float_t         PV_sumpx;
		Float_t         PV_sumpy;
*/		
		Int_t           nSV;
//		Short_t         SV_charge[100];   //[nSV]
//		Float_t         SV_dlen[100];   //[nSV]
//		Float_t         SV_dlenSig[100];   //[nSV]
//		Float_t         SV_dxy[100];   //[nSV]
//		Float_t         SV_dxySig[100];   //[nSV]
//		Float_t         SV_pAngle[100];   //[nSV]

/*
		UChar_t         boostedTau_genPartFlav[100];   //[nboostedTau]
		Short_t         boostedTau_genPartIdx[100];   //[nboostedTau]
*/
/*
		UChar_t         Electron_genPartFlav[100];   //[nElectron]
		Short_t         Electron_genPartIdx[100];   //[nElectron]
		Float_t         Electron_IPx[100];   //[nElectron]
		Float_t         Electron_IPy[100];   //[nElectron]
		Float_t         Electron_IPz[100];   //[nElectron]
		Float_t         Electron_ipLengthSig[100];   //[nElectron]
*/

//		UChar_t         FatJet_hadronFlavour[100];   //[nFatJet]
//		Short_t         FatJet_genJetAK8Idx[100];   //[nFatJet]
/*		
		UChar_t         GenJetAK8_hadronFlavour[100];   //[nGenJetAK8]
		UChar_t         GenJetAK8_nBHadrons[100];   //[nGenJetAK8]
		UChar_t         GenJetAK8_nCHadrons[100];   //[nGenJetAK8]
		Short_t         GenJetAK8_partonFlavour[100];   //[nGenJetAK8]
*/
/*
		UChar_t         GenJet_hadronFlavour[100];   //[nGenJet]
		UChar_t         GenJet_nBHadrons[100];   //[nGenJet]
		UChar_t         GenJet_nCHadrons[100];   //[nGenJet]
		Short_t         GenJet_partonFlavour[100];   //[nGenJet]
*/

//		Float_t         GenVtx_t0;
		
//		UChar_t         Jet_hadronFlavour[100];   //[nJet]
//		Short_t         Jet_genJetIdx[100];   //[nJet]
//		Short_t         Jet_partonFlavour[100];   //[nJet]
		
//		UChar_t         LowPtElectron_genPartFlav[100];   //[nLowPtElectron]
//		Short_t         LowPtElectron_genPartIdx[100];   //[nLowPtElectron]
		
//		UChar_t         Muon_genPartFlav[100];   //[nMuon]
//		Short_t         Muon_genPartIdx[100];   //[nMuon]
//		Float_t         Muon_IPx[100];   //[nMuon]
//		Float_t         Muon_IPy[100];   //[nMuon]
//		Float_t         Muon_IPz[100];   //[nMuon]
//		Float_t         Muon_ipLengthSig[100];   //[nMuon]
		
//		UChar_t         Photon_genPartFlav[100];   //[nPhoton]
//		Short_t         Photon_genPartIdx[100];   //[nPhoton]
		
//		UChar_t         SubJet_hadronFlavour[100];   //[nSubJet]
//		UChar_t         SubJet_nBHadrons[100];   //[nSubJet]
//		UChar_t         SubJet_nCHadrons[100];   //[nSubJet]
//		Short_t         SubJet_subGenJetAK8Idx[100];   //[nSubJet]
		/*
		UChar_t         SV_ntracks[100];   //[nSV]
		Float_t         SV_chi2[100];   //[nSV]
		Float_t         SV_eta[100];   //[nSV]
		Float_t         SV_mass[100];   //[nSV]
		Float_t         SV_ndof[100];   //[nSV]
		Float_t         SV_phi[100];   //[nSV]
		Float_t         SV_pt[100];   //[nSV]
		Float_t         SV_x[100];   //[nSV]
		Float_t         SV_y[100];   //[nSV]
		Float_t         SV_z[100];   //[nSV]
		*/
		/*
		UChar_t         Tau_genPartFlav[100];   //[nTau]
		Short_t         Tau_genPartIdx[100];   //[nTau]
		Bool_t          Tau_hasRefitSV[100];   //[nTau]
		Float_t         Tau_IPx[100];   //[nTau]
		Float_t         Tau_IPy[100];   //[nTau]
		Float_t         Tau_IPz[100];   //[nTau]
		Float_t         Tau_ipLengthSig[100];   //[nTau]
		Float_t         Tau_refitSVchi2[100];   //[nTau]
		Float_t         Tau_refitSVcov00[100];   //[nTau]
		Float_t         Tau_refitSVcov10[100];   //[nTau]
		Float_t         Tau_refitSVcov11[100];   //[nTau]
		Float_t         Tau_refitSVcov20[100];   //[nTau]
		Float_t         Tau_refitSVcov21[100];   //[nTau]
		Float_t         Tau_refitSVcov22[100];   //[nTau]
		Float_t         Tau_refitSVx[100];   //[nTau]
		Float_t         Tau_refitSVy[100];   //[nTau]
		Float_t         Tau_refitSVz[100];   //[nTau]
		*/
/*
   Bool_t          L1_AXO_Loose;
   Bool_t          L1_AXO_Nominal;
   Bool_t          L1_AXO_Tight;
   Bool_t          L1_AXO_VLoose;
   Bool_t          L1_AXO_VTight;
   Bool_t          L1_AlwaysTrue;
   Bool_t          L1_BPTX_AND_Ref1_VME;
   Bool_t          L1_BPTX_AND_Ref3_VME;
   Bool_t          L1_BPTX_AND_Ref4_VME;
   Bool_t          L1_BPTX_BeamGas_B1_VME;
   Bool_t          L1_BPTX_BeamGas_B2_VME;
   Bool_t          L1_BPTX_BeamGas_Ref1_VME;
   Bool_t          L1_BPTX_BeamGas_Ref2_VME;
   Bool_t          L1_BPTX_NotOR_VME;
   Bool_t          L1_BPTX_OR_Ref3_VME;
   Bool_t          L1_BPTX_OR_Ref4_VME;
   Bool_t          L1_BPTX_RefAND_VME;
   Bool_t          L1_BptxMinus;
   Bool_t          L1_BptxOR;
   Bool_t          L1_BptxPlus;
   Bool_t          L1_BptxXOR;
   Bool_t          L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;
   Bool_t          L1_CICADA_Loose;
   Bool_t          L1_CICADA_Medium;
   Bool_t          L1_CICADA_Tight;
   Bool_t          L1_CICADA_VLoose;
   Bool_t          L1_CICADA_VTight;
   Bool_t          L1_DoubleEG11_er1p2_dR_Max0p6;
   Bool_t          L1_DoubleEG8er2p5_HTT280er;
   Bool_t          L1_DoubleEG8er2p5_HTT300er;
   Bool_t          L1_DoubleEG8er2p5_HTT320er;
   Bool_t          L1_DoubleEG_15_10_er2p5;
   Bool_t          L1_DoubleEG_20_10_er2p5;
   Bool_t          L1_DoubleEG_22_10_er2p5;
   Bool_t          L1_DoubleEG_25_12_er2p5;
   Bool_t          L1_DoubleEG_25_14_er2p5;
   Bool_t          L1_DoubleEG_27_14_er2p5;
   Bool_t          L1_DoubleEG_LooseIso16_LooseIso12_er1p5;
   Bool_t          L1_DoubleEG_LooseIso18_LooseIso12_er1p5;
   Bool_t          L1_DoubleEG_LooseIso20_LooseIso12_er1p5;
   Bool_t          L1_DoubleEG_LooseIso22_12_er2p5;
   Bool_t          L1_DoubleEG_LooseIso22_LooseIso12_er1p5;
   Bool_t          L1_DoubleEG_LooseIso25_12_er2p5;
   Bool_t          L1_DoubleEG_LooseIso25_LooseIso12_er1p5;
   Bool_t          L1_DoubleIsoTau26er2p1_Jet55_RmOvlp_dR0p5;
   Bool_t          L1_DoubleIsoTau26er2p1_Jet70_RmOvlp_dR0p5;
   Bool_t          L1_DoubleIsoTau28er2p1;
   Bool_t          L1_DoubleIsoTau30er2p1;
   Bool_t          L1_DoubleIsoTau32er2p1;
   Bool_t          L1_DoubleIsoTau32er2p1_Mass_Max80;
   Bool_t          L1_DoubleIsoTau34er2p1;
   Bool_t          L1_DoubleIsoTau35er2p1;
   Bool_t          L1_DoubleIsoTau36er2p1;
   Bool_t          L1_DoubleJet100er2p3_dEta_Max1p6;
   Bool_t          L1_DoubleJet100er2p5;
   Bool_t          L1_DoubleJet112er2p3_dEta_Max1p6;
   Bool_t          L1_DoubleJet120er2p5;
   Bool_t          L1_DoubleJet120er2p5_Mu3_dR_Max0p8;
   Bool_t          L1_DoubleJet150er2p5;
   Bool_t          L1_DoubleJet16er2p5_Mu3_dR_Max0p4;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min225_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min250_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min300_dEta_Max1p5;
   Bool_t          L1_DoubleJet30er2p5_Mass_Min330_dEta_Max1p5;
   Bool_t          L1_DoubleJet35er2p5_Mu3_dR_Max0p4;
   Bool_t          L1_DoubleJet40er2p5;
   Bool_t          L1_DoubleJet45_Mass_Min550_IsoTau45er2p1_RmOvlp_dR0p5;
   Bool_t          L1_DoubleJet45_Mass_Min550_LooseIsoEG20er2p1_RmOvlp_dR0p2;
   Bool_t          L1_DoubleJet45_Mass_Min600_IsoTau45er2p1_RmOvlp_dR0p5;
   Bool_t          L1_DoubleJet45_Mass_Min600_LooseIsoEG20er2p1_RmOvlp_dR0p2;
   Bool_t          L1_DoubleJet60er2p5_Mu3_dR_Max0p4;
   Bool_t          L1_DoubleJet80er2p5_Mu3_dR_Max0p4;
   Bool_t          L1_DoubleJet_110_35_DoubleJet35_Mass_Min800;
   Bool_t          L1_DoubleJet_110_35_DoubleJet35_Mass_Min850;
   Bool_t          L1_DoubleJet_65_35_DoubleJet35_Mass_Min600_DoubleJetCentral50;
   Bool_t          L1_DoubleJet_65_35_DoubleJet35_Mass_Min650_DoubleJetCentral50;
   Bool_t          L1_DoubleJet_70_35_DoubleJet35_Mass_Min500_ETMHF65;
   Bool_t          L1_DoubleJet_70_35_DoubleJet35_Mass_Min550_ETMHF65;
   Bool_t          L1_DoubleJet_85_35_DoubleJet35_Mass_Min600_Mu3OQ;
   Bool_t          L1_DoubleJet_85_35_DoubleJet35_Mass_Min650_Mu3OQ;
   Bool_t          L1_DoubleLLPJet40;
   Bool_t          L1_DoubleLooseIsoEG22er2p1;
   Bool_t          L1_DoubleLooseIsoEG24er2p1;
   Bool_t          L1_DoubleMu0;
   Bool_t          L1_DoubleMu0_Mass_Min1;
   Bool_t          L1_DoubleMu0_OQ;
   Bool_t          L1_DoubleMu0_SQ;
   Bool_t          L1_DoubleMu0_SQ_OS;
   Bool_t          L1_DoubleMu0_Upt15_Upt7;
   Bool_t          L1_DoubleMu0_Upt5_Upt5;
   Bool_t          L1_DoubleMu0_Upt6_IP_Min1_Upt4;
   Bool_t          L1_DoubleMu0_Upt6_SQ_er2p0;
   Bool_t          L1_DoubleMu0_Upt7_SQ_er2p0;
   Bool_t          L1_DoubleMu0_Upt8_SQ_er2p0;
   Bool_t          L1_DoubleMu0_dR_Max1p6_Jet90er2p5_dR_Max0p8;
   Bool_t          L1_DoubleMu0er1p4_OQ_OS_dEta_Max1p6;
   Bool_t          L1_DoubleMu0er1p4_SQ_OS_dEta_Max1p2;
   Bool_t          L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4;
   Bool_t          L1_DoubleMu0er1p5_SQ;
   Bool_t          L1_DoubleMu0er1p5_SQ_OS;
   Bool_t          L1_DoubleMu0er1p5_SQ_OS_dEta_Max1p2;
   Bool_t          L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4;
   Bool_t          L1_DoubleMu0er1p5_SQ_dR_Max1p4;
   Bool_t          L1_DoubleMu0er2p0_SQ_OS_dEta_Max0p3_dPhi_0p8to1p2;
   Bool_t          L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p5;
   Bool_t          L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p6;
   Bool_t          L1_DoubleMu0er2p0_SQ_dEta_Max1p5;
   Bool_t          L1_DoubleMu0er2p0_SQ_dEta_Max1p6;
   Bool_t          L1_DoubleMu18er2p1_SQ;
   Bool_t          L1_DoubleMu3_OS_er2p3_Mass_Max14_DoubleEG7p5_er2p1_Mass_Max20;
   Bool_t          L1_DoubleMu3_SQ_ETMHF30_HTT60er;
   Bool_t          L1_DoubleMu3_SQ_ETMHF30_Jet60er2p5_OR_DoubleJet40er2p5;
   Bool_t          L1_DoubleMu3_SQ_ETMHF40_HTT60er;
   Bool_t          L1_DoubleMu3_SQ_ETMHF40_Jet60er2p5_OR_DoubleJet40er2p5;
   Bool_t          L1_DoubleMu3_SQ_ETMHF50_HTT60er;
   Bool_t          L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5;
   Bool_t          L1_DoubleMu3_SQ_ETMHF50_Jet60er2p5_OR_DoubleJet40er2p5;
   Bool_t          L1_DoubleMu3_SQ_ETMHF60_Jet60er2p5;
   Bool_t          L1_DoubleMu3_SQ_HTT220er;
   Bool_t          L1_DoubleMu3er2p0_SQ_OS_dR_Max1p6;
   Bool_t          L1_DoubleMu4_SQ_EG9er2p5;
   Bool_t          L1_DoubleMu4_SQ_OS;
   Bool_t          L1_DoubleMu4_SQ_OS_dR_Max1p2;
   Bool_t          L1_DoubleMu4er2p0_SQ_OS_dR_Max1p6;
   Bool_t          L1_DoubleMu4p5_SQ_OS;
   Bool_t          L1_DoubleMu4p5_SQ_OS_dR_Max1p2;
   Bool_t          L1_DoubleMu4p5er2p0_SQ_OS;
   Bool_t          L1_DoubleMu4p5er2p0_SQ_OS_Mass_7to18;
   Bool_t          L1_DoubleMu4p5er2p0_SQ_OS_Mass_Min7;
   Bool_t          L1_DoubleMu5_OS_er2p3_Mass_8to14_DoubleEG3er2p1_Mass_Max20;
   Bool_t          L1_DoubleMu5_SQ_EG9er2p5;
   Bool_t          L1_DoubleMu5_SQ_OS_dR_Max1p6;
   Bool_t          L1_DoubleMu6_Upt6_SQ_er2p0;
   Bool_t          L1_DoubleMu7_Upt7_SQ_er2p0;
   Bool_t          L1_DoubleMu8_SQ;
   Bool_t          L1_DoubleMu8_Upt8_SQ_er2p0;
   Bool_t          L1_DoubleMu9_SQ;
   Bool_t          L1_DoubleMu_12_5;
   Bool_t          L1_DoubleMu_15_5_SQ;
   Bool_t          L1_DoubleMu_15_7;
   Bool_t          L1_DoubleMu_15_7_Mass_Min1;
   Bool_t          L1_DoubleMu_15_7_SQ;
   Bool_t          L1_DoubleTau70er2p1;
   Bool_t          L1_ETM120;
   Bool_t          L1_ETM150;
   Bool_t          L1_ETMHF100;
   Bool_t          L1_ETMHF100_HTT60er;
   Bool_t          L1_ETMHF110;
   Bool_t          L1_ETMHF110_HTT60er;
   Bool_t          L1_ETMHF120;
   Bool_t          L1_ETMHF120_HTT60er;
   Bool_t          L1_ETMHF130;
   Bool_t          L1_ETMHF130_HTT60er;
   Bool_t          L1_ETMHF140;
   Bool_t          L1_ETMHF150;
   Bool_t          L1_ETMHF70;
   Bool_t          L1_ETMHF70_HTT60er;
   Bool_t          L1_ETMHF80;
   Bool_t          L1_ETMHF80_HTT60er;
   Bool_t          L1_ETMHF80_SingleJet55er2p5_dPhi_Min2p1;
   Bool_t          L1_ETMHF80_SingleJet55er2p5_dPhi_Min2p6;
   Bool_t          L1_ETMHF90;
   Bool_t          L1_ETMHF90_HTT60er;
   Bool_t          L1_ETMHF90_SingleJet60er2p5_dPhi_Min2p1;
   Bool_t          L1_ETMHF90_SingleJet60er2p5_dPhi_Min2p6;
   Bool_t          L1_ETT2000;
   Bool_t          L1_FirstBunchAfterTrain;
   Bool_t          L1_FirstBunchBeforeTrain;
   Bool_t          L1_FirstBunchInTrain;
   Bool_t          L1_FirstCollisionInOrbit;
   Bool_t          L1_FirstCollisionInTrain;
   Bool_t          L1_HCAL_LaserMon_Trig;
   Bool_t          L1_HCAL_LaserMon_Veto;
   Bool_t          L1_HTMHF100;
   Bool_t          L1_HTMHF120;
   Bool_t          L1_HTMHF125;
   Bool_t          L1_HTMHF130;
   Bool_t          L1_HTMHF150;
   Bool_t          L1_HTT120_SingleLLPJet40;
   Bool_t          L1_HTT120er;
   Bool_t          L1_HTT160_SingleLLPJet50;
   Bool_t          L1_HTT160er;
   Bool_t          L1_HTT200_SingleLLPJet60;
   Bool_t          L1_HTT200er;
   Bool_t          L1_HTT240_SingleLLPJet70;
   Bool_t          L1_HTT255er;
   Bool_t          L1_HTT280er;
   Bool_t          L1_HTT280er_QuadJet_70_55_40_35_er2p5;
   Bool_t          L1_HTT320er;
   Bool_t          L1_HTT320er_QuadJet_70_55_40_40_er2p5;
   Bool_t          L1_HTT320er_QuadJet_80_60_er2p1_45_40_er2p3;
   Bool_t          L1_HTT320er_QuadJet_80_60_er2p1_50_45_er2p3;
   Bool_t          L1_HTT360er;
   Bool_t          L1_HTT400er;
   Bool_t          L1_HTT450er;
   Bool_t          L1_IsoEG32er2p5_Mt40;
   Bool_t          L1_IsoTau52er2p1_QuadJet36er2p5;
   Bool_t          L1_IsolatedBunch;
   Bool_t          L1_LastBunchInTrain;
   Bool_t          L1_LastCollisionInTrain;
   Bool_t          L1_LooseIsoEG14er2p5_HTT200er;
   Bool_t          L1_LooseIsoEG16er2p5_HTT200er;
   Bool_t          L1_LooseIsoEG22er2p1_IsoTau26er2p1_dR_Min0p3;
   Bool_t          L1_LooseIsoEG22er2p1_Tau70er2p1_dR_Min0p3;
   Bool_t          L1_LooseIsoEG24er2p1_HTT100er;
   Bool_t          L1_LooseIsoEG24er2p1_IsoTau27er2p1_dR_Min0p3;
   Bool_t          L1_LooseIsoEG26er2p1_HTT100er;
   Bool_t          L1_LooseIsoEG26er2p1_Jet34er2p5_dR_Min0p3;
   Bool_t          L1_LooseIsoEG28er2p1_HTT100er;
   Bool_t          L1_LooseIsoEG28er2p1_Jet34er2p5_dR_Min0p3;
   Bool_t          L1_LooseIsoEG30er2p1_Jet34er2p5_dR_Min0p3;
   Bool_t          L1_MinimumBiasHF0;
   Bool_t          L1_MinimumBiasHF0_AND_BptxAND;
   Bool_t          L1_Mu10er2p3_Jet32er2p3_dR_Max0p4_DoubleJet32er2p3_dEta_Max1p6;
   Bool_t          L1_Mu12_HTT150er;
   Bool_t          L1_Mu12er2p3_Jet40er2p3_dR_Max0p4_DoubleJet40er2p3_dEta_Max1p6;
   Bool_t          L1_Mu14_HTT150er;
   Bool_t          L1_Mu18er2p1_Tau24er2p1;
   Bool_t          L1_Mu18er2p1_Tau26er2p1;
   Bool_t          L1_Mu18er2p1_Tau26er2p1_Jet55;
   Bool_t          L1_Mu18er2p1_Tau26er2p1_Jet70;
   Bool_t          L1_Mu20_EG10er2p5;
   Bool_t          L1_Mu22er2p1_IsoTau30er2p1;
   Bool_t          L1_Mu22er2p1_IsoTau32er2p1;
   Bool_t          L1_Mu22er2p1_IsoTau34er2p1;
   Bool_t          L1_Mu22er2p1_IsoTau40er2p1;
   Bool_t          L1_Mu22er2p1_Tau70er2p1;
   Bool_t          L1_Mu3_Jet120er2p5_dR_Max0p4;
   Bool_t          L1_Mu3_Jet16er2p5_dR_Max0p4;
   Bool_t          L1_Mu3_Jet30er2p5;
   Bool_t          L1_Mu3_Jet60er2p5_dR_Max0p4;
   Bool_t          L1_Mu3er1p5_Jet100er2p5_ETMHF30;
   Bool_t          L1_Mu3er1p5_Jet100er2p5_ETMHF40;
   Bool_t          L1_Mu3er1p5_Jet100er2p5_ETMHF50;
   Bool_t          L1_Mu5_EG23er2p5;
   Bool_t          L1_Mu5_LooseIsoEG20er2p5;
   Bool_t          L1_Mu6_DoubleEG10er2p5;
   Bool_t          L1_Mu6_DoubleEG12er2p5;
   Bool_t          L1_Mu6_DoubleEG15er2p5;
   Bool_t          L1_Mu6_DoubleEG17er2p5;
   Bool_t          L1_Mu6_HTT240er;
   Bool_t          L1_Mu6_HTT250er;
   Bool_t          L1_Mu7_EG20er2p5;
   Bool_t          L1_Mu7_EG23er2p5;
   Bool_t          L1_Mu7_LooseIsoEG20er2p5;
   Bool_t          L1_Mu7_LooseIsoEG23er2p5;
   Bool_t          L1_NotBptxOR;
   Bool_t          L1_QuadJet60er2p5;
   Bool_t          L1_QuadJet_95_75_65_20_DoubleJet_75_65_er2p5_Jet20_FWD3p0;
   Bool_t          L1_QuadMu0;
   Bool_t          L1_QuadMu0_OQ;
   Bool_t          L1_QuadMu0_SQ;
   Bool_t          L1_SecondBunchInTrain;
   Bool_t          L1_SecondLastBunchInTrain;
   Bool_t          L1_SingleEG10er2p5;
   Bool_t          L1_SingleEG15er2p5;
   Bool_t          L1_SingleEG26er2p5;
   Bool_t          L1_SingleEG28_FWD2p5;
   Bool_t          L1_SingleEG28er1p5;
   Bool_t          L1_SingleEG28er2p1;
   Bool_t          L1_SingleEG28er2p5;
   Bool_t          L1_SingleEG34er2p5;
   Bool_t          L1_SingleEG36er2p5;
   Bool_t          L1_SingleEG38er2p5;
   Bool_t          L1_SingleEG40er2p5;
   Bool_t          L1_SingleEG42er2p5;
   Bool_t          L1_SingleEG45er2p5;
   Bool_t          L1_SingleEG50;
   Bool_t          L1_SingleEG60;
   Bool_t          L1_SingleEG8er2p5;
   Bool_t          L1_SingleIsoEG24er2p1;
   Bool_t          L1_SingleIsoEG26er2p1;
   Bool_t          L1_SingleIsoEG26er2p5;
   Bool_t          L1_SingleIsoEG28_FWD2p5;
   Bool_t          L1_SingleIsoEG28er1p5;
   Bool_t          L1_SingleIsoEG28er2p1;
   Bool_t          L1_SingleIsoEG28er2p5;
   Bool_t          L1_SingleIsoEG30er2p1;
   Bool_t          L1_SingleIsoEG30er2p5;
   Bool_t          L1_SingleIsoEG32er2p1;
   Bool_t          L1_SingleIsoEG32er2p5;
   Bool_t          L1_SingleIsoEG34er2p5;
   Bool_t          L1_SingleJet10erHE;
   Bool_t          L1_SingleJet120;
   Bool_t          L1_SingleJet120_FWD2p5;
   Bool_t          L1_SingleJet120_FWD3p0;
   Bool_t          L1_SingleJet120er1p3;
   Bool_t          L1_SingleJet120er2p5;
   Bool_t          L1_SingleJet12erHE;
   Bool_t          L1_SingleJet140er2p5;
   Bool_t          L1_SingleJet160er2p5;
   Bool_t          L1_SingleJet180;
   Bool_t          L1_SingleJet180er2p5;
   Bool_t          L1_SingleJet200;
   Bool_t          L1_SingleJet20er2p5_NotBptxOR;
   Bool_t          L1_SingleJet20er2p5_NotBptxOR_3BX;
   Bool_t          L1_SingleJet35;
   Bool_t          L1_SingleJet35_FWD2p5;
   Bool_t          L1_SingleJet35_FWD3p0;
   Bool_t          L1_SingleJet35er1p3;
   Bool_t          L1_SingleJet35er2p5;
   Bool_t          L1_SingleJet43er2p5_NotBptxOR_3BX;
   Bool_t          L1_SingleJet46er2p5_NotBptxOR_3BX;
   Bool_t          L1_SingleJet60;
   Bool_t          L1_SingleJet60_FWD2p5;
   Bool_t          L1_SingleJet8erHE;
   Bool_t          L1_SingleJet90;
   Bool_t          L1_SingleJet90_FWD2p5;
   Bool_t          L1_SingleLooseIsoEG26er1p5;
   Bool_t          L1_SingleLooseIsoEG26er2p5;
   Bool_t          L1_SingleLooseIsoEG28_FWD2p5;
   Bool_t          L1_SingleLooseIsoEG28er1p5;
   Bool_t          L1_SingleLooseIsoEG28er2p1;
   Bool_t          L1_SingleLooseIsoEG28er2p5;
   Bool_t          L1_SingleLooseIsoEG30er1p5;
   Bool_t          L1_SingleLooseIsoEG30er2p5;
   Bool_t          L1_SingleMu0_BMTF;
   Bool_t          L1_SingleMu0_DQ;
   Bool_t          L1_SingleMu0_EMTF;
   Bool_t          L1_SingleMu0_OMTF;
   Bool_t          L1_SingleMu0_SQ13_BMTF;
   Bool_t          L1_SingleMu0_SQ14_BMTF;
   Bool_t          L1_SingleMu0_SQ15_BMTF;
   Bool_t          L1_SingleMu0_Upt10;
   Bool_t          L1_SingleMu0_Upt10_BMTF;
   Bool_t          L1_SingleMu0_Upt10_EMTF;
   Bool_t          L1_SingleMu0_Upt10_OMTF;
   Bool_t          L1_SingleMu0_Upt10_SQ14_BMTF;
   Bool_t          L1_SingleMu0_Upt15_SQ14_BMTF;
   Bool_t          L1_SingleMu0_Upt20_SQ14_BMTF;
   Bool_t          L1_SingleMu0_Upt25_SQ14_BMTF;
   Bool_t          L1_SingleMu10_SQ14_BMTF;
   Bool_t          L1_SingleMu11_SQ14_BMTF;
   Bool_t          L1_SingleMu12_DQ_BMTF;
   Bool_t          L1_SingleMu12_DQ_EMTF;
   Bool_t          L1_SingleMu12_DQ_OMTF;
   Bool_t          L1_SingleMu15_DQ;
   Bool_t          L1_SingleMu18;
   Bool_t          L1_SingleMu20;
   Bool_t          L1_SingleMu22;
   Bool_t          L1_SingleMu22_BMTF;
   Bool_t          L1_SingleMu22_BMTF_NEG;
   Bool_t          L1_SingleMu22_BMTF_POS;
   Bool_t          L1_SingleMu22_DQ;
   Bool_t          L1_SingleMu22_EMTF;
   Bool_t          L1_SingleMu22_EMTF_NEG;
   Bool_t          L1_SingleMu22_EMTF_POS;
   Bool_t          L1_SingleMu22_OMTF;
   Bool_t          L1_SingleMu22_OMTF_NEG;
   Bool_t          L1_SingleMu22_OMTF_POS;
   Bool_t          L1_SingleMu22_OQ;
   Bool_t          L1_SingleMu25;
   Bool_t          L1_SingleMu3;
   Bool_t          L1_SingleMu5;
   Bool_t          L1_SingleMu5_SQ14_BMTF;
   Bool_t          L1_SingleMu6_SQ14_BMTF;
   Bool_t          L1_SingleMu7;
   Bool_t          L1_SingleMu7_DQ;
   Bool_t          L1_SingleMu7_SQ14_BMTF;
   Bool_t          L1_SingleMu8_SQ14_BMTF;
   Bool_t          L1_SingleMu9_SQ14_BMTF;
   Bool_t          L1_SingleMuCosmics;
   Bool_t          L1_SingleMuCosmics_BMTF;
   Bool_t          L1_SingleMuCosmics_EMTF;
   Bool_t          L1_SingleMuCosmics_OMTF;
   Bool_t          L1_SingleMuOpen;
   Bool_t          L1_SingleMuOpen_BMTF;
   Bool_t          L1_SingleMuOpen_EMTF;
   Bool_t          L1_SingleMuOpen_NotBptxOR;
   Bool_t          L1_SingleMuOpen_OMTF;
   Bool_t          L1_SingleMuOpen_er1p1_NotBptxOR_3BX;
   Bool_t          L1_SingleMuOpen_er1p4_NotBptxOR_3BX;
   Bool_t          L1_SingleMuShower_Nominal;
   Bool_t          L1_SingleMuShower_Tight;
   Bool_t          L1_SingleTau120er2p1;
   Bool_t          L1_SingleTau130er2p1;
   Bool_t          L1_TOTEM_1;
   Bool_t          L1_TOTEM_2;
   Bool_t          L1_TOTEM_3;
   Bool_t          L1_TOTEM_4;
   Bool_t          L1_TripleEG_18_17_8_er2p5;
   Bool_t          L1_TripleEG_18_18_12_er2p5;
   Bool_t          L1_TripleJet_100_80_70_DoubleJet_80_70_er2p5;
   Bool_t          L1_TripleJet_105_85_75_DoubleJet_85_75_er2p5;
   Bool_t          L1_TripleJet_95_75_65_DoubleJet_75_65_er2p5;
   Bool_t          L1_TripleMu0;
   Bool_t          L1_TripleMu0_OQ;
   Bool_t          L1_TripleMu0_SQ;
   Bool_t          L1_TripleMu3;
   Bool_t          L1_TripleMu3_SQ;
   Bool_t          L1_TripleMu_3SQ_2p5SQ_0;
   Bool_t          L1_TripleMu_3SQ_2p5SQ_0_Mass_Max12;
   Bool_t          L1_TripleMu_3SQ_2p5SQ_0_OS_Mass_Max12;
   Bool_t          L1_TripleMu_4SQ_2p5SQ_0_OS_Mass_Max12;
   Bool_t          L1_TripleMu_5SQ_3SQ_0OQ;
   Bool_t          L1_TripleMu_5SQ_3SQ_0OQ_DoubleMu_5_3_SQ_OS_Mass_Max9;
   Bool_t          L1_TripleMu_5SQ_3SQ_0_DoubleMu_5_3_SQ_OS_Mass_Max9;
   Bool_t          L1_TripleMu_5_3_3;
   Bool_t          L1_TripleMu_5_3_3_SQ;
   Bool_t          L1_TripleMu_5_3p5_2p5;
   Bool_t          L1_TripleMu_5_3p5_2p5_DoubleMu_5_2p5_OS_Mass_5to17;
   Bool_t          L1_TripleMu_5_4_2p5_DoubleMu_5_2p5_OS_Mass_5to17;
   Bool_t          L1_TripleMu_5_5_3;
   Bool_t          L1_TwoMuShower_Loose;
   Bool_t          L1_UnpairedBunchBptxMinus;
   Bool_t          L1_UnpairedBunchBptxPlus;
   Bool_t          L1_ZeroBias;
   Bool_t          L1_ZeroBias_copy;
   Bool_t          L1_UnprefireableEvent_TriggerRules;
   Bool_t          L1_UnprefireableEvent_FirstBxInTrain;
   Bool_t          L1_FinalOR_BXmin1;
   Bool_t          L1_FinalOR_BXmin2;
   Bool_t          Flag_HBHENoiseFilter;
   Bool_t          Flag_HBHENoiseIsoFilter;
   Bool_t          Flag_CSCTightHaloFilter;
   Bool_t          Flag_CSCTightHaloTrkMuUnvetoFilter;
   Bool_t          Flag_CSCTightHalo2015Filter;
   Bool_t          Flag_globalTightHalo2016Filter;
   Bool_t          Flag_globalSuperTightHalo2016Filter;
   Bool_t          Flag_HcalStripHaloFilter;
   Bool_t          Flag_hcalLaserEventFilter;
   Bool_t          Flag_EcalDeadCellTriggerPrimitiveFilter;
   Bool_t          Flag_EcalDeadCellBoundaryEnergyFilter;
   Bool_t          Flag_ecalBadCalibFilter;
   Bool_t          Flag_goodVertices;
   Bool_t          Flag_eeBadScFilter;
   Bool_t          Flag_ecalLaserCorrFilter;
   Bool_t          Flag_trkPOGFilters;
   Bool_t          Flag_chargedHadronTrackResolutionFilter;
   Bool_t          Flag_muonBadTrackFilter;
   Bool_t          Flag_BadChargedCandidateFilter;
   Bool_t          Flag_BadPFMuonFilter;
   Bool_t          Flag_BadPFMuonDzFilter;
   Bool_t          Flag_hfNoisyHitsFilter;
   Bool_t          Flag_BadChargedCandidateSummer16Filter;
   Bool_t          Flag_BadPFMuonSummer16Filter;
   Bool_t          Flag_trkPOG_manystripclus53X;
   Bool_t          Flag_trkPOG_toomanystripclus53X;
   Bool_t          Flag_trkPOG_logErrorTooManyClusters;
   Bool_t          L1Reco_step;
   Bool_t          L1simulation_step;
   Bool_t          HLTriggerFirstPath;
   Bool_t          DST_PFScouting_DoubleMuon;
   Bool_t          DST_PFScouting_DoubleEG;
   Bool_t          DST_PFScouting_JetHT;
   Bool_t          DST_PFScouting_DatasetMuon;
   Bool_t          DST_PFScouting_AXOVLoose;
   Bool_t          DST_PFScouting_AXOLoose;
   Bool_t          DST_PFScouting_AXONominal;
   Bool_t          DST_PFScouting_AXOTight;
   Bool_t          DST_PFScouting_AXOVTight;
   Bool_t          DST_PFScouting_CICADAVLoose;
   Bool_t          DST_PFScouting_CICADALoose;
   Bool_t          DST_PFScouting_CICADAMedium;
   Bool_t          DST_PFScouting_CICADATight;
   Bool_t          DST_PFScouting_CICADAVTight;
   Bool_t          DST_PFScouting_SingleMuon;
   Bool_t          DST_PFScouting_SinglePhotonEB;
   Bool_t          DST_PFScouting_ZeroBias;
*/
/*
   Bool_t          HLT_EphemeralPhysics;
   Bool_t          HLT_EphemeralZeroBias;
   Bool_t          HLT_EcalCalibration;
   Bool_t          HLT_HcalCalibration;
   Bool_t          HLT_HcalNZS;
   Bool_t          HLT_HcalPhiSym;
   Bool_t          HLT_Random;
   Bool_t          HLT_Physics;
   Bool_t          HLT_ZeroBias;
   Bool_t          HLT_ZeroBias_Alignment;
   Bool_t          HLT_ZeroBias_Beamspot;
   Bool_t          HLT_ZeroBias_IsolatedBunches;
   Bool_t          HLT_ZeroBias_FirstBXAfterTrain;
   Bool_t          HLT_ZeroBias_FirstCollisionAfterAbortGap;
   Bool_t          HLT_ZeroBias_FirstCollisionInTrain;
   Bool_t          HLT_ZeroBias_LastCollisionInTrain;
   Bool_t          HLT_HT300_Beamspot;
   Bool_t          HLT_IsoTrackHB;
   Bool_t          HLT_IsoTrackHE;
   Bool_t          HLT_PFJet40_GPUvsCPU;
	*/


	Bool_t          HLT_AK8PFJet380_SoftDropMass30;
	Bool_t          HLT_AK8PFJet400_SoftDropMass30;
	Bool_t          HLT_AK8PFJet425_SoftDropMass30;
	Bool_t          HLT_AK8PFJet450_SoftDropMass30;
	
	Bool_t          HLT_AK8DiPFJet250_250_SoftDropMass40;
	Bool_t          HLT_AK8DiPFJet250_250_SoftDropMass50;
	Bool_t          HLT_AK8DiPFJet260_260_SoftDropMass30;
	Bool_t          HLT_AK8DiPFJet260_260_SoftDropMass40;
	Bool_t          HLT_AK8DiPFJet270_270_SoftDropMass30;
	Bool_t          HLT_AK8DiPFJet280_280_SoftDropMass30;
	Bool_t          HLT_AK8DiPFJet290_290_SoftDropMass30;
	
	Bool_t          HLT_AK8PFJet500;
	Bool_t          HLT_AK8PFJet550;
	Bool_t          HLT_AK8PFJetFwd400;
	Bool_t          HLT_AK8PFJetFwd450;
	Bool_t          HLT_AK8PFJetFwd500;
	Bool_t          HLT_PFMET120_PFMHT120_IDTight;
	Bool_t          HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;
	Bool_t          HLT_PFHT500_PFMET100_PFMHT100_IDTight;
	Bool_t          HLT_PFHT500_PFMET110_PFMHT110_IDTight;
	Bool_t          HLT_PFHT700_PFMET85_PFMHT85_IDTight;
	Bool_t          HLT_PFHT800_PFMET75_PFMHT75_IDTight;
	Bool_t          HLT_PFMET130_PFMHT130_IDTight;
	Bool_t          HLT_PFMET140_PFMHT140_IDTight;
	Bool_t          HLT_PFMETTypeOne140_PFMHT140_IDTight;
	Bool_t          HLT_PFMET120_PFMHT120_IDTight_PFHT60;
	Bool_t          HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60;
	Bool_t          HLT_PFMETNoMu130_PFMHTNoMu130_IDTight;
	Bool_t          HLT_PFMETNoMu140_PFMHTNoMu140_IDTight;
	Bool_t          HLT_MET105_IsoTrk50;
	Bool_t          HLT_MET120_IsoTrk50;
	Bool_t          HLT_CaloMET350_NotCleaned;
	Bool_t          HLT_PFMET250_NotCleaned;
	Bool_t          HLT_PFMET300_NotCleaned;
	Bool_t          HLT_PFMET200_BeamHaloCleaned;
	Bool_t          HLT_PFMETTypeOne200_BeamHaloCleaned;
	Bool_t          HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_FilterHF;
	Bool_t          HLT_PFMETNoMu130_PFMHTNoMu130_IDTight_FilterHF;
	Bool_t          HLT_PFMETNoMu140_PFMHTNoMu140_IDTight_FilterHF;
	Bool_t          HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p50;
	Bool_t          HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p53;
	Bool_t          HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p55;
	Bool_t          HLT_AK8PFJet220_SoftDropMass40_PNetBB0p06_DoubleAK4PFJet60_30_PNet2BTagMean0p60;
	Bool_t          HLT_AK8PFJet230_SoftDropMass40_PNetBB0p06;
	Bool_t          HLT_AK8PFJet230_SoftDropMass40_PNetBB0p10;
	Bool_t          HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p03;
	Bool_t          HLT_AK8PFJet230_SoftDropMass40_PNetTauTau0p05;
	Bool_t          HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p03;
	Bool_t          HLT_AK8PFJet250_SoftDropMass40_PNetTauTau0p05;
	Bool_t          HLT_AK8PFJet275_SoftDropMass40_PNetBB0p06;
	Bool_t          HLT_AK8PFJet275_SoftDropMass40_PNetBB0p10;
	Bool_t          HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p03;
	Bool_t          HLT_AK8PFJet275_SoftDropMass40_PNetTauTau0p05;
	Bool_t          HLT_AK8PFJet275_Nch45;
	Bool_t          HLT_AK8PFJet275_Nch40;
	Bool_t          HLT_PFMET105_IsoTrk50;
	Bool_t          HLT_CaloJet500_NoJetID;
	Bool_t          HLT_PFJet500;
	Bool_t          HLT_DiPFJetAve300_HFJEC;
	Bool_t          HLT_CaloJet550_NoJetID;
	Bool_t HLT_PFJet550;
	Bool_t HLT_PFJetFwd400;
	Bool_t HLT_PFJetFwd450;
	Bool_t HLT_PFJetFwd500;
	Bool_t HLT_PFMET120_PFMHT120_IDTight;
	Bool_t HLT_AK8PFJet250_SoftDropMass40_PNetBB0p06;
	Bool_t HLT_AK8PFJet250_SoftDropMass40_PNetBB0p10;
	Bool_t HLT_PFHT1050;
	Bool_t HLT_DiPFJetAve260_HFJEC;
	Bool_t HLT_DiPFJetAve180_PPSMatch_Xi0p3_QuadJet_Max2ProtPerRP;
	Bool_t HLT_Mu12_DoublePFJets40MaxDeta1p6_PNet2BTag_0p11;
	Bool_t HLT_Mu12_DoublePFJets54MaxDeta1p6_PNet2BTag_0p11;
	Bool_t HLT_DoublePFJets116MaxDeta1p6_PNet2BTag_0p11;
	Bool_t HLT_DoublePFJets128MaxDeta1p6_PNet2BTag_0p11;




/*
   
   

   Bool_t          HLT_DoubleMu5_Upsilon_DoubleEle3_CaloIdL_TrackIdL;
   Bool_t          HLT_DoubleMu3_DoubleEle7p5_CaloIdL_TrackIdL_Upsilon;
   Bool_t          HLT_Trimuon5_3p5_2_Upsilon_Muon;
   Bool_t          HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon;
   Bool_t          HLT_DoubleEle25_CaloIdL_MW;
   Bool_t          HLT_DoubleEle27_CaloIdL_MW;
   Bool_t          HLT_DoubleEle33_CaloIdL_MW;
   Bool_t          HLT_DoubleEle24_eta2p1_WPTight_Gsf;
   Bool_t          HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350;
   Bool_t          HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350;
   Bool_t          HLT_Mu27_Ele37_CaloIdL_MW;
   Bool_t          HLT_Mu37_Ele27_CaloIdL_MW;
   Bool_t          HLT_Mu37_TkMu27;
   Bool_t          HLT_DoubleMu4_3_Bs;
   Bool_t          HLT_DoubleMu4_3_Jpsi;
   Bool_t          HLT_DoubleMu4_3_LowMass;
   Bool_t          HLT_DoubleMu4_LowMass_Displaced;
   Bool_t          HLT_Mu0_L1DoubleMu;
   Bool_t          HLT_Mu4_L1DoubleMu;
   Bool_t          HLT_DoubleMu2_Jpsi_LowPt;
   Bool_t          HLT_DoubleMu4_3_Photon4_BsToMMG;
   Bool_t          HLT_DoubleMu4_3_Displaced_Photon4_BsToMMG;
   Bool_t          HLT_DoubleMu3_Trk_Tau3mu;
   Bool_t          HLT_DoubleMu3_TkMu_DsTau3Mu;
   Bool_t          HLT_DoubleMu4_Mass3p8_DZ_PFHT350;
   Bool_t          HLT_DoubleMu4_MuMuTrk_Displaced;
   Bool_t          HLT_Mu3_PFJet40;
   Bool_t          HLT_Mu7p5_L2Mu2_Jpsi;
   Bool_t          HLT_Mu7p5_L2Mu2_Upsilon;
   Bool_t          HLT_Mu3_L1SingleMu5orSingleMu7;
   Bool_t          HLT_Mu0_Barrel;
   Bool_t          HLT_Mu0_Barrel_L1HP6;
   Bool_t          HLT_Mu0_Barrel_L1HP7;
   Bool_t          HLT_Mu0_Barrel_L1HP8;
   Bool_t          HLT_Mu0_Barrel_L1HP9;
   Bool_t          HLT_Mu0_Barrel_L1HP10;
   Bool_t          HLT_Mu0_Barrel_L1HP11;
   Bool_t          HLT_Mu0_Barrel_L1HP6_IP6;
   Bool_t          HLT_Mu6_Barrel_L1HP7_IP6;
   Bool_t          HLT_Mu7_Barrel_L1HP8_IP6;
   Bool_t          HLT_Mu8_Barrel_L1HP9_IP6;
   Bool_t          HLT_Mu9_Barrel_L1HP10_IP6;
   Bool_t          HLT_Mu10_Barrel_L1HP11_IP6;
   Bool_t          HLT_DoublePhoton33_CaloIdL;
   Bool_t          HLT_DoublePhoton70;
   Bool_t          HLT_DoublePhoton85;
   Bool_t          HLT_DiEle27_WPTightCaloOnly_L1DoubleEG;
   Bool_t          HLT_Ele30_WPTight_Gsf;
   Bool_t          HLT_Ele32_WPTight_Gsf;
   Bool_t          HLT_Ele35_WPTight_Gsf;
   Bool_t          HLT_Ele38_WPTight_Gsf;
   Bool_t          HLT_Ele40_WPTight_Gsf;
   Bool_t          HLT_Ele32_WPTight_Gsf_L1DoubleEG;
   Bool_t          HLT_IsoMu20;
   Bool_t          HLT_IsoMu24;
   Bool_t          HLT_IsoMu24_eta2p1;
   Bool_t          HLT_IsoMu27;
   Bool_t          HLT_UncorrectedJetE30_NoBPTX;
   Bool_t          HLT_UncorrectedJetE30_NoBPTX3BX;
   Bool_t          HLT_UncorrectedJetE60_NoBPTX3BX;
   Bool_t          HLT_UncorrectedJetE70_NoBPTX3BX;
   Bool_t          HLT_L1SingleMuCosmics;
   Bool_t          HLT_L2Mu10_NoVertex_NoBPTX3BX;
   Bool_t          HLT_L2Mu10_NoVertex_NoBPTX;
   Bool_t          HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX;
   Bool_t          HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX;
   Bool_t          HLT_L2Mu23NoVtx_2Cha;
   Bool_t          HLT_L2Mu23NoVtx_2Cha_CosmicSeed;
   Bool_t          HLT_DoubleL2Mu30NoVtx_2Cha_CosmicSeed_Eta2p4;
   Bool_t          HLT_DoubleL2Mu30NoVtx_2Cha_Eta2p4;
   Bool_t          HLT_DoubleL2Mu50;
   Bool_t          HLT_DoubleL2Mu23NoVtx_2Cha_CosmicSeed;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_CosmicSeed_Eta2p4;
   Bool_t          HLT_DoubleL2Mu23NoVtx_2Cha;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha;
   Bool_t          HLT_DoubleL2Mu25NoVtx_2Cha_Eta2p4;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_PFJet30;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_CaloJet30;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_AK8PFJet30;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_AK8CaloJet30;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8;
   Bool_t          HLT_Mu30_TkMu0_Psi;
   Bool_t          HLT_Mu30_TkMu0_Upsilon;
   Bool_t          HLT_Mu25_TkMu0_Phi;
   Bool_t          HLT_Mu15;
   Bool_t          HLT_Mu20;
   Bool_t          HLT_Mu27;
   Bool_t          HLT_Mu50;
   Bool_t          HLT_Mu55;
   Bool_t          HLT_CascadeMu100;
   Bool_t          HLT_HighPtTkMu100;
   Bool_t          HLT_DiPFJetAve40;
   Bool_t          HLT_DiPFJetAve60;
   Bool_t          HLT_DiPFJetAve80;
   Bool_t          HLT_DiPFJetAve140;
   Bool_t          HLT_DiPFJetAve200;
   Bool_t          HLT_DiPFJetAve260;
   Bool_t          HLT_DiPFJetAve320;
   Bool_t          HLT_DiPFJetAve400;
   Bool_t          HLT_DiPFJetAve500;
   Bool_t          HLT_DiPFJetAve60_HFJEC;
   Bool_t          HLT_DiPFJetAve80_HFJEC;
   Bool_t          HLT_DiPFJetAve100_HFJEC;
   Bool_t          HLT_DiPFJetAve160_HFJEC;
   Bool_t          HLT_DiPFJetAve220_HFJEC;
   Bool_t          HLT_DiPFJetAve260_HFJEC;
   ;
   Bool_t          HLT_DiPFJetAve180_PPSMatch_Xi0p3_QuadJet_Max2ProtPerRP;
*/
/*
   Bool_t          HLT_AK8PFJet40;
   Bool_t          HLT_AK8PFJet60;
   Bool_t          HLT_AK8PFJet80;
   Bool_t          HLT_AK8PFJet140;
   Bool_t          HLT_AK8PFJet200;
   Bool_t          HLT_AK8PFJet260;
   Bool_t          HLT_AK8PFJet320;
   Bool_t          HLT_AK8PFJet400;
   Bool_t          HLT_AK8PFJet450;
	*/

/*
   Bool_t          HLT_PFJet40;
   Bool_t          HLT_PFJet60;
   Bool_t          HLT_PFJet80;
   Bool_t          HLT_PFJet110;
   Bool_t          HLT_PFJet140;
   Bool_t          HLT_PFJet200;
   Bool_t          HLT_PFJet260;
   Bool_t          HLT_PFJet320;
   Bool_t          HLT_PFJet400;
   Bool_t          HLT_PFJet450;
   Bool_t          HLT_PFJetFwd40;
   Bool_t          HLT_PFJetFwd60;
   Bool_t          HLT_PFJetFwd80;
   Bool_t          HLT_PFJetFwd140;
   Bool_t          HLT_PFJetFwd200;
   Bool_t          HLT_PFJetFwd260;
   Bool_t          HLT_PFJetFwd320;
   Bool_t          HLT_PFJetFwd400;
   Bool_t          HLT_PFJetFwd450;
   Bool_t          HLT_PFJetFwd500;
   Bool_t          HLT_AK8PFJetFwd40;
   Bool_t          HLT_AK8PFJetFwd60;
   Bool_t          HLT_AK8PFJetFwd80;
   Bool_t          HLT_AK8PFJetFwd140;
   Bool_t          HLT_AK8PFJetFwd200;
   Bool_t          HLT_AK8PFJetFwd260;
   Bool_t          HLT_AK8PFJetFwd320;
   */

/*
   Bool_t          HLT_PFHT180;
   Bool_t          HLT_PFHT250;
   Bool_t          HLT_PFHT370;
   Bool_t          HLT_PFHT430;
   Bool_t          HLT_PFHT510;
   Bool_t          HLT_PFHT590;
   Bool_t          HLT_PFHT680;
   Bool_t          HLT_PFHT780;
   Bool_t          HLT_PFHT890;
   Bool_t          HLT_PFHT1050;




   
   */
	



   /*



 

   
   Bool_t          HLT_PFMETNoMu130_PFMHTNoMu130_IDTight;
   Bool_t          HLT_PFMETNoMu140_PFMHTNoMu140_IDTight;
   Bool_t          HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_FilterHF;
   
   
   
// Bool_t          HLT_L1ETMHadSeeds;
// Bool_t          HLT_CaloMHT90;
   Bool_t          HLT_CaloMET90_NotCleaned;
   Bool_t          HLT_CaloMET350_NotCleaned;
   Bool_t          HLT_PFMET200_NotCleaned;
   
   
   
   
   
   
   */
   /*
   Bool_t          HLT_Mu12eta2p3;
   Bool_t          HLT_Mu12eta2p3_PFJet40;
   Bool_t          HLT_Mu12_DoublePFJets40_PNetBTag_0p11;
   Bool_t          HLT_Mu12_DoublePFJets100_PNetBTag_0p11;
   Bool_t          HLT_Mu12_DoublePFJets200_PNetBTag_0p11;
   Bool_t          HLT_Mu12_DoublePFJets350_PNetBTag_0p11;
   Bool_t          HLT_Mu12_DoublePFJets40MaxDeta1p6_PNet2BTag_0p11;
   Bool_t          HLT_Mu12_DoublePFJets54MaxDeta1p6_PNet2BTag_0p11;
   */
/*
   Bool_t          HLT_DoublePFJets40_PNetBTag_0p11;
   Bool_t          HLT_DoublePFJets100_PNetBTag_0p11;
   Bool_t          HLT_DoublePFJets200_PNetBTag_0p11;
   Bool_t          HLT_DoublePFJets350_PNetBTag_0p11;
   Bool_t          HLT_DoublePFJets116MaxDeta1p6_PNet2BTag_0p11;
   Bool_t          HLT_DoublePFJets128MaxDeta1p6_PNet2BTag_0p11;
   //Bool_t          HLT_Photon300_NoHE;
  */
   /*
   Bool_t          HLT_Mu8_TrkIsoVVL;
   Bool_t          HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ;
   Bool_t          HLT_Mu8_DiEle12_CaloIdL_TrackIdL;
   Bool_t          HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ;
   Bool_t          HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_CaloDiJet30;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu17_TrkIsoVVL;
   Bool_t          HLT_Mu19_TrkIsoVVL;
   Bool_t          HLT_BTagMu_AK4DiJet20_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet40_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet70_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet110_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet170_Mu5;
   Bool_t          HLT_BTagMu_AK4Jet300_Mu5;
	*/   
 //  Bool_t          HLT_BTagMu_AK8DiJet170_Mu5;
 //  Bool_t          HLT_BTagMu_AK8Jet170_DoubleMu5;
 //  Bool_t          HLT_BTagMu_AK8Jet300_Mu5;
   /*
   Bool_t          HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Mu12_IsoVVL_PFHT150_PNetBTag0p53;
   Bool_t          HLT_Photon33;
   Bool_t          HLT_Photon50;
   Bool_t          HLT_Photon75;
   Bool_t          HLT_Photon90;
   Bool_t          HLT_Photon120;
   Bool_t          HLT_Photon150;
   Bool_t          HLT_Photon175;
   Bool_t          HLT_Photon200;
   Bool_t          HLT_Photon45EB;
   Bool_t          HLT_Photon40EB;
   Bool_t          HLT_Photon50EB;
   Bool_t          HLT_Photon30EB_TightID_TightIso;
   Bool_t          HLT_Photon40EB_TightID_TightIso;
   Bool_t          HLT_Photon45EB_TightID_TightIso;
   Bool_t          HLT_Photon50EB_TightID_TightIso_PFJet30;
   Bool_t          HLT_Photon50EB_TightID_TightIso_CaloJet30;
   Bool_t          HLT_Photon50EB_TightID_TightIso_AK8PFJet30;
   Bool_t          HLT_Photon50EB_TightID_TightIso_AK8CaloJet30;
   Bool_t          HLT_Photon50EB_TightID_TightIso;
   Bool_t          HLT_Photon55EB_TightID_TightIso;
   Bool_t          HLT_Photon75EB_TightID_TightIso;
   Bool_t          HLT_Photon90EB_TightID_TightIso;
   Bool_t          HLT_Photon110EB_TightID_TightIso;
   Bool_t          HLT_Photon110EB_TightID_TightIso_PFJet30;
   Bool_t          HLT_Photon110EB_TightID_TightIso_CaloJet30;
   Bool_t          HLT_Photon110EB_TightID_TightIso_AK8PFJet30;
   Bool_t          HLT_Photon110EB_TightID_TightIso_AK8CaloJet30;
   Bool_t          HLT_Photon100EBHE10;
   Bool_t          HLT_Photon50_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon90_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon120_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon165_R9Id90_HE10_IsoM;
   Bool_t          HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90;
   Bool_t          HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95;
   Bool_t          HLT_DiphotonMVA14p25_Mass90;
   Bool_t          HLT_DiphotonMVA14p25_Tight_Mass90;
   Bool_t          HLT_Photon35_TwoProngs35;
   Bool_t          HLT_IsoMu24_TwoProngs35;
   Bool_t          HLT_Dimuon0_Jpsi_L1_NoOS;
   Bool_t          HLT_Dimuon0_Jpsi_NoVertexing_NoOS;
   Bool_t          HLT_Dimuon0_Jpsi;
   Bool_t          HLT_Dimuon0_Jpsi_NoVertexing;
   Bool_t          HLT_Dimuon0_Jpsi_L1_4R_0er1p5R;
   Bool_t          HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R;
   Bool_t          HLT_Dimuon0_Jpsi3p5_Muon2;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5er2p0;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5er2p0M;
   Bool_t          HLT_Dimuon0_Upsilon_NoVertexing;
   Bool_t          HLT_Dimuon0_LowMass_L1_0er1p5;
   Bool_t          HLT_Dimuon0_LowMass;
   Bool_t          HLT_Dimuon0_LowMass_L1_4;
   Bool_t          HLT_Dimuon0_LowMass_L1_TM530;
   Bool_t          HLT_Dimuon0_Upsilon_Muon_NoL1Mass;
   Bool_t          HLT_TripleMu_5_3_3_Mass3p8_DZ;
   Bool_t          HLT_TripleMu_10_5_5_DZ;
   Bool_t          HLT_TripleMu_12_10_5;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1;
   Bool_t          HLT_DoubleMu3_DZ_PFMET50_PFMHT60;
   Bool_t          HLT_DoubleMu3_DZ_PFMET70_PFMHT70;
   Bool_t          HLT_DoubleMu3_DZ_PFMET90_PFMHT90;
   Bool_t          HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass;
   Bool_t          HLT_DoubleMu4_3_LowMass_SS;
   Bool_t          HLT_DoubleMu4_Jpsi_Displaced;
   Bool_t          HLT_DoubleMu4_Jpsi_NoVertexing;
   Bool_t          HLT_DoubleMu4_JpsiTrkTrk_Displaced;
   Bool_t          HLT_DoubleMu4_JpsiTrk_Bc;
   Bool_t          HLT_DoubleMu43NoFiltersNoVtx;
   Bool_t          HLT_DoubleMu48NoFiltersNoVtx;
   Bool_t          HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL;
   Bool_t          HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL;
   Bool_t          HLT_Mu38NoFiltersNoVtxDisplaced_Photon38_CaloIdL;
   Bool_t          HLT_Mu43NoFiltersNoVtxDisplaced_Photon43_CaloIdL;
   Bool_t          HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned;
   Bool_t          HLT_Ele28_eta2p1_WPTight_Gsf_HT150;
   Bool_t          HLT_Ele28_HighEta_SC20_Mass55;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT450_PFMET50;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT450;
   Bool_t          HLT_Ele50_IsoVVVL_PFHT450;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT600;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT450_PFMET50;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT450;
   Bool_t          HLT_Mu50_IsoVVVL_PFHT450;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT600;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMET80_PFMHT80_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMET90_PFMHT90_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMET100_PFMHT100_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu80_PFMHTNoMu80_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu90_PFMHTNoMu90_IDTight;
   Bool_t          HLT_Mu3er1p5_PFJet100er2p5_PFMETNoMu100_PFMHTNoMu100_IDTight;
   Bool_t          HLT_Dimuon10_Upsilon_y1p4;
   Bool_t          HLT_Dimuon12_Upsilon_y1p4;
   Bool_t          HLT_Dimuon14_Phi_Barrel_Seagulls;
   Bool_t          HLT_Dimuon25_Jpsi;
   Bool_t          HLT_Dimuon14_PsiPrime;
   Bool_t          HLT_Dimuon14_PsiPrime_noCorrL1;
   Bool_t          HLT_Dimuon18_PsiPrime;
   Bool_t          HLT_Dimuon18_PsiPrime_noCorrL1;
   Bool_t          HLT_Dimuon24_Upsilon_noCorrL1;
   Bool_t          HLT_Dimuon24_Phi_noCorrL1;
   Bool_t          HLT_Dimuon25_Jpsi_noCorrL1;
   Bool_t          HLT_DiMu4_Ele9_CaloIdL_TrackIdL_DZ_Mass3p8;
   Bool_t          HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ;
   Bool_t          HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
   Bool_t          HLT_DoubleIsoMu20_eta2p1;
   Bool_t          HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx;
   Bool_t          HLT_Mu8;
   Bool_t          HLT_Mu17;
   Bool_t          HLT_Mu19;
   Bool_t          HLT_Mu17_Photon30_IsoCaloId;
   Bool_t          HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele14_eta2p5_IsoVVVL_Gsf_PFHT200_PNetBTag0p53;
   Bool_t          HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele8_CaloIdM_TrackIdM_PFJet30;
   Bool_t          HLT_Ele17_CaloIdM_TrackIdM_PFJet30;
   Bool_t          HLT_Ele23_CaloIdM_TrackIdM_PFJet30;
   Bool_t          HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165;
   Bool_t          HLT_Ele115_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele135_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_PFHT330PT30_QuadPFJet_75_60_45_40;
   Bool_t          HLT_PFHT400_SixPFJet32;
   Bool_t          HLT_PFHT400_SixPFJet32_PNet2BTagMean0p50;
   Bool_t          HLT_PFHT450_SixPFJet36;
   Bool_t          HLT_PFHT450_SixPFJet36_PNetBTag0p35;
   Bool_t          HLT_PFHT400_FivePFJet_120_120_60_30_30;
   Bool_t          HLT_PFHT350;
   Bool_t          HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350;
   Bool_t          HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT380;
   Bool_t          HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT400;
   Bool_t          HLT_ECALHT800;
   Bool_t          HLT_DiSC30_18_EIso_AND_HE_Mass70;
   Bool_t          HLT_Photon20_HoverELoose;
   Bool_t          HLT_Photon30_HoverELoose;
   Bool_t          HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;
   Bool_t          HLT_CDC_L2cosmic_10_er1p0;
   Bool_t          HLT_CDC_L2cosmic_5p5_er1p0;
   Bool_t          HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;
   Bool_t          HLT_VBF_DoubleMediumDeepTauPFTauHPS20_eta2p1;
   Bool_t          HLT_Photon60_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3;
   Bool_t          HLT_Mu18_Mu9_SameSign;
   Bool_t          HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi1p05;
   Bool_t          HLT_DoubleMu3_DCA_PFMET50_PFMHT60;
   Bool_t          HLT_DoubleMu3_DCA_PFMET50_PFMHT60_Mass2p0;
   Bool_t          HLT_DoubleMu3_DCA_PFMET50_PFMHT60_Mass2p0_noDCA;
   Bool_t          HLT_TripleMu_5_3_3_Mass3p8_DCA;
   Bool_t          HLT_QuadPFJet103_88_75_15;
   Bool_t          HLT_QuadPFJet105_88_76_15;
   Bool_t          HLT_QuadPFJet111_90_80_15;
   Bool_t          HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId;
   Bool_t          HLT_Diphoton30_18_R9IdL_AND_HE_AND_IsoCaloId_Mass55;
   Bool_t          HLT_DoubleMediumDeepTauPFTauHPS35_L2NN_eta2p1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_LooseDeepTauPFTauHPS30_eta2p1_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_PNetTauhPFJet30_Tight_eta2p3_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_PNetTauhPFJet30_Medium_eta2p3_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_PNetTauhPFJet30_Loose_eta2p3_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_LooseDeepTauPFTauHPS27_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_LooseDeepTauPFTauHPS180_eta2p1;
   Bool_t          HLT_IsoMu24_eta2p1_LooseDeepTauPFTauHPS30_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumDeepTauPFTauHPS35_L2NN_eta2p1_CrossL1;
   Bool_t          HLT_LooseDeepTauPFTauHPS180_L2NN_eta2p1;
   Bool_t          HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepJet_4p5;
   Bool_t          HLT_PFHT330PT30_QuadPFJet_75_60_45_40_PNet3BTag_4p3;
   Bool_t          HLT_PFHT330PT30_QuadPFJet_75_60_45_40_PNet3BTag_2p0;
   Bool_t          HLT_PFHT400_FivePFJet_120_120_60_30_30_PNet2BTag_5p6;
   Bool_t          HLT_PFHT400_FivePFJet_120_120_60_30_30_PNet2BTag_4p3;
   Bool_t          HLT_QuadPFJet103_88_75_15_PNetBTag_0p4_VBF2;
   Bool_t          HLT_QuadPFJet103_88_75_15_PNet2BTag_0p4_0p12_VBF1;
   Bool_t          HLT_QuadPFJet105_88_76_15_PNetBTag_0p4_VBF2;
   Bool_t          HLT_QuadPFJet105_88_76_15_PNet2BTag_0p4_0p12_VBF1;
   Bool_t          HLT_QuadPFJet111_90_80_15_PNetBTag_0p4_VBF2;
   Bool_t          HLT_QuadPFJet111_90_80_15_PNet2BTag_0p4_0p12_VBF1;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PFBtagDeepJet_1p5;
   Bool_t          HLT_PFHT250_QuadPFJet25;
   Bool_t          HLT_PFHT250_QuadPFJet25_PNet2BTagMean0p55;
   Bool_t          HLT_PFHT250_QuadPFJet25_PNet1BTag0p20_PNet1Tauh0p50;
   Bool_t          HLT_PFHT250_QuadPFJet30_PNet2BTagMean0p55;
   Bool_t          HLT_PFHT250_QuadPFJet30_PNet1BTag0p20_PNet1Tauh0p50;
   Bool_t          HLT_PFHT280_QuadPFJet30_PNet1BTag0p20_PNet1Tauh0p50;
   Bool_t          HLT_PFHT280_QuadPFJet30;
   Bool_t          HLT_PFHT280_QuadPFJet30_PNet2BTagMean0p55;
   Bool_t          HLT_PFHT280_QuadPFJet30_PNet2BTagMean0p60;
   Bool_t          HLT_PFHT280_QuadPFJet35_PNet2BTagMean0p60;
   Bool_t          HLT_PFHT340_QuadPFJet70_50_40_40_PNet2BTagMean0p70;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFHT280;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFHT280_QuadPFJet30;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFHT280_QuadPFJet30_PNet2BTagMean0p55;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFDiJet30_PNet2BTagMean0p50;
   Bool_t          HLT_QuadPFJet100_88_70_30;
   Bool_t          HLT_QuadPFJet105_88_75_30;
   Bool_t          HLT_QuadPFJet111_90_80_30;
   Bool_t          HLT_QuadPFJet100_88_70_30_PNet1CvsAll0p5_VBF3Tight;
   Bool_t          HLT_QuadPFJet105_88_75_30_PNet1CvsAll0p5_VBF3Tight;
   Bool_t          HLT_QuadPFJet111_90_80_30_PNet1CvsAll0p6_VBF3Tight;
   */

/*
   Bool_t          HLT_AK8PFJet220_SoftDropMass40;
   
   

   Bool_t          HLT_AK8PFJet230_SoftDropMass40;
  */
   /*
   Bool_t          HLT_IsoMu50_AK8PFJet220_SoftDropMass40;
   Bool_t          HLT_IsoMu50_AK8PFJet220_SoftDropMass40_PNetBB0p06;
   Bool_t          HLT_IsoMu50_AK8PFJet230_SoftDropMass40;
   Bool_t          HLT_IsoMu50_AK8PFJet230_SoftDropMass40_PNetBB0p06;
   Bool_t          HLT_IsoMu50_AK8PFJet230_SoftDropMass40_PNetBB0p10;
   Bool_t          HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet220_SoftDropMass40;
   Bool_t          HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet220_SoftDropMass40_PNetBB0p06;
   Bool_t          HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40;
   Bool_t          HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40_PNetBB0p06;
   Bool_t          HLT_Ele50_CaloIdVT_GsfTrkIdT_AK8PFJet230_SoftDropMass40_PNetBB0p10;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_DoubleAK4PFJet60_30;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_DoubleAK4PFJet60_30_PNet2BTagMean0p50;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFHT250;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFHT250_QuadPFJet25;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFHT250_QuadPFJet25_PNet2BTagMean0p55;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_PFHT250_QuadPFJet25_PNet1BTag0p20;
   Bool_t          HLT_DoubleMediumDeepTauPFTauHPS30_L2NN_eta2p1_PFJet60;
   Bool_t          HLT_DoubleMediumDeepTauPFTauHPS30_L2NN_eta2p1_PFJet75;
   Bool_t          HLT_IsoMu24_eta2p1_MediumDeepTauPFTauHPS30_L2NN_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumDeepTauPFTauHPS30_L2NN_eta2p1_PFJet60_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumDeepTauPFTauHPS30_L2NN_eta2p1_PFJet75_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumDeepTauPFTauHPS20_eta2p1_SingleL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumDeepTauPFTauHPS45_L2NN_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet30_Medium_L2NN_eta2p3_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet30_Tight_L2NN_eta2p3_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet26_L2NN_eta2p3_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet26_L2NN_eta2p3_CrossL1_PFJet60;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet26_L2NN_eta2p3_CrossL1_PFJet75;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet30_Tight_eta2p3_CrossL1_ETau_Monitoring;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet30_Medium_eta2p3_CrossL1_ETau_Monitoring;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet30_Loose_eta2p3_CrossL1_ETau_Monitoring;
   Bool_t          HLT_IsoMu20_eta2p1_PNetTauhPFJet27_Tight_eta2p3_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_PNetTauhPFJet27_Medium_eta2p3_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_PNetTauhPFJet27_Loose_eta2p3_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet20_eta2p2_SingleL1;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet45_L2NN_eta2p3_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_PFHT250;
   Bool_t          HLT_IsoMu24_eta2p1_PFHT250_QuadPFJet25;
   Bool_t          HLT_IsoMu24_eta2p1_PFHT250_QuadPFJet25_PNet1Tauh0p50;
   Bool_t          HLT_IsoMu24_eta2p1_SinglePFJet25_PNet1Tauh0p50;
   Bool_t          HLT_DoublePNetTauhPFJet30_Medium_L2NN_eta2p3;
   Bool_t          HLT_DoublePNetTauhPFJet30_Tight_L2NN_eta2p3;
   Bool_t          HLT_DoublePNetTauhPFJet26_L2NN_eta2p3_PFJet60;
   Bool_t          HLT_DoublePNetTauhPFJet26_L2NN_eta2p3_PFJet75;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet130_Loose_L2NN_eta2p3_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet130_Medium_L2NN_eta2p3_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_PNetTauhPFJet130_Tight_L2NN_eta2p3_CrossL1;
   Bool_t          HLT_SinglePNetTauhPFJet130_Loose_L2NN_eta2p3;
   Bool_t          HLT_SinglePNetTauhPFJet130_Medium_L2NN_eta2p3;
   Bool_t          HLT_SinglePNetTauhPFJet130_Tight_L2NN_eta2p3;
   Bool_t          HLT_DoubleL2Mu10NoVtx_2Cha_VetoL3Mu0DxyMax1cm;
   Bool_t          HLT_DoubleL2Mu12NoVtx_2Cha_VetoL3Mu0DxyMax1cm;
   Bool_t          HLT_DoubleL2Mu14NoVtx_2Cha_VetoL3Mu0DxyMax1cm;
   Bool_t          HLT_DoubleL3Mu16_10NoVtx_DxyMin0p01cm;
   Bool_t          HLT_DoubleL3Mu18_10NoVtx_DxyMin0p01cm;
   Bool_t          HLT_DoubleL3Mu20_10NoVtx_DxyMin0p01cm;
   Bool_t          HLT_L2Mu10NoVtx_2Cha;
   Bool_t          HLT_L2Mu10NoVtx_2Cha_VetoL3Mu0DxyMax1cm;
   Bool_t          HLT_L3Mu10NoVtx;
   Bool_t          HLT_L3Mu10NoVtx_DxyMin0p01cm;
   Bool_t          HLT_DoubleL2Mu_L3Mu16NoVtx_VetoL3Mu0DxyMax0p1cm;
   Bool_t          HLT_DoubleL2Mu_L3Mu18NoVtx_VetoL3Mu0DxyMax0p1cm;
   Bool_t          HLT_DoubleL2Mu10NoVtx_2Cha_CosmicSeed_VetoL3Mu0DxyMax1cm;
   Bool_t          HLT_DoubleL2Mu12NoVtx_2Cha_CosmicSeed_VetoL3Mu0DxyMax1cm;
   Bool_t          HLT_L2Mu10NoVtx_2Cha_CosmicSeed;
   Bool_t          HLT_L2Mu10NoVtx_2Cha_CosmicSeed_VetoL3Mu0DxyMax1cm;
   Bool_t          HLT_DoubleL3dTksMu16_10NoVtx_DxyMin0p01cm;
   Bool_t          HLT_L2Mu50NoVtx_3Cha_CosmicSeed_VetoL3Mu0DxyMax1cm;
   Bool_t          HLT_L2Mu50NoVtx_3Cha_VetoL3Mu0DxyMax1cm;
   Bool_t          HLT_L3Mu30NoVtx_DxyMin0p01cm;
   Bool_t          HLT_L3Mu50NoVtx_DxyMin0p01cm;
   Bool_t          HLT_L3dTksMu10_NoVtx_DxyMin0p01cm;
   Bool_t          HLT_Mu20NoFiltersNoVtxDisplaced_Photon20_CaloCustomId;
   Bool_t          HLT_DisplacedMu24_MediumChargedIsoDisplacedPFTauHPS24;
   Bool_t          HLT_Photon34_R9Id90_CaloIdL_IsoL_DisplacedIdL_MediumChargedIsoDisplacedPFTauHPS34;
   Bool_t          HLT_DoubleMediumChargedIsoDisplacedPFTauHPS32_Trk1_eta2p1;
   Bool_t          HLT_DoubleMediumChargedIsoDisplacedPFTauHPS36_Trk1_eta2p1;
   Bool_t          HLT_DoubleMediumChargedIsoDisplacedPFTauHPS32_Trk1_eta2p1_noDxy;
   Bool_t          HLT_IsoMu27_MediumChargedIsoDisplacedPFTauHPS24_eta2p1_SingleL1;
   Bool_t          HLT_HT350_DelayedJet40_SingleDelay1p5To3p5nsInclusive;
   Bool_t          HLT_HT350_DelayedJet40_SingleDelay1p6To3p5nsInclusive;
   Bool_t          HLT_HT350_DelayedJet40_SingleDelay1p75To3p5nsInclusive;
   Bool_t          HLT_HT350_DelayedJet40_SingleDelay3nsInclusive;
   Bool_t          HLT_HT350_DelayedJet40_SingleDelay3p25nsInclusive;
   Bool_t          HLT_HT350_DelayedJet40_SingleDelay3p5nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay0p5nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay1nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay1To1p5nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay1p1To1p6nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay1p25To1p75nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay1p5nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay2nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay2p25nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay2p5nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay0p5nsTrackless;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay1nsTrackless;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay1p25nsTrackless;
   Bool_t          HLT_HT430_DelayedJet40_SingleDelay1p5nsTrackless;
   Bool_t          HLT_HT430_DelayedJet40_DoubleDelay0p5nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_DoubleDelay1nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_DoubleDelay1p25nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_DoubleDelay1p5nsInclusive;
   Bool_t          HLT_HT430_DelayedJet40_DoubleDelay0p5nsTrackless;
   Bool_t          HLT_HT430_DelayedJet40_DoubleDelay0p75nsTrackless;
   Bool_t          HLT_HT430_DelayedJet40_DoubleDelay1nsTrackless;
   Bool_t          HLT_L1Tau_DelayedJet40_SingleDelay2p5To4nsInclusive;
   Bool_t          HLT_L1Tau_DelayedJet40_SingleDelay2p6To4nsInclusive;
   Bool_t          HLT_L1Tau_DelayedJet40_SingleDelay2p75To4nsInclusive;
   Bool_t          HLT_L1Tau_DelayedJet40_SingleDelay3p5nsInclusive;
   Bool_t          HLT_L1Tau_DelayedJet40_SingleDelay3p75nsInclusive;
   Bool_t          HLT_L1Tau_DelayedJet40_SingleDelay4nsInclusive;
   Bool_t          HLT_L1Tau_DelayedJet40_SingleDelay2p5nsTrackless;
   Bool_t          HLT_L1Tau_DelayedJet40_SingleDelay2p75nsTrackless;
   Bool_t          HLT_L1Tau_DelayedJet40_SingleDelay3nsTrackless;
   Bool_t          HLT_L1Tau_DelayedJet40_DoubleDelay0p75nsInclusive;
   Bool_t          HLT_L1Tau_DelayedJet40_DoubleDelay1p25nsInclusive;
   Bool_t          HLT_L1Tau_DelayedJet40_DoubleDelay1p5nsInclusive;
   Bool_t          HLT_L1Tau_DelayedJet40_DoubleDelay1p75nsInclusive;
   Bool_t          HLT_L1Tau_DelayedJet40_DoubleDelay0p5nsTrackless;
   Bool_t          HLT_L1Tau_DelayedJet40_DoubleDelay1nsTrackless;
   Bool_t          HLT_L1Tau_DelayedJet40_DoubleDelay1p25nsTrackless;
   Bool_t          HLT_L1Tau_DelayedJet40_DoubleDelay1p5nsTrackless;
   Bool_t          HLT_L1Mu6HT240;
   Bool_t          HLT_Mu6HT240_DisplacedDijet30_Inclusive1PtrkShortSig5_DisplacedLoose;
   Bool_t          HLT_Mu6HT240_DisplacedDijet35_Inclusive0PtrkShortSig5;
   Bool_t          HLT_Mu6HT240_DisplacedDijet35_Inclusive1PtrkShortSig5_DisplacedLoose;
   Bool_t          HLT_Mu6HT240_DisplacedDijet40_Inclusive0PtrkShortSig5;
   Bool_t          HLT_Mu6HT240_DisplacedDijet40_Inclusive1PtrkShortSig5_DisplacedLoose;
   Bool_t          HLT_Mu6HT240_DisplacedDijet45_Inclusive0PtrkShortSig5;
   Bool_t          HLT_Mu6HT240_DisplacedDijet50_Inclusive0PtrkShortSig5;
   Bool_t          HLT_HT350;
   Bool_t          HLT_HT425;
   Bool_t          HLT_HT360_DisplacedDijet40_Inclusive1PtrkShortSig5;
   Bool_t          HLT_HT360_DisplacedDijet45_Inclusive1PtrkShortSig5;
   Bool_t          HLT_HT390_DisplacedDijet40_Inclusive1PtrkShortSig5;
   Bool_t          HLT_HT390_DisplacedDijet45_Inclusive1PtrkShortSig5;
   Bool_t          HLT_HT390eta2p0_DisplacedDijet40_Inclusive1PtrkShortSig5;
   Bool_t          HLT_HT430_DisplacedDijet40_Inclusive1PtrkShortSig5;
   Bool_t          HLT_HT400_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT430_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT550_DisplacedDijet60_Inclusive;
   Bool_t          HLT_HT650_DisplacedDijet60_Inclusive;
   Bool_t          HLT_CaloMET60_DTCluster50;
   Bool_t          HLT_CaloMET60_DTClusterNoMB1S50;
   Bool_t          HLT_L1MET_DTCluster50;
   Bool_t          HLT_L1MET_DTClusterNoMB1S50;
   Bool_t          HLT_CscCluster_Loose;
   Bool_t          HLT_CscCluster_Medium;
   Bool_t          HLT_CscCluster_Tight;
   Bool_t          HLT_CscCluster50_Photon20Unseeded;
   Bool_t          HLT_CscCluster50_Photon30Unseeded;
   Bool_t          HLT_CscCluster100_Ele5;
   Bool_t          HLT_CscCluster100_Mu5;
   Bool_t          HLT_CscCluster100_PNetTauhPFJet10_Loose;
   Bool_t          HLT_DoubleCscCluster75;
   Bool_t          HLT_IsoTrk200_L1SingleMuShower;
   Bool_t          HLT_IsoTrk400_L1SingleMuShower;
   Bool_t          HLT_DoubleCscCluster100;
   Bool_t          HLT_L1CSCShower_DTCluster50;
   Bool_t          HLT_L1CSCShower_DTCluster75;
   
   Bool_t          HLT_L1SingleLLPJet;
   Bool_t          HLT_HT170_L1SingleLLPJet_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT200_L1SingleLLPJet_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT200_L1SingleLLPJet_DisplacedDijet60_DisplacedTrack;
   Bool_t          HLT_HT270_L1SingleLLPJet_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT200_L1SingleLLPJet_DisplacedDijet40_Inclusive1PtrkShortSig5;
   Bool_t          HLT_HT240_L1SingleLLPJet_DisplacedDijet40_Inclusive1PtrkShortSig5;
   Bool_t          HLT_HT280_L1SingleLLPJet_DisplacedDijet40_Inclusive1PtrkShortSig5;
   Bool_t          HLT_HT320_L1SingleLLPJet_DisplacedDijet60_Inclusive;
   Bool_t          HLT_HT420_L1SingleLLPJet_DisplacedDijet60_Inclusive;
   Bool_t          HLT_HT200_L1SingleLLPJet_DelayedJet40_SingleDelay1nsTrackless;
   Bool_t          HLT_HT200_L1SingleLLPJet_DelayedJet40_SingleDelay2nsInclusive;
   Bool_t          HLT_HT200_L1SingleLLPJet_DelayedJet40_DoubleDelay0p5nsTrackless;
   Bool_t          HLT_HT200_L1SingleLLPJet_DelayedJet40_DoubleDelay1nsInclusive;
   Bool_t          HLT_HT200_L1SingleLLPJet_PFJet60_NeutralHadronFrac0p7;
   Bool_t          HLT_HT200_L1SingleLLPJet_PFJet60_NeutralHadronFrac0p8;
   Bool_t          HLT_DiPhoton10Time1ns;
   Bool_t          HLT_DiPhoton10Time1p2ns;
   Bool_t          HLT_DiPhoton10Time1p4ns;
   Bool_t          HLT_DiPhoton10Time1p6ns;
   Bool_t          HLT_DiPhoton10Time1p8ns;
   Bool_t          HLT_DiPhoton10Time2ns;
   Bool_t          HLT_DiPhoton10_CaloIdL;
   Bool_t          HLT_DoubleEle6p5_eta1p22_mMax6;
   Bool_t          HLT_DoubleEle8_eta1p22_mMax6;
   Bool_t          HLT_DoubleEle10_eta1p22_mMax6;
   Bool_t          HLT_SingleEle8;
   Bool_t          HLT_SingleEle8_SingleEGL1;
   Bool_t          HLT_Diphoton20_14_eta1p5_R9IdL_AND_HE_AND_IsoTCaloIdT;
   Bool_t          HLT_Diphoton20_14_eta1p5_R9IdL_AND_HET_AND_IsoTCaloIdT;
   Bool_t          HLT_Diphoton22_14_eta1p5_R9IdL_AND_HE_AND_IsoTCaloIdT;
   Bool_t          HLT_Diphoton22_14_eta1p5_R9IdL_AND_HET_AND_IsoTCaloIdT;
   Bool_t          HLT_Diphoton24_14_eta1p5_R9IdL_AND_HET_AND_IsoTCaloIdT;
   Bool_t          HLT_Diphoton24_16_eta1p5_R9IdL_AND_HET_AND_IsoTCaloIdT;
   Bool_t          HLT_Mu50_L1SingleMuShower;
   Bool_t          HLT_IsoMu24_OneProng32;
   Bool_t          HLT_Photon32_OneProng32_M50To105;
   Bool_t          HLT_DoubleMediumDeepTauPFTauHPS30_L2NN_eta2p1_OneProng;
   Bool_t          HLT_IsoMu24_eta2p1_MediumDeepTauPFTauHPS30_L2NN_eta2p1_OneProng_CrossL1;
   Bool_t          HLT_VBF_DiPFJet125_45_Mjj1050;
   Bool_t          HLT_VBF_DiPFJet125_45_Mjj1200;
   Bool_t          HLT_VBF_DiPFJet75_45_Mjj800_DiPFJet60;
   Bool_t          HLT_VBF_DiPFJet75_45_Mjj850_DiPFJet60;
   Bool_t          HLT_VBF_DiPFJet80_45_Mjj650_PFMETNoMu85;
   Bool_t          HLT_VBF_DiPFJet80_45_Mjj750_PFMETNoMu85;
   Bool_t          HLT_VBF_DiPFJet95_45_Mjj750_Mu3_TrkIsoVVL;
   Bool_t          HLT_VBF_DiPFJet95_45_Mjj850_Mu3_TrkIsoVVL;
   Bool_t          HLT_VBF_DiPFJet50_Mjj650_Photon22;
   Bool_t          HLT_VBF_DiPFJet50_Mjj750_Photon22;
   Bool_t          HLT_VBF_DiPFJet50_Mjj600_Ele22_eta2p1_WPTight_Gsf;
   Bool_t          HLT_VBF_DiPFJet50_Mjj650_Ele22_eta2p1_WPTight_Gsf;
   Bool_t          HLT_VBF_DiPFJet45_Mjj650_MediumDeepTauPFTauHPS45_L2NN_eta2p1;
   Bool_t          HLT_VBF_DiPFJet45_Mjj750_MediumDeepTauPFTauHPS45_L2NN_eta2p1;
   Bool_t          HLT_VBF_DoublePNetTauhPFJet20_eta2p2;
   Bool_t          HLT_VBF_DiPFJet45_Mjj650_PNetTauhPFJet45_L2NN_eta2p3;
   Bool_t          HLT_VBF_DiPFJet45_Mjj750_PNetTauhPFJet45_L2NN_eta2p3;
   Bool_t          HLT_PFJet200_TimeLtNeg2p5ns;
   Bool_t          HLT_PFJet200_TimeGt2p5ns;
   Bool_t          HLT_Photon50_TimeLtNeg2p5ns;
   Bool_t          HLT_Photon50_TimeGt2p5ns;
   Bool_t          HLT_PPSMaxTracksPerArm1;
   Bool_t          HLT_PPSMaxTracksPerRP4;
   Bool_t          HLT_PPSRandom;
   Bool_t          MC_PFScouting;
   Bool_t          HLT_L1AXOVTight;
*/
//   Bool_t          HLTriggerFinalPath;
//   Bool_t          Dataset_ScoutingPFMonitor;
//   Bool_t          Dataset_ScoutingPFRun3;

        
        
};

#endif





