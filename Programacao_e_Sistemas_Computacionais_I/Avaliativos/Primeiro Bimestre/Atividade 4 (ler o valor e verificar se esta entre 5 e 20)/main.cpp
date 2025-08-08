// Escreva um algoritmo que leia um valor verifique se ele se encontra no intervalo entre 5 e 20.

#include <iostream>
using namespace std;

int main()
{
    double valor_user{};
    cout << boolalpha;

    // Input
    cout << "Indique um valor entre 5 e 20: ";
    cin >> valor_user;

    cout << valor_user << " se encontra entre 5 e 20? -> " << (valor_user >= 5 && valor_user <= 20) << '\n';
}
