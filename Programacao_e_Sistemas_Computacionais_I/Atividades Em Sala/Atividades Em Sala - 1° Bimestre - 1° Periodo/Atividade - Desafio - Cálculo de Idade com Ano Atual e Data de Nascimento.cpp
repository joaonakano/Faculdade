// 2 - Fazer um programa para descobrir a idade de uma pessoa, considerando apenas ano de nascimento e ano atual.

#include<iostream>
using namespace std;
int main() {
    int ano_user;
    const int ano_atual{2023};
    cout<<"\nMeu nome e Akinator, eu adivinharei sua idade! *emoji pensando*"<<endl;
    cout<<"Insira o ano de nascimento: ";
    cin>>ano_user;
    cout<<"Vejamos.... Voce tem...... Puxa, ta dificil....."<<endl;
    cout<<"Voce tem "<<ano_atual-ano_user<<"\n";
}