#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace TestNanoAOD{
    //Variáveis que são dos

        vector<int> v_idx_bjet;
        double JetB_pt1,JetB_pt2,JetB_pt3,JetB_pt4;
        int Nbjet,ijet;
        int Tag_decay_GenZ; // 0 = No match; 1 = z->dd; 2 = z-> uu; 3=z->ss; 4= z->cc; 5 = z->bb; 11=z->ee; 13: z->mumu; 15: z-> tautau ; -1 mais de um Z


        double gilson_pt_genb,gilson_eta_genb,gilson_phi_genb,gilson_mass_genb,gilson_pt_genbar,gilson_eta_genbar,gilson_phi_genbar,gilson_mass_genbar,gilson_pt_Zdecay_one,gilson_eta_Zdecay_one,gilson_phi_Zdecay_one,gilson_mass_Zdecay_one;
        double gilson_pt_Zdecay_sec,gilson_phi_Zdecay_sec,gilson_eta_Zdecay_sec,gilson_mass_Zdecay_sec,gilson_pt_Z,gilson_eta_Z,gilson_phi_Z,gilson_mass_Z,gilson_pt_a,gilson_eta_a,gilson_phi_a,gilson_mass_a;
        double gilson_pt_H,gilson_eta_H,gilson_phi_H,gilson_mass_H;

        double gilson_deltaR_b_ZDecayOne,gilson_deltaR_b_ZDecaySec,gilson_deltaR_ZDecayOne_ZDecaySec,gilson_deltaR_b_z,gilson_deltaR_ZDecayOne_z,gilson_deltaR_ZDecaySec_z,gilson_mass_b_ZDecayOne,gilson_mass_bar_ZDecaySec;
        double gilson_massTran_z_a,gilson_massTran_bZDecayOne_a,gilson_massTran_bZDecaySec_a,gilson_deltaPhi_b_a,gilson_deltaPhi_bZDecayOne_a,gilson_deltaPhi_bZDecaySec_a,gilson_deltaEta_b_z;

        double gilson_deltaPhi_z_a;

        int match_PhiEta_ZDecayOneSec_JetJet,match_PhiEta_BBarGen_JetJet, match_info;

        int match_PhiEta_FatJet_ZDecaySec,match_PhiEta_FatJet_ZDecayOne,match_PhiEta_FatJet_B,match_PhiEta_FatJet_Bar,match_info_fatJet;

        int evento=0;

        double leading_fatJet_pt,subleading_fatJet_pt,B_fatJet_pt,Bar_fatJet_pt;

}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupTestNanoAOD() {

// VARIAVEIS DO NANOAOD (NAO SOFREM CORTE OU FILTRO, mesmo que aplicado!)
         HDF_insert("MET_pt_RAW",&MET_RAW_pt);
                 HDF_insert("MET_phi_RAW",&MET_RAW_phi);
                 HDF_insert("nElectron_RAW",&nElectron);
                 HDF_insert("nGenJet_RAW",&nGenJet);
                 HDF_insert("nGenPart_RAW",&nGenPart);
                 HDF_insert("GenMET_phi_RAW",&GenMET_phi);
                 HDF_insert("GenMET_pt_RAW",&GenMET_pt);
                 HDF_insert("nJet_RAW",&nJet);
                 HDF_insert("nFatJet_RAW",&nFatJet);
                 HDF_insert("nMuon_RAW",&nMuon);
                 HDF_insert("nTau_RAW",&nTau);
                 HDF_insert("nSV_RAW",&nSV);
                 //HDF_insert("nSubJet_RAW",&nSubJet);
                 HDF_insert("nIsoTrack_RAW",&nIsoTrack);
                 HDF_insert("Pileup_nTrueInt_RAW",&Pileup_nTrueInt);

// // VARIAVEIS QUE MUDAM DEPENDENDO DO CORTE E FILTROS APLICADOS MAS SÃO DO FRAMEWORK DO GILSON
                 HDF_insert("LepLep_deltaR",&LepLep_deltaR);
                 HDF_insert("LeadingLep_pt", &LeadingLep_pt);
                 HDF_insert("TrailingLep_pt", &TrailingLep_pt);
                 HDF_insert("RecoLepID", &RecoLepID);
                 HDF_insert("MET_pt",&MET_pt);
                 HDF_insert("MET_phi",&MET_phi);
                 HDF_insert("Njets",&Njets);
                 HDF_insert("Nbjets",&Nbjets);
                 HDF_insert("LeadingJet_pt",&LeadingJet_pt);
                 HDF_insert("SubLeadingJet_pt ",&SubLeadingJet_pt);
                 HDF_insert("ThirdLeadingJet_pt ",&ThirdLeadingJet_pt);
                 HDF_insert("FourthLeadingJet_pt ",&FourthLeadingJet_pt);
                 HDF_insert("Nmuons",&Nmuons);
                 HDF_insert("Ntaus",&Ntaus);
                 HDF_insert("Nelectrons",&Nelectrons);
                 HDF_insert( "Njets30", &Njets30);
                 HDF_insert( "Njets40", &Njets40);

// // VARIAVEIS DO GILSON
         HDF_insert("gilson_pt_genb",&TestNanoAOD::gilson_pt_genb);
         HDF_insert("gilson_eta_genb",&TestNanoAOD::gilson_eta_genb);
         HDF_insert("gilson_phi_genb",&TestNanoAOD::gilson_phi_genb);
         HDF_insert("gilson_mass_genb",&TestNanoAOD::gilson_mass_genb);
         HDF_insert("gilson_pt_genbar",&TestNanoAOD::gilson_pt_genbar);
         HDF_insert("gilson_eta_genbar",&TestNanoAOD::gilson_eta_genbar);
         HDF_insert("gilson_phi_genbar",&TestNanoAOD::gilson_phi_genbar);
         HDF_insert("gilson_mass_genbar",&TestNanoAOD::gilson_mass_genbar);
         HDF_insert("gilson_pt_Zdecay_one",&TestNanoAOD::gilson_pt_Zdecay_one);
         HDF_insert("gilson_eta_Zdecay_one",&TestNanoAOD::gilson_eta_Zdecay_one);
         HDF_insert("gilson_phi_Zdecay_one",&TestNanoAOD::gilson_phi_Zdecay_one);
         HDF_insert("gilson_mass_Zdecay_one",&TestNanoAOD::gilson_mass_Zdecay_one);
         HDF_insert("gilson_pt_Zdecay_sec",&TestNanoAOD::gilson_pt_Zdecay_sec);
         HDF_insert("gilson_phi_Zdecay_sec",&TestNanoAOD::gilson_phi_Zdecay_sec);
         HDF_insert("gilson_eta_Zdecay_sec",&TestNanoAOD::gilson_eta_Zdecay_sec);
         HDF_insert("gilson_mass_Zdecay_sec",&TestNanoAOD::gilson_mass_Zdecay_sec);
         HDF_insert("gilson_pt_Z",&TestNanoAOD::gilson_pt_Z);
         HDF_insert("gilson_eta_Z",&TestNanoAOD::gilson_eta_Z);
         HDF_insert("gilson_phi_Z",&TestNanoAOD::gilson_phi_Z);
         HDF_insert("gilson_mass_Z",&TestNanoAOD::gilson_mass_Z);
         HDF_insert("gilson_pt_a",&TestNanoAOD::gilson_pt_a);
         HDF_insert("gilson_eta_a",&TestNanoAOD::gilson_eta_a);
         HDF_insert("gilson_phi_a",&TestNanoAOD::gilson_phi_a);
         HDF_insert("gilson_mass_a",&TestNanoAOD::gilson_mass_a);

         HDF_insert("gilson_deltaR_b_ZDecayOne",&TestNanoAOD::gilson_deltaR_b_ZDecayOne);
         HDF_insert("gilson_deltaR_b_ZDecaySec",&TestNanoAOD::gilson_deltaR_b_ZDecaySec);
         HDF_insert("gilson_deltaR_ZDecayOne_ZDecaySec",&TestNanoAOD::gilson_deltaR_ZDecayOne_ZDecaySec);
         HDF_insert("gilson_deltaR_b_z",&TestNanoAOD::gilson_deltaR_b_z);
         HDF_insert("gilson_deltaR_ZDecayOne_z",&TestNanoAOD::gilson_deltaR_ZDecayOne_z);
         HDF_insert("gilson_deltaR_ZDecaySec_z",&TestNanoAOD::gilson_deltaR_ZDecaySec_z);
         HDF_insert("gilson_mass_b_ZDecayOne",&TestNanoAOD::gilson_mass_b_ZDecayOne);
         HDF_insert("gilson_mass_bar_ZDecaySec",&TestNanoAOD::gilson_mass_bar_ZDecaySec);
         HDF_insert("gilson_deltaPhi_z_a",&TestNanoAOD::gilson_deltaPhi_z_a);
         HDF_insert("gilson_massTran_z_a",&TestNanoAOD::gilson_massTran_z_a);
         HDF_insert("gilson_massTran_bZDecayOne_a",&TestNanoAOD::gilson_massTran_bZDecayOne_a);
         HDF_insert("gilson_massTran_bZDecaySec_a",&TestNanoAOD::gilson_massTran_bZDecaySec_a);
         HDF_insert("gilson_deltaPhi_b_a",&TestNanoAOD::gilson_deltaPhi_b_a);
         HDF_insert("gilson_deltaPhi_bZDecayOne_a",&TestNanoAOD::gilson_deltaPhi_bZDecayOne_a);
         HDF_insert("gilson_deltaPhi_bZDecaySec_a",&TestNanoAOD::gilson_deltaPhi_bZDecaySec_a);
         HDF_insert("gilson_deltaEta_b_z",&TestNanoAOD::gilson_deltaEta_b_z);





         HDF_insert("Tag_decay_GenZ",&TestNanoAOD::Tag_decay_GenZ);
//         HDF_insert("JetB_pt1",&TestNanoAOD::JetB_pt1);
//         HDF_insert("JetB_pt2",&TestNanoAOD::JetB_pt2);
//         HDF_insert("JetB_pt3",&TestNanoAOD::JetB_pt3);
//         HDF_insert("JetB_pt4",&TestNanoAOD::JetB_pt4);

        HDF_insert("match_PhiEta_ZDecayOneSec_JetJet",&TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet);
        HDF_insert("match_PhiEta_BBarGen_JetJet",&TestNanoAOD::match_PhiEta_BBarGen_JetJet);
HDF_insert("match_info",&TestNanoAOD::match_info);


        HDF_insert("matchs_PhiEta_FatJet_ZDecaySec",&TestNanoAOD::match_PhiEta_FatJet_ZDecaySec);
        HDF_insert("matchs_PhiEta_FatJet_ZDecayOne",&TestNanoAOD::match_PhiEta_FatJet_ZDecayOne);
        HDF_insert("matchs_PhiEta_FatJet_B",&TestNanoAOD::match_PhiEta_FatJet_B);
        HDF_insert("matchs_PhiEta_FatJet_Bar",&TestNanoAOD::match_PhiEta_FatJet_Bar);

        HDF_insert("match_info_fatJet",&TestNanoAOD::match_info_fatJet);


        HDF_insert("ZDecayOne_FatJet_pt",&TestNanoAOD::leading_fatJet_pt);
        HDF_insert("ZDecaySec_FatJet_pt",&TestNanoAOD::subleading_fatJet_pt);
        HDF_insert("B_FatJet_pt",&TestNanoAOD::B_fatJet_pt);
        HDF_insert("Bar_FatJet_pt",&TestNanoAOD::Bar_fatJet_pt);

        return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::TestNanoAODRegion() {

    LeptonSelection();
    Get_Leptonic_Info(true, true);
    Get_LepLep_Variables(true, true);
    //Jet selection
    JetSelection();
    METCorrection();


    //-------------------------------------------------------------------------
    // Cut description
    //-------------------------------------------------------------------------
    //if( !(CutCondition) ) return false;           [Example]
    //_cutFlow.at("CutName") += evtWeight;          [Example]

    return true;
}


//-------------------------------------------------------------------------------------------------
// Write your analysis code here
//-------------------------------------------------------------------------------------------------
void HEPHero::TestNanoAODSelection() {


// CRIACAO DA TAG:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TestNanoAOD::Tag_decay_GenZ = 0; // 0 = No match; 1 = z->dd; 2 = z-> uu; 3=z->ss; 4= z->cc; 5 = z->bb; 11=z->ee; 13: z->mumu; 15: z-> tautau; -1: era classificado como um e mudou para outro (caso de dois Z)
        TLorentzVector part_b,part_bar,part_Zdecay_one,part_Zdecay_sec,part_Z,part_a,part_change,part_Higgs;
                part_b.Clear();
                part_bar.Clear();
                part_Zdecay_one.Clear();
                part_Zdecay_sec.Clear();
                part_Z.Clear();
                part_a.Clear();
                part_Higgs.Clear();
                TestNanoAOD::Tag_decay_GenZ = 0;
                //Loop nas particulas do GenPart (não vou usar o NGenJet, pois quero fazer pro caso do ll tb)
        for(int igen = 0; igen < nGenPart; ++igen){
            // ACHANDO os dois Bs que são produzidos juntos ao Gluon!
                        if ( (abs(GenPart_pdgId[igen]) == 5) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 21 && GenPart_genPartIdxMother[GenPart_genPartIdxMother[igen]]==-1 ) ){
                                if (GenPart_pdgId[igen] == 5){
                                        part_b.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],4.18);
                                }
                                if (GenPart_pdgId[igen] == -5){
                                        part_bar.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],4.18);
                                }

                        }
                        // IF DO PSEUDO ESCALAR
                        if ( (abs(GenPart_pdgId[igen]) == 55 or abs(GenPart_pdgId[igen])==54) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 35) ){
                                part_a.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],GenPart_mass[igen]);
                        }
                        //IF DO Z
                        if ( (abs(GenPart_pdgId[igen]) == 23) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 35) ){
                                part_Z.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],GenPart_mass[igen]);
                        }
                        //IF DO HEAVY HIGGS
                        if  ( (abs(GenPart_pdgId[igen]) == 23) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 35) ){
                                part_Higgs.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],GenPart_mass[igen]);
                        }
                        // VAMOS VER SE ACHAMOS UM Z QUE DECAI EM UM MuMu
            if ( (abs(GenPart_pdgId[igen]) == 13) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ){ //ENCONTRAMOS UM Z->mumu
                if (TestNanoAOD::Tag_decay_GenZ != 0 && TestNanoAOD::Tag_decay_GenZ!= 13){
                                TestNanoAOD::Tag_decay_GenZ=-1;
                        }
                        else{
                                TestNanoAOD::Tag_decay_GenZ=13;
                                                                if (GenPart_pdgId[igen] == 13){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.105658);
                                                                }
                                                                if (GenPart_pdgId[igen] == -13){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.105658);
                                                                }
                        }

                }
                // VAMOS VER SE ACHAMOS UM Z QUE DECAI EM UM ElEl
                if ( (abs(GenPart_pdgId[igen]) == 11) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ){ //ENCONTRAMOS UM Z->elel
                        if (TestNanoAOD::Tag_decay_GenZ != 0 && TestNanoAOD::Tag_decay_GenZ!= 11){
                                TestNanoAOD::Tag_decay_GenZ=-1;
                        }
                        else{
                                TestNanoAOD::Tag_decay_GenZ=11;
                                                                if (GenPart_pdgId[igen] == 11){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.000510999);
                                                                }
                                                                if (GenPart_pdgId[igen] == -11){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.000510999);
                                                                }
                        }

                }
                // VAMOS VER SE ACHAMOS UM Z QUE DECAI EM UM TauTau
                if ( (abs(GenPart_pdgId[igen]) == 15) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ){ //ENCONTRAMOS UM Z->TauTau
                        if (TestNanoAOD::Tag_decay_GenZ != 0 && TestNanoAOD::Tag_decay_GenZ!= 15){
                                TestNanoAOD::Tag_decay_GenZ=-1;
                        }
                        else{
                                TestNanoAOD::Tag_decay_GenZ=15;
                                                                if (GenPart_pdgId[igen] == 15){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0);
                                                                }
                                                                if (GenPart_pdgId[igen] == -15){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0);
                                                                }
                        }

                }

                // VAMOS VER SE ACHAMOS UM Z QUE DECAI EM UM down-down
                if ( (abs(GenPart_pdgId[igen]) == 1) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ){ //ENCONTRAMOS UM Z->dd
                        if (TestNanoAOD::Tag_decay_GenZ !=0 && TestNanoAOD::Tag_decay_GenZ!= 1){
                                TestNanoAOD::Tag_decay_GenZ=-1;
                        }
                        else{
                                TestNanoAOD::Tag_decay_GenZ=1;
                                                                if (GenPart_pdgId[igen] == 1){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.0047);
                                                                }
                                                                if (GenPart_pdgId[igen] == -1){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.0047);
                                                                }
                        }

                }
                // VAMOS VER SE ACHAMOS UM Z QUE DECAI EM UM up-up
                if ( (abs(GenPart_pdgId[igen]) == 2) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ){ //ENCONTRAMOS UM Z->uu
                        if (TestNanoAOD::Tag_decay_GenZ !=0 && TestNanoAOD::Tag_decay_GenZ!= 2){
                                TestNanoAOD::Tag_decay_GenZ=-1;
                        }
                        else{
                                TestNanoAOD::Tag_decay_GenZ=2;
                                                                if (GenPart_pdgId[igen] == 2){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.0022);
                                                                }
                                                                if (GenPart_pdgId[igen] == -2){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.0022);
                                                                }
                        }
                }
                // VAMOS VER SE ACHAMOS UM Z QUE DECAI EM UM strange-strange
                if ( (abs(GenPart_pdgId[igen]) == 3) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ){ //ENCONTRAMOS UM Z->ss
                        if (TestNanoAOD::Tag_decay_GenZ !=0 && TestNanoAOD::Tag_decay_GenZ!= 3){
                                TestNanoAOD::Tag_decay_GenZ=-1;
                        }
                        else{
                                TestNanoAOD::Tag_decay_GenZ=3;
                                                                if (GenPart_pdgId[igen] == 3){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.096);
                                                                }
                                                                if (GenPart_pdgId[igen] == -3){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.096);
                                                                }
                        }

                }
                // VAMOS VER SE ACHAMOS UM Z QUE DECAI EM UM charm-charm
                if ( (abs(GenPart_pdgId[igen]) == 4) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ){ //ENCONTRAMOS UM Z->cc
                        if (TestNanoAOD::Tag_decay_GenZ !=0 && TestNanoAOD::Tag_decay_GenZ!= 4){
                                TestNanoAOD::Tag_decay_GenZ=-1;
                        }
                        else{
                                TestNanoAOD::Tag_decay_GenZ=4;
                                                                if (GenPart_pdgId[igen] == 4){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],1.28);
                                                                }
                                                                if (GenPart_pdgId[igen] == -4){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],1.28);
                                                                }
                        }

                }
                // VAMOS VER SE ACHAMOS UM Z QUE DECAI EM UM bottom-bottom
                if ( (abs(GenPart_pdgId[igen]) == 5) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ){ //ENCONTRAMOS UM Z->bb
                        if (TestNanoAOD::Tag_decay_GenZ !=0 && TestNanoAOD::Tag_decay_GenZ!= 5){
                                TestNanoAOD::Tag_decay_GenZ=-1;
                        }
                        else{
                                TestNanoAOD::Tag_decay_GenZ=5;
                                                                if (GenPart_pdgId[igen] == 5){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],4.18);
                                                                }
                                                                if (GenPart_pdgId[igen] == -5){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],4.18);
                                                                }

                        }

                                }
        }

