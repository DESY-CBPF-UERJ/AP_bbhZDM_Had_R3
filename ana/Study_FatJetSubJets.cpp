#include "HEPHero.h"

namespace Study_FatJetSubJets {
    int fatJet_idx;
    int nMatchedSubJets;
    int subJet1_idx;
    int subJet2_idx;
    float fatJet_pt;
    float fatJet_msoftdrop;
    float fatJet_deltaM_Z;
    float subJet1_pt;
    float subJet2_pt;
    float deltaR_subJets;

    int cut_trigger;
    int cut_METFilter;
    int cut_NLeptons_eq_0;
    int cut_NbJets_gt_0;
    int cut_MET_MHT_gt_200;
    int cut_NFatJets_gt_0;
    int cut_FatJet_pt_gt_200;
    int cut_Omega_gt_0p3;
    int cut_good_lumi;
}

void HEPHero::SetupStudy_FatJetSubJets() {
    HDF_insert("fatJet_idx", &Study_FatJetSubJets::fatJet_idx);
    HDF_insert("fatJet_pt", &Study_FatJetSubJets::fatJet_pt);
    HDF_insert("fatJet_msoftdrop", &Study_FatJetSubJets::fatJet_msoftdrop);
    HDF_insert("fatJet_deltaM_Z", &Study_FatJetSubJets::fatJet_deltaM_Z);
    HDF_insert("nMatchedSubJets", &Study_FatJetSubJets::nMatchedSubJets);
    HDF_insert("subJet1_idx", &Study_FatJetSubJets::subJet1_idx);
    HDF_insert("subJet1_pt", &Study_FatJetSubJets::subJet1_pt);
    HDF_insert("subJet2_idx", &Study_FatJetSubJets::subJet2_idx);
    HDF_insert("subJet2_pt", &Study_FatJetSubJets::subJet2_pt);
    HDF_insert("deltaR_subJets", &Study_FatJetSubJets::deltaR_subJets);

    HDF_insert("cut_trigger", &Study_FatJetSubJets::cut_trigger);
    HDF_insert("cut_METFilter", &Study_FatJetSubJets::cut_METFilter);
    HDF_insert("cut_NLeptons_eq_0", &Study_FatJetSubJets::cut_NLeptons_eq_0);
    HDF_insert("cut_NbJets_gt_0", &Study_FatJetSubJets::cut_NbJets_gt_0);
    HDF_insert("cut_MET_MHT_gt_200", &Study_FatJetSubJets::cut_MET_MHT_gt_200);
    HDF_insert("cut_NFatJets_gt_0", &Study_FatJetSubJets::cut_NFatJets_gt_0);
    HDF_insert("cut_FatJet_pt_gt_200", &Study_FatJetSubJets::cut_FatJet_pt_gt_200);
    HDF_insert("cut_Omega_gt_0p3", &Study_FatJetSubJets::cut_Omega_gt_0p3);
    HDF_insert("cut_good_lumi", &Study_FatJetSubJets::cut_good_lumi);
}

bool HEPHero::Study_FatJetSubJetsRegion() {
    Study_FatJetSubJets::cut_trigger = Trigger();

    Study_FatJetSubJets::cut_METFilter = METFilters();

    LeptonSelection();
    Study_FatJetSubJets::cut_NLeptons_eq_0 = (Nleptons == 0);

    JetSelection();
    Study_FatJetSubJets::cut_NbJets_gt_0 = (Nbjets > 0);

    Study_FatJetSubJets::cut_MET_MHT_gt_200 = (PFMET_pt > 200 && MHT > 200);

    FatjetSelection();
    Study_FatJetSubJets::cut_NFatJets_gt_0 = (NfatJets > 0);

    Study_FatJetSubJets::cut_FatJet_pt_gt_200 = (LeadingFatJet_pt > 200);

    Study_FatJetSubJets::cut_Omega_gt_0p3 = 0;
    if (Njets > 0) {
        Get_Jet_Angular_Variables();
        Study_FatJetSubJets::cut_Omega_gt_0p3 = (OmegaMin > OMEGA_CUT);
    }

    Study_FatJetSubJets::cut_good_lumi =
        lumi_certificate.GoodLumiSection(_datasetName, run, luminosityBlock);

    return true;
}

void HEPHero::Study_FatJetSubJetsSelection() {
    Study_FatJetSubJets::fatJet_idx = idxFatJetClosestToZ;
    Study_FatJetSubJets::fatJet_pt = FatJetClosestToZ_pt;
    Study_FatJetSubJets::fatJet_msoftdrop = FatJetClosestToZ_msoftdrop;
    Study_FatJetSubJets::fatJet_deltaM_Z = FatJetClosestToZ_deltaM_Z;
    Study_FatJetSubJets::nMatchedSubJets = this->nMatchedSubJets;
    Study_FatJetSubJets::subJet1_idx = this->subJet1_idx;
    Study_FatJetSubJets::subJet2_idx = this->subJet2_idx;
    Study_FatJetSubJets::subJet1_pt = this->subJet1_pt;
    Study_FatJetSubJets::subJet2_pt = this->subJet2_pt;
    Study_FatJetSubJets::deltaR_subJets = this->deltaR_subJets;

    Weight_corrections();
    HDF_fill();
}

void HEPHero::Study_FatJetSubJetsSystematic() {
}

void HEPHero::FinishStudy_FatJetSubJets() {
}
