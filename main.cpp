#include <iostream>
#include <stdio.h>
#include <string>
#include "CamadaFisica.h"

using namespace std;

int main() {
    // Função core do simulador que da inicio ao programa
    AplicacaoTransmissora();
    return 0;
}

// Função inicial que recebe o dado do usuario (como se fosse a aplicação)
// e repassa tal dado para a próxima camada da corrente de transmissão
// pegando pelo console uma string e enviando para a próxima função
void AplicacaoTransmissora(){
    string mensagem;
    cout << "Digite a mensagem a ser enviada" << endl;
    cin >> mensagem;
    // Chamada da próxima camada
    ChamadaDeAppTransmissora(mensagem);
}

// Função que recebe a mensagem (string), a transforma em um array de char
// e passa o array para a próxima camada
void ChamadaDeAppTransmissora(string mensagem){
    // Declaração do array com tamanho máximo de 1024 caracteres
    char quadro[1024];
    // Copiando a string passada por argumento para o array
    strncpy(quadro, mensagem.c_str(), sizeof(quadro));
    // Certificando que os caracteres não usados do array sejam zerados
    quadro[sizeof(quadro) - 1] = 0;
    // Chamada da próxima camada
    CamadaFisiccaTransmissora(quadro);
}

// Função que recebe o array de dados, decide a codificação a ser utilizada,
// encaminha os dados para serem codificados e envia os dados codificados para
// a o meio de transmição (função que simula um meio físico de transmissão de dados)
void CamadaFisiccaTransmissora(char quadro[]){

}

// Função que simula um meio de transmissão físico perfeito (sem perdas ou ruidos)
void MeioDeTransmissao(char fluxoBrutoDeBits[]){
    char fluxoBrutoDeBitsA[1024], fluxoBrutoDeBitsB[1024];
    int i = 0;
    while(fluxoBrutoDeBits[i]){
        fluxoBrutoDeBitsA[i] = fluxoBrutoDeBits[i];
        i++;
    }
    while(fluxoBrutoDeBitsA[i]){
        fluxoBrutoDeBitsB[i] = fluxoBrutoDeBitsA[i];
        i++;
    }
    CamadaFisicaReceptora(fluxoBrutoDeBitsB);
}

// Função que recebe o array de dados bruto, decide a decodificação a ser utilizada,
// encaminha os dados para serem decodificados e envia os dados decodificados para
// a próxima camada
void CamadaFisicaReceptora(char quadro[]){

}

// Função que recebe o array de char decodificado na camada anterior
// e o converte para a mensagem (string) final a ser processada pela
// camada de aplicação
void CamadaDeAppReceptora(char quadro[]){
    int i = 0;
    while(quadro[i]){
        i++;
    }
    // Declaração da string
    string mensagem = convertToString(quadro,i);
    AplicacaoReceptora(mensagem);
}

// Função que simula a aplicação que receberia os dados enviados e os mostraria na tela
void AplicacaoReceptora(string mesnagem){
    cout << "A mensagem enviada foi: " << mesnagem << endl;
}

// Funcoes Auxiliares
string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}