//#############################################################################################################################################
//### FAZENDO UMA DANÇA DAS CADEIRAS PARA ORDENAR O DE MAIOR PT PRO DE MENOR NO CASO DAS PARTICULAS QUE DECAEM DO Z E Bs GERADOS NA PRODUÇÃO ##
//#############################################################################################################################################
        part_change.Clear(); // TlorentzVector feito para salvar informações das particulas
        // Caso dos Bs gerados em produção
        if (part_bar.Pt() > part_b.Pt()){
                part_change.SetPtEtaPhiM(part_b.Pt(),part_b.Eta(),part_b.Phi(),part_b.M()); // Salvando a informação do menos energetico
                part_b = part_bar;
                part_bar = part_change;
                part_change.Clear();
        }

        // Caso do decaimento do Z
        if (part_Zdecay_sec.Pt() > part_Zdecay_one.Pt()){
                part_change.SetPtEtaPhiM(part_Zdecay_one.Pt(),part_Zdecay_one.Eta(),part_Zdecay_one.Phi(),part_Zdecay_one.M()); // Salvando a informação do menos energetico
                part_Zdecay_one = part_Zdecay_sec;
                part_Zdecay_sec = part_change;
                part_change.Clear();
        }


//#############################################################################################################################################
//###################################################   PARTE DO GILSON   #####################################################################
//#############################################################################################################################################
                TestNanoAOD::gilson_pt_genb = part_b.Pt();
                TestNanoAOD::gilson_eta_genb = part_b.Eta();
                TestNanoAOD::gilson_phi_genb = part_b.Phi();
                TestNanoAOD::gilson_mass_genb = part_b.M();

                TestNanoAOD::gilson_pt_genbar = part_bar.Pt();
                TestNanoAOD::gilson_eta_genbar = part_bar.Eta();
                TestNanoAOD::gilson_phi_genbar = part_bar.Phi();
                TestNanoAOD::gilson_mass_genbar = part_bar.M();

                TestNanoAOD::gilson_pt_Zdecay_one = part_Zdecay_one.Pt();
                TestNanoAOD::gilson_eta_Zdecay_one = part_Zdecay_one.Eta();
                TestNanoAOD::gilson_phi_Zdecay_one = part_Zdecay_one.Phi();
                TestNanoAOD::gilson_mass_Zdecay_one = part_Zdecay_one.M();

                TestNanoAOD::gilson_pt_Zdecay_sec = part_Zdecay_sec.Pt();
                TestNanoAOD::gilson_phi_Zdecay_sec = part_Zdecay_sec.Eta();
                TestNanoAOD::gilson_eta_Zdecay_sec = part_Zdecay_sec.Phi();
                TestNanoAOD::gilson_mass_Zdecay_sec = part_Zdecay_sec.M();

                // TestNanoAOD::gilson_pt_Z_2 = part_Z.Pt();
                // TestNanoAOD::gilson_eta_Z_2 = part_Z.Eta();
                // TestNanoAOD::gilson_phi_Z_2 = part_Z.Phi();
                // TestNanoAOD::gilson_mass_Z_2 = part_Z.M();

                TestNanoAOD::gilson_pt_Z = (part_Zdecay_one+part_Zdecay_sec).Pt();
                TestNanoAOD::gilson_eta_Z = (part_Zdecay_one+part_Zdecay_sec).Eta();
                TestNanoAOD::gilson_phi_Z = (part_Zdecay_one+part_Zdecay_sec).Phi();
                TestNanoAOD::gilson_mass_Z = (part_Zdecay_one+part_Zdecay_sec).M();

                TestNanoAOD::gilson_pt_a = part_a.Pt();
                TestNanoAOD::gilson_eta_a = part_a.Eta();
                TestNanoAOD::gilson_phi_a = part_a.Phi();
                TestNanoAOD::gilson_mass_a = part_a.M();

                TestNanoAOD::gilson_pt_H = part_Higgs.Pt();
                TestNanoAOD::gilson_eta_H = part_Higgs.Eta();
                TestNanoAOD::gilson_phi_H = part_Higgs.Phi();
                TestNanoAOD::gilson_mass_H = part_Higgs.M();



                TestNanoAOD::gilson_deltaR_b_ZDecayOne=0;       //FEITO
                TestNanoAOD::gilson_deltaR_b_ZDecaySec=0;       //FEITO
                TestNanoAOD::gilson_deltaR_ZDecayOne_ZDecaySec=0;       //FEITO
                TestNanoAOD::gilson_deltaR_b_z=0;                       //FEITO
                TestNanoAOD::gilson_deltaR_ZDecayOne_z=0;               //FEITO
                TestNanoAOD::gilson_deltaR_ZDecaySec_z=0;               //FEITO
                TestNanoAOD::gilson_mass_b_ZDecayOne=0;                 //FEITO
                TestNanoAOD::gilson_mass_bar_ZDecaySec=0;               //FEITO
                TestNanoAOD::gilson_massTran_z_a=0;                     //FEITO
                TestNanoAOD::gilson_massTran_bZDecayOne_a=0;            //FEITO
                TestNanoAOD::gilson_massTran_bZDecaySec_a=0;            //FEITO
                TestNanoAOD::gilson_deltaPhi_b_a=0;                     //FEITO
                TestNanoAOD::gilson_deltaPhi_bZDecayOne_a=0;            //FEITO
                TestNanoAOD::gilson_deltaPhi_bZDecaySec_a=0; // Essa é a variável que eu não sei se ta certa (FEITO)

