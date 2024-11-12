#include "HEPHero.h"


//-------------------------------------------------------------------------
// Return boolean informing if the reco jet is a pileup jet or not
//-------------------------------------------------------------------------
bool HEPHero::PileupJet( int iJet ){
    bool isPileup = true;
    bool isSignal = false;

    for( unsigned int igenJet = 0; igenJet < nGenJet; ++igenJet ) {
        float DEta = fabs( GenJet_eta[igenJet] - Jet_eta[iJet] );
        float DPhi = fabs( GenJet_phi[igenJet] - Jet_phi[iJet] );
        if( DPhi > M_PI ) DPhi = 2*M_PI - DPhi;
        float DR = sqrt( DEta*DEta + DPhi*DPhi );
        if( DR < 0.4 ) isSignal = true;
    }
    if( isSignal ) isPileup = false;

    return isPileup;
}

//---------------------------------------------------------------------------------------------------------------
// Jet BTAG
//---------------------------------------------------------------------------------------------------------------
bool HEPHero::JetBTAG( int iobj, int WP ){

    bool obj_selected = false;
    float BTAG_CUT;

    // DeepJet
    if( dataset_year == "16"){
        if( dataset_dti == 0 ){
            if(      WP == 0 ) BTAG_CUT = 0.0508;   // loose
            else if( WP == 1 ) BTAG_CUT = 0.2598;   // medium
            else if( WP == 2 ) BTAG_CUT = 0.6502;   // tight
        }else{
            if(      WP == 0 ) BTAG_CUT = 0.0480;   // loose
            else if( WP == 1 ) BTAG_CUT = 0.2489;   // medium
            else if( WP == 2 ) BTAG_CUT = 0.6377;   // tight
        }
    }else if( dataset_year == "17" ){
        if(      WP == 0 ) BTAG_CUT = 0.0532;   // loose
        else if( WP == 1 ) BTAG_CUT = 0.3040;   // medium
        else if( WP == 2 ) BTAG_CUT = 0.7476;   // tight
    }else if( dataset_year == "18" ){
        if(      WP == 0 ) BTAG_CUT = 0.0490;   // loose
        else if( WP == 1 ) BTAG_CUT = 0.2783;   // medium
        else if( WP == 2 ) BTAG_CUT = 0.7100;   // tight
    }

    // DeepCSV
    if( dataset_year == "16" ){
        if( dataset_dti == 0 ){
            if(      WP == 3 ) BTAG_CUT = 0.2027;   // loose
            else if( WP == 4 ) BTAG_CUT = 0.6001;   // medium
            else if( WP == 5 ) BTAG_CUT = 0.8819;   // tight
        }else{
            if(      WP == 3 ) BTAG_CUT = 0.1918;   // loose
            else if( WP == 4 ) BTAG_CUT = 0.5847;   // medium
            else if( WP == 5 ) BTAG_CUT = 0.8767;   // tight
        }
    }else if( dataset_year == "17" ){
        if(      WP == 3 ) BTAG_CUT = 0.1355;   // loose
        else if( WP == 4 ) BTAG_CUT = 0.4506;   // medium
        else if( WP == 5 ) BTAG_CUT = 0.7738;   // tight
    }else if( dataset_year == "18" ){
        if(      WP == 3 ) BTAG_CUT = 0.1208;   // loose
        else if( WP == 4 ) BTAG_CUT = 0.4168;   // medium
        else if( WP == 5 ) BTAG_CUT = 0.7665;   // tight
    }

    if(      WP >= 0 and WP <=2 ) obj_selected = (Jet_btagDeepFlavB[iobj] > BTAG_CUT);    // DeepJet
    else if( WP >= 3 and WP <=5 ) obj_selected = (Jet_btagDeepB[iobj] > BTAG_CUT);        // DeepCSV

    return obj_selected;
}


