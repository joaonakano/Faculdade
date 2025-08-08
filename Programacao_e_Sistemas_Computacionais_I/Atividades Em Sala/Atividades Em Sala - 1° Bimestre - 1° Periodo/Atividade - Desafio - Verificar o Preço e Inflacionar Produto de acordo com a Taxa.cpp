/*
4 - Fazer um programa que lê o preço de um produto e inflacione o preço em 10% se ele for menor que 100 reais e em 20% se for maior ou igual a 100 reais.
*/

#include<iostream>
using namespace std;
int main(){
    double valor_produto;
    
    const double taxa_menor_que_cem{0.1};
    const double taxa_maior_ou_igual_a_cem{0.2};

    // Input
    cout<<"Insira o valor do produto: ";
    cin>>valor_produto;

    // Calculo
    if (valor_produto < 100){
        valor_produto = valor_produto + valor_produto*taxa_menor_que_cem;
        cout<<valor_produto;
    } else {
        valor_produto = valor_produto + valor_produto*taxa_maior_ou_igual_a_cem;
        cout<<valor_produto;

    }
}