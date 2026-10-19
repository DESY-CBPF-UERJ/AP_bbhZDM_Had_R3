#include "HEPHero.h"

void HEPHero::SetupTest_SF_btag() {

    _cutFlow.insert(pair<string,double>("00_trigger", 0));
    _cutFlow.insert(pair<string,double>("01_METFilter", 0));
    _cutFlow.insert(pair<string,double>("02_NLeptons_g_0", 0));
    _cutFlow.insert(pair<string,double>("03_NbJets_g_0", 0));
    _cutFlow.insert(pair<string,double>("04_MET_MHT_g_200", 0));
    _cutFlow.insert(pair<string,double>("05_NFatJets_g_0", 0));
    _cutFlow.insert(pair<string,double>("06_FatJet_Pt_g_200", 0));
    _cutFlow.insert(pair<string,double>("07_Omega_g_0p3", 0));
    _cutFlow.insert(pair<string,double>("08_Signal_like", 0));

    HDF_insert("Njets", &Njets);
    HDF_insert("Nbjets", &Nbjets);
    HDF_insert("btag_wgt", &btag_wgt);
}

bool HEPHero::Test_SF_btagRegion() {

    if (!Trigger()) return false;
    _cutFlow.at("00_trigger") += evtWeight;

    // METFilters is disabled in the current base selection.
    _cutFlow.at("01_METFilter") += evtWeight;

    LeptonSelection();
    if (Nleptons != 0) return false;
    _cutFlow.at("02_NLeptons_g_0") += evtWeight;

    JetSelection();
    if (Nbjets <= 0) return false;
    _cutFlow.at("03_NbJets_g_0") += evtWeight;

    if (!(PFMET_pt > 200 && MHT > 200)) return false;
    _cutFlow.at("04_MET_MHT_g_200") += evtWeight;

    FatjetSelection();
    if (NfatJets <= 0) return false;
    _cutFlow.at("05_NFatJets_g_0") += evtWeight;

    if (LeadingFatJet_pt <= 200) return false;
    _cutFlow.at("06_FatJet_Pt_g_200") += evtWeight;

    Get_Jet_Angular_Variables();
    if (OmegaMin <= OMEGA_CUT) return false;
    _cutFlow.at("07_Omega_g_0p3") += evtWeight;

    Get_Jet_Shape_Variables();
    Get_Signal_Taggers();
    Get_Signal_Taggers_Run3();
    if (signal_tag <= 0.8) return false;
    _cutFlow.at("08_Signal_like") += evtWeight;

    if (!lumi_certificate.GoodLumiSection(_datasetName, run, luminosityBlock)) return false;

    Weight_corrections();
    if (dataset_group != "Data" && !apply_btag_wgt) {
        btag_wgt = GetBTagWeight();
    }
    return true;
}

void HEPHero::Test_SF_btagSelection() {
    HDF_fill();
}

void HEPHero::Test_SF_btagSystematic() {}

void HEPHero::FinishTest_SF_btag() {}
