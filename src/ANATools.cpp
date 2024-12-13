#include "HEPHero.h"



//---------------------------------------------------------------------------------------------------------------
// Lepton selection
//---------------------------------------------------------------------------------------------------------------
void HEPHero::LeptonSelection(){

    selectedEle.clear();
    selectedMu.clear();
    //std::cout<<"Numero de eletrons:"<<nElectron<<endl;
    for( unsigned int iele = 0; iele < nElectron; ++iele ) {
        if( abs(Electron_eta[iele]) >= ELECTRON_ETA_CUT ) continue;
        if( !ElectronID( iele, ELECTRON_ID_WP ) ) continue;
        if( (abs(Electron_eta[iele] + Electron_deltaEtaSC[iele]) > ELECTRON_GAP_LOWER_CUT) &&
            (abs(Electron_eta[iele] + Electron_deltaEtaSC[iele]) < ELECTRON_GAP_UPPER_CUT) ) continue;
        if( Electron_pt[iele] <= ELECTRON_PT_CUT ) continue;

/*
        TLorentzVector Ele_test;
        Ele_test.SetPtEtaPhiM(Electron_pt[iele], Electron_eta[iele], Electron_phi[iele], Electron_pdg_mass);
        for( unsigned int iselele = 0; iselele < selectedEle.size(); ++iselele ) {
            int iele_sel = selectedEle[iselele];
            TLorentzVector Ele_sel;
            Ele_sel.SetPtEtaPhiM(Electron_pt[iele_sel], Electron_eta[iele_sel], Electron_phi[iele_sel], Electron_pdg_mass);
            float dilep_deltaR = Ele_test.DeltaR( Ele_sel );
            if( dilep_deltaR < Min_dilep_deltaR ) Min_dilep_deltaR = dilep_deltaR;
        }
*/
        selectedEle.push_back(iele);
    }

    for( unsigned int imu = 0; imu < nMuon; ++imu ) {
        //Muon_raw_pt[imu] = Muon_pt[imu];
        if( abs(Muon_eta[imu]) >= MUON_ETA_CUT ) continue;
        if( !MuonID( imu, MUON_ID_WP ) ) continue;
        if( !MuonISO( imu, MUON_ISO_WP ) ) continue;

        //if( apply_muon_roc_corr ) Muon_pt[imu] = Muon_pt[imu]*muon_roc_corr.GetCorrection( Muon_charge[imu], Muon_pt[imu], Muon_eta[imu], Muon_phi[imu], (Muon_genPartIdx[imu]>=0) ? true : false, (Muon_genPartIdx[imu]>=0) ? GenPart_pt[Muon_genPartIdx[imu]] : 0., Muon_nTrackerLayers[imu], (dataset_group=="Data") );

        //if( Muon_pt[imu] > MUON_LOW_PT_CUT ) selectedMuLowPt.push_back(imu);
        if( Muon_pt[imu] <= MUON_PT_CUT ) continue;
/*
        TLorentzVector Mu_test;
        Mu_test.SetPtEtaPhiM(Muon_pt[imu], Muon_eta[imu], Muon_phi[imu], Muon_pdg_mass);
        for( unsigned int iselmu = 0; iselmu < selectedMu.size(); ++iselmu ) {
            int imu_sel = selectedMu[iselmu];
            TLorentzVector Mu_sel;
            Mu_sel.SetPtEtaPhiM(Muon_pt[imu_sel], Muon_eta[imu_sel], Muon_phi[imu_sel], Muon_pdg_mass);
            float dilep_deltaR = Mu_test.DeltaR( Mu_sel );
            if( dilep_deltaR < Min_dilep_deltaR ) Min_dilep_deltaR = dilep_deltaR;
        }
        for( unsigned int iselele = 0; iselele < selectedEle.size(); ++iselele ) {
            int iele_sel = selectedEle[iselele];
            TLorentzVector Ele_sel;
            Ele_sel.SetPtEtaPhiM(Electron_pt[iele_sel], Electron_eta[iele_sel], Electron_phi[iele_sel], Electron_pdg_mass);
            float dilep_deltaR = Mu_test.DeltaR( Ele_sel );
            if( dilep_deltaR < Min_dilep_deltaR ) Min_dilep_deltaR = dilep_deltaR;
        }
*/
        selectedMu.push_back(imu);
  
    }

    Nelectrons = selectedEle.size();
    Nmuons = selectedMu.size();
    //Nleptons = Nelectrons + Nmuons;

    //int NelectronsLowPt = selectedEleLowPt.size();
    //int NmuonsLowPt = selectedMuLowPt.size();
    //NleptonsLowPt = NelectronsLowPt + NmuonsLowPt;

}






