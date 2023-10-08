/* Fazer um programa em "C++" que solicite 2 números e informe:
a) A soma dos números;
b) O produto do primeiro número pelo quadrado do segundo;
c) O quadrado do primeiro número;
d) A raiz quadrada da soma dos quadrados;
e) O módulo do primeiro número.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double numero_um{}, numero_dois{};

    // Input
    cout << "Insira o primeiro numero: ";
    cin >> numero_um;
    cout << "Insira o segundo numero: ";
    cin >> numero_dois;

    // Output
    cout << "\n* A soma entre os dois numeros (" << numero_um << " + " << numero_dois << ") e ------------------------ " << numero_um + numero_dois << '\n';
    cout << "* O produto do primeiro pelo quadrado do segundo (" << numero_um << " * (" << numero_dois << "²)) e --- " << numero_um * (numero_dois * numero_dois) << '\n';
    cout << "* O quadrado do primeiro numero (" << numero_um << "²) e -------------------------- " << numero_um * numero_um << '\n';
    cout << "* A raiz quadrada da soma dos quadrados √(" << numero_um << "² + " << numero_dois << "²) e ------------ " << sqrt(pow(numero_um, 2) + pow(numero_dois, 2)) << '\n';
    if (numero_um < 0)
    {
        cout << "* O modulo do primeiro numero |" << numero_um << "| e --------------------------- " << numero_um * -1 << '\n';
    }
    else
    {
        cout << "* O modulo do primeiro numero (|" << numero_um << "|) e --------------------------- " << numero_um << '\n';
    }
}
