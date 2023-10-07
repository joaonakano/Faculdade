// Faça um programa que leia 5 valores inteiros, armazeno-os em um vetor, calcule e apresente a soma

#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> valores;
    int valor_user{}, soma{};

    for (int i = 0; i < 5; i++){
        cout << "Insira o " << i+1 << " valor INTEIRO: ";
        cin >> valor_user;
        valores.push_back(valor_user);
        soma += valor_user;
    }

    cout << "A soma de todos os elementos do Vetor e: " << soma << "\n";
}