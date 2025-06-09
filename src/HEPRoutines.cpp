#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Pre-Routines Setup
//-------------------------------------------------------------------------------------------------
void HEPHero::PreRoutines() {
    
    //=============================================================================================
    // CMS SETUP
    //=============================================================================================

    //----OUTPUT INFO------------------------------------------------------------------------------
    _outputTree->Branch( "evtWeight", &evtWeight );
    HDF_insert( "evtWeight", &evtWeight );

    //=============================================================================================
    // METADATA SETUP
    //=============================================================================================

    //----PILEUP-------------------------------------------------------------------------
    //if( apply_pileup_wgt ){
    //    auto pileup_set = correction::CorrectionSet::from_file(pileup_file.c_str());
    //    string SetName = "Collisions" + dataset_year +"_UltraLegacy_goldenJSON";
    //    pileup_corr = pileup_set->at(SetName.c_str());
    //}

    //----MACHINE LEARNING---------------------------------------------------------------
    signal_tagger.readFile(NN_model_file);

}


//-------------------------------------------------------------------------------------------------
// On fly Routines Setup [run before genWeight count]
//-------------------------------------------------------------------------------------------------
bool HEPHero::RunRoutines() {
    

    //======SUM THE GENERATOR WEIGHTS================================================
    SumGenWeights += genWeight;

    if( !MC_processing() ) return false;

    
    return true;
}


//-------------------------------------------------------------------------------------------------
// MCsamples processing
//-------------------------------------------------------------------------------------------------
bool HEPHero::MC_processing(){

    bool pass_cut = true;
    string dsName = _datasetName.substr(0,_datasetName.length()-5);



    return pass_cut;
}

    