// FAZENDO OS VALORES DE DeltaR
        //gilson_deltaR_b_ZDecayOne
        TestNanoAOD::gilson_deltaR_b_ZDecayOne = part_b.DeltaR(part_Zdecay_one);
        //gilson_deltaR_b_ZDecaySec
        TestNanoAOD::gilson_deltaR_b_ZDecaySec = part_b.DeltaR(part_Zdecay_one);
        //gilson_deltaR_ZDecayOne_ZDecaySec
        TestNanoAOD::gilson_deltaR_ZDecayOne_ZDecaySec = part_Zdecay_one.DeltaR(part_Zdecay_sec);
        //gilson_deltaR_b_z
        TestNanoAOD::gilson_deltaR_b_z = part_b.DeltaR((part_Zdecay_one+part_Zdecay_sec));
        //gilson_deltaR_ZDecayOne_z
        TestNanoAOD::gilson_deltaR_ZDecayOne_z = part_Zdecay_one.DeltaR((part_Zdecay_one+part_Zdecay_sec));
        //gilson_deltaR_ZDecaySec_z
        TestNanoAOD::gilson_deltaR_ZDecaySec_z = part_Zdecay_sec.DeltaR((part_Zdecay_one+part_Zdecay_sec));
        //gilson_mass_b_ZDecayOne
        TestNanoAOD::gilson_mass_b_ZDecayOne = (part_b + part_Zdecay_one).M();
        //gilson_mass_bar_ZDecaySec
        TestNanoAOD::gilson_mass_bar_ZDecaySec = (part_bar+part_Zdecay_sec).M();
        //gilson_deltaEta_b_z
        TestNanoAOD::gilson_deltaEta_b_z = (part_b+(part_Zdecay_one+part_Zdecay_sec)).Eta();

        //gilson_deltaPhi_b_a
        TestNanoAOD::gilson_deltaPhi_b_a = abs(part_b.DeltaPhi(part_a));
        if (TestNanoAOD::gilson_deltaPhi_b_a > 3.14159265358979323846264338327950288){TestNanoAOD::gilson_deltaPhi_b_a = 2*3.14159265358979323846264338327950288 - TestNanoAOD::gilson_deltaPhi_b_a;}
        //gilson_deltaPhi_bZDecayOne_a
        TestNanoAOD::gilson_deltaPhi_bZDecayOne_a = abs((part_b+part_Zdecay_one).DeltaPhi(part_a));
        if (TestNanoAOD::gilson_deltaPhi_bZDecayOne_a > 3.14159265358979323846264338327950288){TestNanoAOD::gilson_deltaPhi_bZDecayOne_a = 2*3.14159265358979323846264338327950288 - TestNanoAOD::gilson_deltaPhi_bZDecayOne_a;}
        //gilson_deltaphi_bZDecaySec_a
        TestNanoAOD::gilson_deltaPhi_bZDecaySec_a = abs((part_b+part_Zdecay_sec).DeltaPhi(part_a));
        if (TestNanoAOD::gilson_deltaPhi_bZDecaySec_a > 3.14159265358979323846264338327950288){TestNanoAOD::gilson_deltaPhi_bZDecaySec_a = 2*3.14159265358979323846264338327950288 - TestNanoAOD::gilson_deltaPhi_bZDecaySec_a;}



        ////gilson_massTran_z_a
        //Criacao de uma variavel nova
        TestNanoAOD::gilson_deltaPhi_z_a = abs((part_Zdecay_one+part_Zdecay_sec).DeltaPhi(part_a));
        if (TestNanoAOD::gilson_deltaPhi_z_a > 3.14159265358979323846264338327950288){TestNanoAOD::gilson_deltaPhi_z_a = 2*3.14159265358979323846264338327950288 - TestNanoAOD::gilson_deltaPhi_z_a;}
        TestNanoAOD::gilson_massTran_z_a = sqrt(2*(part_Zdecay_one+part_Zdecay_sec).Pt() * part_a.Pt() * (1- cos(TestNanoAOD::gilson_deltaPhi_z_a) )  );
        //gilson_massTran_bZDecayOne_a
        TestNanoAOD::gilson_massTran_bZDecayOne_a = sqrt(2*(part_b+part_Zdecay_one).Pt() * part_a.Pt() * (1- cos(TestNanoAOD::gilson_deltaPhi_bZDecayOne_a) )  );
        //gilson_massTran_bZDecaySec_a
        TestNanoAOD::gilson_massTran_bZDecaySec_a = sqrt(2*(part_b+part_Zdecay_sec).Pt() * part_a.Pt() * (1- cos(TestNanoAOD::gilson_deltaPhi_bZDecaySec_a) )  );


