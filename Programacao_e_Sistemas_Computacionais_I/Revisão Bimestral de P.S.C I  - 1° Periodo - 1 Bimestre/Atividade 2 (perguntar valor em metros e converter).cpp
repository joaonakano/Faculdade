// Fazer um programa em C++ que pergunta um valor em metros e imprime o correspondente em decímetros, centímetros e milímetros.

#include <iostream>
using namespace std;

int main()
{
    double valor_metros{};
    string enfeite{"---------------------------------------------------"};

    // Input
    cout << "Insira um valor em metros para iniciar a conversao: ";
    cin >> valor_metros;

    // Output
    cout << enfeite << '\n';
    cout << "O valor de " << valor_metros << " metro(s) em decimetros  e   " << valor_metros * 10 << " dm" << '\n';
    cout << "O valor de " << valor_metros << " metro(s) em centimetros e  " << valor_metros * 100 << " cm" << '\n';
    cout << "O valor de " << valor_metros << " metro(s) em milimetros  e " << valor_metros * 1000 << " mm" << '\n';
}