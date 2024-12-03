# ![channel](feynman_diagram.svg)

**Analysis project for the hadronic channel of the bb(h/Z)+DM search using data from Run 3.**

Primeiro baixe a versão mais atualizada do HepHero

```bash
git clone https://github.com/DESY-CBPF-UERJ/HEPHero.git
```
Siga todos os passos presentes no "QuickStart" do HepHero, mas pare a etapa do setup. Acesse a pasta do HepHero
```bash
cd HEPHero
```
Dentro da pasta do HepHero, baixe o seu projeto, no nosso caso, é o AP_bbhZDM_Had_R3
```bash
git clone https://github.com/DESY-CBPF-UERJ/AP_bbhZDM_Had_R3.git
```

A partir daqui, você pode querer fazer duas coisas
* Executar seu projeto para adquirir os arquivos que serão trabalhados mais a frente
* Atualizar o projeto que está trabalhando (incluir features, funções e etc)


# Executando o projeto

Dentro da pasta do HepHero, mude o setup do projeto que está trabalhando, no nosso caso
```bash
python setAnalysis.py -a AP_bbhZDM_Had_R3
```
* Lembre-se de ter dado ```hepenv```!

A partir daqui, você executa o projeto como um projeto padrão do HepHero (veja o readme do HepHero para mais informações)


# Modificando o projeto (Trunk Based method)

Acesse a pasta do seu projeto, no nosso caso AP_bbhZDM_Had_R3

```bash
cd AP_bbhZDM_Had_R3
```
A partir daqui, todas as modificações que fizer, vão estar relacionadas ao git do seu projeto, por isso, é aconselhavel fazer uma branch, que indique o problema/feature que vai ser feita. Para exemplificar, os passos seguintes vão ser feitos, supondo que eu queira alterar o Readme do projeto (mas os passos são os mesmos para qualquer alteração!)