//#############################################################################################################################################
//####################################################   FIM DA PARTE DO GILSON    ############################################################
//#############################################################################################################################################









//#############################################################################################################################################
//####################################################   INICIO DO Taggers de MATCH    ########################################################
//#############################################################################################################################################
// part_b -> b ou bar com maior pt (criado junto com gluon)
// part_bar -> b ou bar com segundo maior pt (criado junto com gluon)

// Declaracao das variaveis
      TestNanoAOD::match_PhiEta_BBarGen_JetJet = 0;                // 0 não teve match, 1xx, teve match com o bottom de maior pt, 2xx, teve match com o segundo de maior pt, 1000 teve match com o mesmo dos quarks
//      TestNanoAOD::match_PhiEta_BarGen_JetJet = 0;              // 0 não teve match no b quark de segundo maior pt  // 1 teve match entre o segundo b jato
      TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet = 0;        // 0 não teve match  // 11 teve match mas somente entre um dos dois (leading pt) // 12 teve match mas somente entre um dos dois (lesubleading pt) // 20 teve match entre os dois e os demais jatos

      //TestNanoAOD::match_PhiEta_GenPart_GenJet_BBar = 0;


        TLorentzVector vecJet_1;
        TLorentzVector vecJet_2;
        TLorentzVector vecJet_test;
        // int valor_1,valor_2,valor_3,valor_4;
        // valor_1=0;
        // valor_2=0;
        // valor_3=0;
        // valor_4=0;


        // COMEÇANDO COM O match_PhiEta_ZDecayOneSec_JetJet
        vector<int> jatos_ZDecayOne,jatos_ZDecaySec,jatos_BGen,jatos_BarGen;
        jatos_ZDecayOne.clear();
        jatos_ZDecaySec.clear();
        jatos_BGen.clear();
        jatos_BarGen.clear();
        vecJet_1.Clear();
        vecJet_2.Clear();
        vecJet_test.Clear();

        // Nesse loop a ordem da logica vai ser:
        // Pego os jatos selecionados, vou ver quais deles sao compativeis com o GenPart de maior pt vindo do Z (para isso vou usar o tagger, pois consigo ver qual GenPart ele é)
        // Vou excluir das possibilidades aquele que apresentar o MENOR deltaR entre o GenPart e o SelectedJet (menor que 0.4)
        // Dos jatos que sobraram vou testar se possuem deltaR menor que 0.4 com o quark gen com segundo maior pt, proveniente do Z. E pegar o que tiver menor deltaR
        // POssiveis cenarios finais:
        // 0: Não tiveram nenhum jatos que possuissem menos de 0.4 deltaR com o leading quark e o subleading quark
        // 1: Teve um jato compativel com o leading pt e um jato compativel com o subleading pt (distintos)
        // 1xx: Teve somente xx jatos compativeis, e foi do leading pt.
        // 2xx: Teve somente xx jatos compativeis, e foi do subleading pt.
        // 1000: Ambos foram compativeis mas somente com o MESMO JATO



        float deltaRZDecayOne = 0.4;
        for(int iSeljet = 0; iSeljet < selectedJet.size(); ++iSeljet){
                // Esse loop é pra testar se o quark de maior pt que decaiu do Z tem um match. E se sim, vamos registrar o jato que teve o menor deltaR entre eles
                int ijet = selectedJet.at(iSeljet);
                vecJet_1.SetPtEtaPhiM(Jet_pt[selectedJet.at(iSeljet)], Jet_eta[selectedJet.at(iSeljet)], Jet_phi[selectedJet.at(iSeljet)], Jet_mass[selectedJet.at(iSeljet)]);
                float DEtab = vecJet_1.Eta() - part_Zdecay_one.Eta();
                float DPhib = vecJet_1.Phi() - part_Zdecay_one.Phi();
                if( DPhib > M_PI ) DPhib = 2*M_PI - DPhib;
                float DRb = sqrt(pow(DEtab,2) + pow(DPhib,2));
                // std::cout<<"DRb"<<std::endl;
                // std::cout<<DRb<<std::endl;
                // std::cout<<deltaRZDecayOne<<std::endl;
                if( DRb < deltaRZDecayOne ) {
                        // std::cout<<"AQUIIIIIIIIIIIIIIIIIIIIIIIII"<<std::endl;
                        // std::cout<<deltaRZDecayOne<<std::endl;
                        if (TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet==0){
                                TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet=100;
                        }
                        if (TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet>99){
                                TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet+=1;       // completando 100
                        }
                        jatos_ZDecayOne.push_back(iSeljet);                 // Salvamos a informação do jatos que foram compativeis
      //                  std::cout<<"iSeljet b: "<<iSeljet<<std::endl;
                        deltaRZDecayOne = DRb;                              // Vamos restringindo o espaço para que no final do vetor tenha o index do jato com menor deltaR
                }
        }


        float deltaRZDecaySec = 0.4;
        for(int iSeljet = 0; iSeljet < selectedJet.size(); ++iSeljet){
                // Esse loop é pra testar se o subleading quark que decaiu do Z tem um match. E se sim, vamos registrar o jato que teve o menor deltaR entre eles
                int ijet = selectedJet.at(iSeljet);
                vecJet_1.SetPtEtaPhiM(Jet_pt[selectedJet.at(iSeljet)], Jet_eta[selectedJet.at(iSeljet)], Jet_phi[selectedJet.at(iSeljet)], Jet_mass[selectedJet.at(iSeljet)]);
                float DEtab = vecJet_1.Eta() - part_Zdecay_sec.Eta();
                float DPhib = vecJet_1.Phi() - part_Zdecay_sec.Phi();
                if( DPhib > M_PI ) DPhib = 2*M_PI - DPhib;
                float DRb = sqrt(pow(DEtab,2) + pow(DPhib,2));

                if( DRb < deltaRZDecaySec ) {
   //                     std::cout<<TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet<<std::endl;
                        if (TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet==0){          // Não achou um match entre o leading quark
                                TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet=200;
                        }
                        if (TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet>199){
                                TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet+=1;   // Até o momento somente o quark subleading foi identificado
                        }
                        if (TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet > 99 && TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet < 199){ //Significa disser que ele já achou um valor compativel com o leading quark
                                //std::cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<std::endl;
                                TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet=-1;
                        }
                        jatos_ZDecaySec.push_back(iSeljet);                 // Salvamos a informação do jatos que foram compativeis
     //                   std::cout<<"iSeljet bar: "<<iSeljet<<std::endl;
                        deltaRZDecaySec = DRb;                              // Vamos restringindo o espaço para que no final do vetor tenha o index do jato com menor deltaR
                }


        }

        // Agora vamos ver se foi o caso 1 ou 1000
        if (TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet == -1){
                if (jatos_ZDecaySec.size()>0 && jatos_ZDecayOne.size()>0){
                        if (jatos_ZDecaySec.back() == jatos_ZDecayOne.back()){
                                TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet = 300; // Pois representa que um unico jato foi o mais compativel com os dois ao mesmo tempo
                        }
                        else if (jatos_ZDecaySec.back() != jatos_ZDecayOne.back()) {
                                TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet = 1; // Pois representa que um unico jato foi o mais compativel com o leading quark, enquanto outro jato foi o mais compativel com o subleading quark
                        }

                }
        }



 //       std::cout<<"match_PhiEta_ZDecayOneSec_JetJet teve valor de:"<<std::endl;
 //       std::cout<<TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet<<std::endl;



