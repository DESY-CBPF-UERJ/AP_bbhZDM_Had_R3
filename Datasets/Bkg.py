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
paths["0_24"] = analysis+'/Datasets/Files/bkg_24/dti_0/v15/'


# https://xsecdb-xsdb-official.app.cern.ch/
# https://twiki.cern.ch/twiki/bin/view/LHCPhysics/CERNYellowReportPageAt13TeV (Higgs)
b_ds_info = { # [DatasetName, Production ID, PROC_XSEC[pb], XSEC_UNC[pb], XSEC_Accuracy]
"DY": [

    ["DYto2L-2Jets_1J_PTLL-40to100",   '20',  XSEC,   KFACT,   'NLO'],
    ["DYto2L-2Jets_1J_PTLL-100to200",  '20',  XSEC,   KFACT,   'NLO'],
    ["DYto2L-2Jets_1J_PTLL-200to400",  '20',  XSEC,   KFACT,   'NLO'],
    ["DYto2L-2Jets_1J_PTLL-400to600",  '20',  XSEC,   KFACT,   'NLO'],
    ["DYto2L-2Jets_1J_PTLL-600",       '20',  XSEC,   KFACT,   'NLO'],

    ["DYto2L-2Jets_2J_PTLL-40to100",   '20',  XSEC,   KFACT,   'NLO'],
    ["DYto2L-2Jets_2J_PTLL-100to200",  '20',  XSEC,   KFACT,   'NLO'],
    ["DYto2L-2Jets_2J_PTLL-200to400",  '20',  XSEC,   KFACT,   'NLO'],
    ["DYto2L-2Jets_2J_PTLL-400to600",  '20',  XSEC,   KFACT,   'NLO'],
    ["DYto2L-2Jets_2J_PTLL-600",       '20',  XSEC,   KFACT,   'NLO'],
    
],

"TT": [
   # ["TTtoLNu2Q",                       '23',       405.7,              0.1345,		        'NLO'],
   # ["TTto2L2Nu",                       '23',       98.04,              0.1345,             'NLO'],
    ["TTtoLNu2Q",     '23',   762.1,     0.1345,   'NLO'],   # powheg
    ["TTto2L2Nu",     '23',   762.1,     0.1345,   'NLO'],   # powheg
],

"ST": [
    ["TBbarQtoLNu-t-channel",             '30',   38.6	,   0.1084,   'NLO'],   # powheg-madspin
    ["TbarBQtoLNu-t-channel",             '30',   23.34	,   0.05875,   'NLO'],   # powheg-madspin
    
    ["TbarWplusto2L2Nu",     '24',   36.05,     0.01296,   'NLO'],   # powheg
    ["TWminusto2L2Nu",       '24',   35.99,     0.01292,   'NLO'],   # powheg

    ["TWminustoLNu2Q",       '24',   35.99,     0.01292,   'NLO'],   # powheg

    ["TbarWplustoLNu2Q",     '24',   36.05,     0.01296,   'NLO'],   # powheg

    
   # ["TQbartoLNu-t-channel",            '24',       130,                 0.07514,           'NLO'], NÃO EXISTE
   # ["TbarQtoLNu-t-channel",            '24',       78.56,               0.04092,           'NLO'], NÃO EXISTE
   # ["TbarWplusto2L2Nu",                '24',       36.05,               0.01296,           'NLO'],
   # ["TWminusto2L2Nu",                  '24',       35.99,               0.01292,           'NLO'],
   # ["TWminustoLNu2Q",                  '24',       35.99,               0.01292,           'NLO'],
   # ["TbarWplustoLNu2Q",                '24',       36.05,               0.01296,           'NLO'],
],

"QCD": [

    ["QCD_PT-15to20",        '25',   885700000.0,     1481000.0,   'LO'],
    ["QCD_PT-20to30",        '25',   415700000.0,     689600.0,   'LO'],
    ["QCD_PT-30to50",        '25',   112300000.0,     222000.0,   'LO'],
    ["QCD_PT-50to80",        '25',   16730000.0,     27390.0,   'LO'],
    ["QCD_PT-80to120",       '25',   2506000.0,     4165.0,   'LO'],
    ["QCD_PT-120to170",      '25',   439800.0,     689.5,   'LO'],
    ["QCD_PT-170to300",      '25',   113300.0,     175.7,   'LO'],
    ["QCD_PT-300to470",      '25',   7581.0,     11.72,   'LO'],
    ["QCD_PT-470to600",      '25',   623.3,     0.9187,   'LO'],
    ["QCD_PT-600to800",      '25',   178.7,     0.265,   'LO'],
    ["QCD_PT-800to1000",     '25',   30.62,     0.04486,   'LO'],
    ["QCD_PT-1000to1500",    '25',   9.306,     0.01459,   'LO'],
    ["QCD_PT-1500to2000",    '25',   0.5015,     0.0007673,   'LO'],
    ["QCD_PT-2000to2500",    '25',   0.04264,     6.795e-05,   'LO'],
    ["QCD_PT-2500to3000",    '25',   0.004454,     7.22e-06,   'LO'],
    ["QCD_PT-3000",          '25',   0.0005539,     9.153e-07,   'LO'],

    
  #  ["QCD_PT-15to30",                   '25',       1301000000,        	2135000,	        'LO'],
  #  ["QCD_PT-30to50",                   '25',       113300000.0,	    589300.0,		    'unknown'],
  #  ["QCD_PT-50to80",                   '25',       16760000,	        27450,		        'LO'],
  #  ["QCD_PT-80to120",                  '25',       2534000.0,	        13280.0,		    'unknown'],
  #  ["QCD_PT-120to170",                 '25',       445800.0,	        2174.0,		        'unknown'],
  #  ["QCD_PT-170to300",                 '25',       113700.0,        	547.6,		        'unknown'],
  #  ["QCD_PT-300to470",                 '25',       7559.0,      	    36.67,		        'unknown'],
  #  ["QCD_PT-470to600",                 '25',       626.4,	            2.863,		        'unknown'],
  #  ["QCD_PT-600to800",                 '25',       178.6,           	0.8268,		        'unknown'],
  #  ["QCD_PT-800to1000",                '25',       30.57,	            0.1405,		        'unknown'],
  #  ["QCD_PT-1000to1400",               '25',       8.92,	            0.04204,		    'unknown'],
  #  ["QCD_PT-1400to1800",               '25',       0.8103,          	0.003798,	    	'unknown'],
  #  ["QCD_PT-1800to2400",               '25',       0.1148,	            0.0005556,	    	'unknown'],
  #  ["QCD_PT-2400to3200",               '25',       0.007542,	        3.779e-05,	    	'unknown'],
  #  ["QCD_PT-3200",                     '25',       0.0002331,	        1.208e-06,		    'unknown'],
],

"Zto2Nu": [
    ["Zto2Nu_PTNuNu-40to100_1J",    '26',   885.7,     5.991,   'NLO'],   # amcatnloFXFX
    ["Zto2Nu_PTNuNu-40to100_2J",    '26',   328.6,     3.458,   'NLO'],   # amcatnloFXFX

    ["Zto2Nu_PTNuNu-100to200_1J",   '26',   78.91,     0.4341,   'NLO'],   # amcatnloFXFX
    ["Zto2Nu_PTNuNu-100to200_2J",   '26',   100.2,     0.931,   'NLO'],   # amcatnloFXFX

    ["Zto2Nu_PTNuNu-200to400_1J",   '26',   5.406,     0.02724,   'NLO'],   # amcatnloFXFX
    ["Zto2Nu_PTNuNu-200to400_2J",   '26',   13.76,     0.1076,   'NLO'],   # amcatnloFXFX

    ["Zto2Nu_PTNuNu-400to600_1J",   '26',   0.1693,     0.0007856,   'NLO'],   # amcatnloFXFX
    ["Zto2Nu_PTNuNu-400to600_2J",   '26',   0.775,     0.005039,   'NLO'],   # amcatnloFXFX
    
    ["Zto2Nu_PTNuNu-600_1J",        '26',   0.01895,     0.00008347,   'NLO'],   # amcatnloFXFX
    ["Zto2Nu_PTNuNu-600_2J",        '26',   0.1304,     0.0007222,   'NLO'],   # amcatnloFXFX


    
    #["Zto2Nu_PTNuNu-40to100_1J",        '26',       929.8,	            5.481,		        'LO'],
    #["Zto2Nu_PTNuNu-40to100_2J",        '26',       335.5,	            3.49,		        'LO'],
    #["Zto2Nu_PTNuNu-100to200_1J",       '26',       86.38,	            0.441,		        'LO'],
    #["Zto2Nu_PTNuNu-100to200_2J",       '26',       100.4,	            0.8555,		        'LO'],
    #["Zto2Nu_PTNuNu-200to400_1J",       '26',       6.354,	            0.03067,		    'LO'],
    #["Zto2Nu_PTNuNu-200to400_2J",       '26',       13.86,	            0.09802,		    'LO'],
    #["Zto2Nu_PTNuNu-400to600_1J",       '26',       0.2188,	            0.0009573,		    'LO'],
    #["Zto2Nu_PTNuNu-400to600_2J",       '26',       0.7816,	            0.005088,		    'LO'],
    #["Zto2Nu_PTNuNu-600_1J",            '26',       0.02583,	        0.000108,		    'LO'],
    #["Zto2Nu_PTNuNu-600_2J",            '26',       0.1311,	            0.0007098,		    'LO'],
],

"WtoLNu": [
   # Devo incluir esses??
#############################################################################
    ["WtoLNu_1J",     '27',   9141,     24.37,   'LO'],   # madgraphMLM
    ["WtoLNu_2J",     '27',   2931,     8.539,   'LO'],   # madgraphMLM
    ["WtoLNu_3J",     '27',   864.6,     2.634,   'LO'],   # madgraphMLM
    ["WtoLNu_4J",     '27',   417.8,     1.283,   'LO'],   # madgraphMLM

##############################################################################
    
    ["WtoLNu_PTLNu-40to100_1J",     '27',   4211,     27.71,   'NLO'],   # amcatnloFXFX
    ["WtoLNu_PTLNu-40to100_2J",     '27',   1581,     16.18	,   'NLO'],   # amcatnloFXFX
    
    ["WtoLNu_PTLNu-100to200_1J",    '27',   342.3,     1.842,   'NLO'],   # amcatnloFXFX
    ["WtoLNu_PTLNu-100to200_2J",    '27',   411.1,     3.841,   'NLO'],   # amcatnloFXFX
    
    ["WtoLNu_PTLNu-200to400_1J",    '27',   21.84,     0.1076,   'NLO'],   # amcatnloFXFX
    ["WtoLNu_PTLNu-200to400_2J",    '27',   53.59,     0.4098,   'NLO'],   # amcatnloFXFX
    
    ["WtoLNu_PTLNu-400to600_1J",    '27',   0.6845,     0.003095,   'NLO'],   # amcatnloFXFX
    ["WtoLNu_PTLNu-400to600_2J",    '27',   3.099,     0.01935,   'NLO'],   # amcatnloFXFX
    
    ["WtoLNu_PTLNu-600_1J",         '27',   0.07753,     0.0003313,   'NLO'],   # amcatnloFXFX
    ["WtoLNu_PTLNu-600_2J",         '27',   0.5259,     0.002768,   'NLO'],   # amcatnloFXFX

    
  #  ["WtoLNu_PTLNu-40to100_1J",         '27',       4427,	            28.3,		        'LO'],
  #  ["WtoLNu_PTLNu-40to100_2J",         '27',       1598,	            16.36,		        'LO'],
  #  ["WtoLNu_PTLNu-100to200_1J",        '27',       368.2,	            1.926,		        'LO'],
  #  ["WtoLNu_PTLNu-100to200_2J",        '27',       421.9,	            3.533,		        'LO'],
  #  ["WtoLNu_PTLNu-200to400_1J",        '27',       25.6,	            0.1207,		        'LO'],
  #  ["WtoLNu_PTLNu-200to400_2J",        '27',       54.77,	            0.3764,		        'LO'],
  #  ["WtoLNu_PTLNu-400to600_1J",        '27',       0.8785,	            0.003223,		    'LO'],
  #  ["WtoLNu_PTLNu-400to600_2J",        '27',       3.119,	            0.01749,		    'LO'],
  #  ["WtoLNu_PTLNu-600_1J",             '27',       0.1053,	            0.0003437,		    'LO'],
  #  ["WtoLNu_PTLNu-600_2J",             '27',       0.5261,	            0.002417,		    'LO'],
],

"VV": [
    ["WWtoLNu2Q",     '28',   48.94,     0.0175,   'NLO'],   # powheg
    ["WZtoLNu2Q",     '28',   15.87,     0.007874,   'NLO'],   # powheg
    ["ZZto2Nu2Q",     '28',   4.826,     0.001296,   'NLO'],   # powheg

    #["WWtoLNu2Q",                       '28',       48.94,	            0.0175,		        'NLO'],
    #["WZtoLNu2Q",                       '28',       15.87,           	0.007874,		    'NLO'],
    #["ZZto2Nu2Q",                       '28',       4.826,	            0.001296,		    'NLO'],
],

"Vh": [
    ["ZH_Hto2B_Zto2Nu",      '29',   0.168,      0.0002559,   'NLO'],   # powheg MINLO
    ["ZH_Hto2C_Zto2Nu",      '29',   0.168,     0.0002559,   'NLO'],   # powheg MINLO
    ["ZHto2Zto4Nu_Zto2Q",    '29',   0.5934	,     0.00004693,   'NLO'],   # powheg MINLO

    ["WplusH_Hto2B_WtoLNu",    '29',   0.3,   0.00000519,   'NLO'],   # powhegMINLO
    ["WplusH_Hto2C_WtoLNu",    '29',   0.3,   0.000004869,   'NLO'],   # powhegMINLO
    ["WminusH_Hto2B_WtoLNu",   '29',   0.1887,   0.000002892,   'NLO'],   # powhegMINLO
    ["WminusH_Hto2C_WtoLNu",   '29',   0.1887,   0.000002855,   'NLO'],   # powhegMINLO


   # ["WplusH_Hto2B_WtoLNu",             '29',       0.05476506,	        0,		            '0.09426*0.581'],
   # ["WplusH_Hto2C_WtoLNu",             '29',       0.00273354,         0,		            '0.09426*0.029'],
   # ["WminusH_Hto2B_WtoLNu",            '29',       0.03476123,	        0,		            '0.05983*0.581'],
   # ["WminusH_Hto2C_WtoLNu",            '29',       0.00173507,	        0,		            '0.05983*0.029'],
   # ["ZH_Hto2B_Zto2Nu",                 '29',       0.08845144,         0,                  '0.7612*0.581*0.2'],
   # ["ZH_Hto2C_Zto2Nu",                 '29',       0.00441496,         0,                  '0.7612*0.029*0.2'],
   # ["ZHto2Zto4Nu_Zto2Q",               '29',       0.000553449,        0,                  '0.7612*0.026*0.2*0.2*0.69911'],
],

"ResidualSM": [

    


    
    #["Zto2Q_PTQQ-100to200_1J",          '30',       302,	            1.493,		        'LO'], # SEM VERSÂO
    #["Zto2Q_PTQQ-100to200_2J",          '30',       343.9,	            2.979,		        'LO'], # SEM VERSÂO
    #["Zto2Q_PTQQ-200to400_1J",          '30',       21.64,	            0.1029,		        'LO'], # SEM VERSÂO
    #["Zto2Q_PTQQ-200to400_2J",          '30',       48.36,	            0.375,		        'LO'], # SEM VERSÂO
    #["Zto2Q_PTQQ-400to600_1J",          '30',       0.7376,	            0.003183,		    'LO'], # SEM VERSÂO
    #["Zto2Q_PTQQ-400to600_2J",          '30',       2.683,	            0.01553,		    'LO'], # SEM VERSÂO
    #["Zto2Q_PTQQ-600_1J",               '30',       0.08717,	        0.0003566,		    'LO'], # SEM VERSÂO
    #["Zto2Q_PTQQ-600_2J",               '30',       0.4459,	            0.002084,		    'LO'], # SEM VERSÂO
    ["Zto2Q_PTQQ-100_2J",          '20',   0,   0,   'NLO'],  # amcatnloFXFX
    ["Zto2Q_HT-100to400_4J",       '20',   6328,   17.95,   'NLO'],  # madgraphMLM
    ["Zto2Q_PTQQ-200_2J",          '20',   0	,   0,   'NLO'],  # amcatnloFXFX
    ["Zto2Q_HT-1500to2500_4J",     '20',   0,   0,   'NLO'],  # madgraphMLM
    ["Zto2Q_PTQQ-400_2J",          '20',   0,   0,   'NLO'],  # amcatnloFXFX
    ["Zto2Q_HT-400to800_4J",       '20',   145.1,   0.4362,   'NLO'],  # madgraphMLM
    ["Zto2Q_PTQQ-600_2J",          '20',   0,   0,   'NLO'],  # amcatnloFXFX
    ["Zto2Q_HT-800to1500_4J",      '20',   0,   0,   'NLO'],  # madgraphMLM


    # --- 2 Jets, PTQQ bins (amcatnloFXFX) ---
    ["Wto2Q-2Jets_Bin-PTQQ-100",        '30',   XSEC,     KFACT,   'NLO'], # Não existe no XSDB, peguei o valor do que parece ser ele lá
    ["Wto2Q-2Jets_Bin-PTQQ-200",        '30',   165.3,     1.226,   'NLO'],
    ["Wto2Q-2Jets_Bin-PTQQ-400",        '30',   XSEC,     KFACT,   'NLO'], # Não existe no XSDB, peguei o valor do que parece ser ele lá
    ["Wto2Q-2Jets_Bin-PTQQ-600",        '30',   XSEC,     KFACT,   'NLO'], # Não existe no XSDB, peguei o valor do que parece ser ele lá
    
    # --- 3 Jets, HT bins (madgraphMLM → LO) ---
    ["Wto2Q-3Jets_Bin-HT-100to400",     '30',   16120,     44.49,   'LO'],
    ["Wto2Q-3Jets_Bin-HT-400to800",     '30',   XSEC,     KFACT,   'LO'], # Não existe no XSDB
    ["Wto2Q-3Jets_Bin-HT-800to1500",    '30',   XSEC,     KFACT,   'LO'], # Não existe no XSDB
    ["Wto2Q-3Jets_Bin-HT-1500to2500",   '30',   XSEC,     KFACT,   'LO'], # Não existe no XSDB
    ["Wto2Q-3Jets_Bin-HT-2500",         '30',   XSEC,     KFACT,   'LO'], # Não existe no XSDB

    #["Wto2Q_PTQQ-100to200_1J",          '30',       1517,	            7.518,		        'LO'],
    #["Wto2Q_PTQQ-100to200_2J",          '30',       1757,	            14.55,		        'LO'],
    #["Wto2Q_PTQQ-200to400_1J",          '30',       103.6,	            0.4359,		        'LO'],
    #["Wto2Q_PTQQ-200to400_2J",          '30',       227.1,	            1.729,		        'LO'],
    #["Wto2Q_PTQQ-400to600_1J",          '30',       3.496,	            0.01291,		    'LO'],
    #["Wto2Q_PTQQ-400to600_2J",          '30',       12.75,	            0.07947,		    'LO'],
    #["Wto2Q_PTQQ-600_1J",               '30',       0.4221,	            0.001474,		    'LO'],
    #["Wto2Q_PTQQ-600_2J",               '30',       2.128,	            0.009921,		    'LO'],


    ["WminusH_Hto2B_Wto2Q",     '30',   0.3918,     0.000007285,   'NLO'],   # powheg MINLO
    ["WminusH_Hto2C_Wto2Q",     '30',   0.3918,     0.000007483,   'NLO'],   # powheg MINLO
    
    ["WplusH_Hto2B_Wto2Q",      '30',   0.6226,     0.00001073,   'NLO'],   # powheg MINLO
    ["WplusH_Hto2C_Wto2Q",      '30',   0.6226,     0.00001092,   'NLO'],   # powheg MINLO
    #["WplusH_Hto2B_Wto2Q",              '30',       0.623,	            0.0001441,		    'NLO'],
    #["WplusH_Hto2C_Wto2Q",              '30',       0.6225,	            0.00002623,		    'NLO'],
    #["WminusH_Hto2B_Wto2Q",             '30',       0.3916,	            5.798e-05,		    'NLO'],
    #["WminusH_Hto2C_Wto2Q",             '30',       0.3918,	            0.00001408,		    'NLO'],

    ["ZH_Hto2B_Zto2L",   '30',   0.08545,   0.0001071,   'NLO'],   # powheg MINLO
    ["ZH_Hto2B_Zto2Q",   '30',   0.5958,   0.0004369,   'NLO'],   # powheg MINLO
    ["ZH_Hto2C_Zto2Q",   '30',   0.5958,   0.0004369,   'NLO'],   # powheg MINLO
    ["ZH_Hto2C_Zto2L",   '30',   0.08545,   0.0001071,   'NLO'],   # powheg MINLO

    #["ZH_Hto2B_Zto2L",                  '30',       0.08545,	        0.0002143,		    'NLO'],
    #["ZH_Hto2B_Zto2Q",                  '30',       0.5958,         	0.0006178,		    'NLO'],
    #["ZH_Hto2C_Zto2L",                  '30',       0.08545,	        0.0001515,		    'NLO'],
    #["ZH_Hto2C_Zto2Q",                  '30',       0.5958,	            0.0004369,		    'NLO'],
  
    ["WWto4Q",       '30',   50.79,   0.01816,   'NLO'],   # powheg
    ["WZto2L2Q",     '30',   7.568,   0.003908,   'NLO'],   # powheg
    ["WZto3LNu",     '30',   4.924,   0.00237,   'NLO'],   # powheg
    ["ZZto2L2Nu",    '30',   1.031,   0.0005268,   'NLO'],   # powheg
    ["ZZto2L2Q",     '30',   6.788,   0.003501,   'NLO'],   # powheg
    #["WWto4Q",                          '30',       50.79,	            0.01816,		    'NLO'],
    #["WZto2L2Q",                        '30',       7.568,	            0.003908,		    'NLO'],
    #["WZto3LNu",                        '30',       4.924,	            0.00237,		    'NLO'],
    #["ZZto2L2Nu",                       '30',       1.031,	            0.0005268,		    'NLO'],
    #["ZZto2L2Q",                        '30',       6.788,	            0.003501,		    'NLO'],

    ["TbarWplusto4Q",   '30',   36.05,   0.01296,   'NLO'],   # powheg
    ["TWminusto4Q",     '30',   35.99,   0.01292,   'NLO'],   # powheg

    #["TbarWplusto4Q",                   '30',       36.05,              0.01296,            'NLO'],
    #["TWminusto4Q",                     '30',       35.99,	            0.01292,		    'NLO'],

    
    #["TQbarto2Q-t-channel",             '30',       130,                0.07514,            'NLO'], # SEM VERSÂO
    #["TbarQto2Q-t-channel",             '30',       78.56,              0.04092,            'NLO'], # SEM VERSÂO
    
    ["TTto4Q",                          '30',       762.1,               0.1345,              'NLO'],   # powheg
    #["TTto4Q",                          '30',       419.7,	            0.1345,	        	'NLO'],
    ["WWW",   '30',   0.2328,   0.00008821,   'NLO'],   # amcatnlo-madspin
    ["WWZ",   '30',   0.1851,   0.00006705,   'NLO'],   # amcatnlo
    ["WZZ",   '30',   0.06206,   0.00002608,   'NLO'],   # amcatnlo
    ["ZZZ",   '30',   0.01591,   5.835e-7,   'NLO'],   # amcatnlo
    #["WWW",                             '30',       0.2328,	            0.0001247,		    'LO'],
    #["WWZ",                             '30',       0.1851,	            9.482e-05,		    'unknown'],
    #["WZZ",                             '30',       0.06206,	        3.689e-05,		    'unknown'],
    #["ZZZ",                             '30',       0.01591,	        7.828e-06,		    'unknown'],
    ["ttHto2B",   '30',   0.5742,   0.006401,   'NLO'],   # powheg
    ["ttHto2C",   '30',   0.5742,   0.006401,   'NLO'],   # powheg
    
    #["ttHto2B",                         '30',       0.5742,	            0.009052,		    'NLO'],
    #["ttHto2C",                         '30',       0.5742,	            0.009052,		    'NLO'],

    # NOVAS AMOSTRAS
    
    ["TBbarQto2Q-t-channel",              '30',   77.26,   0.2169,   'NLO'],   # powheg-madspin

    #["TBbarQtoLNu-t-channel_CP5Down",     '30',   38.6	,   0.1084	,   'NLO'],   # powheg-madspin # OPCIONAL?
    #["TBbarQtoLNu-t-channel_CP5Up",       '30',   38.6	,   0.1084,   'NLO'],   # powheg-madspin # OPCIONAL?
    
    ["TbarBQto2Q-t-channel",              '30',   46.73,   0.1176,   'NLO'],   # powheg-madspin
    
    #["TbarBQtoLNu-t-channel_CP5Down",     '30',   23.34	,   0.05875	,   'NLO'],   # powheg-madspin
    #["TbarBQtoLNu-t-channel_CP5Up",       '30',   23.34	,   0.05875,   'NLO'],   # powheg-madspin
    


    ["WminusHtoInv_Wto2Q",     '30', 0.3916, 0.00002025, 'NLO'],
    ["WplusHtoInv_Wto2Q",     '30', 0.6194, 0.00002424, 'NLO'],
    ["ZHtoInv_Zto2Q",    '30',    0.5934,0.00004693	,'NLO'],


    
],
}


#----------------------------------------------------------------------------------------
# [DO NOT TOUCH THIS PART]
#----------------------------------------------------------------------------------------
b_ds = {}
for period in paths.keys():

    dti = period[0]
    year = period[-2:]

    for key in b_ds_info.keys():
        b_ds[key+"_"+period] = []
        for ds in b_ds_info[key]:
            list_temp = []
            list_temp.append(ds[0]+"_"+period)
            list_temp.append(ds[1]+year+dti)
            list_temp.append(paths[period]+ds[0]+".txt")
            list_temp.append(ds[2])
            list_temp.append(ds[3])
            b_ds[key+"_"+period].append(list_temp)

