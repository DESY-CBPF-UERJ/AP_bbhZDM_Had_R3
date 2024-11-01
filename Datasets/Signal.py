analysis = "AP_bbhZDM_Had_R3"
nano_version = 'v12'
path_0_22 = analysis+'/Datasets/Files/signal_22/dti_0/'+nano_version+'/'
path_1_22 = analysis+'/Datasets/Files/signal_22/dti_1/'+nano_version+'/'
path_0_23 = analysis+'/Datasets/Files/signal_23/dti_0/'+nano_version+'/'
path_1_23 = analysis+'/Datasets/Files/signal_23/dti_1/'+nano_version+'/'

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
        
    Signal = [
        ["Signal_400_100_"+period]           + [year+'9900'+dti, path+"Signal_400_100.txt"],
        ["Signal_1000_100_"+period]           + [year+'9914'+dti, path+"Signal_1000_100.txt"],
    ]

        

    if period == "0_22":
        Signal_0_22 = Signal
    elif period == "1_22":
        Signal_1_22 = Signal
    elif period == "0_23":
        Signal_0_23 = Signal
    elif period == "1_23":
        Signal_1_23 = Signal