// AGORA VAMOS FAZER O TAGGER DO match_PhiEta_BGen_JetJet
///////////////////////////////////////////////////////////////////////////////////////


      float deltaRBgen = 0.4;
        for(int iSeljet = 0; iSeljet < selectedJet.size(); ++iSeljet){
                // Esse loop é pra testar se o subleading quark que decaiu do Z tem um match. E se sim, vamos registrar o jato que teve o menor deltaR entre eles
                int ijet = selectedJet.at(iSeljet);
                // Vou excluir todos os jatos que foram mais compativeis com o quarks que decairam do Z
//                if(jatos_ZDecaySec.size()>0){if (iSeljet==jatos_ZDecaySec.back()){continue;}}
//              if(jatos_ZDecayOne.size()>0){if(iSeljet==jatos_ZDecayOne.back()){continue;}}

                vecJet_1.SetPtEtaPhiM(Jet_pt[selectedJet.at(iSeljet)], Jet_eta[selectedJet.at(iSeljet)], Jet_phi[selectedJet.at(iSeljet)], Jet_mass[selectedJet.at(iSeljet)]);
                float DEtab = vecJet_1.Eta() - part_b.Eta();
                float DPhib = vecJet_1.Phi() - part_b.Phi();
                if( DPhib > M_PI ) DPhib = 2*M_PI - DPhib;
                float DRb = sqrt(pow(DEtab,2) + pow(DPhib,2));

                if( DRb < deltaRBgen ) {
                        std::cout<<TestNanoAOD::match_PhiEta_BBarGen_JetJet<<std::endl;
                        if (TestNanoAOD::match_PhiEta_BBarGen_JetJet==0){          // Não achou um match entre o leading quark
                                TestNanoAOD::match_PhiEta_BBarGen_JetJet=100;
                        }
                        if (TestNanoAOD::match_PhiEta_BBarGen_JetJet>99){
                                TestNanoAOD::match_PhiEta_BBarGen_JetJet+=1;   // Até o momento somente o quark subleading foi identificado
                        }
                        //if (TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet > 99 && TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet < 199){ //Significa disser que ele já achou um valor compativel com o leading quark
                                //std::cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<std::endl;
                          //      TestNanoAOD::match_PhiEta_ZDecayOneSec_JetJet=-1;
                       // }



                        jatos_BGen.push_back(iSeljet);                 // Salvamos a informação do jatos que foram compativeis
        //                std::cout<<"iSeljet bar: "<<iSeljet<<std::endl;
                        deltaRBgen = DRb;                              // Vamos restringindo o espaço para que no final do vetor tenha o index do jato com menor deltaR
                }
        }





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AGORA VAMOS FAZER O TAGGER DO match_PhiEta_BGen_JetJet
///////////////////////////////////////////////////////////////////////////////////////


      float deltaRBargen = 0.4;
        for(int iSeljet = 0; iSeljet < selectedJet.size(); ++iSeljet){
                // Esse loop é pra testar se o subleading quark que decaiu do Z tem um match. E se sim, vamos registrar o jato que teve o menor deltaR entre eles
                int ijet = selectedJet.at(iSeljet);
                // Vou excluir todos os jatos que foram mais compativeis com o quarks que decairam do Z
//                if(jatos_ZDecaySec.size()>0){if (iSeljet==jatos_ZDecaySec.back()){continue;}}
//              if(jatos_ZDecayOne.size()>0){if(iSeljet==jatos_ZDecayOne.back()){continue;}}


                vecJet_1.SetPtEtaPhiM(Jet_pt[selectedJet.at(iSeljet)], Jet_eta[selectedJet.at(iSeljet)], Jet_phi[selectedJet.at(iSeljet)], Jet_mass[selectedJet.at(iSeljet)]);
                float DEtab = vecJet_1.Eta() - part_bar.Eta();
                float DPhib = vecJet_1.Phi() - part_bar.Phi();
                if( DPhib > M_PI ) DPhib = 2*M_PI - DPhib;
                float DRb = sqrt(pow(DEtab,2) + pow(DPhib,2));

                if( DRb < deltaRBargen ) {
                       // std::cout<<TestNanoAOD::match_PhiEta_BBarGen_JetJet<<std::endl;
                        if (TestNanoAOD::match_PhiEta_BBarGen_JetJet==0){          // Não achou um match entre o leading quark
                                TestNanoAOD::match_PhiEta_BBarGen_JetJet=200;
                        }
                        if (TestNanoAOD::match_PhiEta_BBarGen_JetJet>199){
                                TestNanoAOD::match_PhiEta_BBarGen_JetJet+=1;   // Até o momento somente o quark subleading foi identificado
                        }
                        if (TestNanoAOD::match_PhiEta_BBarGen_JetJet > 99 && TestNanoAOD::match_PhiEta_BBarGen_JetJet < 199){ //Significa disser que ele já achou um valor compativel com o leading quark
                                //std::cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<std::endl;
                                TestNanoAOD::match_PhiEta_BBarGen_JetJet=-1;
                        }



                        jatos_BarGen.push_back(iSeljet);                 // Salvamos a informação do jatos que foram compativeis
        //              std::cout<<"iSeljet bar: "<<iSeljet<<std::endl;
                        deltaRBargen = DRb;                              // Vamos restringindo o espaço para que no final do vetor tenha o index do jato com menor deltaR



                }


        }


