// Escreva um programa que receba do usuário um vetor com 20 valores inteiros e apresente o maior, o menor e suas respectivas posições em que os mesmos foram informados. Caso existam números iguais mostre a posição da primeira ocorrência.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int user_valor{}, max{}, min{};
    vector<int> valores (20);

    // INPUTS
    for (int i = 0; i < 20; i++){
        cout << "Insira o " << i+1 << " valor INTEIRO: ";
        cin >> user_valor;
        valores.at(i) = user_valor;
    }

    sort(valores.begin(), valores.end());    // Organiza os numeros em ordem crescente
    max = valores.at(19);    // Como os valores estarao dispostos em ordem, o ultimo numero sera sempre o maior
    min = valores.at(0);    // A mesma logica do item anterior se aplica aqui

    const auto duplicata = adjacent_find(valores.begin(), valores.end());    // Procura se ha numeros iguais e o Iterador para quando houver

    cout << "\nMAIOR NUMERO: "<<max<<" | [19]" << "\n";
    cout << "MENOR NUMERO: "<<min<<" | [0]" << "\n";
    
    if (duplicata != valores.end()){
        cout << "Existe duplicata do elemento " << *duplicata << " | [" << distance(valores.begin(), duplicata) << "]" << "\n";     // Calculo de onde a primeira duplicata se encontra com distance(inicio -> duplicata)
    } else {
        cout << "Nao ha duplicatas." << "\n";
    }
}