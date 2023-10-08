// Com base no exercício 1 mostrar todos os valores digitados pares e todos os valores digitados impares.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int user_valor{}, max{0}, min{0};
    vector<int> valores (20);

    // INPUTS
    for (int i = 0; i < 20; i++){
        cout << "Insira o " << i+1 << " valor INTEIRO: ";
        cin >> user_valor;
        valores.at(i) = user_valor;
    }

    sort(valores.begin(), valores.end());
    max = valores.at(19);
    min = valores.at(0);

    const auto duplicata = adjacent_find(valores.begin(), valores.end());

    cout << "\nMAIOR numero: "<<max<<" | [19]" << "\n";
    cout << "MENOR numero: "<<min<<" | [0]" << "\n";
    
    if (duplicata != valores.end()){
        cout << "Existe DUPLICATA do elemento " << *duplicata << " | [" << distance(valores.begin(), duplicata) << "]" << "\n";
    } else {
        cout << "Nao ha duplicatas." << "\n";
    }
    
    /////////////////////////// CÓDIGO ANTERIOR //////////////////////////////

    vector<int> pares, impares;

    for (auto & elemento : valores) {
        if (elemento % 2 == 0) {
            pares.push_back(elemento);
        } else {
            impares.push_back(elemento);
        }
    }

    cout<<"\nNumeros PARES: ";
    for (auto && elemento : pares){
        cout<<elemento<<" ";
    }

    cout<<"\nNumeros IMPARES: ";
    for (auto && elemento : impares){
        cout<<elemento<<" ";
    }
}