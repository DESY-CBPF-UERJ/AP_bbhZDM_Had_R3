#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace Study_GEN{

    //int variable1Name;   [example]

    int Tag_decay_GenZ;
    float FatJet_pt,FatJet_msoftdrop;


    // Variaveis de GEN
    float GEN_part_z_pt, GEN_part_z_eta, GEN_part_z_phi, GEN_part_z_mass, GEN_part_z_number;
    float GEN_part_h_pt, GEN_part_h_eta, GEN_part_h_phi, GEN_part_h_mass, GEN_part_h_number;
    float GEN_part_b_pt, GEN_part_b_eta, GEN_part_b_phi, GEN_part_b_mass, GEN_part_b_number;
    float GEN_part_bar_pt, GEN_part_bar_eta, GEN_part_bar_phi, GEN_part_bar_mass, GEN_part_bar_number;
    float GEN_part_a_pt, GEN_part_a_eta, GEN_part_a_phi, GEN_part_a_mass, GEN_part_a_number;
    float GEN_met_pt, GEN_met_phi;
    float GEN_part_Q1_pt, GEN_part_Q1_eta, GEN_part_Q1_phi, GEN_part_Q1_mass, GEN_part_Q1_number;
    float GEN_part_Q2_pt, GEN_part_Q2_eta, GEN_part_Q2_phi, GEN_part_Q2_mass, GEN_part_Q2_number;



    float GEN_max_delta_eta_part_jetB_zh;
    float GEN_mass_inv_zh_close_part_jetB,GEN_min_mass_inv_zh_close_part_jetB,GEN_max_mass_inv_zh_close_part_jetB;
    float GEN_mass_tran_met_close_part_jetB,GEN_min_mass_tran_met_close_part_jetB,GEN_max_mass_tran_met_close_part_jetB;
    float GEN_number_of_part_jetB_out_zh;
    float GEN_number_of_part_jetB_in_zh;


    float RECO_max_delta_eta_part_jetB_zh;
    float RECO_mass_inv_zh_close_part_jetB,RECO_min_mass_inv_zh_close_part_jetB,RECO_max_mass_inv_zh_close_part_jetB;
    float RECO_mass_tran_met_close_part_jetB,RECO_min_mass_tran_met_close_part_jetB,RECO_max_mass_tran_met_close_part_jetB;
    float RECO_number_of_part_jetB_out_zh;
    float RECO_number_of_part_jetB_in_zh;


    float GEN_deltaR_FatJet_METJetB, RECO_deltaPhi_FatJet_METJetB;
    float RECO_true_mass_tran_met_close_part_jetB;

    float RECO_deltaR_FatJet_JetB_less_deltaR,RECO_deltaR_FatJet_JetB_more_deltaR,RECO_deltaR_FatJet_JetB_more_deltaphi,RECO_deltaR_FatJet_JetB_less_deltaphi,RECO_deltaR_FatJet_JetB_less_pt,RECO_deltaR_FatJet_JetB_more_pt;

float RECO_deltaEta_FatJet_JetB_less_deltaR,RECO_deltaEta_FatJet_JetB_more_deltaR,RECO_deltaEta_FatJet_JetB_more_deltaphi,RECO_deltaEta_FatJet_JetB_less_deltaphi,RECO_deltaEta_FatJet_JetB_less_pt,RECO_deltaEta_FatJet_JetB_more_pt;

float RECO_deltaPhi_FatJet_JetB_less_deltaR,RECO_deltaPhi_FatJet_JetB_more_deltaR,RECO_deltaPhi_FatJet_JetB_more_deltaphi,RECO_deltaPhi_FatJet_JetB_less_deltaphi,RECO_deltaPhi_FatJet_JetB_less_pt,RECO_deltaPhi_FatJet_JetB_more_pt;

float RECO_deltaPhi_MET_JetB_more_deltaphi,RECO_deltaPhi_MET_JetB_less_deltaphi,RECO_deltaPhi_MET_JetB_less_pt,RECO_deltaPhi_MET_JetB_more_pt;

float RECO_deltaPhi_MET_FatJet;

