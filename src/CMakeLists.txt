set(ANALYSIS "AP_bbhZDM_Had_R3")

target_sources(RunAnalysis PRIVATE ${ANALYSIS}/src/HEPHeroB.cpp ${ANALYSIS}/src/HEPRoutines.cpp ${ANALYSIS}/src/EXPTools.cpp ${ANALYSIS}/src/ANATools.cpp)
