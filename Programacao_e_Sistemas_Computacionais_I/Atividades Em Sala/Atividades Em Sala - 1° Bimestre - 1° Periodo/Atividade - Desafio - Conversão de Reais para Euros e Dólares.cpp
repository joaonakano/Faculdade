/*
1 - Fazer um programa para Converter Reais para Dólares e Euros.
2 - Fazer um programa para descobrir a idade de uma pessoa, considerando apenas ano de nascimento e ano atual.
3 - Fazer um programa que pergunte um valor em metros e imprima o correspondente em decímetros, centímetros e milímetros.
4 - Fazer um programa que lê o preço de um produto e inflacione o preço em 10% se ele for menor que 100 reais e em 20% se for maior ou igual a 100 reais.
*/

#include<iostream>
#include <cstdio>

using namespace std;
int main(){
    double valor_real;
    //const double valor_dolar{5.25};
    const double valor_euro{5.63};

    // Input
    cout<<"Indique o valor em REAIS a ser convertido: "<<endl;
    cin>>valor_real;

    // Output
    cout<<"O valor de "<<valor_real<<endl;
    //cout<<"O valor em EURO "<<valor_real/valor_euro<<endl;
    printf("O valor em EURO %.2f",valor_real/valor_euro);
    //cout<<"O valor em DOLAR "<<valor_real/valor_dolar<<endl;
}