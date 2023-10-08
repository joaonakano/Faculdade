// Criar um programa que possui um menu com switch case onde o usuário escolhe qual operação matemática ele gostaria de fazer: soma, subtração, multiplicação e divisão. O usuário deverá informar dois números para realizar a operação.

#include<iostream>
using namespace std;
int main(){
    double numero_1{}, numero_2{};
    char operacao{};

    cout<<"Insira o primeiro numero: ";
    cin>>numero_1;
    cout<<"Insira o segundo numero: ";
    cin>>numero_2;

    cout<<"Qual operacao desejas fazer (A)dicao, (S)ubtracao, (M)ultiplicacao ou (D)ivisao? ";
    cin>>operacao;

    switch(operacao){
        case 'a':
        case 'A':
            cout<<"A adicao destes dois numeros sera: "<<numero_1+numero_2;
            break;
        case 's':
        case 'S':
            cout<<"A subtracao destes dois numeros sera: "<<numero_1-numero_2;
            break;
        case 'm':
        case 'M':
            cout<<"A multiplicacao destes dois numeros sera: "<<numero_1*numero_2;
            break;
        case 'd':
        case 'D':
            cout<<"A divisao destes dois numeros sera: "<<numero_1/numero_2;
            break;
        default:
            cout<<"Voce inseriu um ou mais caracteres invalidos!";
            break;
    }

}