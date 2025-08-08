/* Elaborar um algoritmo que lê um valor que se refere a altura de uma pessoa e mostra uma mensagem conforme a faixa de altura:
Altura                  Informação mostrada

menos que 1,50          “abaixo de um metro e meio”

de 1,50 a 1,80          “entre um metro e meio e um metro e oitenta centímetros”

mais que 1,80           “acima de um metro e oitenta centímetros”
*/

#include <iostream>
using namespace std;

int main()
{
    double altura_user{};

    // Input
    cout << "Insira sua altura: ";
    cin >> altura_user;

    // Estrutura de Decisao
    if (altura_user < 1.5)
    {
        cout << "Voce esta abaixo de um metro e meio (<1.50m)!" << '\n';
    }
    else if (altura_user >= 1.5 && altura_user <= 1.8)
    {
        cout << "Voce esta entre um metro e meio e um metro e oitenta centimetros (1.50m - 1.80m)!" << '\n';
    }
    else
    {
        cout << "Voce esta acima de um metro e oitenta centimetros (>1.80m)" << '\n';
    }
}