int GEN_qq_inside_zh;

}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupStudy_GEN() {

    _cutFlow.insert(pair<string,double>("00_NLeptons_g_0", 0) );
	_cutFlow.insert(pair<string,double>("01_NbJets_g_0", 0) );
	_cutFlow.insert(pair<string,double>("02_MET_MHT_g_200", 0) );
	_cutFlow.insert(pair<string,double>("03_NFatJets_g_0", 0) );
	_cutFlow.insert(pair<string,double>("04_FatJet_Pt_g_200", 0) );
	_cutFlow.insert(pair<string,double>("05_Omega_g_0p3", 0) );
	_cutFlow.insert(pair<string,double>("06_Signal_like", 0) );

    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
               
    HDF_insert("Nbjets", &Nbjets);
    HDF_insert("HT", &HT);
    HDF_insert("OmegaMin", &OmegaMin);
    HDF_insert("FMax", &FMax);
    HDF_insert("MHT", &MHT);
    HDF_insert("MET_pt", &MET_pt);
    HDF_insert("MDT", &MDT);
    HDF_insert("MET_FatJet_deltaPhi", &MET_FatJet_deltaPhi);
    HDF_insert("MET_FatJet_Mt", &MET_FatJet_Mt);
    HDF_insert("RT_1", &RT_1);
    HDF_insert("RT_3", &RT_3);
    HDF_insert("tauT", &tauT);
                                        
    HDF_insert("FatJet_pt", &Study_GEN::FatJet_pt);									        
    HDF_insert("FatJet_msoftdrop", &Study_GEN::FatJet_msoftdrop);										
    HDF_insert("signal_tag", &signal_tag);

    HDF_insert("Tag_decay_GenZ",&Study_GEN::Tag_decay_GenZ);

   // --- GEN parts ---
    HDF_insert("GEN_part_z_pt",&Study_GEN::GEN_part_z_pt);
    HDF_insert("GEN_part_z_eta",&Study_GEN::GEN_part_z_eta);
    HDF_insert("GEN_part_z_phi",&Study_GEN::GEN_part_z_phi);
    HDF_insert("GEN_part_z_mass",&Study_GEN::GEN_part_z_mass);
    HDF_insert("GEN_part_z_number",&Study_GEN::GEN_part_z_number);
    
    HDF_insert("GEN_part_h_pt",&Study_GEN::GEN_part_h_pt);
    HDF_insert("GEN_part_h_eta",&Study_GEN::GEN_part_h_eta);
    HDF_insert("GEN_part_h_phi",&Study_GEN::GEN_part_h_phi);
    HDF_insert("GEN_part_h_mass",&Study_GEN::GEN_part_h_mass);
    HDF_insert("GEN_part_h_number",&Study_GEN::GEN_part_h_number);
    
    HDF_insert("GEN_part_b_pt",&Study_GEN::GEN_part_b_pt);
    HDF_insert("GEN_part_b_eta",&Study_GEN::GEN_part_b_eta);
    HDF_insert("GEN_part_b_phi",&Study_GEN::GEN_part_b_phi);
    HDF_insert("GEN_part_b_mass",&Study_GEN::GEN_part_b_mass);
    HDF_insert("GEN_part_b_number",&Study_GEN::GEN_part_b_number);
    
    HDF_insert("GEN_part_bar_pt",&Study_GEN::GEN_part_bar_pt);
    HDF_insert("GEN_part_bar_eta",&Study_GEN::GEN_part_bar_eta);
    HDF_insert("GEN_part_bar_phi",&Study_GEN::GEN_part_bar_phi);
    HDF_insert("GEN_part_bar_mass",&Study_GEN::GEN_part_bar_mass);
    HDF_insert("GEN_part_bar_number",&Study_GEN::GEN_part_bar_number);

    HDF_insert("GEN_part_a_pt",&Study_GEN::GEN_part_a_pt);
    HDF_insert("GEN_part_a_eta",&Study_GEN::GEN_part_a_eta);
    HDF_insert("GEN_part_a_phi",&Study_GEN::GEN_part_a_phi);
    HDF_insert("GEN_part_a_mass",&Study_GEN::GEN_part_a_mass);
    HDF_insert("GEN_part_a_number",&Study_GEN::GEN_part_a_number);

    HDF_insert("GEN_part_Q1_pt",&Study_GEN::GEN_part_Q1_pt);
    HDF_insert("GEN_part_Q1_eta",&Study_GEN::GEN_part_Q1_eta);
    HDF_insert("GEN_part_Q1_phi",&Study_GEN::GEN_part_Q1_phi);
    HDF_insert("GEN_part_Q1_mass",&Study_GEN::GEN_part_Q1_mass);
    HDF_insert("GEN_part_Q1_number",&Study_GEN::GEN_part_Q1_number);

    HDF_insert("GEN_part_Q2_pt",&Study_GEN::GEN_part_Q2_pt);
    HDF_insert("GEN_part_Q2_eta",&Study_GEN::GEN_part_Q2_eta);
    HDF_insert("GEN_part_Q2_phi",&Study_GEN::GEN_part_Q2_phi);
    HDF_insert("GEN_part_Q2_mass",&Study_GEN::GEN_part_Q2_mass);
    HDF_insert("GEN_part_Q2_number",&Study_GEN::GEN_part_Q2_number);

    
    // --- GEN MET ---
    HDF_insert("GEN_met_pt",&Study_GEN::GEN_met_pt);
    HDF_insert("GEN_met_phi",&Study_GEN::GEN_met_phi);
    
    // --- GEN max delta eta ---
    HDF_insert("GEN_max_delta_eta_part_jetB_zh",&Study_GEN::GEN_max_delta_eta_part_jetB_zh);
    
    // --- GEN mass inv ---
    HDF_insert("GEN_mass_inv_zh_close_part_jetB",&Study_GEN::GEN_mass_inv_zh_close_part_jetB);
    HDF_insert("GEN_max_mass_inv_zh_close_part_jetB",&Study_GEN::GEN_max_mass_inv_zh_close_part_jetB);
    HDF_insert("GEN_min_mass_inv_zh_close_part_jetB",&Study_GEN::GEN_min_mass_inv_zh_close_part_jetB);

    // --- GEN mass inv ---
    HDF_insert("GEN_mass_tran_met_close_part_jetB",&Study_GEN::GEN_mass_tran_met_close_part_jetB);
    HDF_insert("GEN_max_mass_tran_met_close_part_jetB",&Study_GEN::GEN_max_mass_tran_met_close_part_jetB);
    HDF_insert("GEN_min_mass_tran_met_close_part_jetB",&Study_GEN::GEN_min_mass_tran_met_close_part_jetB);
    
    
    
    // --- GEN numbers of jet/part in/out ---
    HDF_insert("GEN_number_of_part_jetB_out_zh",&Study_GEN::GEN_number_of_part_jetB_out_zh);
    
    
    HDF_insert("GEN_number_of_part_jetB_in_zh",&Study_GEN::GEN_number_of_part_jetB_in_zh);


    // ======================== RECO =================================================

    HDF_insert("RECO_max_delta_eta_part_jetB_zh",&Study_GEN::RECO_max_delta_eta_part_jetB_zh);
    

    HDF_insert("RECO_mass_inv_zh_close_part_jetB",&Study_GEN::RECO_mass_inv_zh_close_part_jetB);
    HDF_insert("RECO_max_mass_inv_zh_close_part_jetB",&Study_GEN::RECO_max_mass_inv_zh_close_part_jetB);
    HDF_insert("RECO_min_mass_inv_zh_close_part_jetB",&Study_GEN::RECO_min_mass_inv_zh_close_part_jetB);


    HDF_insert("RECO_mass_tran_met_close_part_jetB",&Study_GEN::RECO_mass_tran_met_close_part_jetB);
    HDF_insert("RECO_max_mass_tran_met_close_part_jetB",&Study_GEN::RECO_max_mass_tran_met_close_part_jetB);
    HDF_insert("RECO_min_mass_tran_met_close_part_jetB",&Study_GEN::RECO_min_mass_tran_met_close_part_jetB);

    HDF_insert("RECO_number_of_part_jetB_out_zh",&Study_GEN::RECO_number_of_part_jetB_out_zh);
    HDF_insert("RECO_number_of_part_jetB_in_zh",&Study_GEN::RECO_number_of_part_jetB_in_zh);
    HDF_insert("RECO_deltaPhi_FatJet_METJetB",&Study_GEN::RECO_deltaPhi_FatJet_METJetB);
    HDF_insert("GEN_deltaR_FatJet_METJetB",&Study_GEN::GEN_deltaR_FatJet_METJetB);
    HDF_insert("RECO_mass_tran_met_true_close_part_jetB",&Study_GEN::RECO_true_mass_tran_met_close_part_jetB);


    HDF_insert("RECO_deltaR_FatJet_JetB_less_deltaR", &Study_GEN::RECO_deltaR_FatJet_JetB_less_deltaR);
    HDF_insert("RECO_deltaR_FatJet_JetB_more_deltaR", &Study_GEN::RECO_deltaR_FatJet_JetB_more_deltaR);
    HDF_insert("RECO_deltaR_FatJet_JetB_more_deltaphi", &Study_GEN::RECO_deltaR_FatJet_JetB_more_deltaphi);
    HDF_insert("RECO_deltaR_FatJet_JetB_less_deltaphi", &Study_GEN::RECO_deltaR_FatJet_JetB_less_deltaphi);
    HDF_insert("RECO_deltaR_FatJet_JetB_less_pt", &Study_GEN::RECO_deltaR_FatJet_JetB_less_pt);
    HDF_insert("RECO_deltaR_FatJet_JetB_more_pt", &Study_GEN::RECO_deltaR_FatJet_JetB_more_pt);
    
    HDF_insert("RECO_deltaEta_FatJet_JetB_less_deltaR", &Study_GEN::RECO_deltaEta_FatJet_JetB_less_deltaR);
    HDF_insert("RECO_deltaEta_FatJet_JetB_more_deltaR", &Study_GEN::RECO_deltaEta_FatJet_JetB_more_deltaR);
    HDF_insert("RECO_deltaEta_FatJet_JetB_more_deltaphi", &Study_GEN::RECO_deltaEta_FatJet_JetB_more_deltaphi);
    HDF_insert("RECO_deltaEta_FatJet_JetB_less_deltaphi", &Study_GEN::RECO_deltaEta_FatJet_JetB_less_deltaphi);
    HDF_insert("RECO_deltaEta_FatJet_JetB_less_pt", &Study_GEN::RECO_deltaEta_FatJet_JetB_less_pt);
    HDF_insert("RECO_deltaEta_FatJet_JetB_more_pt", &Study_GEN::RECO_deltaEta_FatJet_JetB_more_pt);
    
    HDF_insert("RECO_deltaPhi_FatJet_JetB_less_deltaR", &Study_GEN::RECO_deltaPhi_FatJet_JetB_less_deltaR);
    HDF_insert("RECO_deltaPhi_FatJet_JetB_more_deltaR", &Study_GEN::RECO_deltaPhi_FatJet_JetB_more_deltaR);
    HDF_insert("RECO_deltaPhi_FatJet_JetB_more_deltaphi", &Study_GEN::RECO_deltaPhi_FatJet_JetB_more_deltaphi);
    HDF_insert("RECO_deltaPhi_FatJet_JetB_less_deltaphi", &Study_GEN::RECO_deltaPhi_FatJet_JetB_less_deltaphi);
    HDF_insert("RECO_deltaPhi_FatJet_JetB_less_pt", &Study_GEN::RECO_deltaPhi_FatJet_JetB_less_pt);
    HDF_insert("RECO_deltaPhi_FatJet_JetB_more_pt", &Study_GEN::RECO_deltaPhi_FatJet_JetB_more_pt);
    
    HDF_insert("RECO_deltaPhi_MET_JetB_more_deltaphi", &Study_GEN::RECO_deltaPhi_MET_JetB_more_deltaphi);
    HDF_insert("RECO_deltaPhi_MET_JetB_less_deltaphi", &Study_GEN::RECO_deltaPhi_MET_JetB_less_deltaphi);
    HDF_insert("RECO_deltaPhi_MET_JetB_less_pt", &Study_GEN::RECO_deltaPhi_MET_JetB_less_pt);
    HDF_insert("RECO_deltaPhi_MET_JetB_more_pt", &Study_GEN::RECO_deltaPhi_MET_JetB_more_pt);
    
    HDF_insert("RECO_deltaPhi_MET_FatJet", &Study_GEN::RECO_deltaPhi_MET_FatJet);

    HDF_insert("GEN_qq_inside_zh", &Study_GEN::GEN_qq_inside_zh);



    
	    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::Study_GENRegion() {

    //-------------------------------------------------------------------------
    // Cut description
    //-------------------------------------------------------------------------
    //if( !(CutCondition) ) return false;           [Example]
    //_cutFlow.at("CutName") += evtWeight;          [Example]


	LeptonSelection();
    
    
	if (!(Nleptons==0) ) return false;
    _cutFlow.at("00_NLeptons_g_0") += evtWeight;
	   
	JetSelection();
	        
	if ( !(Nbjets>0) ) return false;	    
	_cutFlow.at("01_NbJets_g_0") += evtWeight;

		        
	if (!(MET_pt > 200 && MHT > 200) ) return false;
	_cutFlow.at("02_MET_MHT_g_200") += evtWeight;

			        
	FatjetSelection();

				    
	if ( !(NfatJets>0) ) return false;				        
	_cutFlow.at("03_NFatJets_g_0") += evtWeight;

					  
	if ( !(LeadingFatJet_pt>200) ) return false;					    
	_cutFlow.at("04_FatJet_Pt_g_200") += evtWeight;

						    
	Get_Jet_Angular_Variables();

						        
	if ( !(OmegaMin>OMEGA_CUT) ) return false;						    
	_cutFlow.at("05_Omega_g_0p3") += evtWeight;

							        
	Get_Jet_Shape_Variables();								    
	Get_Signal_Taggers();

								       
	if ( !(signal_tag>0.8) ) return false;								    
	_cutFlow.at("06_Signal_like") += evtWeight;
								       
	Weight_corrections();

										   
	Study_GEN::FatJet_pt = FatJet_pt[selectedFatJet.at(0)];									        
	Study_GEN::FatJet_msoftdrop = FatJet_msoftdrop[selectedFatJet.at(0)];





    return true;
}


//-------------------------------------------------------------------------------------------------
// Write your analysis code here
//-------------------------------------------------------------------------------------------------
void HEPHero::Study_GENSelection() {
/*
///////////////////////PEGANDO INFORMAÇÂO DO DECAIMENTO///////////////////////////////////////////////////
// ====== Lambda function para traduzir PDG IDs ======
    auto pdgName = [](int id) {
        switch (id) {
            case 11: return string("e-");
            case -11: return string("e+");
            case 13: return string("mu-");
            case -13: return string("mu+");
            case 22: return string("gamma");
            case 23: return string("Z");
            case 24: return string("W+");
            case -24: return string("W-");
            case 25: return string("H");
            case 35: return string("H2");
            case 55: return string("H3");
            case 5: return string("b");
            case -5: return string("bbar");
            case 21: return string("gluon");
            case 2: return string("u");
            case -2: return string("ubar");
            default: return string("PDG=") + to_string(id);
        }
    };

    // ====== Impressão da árvore de decaimento ======
    for (int i = 0; i < nGenPart; ++i) {
        if (GenPart_genPartIdxMother[i] == -1) {

            vector<pair<int, int>> stack;
            stack.push_back({i, 0});

            while (!stack.empty()) {
                auto [idx, depth] = stack.back();
                stack.pop_back();

                // Indentação visual
                for (int j = 0; j < depth; ++j) cout << "  ";
                cout << "→ " << pdgName(GenPart_pdgId[idx])
                     << " (pdgId=" << GenPart_pdgId[idx]
                     << ", idx=" << idx << ")" << endl;

                // Encontrar filhas
                for (int k = 0; k < nGenPart; ++k) {
                    if (GenPart_genPartIdxMother[k] == idx) {
                        stack.push_back({k, depth + 1});
                    }
                }
            }
        }
    }

for (int k = 0; k < nGenPart; ++k) {
    if (GenPart_genPartIdxMother[k] == 31) { // 31 = idx do pi0
        cout << "Filha do pi0: pdgId=" << GenPart_pdgId[k]
             << " pt=" << GenPart_pt[k]
             << " eta=" << GenPart_eta[k]
             << endl;
    }
}
    */
////////////////////////////////////////ESTUDO DAS PARTICULAS DE ESTADO FINAL/////////////////////////////////
/*
cout << "=== Partículas do hard process (estado final físico) ===" << endl;

    for (unsigned int i = 0; i < nGenPart; ++i) {
        bool isLastCopy = GenPart_statusFlags[i] & (1 << 13);
        bool fromHardProcessBeforeFSR = GenPart_statusFlags[i] & (1 << 11);
        bool fromHardProcess = GenPart_statusFlags[i] & (1 << 8);
        bool isHardProcess = GenPart_statusFlags[i] & (1 << 7);

        bool isHardFinal = (isLastCopy &&
                            (fromHardProcessBeforeFSR || fromHardProcess || isHardProcess));

        if (isHardFinal) {
            cout << "idx=" << i
                 << " pdgId=" << GenPart_pdgId[i]
                 << " pt=" << GenPart_pt[i]
                 << " eta=" << GenPart_eta[i]
                 << " phi=" << GenPart_phi[i]
                 << " mass=" << GenPart_mass[i]
                 << endl;
        }
    }
*/

// CRIACAO DA TAG:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Study_GEN::Tag_decay_GenZ = 0; // 0 = No match; 1 = z->dd; 2 = z-> uu; 3=z->ss; 4= z->cc; 5 = z->bb; 11=z->ee; 13: z->mumu; 15: z-> tautau; -1: era classificado como um e mudou para outro (caso de dois Z)
        TLorentzVector part_b,part_bar,part_Zdecay_one,part_Zdecay_sec,part_Z,part_a,part_change,part_Higgs;
                Study_GEN::GEN_qq_inside_zh = -1;
                part_b.Clear();
                part_bar.Clear();
                part_Zdecay_one.Clear();
                part_Zdecay_sec.Clear();
                part_Z.Clear();
                part_a.Clear();
                part_Higgs.Clear();
                Study_GEN::Tag_decay_GenZ = 0;
                int number_of_z_in_gen = 0;
                int number_of_h_in_gen = 0;
                int number_of_b_in_gen = 0;
                int number_of_bar_in_gen = 0;
                int number_of_a_in_gen = 0;
                int number_of_Q1_in_gen = 0;
                int number_of_Q2_in_gen = 0;
                //Loop nas particulas do GenPart (não vou usar o NGenJet, pois quero fazer pro caso do ll tb)
       // std::cout<<"NOVOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"<<std::endl;
       // std::cout<<""<<std::endl;
        for(int igen = 0; igen < nGenPart; ++igen){
         /*
            std::cout<<"Nova particula"<<std::endl;
            std::cout<<""<<std::endl;
            if((abs(GenPart_pdgId[igen]) == 55 or abs(GenPart_pdgId[igen])==54)){ 
            std::cout<<"VAMOS OLHAR TODAS OS ID DAS PARTICULAS"<<std::endl;
            std::cout<<GenPart_pdgId[igen]<<std::endl;
            std::cout<<"VAMOS OLHAR TODAS OS STATUS DESSAS PARTICULAS"<<std::endl;
            std::cout<<GenPart_status[igen]<<std::endl;
            std::cout<<"VAMOS OLHAR TODAS AS FLAGS DESSAS PARTICULAS"<<std::endl;
            std::cout<<GenPart_statusFlags[igen]<<std::endl;
            }
            */
            // ACHANDO os dois Bs que são produzidos juntos ao Gluon!
                        if ( (abs(GenPart_pdgId[igen]) == 5) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 21 && GenPart_genPartIdxMother[GenPart_genPartIdxMother[igen]]==-1 ) ){
                                if (GenPart_pdgId[igen] == 5){
                                        part_b.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],4.18);
                                        number_of_b_in_gen = number_of_b_in_gen +1;
                                }
                                if (GenPart_pdgId[igen] == -5){
                                        part_bar.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],4.18);
                                        number_of_bar_in_gen = number_of_bar_in_gen + 1;
                                }

                        }
                        // IF DO PSEUDO ESCALAR
                        if ( (abs(GenPart_pdgId[igen]) == 55 or abs(GenPart_pdgId[igen])==54) && ((GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 35) || (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 36) ) ){
                                part_a.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],GenPart_mass[igen]);
                                number_of_a_in_gen = number_of_a_in_gen+1;
                        }
                        //IF DO Z
                        if ( (abs(GenPart_pdgId[igen]) == 23) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 35) ){
                                part_Z.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],GenPart_mass[igen]);
                                number_of_z_in_gen = number_of_z_in_gen + 1;
                        }
                        //IF DO HIGGS
                        if  ( (abs(GenPart_pdgId[igen]) == 25) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 36) ){
                                part_Higgs.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],GenPart_mass[igen]);
                                number_of_h_in_gen = number_of_h_in_gen + 1;
                        }
            // VAMOS VER SE ACHAMOS UM Z/h QUE DECAI EM UM MuMu
            if ( ( (abs(GenPart_pdgId[igen]) == 13) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23)) || ( (abs(GenPart_pdgId[igen]) == 13) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 25))  ){ //ENCONTRAMOS UM h/Z->mumu
                if (Study_GEN::Tag_decay_GenZ != 0 && Study_GEN::Tag_decay_GenZ!= 13){
                                Study_GEN::Tag_decay_GenZ=-1;
                        }
                        else{
                                Study_GEN::Tag_decay_GenZ=13;
                                                                if (GenPart_pdgId[igen] == 13){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.105658);
                                                                }
                                                                if (GenPart_pdgId[igen] == -13){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.105658);
                                                                }
                        }

                }
                // VAMOS VER SE ACHAMOS UM h/Z QUE DECAI EM UM ElEl
                if ( ( (abs(GenPart_pdgId[igen]) == 11) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ) || ( (abs(GenPart_pdgId[igen]) == 11) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 25)) ){ //ENCONTRAMOS UM h/Z->elel
                        if (Study_GEN::Tag_decay_GenZ != 0 && Study_GEN::Tag_decay_GenZ!= 11){
                                Study_GEN::Tag_decay_GenZ=-1;
                        }
                        else{
                                Study_GEN::Tag_decay_GenZ=11;
                                                                if (GenPart_pdgId[igen] == 11 ){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.000510999);
                                                                }
                                                                if (GenPart_pdgId[igen] == -11 ){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.000510999);
                                                                }
                        }

                }
                // VAMOS VER SE ACHAMOS UM h/Z QUE DECAI EM UM TauTau
                if ( ((abs(GenPart_pdgId[igen]) == 15) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23)) || ( (abs(GenPart_pdgId[igen]) == 15) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 25)) ){ //ENCONTRAMOS UM h/Z->TauTau
                        if (Study_GEN::Tag_decay_GenZ != 0 && Study_GEN::Tag_decay_GenZ!= 15){
                                Study_GEN::Tag_decay_GenZ=-1;
                        }
                        else{
                                Study_GEN::Tag_decay_GenZ=15;
                                                                if (GenPart_pdgId[igen] == 15 ){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0);
                                                                }
                                                                if (GenPart_pdgId[igen] == -15 ){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0);
                                                                }
                        }

                }

                // VAMOS VER SE ACHAMOS UM h/Z QUE DECAI EM UM down-down
                if ( ( (abs(GenPart_pdgId[igen]) == 1) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ) || ( (abs(GenPart_pdgId[igen]) == 1) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 25)) ){ //ENCONTRAMOS UM h/Z->dd
                        if (Study_GEN::Tag_decay_GenZ !=0 && Study_GEN::Tag_decay_GenZ!= 1){
                                Study_GEN::Tag_decay_GenZ=-1;
                        }
                        else{
                                Study_GEN::Tag_decay_GenZ=1;
                                                                if (GenPart_pdgId[igen] == 1 ){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.0047);
                                                                }
                                                                if (GenPart_pdgId[igen] == -1 ){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.0047);
                                                                }
                        }

                }
                // VAMOS VER SE ACHAMOS UM Z/h QUE DECAI EM UM up-up
                if ( ( (abs(GenPart_pdgId[igen]) == 2) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ) || ( (abs(GenPart_pdgId[igen]) == 2) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 25)) ){ //ENCONTRAMOS UM Z/h->uu
                        if (Study_GEN::Tag_decay_GenZ !=0 && Study_GEN::Tag_decay_GenZ!= 2){
                                Study_GEN::Tag_decay_GenZ=-1;
                        }
                        else{
                                Study_GEN::Tag_decay_GenZ=2;
                                                                if (GenPart_pdgId[igen] == 2 ){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.0022);
                                                                }
                                                                if (GenPart_pdgId[igen] == -2 ){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.0022);
                                                                }
                        }
                }
                // VAMOS VER SE ACHAMOS UM h/Z QUE DECAI EM UM strange-strange
                if ( ( (abs(GenPart_pdgId[igen]) == 3) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ) || ( (abs(GenPart_pdgId[igen]) == 3) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 25)) ){ //ENCONTRAMOS UM h/Z->ss
                        if (Study_GEN::Tag_decay_GenZ !=0 && Study_GEN::Tag_decay_GenZ!= 3){
                                Study_GEN::Tag_decay_GenZ=-1;
                        }
                        else{
                                Study_GEN::Tag_decay_GenZ=3;
                                                                if (GenPart_pdgId[igen] == 3 ){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.096);
                                                                }
                                                                if (GenPart_pdgId[igen] == -3 ){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],0.096);
                                                                }
                        }

                }
                // VAMOS VER SE ACHAMOS UM h/Z QUE DECAI EM UM charm-charm
                if ( ( (abs(GenPart_pdgId[igen]) == 4) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ) || ( (abs(GenPart_pdgId[igen]) == 4) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 25)) ){ //ENCONTRAMOS UM h/Z->cc
                        if (Study_GEN::Tag_decay_GenZ !=0 && Study_GEN::Tag_decay_GenZ!= 4){
                                Study_GEN::Tag_decay_GenZ=-1;
                        }
                        else{
                                Study_GEN::Tag_decay_GenZ=4;
                                                                if (GenPart_pdgId[igen] == 4 ){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],1.28);
                                                                }
                                                                if (GenPart_pdgId[igen] == -4 ){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],1.28);
                                                                }
                        }

                }
                // VAMOS VER SE ACHAMOS UM h/Z QUE DECAI EM UM bottom-bottom
                if ( ( (abs(GenPart_pdgId[igen]) == 5) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23) ) || ( (abs(GenPart_pdgId[igen]) == 5) && (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 25) ) ){ //ENCONTRAMOS UM h/Z->bb
                        if (Study_GEN::Tag_decay_GenZ !=0 && Study_GEN::Tag_decay_GenZ!= 5){
                                Study_GEN::Tag_decay_GenZ=-1;
                        }
                        else{
                                Study_GEN::Tag_decay_GenZ=5;
                                                                if (GenPart_pdgId[igen] == 5 ){
                                                                        part_Zdecay_one.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],4.18);
                                                                }
                                                                if (GenPart_pdgId[igen] == -5 ){
                                                                        part_Zdecay_sec.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],4.18);
                                                                }

                        }

                                }
        }
