#--------------------------------------------------------------------------------------------------
# Dataset files
#--------------------------------------------------------------------------------------------------
selection = "Test"
analysis = "AP_bbhZDM_Had_R3"
treeName = "Events"
LumiWeights = 1

# Comented means not implemented
analysis_parameters = {
"JET_ETA_CUT                ": 2.5,     # [DONE]
"JET_PT_CUT                 ": 20,      # [DONE] GeV
"JET_ID_WP                  ": 2,       # [DONE] 0-loose, 2-tight, 6-tightlepveto 
"JET_PUID_WP                ": 3,       # 0-fail, 1-loose, 3-medium, 7-tight (tight is the only correct WP in v9)
"JET_BTAG_WP                ": 0,       # [DONE] DeepJet: 0-loose, 1-medium, 2-tight 3- Xtight 4-XXtight; particleNET: 5-loose, 6-medium, 7-tight 8- Xtight 9-XXtight; robustParticleTransformer: 10-loose, 11-medium, 12-tight 13- Xtight 14-XXtight; 
"JET_LEP_DR_ISO_CUT         ": 0.4,
"FAT_JET_PT_CUT             ": 170,     # Cut asked by Gilson
"FAT_JET_ETA_CUT            ": 3,
"FAT_JET_ID_WP              ": 6,       # 0-loose, 2-medium, 4-tight, 6-tightLepVeto  !!!!!!TO CONFIRM!!!!!!!
"ELECTRON_GAP_LOWER_CUT     ": 1.444,   # Lower absolute limit of barrel-endcap gap
"ELECTRON_GAP_UPPER_CUT     ": 1.566,   # Upper absolute limit of barrel-endcap gap
"ELECTRON_ETA_CUT           ": 2.5,
"ELECTRON_PT_CUT            ": 20,      # GeV
#"ELECTRON_LOW_PT_CUT        ": 15,      # 
"ELECTRON_ID_WP             ": 1,       # 0-veto, 1-loose, 2-medium, 3-tight, 4-WP80iso, 5-WP90iso
"MUON_ETA_CUT               ": 2.4, 
"MUON_PT_CUT                ": 20,      # GeV
#"MUON_LOW_PT_CUT            ": 15,      # 
"MUON_ID_WP                 ": 0,       # 0=Loose, 1=Medium, 2=mediumPromptID, 3=tight, 4=soft, 5=highPt
"MUON_ISO_WP                ": 2,       # 0=none, 1=PFIsoVeryLoose, 2=PFIsoLoose,3=PFIsoMedium, 4=PFIsoTight, 5=PFIsoVeryTight, 6=PFIsoVeryVeryTight
#"LEPTON_DR_ISO_CUT          ": 0.3,
#"LEADING_LEP_PT_CUT         ": 40,      # 
#"LEPLEP_PT_CUT              ": 40,      # 
#"LEPLEP_DR_CUT              ": 3.2,
#"LEPLEP_DM_CUT              ": 25,      # 
"MET_CUT                    ": 65,      # 
"MET_DY_UPPER_CUT           ": 100,     # 
"MET_LEPLEP_DPHI_CUT        ": 0.8,
"MET_LEPLEP_MT_CUT          ": 90,      #      
"TAU_VS_ELE_ISO_WP          ": 1,       #  0=No Apply, 1 = VVVLoose, 2 = VVLoose, 3 = VLoose, 4 = Loose, 5 = Medium, 6 = Tight, 7 = VTight, 8 = VVTight
"TAU_VS_JET_ISO_WP          ": 1,       #   0=No Apply, 1 = VVVLoose, 2 = VVLoose, 3 = VLoose, 4 = Loose, 5 = Medium, 6 = Tight, 7 = VTight, 8 = VVTight
"TAU_VS_MU_ISO_WP           ": 1,       #    0=No Apply, 1 = VLoose, 2 = Loose, 3 = Medium, 4 = Tight
"TAU_PT_CUT                 ": 10,
"TAU_ETA_CUT                ": 2.5,
"OMEGA_CUT                  ": 0.3,         

}

corrections = {  # 0-don't apply, 1-apply
}

lateral_systematics = { 
"CV":          [0,  1, [], []],   # [sys_source, sys_universe, processes_ID (empty -> all), subsources] 
}

vertical_systematics = {
}


#--------------------------------------------------------------------------------------------------
# Jobs setup
#--------------------------------------------------------------------------------------------------
NumMaxEvents = -1
NumFilesPerJob_Data = 1   
NumFilesPerJob_Signal = 50 
NumFilesPerJob_Bkg = 5      


#--------------------------------------------------------------------------------------------------
# Dataset files
#--------------------------------------------------------------------------------------------------
periods = [
#"0_22",
#"1_22",
#"0_23",
#"1_23",
"0_24",
]

datasets = [
"Data_MET",
"Signal",
"QCD",
"ResidualSM",
"ST",
"TT",
"Zto2Nu",
"WtoLNu",
"VV",
"Vh",
"DY",
]


#--------------------------------------------------------------------------------------------------
# Metadata
#--------------------------------------------------------------------------------------------------
metadata = {
"NN_model_X_XX         ": analysis+"/Metadata/ML/model.onnx",
"lumi_certificate_X_24      ": analysis+"/Metadata/certificates/Cert_Collisions2024_378981_386951_Golden.json",

}


#--------------------------------------------------------------------------------------------------
# Plots
#--------------------------------------------------------------------------------------------------
Get_Image_in_EPS = 0
Get_Image_in_PNG = 1
Get_Image_in_PDF = 0


