// Ler um valor inteiro e : a) exibir a mensagem 'número negativo' quando o valor informado for menor que zero; b) exibir a mensagem 'zero' quando este for igual a zero; e c) exibir a mensagem 'número positivo' quando o valor for maior que zero.

#include <iostream>
using namespace std;

int main()
{
    int valor_user{};

    // Input
    cout << "Digite um valor inteiro: ";
    cin >> valor_user;

    if (valor_user < 0)
    {
        // a) exibir a mensagem 'número negativo' quando o valor informado for menor que zero
        cout << valor_user << "e um numero negativo!" << '\n';
    }
    else if (valor_user == 0)
    {
        // b) exibir a mensagem 'zero' quando este for igual a zero
        cout << "Esse numero e o 0!" << '\n';
    }
    else if (valor_user > 0)
    {
        // c) exibir a mensagem 'número positivo' quando o valor for maior que zero.
        cout << "Esse numero e positivo!" << '\n';
    }
}