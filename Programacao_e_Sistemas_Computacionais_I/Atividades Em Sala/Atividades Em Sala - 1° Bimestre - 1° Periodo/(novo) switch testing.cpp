#include<iostream>
using namespace std;
int main(){
    char conceito;
    cout<<"Informe qual conceito voce deseja tirar no exame: ";
    cin>>conceito;

    switch(conceito){
        case 'a':
        case 'A':
            cout<<"Voce vai estar acima 90, estude muito.";
            break;
        case 'b':
        case 'B':
            cout<<"Voce vai estar entre 80 e 90, estude.";
            break;
        case 'c':
        case 'C':
            cout<<"Voce vai estar entre 70 e 79, mediano.";
            break;
        case 'd':
        case 'D':
            cout<<"Voce vai 60 e 69, abaixo da media.";
            break;
        case 'F':
        case 'f':
        {
            char confirma{};
            cout<<"Voce tem certeza disto? (S/N): ";
            cin>>confirma;

            if (confirma == 'S' || confirma == 's'){
                cout<<"Voce vai estar extremamente abaixo da media."<<endl;
            } else if (confirma == 'N' || confirma == 'n') {
                cout<<"Boa! Bora estudar!"<<endl;
            } else {
                cout<<"Escolha incorreta!";
                break;
            }
        }
        default:
            cout<<"Inseriu um ou demais caracteres invalidos."<<endl;
            break;
    }
}