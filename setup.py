#--------------------------------------------------------------------------------------------------
# Dataset files
#--------------------------------------------------------------------------------------------------
selection = "weights"
analysis = "AP_bbhZDM_Had_R3"
treeName = "Events"
LumiWeights = 1

analysis_parameters = {
"JET_ETA_CUT                ": 2.4,
"JET_PT_CUT                 ": 20,      # GeV
"JET_ID_WP                  ": 6,       # 0-loose, 2-tight, 6-tightlepveto 
"JET_PUID_WP                ": 7,       # 0-fail, 1-loose, 3-medium, 7-tight (tight is the only correct WP in v9)
"JET_BTAG_WP                ": 3,       # DeepJet: 0-loose, 1-medium, 2-tight; DeepCSV: 3-loose, 4-medium, 5-tight; [Set up the efficiency maps as well]
"JET_LEP_DR_ISO_CUT         ": 0.4,
"ELECTRON_GAP_LOWER_CUT     ": 1.444,   # Lower absolute limit of barrel-endcap gap
"ELECTRON_GAP_UPPER_CUT     ": 1.566,   # Upper absolute limit of barrel-endcap gap
"ELECTRON_ETA_CUT           ": 2.5,
"ELECTRON_PT_CUT            ": 20,      # GeV  
"ELECTRON_LOW_PT_CUT        ": 15,      # GeV
"ELECTRON_ID_WP             ": 4,       # 0-veto, 1-loose, 2-medium, 3-tight, 4-WP90iso, 5-WP80iso
"MUON_ETA_CUT               ": 2.4, 
"MUON_PT_CUT                ": 20,      # GeV
"MUON_LOW_PT_CUT            ": 15,      # GeV
"MUON_ID_WP                 ": 1,       # 0-loose, 1-medium, 2-tight
"MUON_ISO_WP                ": 3,       # 0-none, 1-loose/looseID, 2-loose/mediumID, 3-tight/mediumID
#"LEPTON_DR_ISO_CUT          ": 0.3,
"LEADING_LEP_PT_CUT         ": 40,      # GeV
"LEPLEP_PT_CUT              ": 40,      # GeV
"LEPLEP_DR_CUT              ": 3.2,
"LEPLEP_DM_CUT              ": 25,      # GeV
"MET_CUT                    ": 65,      # GeV
"MET_DY_UPPER_CUT           ": 100,     # GeV
"MET_LEPLEP_DPHI_CUT        ": 0.8,
"MET_LEPLEP_MT_CUT          ": 90,      # GeV     
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
datasets = [
#"Data_MET",
"Signal",
]


#--------------------------------------------------------------------------------------------------
# Metadata
#--------------------------------------------------------------------------------------------------
metadata = {       
}


#--------------------------------------------------------------------------------------------------
# Plots
#--------------------------------------------------------------------------------------------------
Get_Image_in_EPS = 0
Get_Image_in_PNG = 1
Get_Image_in_PDF = 0
