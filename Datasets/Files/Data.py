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
    campaigns["15_24_"+era] = "Run2024"+era+"-MINIv6NANOv15"


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
# https://cmsweb.cern.ch/das/request?view=list&limit=50&instance=prod%2Fglobal&input=dataset%3D%2F*%2FRun2024C*MINIv6NANOv15-v1*%2FNANOAOD
datasets["24"] = [
["Data_JetMET0",      "/JetMET0/"],
["Data_JetMET1",      "/JetMET1/"],
["Data_EGamma0",      "/EGamma0/"],
["Data_EGamma1",      "/EGamma1/"],
["Data_Muon0",        "/Muon0/"],
["Data_Muon1",        "/Muon1/"],
["Data_MuonEG",       "/MuonEG/"],
]
