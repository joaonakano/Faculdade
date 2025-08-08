#include<iostream>
using namespace std;

int main(){
    double quantidade_reais{0};

    cout<<"Insira a quantidade de reais que deseja contabilizar: R$";
    cin>>quantidade_reais;

    int notas_cem{quantidade_reais/100};
    quantidade_reais = (notas_cem>=1) ? quantidade_reais-=notas_cem*100:quantidade_reais;

    int notas_cinquenta{quantidade_reais/50};
    quantidade_reais = (notas_cinquenta>=1) ? quantidade_reais-=notas_cinquenta*50:quantidade_reais;

    int notas_vinte{quantidade_reais/20};
    quantidade_reais = (notas_vinte>=1) ? quantidade_reais-=notas_vinte*20:quantidade_reais;

    int notas_dez{quantidade_reais/10};
    quantidade_reais = (notas_dez>=1) ? quantidade_reais-=notas_dez*10:quantidade_reais;

    int notas_cinco{quantidade_reais/5};
    quantidade_reais = (notas_cinco>=1) ? quantidade_reais-=notas_cinco*5:quantidade_reais;

    int notas_dois{quantidade_reais/2};
    quantidade_reais = (notas_dois>=1) ? quantidade_reais-=notas_dois*2:quantidade_reais;

    int moedas_real{quantidade_reais};
    quantidade_reais = (moedas_real>=1) ? quantidade_reais-=moedas_real:quantidade_reais;

    int moedas_cinquenta{quantidade_reais/0.5};
    quantidade_reais = (moedas_cinquenta>=1) ? quantidade_reais-=moedas_cinquenta*0.5:quantidade_reais;

    int moedas_vintecinco{quantidade_reais/0.25};
    quantidade_reais = (moedas_vintecinco>=1) ? quantidade_reais-=moedas_vintecinco*0.25:quantidade_reais;

    int moedas_dez{quantidade_reais/0.1};
    quantidade_reais = (moedas_dez>=1) ? quantidade_reais-=moedas_dez*0.1:quantidade_reais;

    int moedas_cinco{quantidade_reais/0.05};
    quantidade_reais = (moedas_cinco>=1) ? quantidade_reais-=moedas_cinco*0.05:quantidade_reais;

    int moedas_um{quantidade_reais/0.01};
    quantidade_reais = (moedas_um>=1) ? quantidade_reais-=(moedas_um*0.01):quantidade_reais;

    cout<<"\nNotas 100: "<<notas_cem;
    cout<<"\nNotas 50: "<<notas_cinquenta;
    cout<<"\nNotas 20: "<<notas_vinte;
    cout<<"\nNotas 10: "<<notas_dez;
    cout<<"\nNotas 5: "<<notas_cinco;
    cout<<"\nNotas 2: "<<notas_dois;
    cout<<"\nMoedas 1 real: "<<moedas_real;
    cout<<"\nMoedas 50 centavos: "<<moedas_cinquenta;
    cout<<"\nMoedas 25 centavos: "<<moedas_vintecinco;
    cout<<"\nMoedas 10 centavos: "<<moedas_dez;
    cout<<"\nMoedas 5 centavos: "<<moedas_cinco;
    cout<<"\nMoedas 1 centavos: "<<moedas_um;
}
