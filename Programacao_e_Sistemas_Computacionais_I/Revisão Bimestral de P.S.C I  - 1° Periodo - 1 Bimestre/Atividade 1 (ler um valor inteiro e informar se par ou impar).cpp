// Ler um valor inteiro e informar, através de uma mensagem, se este valor é um número par ou ímpar.

#include <iostream>
using namespace std;

int main()
{
    int valor{};

    // Input
    cout << "Insira um numero inteiro: ";
    cin >> valor;

    // Estrutura de Decisao usando Modulo
    if (valor % 2 == 0)
    {
        cout << "O valor " << valor << " e um numero par!" << '\n';
    }
    else if (valor % 2 == 1)
    {
        cout << "O valor " << valor << " e um numero impar!" << '\n';
    }
    else
    {
        cout << "Um caracter invalido foi inserido!" << '\n';
    }
}