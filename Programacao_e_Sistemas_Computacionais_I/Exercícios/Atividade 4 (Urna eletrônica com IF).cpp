/*
Faça um programa que simule a urna eletrônica.
A tela a ser apresentada deverá ser da seguinte forma:
As opções são:
1. Candidato Antônio
2. Candidato Simão
3. Fim da votação

O programa deverá ler os votos dos eleitores e, quando for digitado o
número 3, apresentar as seguintes o número de votos de cada
candidato.
Fazer dois codigos, um utilizando if e outro switch.
*/

#include<iostream>
using namespace std;

int main(){
    string enfeite_borda{" —————————————————✦—————————————————"};
    int opcao_usuario{0}, votos_antonio{0}, votos_simao{0};

    cout<<enfeite_borda<<'\n'<<"  BEM VINDO(A) AO SISTEMA ELEITORAL!\n\n";
    cout<<"  (1) - Candidato Antonio\n  (2) - Candidato Simao\n  (3) - Fim da votacao\n\n";

    do{
        cout<<"Digite o numero correspondente a opcao desejada: ";
        cin>>opcao_usuario;

        if(opcao_usuario == 1){
            votos_antonio++;
        } else if (opcao_usuario == 2) {
            votos_simao++;
        } else {
            cout<<"Digite um numero valido!"<<'\n';
        }
    } while(opcao_usuario != 3);

    cout<<enfeite_borda<<'\n'<<"          VOTAÇÃO ENCERRADA!"<<"\n\n\n\n\n";
    cout<<"VOTOS DO CANDIDATO ANTONIO: "<<votos_antonio<<"\n";
    cout<<"VOTOS DO CANDIDATO SIMAO: "<<votos_simao<<"\n\n\n\n\n";
}