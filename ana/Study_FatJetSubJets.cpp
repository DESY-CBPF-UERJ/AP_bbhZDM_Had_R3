#include "HEPHero.h"

#include <algorithm>
#include <cmath>
#include <vector>

namespace Study_FatJetSubJets {
    int fatJet_idx;
    int nMatchedSubJets;
    int subJet1_idx;
    int subJet2_idx;
    float fatJet_pt;
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

namespace {
float deltaR(float eta1, float phi1, float eta2, float phi2) {
    const float dEta = eta1 - eta2;
    const float dPhi = std::atan2(std::sin(phi1 - phi2), std::cos(phi1 - phi2));
    return std::sqrt(dEta*dEta + dPhi*dPhi);
}
}

void HEPHero::SetupStudy_FatJetSubJets() {
    HDF_insert("fatJet_idx", &Study_FatJetSubJets::fatJet_idx);
    HDF_insert("fatJet_pt", &Study_FatJetSubJets::fatJet_pt);
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
    Study_FatJetSubJets::fatJet_idx = -1;
    Study_FatJetSubJets::fatJet_pt = -1.f;
    Study_FatJetSubJets::nMatchedSubJets = 0;
    Study_FatJetSubJets::subJet1_idx = -1;
    Study_FatJetSubJets::subJet2_idx = -1;
    Study_FatJetSubJets::subJet1_pt = -1.f;
    Study_FatJetSubJets::subJet2_pt = -1.f;
    Study_FatJetSubJets::deltaR_subJets = -1.f;

    std::vector<int> matchedSubJets;
    if (!selectedFatJet.empty()) {
        Study_FatJetSubJets::fatJet_idx = selectedFatJet.at(0);
        Study_FatJetSubJets::fatJet_pt = FatJet_pt[Study_FatJetSubJets::fatJet_idx];
        for (int i = 0; i < nSubJet; ++i) {
            if (deltaR(FatJet_eta[Study_FatJetSubJets::fatJet_idx],
                       FatJet_phi[Study_FatJetSubJets::fatJet_idx],
                       SubJet_eta[i], SubJet_phi[i]) < 0.8f) {
                matchedSubJets.push_back(i);
            }
        }
    }
    std::sort(matchedSubJets.begin(), matchedSubJets.end(), [this](int a, int b) {
        return SubJet_pt[a] > SubJet_pt[b];
    });

    Study_FatJetSubJets::nMatchedSubJets = static_cast<int>(matchedSubJets.size());
    if (!matchedSubJets.empty()) {
        Study_FatJetSubJets::subJet1_idx = matchedSubJets[0];
        Study_FatJetSubJets::subJet1_pt = SubJet_pt[matchedSubJets[0]];
    }
    if (matchedSubJets.size() >= 2) {
        Study_FatJetSubJets::subJet2_idx = matchedSubJets[1];
        Study_FatJetSubJets::subJet2_pt = SubJet_pt[matchedSubJets[1]];
        Study_FatJetSubJets::deltaR_subJets = deltaR(
            SubJet_eta[matchedSubJets[0]], SubJet_phi[matchedSubJets[0]],
            SubJet_eta[matchedSubJets[1]], SubJet_phi[matchedSubJets[1]]);
    }

    Weight_corrections();
    HDF_fill();
}

void HEPHero::Study_FatJetSubJetsSystematic() {
}

void HEPHero::FinishStudy_FatJetSubJets() {
}
