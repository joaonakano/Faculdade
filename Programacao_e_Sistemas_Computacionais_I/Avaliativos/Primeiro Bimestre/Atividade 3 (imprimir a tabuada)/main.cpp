// Fazer um programa em C++ que imprime uma tabela com a tabuada de 1 a 9

#include <iostream>
using namespace std;

int main()
{
    int contador{11}, primeiro_termo{1};
    cout << "TABELA DA TABUADA" << '\n';

    for (int i = 1; i <= contador && primeiro_termo <= 9; i++)
    {
        cout << primeiro_termo << " vezes " << i << " e igual a " << primeiro_termo * i << '\n';

        if (i == 10 && primeiro_termo <= 9)
        {
            cout << "-----------------------" << '\n';
            primeiro_termo++;
            i = 0;
        }
    }
}
