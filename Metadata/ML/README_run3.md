# Dois discriminantes ONNX

O modelo antigo `model.onnx`, a função `Get_Signal_Taggers()` e a variável
`signal_tag` são preservados. O novo arquivo é `model_run3.onnx`, carregado por
`signal_tagger_run3`, com função `Get_Signal_Taggers_Run3()` e saída
`signal_tag_run3`.

Em `setup.py`, `NN_model_run3_X_XX` gera a opção `NN_model_run3` do arquivo de
configuração. O `runSelection.py` atual também recebeu essa entrada. Configurações
antigas sem essa opção continuam executando só o modelo antigo; nesse caso o
novo score fica em `-1` e seu histograma não é preenchido.

As seleções Study_ExcludedRegion, Study_GEN, Test e HEPWeights calculam ambos
os scores e salvam ambos no HDF5. Study_ExcludedRegion também produz os dois
histogramas sistemáticos. Os cortes existentes continuam usando `signal_tag`.
O setup continua selecionando Hist_for_Pileup_wgt: essa seleção não calcula
discriminantes. Para analisá-los, gerar jobs da seleção Study_ExcludedRegion
ou de outra seleção acima.

## Interface e interpretação

- Entrada `features`: float32 `[N, 26]`.
- Saída `output`: float32 `[N, 1]`.
- Normalização e sigmoid já estão no ONNX.
- `signal_tag_run3` guarda a saída direta, sem aplicar `1 - output`.
  A identificação da classe 1 como sinal deve ser conferida no treinamento.
- O wrapper mantém a inversão antiga como padrão; só o novo tagger solicita
  a saída direta. O ambiente ONNX agora vive tanto quanto a sessão.

## Ordem das entradas

1. FMax
2. FatJet_globalParT3_QCD
3. FatJet_globalParT3_TopbWqq
4. FatJet_globalParT3_Xbb
5. FatJet_globalParT3_Xcc
6. FatJet_globalParT3_Xcs
7. FatJet_globalParT3_Xqq
8. FatJet_globalParT3_massCorrGeneric
9. FatJet_globalParT3_massCorrX2p
10. FatJet_globalParT3_withMassTopvsQCD
11. FatJet_globalParT3_withMassWvsQCD
12. FatJet_globalParT3_withMassZvsQCD
13. FatJet_msoftdrop
14. FatJet_nConstituents
15. FatJet_pt
16. HT
17. MET_FatJet_Mt
18. MET_FatJet_deltaPhi
19. MET_pt (PFMET_pt no projeto)
20. MHT
21. Nbjets
22. OmegaMin
23. RECO_mass_tran_met_close_part_jetB
24. RT_1
25. RT_3
26. tauT

A ordem foi fornecida pelo usuário. As entradas do fatjet usam
`selectedFatJet.at(0)`, como na função antiga. A origem da entrada 23 no
Study_GEN foi confirmada pelo usuário: reproduzimos o MT do último b-jet em
selectedJet (zero sem b-jet), exatamente como a coluna existente. Ela difere
da coluna RECO_true_mass_tran_met_close_part_jetB, que usa o menor deltaPhi.

SHA256 do novo modelo:
`0568431f1705f3654d1f343a65d956695387eeb67c5bc21f8b6b829676fb1409`

SHA256 preservado do modelo antigo:
`9a00cefd0807649bf027c49ad695d5683dd0b7b7bf898b146aeae36c0d6bad03`

## Estado da entrega

Compilação concluída com sucesso. Teste do wrapper em 32 vetores concordou
com ONNX Runtime Python (diferença máxima absoluta de 5e-10).
A validação em eventos foi interrompida a pedido do usuário e será feita por ele.
Nenhum resultado de física foi validado nesta entrega.
Backups e logs: /home/mcostare/tmp/run3_model_test_20260924_170500.
