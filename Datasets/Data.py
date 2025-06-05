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
paths["0_22"] = analysis+'/Datasets/Files/data_22/'+nano_version+'/'
paths["1_22"] = analysis+'/Datasets/Files/data_22/'+nano_version+'/'
paths["0_23"] = analysis+'/Datasets/Files/data_23/'+nano_version+'/'
paths["1_23"] = analysis+'/Datasets/Files/data_23/'+nano_version+'/'

eras = {}
eras["0_22"] = ['C', 'D']
eras["1_22"] = ['E', 'F', 'G']
eras["0_23"] = ['C']
eras["1_23"] = ['D']

lumis = {}
lumis["0_22"] = [7980.4,    0,  0,  0]
lumis["1_22"] = [26671.7,   0,  0,  0]
lumis["0_23"] = [17794,     0,  0,  0]
lumis["1_23"] = [9451,      0,  0,  0]


d_ds = {}
for period in paths.keys():

    dti = period[0]
    year = period[-2:]

    d_ds_info = {
    "Data_Lep": [
        ["Data_SingleEle",      '00'],
        ["Data_SingleMu",       '00'],
    ],
    "Data_MET": [
        ["Data_MET",            '01'],
    ],
    }


    for key in d_ds_info.keys():
        d_ds[key+"_"+period] = []
        for ds in d_ds_info[key]:
            for era in eras[period]:
                list_temp = []
                list_temp.append(ds[0]+"_"+era+"_"+period)
                list_temp.append(ds[1]+year+dti)
                list_temp.append(paths[period]+ds[0]+"_"+era+".txt")
                d_ds[key+"_"+period].append(list_temp)
    del d_ds_info







"""
Data_Lep_0_22 = [
["Data_SingleEle_C_0_22"]             + ['2200030', path_22+"SingleEle_C.txt"],
["Data_SingleMu_C_0_22"]              + ['2200230', path_22+"SingleMu_C.txt"],
]

Data_MET_0_22 = [
["Data_MET_C_0_22"]                   + ['2200530', path_22+"MET_C.txt"],
]

Data_Lep_1_22 = [
["Data_SingleEle_F_1_22"]             + ['2200071', path_22+"SingleEle_F.txt"],
["Data_SingleMu_F_1_22"]              + ['2200271', path_22+"SingleMu_F.txt"],
]

Data_MET_1_22 = [
["Data_MET_F_1_22"]                   + ['2200571', path_22+"MET_F.txt"],
]


Data_Lep_0_23 = [
["Data_SingleEle_C_0_23"]             + ['2300030', path_23+"SingleEle_C.txt"],
["Data_SingleMu_C_0_23"]              + ['2300230', path_23+"SingleMu_C.txt"],
]

Data_MET_0_23 = [
["Data_MET_C_0_23"]                   + ['2300530', path_23+"MET_C.txt"],
]

Data_Lep_1_23 = [
["Data_SingleEle_F_1_23"]             + ['2300071', path_23+"SingleEle_F.txt"],
["Data_SingleMu_F_1_23"]              + ['2300271', path_23+"SingleMu_F.txt"],
]

Data_MET_1_23 = [
["Data_MET_F_1_23"]                   + ['2300571', path_23+"MET_F.txt"],
]
"""


print(d_ds["Data_Lep_0_22"])


