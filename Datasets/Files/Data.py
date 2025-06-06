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
for era in set(sum(eras.values(), [])):
    campaigns["9_16_"+era] = "Run2016"+era+"_UL2016_MiniAODv2_NanoAODv9"
    campaigns["9_17_"+era] = "Run2017"+era+"_UL2017_MiniAODv2_NanoAODv9"
    campaigns["9_18_"+era] = "Run2018"+era+"_UL2018_MiniAODv2_NanoAODv9_GT36"
    campaigns["12_22_"+era] = "CMSSW_13_2_0-130X_dataRun3_v2_RelVal_2022"+era
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
