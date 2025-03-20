set(ANALYSIS "AP_bbhZDM_Had_R3")

target_sources(RunAnalysis PRIVATE ${ANALYSIS}/ana/ML.cpp ${ANALYSIS}/ana/TestMatheus.cpp ${ANALYSIS}/ana/massParticlesWeights.cpp ${ANALYSIS}/ana/Test_Electron_ID.cpp ${ANALYSIS}/ana/Test.cpp)
