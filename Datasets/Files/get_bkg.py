import os
import sys
import argparse


#======SETUP=======================================================================================
parser = argparse.ArgumentParser()
parser.add_argument("-v", "--version")
parser.add_argument("-p", "--period")
args = parser.parse_args()

dataset_code = args.period+"_"+args.version

datasets_available = ["0_16_9", "1_16_9", "0_17_9", "0_18_9", "0_22_12", "1_22_12", "0_23_12", "1_23_12"]

if dataset_code not in datasets_available:
    print("There is no dataset for")
    print("NanoAOD version = v"+args.version)
    print("Year = 20"+args.period[-2:])
    print("DTI = "+args.period[0])
    print("Type a period and a version present in the list below in which the elements are formed as period_version.")
    print(datasets_available)
    sys.exit()


if args.version == "9":
    if args.period == "0_16":
        campaign = "RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11"
    elif args.period == "1_16":
        campaign = "RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17"
    elif args.period == "0_17":
        campaign = "RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9"
    elif args.period == "0_18":
        campaign = "RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1"

if args.version == "12":
    if args.period == "0_22":
        campaign = "Run3Summer22NanoAODv12-130X_mcRun3_2022_realistic_v5"
    elif args.period == "1_22":
        campaign = "Run3Summer22EENanoAODv12-130X_mcRun3_2022_realistic_postEE_v6"
    elif args.period == "0_23":
        campaign = "Run3Summer23NanoAODv12-130X_mcRun3_2023_realistic_v14"
    elif args.period == "1_23":
        campaign = "Run3Summer23BPixNanoAODv12-130X_mcRun3_2023_realistic_postBPix_v2"


basedir = "bkg_"+args.period[-2:]+"/dti_"+args.period[0]+"/v"+args.version+"/"
if os.path.isdir(basedir) is False:
    os.makedirs(basedir)


