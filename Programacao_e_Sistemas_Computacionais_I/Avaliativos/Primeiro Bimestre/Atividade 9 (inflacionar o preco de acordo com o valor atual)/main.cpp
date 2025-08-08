// Fazer um programa em "C++" que lê o preço de um produto e inflaciona esse preço em 10% se ele for menor que 100 e em 20% se ele for maior ou igual a 100.

#include <iostream>
using namespace std;

int main()
{
    double valor_produto{};

    // Input
    cout << "Insira o valor do produto: R$";
    cin >> valor_produto;

    // Estrutura de Decisão que Efetua Cálculo
    if (valor_produto < 100)
    {
        valor_produto += valor_produto * 0.1;
        cout << "O valor atualizado e inflacionado sera de " << valor_produto << "!" << '\n';
    }
    else
    {
        valor_produto += valor_produto * 0.2;
        cout << "O valor atualizado e inflacionado sera de " << valor_produto << "!" << '\n';
    }
}
