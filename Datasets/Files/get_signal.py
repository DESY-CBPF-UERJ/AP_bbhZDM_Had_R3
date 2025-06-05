import os
import sys
import argparse


#======SETUP=======================================================================================
parser = argparse.ArgumentParser()
parser.add_argument("-v", "--version")
parser.add_argument("-p", "--period")
args = parser.parse_args()

version = args.version
period = args.period

basedir = "signal_"+period[-2:]+"/dti_"+period[0]+"/v"+version+"/"
if os.path.isdir(basedir) is False:
    os.makedirs(basedir)

#==================================================================================================
# Campaigns setup  (key = version_period)
#==================================================================================================
campaigns = {}
campaigns["9_0_16"] = "RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11"
campaigns["9_1_16"] = "RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17"
campaigns["9_0_17"] = "RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9"
campaigns["9_0_18"] = "RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1"
campaigns["12_0_22"] = "Run3Summer22NanoAODv12-130X_mcRun3_2022_realistic_v5"
campaigns["12_1_22"] = "Run3Summer22EENanoAODv12-130X_mcRun3_2022_realistic_postEE_v6"
campaigns["12_0_23"] = "Run3Summer23NanoAODv12-130X_mcRun3_2023_realistic_v14"
campaigns["12_1_23"] = "Run3Summer23BPixNanoAODv12-130X_mcRun3_2023_realistic_postBPix_v2"

#==================================================================================================
# Datasets setup
#==================================================================================================
datasets = [
["Signal_400_100",      "/bbHToZaToLLChiChi_2HDMa_MH-400_Ma-100_MChi-45_TuneCP5_13TeV_madgraph-pythia8/"],
["Signal_400_200",      "/bbHToZaToLLChiChi_2HDMa_MH-400_Ma-200_MChi-45_TuneCP5_13TeV_madgraph-pythia8/"],
["Signal_500_100",      "/bbHToZaToLLChiChi_2HDMa_MH-500_Ma-100_MChi-45_TuneCP5_13TeV_madgraph-pythia8/"],
["Signal_500_200",      "/bbHToZaToLLChiChi_2HDMa_MH-500_Ma-200_MChi-45_TuneCP5_13TeV_madgraph-pythia8/"],
["Signal_500_300",      "/bbHToZaToLLChiChi_2HDMa_MH-500_Ma-300_MChi-45_TuneCP5_13TeV_madgraph-pythia8/"],
["Signal_600_100",      "/bbHToZaToLLChiChi_2HDMa_MH-600_Ma-100_MChi-45_TuneCP5_13TeV_madgraph-pythia8/"],
]


#==================================================================================================
# DO NOT TOUCH THIS PART
#==================================================================================================
campaign_key = version+"_"+period
if campaign_key in campaigns:
    for i in range(len(datasets)):
        file_name = basedir + datasets[i][0]+".txt"

        # Main dataset
        for k in range(9):
            ds_name = datasets[i][1]+campaigns[campaign_key] + "-v" + str(k+1) + "/NANOAODSIM"
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
            print(datasets[i][1]+campaigns[campaign_key] + " is not available!")

        # Extension
        ds_name = datasets[i][1]+campaigns[campaign_key] + "_ext*-v" + str(k_value) + "/NANOAODSIM"
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
else:
    print("There is no campaign set for this period and NANOAOD version!")
    sys.exit()
