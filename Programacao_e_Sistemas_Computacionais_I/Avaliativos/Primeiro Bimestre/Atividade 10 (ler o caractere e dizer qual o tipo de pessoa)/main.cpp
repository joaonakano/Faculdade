// um algoritmo que leia uma letra que pode ser ‘F’ ou ‘J’ e mostra a mensagem “pessoa física”, “pessoa jurídica” ou "tipo de pessoa inválido", conforme o caso.

#include <iostream>
using namespace std;

int main()
{
    char letra_user{};

    // Input
    cout << "Insira um caractere equivalente a F ou J: ";
    cin >> letra_user;

    // Estrutura de Decisao com Switch Case
    switch (letra_user)
    {
    case 'f':
    case 'F':
        cout << "Voce optou pela PESSOA FISICA." << '\n';
        break;
    case 'j':
    case 'J':
        cout << "Voce optou pela PESSOA JURIDICA." << '\n';
        break;
    default:
        cout << "Caractere invalido ou tipo de pessoa nao existente." << '\n';
    }
}
