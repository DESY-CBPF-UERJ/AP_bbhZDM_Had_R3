#==================================================================================================
# Campaigns setup  (key = version_period)
#==================================================================================================
campaigns = {}
campaigns["12_0_22"] = "Run3Summer22NanoAODv12-130X_mcRun3_2022_realistic_v5"
campaigns["12_1_22"] = "Run3Summer22EENanoAODv12-130X_mcRun3_2022_realistic_postEE_v6"
campaigns["12_0_23"] = "Run3Summer23NanoAODv12-130X_mcRun3_2023_realistic_v14"
campaigns["12_1_23"] = "Run3Summer23BPixNanoAODv12-130X_mcRun3_2023_realistic_postBPix_v2"


#==================================================================================================
# Datasets setup
#==================================================================================================
datasets = [
["ZH_Hto2B_Zto2Nu",             "/ZH-Zto2Nu-Hto2B_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"],       #NEW
["ZH_Hto2C_Zto2Nu",             "/ZH-Zto2Nu-Hto2C_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"],       #NEW
["ZHto2Zto4Nu_Zto2Q",           "/ZH-Hto2Zto4Nu-Zto2Q_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"],   #NEW

["DYto2L-2Jets_MLL-4to10",      "/DYto2L-2Jets_MLL-4to10_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],         #OLD, aparentemente não existe versão
["DYto2L-2Jets_MLL-10to50",     "/DYto2L-2Jets_MLL-10to50_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],        #OLD, aparentemente não existe versão

["DYto2L-2Jets_1J_PTLL-40to100",         "/DYto2L-2Jets_Bin-1J-MLL-50-PTLL-40to100_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW, utilizado PLL agora em vez de MLL
["DYto2L-2Jets_1J_PTLL-100to200",         "/DYto2L-2Jets_Bin-1J-MLL-50-PTLL-100to200_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW, utilizado PLL agora em vez de MLL
["DYto2L-2Jets_1J_PTLL-200to400",         "/DYto2L-2Jets_Bin-1J-MLL-50-PTLL-200to400_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW, utilizado PLL agora em vez de MLL
["DYto2L-2Jets_1J_PTLL-400to600",         "/DYto2L-2Jets_Bin-1J-MLL-50-PTLL-400to600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW, utilizado PLL agora em vez de MLL
["DYto2L-2Jets_1J_PTLL-600",         "/DYto2L-2Jets_Bin-1J-MLL-50-PTLL-600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW, utilizado PLL agora em vez de MLL

["DYto2L-2Jets_2J_PTLL-40to100",         "/DYto2L-2Jets_Bin-2J-MLL-50-PTLL-40to100_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW, utilizado PLL agora em vez de MLL
["DYto2L-2Jets_2J_PTLL-100to200",         "/DYto2L-2Jets_Bin-2J-MLL-50-PTLL-100to200_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW, utilizado PLL agora em vez de MLL
["DYto2L-2Jets_2J_PTLL-200to400",         "/DYto2L-2Jets_Bin-2J-MLL-50-PTLL-200to400_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW, utilizado PLL agora em vez de MLL
["DYto2L-2Jets_2J_PTLL-400to600",         "/DYto2L-2Jets_Bin-2J-MLL-50-PTLL-400to600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW, utilizado PLL agora em vez de MLL
["DYto2L-2Jets_2J_PTLL-600",         "/DYto2L-2Jets_Bin-2J-MLL-50-PTLL-600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW, utilizado PLL agora em vez de MLL
##############################################################################################################
#Essa amostra foi fragmentada em dois tipos
["QCD_PT-15to20",               "/QCD_Bin-PT-15to20_TuneCP5_13p6TeV_pythia8/"], # NEW 
["QCD_PT-20to30",               "/QCD_Bin-PT-20to30_TuneCP5_13p6TeV_pythia8/"], # NEW 
["QCD_PT-30to50",               "/QCD_Bin-PT-30to50_TuneCP5_13p6TeV_pythia8/"], # NEW
["QCD_PT-50to80",               "/QCD_Bin-PT-50to80_TuneCP5_13p6TeV_pythia8/"], # NEW
["QCD_PT-80to120",              "/QCD_Bin-PT-80to120_TuneCP5_13p6TeV_pythia8/"], # NEW
["QCD_PT-120to170",             "/QCD_Bin-PT-120to170_TuneCP5_13p6TeV_pythia8/"], # NEW
["QCD_PT-170to300",             "/QCD_Bin-PT-170to300_TuneCP5_13p6TeV_pythia8/"], # NEW
["QCD_PT-300to470",             "/QCD_Bin-PT-300to470_TuneCP5_13p6TeV_pythia8/"], # NEW
["QCD_PT-470to600",             "/QCD_Bin-PT-470to600_TuneCP5_13p6TeV_pythia8/"], # NEW
["QCD_PT-600to800",             "/QCD_Bin-PT-600to800_TuneCP5_13p6TeV_pythia8/"], # NEW
["QCD_PT-800to1000",            "/QCD_Bin-PT-800to1000_TuneCP5_13p6TeV_pythia8/"], # NEW
["QCD_PT-1000to1500",           "/QCD_Bin-PT-1000to1500_TuneCP5_13p6TeV_pythia8/"], # NEW, MUDARAM O RANGE, de 1000~1400 para 1000~1500. Modifico o nome? Acredito que sim
["QCD_PT-1500to2000",           "/QCD_Bin-PT-1500to2000_TuneCP5_13p6TeV_pythia8/"], # NEW, MUDARAM O RANGE, de 1400~1800 para 1500~2000. Modifico o nome? Acredito que sim
["QCD_PT-2000to2500",           "/QCD_Bin-PT-2000to2500_TuneCP5_13p6TeV_pythia8/"], # NEW, MUDARAM O RANGE, de 1800~2400 para 2000~2500. Modifico o nome? Acredito que sim
["QCD_PT-2500to3000",           "/QCD_Bin-PT-2500to3000_TuneCP5_13p6TeV_pythia8/"], # NEW, MUDARAM O RANGE, de 2400~3200 para 2500~3000. Modifico o nome? Acredito que sim
["QCD_PT-3000",                 "/QCD_Bin-PT-3000_TuneCP5_13p6TeV_pythia8/"], # NEW
["TTto4Q",                      "/TTto4Q_TuneCP5_13p6TeV_powheg-pythia8/"], # Atualizado, mas sem mudança na nomeclatura
["TTtoLNu2Q",                   "/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"], # Atualizado, mas sem mudança na nomeclatura
["TTto2L2Nu",                   "/TTto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/"], # Atualizado, mas sem mudança na nomeclatura. Nesse caso existe uma versão UP (TTto2L2Nu_TuneCP5Up_13p6TeV_powheg-pythia8) e DOWN (TTto2L2Nu_TuneCP5Down_13p6TeV_powheg-pythia8)
["WZtoLNu2Q",                   "/WZtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"], # Atualizado, mas sem mudança na nomeclatura
["ZZto2Nu2Q",                   "/ZZto2Nu2Q_TuneCP5_13p6TeV_powheg-pythia8/"], # Atualizado, mas sem mudança na nomeclatura
["WminusH_Hto2B_Wto2Q",         "/WminusH-Wto2Q-Hto2B_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"], # NEW
["WminusH_Hto2B_WtoLNu",        "/WminusH-WtoLNu-Hto2B_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"], # NEW
["WminusH_Hto2C_Wto2Q",         "/WminusH-Wto2Q-Hto2C_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"], # NEW
["WminusH_Hto2C_WtoLNu",        "/WminusH-WtoLNu-Hto2C_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"], # NEW
["WminusHtoInv_Wto2Q",          "/WminusH-Hto2Zto4Nu-Wto2Q_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"],  #OLD, Não há uma versão facil de apontar que é essa, mas encontrei esse: WminusH-Hto2Zto4Nu-Wto2Q_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8
["WplusH_Hto2B_Wto2Q",          "/WplusH-Wto2Q-Hto2B_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"], # NEW
["WplusH_Hto2B_WtoLNu",         "/WplusH-WtoLNu-Hto2B_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"], # NEW
["WplusH_Hto2C_Wto2Q",          "/WplusH-Wto2Q-Hto2C_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"],  # NEW
["WplusH_Hto2C_WtoLNu",         "/WplusH-WtoLNu-Hto2C_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"],  # NEW
["WplusHtoInv_Wto2Q",           "/WplusH-Hto2Zto4Nu-Wto2Q_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"], #OLD, Não há uma versão facil de apontar que é essa, mas encontrei esse: WplusH-Hto2Zto4Nu-Wto2Q_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8
["ZH_Hto2B_Zto2Q",              "/ZH-Zto2Q-Hto2B_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"], # NEW
["ZH_Hto2C_Zto2Q",              "/ZH-Zto2Q-Hto2C_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"], # NEW
["ZHtoInv_Zto2Q",               "/ZH-Hto2Zto4Nu-Zto2Q_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"], #OLD, Não há uma versão facil de apontar que é essa, mas encontrei esse: ZH-Hto2Zto4Nu-Zto2Q_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8
["ZH_Hto2B_Zto2L",              "/ZH-Zto2L-Hto2B_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"], # NEW
["ZH_Hto2C_Zto2L",              "/ZH-Zto2L-Hto2C_Par-M-125_TuneCP5_13p6TeV_powhegMINLO-pythia8/"], # NEW
["ZZto2L2Nu",                   "/ZZto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/"], # Atualizado, mas sem mudança na nomeclatura
["ZZto2L2Q",                    "/ZZto2L2Q_TuneCP5_13p6TeV_powheg-pythia8/"], # Atualizado, mas sem mudança na nomeclatura
["WZto2L2Q",                    "/WZto2L2Q_TuneCP5_13p6TeV_powheg-pythia8/"], # Atualizado, mas sem mudança na nomeclatura
["WZto3LNu",                    "/WZto3LNu_TuneCP5_13p6TeV_powheg-pythia8/"], # Atualizado, mas sem mudança na nomeclatura
  
["TQbarto2Q-t-channel",         "/TQbarto2Q-t-channel_TuneCP5_13p6TeV_powheg-pythia8/"], #OLD, Não existe versão para 2024
###########################################################################################################################################
["TBbarQto2Q-t-channel",         "/TBbarQto2Q-t-channel-4FS_TuneCP5_13p6TeV_powheg-madspin-pythia8/"], # Nova amostra incluida
["TBbarQtoLNu-t-channel",         "/TBbarQtoLNu-t-channel-4FS_TuneCP5Down_13p6TeV_powheg-madspin-pythia8/"],  # Nova amostra incluida
["TBbarQtoLNu-t-channel",         "/TBbarQtoLNu-t-channel-4FS_TuneCP5Up_13p6TeV_powheg-madspin-pythia8/"],  # Nova amostra incluida
["TBbarQtoLNu-t-channel",         "/TBbarQtoLNu-t-channel-4FS_TuneCP5_13p6TeV_powheg-madspin-pythia8/"],  # Nova amostra incluida
["TbarBQto2Q-t-channel",         "/TbarBQto2Q-t-channel-4FS_TuneCP5_13p6TeV_powheg-madspin-pythia8/"],  # Nova amostra incluida
["TbarBQtoLNu-t-channel",         "/TbarBQtoLNu-t-channel-4FS_TuneCP5Down_13p6TeV_powheg-madspin-pythia8/"],  # Nova amostra incluida
["TbarBQtoLNu-t-channel",         "/TbarBQtoLNu-t-channel-4FS_TuneCP5Up_13p6TeV_powheg-madspin-pythia8/"],  # Nova amostra incluida
["TbarBQtoLNu-t-channel",         "/TbarBQtoLNu-t-channel-4FS_TuneCP5_13p6TeV_powheg-madspin-pythia8/"],  # Nova amostra incluida
  
  
###########################################################################################################################################
["TbarQto2Q-t-channel",         "/TbarQto2Q-t-channel_TuneCP5_13p6TeV_powheg-pythia8/"],# OLD, mesma consideração do de cima
["TQbartoLNu-t-channel",        "/TQbartoLNu-t-channel_TuneCP5_13p6TeV_powheg-pythia8/"],# OLD, mesma consideração do de cima
["TbarQtoLNu-t-channel",        "/TbarQtoLNu-t-channel_TuneCP5_13p6TeV_powheg-pythia8/"],# OLD, mesma consideração do de cima
["TbarWplusto2L2Nu",            "/TbarWplusto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/"],# NEW, não teve mudança na nomeclatura
["TWminusto2L2Nu",              "/TWminusto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/"], # NEW, não teve mudança na nomeclatura
["TWminusto4Q",                 "/TWminusto4Q_TuneCP5_13p6TeV_powheg-pythia8/"],  # NEW, não teve mudança na nomeclatura
["TWminustoLNu2Q",              "/TWminustoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"], # NEW, não teve mudança na nomeclatura
["TbarWplusto4Q",               "/TbarWplusto4Q_TuneCP5_13p6TeV_powheg-pythia8/"], # NEW, não teve mudança na nomeclatura
["TbarWplustoLNu2Q",            "/TbarWplustoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"], # NEW
["WWto4Q",                      "/WWto4Q_TuneCP5_13p6TeV_powheg-pythia8/"], # NEW
["WWtoLNu2Q",                   "/WWtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"], # NEW
["WWW",                         "/WWW-4F_TuneCP5_13p6TeV_amcatnlo-pythia8/"], # NEW
["WWZ",                         "/WWZ-4F_TuneCP5_13p6TeV_amcatnlo-pythia8/"], # NEW
["WZZ",                         "/WZZ_TuneCP5_13p6TeV_amcatnlo-pythia8/"], # OLD, o unico disponivel é o "WZZ-5F_TuneCP5_13p6TeV_amcatnlo-pythia8"
["ZZZ",                         "/ZZZ_TuneCP5_13p6TeV_amcatnlo-pythia8/"], # OLD, o unico disponivel é o "ZZZ-5F_TuneCP5_13p6TeV_amcatnlo-pythia8"
["ttHto2B",                     "/TTH-Hto2B_Par-M-125_TuneCP5_13p6TeV_powheg-pythia8/"], # NEW
["ttHto2C",                     "/TTH-Hto2C_Par-M-125_TuneCP5_13p6TeV_powheg-pythia8/"], # NEW
["Zto2Nu_PTNuNu-40to100_1J",    "/Zto2Nu-2Jets_Bin-1J-PTNuNu-40to100_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
["Zto2Nu_PTNuNu-40to100_2J",    "/Zto2Nu-2Jets_Bin-2J-PTNuNu-40to100_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
["Zto2Nu_PTNuNu-100to200_1J",   "/Zto2Nu-2Jets_Bin-1J-PTNuNu-100to200_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
["Zto2Nu_PTNuNu-100to200_2J",   "/Zto2Nu-2Jets_Bin-2J-PTNuNu-100to200_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],  #NEW
["Zto2Nu_PTNuNu-200to400",      "/Zto2Nu-2Jets_Bin-1J-PTNuNu-200to400_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],  # NEW
["Zto2Nu_PTNuNu-200to400_2J",   "/Zto2Nu-2Jets_Bin-2J-PTNuNu-200to400_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW
["Zto2Nu_PTNuNu-400to600_1J",   "/Zto2Nu-2Jets_Bin-1J-PTNuNu-400to600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW
["Zto2Nu_PTNuNu-400to600_2J",   "/Zto2Nu-2Jets_Bin-2J-PTNuNu-400to600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],  # NEW
["Zto2Nu_PTNuNu-600_1J",        "/Zto2Nu-2Jets_Bin-1J-PTNuNu-600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW
["Zto2Nu_PTNuNu-600_2J",        "/Zto2Nu-2Jets_Bin-2J-PTNuNu-600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # NEW
["Zto2Q_PTQQ-100to200_1J",      "/Zto2Q-2Jets_PTQQ-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # Não existe versão pra 2024
["Zto2Q_PTQQ-100to200_2J",      "/Zto2Q-2Jets_PTQQ-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # Não existe versão pra 2024
["Zto2Q_PTQQ-200to400_1J",      "/Zto2Q-2Jets_PTQQ-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # Não existe versão pra 2024
["Zto2Q_PTQQ-200to400_2J",      "/Zto2Q-2Jets_PTQQ-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # Não existe versão pra 2024
["Zto2Q_PTQQ-400to600_1J",      "/Zto2Q-2Jets_PTQQ-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # Não existe versão pra 2024
["Zto2Q_PTQQ-400to600_2J",      "/Zto2Q-2Jets_PTQQ-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # Não existe versão pra 2024
["Zto2Q_PTQQ-600_1J",           "/Zto2Q-2Jets_PTQQ-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # Não existe versão pra 2024
["Zto2Q_PTQQ-600_2J",           "/Zto2Q-2Jets_PTQQ-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # Não existe versão para 2024


#########################################################################################################################################
# INCLUSÂO DE NOVAS AMOSTRAS QUE ESTÂO DISPONIVEIS NO RUN III - 2024
["Wto2Q-2Jets_Bin-PTQQ-100",      "/Wto2Q-2Jets_Bin-PTQQ-100_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Wto2Q-2Jets_Bin-PTQQ-200",      "/Wto2Q-2Jets_Bin-PTQQ-200_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Wto2Q-2Jets_Bin-PTQQ-400",      "/Wto2Q-2Jets_Bin-PTQQ-400_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Wto2Q-2Jets_Bin-PTQQ",          "/Wto2Q-2Jets_Bin-PTQQ-600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Wto2Q-3Jets_Bin-HT-100to400",   "/Wto2Q-3Jets_Bin-HT-100to400_TuneCP5_13p6TeV_madgraphMLM-pythia8/"],
["Wto2Q-3Jets_Bin-HT-1500to2500", "/Wto2Q-3Jets_Bin-HT-1500to2500_TuneCP5_13p6TeV_madgraphMLM-pythia8/"],
["Wto2Q-3Jets_Bin-HT-2500",       "/Wto2Q-3Jets_Bin-HT-2500_TuneCP5_13p6TeV_madgraphMLM-pythia8/"],
["Wto2Q-3Jets_Bin-HT-400to800",   "/Wto2Q-3Jets_Bin-HT-400to800_TuneCP5_13p6TeV_madgraphMLM-pythia8/"],
["Wto2Q-3Jets_Bin-HT-800to1500",  "/Wto2Q-3Jets_Bin-HT-800to1500_TuneCP5_13p6TeV_madgraphMLM-pythia8/"],



##########################################################################################################################################


["Wto2Q_PTQQ-100to200_1J",      "/Wto2Q-2Jets_PTQQ-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # OLD, Não existe versão para 2024
["Wto2Q_PTQQ-100to200_2J",      "/Wto2Q-2Jets_PTQQ-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # OLD, Não existe versão para 2024
["Wto2Q_PTQQ-200to400_1J",      "/Wto2Q-2Jets_PTQQ-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # OLD, Não existe versão para 2024
["Wto2Q_PTQQ-200to400_2J",      "/Wto2Q-2Jets_PTQQ-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # OLD, Não existe versão para 2024
["Wto2Q_PTQQ-400to600_1J",      "/Wto2Q-2Jets_PTQQ-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # OLD, Não existe versão para 2024
["Wto2Q_PTQQ-400to600_2J",      "/Wto2Q-2Jets_PTQQ-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # OLD, Não existe versão para 2024
["Wto2Q_PTQQ-600_1J",           "/Wto2Q-2Jets_PTQQ-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # OLD, Não existe versão para 2024
["Wto2Q_PTQQ-600_2J",           "/Wto2Q-2Jets_PTQQ-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # OLD, Não existe versão para 2024


["WtoLNu_0J",                   "/WtoLNu-2Jets_0J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # OLD,Não parece existir uma versão para essa de 2024
["WtoLNu_1J",                   "/WtoLNu-2Jets_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # OLD,Não parece existir uma versão para essa de 2024 ou seria um das incluidas abaixo 
["WtoLNu_2J",                   "/WtoLNu-2Jets_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], # OLD,Não parece existir uma versão para essa de 2024 ou seria um das incluidas abaixo

################################################################################
#NOVAS AMOSTRAS INCLUIDAS
["WtoLNu_1J",                   "/WtoLNu-4Jets_Bin-1J_TuneCP5_13p6TeV_madgraphMLM-pythia8/"],
["WtoLNu_2J",                   "/WtoLNu-4Jets_Bin-2J_TuneCP5_13p6TeV_madgraphMLM-pythia8/"],
["WtoLNu_3J",                   "/WtoLNu-4Jets_Bin-3J_TuneCP5_13p6TeV_madgraphMLM-pythia8/"],
["WtoLNu_4J",                   "/WtoLNu-4Jets_Bin-4J_TuneCP5_13p6TeV_madgraphMLM-pythia8/"],

#################################################################################

["WtoLNu_PTLNu-100to200_1J",    "/WtoLNu-2Jets_Bin-1J-PTLNu-100to200_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
["WtoLNu_PTLNu-100to200_2J",    "/WtoLNu-2Jets_Bin-2J-PTLNu-100to200_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
["WtoLNu_PTLNu-200to400_1J",    "/WtoLNu-2Jets_Bin-1J-PTLNu-200to400_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
["WtoLNu_PTLNu-200to400_2J",    "/WtoLNu-2Jets_Bin-2J-PTLNu-200to400_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
["WtoLNu_PTLNu-400to600_1J",    "/WtoLNu-2Jets_Bin-1J-PTLNu-400to600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
["WtoLNu_PTLNu-400to600_2J",    "/WtoLNu-2Jets_Bin-2J-PTLNu-400to600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
["WtoLNu_PTLNu-40to100_1J",     "/WtoLNu-2Jets_Bin-1J-PTLNu-40to100_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
["WtoLNu_PTLNu-40to100_2J",     "/WtoLNu-2Jets_Bin-2J-PTLNu-40to100_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
["WtoLNu_PTLNu-600_1J",         "/WtoLNu-2Jets_Bin-1J-PTLNu-600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
["WtoLNu_PTLNu-600_2J",         "/WtoLNu-2Jets_Bin-2J-PTLNu-600_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"], #NEW
]


## VERSÂO PARA O ANO DE 2022 e 2023 (VALEU CMS!)

'''
datasets = [
["ZH_Hto2B_Zto2Nu",             "/ZH_Hto2B_Zto2Nu_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8/"],
["ZH_Hto2C_Zto2Nu",             "/ZH_Hto2C_Zto2Nu_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8/"],
["ZHto2Zto4Nu_Zto2Q",           "/ZHto2Zto4Nu_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8/"],
["DYto2L-2Jets_MLL-4to10",      "/DYto2L-2Jets_MLL-4to10_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["DYto2L-2Jets_MLL-10to50",     "/DYto2L-2Jets_MLL-10to50_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["DYto2L-2Jets_MLL-50",         "/DYto2L-2Jets_MLL-50_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["DYto2E_MLL-10to50",           "/DYto2E_MLL-10to50_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2E_MLL-50to120",          "/DYto2E_MLL-50to120_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2E_MLL-120to200",         "/DYto2E_MLL-120to200_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2E_MLL-200to400",         "/DYto2E_MLL-200to400_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2E_MLL-400to800",         "/DYto2E_MLL-400to800_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2E_MLL-800to1500",        "/DYto2E_MLL-800to1500_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2E_MLL-1500to2500",       "/DYto2E_MLL-1500to2500_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2E_MLL-2500to4000",       "/DYto2E_MLL-2500to4000_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2E_MLL-4000to6000",       "/DYto2E_MLL-4000to6000_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2E_MLL-6000",             "/DYto2E_MLL-6000_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Mu_MLL-10to50",          "/DYto2Mu_MLL-10to50_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Mu_MLL-50to120",         "/DYto2Mu_MLL-50to120_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Mu_MLL-120to200",        "/DYto2Mu_MLL-120to200_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Mu_MLL-200to400",        "/DYto2Mu_MLL-200to400_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Mu_MLL-400to800",        "/DYto2Mu_MLL-400to800_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Mu_MLL-800to1500",       "/DYto2Mu_MLL-800to1500_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Mu_MLL-1500to2500",      "/DYto2Mu_MLL-1500to2500_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Mu_MLL-2500to4000",      "/DYto2Mu_MLL-2500to4000_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Mu_MLL-4000to6000",      "/DYto2Mu_MLL-4000to6000_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Mu_MLL-6000",            "/DYto2Mu_MLL-6000_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Tau_MLL-10to50",         "/DYto2Tau_MLL-10to50_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Tau_MLL-50to120",        "/DYto2Tau_MLL-50to120_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Tau_MLL-120to200",       "/DYto2Tau_MLL-120to200_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Tau_MLL-200to400",       "/DYto2Tau_MLL-200to400_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Tau_MLL-400to800",       "/DYto2Tau_MLL-400to800_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Tau_MLL-800to1500",      "/DYto2Tau_MLL-800to1500_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Tau_MLL-1500to2500",     "/DYto2Tau_MLL-1500to2500_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Tau_MLL-2500to4000",     "/DYto2Tau_MLL-2500to4000_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Tau_MLL-4000to6000",     "/DYto2Tau_MLL-4000to6000_TuneCP5_13p6TeV_powheg-pythia8/"],
["DYto2Tau_MLL-6000",           "/DYto2Tau_MLL-6000_TuneCP5_13p6TeV_powheg-pythia8/"],
["QCD_PT-15to30",               "/QCD_PT-15to30_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-30to50",               "/QCD_PT-30to50_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-50to80",               "/QCD_PT-50to80_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-80to120",              "/QCD_PT-80to120_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-120to170",             "/QCD_PT-120to170_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-170to300",             "/QCD_PT-170to300_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-300to470",             "/QCD_PT-300to470_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-470to600",             "/QCD_PT-470to600_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-600to800",             "/QCD_PT-600to800_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-800to1000",            "/QCD_PT-800to1000_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-1000to1400",           "/QCD_PT-1000to1400_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-1400to1800",           "/QCD_PT-1400to1800_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-1800to2400",           "/QCD_PT-1800to2400_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-2400to3200",           "/QCD_PT-2400to3200_TuneCP5_13p6TeV_pythia8/"],
["QCD_PT-3200",                 "/QCD_PT-3200_TuneCP5_13p6TeV_pythia8/"],
["TTto4Q",                      "/TTto4Q_TuneCP5_13p6TeV_powheg-pythia8/"],
["TTtoLNu2Q",                   "/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"],
["TTto2L2Nu",                   "/TTto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/"],
["WZtoLNu2Q",                   "/WZtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"],
["ZZto2Nu2Q",                   "/ZZto2Nu2Q_TuneCP5_13p6TeV_powheg-pythia8/"],
["WminusH_Hto2B_Wto2Q",         "/WminusH_Hto2B_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["WminusH_Hto2B_WtoLNu",        "/WminusH_Hto2B_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["WminusH_Hto2C_Wto2Q",         "/WminusH_Hto2C_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["WminusH_Hto2C_WtoLNu",        "/WminusH_Hto2C_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["WminusHtoInv_Wto2Q",          "/WminusHtoInv_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8/"],
["WplusH_Hto2B_Wto2Q",          "/WplusH_Hto2B_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["WplusH_Hto2B_WtoLNu",         "/WplusH_Hto2B_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["WplusH_Hto2C_Wto2Q",          "/WplusH_Hto2C_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["WplusH_Hto2C_WtoLNu",         "/WplusH_Hto2C_WtoLNu_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["WplusHtoInv_Wto2Q",           "/WplusHtoInv_Wto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8/"],
["ZH_Hto2B_Zto2Q",              "/ZH_Hto2B_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["ZH_Hto2C_Zto2Q",              "/ZH_Hto2C_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["ZHtoInv_Zto2Q",               "/ZHtoInv_Zto2Q_M-125_TuneCP5_13p6TeV_powheg-minlo-pythia8/"],
["ZH_Hto2B_Zto2L",              "/ZH_Hto2B_Zto2L_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["ZH_Hto2C_Zto2L",              "/ZH_Hto2C_Zto2L_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["ZZto2L2Nu",                   "/ZZto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/"],
["ZZto2L2Q",                    "/ZZto2L2Q_TuneCP5_13p6TeV_powheg-pythia8/"],
["WZto2L2Q",                    "/WZto2L2Q_TuneCP5_13p6TeV_powheg-pythia8/"],
["WZto3LNu",                    "/WZto3LNu_TuneCP5_13p6TeV_powheg-pythia8/"],
["TQbarto2Q-t-channel",         "/TQbarto2Q-t-channel_TuneCP5_13p6TeV_powheg-pythia8/"],
["TbarQto2Q-t-channel",         "/TbarQto2Q-t-channel_TuneCP5_13p6TeV_powheg-pythia8/"],
["TQbartoLNu-t-channel",        "/TQbartoLNu-t-channel_TuneCP5_13p6TeV_powheg-pythia8/"],
["TbarQtoLNu-t-channel",        "/TbarQtoLNu-t-channel_TuneCP5_13p6TeV_powheg-pythia8/"],
["TbarWplusto2L2Nu",            "/TbarWplusto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/"],
["TWminusto2L2Nu",              "/TWminusto2L2Nu_TuneCP5_13p6TeV_powheg-pythia8/"],
["TWminusto4Q",                 "/TWminusto4Q_TuneCP5_13p6TeV_powheg-pythia8/"],
["TWminustoLNu2Q",              "/TWminustoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"],
["TbarWplusto4Q",               "/TbarWplusto4Q_TuneCP5_13p6TeV_powheg-pythia8/"],
["TbarWplustoLNu2Q",            "/TbarWplustoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"],
["WWto4Q",                      "/WWto4Q_TuneCP5_13p6TeV_powheg-pythia8/"],
["WWtoLNu2Q",                   "/WWtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/"],
["WWW",                         "/WWW_4F_TuneCP5_13p6TeV_amcatnlo-madspin-pythia8/"],
["WWZ",                         "/WWZ_4F_TuneCP5_13p6TeV_amcatnlo-pythia8/"],
["WZZ",                         "/WZZ_TuneCP5_13p6TeV_amcatnlo-pythia8/"],
["ZZZ",                         "/ZZZ_TuneCP5_13p6TeV_amcatnlo-pythia8/"],
["ttHto2B",                     "/ttHto2B_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["ttHto2C",                     "/ttHto2C_M-125_TuneCP5_13p6TeV_powheg-pythia8/"],
["Zto2Nu_PTNuNu-40to100_1J",    "/Zto2Nu-2Jets_PTNuNu-40to100_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Nu_PTNuNu-40to100_2J",    "/Zto2Nu-2Jets_PTNuNu-40to100_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Nu_PTNuNu-100to200_1J",   "/Zto2Nu-2Jets_PTNuNu-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Nu_PTNuNu-100to200_2J",   "/Zto2Nu-2Jets_PTNuNu-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Nu_PTNuNu-200to400",      "/Zto2Nu-2Jets_PTNuNu-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Nu_PTNuNu-200to400_2J",   "/Zto2Nu-2Jets_PTNuNu-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Nu_PTNuNu-400to600_1J",   "/Zto2Nu-2Jets_PTNuNu-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Nu_PTNuNu-400to600_2J",   "/Zto2Nu-2Jets_PTNuNu-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Nu_PTNuNu-600_1J",        "/Zto2Nu-2Jets_PTNuNu-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Nu_PTNuNu-600_2J",        "/Zto2Nu-2Jets_PTNuNu-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Q_PTQQ-100to200_1J",      "/Zto2Q-2Jets_PTQQ-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Q_PTQQ-100to200_2J",      "/Zto2Q-2Jets_PTQQ-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Q_PTQQ-200to400_1J",      "/Zto2Q-2Jets_PTQQ-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Q_PTQQ-200to400_2J",      "/Zto2Q-2Jets_PTQQ-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Q_PTQQ-400to600_1J",      "/Zto2Q-2Jets_PTQQ-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Q_PTQQ-400to600_2J",      "/Zto2Q-2Jets_PTQQ-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Q_PTQQ-600_1J",           "/Zto2Q-2Jets_PTQQ-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Zto2Q_PTQQ-600_2J",           "/Zto2Q-2Jets_PTQQ-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Wto2Q_PTQQ-100to200_1J",      "/Wto2Q-2Jets_PTQQ-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Wto2Q_PTQQ-100to200_2J",      "/Wto2Q-2Jets_PTQQ-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Wto2Q_PTQQ-200to400_1J",      "/Wto2Q-2Jets_PTQQ-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Wto2Q_PTQQ-200to400_2J",      "/Wto2Q-2Jets_PTQQ-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Wto2Q_PTQQ-400to600_1J",      "/Wto2Q-2Jets_PTQQ-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Wto2Q_PTQQ-400to600_2J",      "/Wto2Q-2Jets_PTQQ-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Wto2Q_PTQQ-600_1J",           "/Wto2Q-2Jets_PTQQ-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["Wto2Q_PTQQ-600_2J",           "/Wto2Q-2Jets_PTQQ-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_0J",                   "/WtoLNu-2Jets_0J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_1J",                   "/WtoLNu-2Jets_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_2J",                   "/WtoLNu-2Jets_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_PTLNu-100to200_1J",    "/WtoLNu-2Jets_PTLNu-100to200_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_PTLNu-100to200_2J",    "/WtoLNu-2Jets_PTLNu-100to200_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_PTLNu-200to400_1J",    "/WtoLNu-2Jets_PTLNu-200to400_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_PTLNu-200to400_2J",    "/WtoLNu-2Jets_PTLNu-200to400_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_PTLNu-400to600_1J",    "/WtoLNu-2Jets_PTLNu-400to600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_PTLNu-400to600_2J",    "/WtoLNu-2Jets_PTLNu-400to600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_PTLNu-40to100_1J",     "/WtoLNu-2Jets_PTLNu-40to100_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_PTLNu-40to100_2J",     "/WtoLNu-2Jets_PTLNu-40to100_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_PTLNu-600_1J",         "/WtoLNu-2Jets_PTLNu-600_1J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
["WtoLNu_PTLNu-600_2J",         "/WtoLNu-2Jets_PTLNu-600_2J_TuneCP5_13p6TeV_amcatnloFXFX-pythia8/"],
]
'''
