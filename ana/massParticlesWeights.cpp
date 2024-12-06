#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Defin variables
//-------------------------------------------------------------------------------------------------
namespace massParticlesWeights{
    vector<float> param_variation_weights;
    float ZMass_qqbar;
    float Zmass;
    float amass_pseudoscalar;
    float amass_xx;
    float HMass_qq_chichi;
    
    float qq_pt;
    float qq_eta;
    float chichi_pt;
    float chichi_eta;
    float qqchichi_pt;
    float qqchichi_eta;
    
    int countZ = 0, countu = 0, countd = 0, counts = 0, countc = 0, countb = 0, countevents = 0, counta = 0, countchi = 0;

}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupmassParticlesWeights() {
    HDF_insert("ZMass_qqbar", &massParticlesWeights::ZMass_qqbar);
    HDF_insert("Zmass",&massParticlesWeights::Zmass);

    HDF_insert("amass_pseudoscalar",&massParticlesWeights::amass_pseudoscalar);
    HDF_insert("amass_xx",&massParticlesWeights::amass_xx);

    HDF_insert("HMass_qq_chichi",&massParticlesWeights::HMass_qq_chichi);

    HDF_insert("qq_pt",&massParticlesWeights::qq_pt);
    HDF_insert("qq_eta",&massParticlesWeights::qq_eta);
    HDF_insert("chichi_pt",&massParticlesWeights::chichi_pt);
    HDF_insert("chichi_eta",&massParticlesWeights::chichi_eta);
    HDF_insert("qqchichi_pt",&massParticlesWeights::qqchichi_pt);
    HDF_insert("qqchichi_eta",&massParticlesWeights::qqchichi_eta);

    HDF_insert("param_variation_weights", &massParticlesWeights::param_variation_weights);
    HDF_insert("nGenPart_RAW",&nGenPart);
    



    //======SETUP CUTFLOW==========================================================================
    //_cutFlow.insert(pair<string,double>("CutName", 0) );   [example]

    //======SETUP HISTOGRAMS=======================================================================
    //makeHist( "histogram1DName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeHist( "histogram2DName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]
    makeHist( "ZfornUU", 80, 60., 120., "M(u,u) GeV", "NEvents" );
    makeHist( "ZfornDD", 80, 60., 120., "M(d,d) GeV", "NEvents" );
    makeHist( "ZfornCC", 80, 60., 120., "M(c,c) GeV", "NEvents" );
    makeHist( "ZfornSS", 80, 60., 120., "M(s,s) GeV", "NEvents" );
    makeHist( "ZfornBB", 80, 60., 120., "M(b,b) GeV", "NEvents" );
    makeHist( "Zfornqq", 80, 60., 120., "M(q,q) GeV", "NEvents" );
    makeHist( "ZmassTH1", 80, 60., 120., "Mass GeV", "NEvents" );
    makeHist( "aPseudoscalarTH1", 80, 60., 150., "Mass GeV", "NEvents" );
    makeHist( "a_chichi_TH1", 80, 60., 150., "Mass GeV", "NEvents" );
    makeHist( "HMass_qq_chichi_TH1", 100, 300., 500., "Mass GeV", "NEvents" );
    makeHist( "weights", 80, 60., 120., "a", "NEvents" );

    //======SETUP SYSTEMATIC HISTOGRAMS============================================================
    //sys_regions = { 0, 1, 2 }; [example] // Choose regions as defined in RegionID. Empty vector means that all events will be used.
    //makeSysHist( "histogram1DSysName", 40, 0., 40., "xlabel", "ylabel" );   [example]
    //makeSysHist( "histogram2DSysName", 40, 0., 40., 100, 0., 50., "xlabel",  "ylabel", "zlabel", "COLZ" );   [example]

    //======SETUP OUTPUT BRANCHES==================================================================
    //_outputTree->Branch("variable1NameInTheTree", &massParticlesWeights::variable1Name );  [example]
        
    //======SETUP INFORMATION IN OUTPUT HDF5 FILE==================================================
    //HDF_insert("variable1NameInTheTree", &massParticlesWeights::variable1Name );  [example]

    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::massParticlesWeightsRegion() {

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
void HEPHero::massParticlesWeightsSelection() {
// Define TLorentzVector objects for quarks and Z boson
TLorentzVector quark, quark_bar, ZZero, aPseudoscalar, chi, chi_bar, Sumchi, Sumdd, Sumuu, Sumss, Sumcc, Sumbb;

// Boolean flags to check for presence of quark and antiquark
bool hasQuark = false, hasAntiQuark = false, hasChi = false, hasAntiChi = false ;

// Clear the TLorentzVector objects
Sumdd.Clear();
Sumuu.Clear();
Sumss.Clear();
Sumcc.Clear();
Sumbb.Clear();
quark.Clear();
quark_bar.Clear();
ZZero.Clear();
chi.Clear();
chi_bar.Clear();
Sumchi.Clear();
aPseudoscalar.Clear();
massParticlesWeights::param_variation_weights.clear();

// Check if the dataset group is "Signal" and populate param_variation_weights
if( dataset_group == "Signal" ) {
    for( unsigned int iw = 0; iw < nLHEReweightingWeight; ++iw ) {
        // Store each reweighting weight into param_variation_weights
        massParticlesWeights::param_variation_weights.push_back( LHEReweightingWeight[iw] );
    }
}

// Loop over all generated particles
for(int igen = 0; igen < nGenPart; ++igen){

    // Check if particle is a Z boson (pdgId == 23)
    if (GenPart_pdgId[igen] == 23){
        massParticlesWeights::countZ++;
        // Set ZZero to the Z boson's 4-momentum and fill Zmass histogram
        ZZero.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
        massParticlesWeights::Zmass = ZZero.M();
        _histograms1D.at("ZmassTH1").Fill(massParticlesWeights::Zmass);
    }

    // Check if particle is pseudscalar a (pdgId == 55)
    if (GenPart_pdgId[igen] == 55){
        massParticlesWeights::countZ++;
        // Set 'a' to the 4-momentum and fill 'a' histogram
        aPseudoscalar.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
        massParticlesWeights::amass_pseudoscalar = aPseudoscalar.M();
        _histograms1D.at("aPseudoscalarTH1").Fill(massParticlesWeights::amass_pseudoscalar);
    }

    // If the particle's mother is a Z boson
    if (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 23){

        // Check if particle is a down quark (|pdgId| == 1)
        if  (abs(GenPart_pdgId[igen]) == 1){
            // Set the quark or antiquark based on pdgId sign and update flags
            if (GenPart_pdgId[igen] == 1) {
                //Filling the TLorentzVector with quark 4-momentum information
                quark.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
                hasQuark = true;
            }
            if (GenPart_pdgId[igen] == -1) {
                //Filling the TLorentzVector with quark_bar 4-momentum information
                quark_bar.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
                hasAntiQuark = true;
            }
            // If both quark and antiquark are found, calculate invariant mass and fill histogram
            if (hasQuark && hasAntiQuark) {
                massParticlesWeights::countd++;
                Sumdd = quark + quark_bar;
                massParticlesWeights::ZMass_qqbar = Sumdd.M();
                massParticlesWeights::qq_pt = Sumdd.Pt();
                massParticlesWeights::qq_eta = Sumdd.Eta();
                _histograms1D.at("ZfornDD").Fill(Sumdd.M());
                hasQuark = false;
                hasAntiQuark = false;
            }
        }

        // Check if particle is an up quark (|pdgId| == 2) and repeat as above
        if (abs(GenPart_pdgId[igen]) == 2) {
            if (GenPart_pdgId[igen] == 2) {
                quark.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
                hasQuark = true;
            }
            if (GenPart_pdgId[igen] == -2) {
                quark_bar.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
                hasAntiQuark = true;
            }
            if (hasQuark && hasAntiQuark) {
                massParticlesWeights::countu++;
                Sumuu = quark + quark_bar;
                massParticlesWeights::ZMass_qqbar = Sumuu.M();
                massParticlesWeights::qq_pt = Sumuu.Pt();
                massParticlesWeights::qq_eta = Sumuu.Eta();
                _histograms1D.at("ZfornUU").Fill(Sumuu.M());
                hasQuark = false;
                hasAntiQuark = false;
            }
        }

        // Check if particle is a strange quark (|pdgId| == 3) and repeat as above
        if (abs(GenPart_pdgId[igen]) == 3) {
            if (GenPart_pdgId[igen] == 3) {
                quark.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
                hasQuark = true;
            }
            if (GenPart_pdgId[igen] == -3) {
                quark_bar.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
                hasAntiQuark = true;
            }
            if (hasQuark && hasAntiQuark) {
                massParticlesWeights::counts++;
                Sumss = quark + quark_bar;
                massParticlesWeights::ZMass_qqbar = Sumss.M();
                massParticlesWeights::qq_pt = Sumss.Pt();
                massParticlesWeights::qq_eta = Sumss.Eta();
                _histograms1D.at("ZfornSS").Fill(Sumss.M());
                hasQuark = false;
                hasAntiQuark = false;
            }
        }

        // Check if particle is a charm quark (|pdgId| == 4) and repeat as above
        if (abs(GenPart_pdgId[igen]) == 4) {
            if (GenPart_pdgId[igen] == 4) {
                quark.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
                hasQuark = true;
            }
            if (GenPart_pdgId[igen] == -4) {
                quark_bar.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
                hasAntiQuark = true;
            }
            if (hasQuark && hasAntiQuark) {
                massParticlesWeights::countc++;
                Sumcc = quark + quark_bar;
                massParticlesWeights::ZMass_qqbar = Sumcc.M();
                massParticlesWeights::qq_pt = Sumcc.Pt();
                massParticlesWeights::qq_eta = Sumcc.Eta();
                _histograms1D.at("ZfornCC").Fill(Sumcc.M());
                hasQuark = false;
                hasAntiQuark = false;
            }
        }

        // Check if particle is a bottom quark (|pdgId| == 5) and repeat as above
        if (abs(GenPart_pdgId[igen]) == 5) {
            if (GenPart_pdgId[igen] == 5) {
                quark.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
                hasQuark = true;
            }
            if (GenPart_pdgId[igen] == -5) {
                quark_bar.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
                hasAntiQuark = true;
            }
            if (hasQuark && hasAntiQuark) {
                massParticlesWeights::countb++;
                Sumbb = quark + quark_bar;
                massParticlesWeights::ZMass_qqbar = Sumbb.M();
                massParticlesWeights::qq_pt = Sumbb.Pt();
                massParticlesWeights::qq_eta = Sumbb.Eta();
                _histograms1D.at("ZfornBB").Fill(Sumbb.M());
                hasQuark = false;
                hasAntiQuark = false;
            }
        }
        _histograms1D.at("Zfornqq").Fill(massParticlesWeights::ZMass_qqbar);
    }

     // If the particle's mother is a aPseudoscalar
    if (GenPart_pdgId[GenPart_genPartIdxMother[igen]] == 55){

        // Check if particle is a chi (|pdgId| == 52)
        if  (abs(GenPart_pdgId[igen]) == 52){
            // Set the chi or chi_bar based on pdgId sign and update flags
            if (GenPart_pdgId[igen] == 52) {
                //Filling the TLorentzVector with quark 4-momentum information
                chi.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
                hasChi = true;
            }
            if (GenPart_pdgId[igen] == -52) {
                //Filling the TLorentzVector with chi_bar 4-momentum information
                chi_bar.SetPtEtaPhiM(GenPart_pt[igen], GenPart_eta[igen], GenPart_phi[igen], GenPart_mass[igen]);
                hasAntiChi = true;
            }
            // If both chi and antichi are found, calculate invariant mass and fill histogram
            if (hasChi && hasAntiChi) {
                massParticlesWeights::countchi++;
                Sumchi = chi + chi_bar;
                massParticlesWeights::amass_xx = Sumchi.M();
                massParticlesWeights::chichi_pt = Sumchi.Pt();
                massParticlesWeights::chichi_eta = Sumchi.Eta();
                _histograms1D.at("a_chichi_TH1").Fill(massParticlesWeights::amass_xx);
                hasChi = false;
                hasAntiChi = false;
            }
        }
    }

}

TLorentzVector Sum_qq_chichi = Sumchi + Sumdd + Sumuu + Sumss + Sumcc + Sumbb;
massParticlesWeights::HMass_qq_chichi = Sum_qq_chichi.M();
massParticlesWeights::qqchichi_pt = Sum_qq_chichi.Pt();
massParticlesWeights::qqchichi_eta = Sum_qq_chichi.Eta();
cout << massParticlesWeights::chichi_pt << endl;
 _histograms1D.at("HMass_qq_chichi_TH1").Fill(massParticlesWeights::HMass_qq_chichi);

    //======ASSIGN VALUES TO THE OUTPUT VARIABLES==================================================
    //massParticlesWeights::variable1Name = 100;      [Example]

    //======FILL THE HISTOGRAMS====================================================================
   
    //======FILL THE OUTPUT TREE===================================================================
    //_outputTree->Fill();

    //======FILL THE OUTPUT HDF5 INFO===============================================================
    HDF_fill();

    return;
}


//-------------------------------------------------------------------------------------------------
// Produce systematic histograms
//-------------------------------------------------------------------------------------------------
void HEPHero::massParticlesWeightsSystematic() {

    //FillSystematic( "histogram1DSysName", var, evtWeight );  [Example]
    //FillSystematic( "histogram2DSysName", var1, var2, evtWeight );  [Example]
}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishmassParticlesWeights() {

    //MakeEfficiencyPlot( _histograms1D.at("Matched_pt"), _histograms1D.at("all_pt"), "Match_pt" );   [example]

    return;
}
