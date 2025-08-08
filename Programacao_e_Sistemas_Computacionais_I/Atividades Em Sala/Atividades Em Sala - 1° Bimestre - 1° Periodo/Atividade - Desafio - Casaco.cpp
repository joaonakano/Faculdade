// Fazer um programa para saber se precisa levar casaco se for sair de casa, solicitando duas informações ao usuário Temperatura e Velocidade do Vento.

// Se o vento estiver mais de 50 km/h, preciso de um casaco;
// Se a temperatura estiver abaixo de 15°C, preciso de um casaco;

//  * Criar uma variável booleana vestir_casaco para validar as expressões e informar ao usuário.

#include<iostream>
using namespace std;

int main() {
    float temp{}, velocity_ventos{};
    bool vestir_casaco;

    cout<<"Insira a temperatura la fora: ";
    cin>>temp;
 
    cout<<"Insira a velocidade dos ventos: ";
    cin>>velocity_ventos;

    // Utilizando puro calculo
    cout<<boolalpha;
    vestir_casaco = temp < 15 || velocity_ventos > 50;
    cout<<"Voce precisa vestir um casaco: "<<vestir_casaco;

    // Utilizando IF
/*
    if (velocity_ventos >= 50 || temp < 15) {
        cout<<"Voce precisa levar um casaco";
    } else {
        cout<<"Voce nao precisa levar um casaco";
    }
*/
}