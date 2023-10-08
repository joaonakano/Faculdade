// Ler um número inteiro que representa um dia da semana a apresentar o nome do dia correspondente (domingo, segunda-feira, ...).

#include <iostream>
using namespace std;

int main()
{
    int valor_user{};

    // Input
    cout << "Insira um valor inteiro entre 1 e: ";
    cin >> valor_user;

    // Output com Switch Case
    switch (valor_user)
    {
    case 1:
        cout << "O dia correspondente ao numero 1 e DOMINGO!" << '\n';
        break;
    case 2:
        cout << "O dia correspondente ao numero 2 e SEGUNDA-FEIRA!" << '\n';
        break;
    case 3:
        cout << "O dia correspondente ao numero 3 e TERCA-FEIRA!" << '\n';
        break;
    case 4:
        cout << "O dia correspondente ao numero 4 e QUARTA-FEIRA!" << '\n';
        break;
    case 5:
        cout << "O dia correspondente ao numero 5 e QUINTA-FEIRA!" << '\n';
        break;
    case 6:
        cout << "O dia correspondente ao numero 6 e SEXTA-FEIRA!" << '\n';
        break;
    case 7:
        cout << "O dia correspondente ao numero 7 e SABADO!" << '\n';
        break;
    default:
        cout << "Voce inseriu um caractere ou numero invalido" << '\n';
        break;
    }
}