//std::cout<<"TAG: "<<Study_GEN::Tag_decay_GenZ<<std::endl;
//#############################################################################################################################################
//### Uma vez que todas as particulas principais de GEN estão no TLorentzVector, podemos trabalhar para pegar os valores ##
//#############################################################################################################################################
 

//===========================
// Informações do part_z
//===========================

Study_GEN::GEN_part_z_pt = part_Z.Pt();
Study_GEN::GEN_part_z_eta = part_Z.Eta();
Study_GEN::GEN_part_z_phi = part_Z.Phi();
Study_GEN::GEN_part_z_mass = part_Z.M();
Study_GEN::GEN_part_z_number = number_of_z_in_gen;

//===========================
// Informações do part_h
//===========================

Study_GEN::GEN_part_h_pt = part_Higgs.Pt();
Study_GEN::GEN_part_h_eta = part_Higgs.Eta();
Study_GEN::GEN_part_h_phi = part_Higgs.Phi();
Study_GEN::GEN_part_h_mass = part_Higgs.M();
Study_GEN::GEN_part_h_number = number_of_h_in_gen;


//===========================
// Informações do part_b
//===========================

Study_GEN::GEN_part_b_pt = part_b.Pt();
Study_GEN::GEN_part_b_eta = part_b.Eta();
Study_GEN::GEN_part_b_phi = part_b.Phi();
Study_GEN::GEN_part_b_mass = part_b.M();
Study_GEN::GEN_part_b_number = number_of_b_in_gen;

