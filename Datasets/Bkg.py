analysis = "AP_bbhZDM_Had_R3"
nano_version = 'v12'
path_0_22 = analysis+'/Datasets/Files/bkg_22/dti_0/'+nano_version+'/'
path_1_22 = analysis+'/Datasets/Files/bkg_22/dti_1/'+nano_version+'/'
path_0_23 = analysis+'/Datasets/Files/bkg_23/dti_0/'+nano_version+'/'
path_1_23 = analysis+'/Datasets/Files/bkg_23/dti_1/'+nano_version+'/'

#--------------------------------------------------------------------------------------------------
# ID digits:
# 1st-2nd = 16(2016),17(2017),18(2018)                              # Year
# 3th-4th = 00(Data),01(MC-signal),02-13(MC-bkg),99(private sample) # Group
# 5th-6th = 00(none),...                                            # Bkg -> Process
# 5th-6th = 00(none),11(250_30),12(250_40),55(1250_100)             # Signal -> Signal point
# 5th-6th = 00(none),01(A),02(B),03(C)                              # Data -> Era
# 7th     = 0,1,2,...                                               # Data taking interval (DTI)

# 2022 DTIs = 0(preEE), 1(postEE)
# 2023 DTIs = 0(preBPix), 1(postBPix)
#--------------------------------------------------------------------------------------------------


periods = ["0_22", "1_22", "0_23", "1_23"]
paths = [path_0_22, path_1_22, path_0_23, path_1_23]

