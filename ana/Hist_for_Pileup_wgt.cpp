#include "HEPHero.h"

//-------------------------------------------------------------------------------------------------
// Description:
//-------------------------------------------------------------------------------------------------

/*
Esse anafile é usado somente para gerar os histogramas do Numero de interações de pileup das amos-
tras de MC. Seguindo alguns pontos

1 - Nenhum corte deve ser aplicado!
2 - Espera-se que todas as amostras tenham as mesmas distribuições, pois usam a mesma configuração
do CMSDriver
3 - Esses histogramas devem ser comparados com o que esperamos nos dados, seguindo aqui a recomen-
dação do https://twiki.cern.ch/twiki/bin/viewauth/CMS/PileupJSONFileforData?extralog=-%20caching%20topic
4 - Com isso podemos gerar os pesos de pileup corretos para cada ano, no nosso caso 2024.


PS: ESSE ANAFILE SO EXISTE PQ O CMS NÃO PRODUZIO O PESO CENTRALMENTE PARA 2024. Uma vez que ele exis-
ta não tem sentido fazer esse estudo e esse anafile fica somente para futuras consultas/investigações

Informações adcionais:

Devido ao fato de não aplicarmos cortes, se rodarmos para todos os eventos disponiveis na simulação
vamos ter uma quantidade gigantesca de dados, o que impede a gente de fazer estudos offline (o que 
seria a proxima etapa desse estudo). Por isso use essas configurações no seu setup.py

NumMaxEvents = 40000
NumFilesPerJob_Data = 1   
NumFilesPerJob_Signal = 50 
NumFilesPerJob_Bkg = 5  


periods = [
"0_24",
]

datasets = [
"Signal",
"QCD",
"ST",
"TT",
"Zto2Nu",
"WtoLNu",
"VV",
"Vh",
"Others",
]


*/


//-------------------------------------------------------------------------------------------------
// Define output variables
//-------------------------------------------------------------------------------------------------
namespace Hist_for_Pileup_wgt{

}


//-------------------------------------------------------------------------------------------------
// Define output derivatives
//-------------------------------------------------------------------------------------------------
void HEPHero::SetupHist_for_Pileup_wgt() {

    HDF_insert( "Pileup_nTrueInt", &Pileup_nTrueInt );  


    return;
}


//-------------------------------------------------------------------------------------------------
// Define the selection region
//-------------------------------------------------------------------------------------------------
bool HEPHero::Hist_for_Pileup_wgtRegion() {


    return true;
}


//-------------------------------------------------------------------------------------------------
// Write your analysis code here
//-------------------------------------------------------------------------------------------------
void HEPHero::Hist_for_Pileup_wgtSelection() {

    HDF_fill();

    return;
}


//-------------------------------------------------------------------------------------------------
// Produce systematic histograms
//-------------------------------------------------------------------------------------------------
void HEPHero::Hist_for_Pileup_wgtSystematic() {

}


//-------------------------------------------------------------------------------------------------
// Make efficiency plots
//-------------------------------------------------------------------------------------------------
void HEPHero::FinishHist_for_Pileup_wgt() {


    return;
}