//===========================
// Informações do part_bar
//===========================

Study_GEN::GEN_part_bar_pt = part_bar.Pt();
Study_GEN::GEN_part_bar_eta = part_bar.Eta();
Study_GEN::GEN_part_bar_phi = part_bar.Phi();
Study_GEN::GEN_part_bar_mass = part_bar.M();
Study_GEN::GEN_part_bar_number = number_of_bar_in_gen;

//===========================
// Informações do a
//===========================
Study_GEN::GEN_part_a_pt = part_a.Pt();
Study_GEN::GEN_part_a_eta = part_a.Eta();
Study_GEN::GEN_part_a_phi = part_a.Phi();
Study_GEN::GEN_part_a_mass = part_a.M();
Study_GEN::GEN_part_a_number = number_of_a_in_gen;

//===========================
// Informações do Q1
//===========================
Study_GEN::GEN_part_Q1_pt = part_Zdecay_one.Pt();
Study_GEN::GEN_part_Q1_eta = part_Zdecay_one.Eta();
Study_GEN::GEN_part_Q1_phi = part_Zdecay_one.Phi();
Study_GEN::GEN_part_Q1_mass = part_Zdecay_one.M();
Study_GEN::GEN_part_Q1_number = number_of_Q1_in_gen;


//===========================
// Informações do Q2
//===========================
Study_GEN::GEN_part_Q2_pt = part_Zdecay_sec.Pt();
Study_GEN::GEN_part_Q2_eta = part_Zdecay_sec.Eta();
Study_GEN::GEN_part_Q2_phi = part_Zdecay_sec.Phi();
Study_GEN::GEN_part_Q2_mass = part_Zdecay_sec.M();
Study_GEN::GEN_part_Q2_number = number_of_Q2_in_gen;

