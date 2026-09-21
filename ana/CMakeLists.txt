set(ANALYSIS "AP_bbhZDM_Had_R3")

target_sources(RunAnalysis PRIVATE ${ANALYSIS}/ana/Hist_for_Pileup_wgt.cpp ${ANALYSIS}/ana/TestEfficiency.cpp ${ANALYSIS}/ana/SignalPoints.cpp ${ANALYSIS}/ana/Study_ExcludedRegion.cpp ${ANALYSIS}/ana/MCData.cpp ${ANALYSIS}/ana/BTagEffMap.cpp ${ANALYSIS}/ana/HEPWeights.cpp ${ANALYSIS}/ana/ML.cpp ${ANALYSIS}/ana/Study_GEN.cpp ${ANALYSIS}/ana/Test.cpp)
