# JEC validation anafile

`JECValidation` compares the jet values stored in NanoAOD with values recalculated
using the versioned 2024 JEC payload. It does not alter jets, MET or event
selection, and it processes every input event.

## Configuration

In `setup.py`, use:

```python
selection = "JECValidation"

corrections = {
        "AK4_JEC_CORR           ": 0,
        # other switches may remain disabled for this diagnostic
}
```

The switch must remain `0`: the anafile needs the stored NanoAOD jets unchanged
so that it can calculate and save both values in a single run. Data and years
other than 2024 are rejected explicitly.

From the enclosing HEPHero directory:

```bash
hepenv
python3 setAnalysis.py -a AP_bbhZDM_Had_R3
make -j2
python3 runSelection.py -j 0 -t 0
```

Use a small `NumMaxEvents` while validating. The output ROOT `selection` tree
contains one row per event and vector branches including:

- `Jet_pt_stored`, `Jet_pt_rejec`;
- `Jet_mass_stored`, `Jet_mass_rejec`;
- `Jet_pt_ratio_rejec_over_stored`;
- `Jet_pt_delta_rejec_minus_stored`;
- the old and new correction factors relative to the raw jet;
- `Jet_eta`, `Jet_phi`, `Jet_rawFactor`, `Jet_area`;
- `PFMET` and `PuppiMET` copied unchanged for reference.

The usual HEPHero output also includes histograms for the pt ratio, pt difference,
ratio versus eta, and recalculated versus stored pt. This validates only nominal
AK4 JEC; it does not add JER, systematic variations or MET propagation.