void HEPHero::Jet_lep_overlap( float deltaR_cut ){

    Jet_LepOverlap.clear();
    for( unsigned int ijet = 0; ijet < nJet; ++ijet ) {
        Jet_LepOverlap.push_back(false);
    }

    //for( unsigned int iele = 0; iele < nElectron; ++iele ) {
    for( unsigned int iselEle = 0; iselEle < selectedEle.size(); ++iselEle ) {
        int iele = selectedEle.at(iselEle);
        float drMin = 99999.;
        int JetID = -1;
        for( unsigned int ijet = 0; ijet < nJet; ++ijet ) {
            double deta = fabs(Electron_eta[iele] - Jet_eta[ijet]);
            double dphi = fabs(Electron_phi[iele] - Jet_phi[ijet]);
            if( dphi > M_PI ) dphi = 2*M_PI - dphi;
            double dr = sqrt( deta*deta + dphi*dphi );
            if( dr < drMin ){
                drMin = dr;
                JetID = ijet;
            }
        }
        if( (drMin < deltaR_cut) && (JetID >= 0) ){
            //cout << "deltaR " << drMin << " " << endl;
            //cout << "JetID " << JetID << " " << endl;
            Jet_LepOverlap[JetID] = true;
        }
    }

    //for( unsigned int imu = 0; imu < nMuon; ++imu ) {
    for( unsigned int iselMu = 0; iselMu < selectedMu.size(); ++iselMu ) {
        int imu = selectedMu.at(iselMu);
        float drMin = 99999.;
        int JetID = -1;
        for( unsigned int ijet = 0; ijet < nJet; ++ijet ) {
            double deta = fabs(Muon_eta[imu] - Jet_eta[ijet]);
            double dphi = fabs(Muon_phi[imu] - Jet_phi[ijet]);
            if( dphi > M_PI ) dphi = 2*M_PI - dphi;
            double dr = sqrt( deta*deta + dphi*dphi );
            if( dr < drMin ){
                drMin = dr;
                JetID = ijet;
            }
        }
        if( (drMin < deltaR_cut) && (JetID >= 0) ){
            //cout << "deltaR " << drMin << " " << endl;
            //cout << "JetID " << JetID << " " << endl;
            Jet_LepOverlap[JetID] = true;
        }
    }

}


