// Elabore um algoritmo que lê um número que representa uma senha, verifica se a senha está correta ou não, comparando-a com a senha 34567, e informa "Acesso autorizado" ou "Acesso negado", conforme o caso.

#include <iostream>
using namespace std;

int main()
{
    const int senha{34567};
    int senha_user{};
    string enfeite{"-----------------------"};

    // Input
    cout << "Digite uma senha" << '\n'
         << enfeite << '\n';
    cin >> senha_user;
    cout << enfeite << '\n';

    // Estrutura de Decisao com Switch Case
    switch (senha_user)
    {
    case senha:
        cout << "\n➔ Login feito com sucesso!" << '\n';
        cout << "➔ Acesso autorizado."
             << "\n\n";
        break;
    default:
        cout << "\n➔ Senha invalida." << '\n';
        cout << "➔ Acesso nao autorizado."
             << "\n\n";
        break;
    }
}