//===========================
// Informações do gen_met
//===========================
    
Study_GEN::GEN_met_pt = GenMET_phi;
Study_GEN::GEN_met_phi = GenMET_pt;


//============================
//

if (part_Z.DeltaR(part_Zdecay_one) > 0.8 && part_Z.DeltaR(part_Zdecay_sec) > 0.8){
    Study_GEN::GEN_qq_inside_zh = 0;
}
if (part_Z.DeltaR(part_Zdecay_one) <= 0.8 && part_Z.DeltaR(part_Zdecay_sec) > 0.8){
    Study_GEN::GEN_qq_inside_zh = 1;
}
if (part_Z.DeltaR(part_Zdecay_one) > 0.8 && part_Z.DeltaR(part_Zdecay_sec) <= 0.8){
    Study_GEN::GEN_qq_inside_zh = 1;
}
if (part_Z.DeltaR(part_Zdecay_one) <= 0.8 && part_Z.DeltaR(part_Zdecay_sec) <= 0.8){
    Study_GEN::GEN_qq_inside_zh = 2;
}




    
//=======================
// Hora de preencher informações sobre a variáveis:
// GEN_max_delta_eta_part_b_zh
// GEN_max_delta_eta_part_bar_zh
// GEN_max_delta_eta_part_jetB_zh
//=======================


