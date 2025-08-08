// Escreva um programa em C++ que solicita 10 números ao usuário, através de um laço while, e ao final mostre qual destes números é o maior.

#include<iostream>
using namespace std;

int main(){
    int contador{1};
    double num{}, maior_numero{0};

    while (contador <= 10){
        system("CLS");
        cout<<"Insira o "<<contador<<" numero\n";
        cin>>num;
        
        if (num > maior_numero){
            maior_numero = num;
        }
        contador++;
    }
    system("color 2f");
    system("CLS");
    cout<<"O maior numero destes e "<<maior_numero<<'\n';
}