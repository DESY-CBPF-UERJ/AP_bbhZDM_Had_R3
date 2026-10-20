#include "HEPHero.h"

// Stores reconstruction and generator-level variables for comparing chi45 and chi100 signals.
// Object selections are applied, but no event-level baseline cut rejects an event.
namespace Test_diff_SignalSamples_chi45_vs_chi100 {

    constexpr float missing = -999.0f;

    int trigger_pass;
    int met_filters_pass;
    int Nleptons_value;
    int Nelectrons_value;
    int Nmuons_value;
    int Njets_value;
    int Nbjets_value;
    int NfatJets_value;

    float MET_pt;
    float MHT_value;
    float OmegaMin_value;
    float LeadingFatJet_msoftdrop;

    float LeadingMuon_pt;
    float LeadingMuon_eta;
    float LeadingMuon_phi;
    float LeadingElectron_pt;
    float LeadingElectron_eta;
    float LeadingElectron_phi;
    float LeadingJet_pt;
    float LeadingJet_eta;
    float LeadingJet_phi;
    float LeadingBJet_pt;
    float LeadingBJet_eta;
    float LeadingBJet_phi;
    float LeadingFatJet_pt;
    float LeadingFatJet_eta;
    float LeadingFatJet_phi;

    int GEN_A_found;
    int GEN_H_found;
    int GEN_a_found;
    float GEN_A_pt;
    float GEN_A_eta;
    float GEN_A_phi;
    float GEN_H_pt;
    float GEN_H_eta;
    float GEN_H_phi;
    float GEN_a_pt;
    float GEN_a_eta;
    float GEN_a_phi;
}


void HEPHero::SetupTest_diff_SignalSamples_chi45_vs_chi100() {

    HDF_insert("trigger_pass", &Test_diff_SignalSamples_chi45_vs_chi100::trigger_pass);
    HDF_insert("met_filters_pass", &Test_diff_SignalSamples_chi45_vs_chi100::met_filters_pass);
    HDF_insert("Nleptons", &Test_diff_SignalSamples_chi45_vs_chi100::Nleptons_value);
    HDF_insert("Nelectrons", &Test_diff_SignalSamples_chi45_vs_chi100::Nelectrons_value);
    HDF_insert("Nmuons", &Test_diff_SignalSamples_chi45_vs_chi100::Nmuons_value);
    HDF_insert("Njets", &Test_diff_SignalSamples_chi45_vs_chi100::Njets_value);
    HDF_insert("Nbjets", &Test_diff_SignalSamples_chi45_vs_chi100::Nbjets_value);
    HDF_insert("NfatJets", &Test_diff_SignalSamples_chi45_vs_chi100::NfatJets_value);

    HDF_insert("MET_pt", &Test_diff_SignalSamples_chi45_vs_chi100::MET_pt);
    HDF_insert("MHT", &Test_diff_SignalSamples_chi45_vs_chi100::MHT_value);
    HDF_insert("OmegaMin", &Test_diff_SignalSamples_chi45_vs_chi100::OmegaMin_value);
    HDF_insert("LeadingFatJet_msoftdrop", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingFatJet_msoftdrop);

    HDF_insert("LeadingMuon_pt", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingMuon_pt);
    HDF_insert("LeadingMuon_eta", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingMuon_eta);
    HDF_insert("LeadingMuon_phi", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingMuon_phi);
    HDF_insert("LeadingElectron_pt", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingElectron_pt);
    HDF_insert("LeadingElectron_eta", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingElectron_eta);
    HDF_insert("LeadingElectron_phi", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingElectron_phi);
    HDF_insert("LeadingJet_pt", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingJet_pt);
    HDF_insert("LeadingJet_eta", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingJet_eta);
    HDF_insert("LeadingJet_phi", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingJet_phi);
    HDF_insert("LeadingBJet_pt", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingBJet_pt);
    HDF_insert("LeadingBJet_eta", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingBJet_eta);
    HDF_insert("LeadingBJet_phi", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingBJet_phi);
    HDF_insert("LeadingFatJet_pt", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingFatJet_pt);
    HDF_insert("LeadingFatJet_eta", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingFatJet_eta);
    HDF_insert("LeadingFatJet_phi", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingFatJet_phi);

    HDF_insert("GEN_A_found", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_A_found);
    HDF_insert("GEN_H_found", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_H_found);
    HDF_insert("GEN_a_found", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_a_found);
    HDF_insert("GEN_A_pt", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_A_pt);
    HDF_insert("GEN_A_eta", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_A_eta);
    HDF_insert("GEN_A_phi", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_A_phi);
    HDF_insert("GEN_H_pt", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_H_pt);
    HDF_insert("GEN_H_eta", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_H_eta);
    HDF_insert("GEN_H_phi", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_H_phi);
    HDF_insert("GEN_a_pt", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_a_pt);
    HDF_insert("GEN_a_eta", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_a_eta);
    HDF_insert("GEN_a_phi", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_a_phi);
}


