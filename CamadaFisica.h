//
// Pedro Fernandes - 180108069
//
#ifndef TR1_CAMADAFISICA_H
#define TR1_CAMADAFISICA_H
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
void AplicacaoTransmissora();
void ChamadaDeAppTransmissora(string mensagem);
void CamadaFisiccaTransmissora(char quadro[]);

void MeioDeTransmissao(char fluxoBrutoDeBits);
void CamadaFisicaReceptora(char quadro[]);

void CamadaDeAppReceptora(char quadro[]);
void AplicacaoReceptora(string mesnagem);

// Funcoes auxiliares
string convertToString(char* a, int size);

#endif //TR1_CAMADAFISICA_H
