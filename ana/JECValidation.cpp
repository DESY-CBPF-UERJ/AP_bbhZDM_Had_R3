#include "HEPHero.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace JECValidation {

std::unique_ptr<jetmet::AK4JEC> evaluator;
std::vector<float> pt_stored;
std::vector<float> pt_rejec;
std::vector<float> mass_stored;
std::vector<float> mass_rejec;
std::vector<float> eta;
std::vector<float> phi;
std::vector<float> raw_factor;
std::vector<float> area;
std::vector<float> factor_stored_raw;
std::vector<float> factor_rejec_raw;
std::vector<float> pt_ratio;
std::vector<float> pt_delta;
bool evaluated = true;
bool has_pfmet = false;
bool has_puppimet = false;
float pfmet_pt = std::numeric_limits<float>::quiet_NaN();
float pfmet_phi = std::numeric_limits<float>::quiet_NaN();
float puppimet_pt = std::numeric_limits<float>::quiet_NaN();
float puppimet_phi = std::numeric_limits<float>::quiet_NaN();
unsigned long long events = 0;
unsigned long long jets = 0;

} // namespace JECValidation

void HEPHero::SetupJECValidation() {
    using namespace JECValidation;

    if (dataset_year != "24" || dataset_group == "Data")
        throw std::runtime_error("JECValidation requires 2024 MC");
    if (apply_ak4_jec)
        throw std::runtime_error(
            "JECValidation requires AK4_JEC_CORR=0 to preserve stored NanoAOD jets");
    if (jet_jerc_file.empty())
        throw std::runtime_error("JECValidation requires jet_jerc metadata");

    evaluator.reset(new jetmet::AK4JEC(jet_jerc_file));
    events = jets = 0;

    has_pfmet = _inputTree->GetBranch("PFMET_pt") && _inputTree->GetBranch("PFMET_phi");
    has_puppimet = _inputTree->GetBranch("PuppiMET_pt") && _inputTree->GetBranch("PuppiMET_phi");

    _outputTree->Branch("run", &run);
    _outputTree->Branch("luminosityBlock", &luminosityBlock);
    _outputTree->Branch("event", &event);
    _outputTree->Branch("nJet", &nJet);
    _outputTree->Branch("Jet_pt_stored", &pt_stored);
    _outputTree->Branch("Jet_pt_rejec", &pt_rejec);
    _outputTree->Branch("Jet_mass_stored", &mass_stored);
    _outputTree->Branch("Jet_mass_rejec", &mass_rejec);
    _outputTree->Branch("Jet_eta", &eta);
    _outputTree->Branch("Jet_phi", &phi);
    _outputTree->Branch("Jet_rawFactor", &raw_factor);
    _outputTree->Branch("Jet_area", &area);
    _outputTree->Branch("Jet_factor_stored_raw", &factor_stored_raw);
    _outputTree->Branch("Jet_factor_rejec_raw", &factor_rejec_raw);
    _outputTree->Branch("Jet_pt_ratio_rejec_over_stored", &pt_ratio);
    _outputTree->Branch("Jet_pt_delta_rejec_minus_stored", &pt_delta);
    _outputTree->Branch("JEC_evaluated", &evaluated);
    _outputTree->Branch("PFMET_pt", &pfmet_pt);
    _outputTree->Branch("PFMET_phi", &pfmet_phi);
    _outputTree->Branch("PuppiMET_pt", &puppimet_pt);
    _outputTree->Branch("PuppiMET_phi", &puppimet_phi);

    makeHist("JEC_pt_ratio", 100, 0.8, 1.2,
             "p_{T}^{re-JEC}/p_{T}^{stored}", "Jets");
    makeHist("JEC_pt_delta", 120, -60., 60.,
             "p_{T}^{re-JEC}-p_{T}^{stored} [GeV]", "Jets");
    makeHist("JEC_pt_ratio_vs_eta", 52, -5.2, 5.2, 100, 0.8, 1.2,
             "#eta", "p_{T}^{re-JEC}/p_{T}^{stored}", "Jets", "COLZ");
    makeHist("JEC_pt_rejec_vs_stored", 100, 0., 500., 100, 0., 500.,
             "p_{T}^{stored} [GeV]", "p_{T}^{re-JEC} [GeV]", "Jets", "COLZ");

    std::cout << "JECValidation: comparing stored jets with "
              << jetmet::AK4JEC::key() << std::endl;
}

bool HEPHero::JECValidationRegion() {
    return true;
}

void HEPHero::JECValidationSelection() {
    using namespace JECValidation;

    if (nJet < 0 || nJet > 100)
        throw std::runtime_error("JECValidation: nJet exceeds framework capacity");

    pt_stored.clear();
    pt_rejec.clear();
    mass_stored.clear();
    mass_rejec.clear();
    eta.clear();
    phi.clear();
    raw_factor.clear();
    area.clear();
    factor_stored_raw.clear();
    factor_rejec_raw.clear();
    pt_ratio.clear();
    pt_delta.clear();

    for (int ijet = 0; ijet < nJet; ++ijet) {
        const auto corrected = evaluator->correct(
            Jet_pt[ijet], Jet_mass[ijet], Jet_rawFactor[ijet], Jet_eta[ijet],
            Jet_phi[ijet], Jet_area[ijet], ak4_jec_rho);
        const float ratio = corrected.pt / Jet_pt[ijet];
        const float delta = corrected.pt - Jet_pt[ijet];

        pt_stored.push_back(Jet_pt[ijet]);
        pt_rejec.push_back(corrected.pt);
        mass_stored.push_back(Jet_mass[ijet]);
        mass_rejec.push_back(corrected.mass);
        eta.push_back(Jet_eta[ijet]);
        phi.push_back(Jet_phi[ijet]);
        raw_factor.push_back(Jet_rawFactor[ijet]);
        area.push_back(Jet_area[ijet]);
        factor_stored_raw.push_back(1.f / (1.f - Jet_rawFactor[ijet]));
        factor_rejec_raw.push_back(corrected.factor);
        pt_ratio.push_back(ratio);
        pt_delta.push_back(delta);

        _histograms1D.at("JEC_pt_ratio").Fill(ratio);
        _histograms1D.at("JEC_pt_delta").Fill(delta);
        _histograms2D.at("JEC_pt_ratio_vs_eta").Fill(Jet_eta[ijet], ratio);
        _histograms2D.at("JEC_pt_rejec_vs_stored").Fill(Jet_pt[ijet], corrected.pt);
    }

    pfmet_pt = has_pfmet ? PFMET_pt : std::numeric_limits<float>::quiet_NaN();
    pfmet_phi = has_pfmet ? PFMET_phi : std::numeric_limits<float>::quiet_NaN();
    puppimet_pt = has_puppimet ? PuppiMET_pt : std::numeric_limits<float>::quiet_NaN();
    puppimet_phi = has_puppimet ? PuppiMET_phi : std::numeric_limits<float>::quiet_NaN();

    _outputTree->Fill();
    ++events;
    jets += nJet;
}

void HEPHero::JECValidationSystematic() {
}

void HEPHero::FinishJECValidation() {
    std::cout << "JECValidation saved_events=" << JECValidation::events
              << " saved_jets=" << JECValidation::jets << std::endl;
}
