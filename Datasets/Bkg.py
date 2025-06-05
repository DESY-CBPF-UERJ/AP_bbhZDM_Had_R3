analysis = "AP_bbhZDM_Had_R3"
nano_version = 'v12'

#--------------------------------------------------------------------------------------------------
# Production ID:
# 00-09(Data), 10-19(MC-signal), 20-98(MC-bkg), 99(private sample)
#
# Data taking interval (DTI):
# 2022 DTIs = 0(preEE), 1(postEE)
# 2023 DTIs = 0(preBPix), 1(postBPix)
#--------------------------------------------------------------------------------------------------

paths = {}
paths["0_22"] = analysis+'/Datasets/Files/bkg_22/dti_0/'+nano_version+'/'
paths["1_22"] = analysis+'/Datasets/Files/bkg_22/dti_1/'+nano_version+'/'
paths["0_23"] = analysis+'/Datasets/Files/bkg_23/dti_0/'+nano_version+'/'
paths["1_23"] = analysis+'/Datasets/Files/bkg_23/dti_1/'+nano_version+'/'


b_ds = {}
for period in paths.keys():

    year = period[-2:]
    dti = period[0]

    b_ds_info = {
    "DY": [
        ["DYto2E_MLL-10to50",               '20',       6744,                1.132,             'NLO'],
        ["DYto2E_MLL-50to120",              '20',       2219,                0.2327,            'NLO'],
        ["DYto2E_MLL-120to200",             '20',       21.65,               0.003184,          'NLO'],
        ["DYto2E_MLL-200to400",             '20',       3.058,               0.000465,          'NLO'],
        ["DYto2E_MLL-400to800",             '20',       0.2691,              0.00004215,        'NLO'],
        ["DYto2E_MLL-800to1500",            '20',       0.01915,             0.000003085,       'NLO'],
        ["DYto2E_MLL-1500to2500",           '20',       0.001111,            1.787e-7,          'NLO'],
        ["DYto2E_MLL-2500to4000",           '20',       0.00005949,          9.162e-9,          'NLO'],
        ["DYto2E_MLL-4000to6000",           '20',       0.000001558,         2.078e-10,         'NLO'],
        ["DYto2E_MLL-6000",                 '20',       3.519e-8,            6.811e-12,         'NLO'],
        ["DYto2Mu_MLL-10to50",              '21',       6744,                1.132,             'NLO'],
        ["DYto2Mu_MLL-50to120",             '21',       2219,                0.2327,            'NLO'],
        ["DYto2Mu_MLL-120to200",            '21',       21.65,               0.003184,          'NLO'],
        ["DYto2Mu_MLL-200to400",            '21',       3.058,               0.000465,          'NLO'],
        ["DYto2Mu_MLL-400to800",            '21',       0.2691,              0.00004215,        'NLO'],
        ["DYto2Mu_MLL-800to1500",           '21',       0.01915,             0.000003085,       'NLO'],
        ["DYto2Mu_MLL-1500to2500",          '21',       0.001111,            1.787e-7,          'NLO'],
        ["DYto2Mu_MLL-2500to4000",          '21',       0.00005949,          9.162e-9,          'NLO'],
        ["DYto2Mu_MLL-4000to6000",          '21',       0.000001558,         2.078e-10,         'NLO'],
        ["DYto2Mu_MLL-6000",                '21',       3.519e-8,            6.811e-12,         'NLO'],
        ["DYto2Tau_MLL-10to50",             '22',       6744,                1.132,             'NLO'],
        ["DYto2Tau_MLL-50to120",            '22',       2219,                0.2327,            'NLO'],
        ["DYto2Tau_MLL-120to200",           '22',       21.65,               0.003184,          'NLO'],
        ["DYto2Tau_MLL-200to400",           '22',       3.058,               0.000465,          'NLO'],
        ["DYto2Tau_MLL-400to800",           '22',       0.2691,              0.00004215,        'NLO'],
        ["DYto2Tau_MLL-800to1500",          '22',       0.01915,             0.000003085,       'NLO'],
        ["DYto2Tau_MLL-1500to2500",         '22',       0.001111,            1.787e-7,          'NLO'],
        ["DYto2Tau_MLL-2500to4000",         '22',       0.00005949,          9.162e-9,          'NLO'],
        ["DYto2Tau_MLL-4000to6000",         '22',       0.000001558,         2.078e-10,         'NLO'],
        ["DYto2Tau_MLL-6000",               '22',       3.519e-8,            6.811e-12,         'NLO'],
    ],

    "TT": [
        ["TTtoLNu2Q",                       '23',       405.7,              0.1345,		        'NLO'],
        ["TTto2L2Nu",                       '23',       98.04,              0.1345,             'NLO'],
    ],

    "ST": [
        ["TQbartoLNu-t-channel",            '24',       130,                 0.07514,           'NLO'],
        ["TbarQtoLNu-t-channel",            '24',       78.56,               0.04092,           'NLO'],
        ["TbarWplusto2L2Nu",                '24',       36.05,               0.01296,           'NLO'],
        ["TWminusto2L2Nu",                  '24',       35.99,               0.01292,           'NLO'],
        ["TWminustoLNu2Q",                  '24',       35.99,               0.01292,           'NLO'],
        ["TbarWplustoLNu2Q",                '24',       36.05,               0.01296,           'NLO'],
    ],

    "QCD": [
        ["QCD_PT-15to30",                   '25',       1301000000,        	2135000,	        'LO'],
        ["QCD_PT-30to50",                   '25',       113300000.0,	    589300.0,		    'unknown'],
        ["QCD_PT-50to80",                   '25',       16760000,	        27450,		        'LO'],
        ["QCD_PT-80to120",                  '25',       2534000.0,	        13280.0,		    'unknown'],
        ["QCD_PT-120to170",                 '25',       445800.0,	        2174.0,		        'unknown'],
        ["QCD_PT-170to300",                 '25',       113700.0,        	547.6,		        'unknown'],
        ["QCD_PT-300to470",                 '25',       7559.0,      	    36.67,		        'unknown'],
        ["QCD_PT-470to600",                 '25',       626.4,	            2.863,		        'unknown'],
        ["QCD_PT-600to800",                 '25',       178.6,           	0.8268,		        'unknown'],
        ["QCD_PT-800to1000",                '25',       30.57,	            0.1405,		        'unknown'],
        ["QCD_PT-1000to1400",               '25',       8.92,	            0.04204,		    'unknown'],
        ["QCD_PT-1400to1800",               '25',       0.8103,          	0.003798,	    	'unknown'],
        ["QCD_PT-1800to2400",               '25',       0.1148,	            0.0005556,	    	'unknown'],
        ["QCD_PT-2400to3200",               '25',       0.007542,	        3.779e-05,	    	'unknown'],
        ["QCD_PT-3200",                     '25',       0.0002331,	        1.208e-06,		    'unknown'],
    ],

    "Zto2Nu": [
        ["Zto2Nu_PTNuNu-40to100_1J",        '26',       929.8,	            5.481,		        'LO'],
        ["Zto2Nu_PTNuNu-40to100_2J",        '26',       335.5,	            3.49,		        'LO'],
        ["Zto2Nu_PTNuNu-100to200_1J",       '26',       86.38,	            0.441,		        'LO'],
        ["Zto2Nu_PTNuNu-100to200_2J",       '26',       100.4,	            0.8555,		        'LO'],
        ["Zto2Nu_PTNuNu-200to400_1J",       '26',       6.354,	            0.03067,		    'LO'],
        ["Zto2Nu_PTNuNu-200to400_2J",       '26',       13.86,	            0.09802,		    'LO'],
        ["Zto2Nu_PTNuNu-400to600_1J",       '26',       0.2188,	            0.0009573,		    'LO'],
        ["Zto2Nu_PTNuNu-400to600_2J",       '26',       0.7816,	            0.005088,		    'LO'],
        ["Zto2Nu_PTNuNu-600_1J",            '26',       0.02583,	        0.000108,		    'LO'],
        ["Zto2Nu_PTNuNu-600_2J",            '26',       0.1311,	            0.0007098,		    'LO'],
    ],

    "WtoLNu": [
        ["WtoLNu_PTLNu-40to100_1J",         '27',       4427,	            28.3,		        'LO'],
        ["WtoLNu_PTLNu-40to100_2J",         '27',       1598,	            16.36,		        'LO'],
        ["WtoLNu_PTLNu-100to200_1J",        '27',       368.2,	            1.926,		        'LO'],
        ["WtoLNu_PTLNu-100to200_2J",        '27',       421.9,	            3.533,		        'LO'],
        ["WtoLNu_PTLNu-200to400_1J",        '27',       25.6,	            0.1207,		        'LO'],
        ["WtoLNu_PTLNu-200to400_2J",        '27',       54.77,	            0.3764,		        'LO'],
        ["WtoLNu_PTLNu-400to600_1J",        '27',       0.8785,	            0.003223,		    'LO'],
        ["WtoLNu_PTLNu-400to600_2J",        '27',       3.119,	            0.01749,		    'LO'],
        ["WtoLNu_PTLNu-600_1J",             '27',       0.1053,	            0.0003437,		    'LO'],
        ["WtoLNu_PTLNu-600_2J",             '27',       0.5261,	            0.002417,		    'LO'],
    ],

    "VV": [
        ["WWtoLNu2Q",                       '28',       48.94,	            0.0175,		        'NLO'],
        ["WZtoLNu2Q",                       '28',       15.87,           	0.007874,		    'NLO'],
        ["ZZto2Nu2Q",                       '28',       4.826,	            0.001296,		    'NLO'],
    ],

    "Vh": [
        ["WplusH_Hto2B_WtoLNu",             '29',       0.3001,	            3.337e-05,		    'NLO'],
        ["WplusH_Hto2C_WtoLNu",             '29',       0.3,             	0.000009736,		'NLO'],
        ["WminusH_Hto2B_WtoLNu",            '29',       0.1887,	            2.23e-05,		    'NLO'],
        ["WminusH_Hto2C_WtoLNu",            '29',       0.1887,	            0.000006691,		'NLO'],
        ["ZH_Hto2B_Zto2Nu",                 '29',       0.168,              0,                  'NLO'],
        ["ZH_Hto2C_Zto2Nu",                 '29',       0.168,              0,                  'NLO'],
        ["ZHto2Zto4Nu_Zto2Q",               '29',       0.5932,             0,                  'NLO'],
    ],

    "ResidualSM": [
        ["Zto2Q_PTQQ-100to200_1J",          '30',       302,	            1.493,		        'LO'],
        ["Zto2Q_PTQQ-100to200_2J",          '30',       343.9,	            2.979,		        'LO'],
        ["Zto2Q_PTQQ-200to400_1J",          '30',       21.64,	            0.1029,		        'LO'],
        ["Zto2Q_PTQQ-200to400_2J",          '30',       48.36,	            0.375,		        'LO'],
        ["Zto2Q_PTQQ-400to600_1J",          '30',       0.7376,	            0.003183,		    'LO'],
        ["Zto2Q_PTQQ-400to600_2J",          '30',       2.683,	            0.01553,		    'LO'],
        ["Zto2Q_PTQQ-600_1J",               '30',       0.08717,	        0.0003566,		    'LO'],
        ["Zto2Q_PTQQ-600_2J",               '30',       0.4459,	            0.002084,		    'LO'],
        ["Wto2Q_PTQQ-100to200_1J",          '30',       1517,	            7.518,		        'LO'],
        ["Wto2Q_PTQQ-100to200_2J",          '30',       1757,	            14.55,		        'LO'],
        ["Wto2Q_PTQQ-200to400_1J",          '30',       103.6,	            0.4359,		        'LO'],
        ["Wto2Q_PTQQ-200to400_2J",          '30',       227.1,	            1.729,		        'LO'],
        ["Wto2Q_PTQQ-400to600_1J",          '30',       3.496,	            0.01291,		    'LO'],
        ["Wto2Q_PTQQ-400to600_2J",          '30',       12.75,	            0.07947,		    'LO'],
        ["Wto2Q_PTQQ-600_1J",               '30',       0.4221,	            0.001474,		    'LO'],
        ["Wto2Q_PTQQ-600_2J",               '30',       2.128,	            0.009921,		    'LO'],
        ["WplusH_Hto2B_Wto2Q",              '30',       0.623,	            0.0001441,		    'NLO'],
        ["WplusH_Hto2C_Wto2Q",              '30',       0.6225,	            0.00002623,		    'NLO'],
        ["WminusH_Hto2B_Wto2Q",             '30',       0.3916,	            5.798e-05,		    'NLO'],
        ["WminusH_Hto2C_Wto2Q",             '30',       0.3918,	            0.00001408,		    'NLO'],
        ["ZH_Hto2B_Zto2L",                  '30',       0.08545,	        0.0002143,		    'NLO'],
        ["ZH_Hto2B_Zto2Q",                  '30',       0.5958,         	0.0006178,		    'NLO'],
        ["ZH_Hto2C_Zto2L",                  '30',       0.08545,	        0.0001515,		    'NLO'],
        ["ZH_Hto2C_Zto2Q",                  '30',       0.5958,	            0.0004369,		    'NLO'],
        ["WWto4Q",                          '30',       50.79,	            0.01816,		    'NLO'],
        ["WZto2L2Q",                        '30',       7.568,	            0.003908,		    'NLO'],
        ["WZto3LNu",                        '30',       4.924,	            0.00237,		    'NLO'],
        ["ZZto2L2Nu",                       '30',       1.031,	            0.0005268,		    'NLO'],
        ["ZZto2L2Q",                        '30',       6.788,	            0.003501,		    'NLO'],
        ["TbarWplusto4Q",                   '30',       36.05,              0.01296,            'NLO'],
        ["TWminusto4Q",                     '30',       35.99,	            0.01292,		    'NLO'],
        ["TQbarto2Q-t-channel",             '30',       130,                0.07514,            'NLO'],
        ["TbarQto2Q-t-channel",             '30',       78.56,              0.04092,            'NLO'],
        ["TTto4Q",                          '30',       419.7,	            0.1345,	        	'NLO'],
        ["WWW",                             '30',       0.2328,	            0.0001247,		    'LO'],
        ["WWZ",                             '30',       0.1851,	            9.482e-05,		    'unknown'],
        ["WZZ",                             '30',       0.06206,	        3.689e-05,		    'unknown'],
        ["ZZZ",                             '30',       0.01591,	        7.828e-06,		    'unknown'],
        ["ttHto2B",                         '30',       0.5742,	            0.009052,		    'NLO'],
        ["ttHto2C",                         '30',       0.5742,	            0.009052,		    'NLO'],
    ],
    }


    for key in b_ds_info.keys():
        b_ds[key+"_"+period] = []
        for ds in b_ds_info[key]:
            list_temp = []
            list_temp.append(ds[0]+"_"+period)
            list_temp.append(ds[1]+year+dti)
            list_temp.append(paths[period]+ds[0]+".txt")
            b_ds[key+"_"+period].append(list_temp)
    del b_ds_info

    """
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
        ["TTtoLNu2Q_"+period]       + [year+'1800'+dti, path+"TTtoLNu2Q.txt"],    # TT To SemiLeptonic
        ["TTto2L2Nu_"+period]       + [year+'0300'+dti, path+"TTto2L2Nu.txt"],    # TT To fullyLeptonic
    ]

    ResidualSM = [
        ["Zto2Q_PTQQ-100to200_1J_"+period]    + [year+'1800'+dti, path+"Zto2Q_PTQQ-100to200_1J.txt"],
        ["Zto2Q_PTQQ-100to200_2J_"+period]    + [year+'1800'+dti, path+"Zto2Q_PTQQ-100to200_2J.txt"],
        ["Zto2Q_PTQQ-200to400_1J_"+period]    + [year+'1800'+dti, path+"Zto2Q_PTQQ-200to400_1J.txt"],
        ["Zto2Q_PTQQ-200to400_2J_"+period]    + [year+'1800'+dti, path+"Zto2Q_PTQQ-200to400_2J.txt"],
        ["Zto2Q_PTQQ-400to600_1J_"+period]    + [year+'1800'+dti, path+"Zto2Q_PTQQ-400to600_1J.txt"],
        ["Zto2Q_PTQQ-400to600_2J_"+period]    + [year+'1800'+dti, path+"Zto2Q_PTQQ-400to600_2J.txt"],
        ["Zto2Q_PTQQ-600_1J_"+period]         + [year+'1800'+dti, path+"Zto2Q_PTQQ-600_1J.txt"],
        ["Zto2Q_PTQQ-600_2J_"+period]         + [year+'1800'+dti, path+"Zto2Q_PTQQ-600_2J.txt"],
        ["Wto2Q_PTQQ-100to200_1J_"+period]     + [year+'1800'+dti, path+"Wto2Q_PTQQ-100to200_1J.txt"],
        ["Wto2Q_PTQQ-100to200_2J_"+period]     + [year+'1800'+dti, path+"Wto2Q_PTQQ-100to200_2J.txt"],
        ["Wto2Q_PTQQ-200to400_1J_"+period]     + [year+'1800'+dti, path+"Wto2Q_PTQQ-200to400_1J.txt"],
        ["Wto2Q_PTQQ-200to400_2J_"+period]     + [year+'1800'+dti, path+"Wto2Q_PTQQ-200to400_2J.txt"],
        ["Wto2Q_PTQQ-400to600_1J_"+period]     + [year+'1800'+dti, path+"Wto2Q_PTQQ-400to600_1J.txt"],
        ["Wto2Q_PTQQ-400to600_2J_"+period]     + [year+'1800'+dti, path+"Wto2Q_PTQQ-400to600_2J.txt"],
        ["Wto2Q_PTQQ-600_1J_"+period]          + [year+'1800'+dti, path+"Wto2Q_PTQQ-600_1J.txt"],
        ["Wto2Q_PTQQ-600_2J_"+period]          + [year+'1800'+dti, path+"Wto2Q_PTQQ-600_2J.txt"],
        ["WplusH_Hto2B_Wto2Q_"+period]     + [year+'1800'+dti, path+"WplusH_Hto2B_Wto2Q.txt"],
        ["WplusH_Hto2C_Wto2Q_"+period]     + [year+'1800'+dti, path+"WplusH_Hto2C_Wto2Q.txt"],
        ["WminusH_Hto2B_Wto2Q_"+period]    + [year+'1800'+dti, path+"WminusH_Hto2B_Wto2Q.txt"],
        ["WminusH_Hto2C_Wto2Q_"+period]    + [year+'1800'+dti, path+"WminusH_Hto2C_Wto2Q.txt"],
        ["ZH_Hto2B_Zto2L_"+period]         + [year+'1800'+dti, path+"ZH_Hto2B_Zto2L.txt"],
        ["ZH_Hto2B_Zto2Q_"+period]         + [year+'1800'+dti, path+"ZH_Hto2B_Zto2Q.txt"],
        ["ZH_Hto2C_Zto2L_"+period]         + [year+'1800'+dti, path+"ZH_Hto2C_Zto2L.txt"],
        ["ZH_Hto2C_Zto2Q_"+period]         + [year+'1800'+dti, path+"ZH_Hto2C_Zto2Q.txt"],
        ["WWto4Q_"+period]     + [year+'1800'+dti, path+"WWto4Q.txt"],
        ["WZto2L2Q_"+period]     + [year+'1800'+dti, path+"WZto2L2Q.txt"],
        ["WZto3LNu_"+period]     + [year+'1800'+dti, path+"WZto3LNu.txt"],
        ["ZZto2L2Nu_"+period]    + [year+'1800'+dti, path+"ZZto2L2Nu.txt"],
        ["ZZto2L2Q_"+period]     + [year+'1800'+dti, path+"ZZto2L2Q.txt"],
        ["TbarWplusto4Q_"+period]            + [year+'1800'+dti, path+"TbarWplusto4Q.txt"],
        ["TWminusto4Q_"+period]              + [year+'1800'+dti, path+"TWminusto4Q.txt"],
        ["TQbarto2Q-t-channel_"+period]      + [year+'1800'+dti, path+"TQbarto2Q-t-channel.txt"],
        ["TbarQto2Q-t-channel_"+period]      + [year+'1800'+dti, path+"TbarQto2Q-t-channel.txt"],
        ["TTto4Q_"+period]          + [year+'1800'+dti, path+"TTto4Q.txt"],       # TT To Hadronic
        ["WWW_"+period]                    + [year+'1800'+dti, path+"WWW.txt"],
        ["WWZ_"+period]                    + [year+'1800'+dti, path+"WWZ.txt"],
        ["WZZ_"+period]                    + [year+'1800'+dti, path+"WZZ.txt"],
        ["ZZZ_"+period]                    + [year+'1800'+dti, path+"ZZZ.txt"],
        ["ttHto2B_"+period]                + [year+'1815'+dti, path+"ttHto2B.txt"],
        ["ttHto2C_"+period]                + [year+'1815'+dti, path+"ttHto2C.txt"],
    ]    

    ST = [
        ["TQbartoLNu-t-channel_"+period]     + [year+'1800'+dti, path+"TQbartoLNu-t-channel.txt"],
        ["TbarQtoLNu-t-channel_"+period]     + [year+'1800'+dti, path+"TbarQtoLNu-t-channel.txt"],
        ["TbarWplusto2L2Nu_"+period]         + [year+'1800'+dti, path+"TbarWplusto2L2Nu.txt"],
        ["TWminusto2L2Nu_"+period]           + [year+'1800'+dti, path+"TWminusto2L2Nu.txt"],
        ["TWminustoLNu2Q_"+period]           + [year+'1800'+dti, path+"TWminustoLNu2Q.txt"],
        ["TbarWplustoLNu2Q_"+period]         + [year+'1800'+dti, path+"TbarWplustoLNu2Q.txt"],
    ]

    QCD = [
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

    VV = [
        ["WWtoLNu2Q_"+period]     + [year+'1800'+dti, path+"WWtoLNu2Q.txt"],
        ["WZtoLNu2Q_"+period]    + [year+'1800'+dti, path+"WZtoLNu2Q.txt"],
        ["ZZto2Nu2Q_"+period]    + [year+'1800'+dti, path+"ZZto2Nu2Q.txt"],  
    ]

    Vh = [
        ["WplusH_Hto2B_WtoLNu_"+period]    + [year+'1800'+dti, path+"WplusH_Hto2B_WtoLNu.txt"],
        ["WplusH_Hto2C_WtoLNu_"+period]    + [year+'1800'+dti, path+"WplusH_Hto2C_WtoLNu.txt"],
        ["WminusH_Hto2B_WtoLNu_"+period]   + [year+'1800'+dti, path+"WminusH_Hto2B_WtoLNu.txt"],
        ["WminusH_Hto2C_WtoLNu_"+period]   + [year+'1800'+dti, path+"WminusH_Hto2C_WtoLNu.txt"],
        ["ZH_Hto2B_Zto2Nu_"+period]        + [year+'1800'+dti, path+"ZH_Hto2B_Zto2Nu.txt"],
        ["ZH_Hto2C_Zto2Nu_"+period]        + [year+'1800'+dti, path+"ZH_Hto2C_Zto2Nu.txt"],
        ["ZHto2Zto4Nu_Zto2Q_"+period]      + [year+'1800'+dti, path+"ZHto2Zto4Nu_Zto2Q.txt"],
    ]

    Zto2Nu = [
        ["Zto2Nu_PTNuNu-100to200_1J_"+period]   + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-100to200_1J.txt"],
        ["Zto2Nu_PTNuNu-100to200_2J_"+period]   + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-100to200_2J.txt"],
        ["Zto2Nu_PTNuNu-200to400_1J_"+period]   + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-200to400_1J.txt"],
        ["Zto2Nu_PTNuNu-200to400_2J_"+period]   + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-200to400_2J.txt"],
        ["Zto2Nu_PTNuNu-400to600_1J_"+period]   + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-400to600_1J.txt"],
        ["Zto2Nu_PTNuNu-400to600_2J_"+period]   + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-400to600_2J.txt"],
        ["Zto2Nu_PTNuNu-40to100_1J_"+period]    + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-40to100_1J.txt"],
        ["Zto2Nu_PTNuNu-40to100_2J_"+period]    + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-40to100_2J.txt"],
        ["Zto2Nu_PTNuNu-600_1J_"+period]        + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-600_1J.txt"],
        ["Zto2Nu_PTNuNu-600_2J_"+period]        + [year+'1800'+dti, path+"Zto2Nu_PTNuNu-600_2J.txt"],
    ]    

    if period == "0_22":
        QCD_0_22 = QCD
        ResidualSM_0_22 = ResidualSM
        TT_0_22 = TT
        WtoLNu_0_22 = WtoLNu
        VV_0_22 = VV
        Vh_0_22 = Vh
        Zto2Nu_0_22 = Zto2Nu
        ST_0_22 = ST
        DY_0_22 = DY
    elif period == "1_22":
        QCD_1_22 = QCD
        ResidualSM_1_22 = ResidualSM
        TT_1_22 = TT
        WtoLNu_1_22 = WtoLNu
        VV_1_22 = VV
        Vh_1_22 = Vh
        Zto2Nu_1_22 = Zto2Nu
        ST_1_22 = ST
        DY_1_22 = DY
    elif period == "0_23":
        QCD_0_23 = QCD
        ResidualSM_0_23 = ResidualSM
        TT_0_23 = TT
        WtoLNu_0_23 = WtoLNu
        VV_0_23 = VV
        Vh_0_23 = Vh
        Zto2Nu_0_23 = Zto2Nu
        ST_0_23 = ST
        DY_0_23 = DY
    elif period == "1_23":
        QCD_1_23 = QCD
        ResidualSM_1_23 = ResidualSM
        TT_1_23 = TT
        WtoLNu_1_23 = WtoLNu
        VV_1_23 = VV
        Vh_1_23 = Vh
        Zto2Nu_1_23 = Zto2Nu
        ST_1_23 = ST
        DY_1_23 = DY
    """

