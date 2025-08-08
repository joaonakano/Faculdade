// Ler dois valores inteiros e apresentar a adição destes valores, quando o primeiro valor for maior que o segundo, caso contrário, efetuar a multiplicação dos valores.

#include <iostream>
using namespace std;

int main()
{
    int valor_um{}, valor_dois{};

    // Input
    cout << "Insira o primeiro valor inteiro: ";
    cin >> valor_um;
    cout << "Insira o segundo valor inteiro: ";
    cin >> valor_dois;

    // Estrutura de Decisao seguida de Soma ou Multiplicacao
    if (valor_um > valor_dois)
    {
        cout << "A soma entre esses dois valores e " << valor_um + valor_dois << '\n';
    }
    else
    {
        cout << "A multiplicacao entre esses dois valores e " << valor_um * valor_dois << '\n';
    }
}