if (TestNanoAOD::match_PhiEta_BBarGen_JetJet==-1){
        if (jatos_BGen.size()>0 && jatos_BarGen.size()>0){
                if (jatos_BGen.back() == jatos_BarGen.back()){
                        TestNanoAOD::match_PhiEta_BBarGen_JetJet = 300; //Pois os dois quarks produzidos junto ao gluon acharam o mesmo jato como mais compaivel
                }
                else if (jatos_BGen.back()!= jatos_BarGen.back()){
                        TestNanoAOD::match_PhiEta_BBarGen_JetJet = 1; // Pois representa que ambos encontraram jatos diferentes
                }

        }


}






 // std::cout<<"match_PhiEta_BBarGen_JetJet teve valor de:"<<std::endl;
 // std::cout<<TestNanoAOD::match_PhiEta_BBarGen_JetJet<<std::endl;



///////// Criacao do tagger que vai dar informacoes se os jatos foram os mesmos ou nao
// match_info
//int value_ZDecayOne;value_ZDecaySec,value_GenB,value_GenBar;
// 1-> nao teve jato compativeis
// 2-> teve jato compativeis e nao foram iguais aos dos outros
// 3 -> teve jato compativel e foi igual ao dos outros

    int compatibilidade[4] = {2, 2, 2, 2};

    // Verificar se algum vetor está vazio, se sim, recebe valor 1
    if (jatos_ZDecayOne.empty()) compatibilidade[0] = 1;
    if (jatos_ZDecaySec.empty()) compatibilidade[1] = 1;
    if (jatos_BGen.empty()) compatibilidade[2] = 1;
    if (jatos_BarGen.empty()) compatibilidade[3] = 1;

    // Verificar as compatibilidades e atribuir o mesmo número se forem compatíveis
    int grupo = 3; // Começamos com o número 3, pois 1 é "vetor vazio" e 2 é "sem compatibilidade"

    // Comparar o último elemento de cada jato, se os jatos não estiverem vazios
    if (!jatos_ZDecayOne.empty() && !jatos_ZDecaySec.empty() && jatos_ZDecayOne.back() == jatos_ZDecaySec.back()) {
        compatibilidade[0] = compatibilidade[1] = grupo++;
    }
    if (!jatos_ZDecayOne.empty() && !jatos_BGen.empty() && jatos_ZDecayOne.back() == jatos_BGen.back()) {
        if (compatibilidade[0] == 2) compatibilidade[0] = compatibilidade[2] = grupo++;
        else compatibilidade[2] = compatibilidade[0]; // jato1 já tem um grupo
    }
    if (!jatos_ZDecayOne.empty() && !jatos_BarGen.empty() && jatos_ZDecayOne.back() == jatos_BarGen.back()) {
        if (compatibilidade[0] == 2) compatibilidade[0] = compatibilidade[3] = grupo++;
        else compatibilidade[3] = compatibilidade[0]; // jato1 já tem um grupo
    }

    // Verificar compatibilidade entre jato2 e outros
    if (!jatos_ZDecaySec.empty() && !jatos_BGen.empty() && jatos_ZDecaySec.back() == jatos_BGen.back()) {
        if (compatibilidade[1] == 2) compatibilidade[1] = compatibilidade[2] = grupo++;
        else compatibilidade[2] = compatibilidade[1]; // jato2 já tem um grupo
    }
    if (!jatos_ZDecaySec.empty() && !jatos_BarGen.empty() && jatos_ZDecaySec.back() == jatos_BarGen.back()) {
        if (compatibilidade[1] == 2) compatibilidade[1] = compatibilidade[3] = grupo++;
        else compatibilidade[3] = compatibilidade[1]; // jato2 já tem um grupo
    }

    // Verificar compatibilidade entre jato3 e jato4
    if (!jatos_BGen.empty() && !jatos_BarGen.empty() && jatos_BGen.back() == jatos_BarGen.back()) {
        if (compatibilidade[2] == 2) compatibilidade[2] = compatibilidade[3] = grupo++;
        else compatibilidade[3] = compatibilidade[2]; // jato3 já tem um grupo
    }

    // Montar o número final de 4 dígitos
    int resultado = compatibilidade[0] * 1000 + compatibilidade[1] * 100 + compatibilidade[2] * 10 + compatibilidade[3];

    TestNanoAOD::match_info = resultado;