float max_eta = 0;
int num_b_inside = 0;
int num_b_outside = 0;
float min_deltaR = -1;
float mass_inv_close_b = -1;
float max_mass_inv_close_b = -1;
float min_mass_inv_close_b = 999999;

float mass_tran_close_b = -1;
float max_mass_tran_close_b = -1;
float min_mass_tran_close_b = 999999;

                
TLorentzVector part_bottom,syste_METJetB,syste_FatJet;
for (int igen = 0; igen < nGenPart; ++igen){
        if ( (abs(GenPart_pdgId[igen]) == 5) && GenPart_status[igen]!=71 && GenPart_statusFlags[igen]!=8449){
            part_bottom.Clear();
            syste_METJetB.Clear();
            part_bottom.SetPtEtaPhiM(GenPart_pt[igen],GenPart_eta[igen],GenPart_phi[igen],4.18);

            mass_tran_close_b = sqrt(2 * part_bottom.Pt() * part_a.Pt() * (1 - cos(part_bottom.DeltaPhi(part_a))));
            if (max_mass_tran_close_b < mass_tran_close_b){
                max_mass_tran_close_b = mass_tran_close_b;
            } 
            if (min_mass_tran_close_b > mass_tran_close_b){
                
                min_mass_tran_close_b = mass_tran_close_b;
                syste_METJetB = part_bottom + part_a;
            } 


            
            if (number_of_h_in_gen==1 && number_of_z_in_gen==0){
                syste_FatJet = part_Higgs;
                if (part_bottom.DeltaR(part_Higgs) <= 0.8){
                    num_b_inside= num_b_inside + 1;
                }
                else
                {
                    num_b_outside = num_b_outside + 1;
                    if (max_mass_inv_close_b < ((part_bottom + part_Higgs).M())){
                        max_mass_inv_close_b = (part_bottom + part_Higgs).M();
                    }
                    if (min_mass_inv_close_b > ((part_bottom + part_Higgs).M())){
                        min_mass_inv_close_b = (part_bottom + part_Higgs).M();
                    }
                    if (min_deltaR < part_bottom.DeltaR(part_Higgs)){
                        min_deltaR = part_bottom.DeltaR(part_Higgs);
                        mass_inv_close_b = (part_bottom + part_Higgs).M();
                        
                    }
                }
                if (max_eta < (fabs(part_bottom.Eta() - part_Higgs.Eta())) ){
                    max_eta = fabs(part_bottom.Eta() - part_Higgs.Eta());
                }
            }
            
            if (number_of_h_in_gen==0 && number_of_z_in_gen==1){
                syste_FatJet = part_Z;
                if (part_bottom.DeltaR(part_Z) <= 0.8){
                    num_b_inside= num_b_inside + 1;
                }
                else
                {
                    num_b_outside = num_b_outside + 1;
                    if (max_mass_inv_close_b < ((part_bottom + part_Higgs).M())){
                        max_mass_inv_close_b = (part_bottom + part_Higgs).M();
                    }
                    if (min_mass_inv_close_b > ((part_bottom + part_Higgs).M())){
                        min_mass_inv_close_b = (part_bottom + part_Higgs).M();
                    }
                    if (min_deltaR < part_bottom.DeltaR(part_Z)){
                        min_deltaR = part_bottom.DeltaR(part_Z);
                        mass_inv_close_b = (part_bottom + part_Higgs).M();
                        
                    }
                }
                if (max_eta < (fabs(part_bottom.Eta() - part_Z.Eta())) ){
                    max_eta = fabs(part_bottom.Eta() - part_Z.Eta());
                }
                
            }
                       
        }
}
    
