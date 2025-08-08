#include<iostream>
using namespace std;
int main() {
    double nota_1, nota_2, nota_3, media_ponderada;
    const int peso_1{2}, peso_2{3}, peso_3{5};

    cout<<"Insira sua primeira nota: ";
    cin>>nota_1;
    nota_1 *= peso_1;

    cout<<"Insira sua segunda nota: ";
    cin>>nota_2;
    nota_2 *= peso_2;

    cout<<"Insira sua terceira nota: ";
    cin>>nota_3;
    nota_3 *= peso_3;

    media_ponderada = (nota_1+nota_2+nota_3)/(peso_1+peso_2+peso_3);

    if (media_ponderada <= 10 && media_ponderada >= 6){
        cout<<"Sua media e "<<media_ponderada<<". Voce esta aprovado!!";
    } else if (media_ponderada <= 5.9 && media_ponderada >= 4){
        cout<<"Sua media e "<<media_ponderada<<". Voce esta em recuperacao!!";
    } else {
        cout<<"Voce esta reprovado.";
    }
}