datasets = [
["QCD_PT-15to30",               "/QCD_PT-15to30_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-30to50",               "/QCD_PT-30to50_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-50to80",               "/QCD_PT-50to80_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-80to120",              "/QCD_PT-80to120_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-120to170",             "/QCD_PT-120to170_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-170to300",             "/QCD_PT-170to300_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-300to470",             "/QCD_PT-300to470_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-470to600",             "/QCD_PT-470to600_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-600to800",             "/QCD_PT-600to800_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-800to1000",            "/QCD_PT-800to1000_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-1000to1400",           "/QCD_PT-1000to1400_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-1400to1800",           "/QCD_PT-1400to1800_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-1800to2400",           "/QCD_PT-1800to2400_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-2400to3200",           "/QCD_PT-2400to3200_TuneCP5_13p6TeV_pythia8/"+campaign],
["QCD_PT-3200",                 "/QCD_PT-3200_TuneCP5_13p6TeV_pythia8/"+campaign],
["TTto4Q",                      "/TTto4Q_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["TTtoLNu2Q",                   "/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WZtoLNu2Q",                   "/WZtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["ZZto2Nu2Q",                   "/ZZto2Nu2Q_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WminusH_Hto2B_Wto2Q",         "/WminusH_Hto2B_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WminusH_Hto2B_WtoLNu",        "/WminusH_Hto2B_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WminusH_Hto2C_Wto2Q",         "/WminusH_Hto2C_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WminusH_Hto2C_WtoLNu",        "/WminusH_Hto2C_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WminusHtoInv_Wto2Q",          "/WminusHtoInv_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8/"+campaign],
["WplusH_Hto2B_Wto2Q",          "/WplusH_Hto2B_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WplusH_Hto2B_WtoLNu",         "/WplusH_Hto2B_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WplusH_Hto2C_Wto2Q",          "/WplusH_Hto2C_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WplusH_Hto2C_WtoLNu",         "/WplusH_Hto2C_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WplusHtoInv_Wto2Q",           "/WplusHtoInv_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8/"+campaign],
["ZH_Hto2B_Zto2Q",              "/ZH_Hto2B_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["ZH_Hto2C_Zto2Q",              "/ZH_Hto2C_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["ZHtoInv_Zto2Q",               "/ZHtoInv_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8/"+campaign],
["ZH_Hto2B_Zto2L",              "/ZH_Hto2B_Zto2L_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["ZH_Hto2C_Zto2L",              "/ZH_Hto2C_Zto2L_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["ZZto2L2Nu",                   "/ZZto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["ZZto2L2Q",                    "/ZZto2L2Q_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WZto2L2Q",                    "/WZto2L2Q_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WZto3LNu",                    "/WZto3LNu_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["TWminusto4Q",                 "/TWminusto4Q_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["TWminustoLNu2Q",              "/TWminustoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WWto4Q",                      "/WWto4Q_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WWtoLNu2Q",                   "/WWtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["WWW",                         "/WWW_4F_TuneCP5_13p6TeV_amcatnlo-madspin-pythia8/"+campaign],
["WWZ",                         "/WWZ_4F_TuneCP5_13p6TeV_amcatnlo-pythia8/"+campaign],
["WZZ",                         "/WZZ_TuneCP5_13p6TeV_amcatnlo-pythia8/"+campaign],
["ZZZ",                         "/ZZZ_TuneCP5_13p6TeV_amcatnlo-pythia8/"+campaign],
["ttHto2B",                     "/ttHto2B_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["ttHto2C",                     "/ttHto2C_M-125_TuneCP5_13p6TeV_powheg-pythia8/"+campaign],
["Zto2Nu_PTNuNu-40to100_1J",    "/Zto2Nu-2Jets_PTNuNu-40to100_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Nu_PTNuNu-40to100_2J",    "/Zto2Nu-2Jets_PTNuNu-40to100_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Nu_PTNuNu-100to200_1J",   "/Zto2Nu-2Jets_PTNuNu-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Nu_PTNuNu-100to200_2J",   "/Zto2Nu-2Jets_PTNuNu-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Nu_PTNuNu-200to400",      "/Zto2Nu-2Jets_PTNuNu-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Nu_PTNuNu-200to400_2J",   "/Zto2Nu-2Jets_PTNuNu-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Nu_PTNuNu-400to600_1J",   "/Zto2Nu-2Jets_PTNuNu-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Nu_PTNuNu-400to600_2J",   "/Zto2Nu-2Jets_PTNuNu-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Nu_PTNuNu-600_1J",        "/Zto2Nu-2Jets_PTNuNu-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Nu_PTNuNu-600_2J",        "/Zto2Nu-2Jets_PTNuNu-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Q_PTQQ-100to200_1J",      "/Zto2Q-2Jets_PTQQ-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Q_PTQQ-100to200_2J",      "/Zto2Q-2Jets_PTQQ-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Q_PTQQ-200to400_1J",      "/Zto2Q-2Jets_PTQQ-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Q_PTQQ-200to400_2J",      "/Zto2Q-2Jets_PTQQ-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Q_PTQQ-400to600_1J",      "/Zto2Q-2Jets_PTQQ-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Q_PTQQ-400to600_2J",      "/Zto2Q-2Jets_PTQQ-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Q_PTQQ-600_1J",           "/Zto2Q-2Jets_PTQQ-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Zto2Q_PTQQ-600_2J",           "/Zto2Q-2Jets_PTQQ-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Wto2Q_PTQQ-100to200_1J",      "/Wto2Q-2Jets_PTQQ-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Wto2Q_PTQQ-100to200_2J",      "/_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Wto2Q_PTQQ-200to400_1J",      "/_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Wto2Q_PTQQ-200to400_2J",      "/Wto2Q-2Jets_PTQQ-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Wto2Q_PTQQ-400to600_1J",      "/Wto2Q-2Jets_PTQQ-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Wto2Q_PTQQ-400to600_2J",      "/Wto2Q-2Jets_PTQQ-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Wto2Q_PTQQ-600_1J",           "/Wto2Q-2Jets_PTQQ-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["Wto2Q_PTQQ-600_2J",           "/Wto2Q-2Jets_PTQQ-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_0J",                   "/WtoLNu-2Jets_0J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_1J",                   "/WtoLNu-2Jets_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_2J",                   "/WtoLNu-2Jets_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_PTLNu-100to200_1J",    "/WtoLNu-2Jets_PTLNu-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_PTLNu-100to200_2J",    "/WtoLNu-2Jets_PTLNu-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_PTLNu-200to400_1J",    "/WtoLNu-2Jets_PTLNu-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_PTLNu-200to400_2J",    "/WtoLNu-2Jets_PTLNu-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_PTLNu-400to600_1J",    "/WtoLNu-2Jets_PTLNu-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_PTLNu-400to600_2J",    "/WtoLNu-2Jets_PTLNu-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_PTLNu-40to100_1J",     "/WtoLNu-2Jets_PTLNu-40to100_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_PTLNu-40to100_2J",     "/WtoLNu-2Jets_PTLNu-40to100_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_PTLNu-600_1J",         "/WtoLNu-2Jets_PTLNu-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
["WtoLNu_PTLNu-600_2J",         "/WtoLNu-2Jets_PTLNu-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"+campaign],
]

for i in range(len(datasets)):
    file_name = basedir + datasets[i][0] + ".txt"

    # Main dataset
    for k in range(9):
        ds_name = datasets[i][1] + "-v" + str(k+1) + "/NANOAODSIM"
        if k == 0:
            command = "dasgoclient --limit 0 --query 'dataset dataset=" + ds_name + "' > " + "temp.txt"
        else:
            command = "dasgoclient --limit 0 --query 'dataset dataset=" + ds_name + "' >> " + "temp.txt"
        os.system(command)
    has_dataset = False
    k_lines = []
    with open("temp.txt", "r") as file:
        for line in file:
            has_dataset = True
            k_lines.append(line[0:-1])
    os.system("rm temp.txt")
    if has_dataset:
        k_value = 9
        for dataset_name in reversed(k_lines):
            command = "dasgoclient --limit 0 --query 'file dataset=" + dataset_name + "' > " + file_name
            os.system(command)
            NumLines = sum(1 for line in open(file_name))
            if NumLines > 0:
                print(dataset_name)
                break
            k_value = k_value - 1
    else:
        open(file_name, 'a').close()
        print(datasets[i][1] + " is not available!")

    # Extension
    ds_name = datasets[i][1] + "_ext*-v" + str(k_value) + "/NANOAODSIM"
    command = "dasgoclient --limit 0 --query 'dataset dataset=" + ds_name + "' > " + "temp.txt"
    os.system(command)
    has_dataset = False
    ext_lines = []
    with open("temp.txt", "r") as file:
        for line in file:
            has_dataset = True
            ext_lines.append(line[0:-1])
    os.system("rm temp.txt")
    if has_dataset:
        for dataset_name in ext_lines:
            command = "dasgoclient --limit 0 --query 'file dataset=" + dataset_name + "' >> " + file_name
            os.system(command)
            print(dataset_name)
