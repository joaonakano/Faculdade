#include<iostream>
using namespace std;

int main(){
    int numero_de_idades_user{}, somatorio_das_idades{}, idade_atual{};
    double media{};

    cout<<"Qual o numero de idades que gostaria de calcular a media? ";
    cin>>numero_de_idades_user;

    for(int i = 1; i <= numero_de_idades_user; i++){
        cout<<"Insira a "<<i<<" idade: ";
        cin>>idade_atual;
        somatorio_das_idades += idade_atual;
    }
    
    media = (double)somatorio_das_idades / (double)numero_de_idades_user;
    cout<<"A media de todas as "<<numero_de_idades_user<<" e: "<<media<<'\n';
}