Study_GEN::GEN_max_delta_eta_part_jetB_zh = max_eta;
Study_GEN::GEN_mass_inv_zh_close_part_jetB = mass_inv_close_b;
Study_GEN::GEN_number_of_part_jetB_out_zh = num_b_outside;
Study_GEN::GEN_number_of_part_jetB_in_zh = num_b_inside;
Study_GEN::GEN_max_mass_inv_zh_close_part_jetB = max_mass_inv_close_b;
Study_GEN::GEN_min_mass_inv_zh_close_part_jetB = min_mass_inv_close_b;

Study_GEN::GEN_mass_tran_met_close_part_jetB = mass_tran_close_b;
Study_GEN::GEN_max_mass_tran_met_close_part_jetB = max_mass_tran_close_b;
Study_GEN::GEN_min_mass_tran_met_close_part_jetB = min_mass_tran_close_b;

Study_GEN::GEN_deltaR_FatJet_METJetB = syste_METJetB.DeltaR(syste_FatJet);

    
//=====================================================================================================================================================================
// COMEÇANDO A ETAPA DE RECO
//=====================================================================================================================================================================

float reco_max_eta = 0;
int reco_num_b_inside = 0;
int reco_num_b_outside = 0;
float reco_min_deltaR = -1;
float reco_mass_inv_close_b = -1;
float reco_max_mass_inv_close_b = -1;
float reco_min_mass_inv_close_b = 999999;
float reco_mass_tran_close_b = -1;
float reco_max_mass_tran_close_b = -1;
float reco_min_mass_tran_close_b = 999999;
float reco_deltaR_between_fatJet_MEtJetB = 0;
float dPhi=999;
float dPhi_METJetb= 999;
float temp_reco_mass_tran_close_b = 0;
float temp_deltaR_FatJet_JetB_less = 999;
float temp_deltaR_FatJet_JetB_more = 0;

float temp_deltaPhi_FatJet_JetB_less = 999;
float temp_deltaPhi_FatJet_JetB_more = 0;


float temp_maior_pt_jetB = 0;
float temp_menor_pt_jetB = 999;

