// Elaborar um algoritmo que lê 2 valores a e b e os escreve com a mensagem: ‘São múltiplos’ ou ‘Não são múltiplos’.

#include<iostream>
using namespace std;

int main (){
    int a{}, b{};

    // Input
    cout<<"Insira dois valores separados por um espaco (\" \"): ";
    cin>>a>>b;
    
    // Estrutura de Decisao
    if (a%b==0 || b%a==0) {
        cout<<"Sao multiplos!"<<'\n';
    } else {
        cout<<"Nao sao multiplos!"<<'\n';
    }
}
