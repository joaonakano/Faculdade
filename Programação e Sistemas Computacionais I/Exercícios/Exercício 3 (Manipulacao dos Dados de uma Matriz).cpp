/* Faça um programa que leia 10 números inteiros, armazene-os em um vetor, solicite um valor de referência inteiro e:
    a) Imprima os números do vetor que são maiores que o valor referência.
    b) Retorne quantos números armazenados no vetor são menores que o valor de referência.
    c) Retorne quantas vezes o valor de referência aparece no vetor.
*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> valores, maiores_referencial;
    int referencia{}, valor{}, menores_referencial{}, duplicatas{};

    for (int i = 0; i < 10; i++){
        cout << "Insira o " << i+1 << " numero INTEIRO: ";
        cin >> valor;
        valores.push_back(valor);
    }

    cout << "\nInsira um valor referencial INTEIRO: ";
    cin >> referencia;

    for (auto & elemento : valores){
        if (elemento > referencia){
            maiores_referencial.push_back(elemento);
        } else if (elemento < referencia){
            menores_referencial++;
        } else if (elemento == referencia){
            duplicatas++;
        }
    }

    cout << "\nNumeros maiores que o referencial: ";    // a)
    for (auto && elemento : maiores_referencial){
        cout << elemento << " ";
    }

    cout << "\nQuantos numeros sao menores que o referencial: " << menores_referencial << "\n";    // b)
    cout << "Quantas vezes o referencial e repetido: " << duplicatas << endl;    // c)
}