#ifndef AP_BBHZDM_AK4JEC_H
#define AP_BBHZDM_AK4JEC_H

#include <string>
#include <cmath>
#include <stdexcept>
#include "correction.h"

namespace jetmet {

// This first implementation deliberately leaves data, private signals and other years unchanged.
inline bool applyAK4JECTo(bool requested, const std::string& year,
                         const std::string& group) {
    return requested && year == "24" && group != "Data" && group != "Signal";
}

struct CorrectedJet {
    double pt;
    double mass;
    double factor; // JEC relative to the raw jet, not to the stored NanoAOD jet.
};

class AK4JEC {
public:
    static const char* key() {
        return "Summer24Prompt24_V5_MC_L1L2L3Res_AK4PFPuppi";
    }

    explicit AK4JEC(const std::string& file)
        : set_(correction::CorrectionSet::from_file(file)),
          nominal_(set_->compound().at(key())) {}

    CorrectedJet correct(double pt, double mass, double rawFactor, double eta,
                         double phi, double area, double rho) const {
        for (double value : {pt, mass, rawFactor, eta, phi, area, rho}) {
            if (!std::isfinite(value))
                throw std::invalid_argument("AK4 JEC requires finite jet inputs");
        }
        if (pt <= 0.0 || mass < 0.0 || rawFactor >= 1.0 || area < 0.0 || rho < 0.0)
            throw std::invalid_argument("AK4 JEC: invalid pt, mass, rawFactor, area or rho");
        const double raw = 1.0 - rawFactor;
        const double factor = nominal_->evaluate({area, eta, pt * raw, rho, phi});
        const double correctedPt = pt * raw * factor;
        const double correctedMass = mass * raw * factor;
        if (!std::isfinite(factor) || factor <= 0.0 ||
            !std::isfinite(correctedPt) || !std::isfinite(correctedMass))
            throw std::runtime_error("AK4 JEC returned a nonphysical correction");
        return {correctedPt, correctedMass, factor};
    }

private:
    std::unique_ptr<correction::CorrectionSet> set_;
    correction::CompoundCorrection::Ref nominal_;
};

} // namespace jetmet
#endif