//#############################################################################################################################################
//####################################################   FIM DO Taggers de MATCH    ###########################################################
//#############################################################################################################################################
//#############################################################################################################################################
//##########################################   Inicio DO Taggers de MATCH do FATJET ###########################################################
//#############################################################################################################################################

float deltaRFatJetWithZDecayOne = 0.8;
float deltaRFatJetWithZDecaySec = 0.8;
float deltaRFatJetWithB = 0.8;
float deltaRFatJetWithBar = 0.8;
vector<int> Fatjatos_ZDecayOne,Fatjatos_ZDecaySec,Fatjatos_BGen,Fatjatos_BarGen;
Fatjatos_ZDecayOne.clear();
Fatjatos_ZDecaySec.clear();
Fatjatos_BGen.clear();
Fatjatos_BarGen.clear();
TLorentzVector vecFatJet_1;

TestNanoAOD::leading_fatJet_pt = -1;
TestNanoAOD::subleading_fatJet_pt = -1;
TestNanoAOD::B_fatJet_pt = -1;
TestNanoAOD::Bar_fatJet_pt = -1;




for(int iFatjet = 0; iFatjet < nFatJet; ++iFatjet){
        vecFatJet_1.SetPtEtaPhiM(FatJet_pt[iFatjet], FatJet_eta[iFatjet], FatJet_phi[iFatjet], FatJet_mass[iFatjet]);
        // PRO CASO DO ZDECAYONE
        float DEtab = vecFatJet_1.Eta() - part_Zdecay_one.Eta();
        float DPhib = vecFatJet_1.Phi() - part_Zdecay_one.Phi();
        if( DPhib > M_PI ) DPhib = 2*M_PI - DPhib;
        int DRb = sqrt(pow(DEtab,2) + pow(DPhib,2));
        if( DRb < deltaRFatJetWithZDecayOne ) {
                Fatjatos_ZDecayOne.push_back(iFatjet);                 // Salvamos a informação do jatos que foram compativeis
                TestNanoAOD::leading_fatJet_pt = vecFatJet_1.Pt();
                deltaRFatJetWithZDecayOne = DRb;                              // Vamos restringindo o espaço para que no final do vetor tenha o index do jato com menor deltaR
        }



        // PRO CASO DO ZDECAYSEC
        DEtab = vecFatJet_1.Eta() - part_Zdecay_sec.Eta();
        DPhib = vecFatJet_1.Phi() - part_Zdecay_sec.Phi();
        if( DPhib > M_PI ) DPhib = 2*M_PI - DPhib;
        DRb = sqrt(pow(DEtab,2) + pow(DPhib,2));
        if( DRb < deltaRFatJetWithZDecaySec ) {
                Fatjatos_ZDecaySec.push_back(iFatjet);                 // Salvamos a informação do jatos que foram compativeis
                TestNanoAOD::subleading_fatJet_pt = vecFatJet_1.Pt();
                deltaRFatJetWithZDecaySec = DRb;                              // Vamos restringindo o espaço para que no final do vetor tenha o index do jato com menor deltaR
        }


        // PRO CASO DO B
        DEtab = vecFatJet_1.Eta() - part_b.Eta();
        DPhib = vecFatJet_1.Phi() - part_b.Phi();
        if( DPhib > M_PI ) DPhib = 2*M_PI - DPhib;
        DRb = sqrt(pow(DEtab,2) + pow(DPhib,2));
        if( DRb < deltaRFatJetWithB ) {
                Fatjatos_BGen.push_back(iFatjet);                 // Salvamos a informação do jatos que foram compativeis
                TestNanoAOD::B_fatJet_pt = vecFatJet_1.Pt();
                deltaRFatJetWithB = DRb;                              // Vamos restringindo o espaço para que no final do vetor tenha o index do jato com menor deltaR


        }


        // PRO CASO DO BAR
        DEtab = vecFatJet_1.Eta() - part_bar.Eta();
        DPhib = vecFatJet_1.Phi() - part_bar.Phi();
        if( DPhib > M_PI ) DPhib = 2*M_PI - DPhib;
        DRb = sqrt(pow(DEtab,2) + pow(DPhib,2));
        if( DRb < deltaRFatJetWithBar) {
                Fatjatos_BarGen.push_back(iFatjet);                 // Salvamos a informação do jatos que foram compativeis
                TestNanoAOD::Bar_fatJet_pt = vecFatJet_1.Pt();
                deltaRFatJetWithBar = DRb;                              // Vamos restringindo o espaço para que no final do vetor tenha o index do jato com menor deltaR
        }
}




 TestNanoAOD::match_PhiEta_FatJet_ZDecaySec = Fatjatos_ZDecaySec.size();
 TestNanoAOD::match_PhiEta_FatJet_ZDecayOne = Fatjatos_ZDecayOne.size();
 TestNanoAOD::match_PhiEta_FatJet_B = Fatjatos_BGen.size();
 TestNanoAOD::match_PhiEta_FatJet_Bar = Fatjatos_BarGen.size();


