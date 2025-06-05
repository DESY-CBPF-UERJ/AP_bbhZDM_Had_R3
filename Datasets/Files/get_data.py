import os
import sys
import argparse

# List of datasets generated with the command below (example for MuonEG).
# dasgoclient --limit 0 --query 'dataset dataset=/MuonEG/*UL2016_MiniAODv1_NanoAODv2*/NANOAOD'

parser = argparse.ArgumentParser()
parser.add_argument("-v", "--version")
parser.add_argument("-p", "--year")
args = parser.parse_args()

year = args.year
version = args.version

basedir = "data_"+year+"/v"+version+"/"
if os.path.isdir(basedir) is False:
    os.makedirs(basedir)

#==================================================================================================
# Eras setup  (key = year)
#==================================================================================================
eras = {}
eras["22"] = ['C', 'D', 'E', 'F', 'G']
eras["23"] = ['C', 'D']

#==================================================================================================
# Campaigns setup  (key = version_year_era)
#==================================================================================================
campaigns = {}
for year in eras.keys():
    for era in eras[year]:
        campaigns["9_16_"era] = "Run2016"+era+"_UL2016_MiniAODv2_NanoAODv9"
        campaigns["9_17_"era] = "Run2017"+era+"_UL2017_MiniAODv2_NanoAODv9"
        campaigns["9_18_"era] = "Run2018"+era+"_UL2018_MiniAODv2_NanoAODv9_GT36"
        campaigns["12_22_"era] = "CMSSW_13_2_0-130X_dataRun3_v2_RelVal_2022"+era
        #campaigns["12_23_"era] = "CMSSW_13_2_0-130X_dataRun3_v2_RelVal_2022"+era

#==================================================================================================
# Datasets setup  (key = year)
#==================================================================================================
datasets = {}
datasets["22"] = [
["Data_SingleMu",      "/SingleMuon/"],
["Data_SingleEle",     "/SingleElectron/"],
]

#datasets["23"] = [
#["Data_SingleMu",      "/SingleMuon/"],
#["Data_SingleEle",     "/SingleElectron/"],
#]


#==================================================================================================
# DO NOT TOUCH THIS PART
#==================================================================================================
if year in eras:
    for i in range(len(datasets[year])):
        if year == "17" and version == "9":
            if datasets[year][i][0][:13] == "Data_SingleMu":
                datasets[year][i][1] = datasets[year][i][1]+"_GT36"
        for era in eras[year]:
            campaign_key = version+"_"+year+"_"+era
            if campaign_key in campaigns:
                file_name = basedir + datasets[year][i][0]+"_"+era+".txt"
                for k in range(9):
                    ds_name = datasets[year][i][1]+campaigns[campaign_key] + "-v" + str(k+1) + "/NANOAOD"
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
                if has_dataset:
                    for dataset_name in reversed(k_lines):
                        command = "dasgoclient --limit 0 --query 'file dataset=" + dataset_name + "' > " + file_name
                        os.system(command)
                        NumLines = sum(1 for line in open(file_name))
                        if NumLines > 0:
                            print(dataset_name)
                            break
                else:
                    open(file_name, 'a').close()
                    print(datasets[year][i][1]+campaigns[campaign_key] + " is not available!")
                os.system("rm temp.txt")
            else:
                print("There is no campaign set for this year and NANOAOD version!")
                sys.exit()
else:
    print("There is no era set for this year!")