bool HEPHero::Test_diff_SignalSamples_chi45_vs_chi100Region() {

    using namespace Test_diff_SignalSamples_chi45_vs_chi100;

    trigger_pass = Trigger() ? 1 : 0;
    met_filters_pass = METFilters() ? 1 : 0;

    LeptonSelection();
    FatjetSelection();
    JetSelection();
    Get_Jet_Angular_Variables();

    Nleptons_value = Nleptons;
    Nelectrons_value = Nelectrons;
    Nmuons_value = Nmuons;
    Njets_value = Njets;
    Nbjets_value = Nbjets;
    NfatJets_value = NfatJets;
    MET_pt = PFMET_pt;
    MHT_value = MHT;
    OmegaMin_value = OmegaMin;

    LeadingMuon_pt = missing;
    LeadingMuon_eta = missing;
    LeadingMuon_phi = missing;
    LeadingElectron_pt = missing;
    LeadingElectron_eta = missing;
    LeadingElectron_phi = missing;
    LeadingJet_pt = missing;
    LeadingJet_eta = missing;
    LeadingJet_phi = missing;
    LeadingBJet_pt = missing;
    LeadingBJet_eta = missing;
    LeadingBJet_phi = missing;
    LeadingFatJet_pt = missing;
    LeadingFatJet_eta = missing;
    LeadingFatJet_phi = missing;
    LeadingFatJet_msoftdrop = missing;

    for (const int index : selectedMu) {
        if (LeadingMuon_pt == missing || Muon_pt[index] > LeadingMuon_pt) {
            LeadingMuon_pt = Muon_pt[index];
            LeadingMuon_eta = Muon_eta[index];
            LeadingMuon_phi = Muon_phi[index];
        }
    }

    for (const int index : selectedEle) {
        if (LeadingElectron_pt == missing || Electron_pt[index] > LeadingElectron_pt) {
            LeadingElectron_pt = Electron_pt[index];
            LeadingElectron_eta = Electron_eta[index];
            LeadingElectron_phi = Electron_phi[index];
        }
    }

    for (const int index : selectedJet) {
        if (LeadingJet_pt == missing || Jet_pt[index] > LeadingJet_pt) {
            LeadingJet_pt = Jet_pt[index];
            LeadingJet_eta = Jet_eta[index];
            LeadingJet_phi = Jet_phi[index];
        }

        if (JetBTAG(index, JET_BTAG_WP) &&
            (LeadingBJet_pt == missing || Jet_pt[index] > LeadingBJet_pt)) {
            LeadingBJet_pt = Jet_pt[index];
            LeadingBJet_eta = Jet_eta[index];
            LeadingBJet_phi = Jet_phi[index];
        }
    }

    for (const int index : selectedFatJet) {
        if (LeadingFatJet_pt == missing || FatJet_pt[index] > LeadingFatJet_pt) {
            LeadingFatJet_pt = FatJet_pt[index];
            LeadingFatJet_eta = FatJet_eta[index];
            LeadingFatJet_phi = FatJet_phi[index];
            LeadingFatJet_msoftdrop = FatJet_msoftdrop[index];
        }
    }

    GEN_A_found = 0;
    GEN_H_found = 0;
    GEN_a_found = 0;
    GEN_A_pt = missing;
    GEN_A_eta = missing;
    GEN_A_phi = missing;
    GEN_H_pt = missing;
    GEN_H_eta = missing;
    GEN_H_phi = missing;
    GEN_a_pt = missing;
    GEN_a_eta = missing;
    GEN_a_phi = missing;

    bool gen_A_is_last_copy = false;
    bool gen_H_is_last_copy = false;
    bool gen_a_is_last_copy = false;

    for (unsigned int index = 0; index < nGenPart; ++index) {
        const int abs_pdg_id = std::abs(GenPart_pdgId[index]);
        const bool is_last_copy = (GenPart_statusFlags[index] & (1 << 13)) != 0;

        if (abs_pdg_id == 36 &&
            (!GEN_A_found || (is_last_copy && !gen_A_is_last_copy) ||
             (is_last_copy == gen_A_is_last_copy && GenPart_pt[index] > GEN_A_pt))) {
            GEN_A_found = 1;
            gen_A_is_last_copy = is_last_copy;
            GEN_A_pt = GenPart_pt[index];
            GEN_A_eta = GenPart_eta[index];
            GEN_A_phi = GenPart_phi[index];
        }

        if (abs_pdg_id == 35 &&
            (!GEN_H_found || (is_last_copy && !gen_H_is_last_copy) ||
             (is_last_copy == gen_H_is_last_copy && GenPart_pt[index] > GEN_H_pt))) {
            GEN_H_found = 1;
            gen_H_is_last_copy = is_last_copy;
            GEN_H_pt = GenPart_pt[index];
            GEN_H_eta = GenPart_eta[index];
            GEN_H_phi = GenPart_phi[index];
        }

        if ((abs_pdg_id == 54 || abs_pdg_id == 55) &&
            (!GEN_a_found || (is_last_copy && !gen_a_is_last_copy) ||
             (is_last_copy == gen_a_is_last_copy && GenPart_pt[index] > GEN_a_pt))) {
            GEN_a_found = 1;
            gen_a_is_last_copy = is_last_copy;
            GEN_a_pt = GenPart_pt[index];
            GEN_a_eta = GenPart_eta[index];
            GEN_a_phi = GenPart_phi[index];
        }
    }

    Weight_corrections();
    return true;
}


void HEPHero::Test_diff_SignalSamples_chi45_vs_chi100Selection() {
    HDF_fill();
}


void HEPHero::Test_diff_SignalSamples_chi45_vs_chi100Systematic() {}


void HEPHero::FinishTest_diff_SignalSamples_chi45_vs_chi100() {}