float temp_dPhi_METJetb_more = 0;

    
for(int iSeljet = 0; iSeljet < selectedJet.size(); ++iSeljet){
    // Pego o index do jet que passou pelos cortes de seleção
    int ijet = selectedJet[iSeljet];
    // Testo se ele passou pelos criterio de ser um JetB
    if( JetBTAG( ijet, JET_BTAG_WP ) ){
        
        float FatJet_b_deltaEta = abs( FatJet_eta[selectedFatJet.at(0)] - Jet_eta[ijet]);
        if( FatJet_b_deltaEta > reco_max_eta ) reco_max_eta = FatJet_b_deltaEta;

        double dR = sqrt(pow(Jet_eta[ijet] - FatJet_eta[selectedFatJet.at(0)], 2) + pow(fabs(Jet_phi[ijet] - FatJet_phi[selectedFatJet.at(0)]) > M_PI ? 2*M_PI - fabs(Jet_phi[ijet] - FatJet_phi[selectedFatJet.at(0)]) : fabs(Jet_phi[ijet] - FatJet_phi[selectedFatJet.at(0)]), 2));

        if (dR <= 0.8){
            reco_num_b_inside = reco_num_b_inside +1;
        }
        else{
            reco_num_b_outside = reco_num_b_outside + 1;
            double actual_reco_mass_inv_close_b = sqrt(std::max(0.0,
             pow(sqrt(FatJet_pt[selectedFatJet.at(0)]*FatJet_pt[selectedFatJet.at(0)]*cosh(FatJet_eta[selectedFatJet.at(0)])*cosh(FatJet_eta[selectedFatJet.at(0)]) + FatJet_mass[selectedFatJet.at(0)]*FatJet_mass[selectedFatJet.at(0)])
               + sqrt(Jet_pt[ijet]*Jet_pt[ijet]*cosh(Jet_eta[ijet])*cosh(Jet_eta[ijet]) + Jet_mass[ijet]*Jet_mass[ijet]),2)
                - pow(FatJet_pt[selectedFatJet.at(0)]*cos(FatJet_phi[selectedFatJet.at(0)]) + Jet_pt[ijet]*cos(Jet_phi[ijet]),2)
                - pow(FatJet_pt[selectedFatJet.at(0)]*sin(FatJet_phi[selectedFatJet.at(0)]) + Jet_pt[ijet]*sin(Jet_phi[ijet]),2)
                - pow(FatJet_pt[selectedFatJet.at(0)]*sinh(FatJet_eta[selectedFatJet.at(0)]) + Jet_pt[ijet]*sinh(Jet_eta[ijet]),2)
                ));
            if (reco_max_mass_inv_close_b < actual_reco_mass_inv_close_b){
                reco_max_mass_inv_close_b = actual_reco_mass_inv_close_b;
            }
            if (reco_min_mass_inv_close_b > actual_reco_mass_inv_close_b){
                reco_min_mass_inv_close_b = actual_reco_mass_inv_close_b;
            }
             if (reco_min_deltaR < dR){
                reco_min_deltaR = dR;
                reco_mass_inv_close_b = actual_reco_mass_inv_close_b;
             }
        
        }

        float temp_dPhi_FatJet_Jetb = fabs(acos(cos(FatJet_phi[selectedFatJet.at(0)] - Jet_phi[ijet])));

        
        //Caso onde o JetB tem o menor DeltaR com o FatJet
        if (dR < temp_deltaR_FatJet_JetB_less){
        temp_deltaR_FatJet_JetB_less = dR;
        Study_GEN::RECO_deltaR_FatJet_JetB_less_deltaR = temp_deltaR_FatJet_JetB_less;
        Study_GEN::RECO_deltaEta_FatJet_JetB_less_deltaR = fabs(FatJet_eta[selectedFatJet.at(0)] - Jet_eta[ijet]);
        Study_GEN::RECO_deltaPhi_FatJet_JetB_less_deltaR = temp_dPhi_FatJet_Jetb;    
        }
        // Caso onde o JetB tem o maior DeltaR com o FatJet
        if (dR > temp_deltaR_FatJet_JetB_more){
            temp_deltaR_FatJet_JetB_more = dR ;
            Study_GEN::RECO_deltaR_FatJet_JetB_more_deltaR = temp_deltaR_FatJet_JetB_more;
            Study_GEN::RECO_deltaEta_FatJet_JetB_more_deltaR = fabs(FatJet_eta[selectedFatJet.at(0)] - Jet_eta[ijet]);
            Study_GEN::RECO_deltaPhi_FatJet_JetB_more_deltaR = temp_dPhi_FatJet_Jetb;
        }
        

        // Caso onde temos o menor deltaPhi entre o FatJet e JetB
        if (temp_dPhi_FatJet_Jetb < temp_deltaPhi_FatJet_JetB_less){
            temp_deltaPhi_FatJet_JetB_less = temp_dPhi_FatJet_Jetb;
            Study_GEN::RECO_deltaPhi_FatJet_JetB_less_deltaphi = temp_deltaPhi_FatJet_JetB_less;
            Study_GEN::RECO_deltaR_FatJet_JetB_less_deltaphi = dR;
            Study_GEN::RECO_deltaEta_FatJet_JetB_less_deltaphi = fabs(FatJet_eta[selectedFatJet.at(0)] - Jet_eta[ijet]);
        }
        // Caso onde temos o maior deltaPhi entre o FatJet e JetB
        if (temp_dPhi_FatJet_Jetb > temp_deltaPhi_FatJet_JetB_more){
            temp_deltaPhi_FatJet_JetB_more = temp_dPhi_FatJet_Jetb;
            Study_GEN::RECO_deltaPhi_FatJet_JetB_more_deltaphi = temp_deltaPhi_FatJet_JetB_more;
            Study_GEN::RECO_deltaR_FatJet_JetB_more_deltaphi = dR;
            Study_GEN::RECO_deltaEta_FatJet_JetB_more_deltaphi = fabs(FatJet_eta[selectedFatJet.at(0)] - Jet_eta[ijet]);
        }
        // Caso onde temos o Jet_B de maior pt
        if (Jet_pt[ijet] > temp_maior_pt_jetB){
            temp_maior_pt_jetB = Jet_pt[ijet];
            Study_GEN::RECO_deltaR_FatJet_JetB_more_pt = dR;
            Study_GEN::RECO_deltaEta_FatJet_JetB_more_pt = fabs(FatJet_eta[selectedFatJet.at(0)] - Jet_eta[ijet]);
            Study_GEN::RECO_deltaPhi_FatJet_JetB_more_pt = temp_dPhi_FatJet_Jetb;

            Study_GEN::RECO_deltaPhi_MET_JetB_more_pt = acos(cos(Jet_phi[ijet] - MET_phi));
        }
        // Caso onde o JetB tem o menor pt
        if (Jet_pt[ijet] < temp_menor_pt_jetB){
            temp_menor_pt_jetB = Jet_pt[ijet];
            Study_GEN::RECO_deltaR_FatJet_JetB_less_pt = dR;
            Study_GEN::RECO_deltaEta_FatJet_JetB_less_pt = fabs(FatJet_eta[selectedFatJet.at(0)] - Jet_eta[ijet]);
            Study_GEN::RECO_deltaPhi_FatJet_JetB_less_pt = temp_dPhi_FatJet_Jetb;

            Study_GEN::RECO_deltaPhi_MET_JetB_less_pt = acos(cos(Jet_phi[ijet] - MET_phi));
        }



        Study_GEN::RECO_deltaPhi_MET_FatJet = fabs(acos(cos(FatJet_phi[selectedFatJet.at(0)] - MET_phi)));


        
        
        float temp_dPhi_METJetb = acos(cos(Jet_phi[ijet] - MET_phi));
        // Menor DeltaPhi entre o MET e JetB
        if (dPhi_METJetb > temp_dPhi_METJetb){
            dPhi_METJetb = temp_dPhi_METJetb;
            reco_mass_tran_close_b = sqrt(2 * Jet_pt[ijet] * MET_pt * (1 - cos(Jet_phi[ijet] - MET_phi)));
            Study_GEN::RECO_deltaPhi_MET_JetB_less_deltaphi = dPhi_METJetb;
        }
        // Maior DeltaPhi entre o MET e JetB
        if (temp_dPhi_METJetb > temp_dPhi_METJetb_more){
            temp_dPhi_METJetb_more = temp_dPhi_METJetb;
            Study_GEN::RECO_deltaPhi_MET_JetB_more_deltaphi = temp_dPhi_METJetb_more;
        }
        
        temp_reco_mass_tran_close_b = sqrt(2 * Jet_pt[ijet] * MET_pt * (1 - cos(Jet_phi[ijet] - MET_phi)));
        if (reco_max_mass_tran_close_b < temp_reco_mass_tran_close_b){
            reco_max_mass_tran_close_b = temp_reco_mass_tran_close_b;
        } 
        if (reco_min_mass_tran_close_b > temp_reco_mass_tran_close_b){
            reco_min_mass_tran_close_b = temp_reco_mass_tran_close_b;
        
        
        
        }
        double temp_dPhi = acos(cos(FatJet_phi[selectedFatJet.at(0)] - atan2(Jet_pt[ijet]*sin(Jet_phi[ijet]) + MET_pt*sin(MET_phi), Jet_pt[ijet]*cos(Jet_phi[ijet]) + MET_pt*cos(MET_phi))));
        if (dPhi>temp_dPhi){
            dPhi = temp_dPhi;
        }

    // PREENCHENDO TODAS AS VARIAVEIS COM BASE NO DeltaR menor
    //Sistema FatJet --- JetB
    






        
    }




}



Study_GEN::RECO_max_delta_eta_part_jetB_zh = reco_max_eta;
Study_GEN::RECO_mass_inv_zh_close_part_jetB = reco_mass_inv_close_b;
Study_GEN::RECO_number_of_part_jetB_out_zh = reco_num_b_outside;
Study_GEN::RECO_number_of_part_jetB_in_zh = reco_num_b_inside;
Study_GEN::RECO_max_mass_inv_zh_close_part_jetB = reco_max_mass_inv_close_b;
Study_GEN::RECO_min_mass_inv_zh_close_part_jetB = reco_min_mass_inv_close_b;

Study_GEN::RECO_mass_tran_met_close_part_jetB = temp_reco_mass_tran_close_b;
Study_GEN::RECO_true_mass_tran_met_close_part_jetB = reco_mass_tran_close_b;
Study_GEN::RECO_max_mass_tran_met_close_part_jetB = reco_max_mass_tran_close_b;
Study_GEN::RECO_min_mass_tran_met_close_part_jetB = reco_min_mass_tran_close_b;

Study_GEN::RECO_deltaPhi_FatJet_METJetB = dPhi;




    //======ASSIGN VALUES TO THE OUTPUT VARIABLES==================================================
    //Study_GEN::variable1Name = 100;      [Example]

    //======FILL THE HISTOGRAMS====================================================================
    //_histograms1D.at("histogram1DName").Fill( var, evtWeight );               [Example]
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
void HEPHero::Study_GENSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishStudy_GEN() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}




