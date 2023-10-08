// Criar um programa onde o usuário informa um numero inteiro entre 1 e 12 e imprime o mês correspondente.

#include<iostream>
using namespace std;

int main() {
    int mes;
    cout<<"Insira um numero de 1 a 12: ";
    cin>>mes;

    switch(mes){
        case 1:
        cout<<"O mes correspondente ao valor "<<mes<<" e: Janeiro";
        break;
        case 2:
        cout<<"O mes correspondente ao valor "<<mes<<" e: Fevereiro";
        break;
        case 3:
        cout<<"O mes correspondente ao valor "<<mes<<" e: Marco";
        break;
        case 4:
        cout<<"O mes correspondente ao valor "<<mes<<" e: Abril";
        break;
        case 5:
        cout<<"O mes correspondente ao valor "<<mes<<" e: Maio";
        break;
        case 6:
        cout<<"O mes correspondente ao valor "<<mes<<" e: Junho";
        break;
        case 7:
        cout<<"O mes correspondente ao valor "<<mes<<" e: Julho";
        break;
        case 8:
        cout<<"O mes correspondente ao valor "<<mes<<" e: Agosto";
        break;
        case 9:
        cout<<"O mes correspondente ao valor "<<mes<<" e: Setembro";
        break;
        case 10:
        cout<<"O mes correspondente ao valor "<<mes<<" e: Outubro";
        break;
        case 11:
        cout<<"O mes correspondente ao valor "<<mes<<" e: Novembro";
        break;
        case 12:
        cout<<"O mes correspondente ao valor "<<mes<<" e: Dezembro";
        break;
        default:
        cout<<"Voce inseriu um digito ou caracter errado!";
        break;
    }
}