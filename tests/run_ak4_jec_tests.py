#!/usr/bin/env python3
"""Compile and run the ROOT-independent AK4 JEC regression tests."""
import os
import pathlib
import subprocess
import tempfile
import runpy
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[1]


class AK4JECTests(unittest.TestCase):
    def test_setup_exposes_ak4_switch_and_payload(self):
        setup = runpy.run_path(str(ROOT / 'setup.py'))
        switches = {k.strip(): v for k, v in setup['corrections'].items()}
        metadata = {k.strip(): v for k, v in setup['metadata'].items()}
        self.assertEqual(switches.get('AK4_JEC_CORR'), 0)
        self.assertEqual(metadata.get('jet_jerc_0_24'),
                         'AP_bbhZDM_Had_R3/Metadata/POG/JME/2024/jet_jerc.json.gz')

    def test_scope_and_nominal(self):
        self.assertTrue((ROOT / 'include/AK4JEC.h').is_file(),
                        'AK4 nominal JEC implementation is missing')
        self.assertIn('class AK4JEC', (ROOT / 'include/AK4JEC.h').read_text(),
                      'AK4 nominal JEC evaluator is missing')
        with tempfile.TemporaryDirectory(prefix='ak4-jec-', dir=str(ROOT / 'tests')) as tmp:
            executable = pathlib.Path(tmp) / 'test_ak4_jec'
            command = [os.environ.get('CXX', 'g++'), '-std=c++17', '-O0',
                       '-I' + str(ROOT / 'include'), '-I' + str(ROOT.parent / 'include'),
                       str(ROOT / 'tests/test_ak4_jec.cpp'),
                       str(ROOT / 'src/correction.cc'), str(ROOT / 'src/formula_ast.cc'),
                       '-lz', '-o', str(executable)]
            subprocess.run(command, check=True)
            arguments = [str(executable), str(ROOT / 'Metadata/POG/JME/2024/jet_jerc.json.gz')]
            if os.environ.get('AK4_JEC_JET_SAMPLE'):
                arguments.append(os.environ['AK4_JEC_JET_SAMPLE'])
            subprocess.run(arguments, check=True)


if __name__ == '__main__':
    unittest.main()
