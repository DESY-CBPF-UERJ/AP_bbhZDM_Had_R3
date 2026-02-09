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
  
    //----LUMI CERTIFICATE-------------------------------------------------------------------------
    lumi_certificate.ReadFile(certificate_file);


   //----ELECTRON ID------------------------------------------------------------------------------
    if( apply_electron_wgt ){
        auto electron_set = correction::CorrectionSet::from_file(electron_file.c_str());
        electron_ID_corr = electron_set->at("Electron-ID-SF");
    }

    //----MUON ID----------------------------------------------------------------------------------
    if( apply_muon_wgt ){
        auto muon_set = correction::CorrectionSet::from_file(muon_file.c_str());

        muon_RECO_corr = muon_set->at("NUM_LooseID_DEN_TrackerMuons");

        string MuID_WP;
        if( MUON_ID_WP == 0 ){
            MuID_WP = "NUM_LooseID_DEN_TrackerMuons"; // EXISTE E FUNCIONA
        }else if( MUON_ID_WP == 1 ){
            MuID_WP = "NUM_MediumID_DEN_TrackerMuons";
        }else if( MUON_ID_WP == 2 ){
            MuID_WP = "NUM_TightID_DEN_TrackerMuons";
        }
        muon_ID_corr = muon_set->at(MuID_WP);

        string MuISO_WP;
        if( MUON_ISO_WP == 0 ){
            MuISO_WP = "NUM_LooseRelIso_DEN_LooseID"; // dumb value, not used
        }else if( MUON_ISO_WP == 1 ){
            MuISO_WP = "NUM_LooseRelIso_DEN_LooseID";
        }else if( MUON_ISO_WP == 2 ){
            MuISO_WP = "NUM_LoosePFIso_DEN_MediumID"; //MODIFICADO, FUNCIONANDO
        }else if( MUON_ISO_WP == 3 ){
            MuISO_WP = "NUM_TightRelIso_DEN_MediumID";
        }
        muon_ISO_corr = muon_set->at(MuISO_WP);
    }




    //----PILEUP-------------------------------------------------------------------------
    if( apply_pileup_wgt ){
        auto pileup_set = correction::CorrectionSet::from_file(pileup_file.c_str());
        string SetName = "Collisions" + dataset_year +"_UltraLegacy_goldenJSON";
        pileup_corr = pileup_set->at(SetName.c_str());
    }

    //----MACHINE LEARNING---------------------------------------------------------------
    signal_tagger.readFile(NN_model_file);

}


//-------------------------------------------------------------------------------------------------
// On fly Routines Setup [run before genWeight count]
//-------------------------------------------------------------------------------------------------
bool HEPHero::RunRoutines() {
    
    //======SUM THE GENERATOR WEIGHTS=================================================
    if( dataset_group != "Data" ){
        SumGenWeights_original += genWeight;
//        if(dataset_group == "Signal"){
//            SumGenWeights += genWeight*LHEReweightingWeight[15]; //parvar_tb10_sp0p7_l30p3
//        }else{
            SumGenWeights += genWeight;
//        }
    }

    //======MC SAMPLES PROCESSING=====================================================
    if( !MC_processing() ) return false;


    //======START EVENT WEIGHT========================================================
    evtWeight = 1.;
    if( dataset_group != "Data" ){
        //if(dataset_group == "Signal"){
        //    evtWeight = genWeight*LHEReweightingWeight[15]; //parvar_tb10_sp0p7_l30p3
        //}else{
        evtWeight = genWeight;
        //}
    }

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

    