void HEPHero::JetSelection(){

    selectedJet.clear();
    //jetMomenta.clear();

    for( unsigned int ijet = 0; ijet < nJet; ++ijet ) {
        Jet_JES_pt[ijet] = Jet_pt[ijet];
    }

    // JESvariation();
    // JERvariation();

    Jet_lep_overlap(JET_LEP_DR_ISO_CUT);

    Nbjets = 0;
    Nbjets30 = 0;
    Nbjets_LepIso04 = 0;
    Nbjets30_LepIso04 = 0;
    Njets = 0;
    Njets30 = 0;
    Njets40 = 0;
    Njets_LepIso04 = 0;
    Njets30_LepIso04 = 0;
    Njets40_LepIso04 = 0;
    Njets_forward = 0;
    Njets_tight = 0;
    Njets_ISR = 0;
    NPUjets = 0;
    Jet_abseta_max = 0;
    HT = 0;
    HT30 = 0;
    HT40 = 0;
    float HPx = 0;
    float HPy = 0;
    float HPx30 = 0;
    float HPy30 = 0;
    float HPx40 = 0;
    float HPy40 = 0;
    float HPx_trig = 0;
    float HPy_trig = 0;


    // Main loop to process each jet
    for( unsigned int ijet = 0; ijet < nJet; ++ijet ) {
        
        if( Jet_pt[ijet] <= JET_PT_CUT ) continue;
        if( Jet_jetId[ijet] >= 2 ){
            TLorentzVector Jet_trig;
            Jet_trig.SetPtEtaPhiE(Jet_pt[ijet], Jet_eta[ijet], Jet_phi[ijet], 0);
            HPx_trig += Jet_trig.Px();
            HPy_trig += Jet_trig.Py();
        }
        if( (abs(Jet_eta[ijet]) < JET_ETA_CUT) and (Jet_jetId[ijet] >= 2) ) Njets_tight += 1;
        if( Jet_jetId[ijet] < JET_ID_WP ) continue;
        
        //if( Jet_lep_overlap( ijet, JET_LEP_DR_ISO_CUT ) ) continue;
        if( Jet_LepOverlap[ijet] ) continue;
        if( (Jet_pt[ijet] < 50) && (Jet_puId[ijet] < JET_PUID_WP) ) continue;

        if( abs(Jet_eta[ijet]) >= 5.0 ) continue;
        if( abs(Jet_eta[ijet]) > 1.4 ) Njets_forward += 1;
        if( abs(Jet_eta[ijet]) > Jet_abseta_max ) Jet_abseta_max = abs(Jet_eta[ijet]);
        if( abs(Jet_eta[ijet]) >= JET_ETA_CUT ) continue;
        selectedJet.push_back(ijet);
        TLorentzVector Jet;
        Jet.SetPtEtaPhiE(Jet_pt[ijet], Jet_eta[ijet], Jet_phi[ijet], 0);
        Njets += 1;
        //if( !Jet_lep_overlap(ijet, 0.4) ) Njets_LepIso04 += 1;
        if( PileupJet( ijet ) ) NPUjets += 1;
        HT += Jet_pt[ijet];
        HPx += Jet.Px();
        HPy += Jet.Py();
        if( Jet_pt[ijet] > 30 ){
            Njets30 += 1;
            //if( !Jet_lep_overlap(ijet, 0.4) ) Njets30_LepIso04 += 1;
            HT30 += Jet_pt[ijet];
            HPx30 += Jet.Px();
            HPy30 += Jet.Py();
        }
        if( Jet_pt[ijet] > 40 ){
            Njets40 += 1;
            //if( !Jet_lep_overlap(ijet, 0.4) ) Njets40_LepIso04 += 1;
            HT40 += Jet_pt[ijet];
            HPx40 += Jet.Px();
            HPy40 += Jet.Py();
        }
        if( JetBTAG( ijet, JET_BTAG_WP ) ){
            Nbjets += 1;
            if( Jet_pt[ijet] > 30 ) Nbjets30 += 1;
            //if( !Jet_lep_overlap(ijet, 0.4) ){
            //    Nbjets_LepIso04 += 1;
            //    if( Jet_pt[ijet] > 30 ) Nbjets30_LepIso04 += 1;
            //}
        }
        if( Jet_pt[ijet] > 26 ) Njets_ISR += 1;
        // std::cout << "Jet_pt[ijet]: " << Jet_pt[ijet] << std::endl;
    }
    MHT = sqrt(HPx*HPx + HPy*HPy);
    MHT30 = sqrt(HPx30*HPx30 + HPy30*HPy30);
    MHT40 = sqrt(HPx40*HPx40 + HPy40*HPy40);
    MHT_trig = sqrt(HPx_trig*HPx_trig + HPy_trig*HPy_trig);

    MDT = abs(MHT_trig - MET_pt);
    // std::cout << "Jet_pt[selectedJet.at(0)] " << Jet_pt[selectedJet.at(0)] << std::endl;
    LeadingJet_pt = 0;
    SubLeadingJet_pt = 0;
    ThirdLeadingJet_pt = 0;
    FourthLeadingJet_pt = 0;
    if( Njets >= 1 ) LeadingJet_pt = Jet_pt[selectedJet.at(0)];
    if( Njets >= 2 ) SubLeadingJet_pt = Jet_pt[selectedJet.at(1)];
    if( Njets >= 3 ) ThirdLeadingJet_pt = Jet_pt[selectedJet.at(2)];
    if( Njets >= 4 ) FourthLeadingJet_pt = Jet_pt[selectedJet.at(3)];



}

