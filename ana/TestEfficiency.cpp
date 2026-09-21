#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//
// Salva as variáveis necessárias para estudar offline a eficiência dos cortes:
//   - trigger;
//   - veto de léptons;
//   - presença de b-jet;
//   - MET e MHT (valores em GeV, sem cortes);
//   - presença de fat jet;
//   - corte em OmegaMin.
//
// Nenhum corte é aplicado neste anafile.
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace TestEfficiency {

    // Decisão do trigger
    int trigger;

    // Multiplicidades reconstruídas
    int Nleptons_value;
    int Nbjets_value;
    int NfatJets_value;

    // Variável angular
    float OmegaMin_value;

    // Informações adicionais do fat jet principal
    float FatJet_pt;
    float FatJet_msoftdrop;
}


//-------------------------------------------------------------------------------------------------
// Configure output
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupTestEfficiency() {

    // MET do evento e MHT calculado por JetSelection(), em GeV.
    // HDF_insert registra os enderecos; HDF_fill salva os valores do evento
    // depois da execucao de TestEfficiencyRegion(). Nenhum corte e aplicado.
    HDF_insert("MET_pt", &PFMET_pt);
    HDF_insert("MHT", &MHT);


    // Nenhum cutflow de seleção é definido porque os cortes
    // serão aplicados posteriormente, de forma offline.

    // Variável usada no corte de trigger
    HDF_insert(
        "trigger",
        &TestEfficiency::trigger
    );

    // Variável usada no veto de léptons
    HDF_insert(
        "Nleptons",
        &TestEfficiency::Nleptons_value
    );

    // Variável usada no requisito de b-jet
    HDF_insert(
        "Nbjets",
        &TestEfficiency::Nbjets_value
    );

    // Variável usada no requisito de fat jet
    HDF_insert(
        "NfatJets",
        &TestEfficiency::NfatJets_value
    );

    // Variável usada no corte angular
    HDF_insert(
        "OmegaMin",
        &TestEfficiency::OmegaMin_value
    );

    // Informações adicionais do fat jet principal
    HDF_insert(
        "FatJet_pt",
        &TestEfficiency::FatJet_pt
    );

    HDF_insert(
        "FatJet_msoftdrop",
        &TestEfficiency::FatJet_msoftdrop
    );

    return;
}


//-------------------------------------------------------------------------------------------------
// Calculate variables without applying event cuts
//-------------------------------------------------------------------------------------------------
bool HEPHero::TestEfficiencyRegion() {

    //---------------------------------------------------------------------------------------------
    // Trigger
    //
    // Trigger() é apenas avaliado. O resultado é salvo como 0 ou 1,
    // mas nenhum evento é rejeitado.
    //---------------------------------------------------------------------------------------------
    TestEfficiency::trigger = Trigger() ? 1 : 0;


    //---------------------------------------------------------------------------------------------
    // Leptons
    //
    // Constrói a coleção de léptons e salva sua multiplicidade.
    // O veto Nleptons == 0 será aplicado offline.
    //---------------------------------------------------------------------------------------------
    LeptonSelection();

    TestEfficiency::Nleptons_value = Nleptons;


    //---------------------------------------------------------------------------------------------
    // Jets and b-jets
    //
    // Constrói as coleções de jets e b-jets e calcula MHT.
    // MHT e registrado diretamente no HDF5, sem exigir MHT > 200 GeV.
    // O requisito Nbjets > 0 será aplicado offline.
    //---------------------------------------------------------------------------------------------
    JetSelection();

    TestEfficiency::Nbjets_value = Nbjets;


    //---------------------------------------------------------------------------------------------
    // Fat jets
    //
    // Constrói a coleção de fat jets e salva NfatJets.
    // O requisito NfatJets > 0 será aplicado offline.
    //---------------------------------------------------------------------------------------------
    FatjetSelection();

    TestEfficiency::NfatJets_value = NfatJets;


    //---------------------------------------------------------------------------------------------
    // Angular variables
    //
    // Calcula OmegaMin, mas não aplica OmegaMin > OMEGA_CUT.
    //---------------------------------------------------------------------------------------------
    Get_Jet_Angular_Variables();

    TestEfficiency::OmegaMin_value = OmegaMin;


    //---------------------------------------------------------------------------------------------
    // Leading selected fat jet
    //
    // Quando não houver fat jet selecionado, são usados valores sentinela.
    // Isso mantém o evento no arquivo e permite identificá-lo offline.
    //---------------------------------------------------------------------------------------------
    if (!selectedFatJet.empty()) {

        const int fatjet_index = selectedFatJet.at(0);

        TestEfficiency::FatJet_pt =
            FatJet_pt[fatjet_index];

        TestEfficiency::FatJet_msoftdrop =
            FatJet_msoftdrop[fatjet_index];

    } else {

        TestEfficiency::FatJet_pt = 0.0;
        TestEfficiency::FatJet_msoftdrop = -1.0;
    }


    //---------------------------------------------------------------------------------------------
    // Event weights
    //
    // Calcula as correções dos pesos, mas não rejeita eventos.
    // O evtWeight é normalmente salvo automaticamente pelo HEPHero.
    //---------------------------------------------------------------------------------------------
    Weight_corrections();


    //---------------------------------------------------------------------------------------------
    // Accept every event
    //---------------------------------------------------------------------------------------------
    return true;
}


//-------------------------------------------------------------------------------------------------
// Save every accepted event
//-------------------------------------------------------------------------------------------------
void HEPHero::TestEfficiencySelection() {

    HDF_fill();

    return;
}


//-------------------------------------------------------------------------------------------------
// Systematic histograms
//-------------------------------------------------------------------------------------------------
void HEPHero::TestEfficiencySystematic() {

    // Nenhum histograma sistemático é produzido neste anafile.

    return;
}


//-------------------------------------------------------------------------------------------------
// Finish
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishTestEfficiency() {

    return;
}

