#==================================================================================================
# Eras setup  (key = year)
#==================================================================================================
eras = {}
eras["22"] = ['C', 'D', 'E', 'F', 'G']
eras["23"] = ['C', 'D']
eras["24"] = ['C','D','E','F','G','H','I']

#==================================================================================================
# Campaigns setup  (key = version_year_era)
#==================================================================================================
campaigns = {}
for era in set(sum(eras.values(), [])):
    campaigns["12_22_"+era] = "CMSSW_13_2_0-130X_dataRun3_v2_RelVal_2022"+era
    #campaigns["12_23_"+era] = "CMSSW_13_2_0-130X_dataRun3_v2_RelVal_2022"+era
    campaigns["15_24_"+era] = "CMSSW_13_2_0-130X_dataRun3_v2_RelVal_2022"+era


#==================================================================================================
# Datasets setup  (key = year)
#==================================================================================================
datasets = {}
#datasets["22"] = [
#["Data_SingleMu",      "/SingleMuon/"],
#["Data_SingleEle",     "/SingleElectron/"],
#]

#datasets["23"] = [
#["Data_SingleMu",      "/SingleMuon/"],
#["Data_SingleEle",     "/SingleElectron/"],
#]

datasets["24"] = [
["Data_SingleMu",      "/SingleMuon/"],
["Data_SingleEle",     "/SingleElectron/"],
]
