// 1 - Crie uma matriz que leia e armazene o nome e CPF de 5 pessoas. Após o usuário digitar os dados eles devem ser exibidos na tela.

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int CPF [5];
    string nome [5];

    cout<<"ATIVIDADE 1"<<endl;
    for(int i=0; i<5; i++){
        cout<<"Insira um CPF ("<<i+1<<"): ";
        cin>>CPF[i];
        cout<<"Insira um nome ("<<i+1<<"): ";
        cin>>nome[i];
    }

    cout<<"Obrigado por responder! Mostrando todos os CPFs e nomes inseridos"<<'\n';
    for(int i=0; i<5; i++){
        cout<<CPF[i]<<" - ";
        cout<<nome[i]<<endl;
    }

    // 2 - Capture do teclado valores para preenchimento de uma matriz M 3x3. Após a captura imprima a matriz criada e encontre a quantidade de números pares, a quantidade de números ímpares.

    int valores[3][3], pares{}, impares{};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<"Insira um valor no espaco ["<<i+1<<"]["<<j+1<<"]"<<'\n';
            cin>>valores[i][j];

            if(valores[i][j] % 2==0){
                pares++;
            } else {
                impares++;
            }
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<valores[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<"Numeros Pares: "<<pares<<endl;
    cout<<"Numeros Impares: "<<impares<<endl;
}