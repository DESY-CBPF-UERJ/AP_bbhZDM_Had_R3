#include "AK4JEC.h"
#include <cassert>
#include <iostream>
#include <cmath>
#include <fstream>
#include <limits>

int main(int argc, char** argv) {
    using jetmet::applyAK4JECTo;
    assert(applyAK4JECTo(true, "24", "TT"));
    assert(applyAK4JECTo(true, "24", "QCD"));
    assert(!applyAK4JECTo(false, "24", "TT"));
    assert(!applyAK4JECTo(true, "24", "Data"));
    assert(!applyAK4JECTo(true, "24", "Signal"));
    assert(!applyAK4JECTo(true, "23", "TT"));
    assert(argc == 2 || argc == 3);
    jetmet::AK4JEC jec(argv[1]);
    auto referenceSet = correction::CorrectionSet::from_file(argv[1]);
    auto reference = referenceSet->compound().at(jetmet::AK4JEC::key());
    for (double eta : {-3.1, -1.2, 0.0, 1.2, 3.1}) {
        for (double rawFactor : {-0.1, 0.0, 0.2}) {
            const double pt = 100.0, mass = 12.0, phi = 0.5, area = 0.5, rho = 30.0;
            const double raw = 1.0 - rawFactor;
            const double factor = reference->evaluate({area, eta, pt * raw, rho, phi});
            const auto result = jec.correct(pt, mass, rawFactor, eta, phi, area, rho);
            assert(std::abs(result.pt - pt * raw * factor) < 1e-9);
            assert(std::abs(result.mass - mass * raw * factor) < 1e-9);
            assert(std::abs(result.factor - factor) < 1e-12);
        }
    }
    bool rejectedInvalidRawFactor = false;
    try { jec.correct(100., 12., 1., 0., 0.5, 0.5, 30.); }
    catch (const std::invalid_argument&) { rejectedInvalidRawFactor = true; }
    assert(rejectedInvalidRawFactor);
    bool rejectedNaN = false;
    try { jec.correct(100., 12., 0.2, 0., 0.5, 0.5, std::numeric_limits<double>::quiet_NaN()); }
    catch (const std::invalid_argument&) { rejectedNaN = true; }
    assert(rejectedNaN);
    bool rejectedMissingFile = false;
    try { jetmet::AK4JEC missing("/nonexistent/ak4-jec-test.json.gz"); }
    catch (const std::exception&) { rejectedMissingFile = true; }
    assert(rejectedMissingFile);
    if (argc == 3) {
        std::ifstream sample(argv[2]);
        assert(sample.good());
        double pt, mass, rawFactor, eta, phi, area, rho;
        int count = 0;
        while (sample >> pt >> mass >> rawFactor >> eta >> phi >> area >> rho) {
            const auto result = jec.correct(pt, mass, rawFactor, eta, phi, area, rho);
            const double direct = reference->evaluate({area, eta, pt * (1. - rawFactor), rho, phi});
            assert(std::abs(result.pt - pt * (1. - rawFactor) * direct) < 1e-7);
            assert(std::isfinite(result.mass));
            ++count;
        }
        assert(sample.eof() && count > 0);
        std::cout << "Local ROOT sample: " << count << " jets passed\n";
    }
    std::cout << "AK4 JEC scope and nominal payload tests passed\n";
}
