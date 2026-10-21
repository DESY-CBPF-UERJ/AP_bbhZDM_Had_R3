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
    float LeadingFatJet_msoftdrop_value;

    float LeadingMuon_pt;
    float LeadingMuon_eta;
    float LeadingMuon_phi;
    float LeadingElectron_pt;
    float LeadingElectron_eta;
    float LeadingElectron_phi;
    float LeadingJet_pt_value;
    float LeadingJet_eta;
    float LeadingJet_phi;
    float LeadingBJet_pt;
    float LeadingBJet_eta;
    float LeadingBJet_phi;
    float LeadingFatJet_pt_value;
    float LeadingFatJet_eta;
    float LeadingFatJet_phi;

    int GEN_A_found;
    int GEN_H_found;
    int GEN_a_found;
    int GEN_Z_found;
    int GEN_hSM_found;
    int GEN_chi_found;
    int GEN_chibar_found;
    float GEN_A_pt;
    float GEN_A_eta;
    float GEN_A_phi;
    float GEN_A_mass;
    float GEN_H_pt;
    float GEN_H_eta;
    float GEN_H_phi;
    float GEN_H_mass;
    float GEN_a_pt;
    float GEN_a_eta;
    float GEN_a_phi;
    float GEN_a_mass;
    float GEN_Z_pt;
    float GEN_Z_eta;
    float GEN_Z_phi;
    float GEN_Z_mass;
    float GEN_hSM_pt;
    float GEN_hSM_eta;
    float GEN_hSM_phi;
    float GEN_hSM_mass;
    float GEN_chi_pt;
    float GEN_chi_eta;
    float GEN_chi_phi;
    float GEN_chi_mass;
    float GEN_chibar_pt;
    float GEN_chibar_eta;
    float GEN_chibar_phi;
    float GEN_chibar_mass;
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
    HDF_insert("LeadingFatJet_msoftdrop", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingFatJet_msoftdrop_value);

    HDF_insert("LeadingMuon_pt", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingMuon_pt);
    HDF_insert("LeadingMuon_eta", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingMuon_eta);
    HDF_insert("LeadingMuon_phi", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingMuon_phi);
    HDF_insert("LeadingElectron_pt", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingElectron_pt);
    HDF_insert("LeadingElectron_eta", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingElectron_eta);
    HDF_insert("LeadingElectron_phi", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingElectron_phi);
    HDF_insert("LeadingJet_pt", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingJet_pt_value);
    HDF_insert("LeadingJet_eta", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingJet_eta);
    HDF_insert("LeadingJet_phi", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingJet_phi);
    HDF_insert("LeadingBJet_pt", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingBJet_pt);
    HDF_insert("LeadingBJet_eta", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingBJet_eta);
    HDF_insert("LeadingBJet_phi", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingBJet_phi);
    HDF_insert("LeadingFatJet_pt", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingFatJet_pt_value);
    HDF_insert("LeadingFatJet_eta", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingFatJet_eta);
    HDF_insert("LeadingFatJet_phi", &Test_diff_SignalSamples_chi45_vs_chi100::LeadingFatJet_phi);

    HDF_insert("GEN_A_found", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_A_found);
    HDF_insert("GEN_H_found", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_H_found);
    HDF_insert("GEN_a_found", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_a_found);
    HDF_insert("GEN_Z_found", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_Z_found);
    HDF_insert("GEN_hSM_found", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_hSM_found);
    HDF_insert("GEN_chi_found", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_chi_found);
    HDF_insert("GEN_chibar_found", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_chibar_found);
    HDF_insert("GEN_A_pt", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_A_pt);
    HDF_insert("GEN_A_eta", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_A_eta);
    HDF_insert("GEN_A_phi", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_A_phi);
    HDF_insert("GEN_A_mass", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_A_mass);
    HDF_insert("GEN_H_pt", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_H_pt);
    HDF_insert("GEN_H_eta", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_H_eta);
    HDF_insert("GEN_H_phi", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_H_phi);
    HDF_insert("GEN_H_mass", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_H_mass);
    HDF_insert("GEN_a_pt", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_a_pt);
    HDF_insert("GEN_a_eta", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_a_eta);
    HDF_insert("GEN_a_phi", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_a_phi);
    HDF_insert("GEN_a_mass", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_a_mass);
    HDF_insert("GEN_Z_pt", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_Z_pt);
    HDF_insert("GEN_Z_eta", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_Z_eta);
    HDF_insert("GEN_Z_phi", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_Z_phi);
    HDF_insert("GEN_Z_mass", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_Z_mass);
    HDF_insert("GEN_hSM_pt", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_hSM_pt);
    HDF_insert("GEN_hSM_eta", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_hSM_eta);
    HDF_insert("GEN_hSM_phi", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_hSM_phi);
    HDF_insert("GEN_hSM_mass", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_hSM_mass);
    HDF_insert("GEN_chi_pt", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_chi_pt);
    HDF_insert("GEN_chi_eta", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_chi_eta);
    HDF_insert("GEN_chi_phi", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_chi_phi);
    HDF_insert("GEN_chi_mass", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_chi_mass);
    HDF_insert("GEN_chibar_pt", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_chibar_pt);
    HDF_insert("GEN_chibar_eta", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_chibar_eta);
    HDF_insert("GEN_chibar_phi", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_chibar_phi);
    HDF_insert("GEN_chibar_mass", &Test_diff_SignalSamples_chi45_vs_chi100::GEN_chibar_mass);
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
    LeadingJet_pt_value = missing;
    LeadingJet_eta = missing;
    LeadingJet_phi = missing;
    LeadingBJet_pt = missing;
    LeadingBJet_eta = missing;
    LeadingBJet_phi = missing;
    LeadingFatJet_pt_value = missing;
    LeadingFatJet_eta = missing;
    LeadingFatJet_phi = missing;
    LeadingFatJet_msoftdrop_value = missing;

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
        if (LeadingJet_pt_value == missing || Jet_pt[index] > LeadingJet_pt_value) {
            LeadingJet_pt_value = Jet_pt[index];
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
        if (LeadingFatJet_pt_value == missing || FatJet_pt[index] > LeadingFatJet_pt_value) {
            LeadingFatJet_pt_value = FatJet_pt[index];
            LeadingFatJet_eta = FatJet_eta[index];
            LeadingFatJet_phi = FatJet_phi[index];
            LeadingFatJet_msoftdrop_value = FatJet_msoftdrop[index];
        }
    }

    GEN_A_found = 0;
    GEN_H_found = 0;
    GEN_a_found = 0;
    GEN_Z_found = 0;
    GEN_hSM_found = 0;
    GEN_chi_found = 0;
    GEN_chibar_found = 0;
    GEN_A_pt = missing;
    GEN_A_eta = missing;
    GEN_A_phi = missing;
    GEN_A_mass = missing;
    GEN_H_pt = missing;
    GEN_H_eta = missing;
    GEN_H_phi = missing;
    GEN_H_mass = missing;
    GEN_a_pt = missing;
    GEN_a_eta = missing;
    GEN_a_phi = missing;
    GEN_a_mass = missing;
    GEN_Z_pt = missing;
    GEN_Z_eta = missing;
    GEN_Z_phi = missing;
    GEN_Z_mass = missing;
    GEN_hSM_pt = missing;
    GEN_hSM_eta = missing;
    GEN_hSM_phi = missing;
    GEN_hSM_mass = missing;
    GEN_chi_pt = missing;
    GEN_chi_eta = missing;
    GEN_chi_phi = missing;
    GEN_chi_mass = missing;
    GEN_chibar_pt = missing;
    GEN_chibar_eta = missing;
    GEN_chibar_phi = missing;
    GEN_chibar_mass = missing;

    bool gen_A_is_last_copy = false;
    bool gen_H_is_last_copy = false;
    bool gen_a_is_last_copy = false;
    bool gen_Z_is_last_copy = false;
    bool gen_hSM_is_last_copy = false;
    bool gen_chi_is_last_copy = false;
    bool gen_chibar_is_last_copy = false;

    const auto has_ancestor = [&](unsigned int particle_index, int ancestor_pdg_id) {
        int mother_index = GenPart_genPartIdxMother[particle_index];
        unsigned int depth = 0;
        while (mother_index >= 0 && mother_index < static_cast<int>(nGenPart) && depth < nGenPart) {
            if (std::abs(GenPart_pdgId[mother_index]) == ancestor_pdg_id) return true;
            const int next_mother = GenPart_genPartIdxMother[mother_index];
            if (next_mother == mother_index) break;
            mother_index = next_mother;
            ++depth;
        }
        return false;
    };

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
            GEN_A_mass = GenPart_mass[index];
        }

        if (abs_pdg_id == 35 &&
            (!GEN_H_found || (is_last_copy && !gen_H_is_last_copy) ||
             (is_last_copy == gen_H_is_last_copy && GenPart_pt[index] > GEN_H_pt))) {
            GEN_H_found = 1;
            gen_H_is_last_copy = is_last_copy;
            GEN_H_pt = GenPart_pt[index];
            GEN_H_eta = GenPart_eta[index];
            GEN_H_phi = GenPart_phi[index];
            GEN_H_mass = GenPart_mass[index];
        }

        if ((abs_pdg_id == 54 || abs_pdg_id == 55) &&
            (!GEN_a_found || (is_last_copy && !gen_a_is_last_copy) ||
             (is_last_copy == gen_a_is_last_copy && GenPart_pt[index] > GEN_a_pt))) {
            GEN_a_found = 1;
            gen_a_is_last_copy = is_last_copy;
            GEN_a_pt = GenPart_pt[index];
            GEN_a_eta = GenPart_eta[index];
            GEN_a_phi = GenPart_phi[index];
            GEN_a_mass = GenPart_mass[index];
        }

        // H (PDG 35) -> Z + a. Follow the ancestry so the last Z copy is retained.
        if (abs_pdg_id == 23 && has_ancestor(index, 35) &&
            (!GEN_Z_found || (is_last_copy && !gen_Z_is_last_copy) ||
             (is_last_copy == gen_Z_is_last_copy && GenPart_pt[index] > GEN_Z_pt))) {
            GEN_Z_found = 1;
            gen_Z_is_last_copy = is_last_copy;
            GEN_Z_pt = GenPart_pt[index];
            GEN_Z_eta = GenPart_eta[index];
            GEN_Z_phi = GenPart_phi[index];
            GEN_Z_mass = GenPart_mass[index];
        }

        // A (PDG 36) -> h(SM, PDG 25) + a. Follow copies through the ancestry chain.
        if (abs_pdg_id == 25 && has_ancestor(index, 36) &&
            (!GEN_hSM_found || (is_last_copy && !gen_hSM_is_last_copy) ||
             (is_last_copy == gen_hSM_is_last_copy && GenPart_pt[index] > GEN_hSM_pt))) {
            GEN_hSM_found = 1;
            gen_hSM_is_last_copy = is_last_copy;
            GEN_hSM_pt = GenPart_pt[index];
            GEN_hSM_eta = GenPart_eta[index];
            GEN_hSM_phi = GenPart_phi[index];
            GEN_hSM_mass = GenPart_mass[index];
        }

        const bool from_pseudoscalar = has_ancestor(index, 54) || has_ancestor(index, 55);

        // Dark matter particle chi (PDG +52), descending from the pseudoscalar a.
        if (GenPart_pdgId[index] == 52 && from_pseudoscalar &&
            (!GEN_chi_found || (is_last_copy && !gen_chi_is_last_copy) ||
             (is_last_copy == gen_chi_is_last_copy && GenPart_pt[index] > GEN_chi_pt))) {
            GEN_chi_found = 1;
            gen_chi_is_last_copy = is_last_copy;
            GEN_chi_pt = GenPart_pt[index];
            GEN_chi_eta = GenPart_eta[index];
            GEN_chi_phi = GenPart_phi[index];
            GEN_chi_mass = GenPart_mass[index];
        }

        // Dark matter antiparticle chibar (PDG -52), descending from the pseudoscalar a.
        if (GenPart_pdgId[index] == -52 && from_pseudoscalar &&
            (!GEN_chibar_found || (is_last_copy && !gen_chibar_is_last_copy) ||
             (is_last_copy == gen_chibar_is_last_copy && GenPart_pt[index] > GEN_chibar_pt))) {
            GEN_chibar_found = 1;
            gen_chibar_is_last_copy = is_last_copy;
            GEN_chibar_pt = GenPart_pt[index];
            GEN_chibar_eta = GenPart_eta[index];
            GEN_chibar_phi = GenPart_phi[index];
            GEN_chibar_mass = GenPart_mass[index];
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