// AGORA VAMOS FAZER AS COMBINAÇÕES

    //compatibilidade[4] = {2, 2, 2, 2};

    // Verificar se algum vetor está vazio, se sim, recebe valor 1
    if (Fatjatos_ZDecayOne.empty()) compatibilidade[0] = 1;
    if (Fatjatos_ZDecaySec.empty()) compatibilidade[1] = 1;
    if (Fatjatos_BGen.empty()) compatibilidade[2] = 1;
    if (Fatjatos_BarGen.empty()) compatibilidade[3] = 1;

    // Verificar as compatibilidades e atribuir o mesmo número se forem compatíveis
    grupo = 3; // Começamos com o número 3, pois 1 é "vetor vazio" e 2 é "sem compatibilidade"

    // Comparar o último elemento de cada jato, se os jatos não estiverem vazios
    if (!Fatjatos_ZDecayOne.empty() && !Fatjatos_ZDecaySec.empty() && Fatjatos_ZDecayOne.back() == Fatjatos_ZDecaySec.back()) {
        compatibilidade[0] = compatibilidade[1] = grupo++;
    }
    if (!Fatjatos_ZDecayOne.empty() && !Fatjatos_BGen.empty() && Fatjatos_ZDecayOne.back() == Fatjatos_BGen.back()) {
        if (compatibilidade[0] == 2) compatibilidade[0] = compatibilidade[2] = grupo++;
        else compatibilidade[2] = compatibilidade[0]; // jato1 já tem um grupo
    }
    if (!Fatjatos_ZDecayOne.empty() && !Fatjatos_BarGen.empty() && Fatjatos_ZDecayOne.back() == Fatjatos_BarGen.back()) {
        if (compatibilidade[0] == 2) compatibilidade[0] = compatibilidade[3] = grupo++;
        else compatibilidade[3] = compatibilidade[0]; // jato1 já tem um grupo
    }

    // Verificar compatibilidade entre jato2 e outros
    if (!Fatjatos_ZDecaySec.empty() && !Fatjatos_BGen.empty() && Fatjatos_ZDecaySec.back() == Fatjatos_BGen.back()) {
        if (compatibilidade[1] == 2) compatibilidade[1] = compatibilidade[2] = grupo++;
        else compatibilidade[2] = compatibilidade[1]; // jato2 já tem um grupo
    }
    if (!Fatjatos_ZDecaySec.empty() && !Fatjatos_BarGen.empty() && Fatjatos_ZDecaySec.back() == Fatjatos_BarGen.back()) {
        if (compatibilidade[1] == 2) compatibilidade[1] = compatibilidade[3] = grupo++;
        else compatibilidade[3] = compatibilidade[1]; // jato2 já tem um grupo
    }

    // Verificar compatibilidade entre jato3 e jato4
    if (!Fatjatos_BGen.empty() && !Fatjatos_BarGen.empty() && Fatjatos_BGen.back() == Fatjatos_BarGen.back()) {
        if (compatibilidade[2] == 2) compatibilidade[2] = compatibilidade[3] = grupo++;
        else compatibilidade[3] = compatibilidade[2]; // jato3 já tem um grupo
    }

    // Montar o número final de 4 dígitos
    resultado = compatibilidade[0] * 1000 + compatibilidade[1] * 100 + compatibilidade[2] * 10 + compatibilidade[3];

    TestNanoAOD::match_info_fatJet = resultado;




















//####################################################   FIM DO Taggers de MATCH    ###########################################################




    //_histograms2D.at("histogram2DName").Fill( var1, var2, evtWeight );        [Example]

    //======FILL THE OUTPUT TREE===================================================================
    //_outputTree->Fill();

    //======FILL THE OUTPUT HDF5 INFO===============================================================
    HDF_fill();

    return;
}


//-------------------------------------------------------------------------------------------------
// Produce systematic histograms
//-------------------------------------------------------------------------------------------------
void HEPHero::TestNanoAODSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishTestNanoAOD() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
