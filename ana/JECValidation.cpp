#include "HEPHero.h"
#include <iostream>
#include <memory>
#include <stdexcept>

namespace JECValidation {

std::unique_ptr<jetmet::AK4JEC> evaluator;
float pt_stored = 0.f;
float pt_rejec = 0.f;
float mass_stored = 0.f;
float mass_rejec = 0.f;
float eta = 0.f;
float phi = 0.f;
float pt_ratio = 0.f;
float pt_delta = 0.f;

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
    HDF_insert("Jet_pt_stored", &pt_stored);
    HDF_insert("Jet_pt_rejec", &pt_rejec);
    HDF_insert("Jet_mass_stored", &mass_stored);
    HDF_insert("Jet_mass_rejec", &mass_rejec);
    HDF_insert("Jet_eta", &eta);
    HDF_insert("Jet_phi", &phi);
    HDF_insert("Jet_pt_ratio_rejec_over_stored", &pt_ratio);
    HDF_insert("Jet_pt_delta_rejec_minus_stored", &pt_delta);

    std::cout << "JECValidation: comparing stored jets with "
              << jetmet::AK4JEC::key() << std::endl;
}

bool HEPHero::JECValidationRegion() {
    return true;
}

void HEPHero::JECValidationSelection() {
    using namespace JECValidation;

    if (nJet > 100)
        throw std::runtime_error("JECValidation: nJet exceeds framework capacity");
    if (nJet == 0)
        return;

    unsigned int leading = 0;
    for (unsigned int ijet = 1; ijet < nJet; ++ijet)
        if (Jet_pt[ijet] > Jet_pt[leading])
            leading = ijet;

    const auto corrected = evaluator->correct(
        Jet_pt[leading], Jet_mass[leading], Jet_rawFactor[leading],
        Jet_eta[leading], Jet_phi[leading], Jet_area[leading], ak4_jec_rho);

    pt_stored = Jet_pt[leading];
    pt_rejec = corrected.pt;
    mass_stored = Jet_mass[leading];
    mass_rejec = corrected.mass;
    eta = Jet_eta[leading];
    phi = Jet_phi[leading];
    pt_ratio = corrected.pt / Jet_pt[leading];
    pt_delta = corrected.pt - Jet_pt[leading];

    HDF_fill();
}

void HEPHero::JECValidationSystematic() {
}

void HEPHero::FinishJECValidation() {
}
