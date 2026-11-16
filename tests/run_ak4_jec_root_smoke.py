#!/usr/bin/env python3
"""Exercise the nominal AK4 JEC with the tracked background and signal ROOT fixtures."""
import os
import pathlib
import subprocess
import sys
import tempfile

import ROOT


REPO = pathlib.Path(__file__).resolve().parents[1]
DEFAULT_INPUTS = [REPO / 'Datasets/bkg.root', REPO / 'Datasets/signal.root']
REQUIRED = ('nJet', 'Jet_pt', 'Jet_mass', 'Jet_rawFactor', 'Jet_eta', 'Jet_phi', 'Jet_area')


def extract(path, output, max_events=20):
    source = ROOT.TFile.Open(str(path))
    if not source or source.IsZombie():
        raise RuntimeError(f'cannot open {path}')
    tree = source.Get('Events')
    if not tree:
        raise RuntimeError(f'{path} has no Events tree')
    missing = [name for name in REQUIRED if not tree.GetBranch(name)]
    if missing:
        raise RuntimeError(f'{path} is missing {", ".join(missing)}')
    rho_name = ('Rho_fixedGridRhoFastjetAll'
                if tree.GetBranch('Rho_fixedGridRhoFastjetAll')
                else 'fixedGridRhoFastjetAll')
    if not tree.GetBranch(rho_name):
        raise RuntimeError(f'{path} has no supported rho branch')

    count = 0
    with output.open('w', encoding='ascii') as stream:
        for event_index, event in enumerate(tree):
            if event_index >= max_events:
                break
            rho = getattr(event, rho_name)
            for jet in range(int(event.nJet)):
                values = (event.Jet_pt[jet], event.Jet_mass[jet],
                          event.Jet_rawFactor[jet], event.Jet_eta[jet],
                          event.Jet_phi[jet], event.Jet_area[jet], rho)
                stream.write(' '.join(str(float(value)) for value in values) + '\n')
                count += 1
    source.Close()
    if not count:
        raise RuntimeError(f'{path} yielded no jets')
    return count, rho_name


def main():
    inputs = [pathlib.Path(value) for value in sys.argv[1:]] or DEFAULT_INPUTS
    with tempfile.TemporaryDirectory(prefix='ak4-jec-root-smoke-') as tmp:
        for index, path in enumerate(inputs):
            sample = pathlib.Path(tmp) / f'jets-{index}.txt'
            count, rho_name = extract(path, sample)
            env = os.environ.copy()
            env['AK4_JEC_JET_SAMPLE'] = str(sample)
            subprocess.run([sys.executable, str(REPO / 'tests/run_ak4_jec_tests.py')],
                           check=True, env=env)
            print(f'{path.name}: {count} jets passed using {rho_name}')


if __name__ == '__main__':
    main()
