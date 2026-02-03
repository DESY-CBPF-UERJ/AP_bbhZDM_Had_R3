#include "HEPHero.h"


//-------------------------------------------------------------------------------------------------
// Weight corrections
//-------------------------------------------------------------------------------------------------
void HEPHero::Weight_corrections(){

    pileup_wgt = 1.;

    if(dataset_group != "Data"){
	
        if( apply_pileup_wgt ){
            pileup_wgt = GetPileupWeight(Pileup_nTrueInt, "nominal");
            evtWeight *= pileup_wgt;
        }
        
    }

}

//---------------------------------------------------------------------------------------------
// Pileup Correction
// Return weight associated to the pileup effect
//---------------------------------------------------------------------------------------------
float HEPHero::GetPileupWeight( float Pileup_nTrueInt, string sysType ){

    double pileup_weight = 1.;

    string dsName = _datasetName.substr(0,_datasetName.length()-5);
    string dsNameDY = dsName.substr(0,10);

    std::cout<<"dsName"<<dsName<<std::endl;
    std::cout<<"sysType"<<sysType<<std::endl;
    std::cout<<"dataset_year"<<dataset_year<<std::endl;


    if( (dsNameDY == "DYJetsToLL") && (sysType != "nominal") ){

        float syst_SF;
        if( sysType == "up" ){
            vector<float> SF_22 = {1.027, 1.067};
            vector<float> SF_23 = {1.030, 1.064};
            vector<float> SF_24 = {1.028, 1.066};
            vector<float> SF_25 = {1.032, 1.069};
            if( (dataset_year == "22") && (dataset_dti == 0) ){
                if( NPUjets == 0 ){
                    syst_SF = SF_22[0];
                }else{
                    syst_SF = SF_22[1];
                }
            }else if( (dataset_year == "23") && (dataset_dti == 1) ){
                if( NPUjets == 0 ){
                    syst_SF = SF_23[0];
                }else{
                    syst_SF = SF_23[1];
                }
            }else if( dataset_year == "24" ){
                if( NPUjets == 0 ){
                    syst_SF = SF_24[0];
                }else{
                    syst_SF = SF_24[1];
                }
            }else if( dataset_year == "25" ){
                if( NPUjets == 0 ){
                    syst_SF = SF_25[0];
                }else{
                    syst_SF = SF_25[1];
                }
            }
            pileup_weight = pileup_corr->evaluate({Pileup_nTrueInt, "nominal"})*syst_SF;
        }else if( sysType == "down" ){
            vector<float> SF_22 = {1.027, 1.067};
            vector<float> SF_23 = {1.030, 1.064};
            vector<float> SF_24 = {1.028, 1.066};
            vector<float> SF_25 = {1.032, 1.069};
            if( (dataset_year == "22") && (dataset_dti == 0) ){
                if( NPUjets == 0 ){
                    syst_SF = SF_22[0];
                }else{
                    syst_SF = SF_22[1];
                }
            }else if( (dataset_year == "23") && (dataset_dti == 1) ){
                if( NPUjets == 0 ){
                    syst_SF = SF_23[0];
                }else{
                    syst_SF = SF_23[1];
                }
            }else if( dataset_year == "24" ){
                if( NPUjets == 0 ){
                    syst_SF = SF_24[0];
                }else{
                    syst_SF = SF_24[1];
                }
            }else if( dataset_year == "25" ){
                if( NPUjets == 0 ){
                    syst_SF = SF_25[0];
                }else{
                    syst_SF = SF_25[1];
                }
            }
            pileup_weight = pileup_corr->evaluate({Pileup_nTrueInt, "nominal"})*syst_SF;
        }
    }else{
        pileup_weight = pileup_corr->evaluate({Pileup_nTrueInt, sysType});
    }

    //pileup_weight = pileup_corr->evaluate({Pileup_nTrueInt, sysType});

    return pileup_weight;
}

