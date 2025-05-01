import os
import sys
import argparse

# List of datasets generated with the dasgoclient command.
# Example: dasgoclient --limit 0 --query 'dataset dataset=/QCD*/*22*v12*/NANOAODSIM'

#======SETUP=======================================================================================
parser = argparse.ArgumentParser()
parser.add_argument("-t", "--tag")
args = parser.parse_args()

campaign = "*"+args.tag+"*/NANOAODSIM"


datasets = [
"ZH_Hto2B_Zto2Nu_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8",
"ZH_Hto2C_Zto2Nu_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8",
"ZHto2Zto4Nu_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8",
"TTto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8",
"TQbartoLNu-t-channel_TuneCP5_13p6TeV_powheg-pythia8",
"TbarQtoLNu-t-channel_TuneCP5_13p6TeV_powheg-pythia8",
"TbarWplusto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8",
"TWminusto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8",
"TWminustoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8",
"TbarWplustoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8",
"QCD_PT-15to30_TuneCP5_13p6TeV_pythia8",
"QCD_PT-30to50_TuneCP5_13p6TeV_pythia",
"QCD_PT-50to80_TuneCP5_13p6TeV_pythia8",
"QCD_PT-80to120_TuneCP5_13p6TeV_pythia8",
"QCD_PT-120to170_TuneCP5_13p6TeV_pythia8",
"QCD_PT-170to300_TuneCP5_13p6TeV_pythia8",
"QCD_PT-300to470_TuneCP5_13p6TeV_pythia8",
"QCD_PT-470to600_TuneCP5_13p6TeV_pythia8",
"QCD_PT-600to800_TuneCP5_13p6TeV_pythia8",
"QCD_PT-800to1000_TuneCP5_13p6TeV_pythia8",
"QCD_PT-1000to1400_TuneCP5_13p6TeV_pythia8",
"QCD_PT-1400to1800_TuneCP5_13p6TeV_pythia8",
"QCD_PT-1800to2400_TuneCP5_13p6TeV_pythia8",
"QCD_PT-2400to3200_TuneCP5_13p6TeV_pythia8",
"QCD_PT-3200_TuneCP5_13p6TeV_pythia8",
"TTto4Q_TuneCP5_13p6TeV_powheg-pythia8",
"TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8",
"WZtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8",
"ZZto2Nu2Q_TuneCP5_13p6TeV_powheg-pythia8",
"WminusH_Hto2B_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"WminusH_Hto2B_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"WminusH_Hto2C_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"WminusH_Hto2C_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"WminusHtoInv_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8",
"WplusH_Hto2B_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"WplusH_Hto2B_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"WplusH_Hto2C_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"WplusH_Hto2C_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"WplusHtoInv_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8",
"ZH_Hto2B_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"ZH_Hto2C_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"ZHtoInv_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8",
"ZH_Hto2B_Zto2L_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"ZH_Hto2C_Zto2L_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"ZZto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8",
"ZZto2L2Q_TuneCP5_13p6TeV_powheg-pythia8",
"WZto2L2Q_TuneCP5_13p6TeV_powheg-pythia8",
"WZto3LNu_TuneCP5_13p6TeV_powheg-pythia8",
"WWto4Q_TuneCP5_13p6TeV_powheg-pythia8",
"WWtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8",
"WWW_4F_TuneCP5_13p6TeV_amcatnlo-madspin-pythia8",
"WWZ_4F_TuneCP5_13p6TeV_amcatnlo-pythia8",
"WZZ_TuneCP5_13p6TeV_amcatnlo-pythia8",
"ZZZ_TuneCP5_13p6TeV_amcatnlo-pythia8",
"ttHto2B_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"ttHto2C_M-125_TuneCP5_13p6TeV_powheg-pythia8",
"Zto2Nu-2Jets_PTNuNu-40to100_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Nu-2Jets_PTNuNu-40to100_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Nu-2Jets_PTNuNu-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Nu-2Jets_PTNuNu-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Nu-2Jets_PTNuNu-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Nu-2Jets_PTNuNu-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Nu-2Jets_PTNuNu-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Nu-2Jets_PTNuNu-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Nu-2Jets_PTNuNu-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Nu-2Jets_PTNuNu-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Q-2Jets_PTQQ-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Q-2Jets_PTQQ-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Q-2Jets_PTQQ-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Q-2Jets_PTQQ-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Q-2Jets_PTQQ-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Q-2Jets_PTQQ-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Q-2Jets_PTQQ-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Zto2Q-2Jets_PTQQ-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Wto2Q-2Jets_PTQQ-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Wto2Q-2Jets_PTQQ-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Wto2Q-2Jets_PTQQ-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Wto2Q-2Jets_PTQQ-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Wto2Q-2Jets_PTQQ-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Wto2Q-2Jets_PTQQ-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Wto2Q-2Jets_PTQQ-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"Wto2Q-2Jets_PTQQ-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_0J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_PTLNu-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_PTLNu-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_PTLNu-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_PTLNu-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_PTLNu-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_PTLNu-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_PTLNu-40to100_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_PTLNu-40to100_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_PTLNu-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
"WtoLNu-2Jets_PTLNu-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8",
]


print("#############################################################################################")
for i in range(len(datasets)):
    command = "dasgoclient --limit 0 --query 'dataset dataset=/" + datasets[i] + "*/" + campaign + "'"
    print(">>>> " + command)
    os.system(command)
    print(" ")