for period,path in zip(periods,paths):

    dti = period[0]
    year = period[-2:]
    
    # DYPt50ToInf = [
    #     ["DYJetsToLL_PtZ-50To100_"+period]           + [year+'0202'+dti, path+"DYJetsToLL_PtZ-50To100.txt"],
    # ]

    DY = [

        # ["DYto2L-2Jets_MLL-4to10_"+period]          + [year+'0300'+dti, path+"DYto2L-2Jets_MLL-4to10.txt"],
        # ["DYto2L-2Jets_MLL-10to50_"+period]         + [year+'0300'+dti, path+"DYto2L-2Jets_MLL-10to50.txt"],
        # ["DYto2L-2Jets_MLL-50_"+period]             + [year+'0300'+dti, path+"DYto2L-2Jets_MLL-50.txt"],

        ["DYto2E_MLL-10to50_"+period]             + [year+'0300'+dti, path+"DYto2E_MLL-10to50.txt"],
        ["DYto2E_MLL-50to120_"+period]            + [year+'0300'+dti, path+"DYto2E_MLL-50to120.txt"],
        ["DYto2E_MLL-120to200_"+period]           + [year+'0300'+dti, path+"DYto2E_MLL-120to200.txt"],
        ["DYto2E_MLL-200to400_"+period]           + [year+'0300'+dti, path+"DYto2E_MLL-200to400.txt"],
        ["DYto2E_MLL-400to800_"+period]           + [year+'0300'+dti, path+"DYto2E_MLL-400to800.txt"], 
        ["DYto2E_MLL-800to1500_"+period]          + [year+'0300'+dti, path+"DYto2E_MLL-800to1500.txt"], 
        ["DYto2E_MLL-1500to2500_"+period]         + [year+'0300'+dti, path+"DYto2E_MLL-1500to2500.txt"],
        ["DYto2E_MLL-2500to4000_"+period]         + [year+'0300'+dti, path+"DYto2E_MLL-2500to4000.txt"],
        ["DYto2E_MLL-4000to6000_"+period]         + [year+'0300'+dti, path+"DYto2E_MLL-4000to6000.txt"],
        ["DYto2E_MLL-6000_"+period]               + [year+'0300'+dti, path+"DYto2E_MLL-6000.txt"],

        ["DYto2Mu_MLL-10to50_"+period]             + [year+'0300'+dti, path+"DYto2Mu_MLL-10to50.txt"],
        ["DYto2Mu_MLL-50to120_"+period]            + [year+'0300'+dti, path+"DYto2Mu_MLL-50to120.txt"],
        ["DYto2Mu_MLL-120to200_"+period]           + [year+'0300'+dti, path+"DYto2Mu_MLL-120to200.txt"],
        ["DYto2Mu_MLL-200to400_"+period]           + [year+'0300'+dti, path+"DYto2Mu_MLL-200to400.txt"],
        ["DYto2Mu_MLL-400to800_"+period]           + [year+'0300'+dti, path+"DYto2Mu_MLL-400to800.txt"],
        ["DYto2Mu_MLL-800to1500_"+period]          + [year+'0300'+dti, path+"DYto2Mu_MLL-800to1500.txt"],
        ["DYto2Mu_MLL-1500to2500_"+period]         + [year+'0300'+dti, path+"DYto2Mu_MLL-1500to2500.txt"],
        ["DYto2Mu_MLL-2500to4000_"+period]         + [year+'0300'+dti, path+"DYto2Mu_MLL-2500to4000.txt"],
        ["DYto2Mu_MLL-4000to6000_"+period]         + [year+'0300'+dti, path+"DYto2Mu_MLL-4000to6000.txt"],
        ["DYto2Mu_MLL-6000_"+period]               + [year+'0300'+dti, path+"DYto2Mu_MLL-6000.txt"],

        ["DYto2Tau_MLL-10to50_"+period]             + [year+'0300'+dti, path+"DYto2Tau_MLL-10to50.txt"],
        ["DYto2Tau_MLL-50to120_"+period]            + [year+'0300'+dti, path+"DYto2Tau_MLL-50to120.txt"],
        ["DYto2Tau_MLL-120to200_"+period]           + [year+'0300'+dti, path+"DYto2Tau_MLL-120to200.txt"],
        ["DYto2Tau_MLL-200to400_"+period]           + [year+'0300'+dti, path+"DYto2Tau_MLL-200to400.txt"],
        ["DYto2Tau_MLL-400to800_"+period]           + [year+'0300'+dti, path+"DYto2Tau_MLL-400to800.txt"],
        ["DYto2Tau_MLL-800to1500_"+period]          + [year+'0300'+dti, path+"DYto2Tau_MLL-800to1500.txt"],
        ["DYto2Tau_MLL-1500to2500_"+period]         + [year+'0300'+dti, path+"DYto2Tau_MLL-1500to2500.txt"],
        ["DYto2Tau_MLL-2500to4000_"+period]         + [year+'0300'+dti, path+"DYto2Tau_MLL-2500to4000.txt"],
        ["DYto2Tau_MLL-4000to6000_"+period]         + [year+'0300'+dti, path+"DYto2Tau_MLL-4000to6000.txt"],
        ["DYto2Tau_MLL-6000_"+period]               + [year+'0300'+dti, path+"DYto2Tau_MLL-6000.txt"],

    ]

    TT = [
        ["TTto4Q_"+period]          + [year+'1800'+dti, path+"TTto4Q.txt"],       # TT To Hadronic
        ["TTtoLNu2Q_"+period]       + [year+'1800'+dti, path+"TTtoLNu2Q.txt"],    # TT To SemiLeptonic
        ["TTto2L2Nu_"+period]       + [year+'0300'+dti, path+"TTto2L2Nu.txt"],    # TT To fullyLeptonic
    ]

    ResidualSM = [
        ["WtoLNu_0J_"+period]              + [year+'1800'+dti, path+"WtoLNu_0J.txt"],
        ["WtoLNu_1J_"+period]              + [year+'1800'+dti, path+"WtoLNu_1J.txt"],
        ["WtoLNu_2J_"+period]              + [year+'1800'+dti, path+"WtoLNu_2J.txt"],
        ["WplusH_Hto2B_Wto2Q_"+period]     + [year+'1800'+dti, path+"WplusH_Hto2B_Wto2Q.txt"],
        ["WplusH_Hto2B_WtoLNu_"+period]    + [year+'1800'+dti, path+"WplusH_Hto2B_WtoLNu.txt"],
        ["WplusH_Hto2C_Wto2Q_"+period]     + [year+'1800'+dti, path+"WplusH_Hto2C_Wto2Q.txt"],
        ["WplusH_Hto2C_WtoLNu_"+period]    + [year+'1800'+dti, path+"WplusH_Hto2C_WtoLNu.txt"],
        ["WplusHtoInv_Wto2Q_"+period]      + [year+'1800'+dti, path+"WplusHtoInv_Wto2Q.txt"],
        ["WminusH_Hto2B_Wto2Q_"+period]    + [year+'1800'+dti, path+"WminusH_Hto2B_Wto2Q.txt"],
        ["WminusH_Hto2B_WtoLNu_"+period]   + [year+'1800'+dti, path+"WminusH_Hto2B_WtoLNu.txt"],
        ["WminusH_Hto2C_Wto2Q_"+period]    + [year+'1800'+dti, path+"WminusH_Hto2C_Wto2Q.txt"],
        ["WminusH_Hto2C_WtoLNu_"+period]   + [year+'1800'+dti, path+"WminusH_Hto2C_WtoLNu.txt"],
        ["WminusHtoInv_Wto2Q_"+period]     + [year+'1800'+dti, path+"WminusHtoInv_Wto2Q.txt"],
        ["WWW_"+period]                    + [year+'1800'+dti, path+"WWW.txt"],
        ["WWZ_"+period]                    + [year+'1800'+dti, path+"WWZ.txt"],
        ["WZZ_"+period]                    + [year+'1800'+dti, path+"WZZ.txt"],
        ["ZZZ_"+period]                    + [year+'1800'+dti, path+"ZZZ.txt"],
        ["ZH_Hto2B_Zto2L_"+period]         + [year+'1800'+dti, path+"ZH_Hto2B_Zto2L.txt"],
        ["ZH_Hto2B_Zto2Q_"+period]         + [year+'1800'+dti, path+"ZH_Hto2B_Zto2Q.txt"],
        ["ZH_Hto2C_Zto2L_"+period]         + [year+'1800'+dti, path+"ZH_Hto2C_Zto2L.txt"],
        ["ZH_Hto2C_Zto2Q_"+period]         + [year+'1800'+dti, path+"ZH_Hto2C_Zto2Q.txt"],
        ["ZHtoInv_Zto2Q_"+period]          + [year+'1800'+dti, path+"ZHtoInv_Zto2Q.txt"],
    ]    

    ST = [
        ["TQbarto2Q-t-channel_"+period]      + [year+'1800'+dti, path+"TQbarto2Q-t-channel.txt"],
        ["TbarQto2Q-t-channel_"+period]      + [year+'1800'+dti, path+"TbarQto2Q-t-channel.txt"],
        ["TQbartoLNu-t-channel_"+period]     + [year+'1800'+dti, path+"TQbartoLNu-t-channel.txt"],
        ["TbarQtoLNu-t-channel_"+period]     + [year+'1800'+dti, path+"TbarQtoLNu-t-channel.txt"],
        ["TbarWplusto2L2Nu_"+period]         + [year+'1800'+dti, path+"TbarWplusto2L2Nu.txt"],
        ["TWminusto2L2Nu_"+period]           + [year+'1800'+dti, path+"TWminusto2L2Nu.txt"],
        ["TWminusto4Q_"+period]              + [year+'1800'+dti, path+"TWminusto4Q.txt"],
        ["TWminustoLNu2Q_"+period]           + [year+'1800'+dti, path+"TWminustoLNu2Q.txt"],
        ["TbarWplusto4Q_"+period]            + [year+'1800'+dti, path+"TbarWplusto4Q.txt"],
        ["TbarWplustoLNu2Q_"+period]         + [year+'1800'+dti, path+"TbarWplustoLNu2Q.txt"],
    ]

    Bkg_4b = [
        ["QCD_PT-15to30_"+period]          + [year+'1800'+dti, path+"QCD_PT-15to30.txt"],
        ["QCD_PT-30to50_"+period]          + [year+'1802'+dti, path+"QCD_PT-30to50.txt"],
        ["QCD_PT-50to80_"+period]          + [year+'1803'+dti, path+"QCD_PT-50to80.txt"],
        ["QCD_PT-80to120_"+period]         + [year+'1804'+dti, path+"QCD_PT-80to120.txt"],
        ["QCD_PT-120to170_"+period]        + [year+'1805'+dti, path+"QCD_PT-120to170.txt"],
        ["QCD_PT-170to300_"+period]        + [year+'1806'+dti, path+"QCD_PT-170to300.txt"],
        ["QCD_PT-300to470_"+period]        + [year+'1807'+dti, path+"QCD_PT-300to470.txt"],
        ["QCD_PT-470to600_"+period]        + [year+'1808'+dti, path+"QCD_PT-470to600.txt"],
        ["QCD_PT-600to800_"+period]        + [year+'1809'+dti, path+"QCD_PT-600to800.txt"],
        ["QCD_PT-800to1000_"+period]       + [year+'1810'+dti, path+"QCD_PT-800to1000.txt"],
        ["QCD_PT-1000to1400_"+period]      + [year+'1811'+dti, path+"QCD_PT-1000to1400.txt"],
        ["QCD_PT-1400to1800_"+period]      + [year+'1812'+dti, path+"QCD_PT-1400to1800.txt"],
        ["QCD_PT-1800to2400_"+period]      + [year+'1813'+dti, path+"QCD_PT-1800to2400.txt"],
        ["QCD_PT-2400to3200_"+period]      + [year+'1814'+dti, path+"QCD_PT-2400to3200.txt"],
        ["QCD_PT-3200_"+period]            + [year+'1814'+dti, path+"QCD_PT-3200.txt"],
        # ["QCD_PT-3200toInf_"+period]       + [year+'1815'+dti, path+"QCD_PT-3200toInf.txt"],
        ["ttHto2B_"+period]                + [year+'1815'+dti, path+"ttHto2B.txt"],
        ["ttHto2C_"+period]                + [year+'1815'+dti, path+"ttHto2C.txt"],
    ]

    Wto2Q = [
        ["Wto2Q_PTQQ-100to200_1J_"+period]     + [year+'1800'+dti, path+"Wto2Q_PTQQ-100to200_1J.txt"],
        ["Wto2Q_PTQQ-100to200_2J_"+period]     + [year+'1800'+dti, path+"Wto2Q_PTQQ-100to200_2J.txt"],
        ["Wto2Q_PTQQ-200to400_1J_"+period]     + [year+'1800'+dti, path+"Wto2Q_PTQQ-200to400_1J.txt"],
        ["Wto2Q_PTQQ-200to400_2J_"+period]     + [year+'1800'+dti, path+"Wto2Q_PTQQ-200to400_2J.txt"],
        ["Wto2Q_PTQQ-400to600_1J_"+period]     + [year+'1800'+dti, path+"Wto2Q_PTQQ-400to600_1J.txt"],
        ["Wto2Q_PTQQ-400to600_2J_"+period]     + [year+'1800'+dti, path+"Wto2Q_PTQQ-400to600_2J.txt"],
        ["Wto2Q_PTQQ-600_1J_"+period]          + [year+'1800'+dti, path+"Wto2Q_PTQQ-600_1J.txt"],
        ["Wto2Q_PTQQ-600_2J_"+period]          + [year+'1800'+dti, path+"Wto2Q_PTQQ-600_2J.txt"],
    ]

    WtoLNu = [
        ["WtoLNu_PTLNu-100to200_1J_"+period]   + [year+'1800'+dti, path+"WtoLNu_PTLNu-100to200_1J.txt"],
        ["WtoLNu_PTLNu-100to200_2J_"+period]   + [year+'1800'+dti, path+"WtoLNu_PTLNu-100to200_2J.txt"],
        ["WtoLNu_PTLNu-200to400_1J_"+period]   + [year+'1800'+dti, path+"WtoLNu_PTLNu-200to400_1J.txt"],
        ["WtoLNu_PTLNu-200to400_2J_"+period]   + [year+'1800'+dti, path+"WtoLNu_PTLNu-200to400_2J.txt"],
        ["WtoLNu_PTLNu-400to600_1J_"+period]   + [year+'1800'+dti, path+"WtoLNu_PTLNu-400to600_1J.txt"],
        ["WtoLNu_PTLNu-400to600_2J_"+period]   + [year+'1800'+dti, path+"WtoLNu_PTLNu-400to600_2J.txt"],
        ["WtoLNu_PTLNu-40to100_1J_"+period]    + [year+'1800'+dti, path+"WtoLNu_PTLNu-40to100_1J.txt"],
        ["WtoLNu_PTLNu-40to100_2J_"+period]    + [year+'1800'+dti, path+"WtoLNu_PTLNu-40to100_2J.txt"],
        ["WtoLNu_PTLNu-600_1J_"+period]        + [year+'1800'+dti, path+"WtoLNu_PTLNu-600_1J.txt"],
        ["WtoLNu_PTLNu-600_2J_"+period]        + [year+'1800'+dti, path+"WtoLNu_PTLNu-600_2J.txt"],
    ]

    VZ = [
        ["WWto4Q_"+period]     + [year+'1800'+dti, path+"WWto4Q.txt"],
        ["WWtoLNu2Q_"+period]     + [year+'1800'+dti, path+"WWtoLNu2Q.txt"],
        ["WZto2L2Q_"+period]     + [year+'1800'+dti, path+"WZto2L2Q.txt"],
        ["WZto3LNu_"+period]     + [year+'1800'+dti, path+"WZto3LNu.txt"],
        ["WZtoLNu2Q_"+period]    + [year+'1800'+dti, path+"WZtoLNu2Q.txt"],
        ["ZZto2L2Nu_"+period]    + [year+'1800'+dti, path+"ZZto2L2Nu.txt"],
        ["ZZto2L2Q_"+period]     + [year+'1800'+dti, path+"ZZto2L2Q.txt"],
        ["ZZto2Nu2Q_"+period]    + [year+'1800'+dti, path+"ZZto2Nu2Q.txt"],  
    ]

    Zto2Nu = [
        ["Zto2Nu_PTNuNu-100to200_1J_"+period]   + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-100to200_1J.txt"],
        ["Zto2Nu_PTNuNu-100to200_2J_"+period]   + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-100to200_2J.txt"],
        ["Zto2Nu_PTNuNu-200to400_2J_"+period]   + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-200to400_2J.txt"],
        ["Zto2Nu_PTNuNu-200to400_"+period]      + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-200to400.txt"],
        ["Zto2Nu_PTNuNu-400to600_1J_"+period]   + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-400to600_1J.txt"],
        ["Zto2Nu_PTNuNu-400to600_2J_"+period]   + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-400to600_2J.txt"],
        ["Zto2Nu_PTNuNu-40to100_1J_"+period]    + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-40to100_1J.txt"],
        ["Zto2Nu_PTNuNu-40to100_2J_"+period]    + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-40to100_2J.txt"],
        ["Zto2Nu_PTNuNu-600_1J_"+period]        + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-600_1J.txt"],
        ["Zto2Nu_PTNuNu-600_2J_"+period]        + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-600_2J.txt"],
    ]    
    
    Zto2Q = [
        ["Zto2Q_PTQQ-100to200_1J_"+period]    + [year+'1800'+dti, path+"Zto2Q_PTQQ-100to200_1J.txt"],
        ["Zto2Q_PTQQ-100to200_2J_"+period]    + [year+'1800'+dti, path+"Zto2Q_PTQQ-100to200_2J.txt"],
        ["Zto2Q_PTQQ-200to400_1J_"+period]    + [year+'1800'+dti, path+"Zto2Q_PTQQ-200to400_1J.txt"],
        ["Zto2Q_PTQQ-200to400_2J_"+period]    + [year+'1800'+dti, path+"Zto2Q_PTQQ-200to400_2J.txt"],
        ["Zto2Q_PTQQ-400to600_1J_"+period]    + [year+'1800'+dti, path+"Zto2Q_PTQQ-400to600_1J.txt"],
        ["Zto2Q_PTQQ-400to600_2J_"+period]    + [year+'1800'+dti, path+"Zto2Q_PTQQ-400to600_2J.txt"],
        ["Zto2Q_PTQQ-600_1J_"+period]         + [year+'1800'+dti, path+"Zto2Q_PTQQ-600_1J.txt"],
        ["Zto2Q_PTQQ-600_2J_"+period]         + [year+'1800'+dti, path+"Zto2Q_PTQQ-600_2J.txt"],
    ]

    if period == "0_22":
        Bkg_4b_0_22 = Bkg_4b
        ResidualSM_0_22 = ResidualSM
        TT_0_22 = TT
        Wto2Q_0_22 = Wto2Q
        WtoLNu_0_22 = WtoLNu
        VZ_0_22 = VZ
        Zto2Nu_0_22 = Zto2Nu
        Zto2Q_0_22 = Zto2Q
        ST_0_22 = ST
        DY_0_22 = DY
    elif period == "1_22":
        Bkg_4b_1_22 = Bkg_4b
        ResidualSM_1_22 = ResidualSM
        TT_1_22 = TT
        Wto2Q_1_22 = Wto2Q
        WtoLNu_1_22 = WtoLNu
        VZ_1_22 = VZ
        Zto2Nu_1_22 = Zto2Nu
        Zto2Q_1_22 = Zto2Q
        ST_1_22 = ST
        DY_1_22 = DY
    elif period == "0_23":
        Bkg_4b_0_23 = Bkg_4b
        ResidualSM_0_23 = ResidualSM
        TT_0_23 = TT
        Wto2Q_0_23 = Wto2Q
        WtoLNu_0_23 = WtoLNu
        VZ_0_23 = VZ
        Zto2Nu_0_23 = Zto2Nu
        Zto2Q_0_23 = Zto2Q
        ST_0_23 = ST
        DY_0_23 = DY
    elif period == "1_23":
        Bkg_4b_1_23 = Bkg_4b
        ResidualSM_1_23 = ResidualSM
        TT_1_23 = TT
        Wto2Q_1_23 = Wto2Q
        WtoLNu_1_23 = WtoLNu
        VZ_1_23 = VZ
        Zto2Nu_1_23 = Zto2Nu
        Zto2Q_1_23 = Zto2Q
        ST_1_23 = ST
        DY_1_23 = DY

