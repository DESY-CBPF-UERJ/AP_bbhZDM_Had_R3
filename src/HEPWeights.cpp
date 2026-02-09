#include "HEPHero.h"


//-------------------------------------------------------------------------------------------------
// Weight corrections
//-------------------------------------------------------------------------------------------------
void HEPHero::Weight_corrections(){

    pileup_wgt = 1.;
    electron_wgt = 1.;




    if(dataset_group != "Data"){
	
        if( apply_pileup_wgt ){
            pileup_wgt = GetPileupWeight(Pileup_nTrueInt, "nominal");
            evtWeight *= pileup_wgt;
        }

	if( apply_electron_wgt ){
            electron_wgt = GetElectronWeight("cv");
            evtWeight *= electron_wgt;
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



//---------------------------------------------------------------------------------------------
// Electron ID Correction
// Return weight associated to the identification of the two electrons
//---------------------------------------------------------------------------------------------
float HEPHero::GetElectronWeight( string sysID ){

    float LeptonID_wgt = 1.;
    if( dataset_group != "Data" ){

        string year;
        if( dataset_year == "16" ){
            if( dataset_dti == 0 ){
                year = "2016preVFP";
            }else{
                year = "2016postVFP";
            }
        }else if( dataset_year == "17" ){
            year = "2017";
        }else if( dataset_year == "18" ){
            year = "2018";
        }else if( dataset_year == "24"){
	    year = "2024";
	}


        string EleID_WP;
        if( ELECTRON_ID_WP == 0 ){
            EleID_WP = "Veto";
        }else if( ELECTRON_ID_WP == 1 ){
            EleID_WP = "Loose";
        }else if( ELECTRON_ID_WP == 2 ){
            EleID_WP = "Medium";
        }else if( ELECTRON_ID_WP == 3 ){
            EleID_WP = "Tight";
        }else if( ELECTRON_ID_WP == 4 ){
            EleID_WP = "wp80iso";
        }else if( ELECTRON_ID_WP == 5 ){
            EleID_WP = "wp90iso";
        }

        for( unsigned int iele = 0; iele < nElectron; ++iele ) {
            if( Electron_pt[iele] <= 20 ) continue;
            //if( Electron_pt[iele] >= 500 ) continue;

            float ele_pt = Electron_pt[iele];
            float ele_etaSC = Electron_eta[iele] + Electron_deltaEtaSC[iele];

            float RECO_SF;
            //if( sysID == "cv" ){
            //    if( ele_pt <= 20     ) RECO_SF = electron_ID_corr->evaluate({year, "sf", "RecoBelow20", ele_etaSC, ele_pt});
            //    else if( ele_pt > 20 ) RECO_SF = electron_ID_corr->evaluate({year, "sf", "RecoAbove20", ele_etaSC, ele_pt});
            //}else if( sysID == "down" ){
            //    if( ele_pt <= 20     ) RECO_SF = electron_ID_corr->evaluate({year, "sfdown", "RecoBelow20", ele_etaSC, ele_pt});
            //    else if( ele_pt > 20 ) RECO_SF = electron_ID_corr->evaluate({year, "sfdown", "RecoAbove20", ele_etaSC, ele_pt});
            //}else if( sysID == "up" ){
            //    if( ele_pt <= 20     ) RECO_SF = electron_ID_corr->evaluate({year, "sfup", "RecoBelow20", ele_etaSC, ele_pt});
            //    else if( ele_pt > 20 ) RECO_SF = electron_ID_corr->evaluate({year, "sfup", "RecoAbove20", ele_etaSC, ele_pt});
            //}
            //LeptonID_wgt *= RECO_SF;

            if( !ElectronID( iele, ELECTRON_ID_WP ) ) continue;

            float ID_SF;
            if( sysID == "cv" ){
                ID_SF = electron_ID_corr->evaluate({year, "sf", EleID_WP, ele_etaSC, ele_pt});
            }else if( sysID == "down" ){
                ID_SF = electron_ID_corr->evaluate({year, "sfdown", EleID_WP, ele_etaSC, ele_pt});
            }else if( sysID == "up" ){
                ID_SF = electron_ID_corr->evaluate({year, "sfup", EleID_WP, ele_etaSC, ele_pt});
            }
            LeptonID_wgt *= ID_SF;
        }
    }

    return LeptonID_wgt;
}

